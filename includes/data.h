/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atenhune <atenhune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 12:36:34 by atenhune          #+#    #+#             */
/*   Updated: 2022/10/07 20:45:02 by altikka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA_H
# define DATA_H

/*
**STRUCTIONS FOR THE PROGRAM
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
	int		**links;
	int		room_count;
	bool	start_to_end;
	int		start;
	int		end;
}			t_lem;

#endif
