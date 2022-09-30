/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atenhune <atenhune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 12:36:34 by atenhune          #+#    #+#             */
/*   Updated: 2022/09/30 12:37:25 by atenhune         ###   ########.fr       */
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
	int		start;
	int		end;
}			t_lem;

#endif