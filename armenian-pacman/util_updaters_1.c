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

void	change_weights(t_xys *coords, t_const *constants, t_mlx *mlx)
{
	static int	dir[5];
	int			k;
	t_xy		child;

	init_directions(dir, mlx, *coords->curr_cell);
	k = 0;
	while (k < 4)
	{
		if (dir[k] == 1)
		{
			constants->temp_dist = 0;
			fix_coordinates(k, coords->child_cell, *coords->curr_cell);
			check_exit(coords, constants);
			child.row = coords->child_cell->row;
			child.col = coords->child_cell->col;
			if (mlx->pos_mat[child.row][child.col].visited == 0 || \
			mlx->pos_mat[child.row][child.col].cost != INT_MAX - 1)
			{
				k++;
				continue ;
			}
			update_weights(coords, constants, mlx);
		}
		k++;
	}
}

void	update_weights(t_xys *coords, t_const *constants, t_mlx *mlx)
{
	t_xy		child;
	t_xy		curr;
	t_key_value	content;

	set_row_cols(&curr, &child, coords);
	constants->temp_dist = mlx->pos_mat[curr.row][curr.col].cost;
	if (mlx->char_mat[child.row][child.col] == 'C'
		&& mlx->enemy_perspective == 0)
	{
		constants->temp_dist += 1;
		constants->coin_count -= 1;
	}
	else if (mlx->char_mat[child.row][child.col] == 'M')
		constants->temp_dist += 100;
	else
		constants->temp_dist = \
		mlx->pos_mat[curr.row][curr.col].cost + 10;
	if (constants->temp_dist < mlx->pos_mat[child.row][child.col].cost)
	{
		mlx->pos_mat[child.row][child.col].cost = constants->temp_dist;
		set_content(&content, child, curr);
		ft_lstadd_back(&(mlx->lst), ft_lstnew(content));
	}
}

void	update_weights_after_move(t_mlx *mlx)
{
	int			enemy_num;

	enemy_num = 0;
	mlx->enemy_perspective = 1;
	while (enemy_num < mlx->enemy_count)
	{
		ft_lstclear(&(mlx->enemies[enemy_num].enemy_path));
		mlx->enemies[enemy_num].enemy_path = NULL;
		mlx->start_xy.enemy_path = mlx->enemies[enemy_num].enemy_path;
		update_visited_and_costs(mlx, mlx->enemies[enemy_num]);
		check_path(mlx->dims, mlx->e_xy, mlx, enemy_num);
		move_enemy(mlx->enemies[enemy_num].enemy_path, mlx, enemy_num);
		enemy_num++;
	}
}

void	update_visited_and_costs(t_mlx *mlx, t_xy zero_position)
{
	int	k2;
	int	i2;

	i2 = -1;
	while (++i2 < mlx->dims.row)
	{
		k2 = -1;
		while (++k2 < mlx->dims.col)
		{
			mlx->pos_mat[i2][k2].cost = INT_MAX - 1;
			mlx->pos_mat[i2][k2].visited = 1;
		}
	}
	mlx->pos_mat[zero_position.row][zero_position.col].cost = 0;
}
