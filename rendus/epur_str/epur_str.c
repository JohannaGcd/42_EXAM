#include <unistd.h>

void	ft_epur(char *str)
{
	int	i;
	int	flag;

	// skip spaces or tabs at the beginning of the string
	i = 0;
	while (str[i] == ' ' || str[i] == '\t')
		i++;
	// if space or tab, set the flag to 1.
	// if not a space or tab,
	// AND if flag is 1, print a space,
	// set the flag back to 0 and print the character
	// keep going until the end of the string
	while (str[i])
	{
		if (str[i] == ' ' || str[i] == '\t')
			flag = 1;
		if (!(str[i] == ' ' || str[i] == '\t'))
		{
			if (flag == 1)
				write(1, " ", 1);
			flag = 0;
			write(1, &str[i], 1);
		}
		i++;
	}
}

int	main(int argc, char *argv[])
{
	if (argc == 2)
		ft_epur(argv[1]);
	write(1, "\n", 1);
	return (0);
}