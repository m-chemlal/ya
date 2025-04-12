CC = cc
CFLAGS = -Wall -Wextra -Werror

NAME = so_long
NAME_BONUS = so_long_bonus

SRC = ./Mandatory/so_long.c ./Mandatory/get_next_line.c ./Mandatory/get_next_line_utils.c \
      ./Mandatory/check_map.c ./Mandatory/ft_split.c ./Mandatory/ft_strncmp.c ./Mandatory/draw_map.c \
      ./Mandatory/events.c ./Mandatory/flood_fill.c ./Mandatory/free_data.c ./Mandatory/move_count.c
OBJ = $(SRC:.c=.o)

SRC_BONUS = ./Bonus/so_long_bonus.c ./Bonus/get_next_line_bonus.c ./Bonus/get_next_line_utils_bonus.c \
            ./Bonus/check_map_bonus.c ./Bonus/ft_split_bonus.c ./Bonus/ft_strncmp_bonus.c ./Bonus/load_img_bonus.c \
            ./Bonus/render_map_bonus.c ./Bonus/events_bonus.c ./Bonus/flood_fill_bonus.c ./Bonus/free_data_bonus.c \
            ./Bonus/enemy_bonus.c ./Bonus/move_count_bonus.c ./Bonus/move_enemy_bonus.c
BONUS_OBJ = $(SRC_BONUS:.c=.o)

GREEN       := \033[38;5;82m  
YELLOW      := \033[38;5;226m 
BLUE        := \033[38;5;45m  
RED         := \033[38;5;196m 
RESET       := \033[0m       
OK_SIGN     := 🎮 🟢 "SUCCESS"
INFO_SIGN   := 🎮 🟡 "INFO"
WORKING     := 🎮 🔵 "LOADING"
ERROR_SIGN  := 🎮 🔴 "ERROR"


all: $(NAME)
	@echo "$(OK_SIGN) $(GREEN)Build complete! Start your game!$(RESET)"
	@echo "$(INFO_SIGN) $(YELLOW)Here comes Scrat!$(RESET)"
	@echo "      Scrat is ready to collect acorns!"

$(NAME): $(OBJ)
	@echo "$(WORKING) $(BLUE)Linking and building mandatory: $(NAME)$(RESET)"
	@$(CC)  $(CFLAGS) $(OBJ) -lmlx -framework OpenGL -framework AppKit -o $(NAME)
	@echo "$(OK_SIGN) $(GREEN)Mandatory build complete! Start your game!$(RESET)"

bonus: $(NAME_BONUS)

$(NAME_BONUS): $(BONUS_OBJ)
	@echo "$(WORKING) $(BLUE)Linking and building bonus: $(BONUS_NAME)$(RESET)"
	@$(CC) $(BONUS_OBJ) -lmlx -framework OpenGL -framework AppKit -o $(NAME_BONUS)
	@echo "$(OK_SIGN) $(GREEN)Bonus build complete! Ready for enhanced gameplay!$(RESET)"

./Mandatory/%.o: ./Mandatory/%.c ./Mandatory/so_long.h ./Mandatory/get_next_line.h
	@echo "$(WORKING) $(YELLOW)Compiling: $<$(RESET)"
	@$(CC)  $(CFLAGS) -c $< -o $@

./Bonus/%.o: ./Bonus/%.c ./Bonus/so_long_bonus.h ./Bonus/get_next_line_bonus.h
	@echo "$(WORKING) $(YELLOW)Compiling bonus: $<$(RESET)"
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@echo "$(INFO_SIGN) $(YELLOW)Cleaning object files...$(RESET)"
	@rm -f $(OBJ) $(BONUS_OBJ)
	@echo "$(OK_SIGN) $(GREEN)Object files cleaned!$(RESET)"

fclean: clean
	@echo "$(INFO_SIGN) $(RED)Removing executables: $(NAME) and $(BONUS_NAME)$(RESET)"
	@rm -f $(NAME) $(NAME_BONUS)
	@echo "$(OK_SIGN) $(GREEN)Executables removed! Ready for a fresh start!$(RESET)"

re: fclean all
