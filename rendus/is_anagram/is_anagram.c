#include <unistd.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}
int	str_search(char *str, char c)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (1);
	}
	return (0);
}
int	is_anagram(char *s1, char *s2)
{
	int	i;

	if (ft_strlen(s1) == 0 || ft_strlen(s2) == 0)
		return (1);
	if (ft_strlen(s1) != ft_strlen(s2))
		return (1);
	i = 0;
	while (s1[i])
	{
		if (str_search(s2, s1[i]) == 1)
			s1[i] = "\n";
		i++;
	}
	i = 0;
	while (s1[i])
	{
		if (s1[i] != "\n")
			return (1);
	}
	return (0);
}

int	main(int argc, char *argv[])
{
	int result;

	result = 0;
	if (argc == 3)
		result = is_anagram(argv[1], argv[2]);
	return (result);
}