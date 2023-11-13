NAME = libftprintf.a
LIBFT = ./libft/libft.a
LIBFTDIR = ./libft
CC = gcc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f
AR = ar rcs
SRC = ft_printf.c write_characters.c write_numbers.c
OBJS = ${SRC:.c=.o}

$(NAME): $(OBJS)
		make -C $(LIBFTDIR)
		cp $(LIBFT) $(NAME)
		$(AR) $(NAME) $(SRC)


%.o:%.c
	$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

clean:
	$(RM) $(OBJS)
	cd $(LIBFTDIR) && make clean

fclean: clean
		$(RM) $(NAME)
		cd $(LIBFTDIR) && make fclean

re: fclean all
