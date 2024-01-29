/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_updaters_3.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amkrtumy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 23:05:09 by amkrtumy          #+#    #+#             */
/*   Updated: 2023/10/25 23:05:10 by amkrtumy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	set_row_cols(t_xy *curr, t_xy *child, t_xys *coords)
{
	curr->row = coords->curr_cell->row;
	curr->col = coords->curr_cell->col;
	child->row = coords->child_cell->row;
	child->col = coords->child_cell->col;
}

void	set_content(t_key_value *content, t_xy child, t_xy curr)
{
	content->key.row = child.row;
	content->key.col = child.col;
	content->value.row = curr.row;
	content->value.col = curr.col;
}

t_xys	pack_coorniates(t_xy dims, t_xy *curr, t_xy *child, t_xy e_xy)
{
	t_xys	coords;

	coords.dims = dims;
	coords.child_cell = child;
	coords.curr_cell = curr;
	coords.e_xy = e_xy;
	return (coords);
}

void	switch_places(int pos, t_mlx *mlx, int row, int col)
{
	check_pos(mlx, pos, row, col);
	mlx->coin_count = get_coin_count(mlx->char_mat, mlx->dims);
	if (mlx->coin_count == 0)
		mlx->door_cur = mlx->door_open;
	if (mlx->coin_count == 0 && mlx->p_xy.row == mlx->e_xy.row \
	&& mlx->p_xy.col == mlx->e_xy.col)
		on_exit_sl("Good job!");
	redraw_map(pos, *mlx, mlx->p_xy.row, mlx->p_xy.col);
}
