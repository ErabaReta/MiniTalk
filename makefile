CC = cc
RM = rm -rf
CFLAGS = -Wall -Wextra -Werror
CCFILES = client.c
SCFILES = server.c
COFILES = $(CCFILES:.c=.o)
SOFILES = $(SCFILES:.c=.o)
CNAME = client
SNAME = server
NAME = $(SNAME) $(CNAME)

all : $(NAME)

$(CNAME) : $(COFILES)
	$(CC) $(CFLAGS) $(COFILES) -o $(CNAME)

$(SNAME) : $(SOFILES)
	$(CC) $(SFLAGS) $(SOFILES) -o $(SNAME)

$(COFILES) : $(CCFILES)
	$(CC) -c $(CFLAGS) $(CCFILES)

$(SOFILES) : $(SCFILES)
	$(CC) -c $(CFLAGS) $(SCFILES)

#.c.o:
#	$(CC) -c $< -o $@
# $(CC) $(CFLAGS) -c $< -o $@
bonus : all

clean :
	$(RM) $(COFILES) $(SOFILES)

fclean : clean
	$(RM) $(NAME)

re: fclean all
