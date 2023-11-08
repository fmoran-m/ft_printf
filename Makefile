NAME = libftprintf.a
LIBFT = ./libft/libft.a
LIBFTDIR = ./libft
CC = gcc
FLAGS = -Wall -Wextra -Werror
RM = rm -f
AR = ar rcs
SRC = ft_printf.c ft_write_lower_hex.c ft_write_upper_hex.c ft_write_pointer_address.c
OBJS = ${SRC:.c=.o}

$(NAME): $(OBJS)
		make -C $(LIBFTDIR)
		cp $(LIBFT) $(NAME)
		$(AR) $(NAME) $(OBJS)

%.o:%.c
	$(CC) $(FLAGS) -c $< -o $@

all: $(NAME)

clean:
	$(RM) $(OBJS)
	cd $(LIBFTDIR) && make clean

fclean: clean
		$(RM) $(NAME)
		cd $(LIBFTDIR) && make fclean

re: fclean all
