# **************************************************************************** #
#                                VARIABLES                                     #
# **************************************************************************** #

HEADER        =                    includes/lem_in.h

LIB            =                    libft.a

LIBS        =                    libft/libft.a

SRC_PATH    =                    src

SRCS_NAME    =	lem_in.c map_resolver.c\


OBJS        =                     ${SRCS:.c=.o}

NAME        =                     lem_in.a

RM            =                     rm -f

FLAGS         =                     -Wall -Wextra -Werror

SRCS         =                     $(addprefix $(SRC_PATH)/,$(SRCS_NAME))

# **************************************************************************** #
#                                REGLES                                        #
# **************************************************************************** #

all:                            $(LIB) $(NAME)

%.o: %.c                         $(HEADER) $(LIBS)
	@echo "\033[0;32m[OK] \033[0m \033[0;33m Compiling:\033[0m" $<
	@gcc $(FLAGS) -I $(HEADER) -c $< -o$@

$(NAME):                        $(OBJS) $(HEADER)
	@cp libft/libft.a ./$(NAME)
	@echo "\x1b[36m\n[OK] \033[0m \x1b[35m Compiling Lem_in\033[0m"
	@ar rcs $(NAME) $(OBJS)

$(LIB):
	@$(MAKE) -C libft all

clean:
	@$(MAKE) -C libft clean
	@echo "\x1b[36m[OK] \033[0m \x1b[31m Removing File object\033[0m"
	@$(RM) $(OBJS)

fclean:                            clean
	@$(MAKE) -C libft fclean
	@echo "\x1b[36m[OK] \033[0m \x1b[31m Removing All\033[0m"
	@$(RM) $(NAME)

re:                                fclean all

.PHONY:                         clean fclean