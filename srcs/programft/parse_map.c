/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdel-giu <gdel-giu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 14:27:24 by gdel-giu          #+#    #+#             */
/*   Updated: 2023/03/28 22:42:56 by gdel-giu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/program.h"

#define MAX_MAP_PARAMS 6

//check sulls validitá del file

int validate_file(char *map_path)
{
	char *s;

	s = ft_strstr(map_path, ".cub");
	if (!s || ft_strcmp(s, ".cub"))
		return (-1);
	return (open(map_path, O_RDONLY));
}

// check sui token iniziali e smistamento dei valori

int	get_element_id(char c)
{
	if (c == 'N')
		return (NORD);
	if (c == 'S')
		return (SOUTH);
	if (c == 'E')
		return (EAST);
	if (c == 'W')
		return (WEST);
	return (-1);
}

// se s1 non risulta allocato allora copia

char 	*safe_strjoin(char *s1, char *s2)
{
	char	*str;
	
	if (!s1)
		return (ft_strjoin(ft_strdup(s2), ":"));
	str = ft_strjoin(s1, s2);
	return (str);
}

// ottiene le cmponenti della mappa

int	get_elements_from_matrix(t_cub *cub)
{
	char 	**getter;
	int		i;
	
	getter = cub->map;
	i = 0;
	while (i < MAX_MAP_PARAMS && *(getter + i))
	{
		if (ft_isdigit(**(getter + i)))
			return (0);
		*(getter + i) = ft_strtrim(*(getter + i), " \t");
		if (**(getter + i) == 'N' || **(getter + i) == 'S'
			|| **(getter + i) == 'E' || **(getter + i) == 'W')
			cub->wall_imgs_addrs[get_element_id(**(getter + i))]
				= ft_strdup(*(getter + i));
		else if (**(getter + i) == 'F' || **(getter + i) == 'C')
			cub->str_tmp = safe_strjoin(cub->str_tmp, *(getter + i));
		else if (**(getter + i) == '\0' && i--)
			getter++;
		else
			return (0);
		i++;
	}
	cub->wall_imgs_addrs[4] = NULL;
	return (1);
}

// funzione base per ottenere le componenti dalla mappa

int	parse_map(t_cub *cub, char *map_path)
{
	int		fd;
	char	*tmp;
	
	fd = validate_file(map_path);
	if (fd < 0)
		return (0);
	tmp = get_next_line(fd);
	cub->str_tmp = (char *) ft_calloc(1, 1);
	while (tmp)
	{
		cub->str_tmp = ft_strjoin(cub->str_tmp, tmp);
		free(tmp);
		tmp = get_next_line(fd);
	}
	close(fd);
	cub->map = ft_split(cub->str_tmp, '\n');
	free(cub->str_tmp);
	cub->str_tmp = NULL;
	if (!cub->map || !get_elements_from_matrix(cub))
		return (0);
	if (!import_elements(cub))
		return (0);
	return (1);
}