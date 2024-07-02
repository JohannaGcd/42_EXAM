#include <unistd.h>

void	ft_last_word(char *str)
{
	int	i;

	i = 0;
	// iterate until just before the end of the string
	while (str[i + 1])
		i++;
	// go back while it's a space or tab (in case the string ends with spaces)
	while (str[i] == ' ' || str[i] == '\t')
		i--;
	// then continue going back while str is not a space (ie. its a letter)
	while (!(str[i] == ' ' || str[i] == '\t'))
		i--;
	// add one to i to go back to the letter
	i++;
	// then write each character and increment i until its not a space/tab/Null
	while ((str[i] >= 33 && str[i] <= 126) && (str[i] != ' ' || str[i] != '\t'
			|| str[i] != '\0'))
	{
		write(1, &str[i], 1);
		i++;
	}
}

int	main(int argc, char *argv[])
{
	if (argc == 2)
		ft_last_word(argv[1]);
	write(1, "\n", 1);
	return (0);
}