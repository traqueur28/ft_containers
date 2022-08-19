#    Colors
GREY = \e[90m
RED = \e[91m
GREEN = \e[92m
YELLOW = \e[93m
BLUE = \e[34m
PURPLE = \e[95m
CYAN = \e[96m
END = \e[39m

#    Showing command
DISP = TRUE

ifeq ($(DISP),TRUE)
    HIDE =
else
    HIDE = @
endif

#    Includes
CLASS_PATH = class

CFILES =	Algorithm/equal.hpp Algorithm/lexicographical_compare.hpp \
			Iterator/iterator_traits.hpp Iterator/reverse_iterator.hpp Iterator/random_access_iterator.hpp\
			Type_traits/enable_if.hpp Type_traits/is_integral.hpp \

CLASS = $(addprefix $(CLASS_PATH)/, $(CFILES))

#    Files
SRCS_PATH = src

FILES = main.cpp

SRCS = $(addprefix $(SRCS_PATH)/, $(FILES))

#    Compilation
NAME = tester_01

CXX = c++

CFLAGS = -Wall -Wextra -Werror -std=c++98 -Wshadow -Wno-shadow

RM = rm -rf

OBJS_PATH = objs/

OBJS = $(patsubst $(SRCS_PATH)%.cpp,    $(OBJS_PATH)%.o,    $(SRCS))

#    Rules
all: $(NAME)

$(NAME): $(OBJS_PATH) $(OBJS) $(CLASS)
	@ echo "$(BLUE)\n         ***Make $(NAME) ***\n$(END)"
	$(HIDE) $(CXX) $(CFLAGS) $(OBJS) -o $(NAME)
	@ echo "$(GREEN)\n        ---$(NAME) created ---\n$(END)"

$(OBJS_PATH):
	$(HIDE) mkdir -p $(OBJS_PATH)

$(OBJS_PATH)%.o: $(SRCS_PATH)%.cpp $(CLASS) Makefile
	$(HIDE) $(CXX) $(CFLAGS) -c $< -o $@
	@ echo "$(GREEN)[ OK ]$(END) $(CYAN)${<:.s=.o}$(END)"

clean:
	$(HIDE) $(RM) $(OBJS_PATH)
	@ echo "$(PURPLE)\n        *** Clean objects ***\n$(END)"

fclean: clean
	$(HIDE) $(RM) $(NAME)
	@ echo "$(RED)\n        *** Remove $(NAME) ***\n$(END)"

re: fclean all

.PHONY: all clean fclean re