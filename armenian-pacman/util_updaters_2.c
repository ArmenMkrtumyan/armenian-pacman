/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_updaters_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amkrtumy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 20:18:52 by amkrtumy          #+#    #+#             */
/*   Updated: 2023/10/25 20:18:53 by amkrtumy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_enemy_pos(t_mlx *mlx, int *pos, t_list *last, int enemy_num)
{
	if (mlx->enemies[enemy_num].row != last->content.value.row)
	{
		*pos = DOWN;
		if (mlx->enemies[enemy_num].row > last->content.value.row)
			*pos = UP;
	}
	else if (mlx->enemies[enemy_num].col != last->content.value.col)
	{
		*pos = RIGHT;
		if (mlx->enemies[enemy_num].col > last->content.value.col)
			*pos = LEFT;
	}
}

void	move_enemy(t_list *enemy_path, t_mlx *mlx, int enemy_num)
{
	t_list	*last;
	int		pos;

	if (hit_enemy(mlx))
		on_exit_sl("You lost!");
	ft_lstdellast(&enemy_path);
	last = ft_lstlast(enemy_path);
	if (!mlx->enemies[enemy_num].path_exists)
	{
		return ;
	}
	check_enemy_pos(mlx, &pos, last, enemy_num);
	mlx->enemies[enemy_num].row = last->content.value.row;
	mlx->enemies[enemy_num].col = last->content.value.col;
	redraw_map_enemy(pos, *mlx, mlx->enemies[enemy_num].row, \
	mlx->enemies[enemy_num].col);
	ft_lstdellast(&enemy_path);
	if (hit_enemy(mlx))
		on_exit_sl("You lost!");
}

void	fix_coordinates(int k, t_xy *child_cell, t_xy curr_cell)
{
	if (k == 0)
	{
		child_cell->row = curr_cell.row - 1;
		child_cell->col = curr_cell.col;
	}
	else if (k == 1)
	{
		child_cell->row = curr_cell.row + 1;
		child_cell->col = curr_cell.col;
	}
	else if (k == 2)
	{
		child_cell->row = curr_cell.row;
		child_cell->col = curr_cell.col + 1;
	}
	else if (k == 3)
	{
		child_cell->row = curr_cell.row;
		child_cell->col = curr_cell.col - 1;
	}
}
