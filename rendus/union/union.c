#include <unistd.h>

void	ft_union(char *s1, char *s2)
{
	int	array[128];
	int	i;

	// create an int array for all ascii characters
	// set all values in this array to 0
	i = 0;
	while (i < 128)
	{
		array[i] = 0;
		i++;
	}
	// going through the first string, write each character
	// set the array index corresponding to that character's value to 1
	i = 0;
	while (s1[i])
	{
		if (array[(int)s1[i]] == 0)
		{
			write(1, &s1[i], 1);
			array[(int)s1[i]] = 1;
		}
		i++;
	}
	i = 0;
	while (s2[i])
	{
		if (array[(int)s2[i]] == 0)
		{
			write(1, &s2[i], 1);
			array[(int)s2[i]] = 1;
		}
		i++;
	}
}

int	main(int argc, char *argv[])
{
	// if the number of arguments is correct, execute the function,
	// print a new line in any case.
	if (argc == 3)
		ft_union(argv[1], argv[2]);
	write(1, "\n", 1);
	return (0);
}
