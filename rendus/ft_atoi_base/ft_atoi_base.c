#include <stdio.h>
#include <unistd.h>

int	ft_atoi_base(const char *str, int str_base)
{
	char	dec_symbols[] = "0123456789";
	int		i;
	int		sign;
	int		nbr;

	i = 0;
	sign = 0;
	nbr = 0;
	while (str[i])
	{
		while (str[i] == '+' || str[i] == '-')
		{
			if (str[i] == '-')
				sign *= -1;
			i++;
		}
		nbr = nbr * str_base;
		nbr = nbr + str[i] - '0';
	}
	return (nbr * sign);
}

int	main(int argc, char *argv[])
{
	int nbr = 0;
	if (argc == 2)
	{
		nbr = ft_atoi_base(argv[1], 10);
		printf("%d", nbr);
	}
	return (0);
}