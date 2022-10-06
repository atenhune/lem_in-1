/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_ants.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atenhune <atenhune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 11:06:32 by altikka           #+#    #+#             */
/*   Updated: 2022/10/06 12:00:11 by altikka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static int	no_overflow_atoi(const char *str)
{
	int					i;
	int					sign;
	unsigned long long	ret;

	i = 0;
	ret = 0;
	sign = 1;
	while (ft_isspace(str[i]) == 1)
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		ret = ret * 10 + str[i++] - 48;
		if (ret > 2147483647 && sign == 1)
			return (-1);
		if (ret > 2147483648 && sign == -1)
			return (-1);
	}
	return (ret * sign);
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
