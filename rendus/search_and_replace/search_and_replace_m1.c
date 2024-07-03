#include <unistd.h>

// check if the char b is in the string, return 0 if not.
int	ft_str_search(char *str, char b)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (1);
		i++;
	}
	return (0);
}

// check if the character b is in str
// if yes, iterate through str and replace b with c
// if not found, return 1
int	search_and_replace(char *str, char b, char c)
{
	int	i;

	i = 0;
	if (ft_str_search(str, b) == 1)
	{
		while (str[i])
		{
			if (str[i] == b)
				str[i] = c;
			write(1, &str[i], 1);
			i++;
		}
		return (0);
	}
	return (1);
}

int	main(int argc, char *argv[])
{
	int i;

	// execute function only if search and replace returns 1
	if (argc == 4)
	{
		if (search_and_replace(argv[1], argv[2][0], argv[3][0]) == 1)
		{
			i = 0;
			while (argv[1][i])
			{
				write(1, &argv[1][i], 1);
				i++;
			}
		}
	}

	write(1, "\n", 1);
	return (0);
}