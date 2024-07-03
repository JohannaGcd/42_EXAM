#include <unistd.h>

int ft_strlen(char *s)
{
	if (!s)
		return (0);
	int i = 0;
	while (s[i])
		i++;
	return (i);
}


void	search_and_replace(char *s, char a, char b)
{
	int i = 0;
	// First replace the char a with char b
	while (s[i])
	{
		if (s[i] == a)
			s[i] = b;
		i++;
	}
	// Then print out the modified string. For the loop, i is -1 with a prefix increment next. 
	// This is equivalent to the first loop above. It saves lines but may not be as clear.
	i = -1;
	while (s[++i])
		write(1, &s[i], 1);
}

int main(int argc, char *argv[])
{
	// argc 1 is the name of the program output
	if (argc == 4)
	{
		// verify the length of argc 3 and 4 to check if it's a 1 character string
		int n = 0;
		int m = 0;
		n = ft_strlen(argv[2]);
		m = ft_strlen(argv[3]);
		if (n == 1 && m == 1)
		// send argv[1] as a string & argv[2][0] and argv[3][0] as char
			search_and_replace(argv[1], argv[2][0], argv[3][0]);
	}
	write(1, "\n", 1);
	return (0);
}
