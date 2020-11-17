##
## EPITECH PROJECT, 2020
## Makefil
## File description:
## Makefile
##

NAME	=	my_hunter

SRC	=		src/main.c			\
			src/ducks.c			\
			src/player.c		\
			src/game.c			\
			src/init.c			\
			src/render.c		\
			src/render2.c		\
			src/update.c		\
			src/style_maker.c	\
			src/style_maker2.c	\
			src/manage.c		\
			src/case.c			\
			src/ah.c			\
			src/special.c

OBJ     =	$(SRC:.c=.o)

CFLAGS  =	-Wall -Wextra

FFLAGS	=	-l csfml-graphics -l csfml-system -l csfml-audio -l csfml-window -lm

all     :	$(NAME) clean

clean	:
		rm src/*.o

$(NAME) :	$(OBJ)
		gcc -g -o $(NAME) $(OBJ) $(FFLAGS) libmy.a

fclean  :	clean
		rm -f $(NAME)
		rm -f vgcore*

re      :	fclean all clean

.PHONE: all clean fclean re
