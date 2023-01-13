# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ailopez- <ailopez-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/29 17:49:21 by aitoraudica       #+#    #+#              #
#    Updated: 2023/01/13 23:19:58 by ailopez-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


#Variables

NAME		:= pro_checker

SRC_DIR		:= src/
OBJ_DIR		:= obj/
CC			:= gcc
CFLAGS		:= -g -Wall -Werror -Wextra
FSANITIZE	:= -fsanitize=address -g3
NOFLAGS		:= -g
RM			:= rm -f

INC		 		:= inc/
LIB				:= libs/
LIBFT_DIR		:= $(LIB)libft/
LIBFT			:= $(LIBFT_DIR)libft.a
HEADER 			:= -I$(INC) -I$(LIBFT_DIR) -I$(MINILIBX_DIR)
MINILIBX_DIR	:= $(LIB)miniliblx/minilibx_macos/
MINILIBX		:= $(MINILIBX_DIR)libmlx.a
MINILIBXCC		:= -I mlx -L $(MINILIBX_DIR) -lmlx
OPENGL			:= -framework OpenGL -framework AppKit


# Colors

DEF_COLOR = \033[0;39m
GRAY = \033[0;90m
RED = \033[0;91m
GREEN = \033[0;92m
YELLOW = \033[0;93m
BLUE = \033[0;94m
MAGENTA = \033[0;95m
CYAN = \033[0;96m
WHITE = \033[0;97m

#Sources

SRC_FILES	=	main 		\
				lists 		\
				lists_utils \
				parser 		\
				ops_rab 	\
				ops_rrab 	\
				ops_sab 	\
				ops_pab 	\
				exec_ops 	\
				gui			\
				gui_init	\
				gui_utils	\
				draw		\
				print		\
				utils		


SRC 		= 	$(addprefix $(SRC_DIR), $(addsuffix .c, $(SRC_FILES)))
OBJ 		= 	$(addprefix $(OBJ_DIR), $(addsuffix .o, $(SRC_FILES)))
DEPS 		= 	$(addprefix $(OBJ_DIR), $(addsuffix .d, $(SRC_FILES)))
INCS		= 	$(addprefix $(INCLUDE), $(addsuffix .h, $(INC_FILES)))
###

OBJF		=	.cache_exists

all:	makelibs
		@$(MAKE) $(NAME)
		@echo " "

makelibs:
	@echo " "
	@echo "$(MAGENTA)🔸 MAKE LIBS 🔸$(DEF_COLOR)"
	@echo " "
	@echo "$(GREEN)Libft lib...$(DEF_COLOR)"	
	@$(MAKE) -C $(LIBFT_DIR)
	@echo " "
	@echo "$(GREEN)Minilibx lib...$(DEF_COLOR)"	
	@$(MAKE) -C $(MINILIBX_DIR)
	@echo " "	
	
-include 	${DEPS}
$(NAME):	$(OBJ) Makefile
			@echo " "
			@echo "$(MAGENTA)🔸 MAKE PROGRAM 🔸$(DEF_COLOR)"
			@echo " "			
			@$(CC) $(CFLAGS) $(FSANITIZE) $(OBJ) $(LIBFT) $(MINILIBXCC) $(OPENGL) -o $(NAME)
			@echo " "
			@echo "👉 $(CYAN)$(CC) $(CFLAGS) $(FSANITIZE) $(OBJ) $(LIBFT) $(MINILIBXCC) $(OPENGL) -o $(NAME)$(DEF_COLOR)"
			@echo " "
			@echo "$(GREEN)✨ PRO CHECKER!$(DEF_COLOR)"
			@echo " "

			

bonus:		
			@$(MAKE) all
			
$(OBJ_DIR)%.o: $(SRC_DIR)%.c | $(OBJF)
			@echo "🍩 $(YELLOW)Compiling: $< $(DEF_COLOR)"
			$(CC) $(CFLAGS) $(FSANITIZE) -MMD -c $< -o $@

$(OBJF):
			@mkdir -p $(OBJ_DIR)

$(LIBFT):
	@make -C $(LIBFT_DIR) complete
	@echo "$(GREEN)Libft compiled!$(DEF_COLOR)"	

$(MINILIBX):
	@make -C $(MINILIBX_DIR)
	@echo "$(GREEN)Minilibx compiled!$(DEF_COLOR)"	
		
clean:
			@echo " "
			@echo "$(MAGENTA)🔸 CLEAN 🔸$(DEF_COLOR)"
			@echo " "			
			@make clean -sC $(LIBFT_DIR)
			@echo "$(CYAN)Libft object and dependency files cleaned.$(DEF_COLOR)"
			@make clean -C $(MINILIBX_DIR)
			@echo "$(CYAN)Minilibx object files cleaned.$(DEF_COLOR)"	
			$(RM) -rf $(OBJ_DIR)
			@echo "$(CYAN)checker object files cleaned!$(DEF_COLOR)"

fclean:		clean
			$(RM) -f $(NAME)
			@echo "$(CYAN)checker executable files cleaned!$(DEF_COLOR)"			
			$(RM) -f $(MINILIBX_DIR)libmlx.a
			@echo "$(CYAN)libmlx.a lib cleaned!$(DEF_COLOR)"			
			$(RM) -f $(LIBFT_DIR)libft.a
			@echo "$(CYAN)libft.a lib cleaned!$(DEF_COLOR)"


re:			fclean 
			@$(MAKE)	
			@echo "$(GREEN)Cleaned and rebuilt everything for checker!$(DEF_COLOR)"

norm:
			@norminette $(SRC) $(INCLUDE) | grep -v Norme -B1 || true

.PHONY:		all clean fclean re norm

