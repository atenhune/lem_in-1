/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: altikka <altikka@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 08:24:33 by altikka           #+#    #+#             */
/*   Updated: 2022/10/07 16:14:15 by altikka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FLAGS_H

# define FLAGS_H

# define BOLD_ON "\e[1m"
# define BOLD_OFF "\e[m"

# define LEM_USAGE "\nusage: ./lem-in [-hpqt] < [file]\n\
 options:\n\
 	"BOLD_ON"-h"BOLD_OFF"\thelp\n\
	"BOLD_ON"-p"BOLD_OFF"\tadditional path information\n\
	"BOLD_ON"-q"BOLD_OFF"\tquiet mode\n\
	"BOLD_ON"-t"BOLD_OFF"\ttest mode\n\n"

# define LEM_FLAGS "pqt"

typedef enum e_flag
{
		NONE,
		PATHS,
		QUIET,
		TEST
}		t_flag;

int		init_flags(t_flag *flag, int argc, char **argv);

#endif
