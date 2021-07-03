#include "bsq.h"

void	printMap(t_struct *bsq)
{
	FILE *fp;

	fp = fopen("result.txt", "w");
	int i = 0;
	while (bsq->map[i])
	{
		fprintf(fp, "%s\n", bsq->map[i]);
		i++;
	}
}

int main(void)
{
	t_struct *bsq;

	bsq = malloc(sizeof(t_struct*));
	createMap();
	setStruct(bsq);
	startSearching(bsq);
	fillSquare(bsq);
	printMap(bsq);
	return (0);
}