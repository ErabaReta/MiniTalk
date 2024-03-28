CC = cc
RM = rm -rf
CFLAGS = -Wall -Wextra -Werror
CCFILES = client.c ft_minitalk_atoi.c
SCFILES = server.c
COFILES = $(CCFILES:.c=.o)
SOFILES = $(SCFILES:.c=.o)
CNAME = client
SNAME = server
NAME = $(SNAME) $(CNAME)

all : $(NAME)

$(CNAME) : $(COFILES)
	$(CC) $(CFLAGS) $(COFILES) -fsanitize=address -o $(CNAME)

$(SNAME) : $(SOFILES)
	$(CC) $(SFLAGS) $(SOFILES) -fsanitize=address -o $(SNAME)

$(COFILES) : $(CCFILES)
	$(CC) -c $(CFLAGS) $(CCFILES)

$(SOFILES) : $(SCFILES)
	$(CC) -c $(CFLAGS) $(SCFILES)

bonus : all

clean :
	$(RM) $(COFILES) $(SOFILES)

fclean : clean
	$(RM) $(NAME)

re: fclean all
