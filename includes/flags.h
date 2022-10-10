/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*    By: altikka & atenhune <@student.hive.fi>      +#+  +:+       +#+       */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 08:24:33 by altikka           #+#    #+#             */
/*   Updated: 2022/10/10 11:15:03 by altikka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FLAGS_H
# define FLAGS_H

# define LEM_USAGE "\nusage: ./lem-in [-hpqt] < [file]\n\
 options:\n\
 \t\e[1m-h\e[m\thelp\n\
 \t\e[1m-p\e[m\tadditional path information\n\
 \t\e[1m-q\e[m\tquiet mode\n\
 \t\e[1m-t\e[m\ttest mode\n\n"

# define LEM_FLAGS "pqt"

typedef enum e_flag
{
	NONE,
	PATHS,
	QUIET,
	TEST
}	t_flag;

int	init_flags(t_flag *flag, int argc, char **argv);

#endif
