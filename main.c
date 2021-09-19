/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgim <cgim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/18 17:36:46 by cgim              #+#    #+#             */
/*   Updated: 2021/09/19 20:33:09 by dokwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>
#include <unistd.h>
int	fillin_the_board(char **board, char **hint, int size, int tar);

int	count_num(char *arr)
{
	int	size;
	int	i;

	size = 0;
	i = 0;
	while (arr[i] != '\0')
	{
		if (arr[i] >= '0' && arr[i] <= '9')
			size++;
		i++;
	}
	return (size);
}

char	**allocate_arr(int len)
{
	int		i;
	char	**arr;

	arr = malloc(sizeof (char *) * len);
	i = 0;
	while (i < len)
	{
		arr[i] = malloc(sizeof (char) * len);
		i++;
	}
	return (arr);
}

char	**check_input(char	*arr, int len)
{
	int		i;
	int		j;
	int		k;
	char	**pp_arr;

	pp_arr = malloc(sizeof(char *) * 4);
	i = 0;
	while (i < 4)
		pp_arr[i++] = malloc(sizeof(char) * len);
	i = 0;
	j = 0;
	k = 0;
	while (arr[i] != '\0')
	{
		if (arr[i] >= '0' && arr[i] <= '9')
		{
			pp_arr[j][k++] = arr[i++];
			if (k == len)
			{
				k = 0;
				j++;
			}
		}
	}
	return (pp_arr);
}

void	init_board(char **board, int len)
{
	int	i;
	int	j;

	i = 0;
	while (i < len)
	{
		j = 0;
		while (j < len)
		{
			board[i][j] = '0';
			j++;
		}
		i++;
	}
}

int	main(int argc, char **argv)
{
	int		tar;
	char	**hint;
	char	**board;
	int		len;

	if (argc != 2)
		return (0);
	tar = count_num(argv[1]);
	len = tar / 4;
	hint = check_input(argv[1], len);
	board = allocate_arr(len);
	init_board(board, len);
	fillin_the_board(board, hint, len, tar);
	return (0);
}
