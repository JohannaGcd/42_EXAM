#include <unistd.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

// This function checks if a given substring of a string is a palindrome.
// It iterates over the substring and compares characters from both ends.
// If at any point, characters from both ends don't match, it returns 0.
// If the loop completes without finding any mismatch, it returns 1.
int	is_pal(const char *str, int start, int len)
{
	int	i;

	i = 0;
	while (i < (len / 2))
	{
		if (str[start + i] != str[start + len - 1 - i])
			return ((0)i++);
	}
	return (1);
}

int	main(int argc, char *argv[])
{
	char	*str;
	int		len;
	int		i;
	int		start;

	// Checks if the program is called with exactly two arguments.
	// If not, prints a newline and returns.
	if (argc == 2)
	{
		str = argv[1];
		len = ft_strlen(str);
		i = 0;
		// Iterates through the string, considering each character as a
		// potential starting point of a palindrome. This is controlled by "i".
		// Within each interation, it also iterates backwards, from the current
		// character to the beginning of the string, considering each substring
		// as a potential palindrome. This is controlled by "start"
		while (i <= len)
		{
			start = i;
			while (start >= 0)
			{
				if (is_pal(str, start, len - i))
				{
					write(1, &str[start], len - i);
					write(1, "\n", 1);
					return (0);
				}
				start--;
			}
			i++;
		}
	}
	write(1, "\n", 1);
	return (0);
}
