#include <stdio.h>
#include <fcntl.h>
#include "get_next_line.h"
#include <string.h>

typedef struct s_orientation
{
	int nord;
	int sud;
	int east;
	int west;
} t_orientation;

void init_orientation(t_orientation* orient)
{
	orient->nord = 0;
	orient->sud = 0;
	orient->east = 0;
	orient->west = 0;
}

int ft_isspace(char c)
{
	if (c != ' ')
		return (0);
	return (1);
}

char* ft_strtrim(char *str)
{
	char*	tmp;
    size_t len = strlen(str);
    size_t start = 0;
    size_t end = len - 2;

    // Trova l'indice del primo carattere non spazio
    while (ft_isspace((unsigned char)str[start]))
    {
        start++;
    }

    // Trova l'indice dell'ultimo carattere non spazio
    while (end > start && ft_isspace((unsigned char)str[end]))
    {
        end--;
    }

	tmp = (char*) malloc (sizeof(char) * (end - start + 1));
    // Sposta i caratteri validi all'inizio della stringa
    size_t i;
    for (i = 0; start <= end; i++, start++)
    {
        tmp[i] = str[start];
    }

    // Aggiunge il terminatore di stringa
    tmp[i] = '\0';
	return (tmp);
}

int anal_special(char* line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] != '1' && line[i] != ' ')
		{
			if (line[i] == '\n' || line[i] == '\0')
			{
				if (i != strlen(line) - 1)
				{
					printf("Backslash only at the end of the line\n");
					return (1);
				}
			}
			else
			{
				printf("Only ones and spaces are accepted in first and last row\n");
				return (1);
			}
		}
		i++;
	}
	return (0);
}

int	check_walls(char* line, int index, int rows)
{
	int		i;
	char*	tmp;

	tmp = ft_strtrim(line);
	//gestisce prima e ultima riga
	if (index == 0 || index == rows - 1)
	{
		if (anal_special(tmp))
			return (1);
	}
	//controlla ultimo carattere della linea
	if (tmp[strlen(tmp) - 1] != '1')
	{
		printf("Gli ultimi devono essere come i primi o na cosa del genere non sono cristiano dio porco\n");
		return (1);
	}
	//controlla primo carattere della linea
	if (tmp[0] != '1')
	{
		printf("Bro ma veramente nemmeno il primo char è un muro dai impegnati su\n");
		return (1);
	}
	//analizza se ci sono dei muri non chiusi nelle righe intermedie della mappa
 	i = 0;
	while (tmp[i])
	{
		if (tmp[i] == ' ')
		{
			if (tmp[i + 1] && ((tmp[i - 1] != ' ' && tmp[i - 1] != '1')  || (tmp[i + 1] != '1' && tmp[i + 1] != ' ' && tmp[i + 1] != '\n')))
			{
				printf("La mappa deve essere circondata da muri\n");
				return (1);
			}
		}
		i++;
	}
	return (0);
}

int	anal_line(char* line, t_orientation* orient, int rows, int index)
{
	int i;

	if (check_walls(line, index, rows))
		return (1);
	i = 0;
	while (line[i])
	{
		if (line[i] != 'N' && line[i] != 'S' && line[i] != 'W' && line[i] != 'E' && line[i] != '0' && line[i] != '1' && line[i] != '\0' && line[i] != ' ')
		{
			if (line[i] == '\n')
			{
				if (i != strlen(line) - 1)
				{
					printf("Backslash only at the end of the line\n");
					return (1);
				}
			}
			else
			{
				printf("Bella mappa ma brutto carattere\n");
				return (1);
			}
		}
		else if (line[i] == 'N')
			orient->nord++;
		else if (line[i] == 'S')
			orient->sud++;
		else if (line[i] == 'W')
			orient->west++;
		else if (line[i] == 'E')
			orient->east++;
		i++;
	}
}

int main (int argc, char** argv)
{
	int		fd;
	char*	line;
	char**	map;
	int		i;

	i = 0;
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		printf("Cannot open file\n");
	}
	while ((line = get_next_line(fd, 1)) != NULL)
	{
		i++;
	}
	if (i == 0)
	{
		printf("Mappa vuota\n");
		close(fd);
		return (1);
	}
	map = (char**) malloc(sizeof(char*) * (i + 1));
	map[i] = NULL;
	close(fd);

 	i = 0;
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		printf("Cannot open file\n");
	}
	while ((line = get_next_line(fd, 1)) != NULL)
	{
		if (!strcmp(line, "\n"))
		{
			printf("Ma che c'hai messo solo backslash??\n");
			close(fd);
			return (1);
		}
		map[i] = (char *) malloc (sizeof(char) * (strlen(line) + 1));
		strcpy(map[i], line);
		i++;
	}
	close(fd);

	int j = 0;
	t_orientation *orient;
	orient = (t_orientation*) malloc(sizeof(t_orientation));
	init_orientation(orient);
	while (j < i)
	{
		if (anal_line(map[j], orient, i, j))
		{
			return (1);
		}
		j++;
	}
	if ((orient->nord + orient->sud + orient->west + orient->east) != 1)
	{
			printf("Character must be one\n");
			return (1);
	}
	return (0);
}