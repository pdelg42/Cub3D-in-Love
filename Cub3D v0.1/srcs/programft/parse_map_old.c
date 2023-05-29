/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map_old.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperrone <aperrone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 14:27:24 by gdel-giu          #+#    #+#             */
/*   Updated: 2023/05/16 14:36:16 by aperrone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "../../includes/program.h"

// #define MAX_MAP_PARAMS 6

// //check sulls validitá del file

// int validate_file(char *map_path)
// {
// 	char *s;

// 	s = ft_strstr(map_path, ".cub");
// 	if (!s || ft_strcmp(s, ".cub\0"))
// 		return (-1);
// 	return (open(map_path, O_RDONLY));
// }


// // se s1 non risulta allocato allora copia

// char 	*safe_strjoin(char *s1, char *s2)
// {
// 	char	*str;
	
// 	if (!s1)
// 		return (ft_strjoin(ft_strdup(s2), ":"));
// 	str = ft_strjoin(s1, s2);
// 	return (str);
// }

// // funzione per prendere solo la base della mappa

// int	update_map(t_cub *cub, int map_begin)
// {
// 	int j;

// 	if (!cub->map[map_begin])
// 		return (0);
// 	if (cub->mat_tmp && *cub->mat_tmp)
// 		freematrix(cub->mat_tmp, row_counter(cub->mat_tmp));
// 	cub->mat_tmp = (char **) ft_calloc(row_counter(cub->map + map_begin) + 1
// 		, sizeof(char *));
// 	cub->mat_tmp[row_counter(cub->map + map_begin)] = NULL;
// 	j = 0;
// 	while (cub->map[map_begin])
// 	{
// 		cub->mat_tmp[j++] = ft_strtrim(ft_strdup(cub->map[map_begin]), "\n");
// 		free(cub->map[map_begin++]);
// 	}
// 	free(cub->map);
// 	cub->map = cub->mat_tmp;
// 	cub->mat_tmp = NULL;
// 	if (row_counter(cub->map) < 3)
// 		return (0);
// 	return (1);
// }

// // controlla se è un elemento che fa riferimento al colore

// int	is_color_element(char *el)
// {
// 	if (!el)
// 		return (0);
// 	while (ft_isspace(*el))
// 		el++;
// 	if (*el == 'C' || *el == 'F')
// 		return (1);
// 	return (0);
// }

// //ritorna l indice del primo valore dopo spazi e tab
// int	ft_skip_space_tab(char **mat_tmp, int flag)
// {
// 	int i;

// 	i = 0;
// 	while (mat_tmp[i])
// 	{
// 		if (ft_strcmp(mat_tmp[i], "\0"))
// 		{
// 			if (flag == 0)
// 				break;
// 			else
// 				flag -= 1;
// 		}
// 		i++;
// 	}
// 	return (i);
// }
// // check sui token iniziali e smistamento dei valori

// int	get_element_id(char **el)
// {
// 	char *str_el;

// 	if (!el || !*el)
// 		return (0);
// 	str_el = el[ft_skip_space_tab(el, 0)];
// 	if (!ft_strcmp(str_el, "NO\0"))
// 		return (NORD);
// 	if (!ft_strcmp(str_el, "SO\0"))
// 		return (SOUTH);
// 	if (!ft_strcmp(str_el, "EA\0"))
// 		return (EAST);
// 	if (!ft_strcmp(str_el, "WE\0"))
// 		return (WEST);
// 	return (0);
// }

// char **get_row_as_mat(char *str)
// {
// 	char **new_mat;
// 	int j;

// 	new_mat = ft_split(str, ' ');
// 	if (!new_mat)
// 		return (NULL);
// 	j = 0;
// 	while (new_mat && new_mat[j])
// 	{
// 		new_mat[j] = ft_strtrim(new_mat[j], " \t");
// 		j++;
// 	}
// 	if (row_counter(new_mat) > 2)
// 	{
// 		freematrix(new_mat, row_counter(new_mat));
// 		return (NULL);
// 	}
// 	return (new_mat);
// }

// // ottiene le cmponenti della mappa

// int	get_elements_from_matrix(t_cub *cub)
// {
// 	char 	**getter;
// 	int		i;
	
// 	getter = cub->map;
// 	i = 0;
// 	while (i < MAX_MAP_PARAMS && *(getter + i) && !ft_isdigit(**(getter + i)))
// 	{
// 		cub->mat_tmp = get_row_as_mat(*(getter + i));
// 		int el_id = get_element_id(cub->mat_tmp);
// 		if (el_id && !cub->wall_imgs_addrs[el_id - 1])
// 			cub->wall_imgs_addrs[el_id - 1] 
// 				= ft_strdup(cub->mat_tmp[ft_skip_space_tab(cub->mat_tmp, 1)]);
// 		else if (is_color_element(*(getter + i)))
// 			cub->str_tmp = safe_strjoin(cub->str_tmp, *(getter + i));
// 		else if (**(getter + i) == '\0' && i--)
// 			getter++;
// 		else
// 			return (update_map(cub, ((getter + i) - cub->map)) && 0);
// 		free(cub->map[(getter + i) - cub->map]);
// 		cub->map[(getter + i) - cub->map] = NULL;
// 		freematrix(cub->mat_tmp, row_counter(cub->mat_tmp));
// 		i++;
// 	}
// 	update_map(cub, ((getter + i) - cub->map));
// 	return (!(i - MAX_MAP_PARAMS));
// }

// // funzione base per ottenere le componenti dalla mappa

// int	parse_map(t_cub *cub, char *map_path)
// {
// 	int		fd;
// 	char	*tmp;
	
// 	fd = validate_file(map_path);
// 	if (fd < 0)
// 		return (0);
// 	tmp = get_next_line(fd);
// 	cub->str_tmp = (char *) ft_calloc(1, 1);
// 	while (tmp)
// 	{
// 		cub->str_tmp = ft_strjoin(cub->str_tmp, tmp);
// 		free(tmp);
// 		tmp = get_next_line(fd);
// 	}
// 	close(fd);
// 	cub->map = ft_split(cub->str_tmp, '\n');
// 	free(cub->str_tmp);
// 	cub->str_tmp = NULL;
// 	if (!cub->map || !get_elements_from_matrix(cub))
// 		return (0);
// 	if (!import_elements(cub))
// 		return (0);
// 	while(*cub->map)
// 		printf("%s\n", *cub->map++);
// 	return (1);
// }