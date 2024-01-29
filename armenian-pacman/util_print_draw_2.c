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

void	draw_map_images(t_mlx *mlx, int k, int i)
{
	if (mlx->char_mat[k][i] == '0')
		mlx_put_image_to_window(mlx->mlx_ptr, mlx->mlx_win, \
		mlx->empty_space, i * mlx->xy, k * mlx->xy);
	else if (mlx->char_mat[k][i] == '1')
		mlx_put_image_to_window(mlx->mlx_ptr, mlx->mlx_win, \
		mlx->wall, i * mlx->xy, k * mlx->xy);
	else if (mlx->char_mat[k][i] == 'C')
		mlx_put_image_to_window(mlx->mlx_ptr, mlx->mlx_win, \
		mlx->coin, i * mlx->xy, k * mlx->xy);
	else if (mlx->char_mat[k][i] == 'M')
		mlx_put_image_to_window(mlx->mlx_ptr, mlx->mlx_win, \
		mlx->enemy, i * mlx->xy, k * mlx->xy);
	else if (mlx->char_mat[k][i] == 'P')
		mlx_put_image_to_window(mlx->mlx_ptr, mlx->mlx_win, \
		mlx->pacman_eating, i * mlx->xy, k * mlx->xy);
	else if (mlx->char_mat[k][i] == 'E')
		mlx_put_image_to_window(mlx->mlx_ptr, mlx->mlx_win, \
		mlx->door_cur, i * mlx->xy, k * mlx->xy);
}

void	draw_map(t_mlx *mlx)
{
	int	k;
	int	i;

	k = -1;
	while (mlx->char_mat[++k])
	{
		i = -1;
		while (mlx->char_mat[k][++i])
			draw_map_images(mlx, k, i);
	}
}
