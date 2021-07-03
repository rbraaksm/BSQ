#include "bsq.h"

void	setWidthHeightChar(t_struct *bsq, char *str)
{
	int	i;
	int	nb;

	i = 0;
	nb = 0;
	while (str[i] != '.')
	{
		nb += str[i] - 48;
		if (i == 0)
			nb *= 10;
		i++;
	}
	bsq->w = nb;
	bsq->h = nb;
	bsq->object = 'o';
	bsq->empty = '.';
	bsq->fill = 'x';
	bsq->map = calloc((bsq->w + 1), sizeof(char **));
	i = 0;
	while (i < bsq->w)
	{
		bsq->map[i] = calloc(bsq->w + 1, sizeof(char));
		i++;
	}
}

void	setStruct(t_struct *bsq)
{
	char	*str;
	int		fd;
	int		i;
	int		ret;

	ret = 1;
	fd = open("map", O_RDONLY);
	bsq->w = 0;
	i = 0;
	while (ret > 0)
	{
		ret = get_next_line(fd, &str);
		if (bsq->w != 0)
		{
			bsq->map[i] = strdup(str);
			i++;
		}
		if (bsq->w == 0)
			setWidthHeightChar(bsq, str);
		free(str);
	}
}
