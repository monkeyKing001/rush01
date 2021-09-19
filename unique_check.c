/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unique_check.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dokwak <dokwak@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/19 21:28:02 by dokwak            #+#    #+#             */
/*   Updated: 2021/09/19 22:18:57 by dokwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
int	unique_check_row(char **board, int row, int col, int len)
{
	int		i;
	char	val;

	val = board[row][col];
	i = 0;
	while (i < len)
	{
		if (i != col && board[row][i] == val)
		{
			return (0);
		}
		i++;
	}
	return (1);
}

int	unique_check_col(char **board, int row, int col, int len)
{
	int		i;
	char	val;

	val = board[row][col];
	i = 0;
	while (i < len)
	{
		if (i != row && board[i][col] == val)
		{
			return (0);
		}
		i++;
	}
	return (1);
}

int	unique_check(char **board, int *pos, int len)
{
	int	row;
	int	col;

	row = pos[0];
	col = pos[1];
	if (unique_check_row(board, row, col, len)
		&& unique_check_col(board, row, col, len))
	{
		return (1);
	}
	else
	{
		return (0);
	}
}
