#include <unistd.h>

void	rev_print(char *s)
{
	int i = 0;
	// Loop goes through the string until it reaches the end.
	while (s[i])
		i++;
	// Loop prints each character from end-1 (pre-increment operation to avoid printing garbage value) until the beginning
	while (--i >= 0)
		write(1, &s[i], 1);
}

int main(int argc, char *argv[])
{
	if (argc == 2)
		rev_print(argv[1]);
	write(1, "\n", 1);
	return (0);
}
