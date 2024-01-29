/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amkrtumy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 16:18:57 by amkrtumy          #+#    #+#             */
/*   Updated: 2023/10/06 16:19:02 by amkrtumy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	draw_space_player(int pos, t_mlx mlx, int p_row, int p_col)
{
	if (pos == UP && !(p_col == mlx.e_xy.col && p_row + 1 == mlx.e_xy.row))
		mlx_put_image_to_window(mlx.mlx_ptr, mlx.mlx_win, mlx.empty_space, \
		p_col * mlx.xy, (p_row + 1) * mlx.xy);
	else if (pos == DOWN \
	&& !(p_col == mlx.e_xy.col && p_row -1 == mlx.e_xy.row))
		mlx_put_image_to_window(mlx.mlx_ptr, mlx.mlx_win, mlx.empty_space, \
		p_col * mlx.xy, (p_row - 1) * mlx.xy);
	else if (pos == LEFT \
	&& !(p_col + 1 == mlx.e_xy.col && p_row == mlx.e_xy.row))
		mlx_put_image_to_window(mlx.mlx_ptr, mlx.mlx_win, mlx.empty_space, \
		(p_col + 1) * mlx.xy, p_row * mlx.xy);
	else if (pos == RIGHT \
	&& !(p_col - 1 == mlx.e_xy.col && p_row == mlx.e_xy.row))
		mlx_put_image_to_window(mlx.mlx_ptr, mlx.mlx_win, mlx.empty_space, \
		(p_col - 1) * mlx.xy, p_row * mlx.xy);
}

void	redraw_map(int pos, t_mlx mlx, int p_row, int p_col)
{
	mlx_put_image_to_window(mlx.mlx_ptr, mlx.mlx_win, mlx.pacman_eating, \
	mlx.xy * p_col, mlx.xy * p_row);
	if (!(p_row == mlx.e_xy.row && p_col == mlx.e_xy.col))
	{
		mlx_put_image_to_window(mlx.mlx_ptr, mlx.mlx_win, mlx.empty_space, \
		mlx.xy * mlx.e_xy.col, mlx.xy * mlx.e_xy.row);
		mlx_put_image_to_window(mlx.mlx_ptr, mlx.mlx_win, mlx.door_cur, \
		mlx.xy * mlx.e_xy.col, mlx.xy * mlx.e_xy.row);
		mlx_put_image_to_window(mlx.mlx_ptr, mlx.mlx_win, mlx.empty_space, \
		mlx.xy * p_col, mlx.xy * p_row);
		mlx_put_image_to_window(mlx.mlx_ptr, mlx.mlx_win, mlx.pacman_eating, \
		mlx.xy * p_col, mlx.xy * p_row);
	}
	draw_space_player(pos, mlx, p_row, p_col);
}

void	draw_coin_enemy(t_mlx mlx, int row, int col)
{
	mlx_put_image_to_window(mlx.mlx_ptr, mlx.mlx_win, mlx.empty_space, \
	col * mlx.xy, (row) * mlx.xy);
	if (mlx.char_mat[row][col] == 'C')
		mlx_put_image_to_window(mlx.mlx_ptr, mlx.mlx_win, mlx.coin, \
		col * mlx.xy, (row) * mlx.xy);
}

void	redraw_map_enemy(int pos, t_mlx mlx, int e_row, int e_col)
{
	if (!(e_row == mlx.e_xy.row && e_col == mlx.e_xy.col))
	{
		mlx_put_image_to_window(mlx.mlx_ptr, mlx.mlx_win, mlx.empty_space, \
		mlx.xy * mlx.e_xy.col, mlx.xy * mlx.e_xy.row);
		mlx_put_image_to_window(mlx.mlx_ptr, mlx.mlx_win, mlx.door_cur, \
		mlx.xy * mlx.e_xy.col, mlx.xy * mlx.e_xy.row);
		mlx_put_image_to_window(mlx.mlx_ptr, mlx.mlx_win, mlx.empty_space, \
		mlx.xy * e_col, mlx.xy * e_row);
		mlx_put_image_to_window(mlx.mlx_ptr, mlx.mlx_win, mlx.enemy, \
		mlx.xy * e_col, mlx.xy * e_row);
	}
	else
		mlx_put_image_to_window(mlx.mlx_ptr, mlx.mlx_win, mlx.enemy, \
		mlx.xy * e_col, mlx.xy * e_row);
	if (pos == UP && !(e_col == mlx.e_xy.col && e_row + 1 == mlx.e_xy.row))
		draw_coin_enemy(mlx, e_row + 1, e_col);
	else if (pos == DOWN \
	&& !(e_col == mlx.e_xy.col && e_row - 1 == mlx.e_xy.row))
		draw_coin_enemy(mlx, e_row - 1, e_col);
	else if (pos == LEFT \
	&& !(e_col + 1 == mlx.e_xy.col && e_row == mlx.e_xy.row))
		draw_coin_enemy(mlx, e_row, e_col + 1);
	else if (pos == RIGHT \
	&& !(e_col - 1 == mlx.e_xy.col && e_row == mlx.e_xy.row))
		draw_coin_enemy(mlx, e_row, e_col - 1);
}
