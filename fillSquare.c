#include "bsq.h"

// void	clearEmpty(t_struct *bsq)
// {

// }

void	fillSquare(t_struct* bsq)
{
	int x;
	int	y;

	x = bsq->x_top;
	y = bsq->y_top;
	if (bsq->size == 1)
		bsq->map[y][x] = bsq->fill;

	while (y < bsq->y_low)
	{
		x = bsq->x_top;
		while (x < bsq->x_low)
		{
			bsq->map[y][x] = bsq->fill;
			x++;
		}
		y++;
	}
	// clearEmpty(bsq);
	// printMap(bsq);
}