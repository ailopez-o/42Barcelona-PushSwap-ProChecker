# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ailopez- <ailopez-@student.42barcelon      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/09 16:48:38 by ailopez-          #+#    #+#              #
#    Updated: 2022/05/18 16:15:48 by ailopez-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
NAME	= libft.a

SRCS		=	ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c \
				ft_strchr.c ft_strrchr.c ft_tolower.c ft_toupper.c ft_strlen.c \
				ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c ft_strdup.c \
				ft_strlcpy.c ft_strlcat.c ft_strncmp.c ft_calloc.c ft_memchr.c \
				ft_memcmp.c ft_strnstr.c ft_atoi.c ft_substr.c ft_strjoin.c \
				ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c ft_striteri.c \
				ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c \
				ft_atoi_ex.c get_next_line.c


SRCS_BONUS	=	ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c \
				ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c \
				ft_lstmap.c

OBJS		=	$(SRCS:%.c=%.o)
OBJS_BONUS	=	$(SRCS_BONUS:%.c=%.o)

CC		=	gcc

CFLAGS	=	-Wall -Wextra -Werror

RM		=	rm -f

# Colors

BOLD_PURPLE	=	\033[1;35m
BOLD_CYAN	=	\033[1;36m
BOLD_YELLOW	=	\033[1;33m
NO_COLOR	=	\033[0m
DEF_COLOR 	= \033[0;39m
DEF_COLOR = \033[0;39m
GRAY = \033[0;90m
RED = \033[0;91m
GREEN = \033[0;92m
YELLOW = \033[0;93m
BLUE = \033[0;94m
MAGENTA = \033[0;95m
CYAN = \033[0;96m
WHITE = \033[0;97m


%.o: %.c
		@${CC} ${CFLAGS} -I./ -c $< -o $@
		@printf "\r                                                                           "
		@printf "\r🔧 $(GRAY)${CC} ${CFLAGS} -I./ -c $< -o $@$(DEF_COLOR)"

all: 
	@echo "🎯 $(YELLOW)Starting $(WHITE)[${NAME}] $(YELLOW)compilation..$(DEF_COLOR)"
	@Make ${NAME}
	@echo "\n🔰 $(GREEN)${NAME} done!\n$(DEF_COLOR)"

${NAME}:${OBJS} ${OBJS_BONUS} libft.h Makefile
		@ar -crs ${NAME} ${OBJS} ${OBJS_BONUS}
		@echo "\n🔗 $(CYAN) ar -crs ${NAME} ${OBJS} ${OBJS_BONUS}$(DEF_COLOR)"
		
bonus:${NAME} ${OBJS_BONUS} Makefile
		@ar -crs ${NAME} ${OBJS_BONUS}
		@touch $@

#Regla para borrar todos los objetos y directorios
clean:
		@${RM} ${OBJS}
		@${RM} ${OBJS_BONUS}
		@${RM} bonus		
		@echo "$(MAGENTA)🚽 Cleaned ${NAME}$(DEF_COLOR)"	

#Regla para borrar todo lo que ha sido creado or el makefile
fclean:	clean
		@${RM} ${NAME} 
		@echo "$(MAGENTA)🚽 Fcleaned ${NAME}!$(DEF_COLOR)"	

#Regla  para rehacer todo
re:		fclean all

.PHONY: fclean, all, clean, re

