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

void	init(t_mlx *mlx, t_xy *dims, t_const *constants)
{
	ft_lstclear(&(mlx->lst));
	mlx->lst = NULL;
	init_nsew(mlx, *dims);
	constants->exit_exists = 0;
	constants->coin_count = get_coin_count(mlx->char_mat, *dims);
}

void	initalize_info(t_check_path *info, t_mlx *mlx, int enemy_num)
{
	info->dest_xy = mlx->p_xy;
	info->start_xy = mlx->enemies[enemy_num];
	info->last_xy.value.row = mlx->p_xy.row;
	info->last_xy.value.col = mlx->p_xy.col;
}
