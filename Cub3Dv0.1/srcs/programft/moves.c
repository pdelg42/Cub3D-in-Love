/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgerace <sgerace@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 10:05:25 by sgerace           #+#    #+#             */
/*   Updated: 2023/05/30 13:55:51 by sgerace          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/program.h"

void	try_move(t_cub *cub, int key)
{
	if (check_wall_collision(cub, key))
		return ;
	else if (key == 1)
	{
		cub->player_pos.x -= cub->player_pos.dirx * MOVESTEP;
		cub->player_pos.y -= cub->player_pos.diry * MOVESTEP;
	}
	else if (key == 13)
	{
		cub->player_pos.x += cub->player_pos.dirx * MOVESTEP;
		cub->player_pos.y += cub->player_pos.diry * MOVESTEP;
	}
	else if (key == 0)
	{
		cub->player_pos.x += cub->player_pos.diry * MOVESTEP;
		cub->player_pos.y -= cub->player_pos.dirx * MOVESTEP;
	}
	else if (key == 2)
	{
		cub->player_pos.x -= cub->player_pos.diry * MOVESTEP;
		cub->player_pos.y += cub->player_pos.dirx * MOVESTEP;
	}
	if (key == 124 || key == 123)
		rotate_player(cub, key, THREE_DEG);
	return ;
}

int	moves_loop(t_cub *cub, int key)
{
	if (key == 13)
		try_move(cub, 13);
	if (key == 0)
		try_move(cub, 0);
	if (key == 1)
		try_move(cub, 1);
	if (key == 2)
		try_move(cub, 2);
	if (key == 124)
		try_move(cub, 124);
	if (key == 123)
		try_move(cub, 123);
	start_game(cub);
	return (0);
}

int	move(int key, t_cub *cub)
{
	if (key == 53)
		exit_call(cub);
	moves_loop(cub, key);
	return (1);
}

int	stop_motion(int key, t_cub *cub)
{
	cub->key_state[key] = 0;
	return (0);
}
