/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_initializers_2.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amkrtumy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 22:51:11 by amkrtumy          #+#    #+#             */
/*   Updated: 2023/10/25 22:51:13 by amkrtumy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_inside(t_inside *insides, t_mlx *mlx, t_xy dims, t_xy e)
{
	mlx->matrices.pos_info = mlx->pos_mat;
	mlx->matrices.char_info = mlx->char_mat;
	mlx->matrices.path_exists = mlx->path_exists;
	insides->matrices = mlx->matrices;
	insides->dims = dims;
	insides->e_xy = e;
	insides->freed = 0;
}

void	letters_init(char *letters)
{
	letters[0] = '0';
	letters[1] = '0';
	letters[2] = '0';
	letters[3] = '0';
	letters[4] = '\0';
}

void	init_directions(int *dir, t_mlx *mlx, t_xy curr_cell)
{
	dir[0] = mlx->pos_mat[curr_cell.row][curr_cell.col].n;
	dir[1] = mlx->pos_mat[curr_cell.row][curr_cell.col].s;
	dir[2] = mlx->pos_mat[curr_cell.row][curr_cell.col].e;
	dir[3] = mlx->pos_mat[curr_cell.row][curr_cell.col].w;
	dir[4] = '\0';
}

void	direction_init(char **maze, t_pos **matrix, int row, int col)
{
	if (maze[row + 1][col] != '1')
		(matrix[row][col]).s = 1;
	if (maze[row - 1][col] != '1')
		(matrix[row][col]).n = 1;
	if (maze[row][col + 1] != '1')
		(matrix[row][col]).e = 1;
	if (maze[row][col - 1] != '1')
		(matrix[row][col]).w = 1;
}

void	create_matrices(t_xy dim, t_mlx *mlx)
{
	int	k;

	mlx->char_mat = malloc((dim.row + 1) * sizeof(char *));
	mlx->pos_mat = malloc((dim.row + 1) * sizeof(t_pos *));
	if (!(mlx->char_mat) || !(mlx->pos_mat))
		on_exit_sl("Memory allocation failed");
	mlx->char_mat[dim.row] = NULL;
	k = 0;
	while (k < dim.row)
	{
		mlx->pos_mat[k] = malloc((dim.col + 1) * sizeof(t_pos));
		mlx->char_mat[k] = malloc((dim.col + 1) * sizeof(char));
		if (!(mlx->char_mat[k]) || !(mlx->pos_mat[k]))
			on_exit_sl("Memory allocation failed");
		k++;
	}
}
