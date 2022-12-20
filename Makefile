.PHONY:	all clean fclean re fclean_lib fclean_all

# ******** VARIABLES ******** #

# ---- Final Executable --- #

NAME		=	minitalk

NAME_SERVER	=	server

NAME_CLIENT	=	client

LIBFT		=	libft.a

# ---- Directories ---- #

DIR_OBJS	=	.build/

DIR_SRCS	=	srcs/

DIR_LIBFT	=	libft/

DIR_HEAD	=	head/

# ---- Files ---- #

HEAD		=	minitalk.h

COMMON_SRCS	=	ft_msg_error.c	ft_utils.c

SRCS_SERVER	=	server.c

SRCS_CLIENT	=	client.c

COMMON_OBJS	=	${COMMON_SRCS:%.c=${DIR_OBJS}%.o}

OBJS_SERVER	=	${COMMON_OBJS} ${SRCS_SERVER:%.c=${DIR_OBJS}%.o}

OBJS_CLIENT	=	${COMMON_OBJS} ${SRCS_CLIENT:%.c=${DIR_OBJS}%.o}

# ---- Compilation ---- #

CC		=	cc
CFLAGS	=	-Wall -Wextra -Werror

# ---- Commands ---- #

RM		=	rm -rf
MKDIR	=	mkdir -p

# ********* RULES ******** #

all				:	${NAME_CLIENT} ${NAME_SERVER}

# ---- Variables Rules ---- #

${NAME}			:	all

${NAME_SERVER}	:	${OBJS_SERVER} Makefile ${addprefix ${DIR_LIBFT}, ${LIBFT}}
					${CC} ${CFLAGS} -o ${NAME_SERVER} ${OBJS_SERVER} -L${DIR_LIBFT} -lft

${NAME_CLIENT}	:	${OBJS_CLIENT} Makefile ${addprefix ${DIR_LIBFT}, ${LIBFT}}
					${CC} ${CFLAGS} -o ${NAME_CLIENT} ${OBJS_CLIENT} -L${DIR_LIBFT} -lft

${addprefix ${DIR_LIBFT}, ${LIBFT}}	:
					make ${LIBFT} -C ${DIR_LIBFT}

# ---- Compiled Rules ---- #

${DIR_OBJS}%.o	:	${DIR_SRCS}%.c Makefile | ${DIR_OBJS}
					${CC} ${CFLAGS} -MMD -I ${DIR_HEAD} -I ${DIR_LIBFT} -c $< -o $@

${DIR_OBJS}		:
					${MKDIR} ${DIR_OBJS}

-include ${DIR_OBJS}/*.d

# ---- Usual Commands ---- #
					
fclean_lib		:	
					make fclean -C ${DIR_LIBFT}

clean			:
					${RM} ${DIR_OBJS}

fclean			:	clean
					${RM} ${NAME_SERVER} ${NAME_CLIENT}

fclean_all		:	fclean fclean_lib

re				:	fclean
					${MAKE} all
