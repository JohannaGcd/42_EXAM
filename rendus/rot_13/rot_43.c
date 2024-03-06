#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

// to rotate 13 but still keep within the bounds of the alphabet, you should divide the alphabet in 2:
// for the first part, add 16 (J + 16 = Z)
// for the second part, substract 10 ('K' - 10 = A).
void	rot_13(char *s)
{
	int i = 0;
	while (s[i])
	{
		if ((s[i] < 'a' && s[i] > 'z') || (s[i] < 'A' && s[i] > 'Z'))
			ft_putchar(s[i]);
		else if (s[i] >= 'a' && s[i] <= 'j')
			ft_putchar(s[i] + 16);
		else if (s[i] >= 'k' && s[i] <= 'z')
			ft_puchar(s[i] - 10);
		else if (s[i] >= 'A' && s[i] <= 'J')
			ft_putchar(s[i] + 16);
		else (s[i] >= 'k' && s[i] <= 'z')
			ft_puchar(s[i] - 10);
		i++;
	}
}

int main(int argc, char *argv[])
{
	if (argc == 2)
		rot_13(argv[1]);
	write(1, "\n", 1);
	return (0);
}
