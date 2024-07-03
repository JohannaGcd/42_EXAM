#include <unistd.h>

void	expand_str(char *str)
{
	int	i;
	int	flag;

	i = 0;
	flag = 0;
	// skip spaces at the beginning
	while ((str[i] == ' ' || str[i] == '\t') && (str[i] != '\0'))
		i++;
	// continue until the string ends (ie. '\0')
	while (str[i])
	{
		// if encounter a space, flag = 1
		if (str[i] == ' ' || str[i] == '\t')
			flag = 1;
		// if not a space, and flag is 1, write three spaces
		// then bring the flag back to 0 and write the character
		// increment i
		if (!(str[i] == ' ' || str[i] == '\t'))
		{
			if (flag == 1)
				write(1, "   ", 3);
			flag = 0;
			write(1, &str[i], 1);
		}
		i++;
	}
}

int	main(int argc, char *argv[])
{
	// only execute the function with the correct number of arguments
	if (argc == 2)
		expand_str(argv[1]);
	// write a new line in any case
	write(1, "\n", 1);
	return (0);
}
