/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_options.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atenhune <atenhune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 14:17:12 by altikka           #+#    #+#             */
/*   Updated: 2022/10/06 18:34:59 by atenhune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int	print_send_all(t_lem *d)
{
	t_room	*temp;
	int		ant_nbr;

	ant_nbr = 1;
	temp = ft_vecget(&d->rooms, d->end);
	while (ant_nbr <= d->ants)
	{
		ft_printf("L%d-%s", ant_nbr, temp->name);
		ant_nbr++;
		if (ant_nbr <= d->ants)
			ft_printf(" ");
	}
	ft_printf("\n");
	return (1);
}
