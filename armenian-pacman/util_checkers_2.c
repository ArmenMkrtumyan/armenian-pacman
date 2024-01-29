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

int	check_file_name(char *file_name)
{
	int	len;

	len = get_len(file_name);
	while (file_name[len] != '.')
		len--;
	if (len == 0)
	{
		ft_printf("Error\nInput correct map name!\n");
		return (0);
	}
	if (ft_strncmp(&file_name[len], ".ber", 4) != 0)
	{
		ft_printf("Error\nInput correct map name!\n");
		return (0);
	}
	return (1);
}

void	assign_message(int num_of_moves, t_mlx *mlx)
{
	char	*message;
	char	*first_part;

	free(mlx->message);
	first_part = "Moves: ";
	message = ft_itoa(num_of_moves);
	mlx->message = ft_strjoin(first_part, message);
	free(message);
}

void	check_pos(t_mlx *mlx, int pos, int row, int col)
{
	mlx->char_mat[row][col] = '0';
	if (pos == UP)
	{
		mlx->char_mat[row - 1][col] = 'P';
		mlx->p_xy.row = row - 1;
	}
	else if (pos == DOWN)
	{
		mlx->char_mat[row + 1][col] = 'P';
		mlx->p_xy.row = row + 1;
	}
	else if (pos == LEFT)
	{
		mlx->char_mat[row][col - 1] = 'P';
		mlx->p_xy.col = col - 1;
	}
	else if (pos == RIGHT)
	{
		mlx->char_mat[row][col + 1] = 'P';
		mlx->p_xy.col = col + 1;
	}
	assign_message(mlx->num_of_moves - 1, mlx);
	mlx_string_put(mlx->mlx_ptr, mlx->mlx_win, 20, 20, 0, mlx->message);
	assign_message(mlx->num_of_moves++, mlx);
	mlx_string_put(mlx->mlx_ptr, mlx->mlx_win, 20, 20, 56789, mlx->message);
}

void	checkings(int fd1, int fd2, t_xy dims, t_mlx *mlx)
{
	t_inside		insides;

	if (check_dimensions_map(fd1, &dims))
	{
		if (check_insides_map(fd2, dims, &insides, mlx) == 0)
		{
			mlx->enemy_perspective = 0;
			ft_printf("\n\nCORRECT MAP INSIDES, CHECKING PATHS...");
			check_path(insides.dims, insides.e_xy, mlx, 0);
			if (mlx->path_exists == 1)
				ft_printf("\n\nCORRECT PATHS...Launching the game\n\n");
			else
				on_exit_sl("Issue with paths!");
		}
	}
	else
		on_exit_sl("\n\nWRONG DIMENSIONS\n\n");
}

int	check_insides_map(int fd, t_xy dims, t_inside *insides, t_mlx *mlx)
{
	t_xy			temp_dimensions;
	t_fileRead		file_read_info;

	file_read_info.fd = fd;
	temp_dimensions.row = 0;
	temp_dimensions.col = 0;
	temp_dimensions.col = 0;
	create_matrices(dims, mlx);
	fill_matrices(&temp_dimensions, &file_read_info, mlx);
	count_check(dims, insides, mlx);
	return (insides->freed);
}
