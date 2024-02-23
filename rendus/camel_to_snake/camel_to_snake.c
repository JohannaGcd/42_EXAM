#include <unistd.h>
#include <stdlib.h>

// We measure the length of the string to be allocated:
// using i as an index 
// and maj to keep track of capital letters (to allocate an extra space for the underscore)
int	ft_strlen(char *s)
{
	int i = 0;
	int maj = 0;
	while (s[i])
	{
		if (s[i] >= 65 && s[i] <= 90)
			maj++;
		i++;
	}
	return (i + maj);
}

// We copy s into new_s 
// if a capital letter is met, increment only j to add an underscore and the new value in s[i] 
// finally increment both indexes
char	*camel_to_snake(char *s)
{
	int i = 0;
	int j = 0;
	int len = ft_strlen(s);
	char *new_s = malloc(sizeof(char) * (len + 1));
	while (s[i])
	{
		new_s[j] = s[i];
		if (s[i] >= 65 && s[i] <= 90)
		{
			s[i] += 32;
			new_s[j] = '_';
			j++;
			new_s[j] = s[i];
		}	
		j++, i++;
		
	}
	new_s[j] = '\0';
	return (new_s);
}

// the main function calls camel_to_snake if argc is 2
// otherwise just prints a new line
// the new_s is freed since it was allocated on the heap using malloc.
int main(int argc, char *argv[])
{
	char *new_s;
	if (argc == 2)
	{
		new_s = camel_to_snake(argv[1]);
		write(1, new_s, ft_strlen(new_s) + 1);
		free (new_s);
	}
	write(1, "\n", 1);
	return (0);
}
