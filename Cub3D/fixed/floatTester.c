/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floatTester.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgerace <sgerace@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 16:46:43 by sgerace           #+#    #+#             */
/*   Updated: 2023/05/30 16:50:30 by sgerace          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fixed.h"
#include <stdio.h>

int	main(void)
{
	t_fixed8	f1;
	t_fixed8	f2;

	f1 = flo2fixed(2.5);
	f2 = flo2fixed(14.5);
	printf("%f\n", fixed2flo(fixdiv(f2, f1)));
	return (0);
}
