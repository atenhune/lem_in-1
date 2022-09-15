/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: altikka <altikka@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 10:28:17 by altikka           #+#    #+#             */
/*   Updated: 2022/06/15 19:51:16 by altikka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HANDLE_H

# define HANDLE_H

# include <stdbool.h>
# include "libft.h"

typedef enum e_len
{
	null,
	hh,
	h,
	ll,
	l,
	L
}			t_len;

typedef struct s_stat
{
	va_list			ap;
	long			val;
	int				sign;
	bool			is_signed;
	bool			hash;
	bool			dash;
	bool			plus;
	bool			space;
	bool			zero;
	unsigned int	width;
	unsigned int	preci;
	bool			preci_on;
	t_len			length;
	char			type;
	char			pad;
}			t_stat;

char	*handle_char(t_stat *info);
char	*handle_short(t_stat *info);
char	*handle_int(t_stat *info);
char	*handle_long(t_stat *info);

typedef char			*(*t_handler)(t_stat *);

static const t_handler	g_handler[6] = {
	handle_int,
	handle_char,
	handle_short,
	handle_long,
	handle_long,
	handle_long
};

char	*pad_nums_front(t_stat *info, size_t len);
t_vec	*pad_dbls_front(t_vec *src, t_vec *temp, size_t src_len, t_stat *info);

#endif
