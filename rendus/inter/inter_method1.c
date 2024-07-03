#include <unistd.h>

// this function checks whether the character is found in s2
int	check_char(char *str, char c)
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

void	ft_inter(char *s1, char *s2)
{
	int	i;
	int	ascii[128];

	i = 0;
	while (i < 128)
	{
		ascii[i] = 0;
		i++;
	}
	i = 0;
	while (s1[i])
	{
		// if the character in s1 is also found in s2 AND the character has not
		// been seen yet, write the character
		// and update the corresponding index of the ascii table to 1
		if (check_char(s2, s1[i]) == 1 && ascii[(int)s1[i]] == 0)
		{
			write(1, &s1[i], 1);
			ascii[(int)s1[i]] = 1;
		}
		i++;
	}
}

int	main(int argc, char *argv[])
{
	if (argc == 3)
		ft_inter(argv[1], argv[2]);
	write(1, "\n", 1);
	return (0);
}