/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_validator.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperrone <aperrone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 05:12:53 by aperrone          #+#    #+#             */
/*   Updated: 2023/05/14 05:27:56 by aperrone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incl/cub.h"

int	file_validator(char *map_path)
{
	char	*temp;

	temp = ft_strstr(map_path, ".cub");
	if (!temp || ft_strcmp(temp, ".cub"))
		return (-1);
	return (open(map_path, O_RDONLY));
}
