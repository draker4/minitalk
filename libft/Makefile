.PHONY:	all clean fclean re

# ******** VARIABLES ******** #

# ---- Final Executable --- #

NAME		=	libft.a

# ---- Directories ---- #

DIR_OBJS	=	.objs/

DIR_SRCS	=	srcs/

# ---- Files ---- #

HEAD		=	libft.h

SRCS		=	ft_isascii.c	\
				ft_strlen.c		\
				ft_strlcat.c	\
				ft_tolower.c	\
				ft_strchr.c		\
				ft_mem.c		\
				ft_atoi.c		\
				ft_strdup.c		\
				ft_strtrim.c	\
				ft_split.c		\
				ft_itoa.c		\
				ft_strmapi.c	\
				ft_putchar_fd.c	\
				ft_putnbr_fd.c	\
				ft_calloc.c		\
				ft_lst_elems.c	\
				ft_lstclear.c	\
				ft_lstmap.c		\
				ft_printf.c		\
				ft_itoa.c		\
				ft_strdup.c		\
				ft_strlen.c		\
				ft_conv.c		\
				ft_char.c		\
				ft_pointer.c	\
				get_next_line.c	\
				get_next_line_utils.c

OBJS		=	${SRCS:%.c=${DIR_OBJS}%.o}

# ---- Compilation ---- #

CC		=	cc
CFLAGS	=	-Wall -Wextra -Werror

# ---- Commands ---- #

RM		=	rm -rf
MKDIR	=	mkdir -p
AR		=	ar rc

# ********* RULES ******** #

all			:	${NAME}

# ---- Variables Rules ---- #

${NAME}			:	${OBJS} Makefile ${HEAD}
					${AR} ${NAME} ${OBJS}
					ranlib ${NAME}

# ---- Compiled Rules ---- #

${OBJS}			:	| ${DIR_OBJS}

${DIR_OBJS}%.o	:	${DIR_SRCS}%.c ${HEAD} Makefile
					${CC} ${CFLAGS} -I . -c $< -o $@

${DIR_OBJS}		:
					${MKDIR} ${DIR_OBJS}

# ---- Usual Commands ---- #

clean			:
					${RM} ${DIR_OBJS}

fclean			:	clean
					${RM} ${NAME}

re				:	fclean all
