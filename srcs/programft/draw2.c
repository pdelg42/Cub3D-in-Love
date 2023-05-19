/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdel-giu <gdel-giu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 04:28:13 by gdel-giu          #+#    #+#             */
/*   Updated: 2023/05/19 17:58:33 by gdel-giu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/program.h"

#define DR 0.0174533f

// variabili hardcoded
// float cub->player_angle = 0;
int wall_height = WIN_SIZE_H / 2;
int offset = WIN_SIZE_H / 4;
float disT = (unsigned int) -1;
int vertical_offset = 0;

float   startRayAng(float ang)
{
    ang -= DR * 30;
    if (ang < 0)
        ang += 2 * M_PI;
    else if (ang > 0)
        ang -= 2 * M_PI;
    return (ang);
}

float   dist(float ax, float ay, float bx, float by, float ang)
{
    return (sqrt(pow(bx - ax, 2.) + pow(by - ay, 2.)));
}

int    draw2d(t_cub *cub)
{
    int     r, dof;
    float   ra;
    float   ry, rx;
    float   x0, y0;
    int     mapX = ft_strlen(cub->map[0]);
    int     mapY = row_counter(cub->map);
    float   playerPosX = fixed2flo(cub->player_pos.x) * ((float) WIN_SIZE_W / (float) mapX);
    float   playerPosY = fixed2flo(cub->player_pos.y) * ((float) WIN_SIZE_H / (float) mapY);
    float hx = playerPosX;
    float hy = playerPosY;
    float vx = playerPosX;
    float vy = playerPosY;

    // draw base
    for (int y = 0; y < WIN_SIZE_H; y++)
    {
        for (int x = 0; x < WIN_SIZE_W; x++)
        {
            if (y > (WIN_SIZE_H / 2))
                my_mlx_pixel_put(cub->data, x, y, 0x0055ee66);
            else
                my_mlx_pixel_put(cub->data, x, y, 0x005566ee);
        }
    }
    //

    r = 0;
    dof = 0;
    ra = startRayAng(cub->player_angle);
    while (r < 60)
    {
        
        float disH = (unsigned int) -1;
        float disV = (unsigned int) -1;
        // looking up - down
        float atan = -1 / tan(ra);
        if (ra > M_PI)
        {
            ry = (((int) playerPosY >> 6) << 6) - 0.0001f;
            rx = (playerPosY - ry) * atan + playerPosX;
            y0 = -(mapX * mapY);
            x0 = -y0 * atan;
        }
        if (ra < M_PI)
        {
            ry = (((int) playerPosY >> 6) << 6);
            rx = (playerPosY - ry) * atan + playerPosX;
            y0 = (mapX * mapY);
            x0 = -y0 * atan;
        }
        if (ra == 0 || ra == M_PI) 
        {
            rx = playerPosX;
            ry = playerPosY;
            dof = 8;
        }

        int mx, my;
        while (dof < 8)
        {
            mx = ((int)rx >> 6);
            my = ((int)ry >> 6);
            if (my * mx > 0 && cub->map[my][mx] == '1')
            {
                dof = 8;
                hx = rx;
                hy = ry;
                disH = dist(playerPosX, playerPosY, hx, hy, ra);
            }
            else
            {
                rx += x0;
                ry += y0;
                dof += 1;
            }
        }

        // looking left - right
        dof = 0;
        float ntan = -tan(ra);
        if (ra > M_PI_2 && ra < (M_PI / 3))
        {
            rx = (((int) playerPosX >> 6) << 6) - 0.0001f;
            ry = (playerPosX - rx) * ntan + playerPosY;
            x0 = -64;
            y0 = -x0 * ntan;
        }
        if (ra < M_PI_2 || ra > (M_PI / 3))
        {
            rx = (((int) playerPosX >> 6) << 6) + 64;
            ry = (playerPosX - rx) * ntan + playerPosY;
            x0 = 64;
            y0 = -x0 * ntan;
        }
        if (ra == 0 || ra == M_PI) 
        {
            rx = playerPosX;
            ry = playerPosY;
            dof = 8;
        }

        while (dof < 8)
        {
            mx = ((int)rx >> 6);
            my = ((int)ry >> 6);
            if (my * mx > 0 && cub->map[my][mx] == '1')
            {
                dof = 8;
                vx = rx;
                vy = ry;
                disV = dist(playerPosX, playerPosY, vx, vy, ra);
            }
            else
            {
                rx += x0;
                ry += y0;
                dof += 1;
            }
        }
        if (disV < disH)
        {
            rx = vx;
            ry = vy;
            disT = disV;
        }
        if (disV > disH)
        {
            rx = hx;
            ry = hy;
            disT = disH;
        }
        ra += DR;
        float ca=cub->player_angle-ra; if (ca < 0) {ca+=2*M_PI;} if (ca > 2 * M_PI) {ca -= 2*M_PI;} disT = disT*cos(ca);
        int i = 0;
        int q = 0;
        wall_height = ((mapX * mapY) * (WIN_SIZE_H / 2)) / disT; if (wall_height > (WIN_SIZE_H / 2)) {wall_height = (WIN_SIZE_H / 2);}
        while (wall_height--)
        {
            printf("%d", wall_height + offset);
            for (q = 0; q < (WIN_SIZE_W / 60); q++)
                my_mlx_pixel_put(cub->data, r * (WIN_SIZE_W / 60) + q, wall_height + offset, 0x00ee5555);
            i++;
        }
        r++;
    }
    mlx_clear_window(cub->mlx, cub->win);
    mlx_put_image_to_window(cub->mlx, cub->win, cub->data->img, 0, 0);
    mlx_put_image_to_window(cub->mlx, cub->win, cub->playerImg, fixed2flo(cub->player_pos.x), fixed2flo(cub->player_pos.y));
    return (1);
}