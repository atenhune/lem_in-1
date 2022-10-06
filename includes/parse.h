/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: altikka <altikka@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 19:47:46 by altikka           #+#    #+#             */
/*   Updated: 2022/10/06 19:53:41 by altikka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_H

# define PARSE_H

/*
**STRUCTIONS & FUNCTIONS FOR THE PARSER
*/

typedef enum e_state
{
	ANTS,
	ROOMS,
	LINKS
}			t_state;

typedef struct s_parser
{
	t_vec	inputs;
	char	*line;
	int		start;
	int		end;
	t_hash	table[TABLE_SIZE];
	t_state	state;
}			t_parser;

int		parse_ants(t_lem *d, t_parser *p);
int		parse_rooms(t_lem *d, t_parser *p);
int		parse_links(t_lem *d, t_parser *p);

typedef int				(*t_parsers)(t_lem *, t_parser *);
//						is this legal global?
static const t_parsers	g_parsers[3] = {
	parse_ants,
	parse_rooms,
	parse_links
};

int		init_parser(t_parser *p);
int		return_next_line(const int fd, char **line, int *ret);
int		panic_parser(t_parser *p, const char *msg);
void	free_parser(t_parser *p);
void	free_intarr(void **apa, size_t n);
int		prepare_data(t_lem *d);

#endif
