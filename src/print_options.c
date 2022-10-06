/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_options.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: altikka <altikka@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 14:17:12 by altikka           #+#    #+#             */
/*   Updated: 2022/10/06 14:20:18 by altikka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int	print_send_all(t_lem *d)
{
	t_vec	print;

	if (ft_vecnew(&print, 5, sizeof(char)) < 0)
		return (panic(NULL, "Error: Couldn't initialize print for all ants."));
	(void)d; //here
	return (1);
}
