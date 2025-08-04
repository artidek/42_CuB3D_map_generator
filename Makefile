CC = cc 
CFLAGS = -Wall -Wextra -Werror -g

GNL = get_next_line/get_next_line.c get_next_line/get_next_line_utils.c
SRC = ft_split.c generator.c helpers.c ft_strjoin.c

GNLOBJS = $(GNL:.c=.o)
SRCOBJS = $(SRC:.c=.o)

OBJS = $(GNLOBJS) $(SRCOBJS)

NAME = generator

%.o: %.c
		$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS)
		$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

all: $(NAME)
clean:
	rm -f get_next_line/*.o 
	rm -f *.o 
fclean: clean
	rm -f generator
re: fclean all

.PHONY: all clean fclean re