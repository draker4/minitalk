.PHONY:	all clean fclean re fclean_lib fclean_all

# ******** VARIABLES ******** #

# ---- Final Executable --- #

NAME_SERVER		=	server

NAME_CLIENT		=	client

LIBFT			=	libft.a

# ---- Directories ---- #

DIR_OBJS		=	.objs/

DIR_SRCS_SERVER	=	srcs_server/

DIR_SRCS_CLIENT	=	srcs_client/

DIR_LIBFT		=	libft/

DIR_HEAD		=	head/

# ---- Files ---- #

HEAD		=	minitalk.h

SRCS		=	main.c

OBJS		=	${SRCS:%.c=${DIR_OBJS}%.o}

# ---- Compilation ---- #

CC		=	cc
CFLAGS	=	-Wall -Wextra -Werror

# ---- Commands ---- #

RM		=	rm -rf
MKDIR	=	mkdir -p
AR		=	ar rc

# ********* RULES ******** #

all				:	${NAME_SERVER}

# ---- Variables Rules ---- #

${NAME_SERVER}			:	${OBJS} Makefile ${LIBMLX} ${addprefix ${DIR_LIBFT}, ${LIBFT}} ${addprefix ${DIR_HEAD}, ${HEAD}}
					${CC} ${CFLAGS} -o ${NAME} ${OBJS} -L${DIR_LIBFT} -lft

${addprefix ${DIR_LIBFT}, ${LIBFT}}	:
					make ${LIBFT} -C ${DIR_LIBFT}

# ---- Compiled Rules ---- #

${OBJS}			:	| ${DIR_OBJS}

${DIR_OBJS}%.o	:	${DIR_SRCS}%.c Makefile ${addprefix ${DIR_HEAD}, ${HEAD}}
					${CC} ${CFLAGS} -I ${DIR_HEAD} -c $< -o $@

${DIR_OBJS}		:
					${MKDIR} ${DIR_OBJS}

# ---- Usual Commands ---- #
					
fclean_lib		:	
					make fclean -C ${DIR_LIBFT}

clean			:
					${RM} ${DIR_OBJS}

fclean			:	clean
					${RM} ${NAME_CLIENT} ${NAME_SERVER}

fclean_all		:	fclean fclean_lib

re				:	fclean all
