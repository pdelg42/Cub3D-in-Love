/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fixed.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgerace <sgerace@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 19:36:32 by gdel-giu          #+#    #+#             */
/*   Updated: 2023/05/30 16:46:35 by sgerace          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_H
# define FIXED_H

# include <math.h>
# include <stdlib.h>

typedef unsigned int	t_fixed8;

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