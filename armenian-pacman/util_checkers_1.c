/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amkrtumy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 16:19:14 by amkrtumy          #+#    #+#             */
/*   Updated: 2023/10/06 16:19:15 by amkrtumy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_visited(t_pos **matrix, t_xy dims)
{
	int	i;
	int	k;

	i = -1;
	while (++i < dims.row)
	{
		k = -1;
		while (++k < dims.col)
		{
			if (matrix[i][k].visited == 1)
				return (1);
		}
	}
	return (0);
}

void	check_exit(t_xys *coords, t_const *constants)
{
	if (coords->child_cell->row == coords->e_xy.row \
	&& coords->child_cell->col == coords->e_xy.col)
		constants->exit_exists = 1;
}

int	check_wall(int wall, t_const *constants, t_mlx *mlx, int enemy_num)
{
	if (wall)
	{
		if (constants->exit_exists == 0)
		{
			if (mlx->enemy_perspective)
			{
				mlx->path_exists = 1;
				mlx->enemies[enemy_num].path_exists = 0;
				return (1);
			}
			ft_printf("\n\nCouldnt Find an EXIT!!!!\n\n");
			mlx->path_exists = 0;
		}
		else
			second_part(constants, mlx);
		return (1);
	}
	return (0);
}

int	ft_strncmp(char *str1, char *str2, int n)
{
	int	i;

	i = 0;
	if (get_len(str1) != 4)
		return (1);
	while (i < n)
	{
		if (str1[i] != str2[i])
			return (1);
		i++;
	}
	return (0);
}

int	check_dimensions_map(int fd, t_xy *dims)
{
	int		sz;
	char	symbol[2];
	int		fix_cols;

	fix_cols = -1;
	sz = 1;
	while (sz != 0)
	{
		sz = read(fd, symbol, 1);
		symbol[sz] = '\0';
		if ((dims->row) - 1 == 0)
			fix_cols++;
		(dims->col)++;
		if (symbol[0] == '\n')
		{
			(dims->row)++;
			if (dims->col != fix_cols)
				return (0);
			dims->col = -1;
		}
	}
	if (dims->col != fix_cols || dims->row < 3)
		return (0);
	dims->col = fix_cols;
	return (1);
}
