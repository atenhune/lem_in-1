/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atenhune <atenhune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 11:09:22 by altikka           #+#    #+#             */
/*   Updated: 2022/10/06 19:54:01 by altikka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H

# define LEM_IN_H

# include "libft.h"
# include "hashmap.h"
# include "data.h"
# include "parse.h"
# include "pathset.h"
# include "bfs.h"
# include "print.h"

//////////////////////
# include <stdio.h> // remove me!
//////////////////////

/*
**STRUCTION FOR THE PROGRAM
*/

typedef struct s_room
{
	char	*name;
	int		x;
	int		y;
	t_vec	links;
	int		index;
}			t_room;

/*
**FUNCTIONS FOR THE PROGRAM
*/

int		init_data(t_lem *d, t_vec *farm);
int		panic(t_lem *d, const char *msg);
int		parse_data(t_lem *d, t_vec *farm);
void	free_data(t_lem *d);
int		solve(t_lem *d, t_bfs *bf);
int		print(t_lem *d, t_bfs *bf, t_vec *farm);

#endif
