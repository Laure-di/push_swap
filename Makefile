NAME	=	push_swap

SRCS_DIR	=	srcs

SRCS =	push_swap.c \
		parsing.c \
		utils.c \
		lst_utils.c \
		move.c \
		element.c \
		ft_atoi.c \
		exit.c \
		markup.c \
		sort.c \
		sort_a.c \
		sort_b.c \
		info_move.c \
		parsing_utils.c \
		sort_utils.c

OBJDIR = objs

MEM = -fsanitize=address

OBJS	=	${addprefix ${OBJDIR}/, ${SRCS:.c=.o}}

HEAD	=	-I include

CC		= clang

CFLAGS	= -Wall -Werror -Wextra -g3

${OBJDIR}/%.o:${SRCS_DIR}/%.c
			mkdir -p ${@D}
			${CC} ${CFLAGS} ${MEM} ${HEAD} -c $< -o $@

$(NAME):	${OBJS}
					${CC} ${CFLAGS} ${MEM} ${HEAD} ${OBJS} -o $@

all: ${NAME}

clean:
			rm -rf ${OBJDIR}

fclean: clean
		rm -rf ${NAME}

re: fclean all
