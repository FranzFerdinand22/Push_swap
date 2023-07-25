#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

void    bubble_sort(int arr[], int n);

int	*rand_num(const char *str)
{
	int *arr;
	int size = atoi(str);
	int i = 0;

	arr = malloc(sizeof(int) * size);
	while (i < size)
	{
		arr[i] = rand();
		i++;
	}
	return(arr);
}

int main(int argc, char **argv)
{
	int *arr;
	int i = 0;

	if (argc == 2)
	{	
		arr = rand_num(argv[1]);
		printf("Array before sort: ");
		for (i = 0; i < atoi(argv[1]); i++)
			printf("%d,", arr[i]);
		printf("\n");
		bubble_sort(arr, atoi(argv[1]));
		printf("Array after sort: ");
		for (i = 0; i < atoi(argv[1]); i++)
			printf("%d,", arr[i]);		
		printf("\n");
		free(arr);
	}
	write(1, "\n", 1);
	return (0);
}
