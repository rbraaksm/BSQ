#include "bsq.h"

void	printEnd(t_struct *bsq, int x, int y)
{
	printf("x: %d y: %d char: %c\n", x, y, bsq->map[y][x]);
}

bool	checkDownSide(t_struct *bsq)
{
	int	x;
	int	y;

	x = bsq->vax_top;
	y = bsq->vay_low;
	while (x <  bsq->vax_low)
	{
		if (isEmpty(bsq, x, y) == false)
			return (false);
		x++;
	}
	return (true);
}

bool	checkRightSide(t_struct *bsq)
{
	int	x;
	int	y;

	x = bsq->vax_low;
	y = bsq->vay_top;
	while (y <  bsq->vay_low)
	{
		if (isEmpty(bsq, x, y) == false)
			return (false);
		y++;
	}
	return (true);
}

bool	check(t_struct *bsq)
{
	if (checkRightSide(bsq) == false)
		return (false);
	if (checkDownSide(bsq) == false)
		return (false);

	return (true);
}
