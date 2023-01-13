/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   defines.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ailopez- <ailopez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/29 17:41:33 by aitoraudica       #+#    #+#             */
/*   Updated: 2023/01/13 23:29:49 by ailopez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFINES_H
# define DEFINES_H

# include "keycodes.h"
# include <stdlib.h>
# include <unistd.h>

# define WINX 600	
# define WINY 800

# define X 0
# define Y 1
# define Z 2

# define STACKA	0
# define STACKB	1

# define MIN_BLOCK_SIZE  25
# define MAX_BLOCK_SIZE  45

# define ROJO 		0xc1272d
# define VERDE		0x33cc55
# define FUCSIA 	0xff255c
# define AZUL		0x1B8EFA
# define CARBON		0x151515
# define WHITE		0xBBBBBB
# define DISCO		0x9A1F6A
# define BRICK_RED	0xC2294E
# define FLAMINGO	0xEC4B27
# define JAFFA		0xEF8633
# define SAFFRON	0xF3AF3D

//--/ Printf colors
# define DEF_COLOR	"\033[0;39m"
# define GRAY		"\033[0;90m"
# define RED		"\033[0;91m"
# define GREEN		"\033[0;92m"
# define YELLOW		"\033[0;93m"
# define BLUE		"\033[0;94m"
# define MAGENTA	"\033[0;95m"
# define CYAN 		"\033[0;96m"
# define KNRM		"\x1B[0m"
# define KRED		"\x1B[31m"
# define KGRN		"\x1B[32m"
# define KYEL		"\x1B[33m"
# define KBLU		"\x1B[34m"
# define KMAG		"\x1B[35m"
# define KCYN		"\x1B[36m"
# define KWHT		"\x1B[37m"

typedef struct s_stack
{
	int				num;
	int				index;
	struct s_stack	*next;
	struct s_stack	*pre;
}					t_stack;

typedef struct s_point {
	float	axis[2];
	int		color;
}	t_point;

typedef struct s_bar {
	t_point	start;
	t_point	end;
	float	width;
}	t_bar;

typedef struct s_bitmap {
	void	*img;
	char	*buffer;
	int		bitxpixel;
	int		lines;
	int		endian;
}	t_bitmap;

typedef struct s_vars {
	void	*mlx;
	void	*win;
}	t_vars;

typedef struct s_op	t_op;
struct s_op {
	char	*op;
	t_op 	*next;
};

typedef struct s_meta {
	t_vars		vars;
	t_bitmap	bitmap;
	t_stack		*stack_a;
	t_stack		*stack_b;
	t_op		*ops;
	int			gui;
	int			print_stack;
	int			print_ops;
	int			stack_size;
	int			max;
	int			min;
	int			abs;
	int			neg;
	int			numops;
	int			numops_load;
	char		run;	
}	t_meta;



#endif
