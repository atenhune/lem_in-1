# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: altikka <altikka@student.hive.fi>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/08 13:27:42 by altikka           #+#    #+#              #
#    Updated: 2022/09/28 09:54:37 by altikka          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRCS = ft_putchar.c ft_putstr.c ft_putendl.c ft_putnbr.c ft_strlen.c \
	   ft_strcmp.c ft_strncmp.c ft_strcpy.c ft_strncpy.c ft_strdup.c \
	   ft_strcat.c ft_strncat.c ft_strlcat.c ft_atoi.c ft_strchr.c \
	   ft_strrchr.c ft_strstr.c ft_strnstr.c ft_memset.c ft_bzero.c \
	   ft_memcpy.c ft_memccpy.c ft_memmove.c ft_memchr.c ft_memcmp.c \
	   ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c \
	   ft_toupper.c ft_tolower.c ft_memalloc.c ft_memdel.c ft_strnew.c \
	   ft_strdel.c ft_strclr.c ft_striter.c ft_striteri.c ft_strmap.c \
	   ft_strmapi.c ft_strequ.c ft_strnequ.c ft_strsub.c ft_strjoin.c \
	   ft_strtrim.c ft_strsplit.c ft_itoa.c ft_putchar_fd.c ft_putstr_fd.c \
	   ft_putendl_fd.c ft_putnbr_fd.c ft_lstnew.c ft_lstdelone.c ft_lstdel.c \
	   ft_lstadd.c ft_lstiter.c ft_lstmap.c ft_strndup.c ft_strnchr.c \
	   ft_intlen.c ft_abs.c ft_strcasechr.c ft_strncasecmp.c ft_strcasestr.c \
	   ft_isspace.c ft_strrev.c get_next_line.c ft_sqrt.c ft_pow.c ft_powl.c \
	   ft_anylen.c ft_anytoa.c ft_isinf.c \
	   ft_vecnew.c ft_vecdel.c ft_veccpy.c ft_vecresize.c ft_vecpush.c \
	   ft_vecappend.c ft_vecncat.c ft_vecfrom.c ft_vecget.c ft_vecpop.c \
	   ft_vecinsert.c ft_vecremove.c \
	   ft_strdelarr.c ft_memdelarr.c ft_isnbr.c ft_cntchr.c

PRINTF_INCS = -I. -I./ft_printf/includes
PRINTF_DIR = ft_printf/src/

PRINTF_SRCS = $(PRINTF_DIR)ft_printf.c \
	   $(PRINTF_DIR)ft_vasprintf.c \
	   $(PRINTF_DIR)utilities.c \
	   $(PRINTF_DIR)press.c \
	   $(PRINTF_DIR)press_type.c \
	   $(PRINTF_DIR)inves_flags.c \
	   $(PRINTF_DIR)inves_width.c \
	   $(PRINTF_DIR)inves_preci.c \
	   $(PRINTF_DIR)inves_length.c \
	   $(PRINTF_DIR)tc_char.c \
	   $(PRINTF_DIR)tc_dbl.c \
	   $(PRINTF_DIR)round_dbl.c \
	   $(PRINTF_DIR)tc_len.c \
	   $(PRINTF_DIR)tc_num.c \
	   $(PRINTF_DIR)tc_ptr.c \
	   $(PRINTF_DIR)tc_str.c \
	   $(PRINTF_DIR)pad_nums_front.c \
	   $(PRINTF_DIR)pad_dbls_front.c \
	   $(PRINTF_DIR)pad_inf.c \
	   $(PRINTF_DIR)handlers.c

OBJS = $(SRCS:.c=.o)
PRINTF_OBJS = ft_printf.o ft_vasprintf.o utilities.o press.o press_type.o \
	   inves_flags.o inves_width.o inves_preci.o inves_length.o \
	   tc_char.o tc_dbl.o round_dbl.o tc_len.o tc_num.o tc_ptr.o tc_str.o \
	   pad_nums_front.o pad_dbls_front.o pad_inf.o handlers.o

FLGS = -Wall -Wextra -Werror -O3

EOC = \033[0m
LGRAY = \033[38;5;243m
GREEN = \033[38;5;70m
BLUE = \033[38;5;25m
RUST = \033[38;5;130m
YELLOW = \033[38;5;220m

all: $(NAME)

$(NAME):
	@echo "$(LGRAY)[libft] $(BLUE)Making object files...$(EOC)"
	@gcc -c $(FLGS) $(PRINTF_INCS) $(SRCS) $(PRINTF_SRCS)
	@echo "$(LGRAY)[libft] $(BLUE)Creating library...$(EOC)"
	@ar rcs $(NAME) $(OBJS) $(PRINTF_OBJS)
	@echo "$(LGRAY)[libft] $(BLUE)Library created!$(EOC)"

clean:
	@echo "$(LGRAY)[libft] $(RUST)Cleaning object files...$(EOC)"
	@rm -f $(OBJS) $(PRINTF_OBJS)

fclean: clean
	@echo "$(LGRAY)[libft] $(RUST)Removing library...$(EOC)"
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
