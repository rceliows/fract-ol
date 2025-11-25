# Standard
NAME			= fractol

# Directories
LIBFT			= ./libft/libft.a
MINILIBX		= ./minilibx-linux/libmlx_Linux.a
INC			= inc/
SRC_DIR			= src/
OBJ_DIR			= obj/

# Compiler and Flags
CC			= cc
CFLAGS			= -Wall -Wextra -Werror -I$(INC) -I./minilibx-linux
RM			= rm -f
AR			= ar rcs
LIBS			= $(MINILIBX) -lX11 -lXext -lm

# Source Files
FRACTOL		=	$(SRC_DIR)main.c		\
			$(SRC_DIR)mandelbrot.c		\
			$(SRC_DIR)julia.c		\
			$(SRC_DIR)render.c		\
			$(SRC_DIR)colours.c		\
			$(SRC_DIR)events.c		\
			$(SRC_DIR)complex_math.c	\
			$(SRC_DIR)init.c		\
			$(SRC_DIR)atof.c		\
			$(SRC_DIR)utils.c

# Concatenate all source files
SRCS 			= $(FRACTOL)

# Apply the pattern substitution to each source file in SRC and produce a corresponding list of object files in the OBJ_DIR
OBJ 			= $(patsubst $(SRC_DIR)%.c,$(OBJ_DIR)%.o,$(SRCS))

# Build rules
start:				
			@make all

$(LIBFT):
			@make -C ./libft

# Check if minilibx-linux directory exists, if not clone it
./minilibx-linux:
			@echo "MinilibX not found. Cloning from repository..."
			@git clone https://github.com/42paris/minilibx-linux.git
			@echo "MinilibX cloned successfully!"

$(MINILIBX):		./minilibx-linux
			@echo "Building MinilibX..."
			@make -C ./minilibx-linux
			@echo "MinilibX built successfully!"

all: 			$(NAME)

$(NAME): 		$(OBJ) $(LIBFT) $(MINILIBX)
			@$(CC) $(CFLAGS) $(OBJ) -o $(NAME) $(LIBFT) $(LIBS)

# Compile object files from source files
$(OBJ_DIR)%.o:		$(SRC_DIR)%.c ./minilibx-linux
			@mkdir -p $(@D)
			@$(CC) $(CFLAGS) -c $< -o $@

clean:
			@$(RM) -r $(OBJ_DIR)
			@make clean -C ./libft

fclean: 		clean
			@$(RM) $(NAME)
			@$(RM) $(LIBFT)

re: 			fclean all

# Phony targets represent actions not files
.PHONY: 		start all clean fclean re
