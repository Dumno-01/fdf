NAME		=	fdf

HEAD_DIR	=	./include/
HEAD		=	fdf.h
HEADS		=	$(addprefix $(HEAD_DIR), $(HEAD))

LIBFT_DIR	=	./libft/
LIBFT_HEAD	=	libft.h
LIBFT_A		=	$(LIBFT_DIR)libft.a

MLX_DIR		=	./minilibx-linux/
MLX_HEAD	=	mlx.h
MLX_A		=	$(MLX_DIR)libmlx.a

SRCS_DIR	=	./srcs/
SRCS		=	main.c\
				print.c\
				reading_map.c\
				bresham_utils.c

OBJS_DIR	=	./objs/
OBJS		=	$(SRCS:%.c=$(OBJS_DIR)%.o)

CC			=	cc
CC_FLAG		=	#-Wall -Wextra -Werror -g3 -O3 

RM			=	rm -rf


all:	make_mlx make_libft $(NAME)

$(OBJS)	:	$(OBJS_DIR)%.o: $(SRCS_DIR)%.c $(HEADS) $(LIBFT_A) $(LIBFT_DIR)libft.h $(MLX_A) $(MLX_DIR)mlx.h 
			mkdir -p $(OBJS_DIR)
			$(CC) $(CC_FLAG) -I$(HEAD_DIR) -I$(LIBFT_DIR) -I$(MLX_DIR) -c $< -o $@

$(NAME)	:	$(OBJS) $(LIBFT_A) $(MLX_A)
			$(CC) $(CC_FLAG) $(OBJS) $(LIBFT_A) $(MLX_A) -lXext -lX11 -lm -lz -o $(NAME)

make_mlx :
			$(MAKE) -C $(MLX_DIR)

make_libft :
			$(MAKE) -C $(LIBFT_DIR)

clean	:
			make fclean -C $(LIBFT_DIR)
			make clean -C $(MLX_DIR)
			$(RM) $(OBJS_DIR)

fclean	:	clean
			$(RM) $(NAME)

re:			fclean all

tt: make_libft $(NAME)


.PHONY	:	all clean fclean re make_libft make_mlx
