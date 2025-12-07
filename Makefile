# Standard
NAME			= fractol

# Directories
LIBFT_DIR		= ./libft
LIBFT			= $(LIBFT_DIR)/libft.a
MINILIBX_DIR		= ./minilibx-linux
MINILIBX		= $(MINILIBX_DIR)/libmlx_Linux.a
INC				= inc/
SRC_DIR			= src/
OBJ_DIR			= obj/

# Compiler and Flags
CC				= cc
CFLAGS			= -Wall -Wextra -Werror -I$(INC) -I$(LIBFT_DIR)/inc -I$(MINILIBX_DIR)
RM				= rm -f
AR				= ar rcs
LIBS			= $(MINILIBX) $(LIBFT) -lX11 -lXext -lm

# Source Files
FRACTOL			=	$(SRC_DIR)main.c \
				$(SRC_DIR)mandelbrot.c \
				$(SRC_DIR)julia.c \
				$(SRC_DIR)tricorn.c \
				$(SRC_DIR)render.c \
				$(SRC_DIR)colours.c \
				$(SRC_DIR)events.c \
				$(SRC_DIR)complex_math.c \
				$(SRC_DIR)init.c \
				$(SRC_DIR)atof.c \
				$(SRC_DIR)utils.c \

# Concatenate all source files
SRCS 			= $(FRACTOL)

# Apply the pattern substitution to each source file in SRC and produce a corresponding list of object files in the OBJ_DIR
OBJ 			= $(patsubst $(SRC_DIR)%.c,$(OBJ_DIR)%.o,$(SRCS))

# Build rules
all: 			$(NAME)

$(NAME): 		$(LIBFT) $(MINILIBX) $(OBJ)
			@echo "Linking $(NAME)..."
			@$(CC) $(CFLAGS) $(OBJ) -o $(NAME) $(LIBS)
			@echo "Build complete!"

# Check if libft directory exists, if not clone it
$(LIBFT_DIR):
			@echo "libft not found. Cloning from repository..."
			@git clone git@github.com:rceliows/libft.git $(LIBFT_DIR)
			@echo "libft cloned successfully!"

$(LIBFT):		$(LIBFT_DIR)
			@echo "Building libft..."
			@make -C $(LIBFT_DIR)
			@echo "libft built successfully!"

# Check if minilibx-linux directory exists, if not clone it
$(MINILIBX_DIR):
			@echo "MinilibX not found. Cloning from repository..."
			@git clone https://github.com/42paris/minilibx-linux.git $(MINILIBX_DIR)
			@echo "MinilibX cloned successfully!"

$(MINILIBX):		$(MINILIBX_DIR)
			@echo "Building MinilibX..."
			@make -C $(MINILIBX_DIR)
			@echo "MinilibX built successfully!"

# Compile object files from source files
$(OBJ_DIR)%.o:		$(SRC_DIR)%.c
			@mkdir -p $(@D)
			@$(CC) $(CFLAGS) -c $< -o $@

clean:
			@echo "Cleaning object files..."
			@$(RM) -r $(OBJ_DIR)
			@if [ -d "$(LIBFT_DIR)" ]; then make clean -C $(LIBFT_DIR); fi
			@if [ -d "$(MINILIBX_DIR)" ]; then make clean -C $(MINILIBX_DIR) 2>/dev/null || true; fi
			@echo "Clean complete!"

fclean: 		clean
			@echo "Removing executables..."
			@$(RM) $(NAME)
			@if [ -d "$(LIBFT_DIR)" ]; then $(RM) $(LIBFT); fi
			@echo "Full clean complete!"

fcleanall:		fclean
			@echo "Removing library directories..."
			@if [ -d "$(LIBFT_DIR)" ]; then rm -rf $(LIBFT_DIR); echo "Removed $(LIBFT_DIR)"; fi
			@if [ -d "$(MINILIBX_DIR)" ]; then rm -rf $(MINILIBX_DIR); echo "Removed $(MINILIBX_DIR)"; fi
			@echo "Full clean with libraries complete!"

re: 			fclean all

reall:			fcleanall all
