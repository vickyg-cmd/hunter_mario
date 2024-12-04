##
## EPITECH PROJECT , [ YEAR ]
## [ NAME_OF_THE_PROJECT ]
## File description : meaningful
## No file there , just an epitech header example .
## You can even have multiple lines if you want !
##

SRC	=	src/my_putchar.c\
		src/my_putstr.c\
		src/my_putnbr.c\
		src/my_numlen.c\
		src/mod_struct.c\
		src/my_specifier_fun.c\
		src/conversion_f.c\
		src/my_printf.c\
		src/create_sprites.c\
		src/flag_hunter.c\
		src/add_sprites.c\
		src/home_window_stuff.c\
		src/tema_music.c\
		src/hunt_principe.c\
		src/play_window.c\
		src/my_hunter.c

OBJ	=	$(SRC:.c=.o)

NAME	=	my_hunter

CFLAGS	= 	-I./include -lmy -g3

CSFMLFLAGS	=	-lcsfml-graphics -lcsfml-system -lcsfml-audio -lcsfml-window

all: $(NAME)

$(NAME):	$(OBJ)
		gcc -o $(NAME) $(OBJ) $(CSFMLFLAGS)
clean:
	rm -f *.o

fclean: clean
	rm -f *.a
	rm -f $(NAME)

re: fclean all
