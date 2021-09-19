/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dokwak <dokwak@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/19 23:34:34 by dokwak            #+#    #+#             */
/*   Updated: 2021/09/19 23:34:44 by dokwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	view_check_row_from_l(char **board, char *row_left, int row, int len);
int	view_check_row_from_r(char **board, char *row_right, int row, int len);
int	view_check_col_from_u(char **board, char *col_up, int col, int len);
int	view_check_col_from_d(char **board, char *col_down, int col, int len);

int	view_check(char **board, char **hint, int pos[2], int len)
{
	int	row;
	int	col;

	row = pos[0];
	col = pos[1];
	if (view_check_row_from_l(board, hint[2], row, len)
		&& view_check_row_from_r(board, hint[3], row, len)
		&& view_check_col_from_u(board, hint[0], col, len)
		&& view_check_col_from_d(board, hint[1], col, len))
		return (1);
	else
		return (0);
}

int	view_check_row_from_l(char **board, char *row_left, int row, int len)
{
	char	view_left;
	char	count;
	char	biggest_box;
	int		index;

	view_left = row_left[row];
	count = '0';
	index = 0;
	biggest_box = '0';
	while (index < len)
	{
		if (board[row][index] > biggest_box)
		{
			count++;
			biggest_box = board[row][index];
			if (count > view_left)
				return (0);
		}
		index++;
	}
	return (count);
}

int	view_check_row_from_r(char **board, char *row_right, int row, int len)
{
	char	view_right;
	char	count;
	char	biggest_box;
	int		index;

	view_right = row_right[row];
	count = '0';
	index = len - 1;
	biggest_box = '0';
	while (index >= 0)
	{
		if (board[row][index] > biggest_box)
		{
			count++;
			biggest_box = board[row][index];
			if (count > view_right)
				return (0);
		}
		index--;
	}
	return (count);
}

int	view_check_col_from_u(char **board, char *col_up, int col, int len)
{
	char	view_up;
	char	count;
	char	biggest_box;
	int		index;

	view_up = col_up[col];
	count = '0';
	index = 0;
	biggest_box = '0';
	while (index < len - 1)
	{
		if (board[index][col] > biggest_box)
		{
			count++;
			biggest_box = board[index][col];
			if (count > view_up)
				return (0);
		}
		index++;
	}
	return (count);
}

int	view_check_col_from_d(char **board, char *col_down, int col, int len)
{
	char	view_down;
	char	count;
	char	biggest_box;
	int		index;

	view_down = col_down[col];
	count = '0';
	index = len - 1;
	biggest_box = '0';
	while (index >= 0)
	{
		if (board[index][col] > biggest_box)
		{
			count++;
			biggest_box = board[index][col];
			if (count > view_down)
				return (0);
		}
		index--;
	}
	return (count);
}
