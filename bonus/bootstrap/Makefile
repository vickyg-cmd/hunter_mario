## ----------------------------------------------------------------------------------- ##
##                                                                                     ##
## EPITECH PROJECT - Tue, Nov, 2024                                                    ##
## Title           - B-MUL-100-BAR-1-1-myhunter-victoria.gonzalez-malave               ##
## Description     -                                                                   ##
##                                                                                     ##

SRC	=	bsmyhunter.c

OBJ		=    $(SRC:.c=.o)

NAME	=	exc

CFLAGS	=	-I./include -lmy -g3 

all: $(NAME)

$(NAME):	$(OBJ)
		gcc -o $(NAME) $(OBJ) -lcsfml-graphics -lcsfml-system -lcsfml-audio -lcsfml-window

clean:
		rm -f *.a

fclean:	clean 
		rm -f *.a
		rm -f $(NAME)

re: fclean all