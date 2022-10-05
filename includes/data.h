/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atenhune <atenhune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 12:36:34 by atenhune          #+#    #+#             */
/*   Updated: 2022/10/05 19:04:01 by altikka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA_H
# define DATA_H

typedef struct s_lem
{
	int		ants;
	t_vec	rooms;
	int		**links;
	int		room_count; // <------ antti muuttaa!
	bool	start_to_end;
	int		start;
	int		end;
}			t_lem;

#endif
