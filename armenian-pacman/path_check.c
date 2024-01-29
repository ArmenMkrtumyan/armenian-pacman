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

void	calculate_enemy_path(t_check_path *info, t_mlx *mlx, int enemy_num)
{
	ft_lstclear(&(mlx->enemies[enemy_num].enemy_path));
	mlx->enemies[enemy_num].enemy_path = NULL;
	if (mlx->enemies[enemy_num].path_exists == 0)
		return ;
	initalize_info(info, mlx, enemy_num);
	ft_lstadd_back(&mlx->enemies[enemy_num].enemy_path, \
	ft_lstnew(info->last_xy));
	while (info->dest_xy.row != info->start_xy.row \
	|| info->dest_xy.col != info->start_xy.col)
	{
		info->temp = mlx->lst;
		while (info->temp != NULL)
		{
			if (info->temp->content.key.row == info->dest_xy.row \
			&& info->temp->content.key.col == info->dest_xy.col)
			{
				ft_lstadd_back(&(mlx->enemies[enemy_num].enemy_path), \
					ft_lstnew(info->temp->content));
				info->dest_xy = info->temp->content.value;
			}
			info->temp = info->temp->next;
		}
	}
	info->temp = mlx->enemies[enemy_num].enemy_path;
}

void	check_path(t_xy dims, t_xy e, t_mlx *mlx, int enemy_num)
{
	t_check_path	check_path_info;
	t_xy			curr_cell;
	t_xy			child_cell;
	t_const			constants;
	t_xys			coords;

	init(mlx, &dims, &constants);
	while (check_visited(mlx->pos_mat, dims))
	{
		curr_cell = get_min(mlx->pos_mat, dims, mlx->char_mat);
		mlx->pos_mat[curr_cell.row][curr_cell.col].visited = 0;
		if (check_wall(curr_cell.wall, &constants, mlx, enemy_num))
			break ;
		if (curr_cell.row == e.row && \
		curr_cell.col == e.col && constants.coin_count == 0)
			constants.exit_exists = 1;
		coords = pack_coorniates(dims, &curr_cell, &child_cell, e);
		change_weights(&coords, &constants, mlx);
	}
	if (mlx->enemy_perspective == 1)
		calculate_enemy_path(&check_path_info, mlx, enemy_num);
	mlx->dims = dims;
}
