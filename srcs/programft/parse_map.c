/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdel-giu <gdel-giu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 14:27:24 by gdel-giu          #+#    #+#             */
/*   Updated: 2023/05/10 08:53:01 by gdel-giu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/program.h"

#define MAX_MAP_PARAMS 6

//check sulls validitá del file

int validate_file(char *map_path)
{
	char *s;

	s = ft_strstr(map_path, ".cub");
	if (!s || ft_strcmp(s, ".cub\0"))
		return (-1);
	return (open(map_path, O_RDONLY));
}

// check sui token iniziali e smistamento dei valori

int	get_element_id(char *el)
{
	if (!ft_strcmp(el, "NO\0"))
		return (NORD);
	if (!ft_strcmp(el, "SO\0"))
		return (SOUTH);
	if (!ft_strcmp(el, "EA\0"))
		return (EAST);
	if (!ft_strcmp(el, "WE\0"))
		return (WEST);
	return (0);
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

// funzione per prendere solo la base della mappa

int	update_map(t_cub *cub)
{
	int i;
	int j;

	i = 0;
	while (!cub->map[i])
		i++;
	if (cub->mat_tmp && *cub->mat_tmp)
		freematrix(cub->mat_tmp, row_counter(cub->mat_tmp));
	cub->mat_tmp = (char **) ft_calloc(row_counter(cub->map + i) + 1
		, sizeof(char *));
	cub->mat_tmp[row_counter(cub->map + i)] = NULL;
	j = 0;
	while (cub->map[i])
	{
		cub->mat_tmp[j++] = ft_strtrim(ft_strdup(cub->map[i]), "\n");
		free(cub->map[i++]);
	}
	free(cub->map);
	cub->map = cub->mat_tmp;
	cub->mat_tmp = NULL;
	if (row_counter(cub->map) < 3)
		return (0);
	return (1);
}

// controlla se è un elemento che fa riferimento al colore

int	is_color_element(char *el)
{
	if (!el)
		return (0);
	while (ft_isspace(*el))
		el++;
	if (*el == 'C' || *el == 'F')
		return (1);
	return (0);
}

// ottiene le cmponenti della mappa

int	get_elements_from_matrix(t_cub *cub)
{
	char 	**getter;
	int		i;
	
	getter = cub->map;
	i = 0;
	while (i < MAX_MAP_PARAMS && *(getter + i) && !ft_isdigit(**(getter + i)))
	{
		cub->mat_tmp = ft_split(*(getter + i), ' ');
		if (get_element_id(cub->mat_tmp[0])
			&& !cub->wall_imgs_addrs[get_element_id(cub->mat_tmp[0]) - 1])
			cub->wall_imgs_addrs[get_element_id(cub->mat_tmp[0]) - 1]
				= ft_strdup(cub->mat_tmp[1]);
		else if (is_color_element(*(getter + i)))
			cub->str_tmp = safe_strjoin(cub->str_tmp, *(getter + i));
		else if (**(getter + i) == '\0' && i--)
			getter++;
		else
			return (update_map(cub) && 0);
		free(cub->map[(getter + i) - cub->map]);
		cub->map[(getter + i) - cub->map] = NULL;
		freematrix(cub->mat_tmp, row_counter(cub->mat_tmp));
		i++;
	}
	update_map(cub);
	return (!(i - MAX_MAP_PARAMS));
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