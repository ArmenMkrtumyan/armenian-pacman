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

void	second_part(t_const *constants, t_mlx *mlx)
{
	if (constants->coin_count == 0)
	{
		if (mlx->enemy_perspective != 1)
			ft_printf("\n\nEXIT EXISTS AND COINS ARE ACCESSIBLE!\n\n");
		mlx->path_exists = 1;
	}
	else
	{
		if (mlx->enemy_perspective != 1)
			ft_printf("\n\nEXIT EXISTS BUT COINS ARE UNAVAILABLE!\n\n");
		mlx->path_exists = 0;
	}
}
