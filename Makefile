TARGET = minishell

CMD = cc

CFLAGS = -Werror -Wall -Wextra

LDFLAGS = -lreadline

LIBFT_DIR = ./ft_libft

TARGET_LIBFT = $(LIBFT_DIR)/libft.a

LIBFT_LINK = -L$(LIBFT_DIR) -lft

LIBFT_INC = $(LIBFT_DIR)/libft.h $(LIBFT_DIR)/ft_printf.h $(LIBFT_DIR)/get_next_line.h

SRCS = \
	srcs/built_in/cd.c\
	srcs/built_in/pwd.c\
	srcs/built_in/echo.c\
	srcs/built_in/env.c\
	srcs/built_in/builtin.c\
	srcs/built_in/unset.c\
	srcs/built_in/export.c\
	srcs/built_in/exit.c\
	srcs/clean/cleaner.c\
	srcs/env/handel_env.c\
	srcs/execute/execute.c\
	srcs/parse/envrn.c\
	srcs/parse/heredoc.c\
	srcs/parse/input.c\
	srcs/parse/parser.c\
	srcs/parse/redirect.c\
	srcs/parse/surround.c\
	srcs/signal/signal.c\
	srcs/tokenize/token.c\
	srcs/utils/error.c\
	srcs/utils/helper.c\
	srcs/utils/utils.c\
	srcs/validate/quote.c\
	srcs/validate/validate.c\
	main.c\

OBJS = $(SRCS:.c=.o)

all : $(TARGET)

$(TARGET) : $(TARGET_LIBFT) $(OBJS)
	$(CMD) $(CFLAGS) $(OBJS) $(LIBFT_LINK) -o $(TARGET) $(LDFLAGS)
%.o : %.c
	$(CMD) $(CFLAGS) -c $< -o $@

$(TARGET_LIBFT) :
	@make -C $(LIBFT_DIR)

clean :
	rm -f $(OBJS)
	@make -C $(LIBFT_DIR) clean

fclean : clean
	rm -f $(TARGET)
	@make -C $(LIBFT_DIR) fclean

re : fclean all

.PHONY : all clean fclean re
