FLAGS = -Wall -Wextra -Werror -lmlx -framework OpenGL -framework AppKit

INC = Mandatory/so_long.h Mandatory/gnl/get_next_line.h \
						Mandatory/ft_printf/ft_printf.h  

B_INC = Bonus/so_long_bonus.h Bonus/gnl/get_next_line.h \
					Bonus/ft_printf/ft_printf.h  


SRC_FILES = so_long.c map_checker.c draw.c play.c \
	gnl/get_next_line.c gnl/get_next_line_utils.c \
	
SRC_PRINTF = ft_printf/ft_printf.c ft_printf/ft_ptr.c ft_printf/ft_putchar.c ft_printf/ft_putnbr.c ft_printf/ft_putstr.c ft_printf/ft_tohex.c ft_printf/ft_unsigned.c \

OBJ_PRINTF = $(SRC_PRINTF:.c=.o)

FT_PRINTF = libftprintf.a

B_SRC_FILES = so_long_bonus.c map_checker_bonus.c \
 			draw_bonus.c \
			play_bonus.c \
			update_bonus.c \
			gnl/get_next_line.c gnl/get_next_line_utils.c \
			ft_itoa.c \

BONUS_PRINTF = Bonus/ft_printf/ft_printf.c \
			Bonus/ft_printf/ft_ptr.c \
			Bonus/ft_printf/ft_putchar.c \
			Bonus/ft_printf/ft_putnbr.c \
			Bonus/ft_printf/ft_putstr.c \
			Bonus/ft_printf/ft_tohex.c \
			Bonus/ft_printf/ft_unsigned.c \

SRC = $(addprefix Mandatory/, $(SRC_FILES))

B_SRC = $(addprefix Bonus/, $(B_SRC_FILES))

$(NAME): all

all: $(SRC) $(INC) $(FT_PRINTF)
	cc $(FLAGS) $(SRC) $(FT_PRINTF) -o so_long

%.o : %.c
	cc -c $< -o $@

$(FT_PRINTF) : $(OBJ_PRINTF)
	ar rc $(FT_PRINTF) $(OBJ_PRINTF)

bonus: $(B_SRC) $(B_INC) $(FT_PRINTF)
	cc $(FLAGS) $(B_SRC) $(BONUS_PRINTF) -o so_long_bonus

clean:
	rm -f $(OBJ_PRINTF)

fclean: clean
	rm -rf so_long so_long_bonus libftprintf.a

re: fclean all

.PHONY: all clean fclean bonus re
