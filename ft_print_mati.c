#include "libft.h"

void	ft_print_mati(int**mat, int max_width)
{
	int	x;
	int	y;

	y = 0;
	while (mat[y])
	{
		x = 0;
		while (x < max_width)
		{
			ft_putnbr(mat[y][x], 1);
			x++;
			if (x < max_width)
				write(1, 32, 1);
		}
		write(1, "\n", 1);
		y++;
	}
}
