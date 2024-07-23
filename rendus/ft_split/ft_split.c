#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

// this function returns 1 (true) if c is a space/tab/newline or 0 (false) otherwise.
int	is_space(char c)
{
	return (c == ' ' || c == '\t' || c == '\n');
}

// this function counts the words in the full string
// while still in the string, 
// it skips any white space in the beginning
// then increments count and moves to the next white space.
int count_words(char *str)
{
	int	count;

	while (*str)
	{
		while (*str && is_space(*str))
			str++;
		if (*str && !is_space(*str))
		{
			count++;
			while (*str && !is_space(*str))
				str++;
		}
	}
	return (count);
}

// this function finds the boundaries of the first word,
// mallocs for the number of characters
// adds a NULL
// and returns a pointer to the word.
char	*malloc_word(char *str)
{
	int 	i;
	char	*word;
	
	i = 0;
	while (str[i] && !is_space(str[i]))
		i++;
	word = malloc(sizeof(char) * i + 1);
	i = 0;
	while (str[i] && !is_space(str[i]))
	{
		word[i] = str[i];
		i++;
	}
	word[i] = '\0';
	return (word);
}

char	**ft_split(char *str)
{
	char	**array;
	int		j;	

	j = 0;
	array = malloc(sizeof (char *) * (count_words(str) + 1));
	while (*str)
	{
		while (*str && is_space(*str))
			str++;
		if (*str && !is_space(*str))
		{
			array[j] = malloc_word(str);
			j++;
			while (*str && !is_space(*str))
				str++;
		}
	}
	array[j] = NULL;
	return (array);
}

int main(int argc, char *argv[])
{
	int i;
	char **array;
	if (argc == 2)
	{
		array = ft_split(argv[1]);
		i = 0;
		while (array[i])
		{
			printf("%s", array[i]);
			i++;
		}
	}
	return (0);
}
