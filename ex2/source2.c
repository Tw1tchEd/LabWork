#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

void create(char** arr, char** argv, int argc)
{
	for (int i = 0; i < argc - 1; i++)
	{
		arr[i] = malloc(sizeof(char) * 10);
	}
	int i = 0, j = 0, c = 0;
	while (j < argc - 1)
	{
		if (i >= 10)
		{
			arr[i] = realloc(arr[i], sizeof(char) * (i + 1));
		}
		if (argv[1][c] == '\0')
		{
			arr[j][i] = '\0';
			j++;
			i = 0;
			c++;
		}
		else
		{
			arr[j][i] = argv[1][c];
			i++;
			c++;
		}
	}
}

int count(char** arr, int index)
{
	int length = 0;
	while (arr[index][length] != '\0')
	{
		length++;
	}
	return length;
}

void sort(char** arr, int size)
{
	for (int i = 0; i < size; i++)
	{
		int k = i;
		while (k > 0 && count(arr, k - 1) < count(arr, k))
		{
			char* tmp = arr[k - 1];
			arr[k - 1] = arr[k];
			arr[k] = tmp;
			k -= 1;
		}
	}
}

void print(char** arr, int size)
{
	for (int i = 0; i < size; i++)
	{
		puts(arr[i]);
	}
	printf("\n");
}

void clear(char** arr, int size)
{
	for (int i = 0; i < size; i++)
	{
		free(arr[i]);
	}
	free(arr);
}

void main(int argc, char** argv)
{
	char** arr = malloc(sizeof(int*) * (argc - 1));
	create(arr, argv, argc);
	print(arr, argc - 1);
	sort(arr, argc - 1);
	print(arr, argc - 1);
	clear(arr, argc - 1);
}