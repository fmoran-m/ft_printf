NAME = libftprintf.a
LIBFT = ./libft/libft.a
LIBFTDIR = ./libft
CC = gcc
FLAGS = -Wall -Wextra -Werror
RM = rm -f
AR = ar rcs
SRC = ft_printf.c
OBJS = ${SRC:.c=.o}

all = $(NAME)

%.o:%.c
	$(CC) $(FLAGS) -c $< -o $@

$(NAME): $(OBJS) $(LIBFT)
		$(AR) $(NAME) $(OBJS)

$(LIBFT):
	make -C $(LIBFTDIR)

clean:
	$(RM) $(OBJS)
	cd $(LIBFTDIR) && make clean

fclean: clean
		$(RM) $(NAME)
		cd $(LIBFTDIR) && make fclean

re: fclean all