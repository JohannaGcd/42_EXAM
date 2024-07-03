#include <unistd.h>

void	ft_inter(char *s1, char *s2)
{
	int		i;
	char	ascii[128];

	i = 0;
	while (i < 128)
	{
		ascii[i] = 0;
		i++;
	}
	i = 0;
	// go through the second string
	// change ascii table index value to 1 for each character met
	while (s2[i])
	{
		ascii[(int)s2[i % 128]] = 1;
		i++;
	}
	// go through the first string, if corresponding index in the ascii table is
	// already marked 1, print it. Set that value to 2 before continuing.
	i = 0;
	while (s1[i])
	{
		if (ascii[(int)s1[i % 128]] == 1)
		{
			write(1, &s1[i], 1);
			ascii[(int)s1[i % 128]] = 2;
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