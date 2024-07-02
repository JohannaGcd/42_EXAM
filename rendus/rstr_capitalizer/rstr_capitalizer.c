#include <unistd.h>

void	ft_rstr_capitalizer(char *str)
{
	int	i;

	i = 0;
	// Iterate through the string
	// if encounter a CAPITAL, change that character to lowercase
	// if character c is a letter AND the next character is a space or a tab or the NULL
	// change that character to a lowercase
	// write that character
	// and increment i
	while (str[i])
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
			str[i] += 32;
		if ((str[i] >= 'a' && str[i] <= 'z') && (str[i + 1] == ' ' || str[i
				+ 1] == '\t' || str[i + 1] == '\0'))
			str[i] -= 32;
		write(1, &str[i], 1);
		i++;
	}
}

int	main(int argc, char *argv[])
{
	if (argc == 1)
		write(1, "\n", 1);
	else
	{
		int i = 1;
		while (i < argc)
		{
			ft_rstr_capitalizer(argv[i]);
			write(1, "\n", 1);
			i++;
		}
	}
	return (0);
}