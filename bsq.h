#ifndef BSQ_HPP
# define BSQ_HPP

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <limits.h>
# include <string.h>
# include <time.h>
# include <fcntl.h>
# include <stdbool.h>

# define RAND 100
# define BUFFER_SIZE 1024

typedef struct	s_struct{
	char	**map;
	int		w;
	int		h;
	char	object;
	char	empty;
	char	fill;
	int		x_top;
	int		y_top;
	int		x_low;
	int		y_low;
	int		size_max;
	int		vax_top;
	int		vax_low;
	int		vay_top;
	int		vay_low;
	int		size;
	int		x;
	int		y;
}				t_struct;

void	createMap(void);
void	setStruct(t_struct *bsq);
void	startSearching(t_struct *bsq);
bool	check(t_struct *bsq);
bool	isEmpty(t_struct *bsq, int x, int y);
void	fillSquare(t_struct* bsq);
int		get_next_line(int fd, char **line);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strjoin(char const *s1, char const *s2);

void	printMap(t_struct *bsq);
#endif
