/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dokwak_main.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dokwak <dokwak@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/18 09:15:56 by dokwak            #+#    #+#             */
/*   Updated: 2021/09/19 23:31:14 by dokwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

int		unique_check(char **board, int pos[2], int len, int val);
int		view_check(char **board, char	**hint, int	*pos, int length);
void	fillin_the_board(char **board, char **hint, int len, int tar);
void	print_board(char **board, int size);
void	reset_board(char **board, int len, int *pos);
/*int		last_check(char **board, char **hint, int len);*/

void	print_board(char **board, int length)
{
	int		i;
	int		j;

	i = 0;
	while (i < length)
	{
		j = 0;
		while (j < length)
		{
			write(1, &board[i][j], 1);
			write(1, " ", 1);
			j++;
		}
		i++;
		write(1, "\n", 1);
	}
}

/* pos[0] means row, pos[1] means col */
void	fillin_the_board(char **board, char	**hint, int len, int tar)
{
	int	k;
	int	pos[2];

	pos[0] = ((len * len) - tar) / len;
	pos[1] = ((len * len) - tar) % len;
	if (tar == 0)
	{
		print_board(board, len);
		return ;
	}
	k = 1;
	while (k <= len)
	{
		board[pos[0]][pos[1]] = k + '0';
		if (unique_check(board, pos, len, k)
			&& view_check(board, hint, pos, len))
		{
			fillin_the_board(board, hint, len, tar - 1);
		}
		else
			reset_board(board, len, pos);
		k++;
	}
	return ;
}

void	reset_board(char **board, int len, int *pos)
{
	int	row;
	int	col;

	row = pos[0];
	col = pos[1];
	while (row < len)
	{
		while (col < len)
		{
			board[row][col] = '0';
			col++;
		}
		col = 0;
		row++;
	}
}
