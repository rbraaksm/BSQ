
#include "bsq.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char		*newstr;
	int			index;
	int			index2;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	index = 0;
	index2 = 0;
	newstr = (char *)malloc(strlen(s1) + (strlen(s2) + 1) * sizeof(char));
	if (!newstr)
		return (NULL);
	while (s1[index] != '\0')
	{
		newstr[index] = s1[index];
		index++;
	}
	while (s2[index2] != '\0')
	{
		newstr[index + index2] = s2[index2];
		index2++;
	}
	newstr[index + index2] = '\0';
	return (newstr);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*newstr;
	unsigned int	index;
	size_t			count;

	index = 0;
	count = 0;
	if (!s)
		return (NULL);
	while (s[index] != '\0')
		index++;
	if (!*s || start >= index)
		return (strdup(""));
	if ((index - start) < len)
		newstr = (char *)malloc(sizeof(char) * ((index - start) + 1));
	else
		newstr = (char *)malloc(sizeof(char) * (len + 1));
	if (!newstr)
		return (NULL);
	while (count < len)
	{
		newstr[count] = s[start + count];
		count++;
	}
	newstr[count] = '\0';
	return (newstr);
}
