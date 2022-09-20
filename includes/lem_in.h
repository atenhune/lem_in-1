/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: altikka <altikka@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 11:09:22 by altikka           #+#    #+#             */
/*   Updated: 2022/09/20 18:26:29 by altikka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H

# define LEM_IN_H

# include "libft.h"

/*
**STRUCTS FOR THE PROGRAM
*/

typedef struct s_room
{
	char	*name;
	int		x;
	int		y;
	t_vec	links;
	int		index;
}			t_room;

typedef struct s_lem
{
	int		ants;
	t_vec	rooms;
	int		start;
	int		end;
}			t_lem;

/*
**STRUCTS & FUNCTIONS FOR THE PARSER
*/

typedef enum e_state
{
	ANTS,
	ROOMS,
	LINKS,
	DONE
}			t_state;

typedef struct s_parser
{
	t_vec	inputs;
	char	*line;
	int		start;
	int		end;
	t_state	state;
}			t_parser;

int		number_of_ants(t_lem *d, t_parser *p);
int		the_rooms(t_lem *d, t_parser *p);
int		the_links(t_lem *d, t_parser *p);

typedef int				(*t_parsers)(t_lem *, t_parser *);

static const t_parsers	g_parsers[3] = {
	number_of_ants,
	the_rooms,
	the_links
};

/*
**FUNCTIONS FOR THE PROGRAM
*/

int		init_data(t_lem *d);
int		panic(t_lem *d, const char *msg);
void	free_data(t_lem *d);
int		parse_data(t_lem *d, t_vec *farm);

#endif
