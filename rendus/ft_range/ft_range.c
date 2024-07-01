#include <stdio.h>
#include <stdlib.h>

// this function returns the absolute value of n
// this is useful in case start > end
int	myabs(int n)
{
	if (n < 0)
		return (n * -1);
	return (n);
}

int	*ft_range(int start, int end)
{
	int	i;
	int	len;
	int	*range;

	i = 0;
	// calculate the total length of the array to be allocated
	len = myabs(end - start) + 1;
	range = malloc(len * sizeof(int));
	// if start < end, allocate start as range[i] and increment
	if (start < end)
	{
		while (i < len)
		{
			range[i] = start;
			start++;
			i++;
		}
	}
	// if start > end, allocate start as range[i] and decrement
	else
	{
		while (i < len)
		{
			range[i] = start;
			start--;
			i++;
		}
	}
	return (range);
}

// main not needed for the exam, only to test the output
/*
int	main(int argc, char *argv[])
{
	int *range_array;
	int i = 0;
	int start = atoi(argv[1]);
	int end = atoi(argv[2]);
	int size = myabs(end - start) + 1;
	range_array = ft_range(start, end);
	while (i < size)
	{
		printf("%d", range_array[i]);
		i++;
	}
	return (0);
}*/