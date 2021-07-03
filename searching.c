#include "bsq.h"

bool	isEmpty(t_struct *bsq, int x, int y)
{
	if (bsq->map[y][x] == bsq->empty)
		return (true);
	return (false);
}

void	setVariables(t_struct *bsq)
{
	bsq->x_top = 0;
	bsq->y_top = 0;
	bsq->x_low = 0;
	bsq->y_low = 0;
	bsq->size = 0;
	bsq->size_max = 0;
}

void	setStart(t_struct *bsq)
{
	bsq->size_max = bsq->size;
	bsq->x_top = bsq->vax_top;
	bsq->x_low = bsq->vax_low;
	bsq->y_top = bsq->vay_top;
	bsq->y_low = bsq->vay_low;
}

void	startSquare(t_struct *bsq)
{
	if ((bsq->vay_low + 1) < bsq->h && (bsq->vax_low + 1) < bsq->w)
	{
		if (isEmpty(bsq, (bsq->vax_low + 1), (bsq->vay_low + 1)) == true)
		{
			if (check(bsq) == true)
			{
				bsq->vay_low++;
				bsq->vax_low++;
				startSquare(bsq);
				bsq->size++;
			}
		}
	}
	if (bsq->size > bsq->size_max)
		setStart(bsq);

}

void	startSearching(t_struct *bsq)
{
	bsq->y = 0;
	setVariables(bsq);
	while (bsq->y < bsq->h)
	{
		bsq->x = 0;
		while (bsq->x < bsq->w)
		{
			if (isEmpty(bsq, bsq->x, bsq->y) == true)
			{
				bsq->size = 1;
				bsq->vax_top = bsq->x;
				bsq->vay_top = bsq->y;
				bsq->vax_low = bsq->x;
				bsq->vay_low = bsq->y;
				startSquare(bsq);
			}
			bsq->x++;
		}
		bsq->y++;
	}
}
