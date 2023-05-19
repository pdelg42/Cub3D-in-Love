/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdel-giu <gdel-giu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 04:28:13 by gdel-giu          #+#    #+#             */
/*   Updated: 2023/05/19 06:00:21 by gdel-giu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/program.h"

// variabili hardcoded
int player_angle = -1;
float playerPosX = WIN_SIZE_H / 2;
float playerPosH = WIN_SIZE_W / 2;
float hx = WIN_SIZE_W / 2;
float hy = WIN_SIZE_H / 2;
float disH = (unsigned int) -1;
float disV = (unsigned int) -1;

float   ang2rad(float ang)
{
    ang = (float) player_angle - (M_PI4/45) * 30;
    if (ang < 0)
        ang += 2 * M_PI;
    else if (ang > 0)
        ang -= 2 * M_PI;
    retrun (ang);
}

void    draw2d(t_cub *cub)
{
    int     r;
    float   atan;
    float   ra;
    float   ry, rx

    r = 0;
    ra = ang2rad(player_angle);
    while (r++ < WIN_SIZE_H)
    {
        atan = -1 / tan(player_angle);
        if (ra > M_PI)
        {
            ry = (int) 0;
        }
    }
}