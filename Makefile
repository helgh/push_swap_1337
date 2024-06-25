# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hael-ghd <hael-ghd@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/10 15:45:40 by hael-ghd          #+#    #+#              #
#    Updated: 2024/03/24 23:40:41 by hael-ghd         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

NAME_BONUS = checker

CC = CC

FLAGS = -Wall -Wextra -Werror

SOURCE = part_1_mandatory.c part_2_mandatory.c part_3_mandatory.c move_1_mandatory.c move_2_mandatory.c parsing_1_mandatory.c parsing_2_mandatory.c \
					push_swap_mandatory.c sort_1_mandatory.c sort_2_mandatory.c sort_3_mandatory.c \

SOURCE_BONUS = part_1_bonus.c part_2_bonus.c part_3_bonus.c move_functions_1_bonus.c move_functions_2_bonus.c parsing_functions_1_bonus.c parsing_functions_2_bonus.c push_swap_bonus.c \
				read_line_1_bonus.c read_line_2_bonus.c \

OBJ_SRC = $(SOURCE:.c=.o)

OBJ_SRC_BONUS = $(SOURCE_BONUS:.c=.o)

all: $(NAME)

$(NAME): $(OBJ_SRC)
	$(CC) $(FLAGS) $(OBJ_SRC) -o $(NAME)

bonus: $(NAME_BONUS)

$(NAME_BONUS): $(OBJ_SRC_BONUS)
	$(CC) $(FLAGS) $(OBJ_SRC_BONUS) -o $(NAME_BONUS)

%tory.o: %tory.c push_swap.h
	$(CC) $(FLAGS) -c $<

%bonus.o: %bonus.c push_swap_bonus.h
	$(CC) $(FLAGS) -c $<

clean:
	rm -f $(OBJ_SRC) $(OBJ_SRC_BONUS)

fclean: clean
	rm -f $(NAME) $(NAME_BONUS)

re: fclean all