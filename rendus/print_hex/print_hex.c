#include <unistd.h>

int	ft_atoi(char *str)
{
	int	i;
	int	nbr;

	i = 0;
	nbr = 0;
	// multiply the number by ten (first round will be 0)
	// convert the next character to a number (using - '0')
	// then add that number to the original number
	while (str[i])
	{
		nbr = nbr * 10;
		nbr = nbr + str[i] - '0';
		i++;
	}
	return (nbr);
}

void	print_hex(int n)
{
	char	numbers[] = "0123456789abcdef";

	// initialize an array with all the symbols for the base 16 conversion
	// create a recursive call:
	// each time the function is called, the number is divided by 16
	// then print the number in hexadecimal by using its relative position in the array
	if (n >= 16)
		print_hex(n / 16);
	write(1, &numbers[n % 16], 1);
}

int	main(int argc, char *argv[])
{
	int nbr;

	if (argc == 2)
	{
		// first convert arg[1] to a number using atoi
		nbr = ft_atoi(argv[1]);
		print_hex(nbr);
	}
	write(1, "\n", 1);
	return (0);
}