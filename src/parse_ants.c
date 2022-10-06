/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_ants.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atenhune <atenhune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 11:06:32 by altikka           #+#    #+#             */
/*   Updated: 2022/10/06 11:53:26 by atenhune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static int	no_overflow_atoi(const char *str)
{
	int					i;
	int					etu;
	unsigned long long	ret;

	i = 0;
	ret = 0;
	etu = 1;
	while (str[i] == '\n' || str[i] == '\r' || str[i] == '\v'
		|| str[i] == '\f' || str[i] == '\t' || str[i] == ' ')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			etu = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		ret = ret * 10 + str[i++] - 48;
		if (ret > 2147483647 && etu == 1)
			return (-1);
		if (ret > 2147483648 && etu == -1)
			return (-1);
	}
	return (ret * etu);
}

int	parse_ants(t_lem *d, t_parser *p)
{
	if (!ft_isnbr(p->line))
		return (panic(NULL, "Error: Has nothing to do with ants."));
	d->ants = no_overflow_atoi(p->line);
	if (d->ants < 0)
		return (panic(NULL, "Error: Negative amount of ants."));
	if (d->ants == 0)
		return (panic(NULL, "Error: No ants."));
	p->state = ROOMS;
	return (1);
}
