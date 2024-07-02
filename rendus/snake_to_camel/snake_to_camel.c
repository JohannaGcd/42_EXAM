#include <unistd.h>

int	main(int argc, char *argv[])
{
	if (argc == 2)
	{
		int i = 0;
		// iterate through the first argument string
		// if "_", increment i and substract 32 to the char to make it CAPITAL)
		// write that character
		// increment i
		while (argv[1][i])
		{
			if (argv[1][i] == '_')
			{
				i++;
				argv[1][i] = argv[1][i] - 32
			}
			write(1, &argv[1][i], 1);
			i++;
		}
	}
	write(1, "\n", 1);
	return (0);
}