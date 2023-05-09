/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   import_elements.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdel-giu <gdel-giu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 00:47:10 by gdel-giu          #+#    #+#             */
/*   Updated: 2023/03/28 22:28:54 by gdel-giu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/program.h"

// define di colori per effettuare un fallback nel caso non si riesca ad
// aprire un immagine (da decidere se solo per debug o per feature)
// ci sará comunque il messaggio da prompt per la mancata apertura dell'immagine

#define FLBK_NO 0x00aa1111
#define FLBK_SO 0x00aa5555
#define FLBK_WE 0x00dd2222
#define FLBK_EA 0x00dd8888

// funzione da utilizzare per smistare i componenti ottenuti dal parsing
// in variabili e struct necessarie all'esecuzione

int	import_elements(t_cub *cub)
{
	printf("%s\n", cub->str_tmp);
	free(cub->str_tmp);
	cub->str_tmp = NULL;
	return (1);
}