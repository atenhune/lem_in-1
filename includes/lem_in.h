/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: altikka <altikka@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 11:09:22 by altikka           #+#    #+#             */
/*   Updated: 2022/09/16 11:03:51 by altikka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H

# define LEM_IN_H

# include "libft.h"

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

int		init_data(t_lem *d);
int		panic(t_lem *d, const char *msg);
void	free_data(t_lem *d);
int		parse_data(t_lem *d);

#endif
