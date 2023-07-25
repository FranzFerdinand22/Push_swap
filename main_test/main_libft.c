
#include "push_swap.h"

int ft_strlen(const char *str)
{
    int i = 0;

    while (*(str++))
        i++;
    return (i);
}

char	*ft_strdup(const char *s)
{
	char	*p;
	int		l;
	int		i;

	i = 0;
	l = ft_strlen(s) + 1;
	p = (char *)malloc(l * sizeof(char));
	if (p != NULL)
	{
		while (s[i])
		{
			p[i] = s[i];
			i++;
		}
		p[i] = '\0';
		return (p);
	}
	return (NULL);
}


char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	i;
	size_t	j;

	i = start;
	j = 0;
	if (!s)
		return (NULL);
	if (start >= ft_strlen(s))
		return (ft_strdup(""));
	sub = (char *)malloc(sizeof(char) * (len + 1));
	if (sub == NULL)
		return (NULL);
	while (s[i] && i < ft_strlen(s) && j < len)
	{
		sub[j] = s[i];
		i++;
		j++;
	}
	sub[j] = '\0';
	return (sub);
}

int	wordcount(char const *s, char c)
{
	int	dl;
	int	i;

	dl = 0;
	i = 0;
	while (s[i])
	{
		if (s[++i] == c && s[i - 1] != c)
			dl++;
	}
	return (dl + 1);
}

char	**ft_mysplit(char **split, char const *s, char c)
{
	int		i;
	int		j;
	int		sub;

	i = 0;
	j = 0;
	sub = 0;
	while (s[i])
	{
		if (s[i] == c)
			i++;
		else
		{
			while (s[i] && s[i] != c)
			{
				j++;
				i++;
			}
			split[sub] = ft_substr(s, i - j, j);
			sub++;
			j = 0;
		}
	}
	split[sub] = NULL;
	return (split);
}

char	**ft_split(char const *s, char c)
{
	char	**split;

	split = (char **)malloc(sizeof(char *) * (wordcount(s, c) + 1));
	if (split == NULL)
		return (NULL);
	return (ft_mysplit(split, s, c));
}