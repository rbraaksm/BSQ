#include "bsq.h"

char*	mergeNumbers(int *x)
{
	char	*ret;
	char	str[3][3];
	int		i;

	i = 0;
	ret = malloc(sizeof(char *) + 8);
	while (i < 3)
	{
		sprintf(str[i], "%d", x[i]);
		strcpy(&ret[strlen(ret)], str[i]);
		strcpy(&ret[strlen(ret)], " ");
		i++;
	}
	return (ret);
}

char*	createMiddle(void)
{
	int		x[3];

	srand(time(NULL));
	x[0] = 0;
	while (x[0] < 10)
		x[0] = rand() % RAND;
	x[1] = x[0];
	x[2] = 7;
	return (mergeNumbers(x));
}

char	*createCommand(void)
{
	char	*ret;
	char	*str[3];
	int		i;

	i = 0;
	str[0] = "perl mapGenerator ";
	str[1] = createMiddle();
	str[2] = "> map";
	ret = malloc(sizeof(char *) + (strlen(str[0]), strlen(str[1]),
				strlen(str[2]) + 1));
	while (i < 3)
	{
		strcpy(&ret[strlen(ret)], str[i]);
		i++;
	}
	ret[strlen(ret)] = '\0';
	return (ret);
}

void	createMap(void)
{
	char	*str;
	char	ret[50];

	str = createCommand();
	strcpy(ret, str);
	system(ret);
}
