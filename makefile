CC = cc
RM = rm -rf
CFLAGS = -Wall -Wextra -Werror
CFILES = 
OFILES = $(CFILES:.c=.o)
NAME = 

all : $(NAME)

$(NAME) : $(OFILES)
	$(CC) $(OFILES) -o $(NAME)

# $(OFILES) : $(CFILES)
# 	$(CC) -c $(CFILES)

.c.o:
	$(CC) -c $< -o $@
# $(CC) $(CFLAGS) -c $< -o $@

clean :
	$(RM) $(OFILES) $(BONUS_OFILES)

fclean : clean
	$(RM) $(NAME)

re: fclean all
