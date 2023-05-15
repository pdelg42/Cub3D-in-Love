/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fixed.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdel-giu <gdel-giu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 19:36:32 by gdel-giu          #+#    #+#             */
/*   Updated: 2023/05/12 20:14:44 by gdel-giu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_H
# define FIXED_H
# include "fixed_types.h"

float		fixed2flo(t_fixed8 fixed);
int			fixed2int(t_fixed8 fixed);
t_fixed8	int2fixed(int val);
t_fixed8	flo2fixed(float val);

t_fixed8	fixsum(t_fixed8 a, t_fixed8 b);
t_fixed8	fixsub(t_fixed8 a, t_fixed8 b);
t_fixed8	fixmul(t_fixed8 a, t_fixed8 b);
t_fixed8	fixdiv(t_fixed8 a, t_fixed8 b);
t_fixed8	fixabs(t_fixed8 val);

#endif
