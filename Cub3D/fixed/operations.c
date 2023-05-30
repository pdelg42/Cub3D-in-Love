/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdel-giu <gdel-giu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 19:36:29 by gdel-giu          #+#    #+#             */
/*   Updated: 2023/05/12 19:36:57 by gdel-giu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fixed.h"

t_fixed8    fixsum(t_fixed8 a, t_fixed8 b)
{
    return (a + b);
}

t_fixed8    fixsub(t_fixed8 a, t_fixed8 b)
{
    return (a - b);
}

t_fixed8    fixmul(t_fixed8 a, t_fixed8 b)
{
    return (a * b >> 8);
}

t_fixed8    fixdiv(t_fixed8 a, t_fixed8 b)
{
    return (((a << 8) / b));
}