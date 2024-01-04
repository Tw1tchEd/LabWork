#include <stdlib.h>
#include <stdio.h>
#include <conio.h>

void enter_x(int* value, int x)
{
	while (scanf_s("%d", value) == 0 || getchar() != '\n' || *value < x)
	{
		printf("Wrong\n");
		rewind(stdin);
	}
}

char** create_1(char** arr, int* words, int* letters)
{
	arr[0] = malloc(sizeof(char) * (*letters));
	char c = '1';
	int i = 0, j = 0, flag = 0;
	while (c != '\0' && c != '\n')
	{
		if (i >= *letters)
		{
			(*letters) *= 2;
			arr[j] = (char*)realloc(arr[j], sizeof(char) * (*letters));
		}
		c = getchar();
		if (c != ' ' && c != '\n')
		{
			arr[j][i] = c;
			i++;
			flag = 1;
		}
		else if (flag)
		{
			arr[j][i] = '\0';
			flag = 0;
			j++;
			i = 0;
		}
		if (j >= (*words))
		{
			(*words)++;
			arr = (char**)realloc(arr, sizeof(char*) * (*words));
			arr[j] = (char*)malloc(sizeof(char) * (*letters));
		}

	}
	arr[j][i] = '\0';
	(*words) = j;
	return arr;
}

void print(char** arr, int words)
{
	for (int i = 0; i < words; i++)
	{
		puts(arr[i]);
	}
	printf("\n");
}

char** deleter_of_kth(char** arr, int* words, int k)
{
	for (int i = k - 1; i < *words; i += (k - 1))
	{
		free(arr[i]);
		for (int j = i; j < (*words) - 1; j++)
		{
			arr[j] = arr[j + 1];
		}
		(*words)--;
	}
	return arr;
}

void clear(char** arr, int words)
{
	for (int i = 0; i < words; i++)
	{
		free(arr[i]);
	}
	free(arr);
}

char* create_2(int length)
{
	char* arr = malloc(sizeof(char) * (length));
	char c = '1';
	int i = 0;
	while (c != '\n' && c != '\0')
	{
		if (i >= length)
		{
			length *= 2;
			arr = realloc(arr, sizeof(char) * length);
		}
		c = getchar();
		arr[i] = c;
		i++;
	}
	arr[i] = '\0';
	return arr;
}

int strlen_s(char* arr)
{
	int length = 0;
	while (arr[length] != '\0')
	{
		length++;
	}
	return length;
}

char* add_substring(char* arr, char* substring, char s)
{
	int i = 0, step = strlen_s(substring) - 1, length = strlen_s(arr);
	while (arr[i] != '\0')
	{
		if (arr[i] == s)
		{
			length += step + 1;
			arr = realloc(arr, sizeof(char) * length);
			for (int j = length - 1; j > i + step; j--)
			{
				arr[j] = arr[j - step];
			}
			for (int j = i + 1; j < i + step + 1; j++)
			{
				arr[j] = substring[j - (i + 1)];
			}
		}
		i++;
	}
	return arr;
}

void kth_word_away()
{
	int words = 1, letters = 10, k;
	char** arr = (char**)malloc(sizeof(char*) * words);
	printf("Your string:\n");
	arr = create_1(arr, &words, &letters);
	print(arr, words);
	printf("k = ");
	enter_x(&k, 0);
	arr = deleter_of_kth(arr, &words, k);
	print(arr, words);
	clear(arr, words);
}

void substring_input()
{
	printf("Your string S:\n");
	char* arr = create_2(10);
	puts(arr);
	printf("Input substring S0:\n");
	char* substring = create_2(10);
	printf("Input the C-symbol:\n");
	char c;
	while (scanf_s("%c", &c) == 0 || getchar() != '\n')
	{
		printf("Error\n");
		rewind(stdin);
	}
	arr = add_substring(arr, substring, c);
	puts(arr);
	free(arr);
}

void main()
{
	printf("What do you want to do?\n");
	printf("1 - delete kth\n");
	printf("2 - substring input\n");
	int choice;
	while (scanf_s("%d", &choice) == 0 || getchar() != '\n' || (choice != 1 && choice != 2))
	{
		printf("Error\n");
		rewind(stdin);
	}
	void (*do_it) (void);
	if (choice == 1)
	{
		do_it = kth_word_away;
	}
	else
	{
		do_it = substring_input;
	}
	do_it();
}