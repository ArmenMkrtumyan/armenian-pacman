/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amkrtumy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 16:19:29 by amkrtumy          #+#    #+#             */
/*   Updated: 2023/10/06 16:19:31 by amkrtumy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_letters(char letter, char *array, t_xy *e, t_xy *i_k)
{
	if (letter == '1' || letter == '0')
		return (1);
	if (letter == 'C')
		array[0]++;
	else if (letter == 'E')
	{
		array[1]++;
		e->row = i_k->row;
		e->col = i_k->col;
	}
	else if (letter == 'P')
		array[2]++;
	else if (letter == 'M')
		array[3]++;
	if (letter == 'C' || letter == 'E' || letter == 'P' || letter == 'M')
		return (1);
	return (0);
}

void	count_norm(t_mlx *mlx, t_xy *e, t_xy dims, char *letters)
{
	char	element;
	t_xy	i_k;

	i_k.row = -1;
	while (++i_k.row < dims.row)
	{
		i_k.col = -1;
		while (++i_k.col < dims.col)
		{
			element = mlx->char_mat[i_k.row][i_k.col];
			if ((element != '1') && (i_k.col == 0 || \
			i_k.col == dims.col - 1 || i_k.row == 0 || \
			i_k.row == dims.row - 1))
				on_exit_sl("Wrong insides!");
			else if (check_letters(element, letters, e, &i_k))
				continue ;
			else
				on_exit_sl("Wrong insides!");
		}
	}
}

void	count_check(t_xy dims, t_inside *insides, t_mlx *mlx)
{
	char			letters[5];
	t_xy			e;

	letters_init(letters);
	count_norm(mlx, &e, dims, letters);
	mlx->enemy_count = letters[3] - '0';
	if (letters[0] == '0' || letters[1] != '1' || letters[2] != '1')
		on_exit_sl("Wrong insides!");
	init_inside(insides, mlx, dims, e);
}

void	fill_mat_continue(t_mlx *mlx, t_fileRead *fd, t_xy *dims)
{
	if (fd->sz == 0)
		mlx->char_mat[dims->row][dims->col] = '\0';
	else
	{
		mlx->char_mat[dims->row][dims->col] = fd->symbol[0];
		mlx->pos_mat[dims->row][dims->col].cost = INT_MAX - 1;
		(mlx->pos_mat[dims->row][dims->col]).visited = 1;
		if (fd->symbol[0] == 'E')
		{
			mlx->e_xy.row = dims->row;
			mlx->e_xy.col = dims->col;
		}
		if (fd->symbol[0] == 'P')
		{
			(mlx->pos_mat[dims->row][dims->col]).cost = 0;
			(mlx->pos_mat[dims->row][dims->col]).cost = 0;
			mlx->p_xy.row = dims->row;
			mlx->p_xy.col = dims->col;
		}
	}
}

void	fill_matrices(t_xy *dims, t_fileRead *fd, t_mlx *mlx)
{
	fd->sz = 1;
	while (fd->sz != 0)
	{
		fd->sz = read(fd->fd, fd->symbol, 1);
		fd->symbol[fd->sz] = '\0';
		fill_mat_continue(mlx, fd, dims);
		dims->col++;
		if (fd->symbol[0] == '\n' || fd->sz == 0)
		{
			mlx->char_mat[dims->row][dims->col - 1] = 0;
			mlx->char_mat[dims->row][dims->col - 1] = 0;
			dims->row += 1;
			dims->col = 0;
		}
	}
}
//letters[0] - C
//letters[1] - E
//letters[2] - P
//letters[3] - M
