#include <unistd.h>

int	ft_atoi(char *str)
{
	int	i;
	int	nbr;

	i = 0;
	nbr = 0;
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

	if (n >= 16)
		print_hex(n / 16);
	write(1, &numbers[n % 16], 1);
}

int	main(int argc, char *argv[])
{
	int nbr;

	if (argc == 2)
	{
		nbr = ft_atoi(argv[1]);
		print_hex(nbr);
	}
	write(1, "\n", 1);
	return (0);
}