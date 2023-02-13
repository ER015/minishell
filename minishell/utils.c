#include "minishell.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	char	*ptr;
	size_t	i;

	if (start >= ft_strlen(s))
		len = 0;
	else
		ptr = (char *)s + start;
	i = -1;
	if (ft_strlen(s) < len)
		len = ft_strlen(s);
	str = malloc(sizeof(char) * (len + 1));
	if (!str)
		return (0);
	while (++i < len && *(ptr + i))
	{
		str[i] = *(ptr + i);
	}
	str[i] = '\0';
	//printf("debug |%s|\n",str);
	return (str);
}



char	*ft_strtrim(char *str)
{
	size_t	i;
	size_t	j;

	j = 0;
	while (*str != '\0')
	{
		if(str[j] == 32 || str[j] == '\t')
			j++;
		else
			break;
	}

	i = ft_strlen(str) - 1;
	while (&str[i] != str)
	{
		if(str[i] == 32 || str[i] == '\t')
			i--;
		else
			break;
	}
	return (ft_substr(str, j, i - j + 1));
}

size_t	ft_strlen(const char*s)
{
	unsigned int	count;
	unsigned int	i;

	count = 0;
	i = 0;
	while (s && s[i])
	{
	count++;
	i++;
	}
	return (count);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	if (n == 0)
		return (0);
	while (n > 1 && ((unsigned char)*s1 == (unsigned char)*s2) && *s1)
	{
		n--;
		s1++;
		s2++;
	}
	return ((unsigned char)*s1 - (unsigned char)*s2);
}

int	ft_strcmp(const char *s1, const char *s2, size_t n)
{
	if (n == 0)
		return (1);
	while (n > 0 && ((unsigned char)*s1 == (unsigned char)*s2) && *s1)
	{
		n--;
		s1++;
		s2++;
	}
	return ((unsigned char)*s1 - (unsigned char)*s2);
}

void lst_add(t_node **lst, char *token, int type)
{
    ft_lstadd_back(lst, ft_lstnew(type, token));
}