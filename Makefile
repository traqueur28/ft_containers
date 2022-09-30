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
			Iterator/iterator_traits.hpp Iterator/reverse_iterator.hpp Iterator/map_iterator.hpp Iterator/map_reverse_iterator.hpp \
			Type_traits/enable_if.hpp Type_traits/is_integral.hpp \
			vector.hpp stack.hpp map.hpp\
			Utility/proto.hpp Utility/pair.hpp \
			Map/node.hpp

CLASS = $(addprefix $(CLASS_PATH)/, $(CFILES))

#    Files
SRCS_PATH = src

FILES = main.cpp \
		vector_main.cpp stack_main.cpp map_main.cpp

SRCS = $(addprefix $(SRCS_PATH)/, $(FILES))

#    Compilation
NAME = ft_tester
STD_NAME = std_tester

CXX = clang++
#CXX = clang++ -O1 -g -fsanitize=address

CFLAGS = -Wall -Wextra -Werror -std=c++98

RM = rm -rf

OBJS_PATH = objs_ft/
STD_OBJS_PATH = objs_std/

OBJS =     $(patsubst $(SRCS_PATH)%.cpp,    $(OBJS_PATH)%.o,    $(SRCS))
STD_OBJS = $(patsubst $(SRCS_PATH)%.cpp,    $(STD_OBJS_PATH)%.o,    $(SRCS))

#    Rules
all: $(NAME) $(STD_NAME)

ft:	 $(NAME)

std: $(STD_NAME)

$(NAME): $(OBJS_PATH) $(OBJS) $(CLASS)
	@ echo "$(BLUE)\n         ***Make $(NAME) ***\n$(END)"
	$(HIDE) $(CXX) $(CFLAGS) $(OBJS) -o $(NAME)
	@ echo "$(GREEN)\n        ---$(NAME) created ---\n$(END)"

$(STD_NAME): $(STD_OBJS_PATH) $(STD_OBJS) $(CLASS)
	@ echo "$(BLUE)\n         ***Make $(STD_NAME) ***\n$(END)"
	$(HIDE) $(CXX) $(CFLAGS) $(STD_OBJS) -o $(STD_NAME)
	@ echo "$(GREEN)\n        ---$(STD_NAME) created ---\n$(END)"

$(OBJS_PATH):
	$(HIDE) mkdir -p $(OBJS_PATH)

$(STD_OBJS_PATH):
	$(HIDE) mkdir -p $(STD_OBJS_PATH)

$(OBJS_PATH)%.o: $(SRCS_PATH)%.cpp $(CLASS) Makefile
	$(HIDE) $(CXX) $(CFLAGS) -c $< -o $@
	@ echo "$(GREEN)[ OK ]$(END) $(CYAN)${<:.s=.o}$(END)"

$(STD_OBJS_PATH)%.o: $(SRCS_PATH)%.cpp $(CLASS) Makefile
	$(HIDE) $(CXX) $(CFLAGS) -D STD -c $< -o $@
	@ echo "$(GREEN)[ OK ]$(END) $(CYAN)${<:.s=.o}$(END)"

diff: $(NAME) $(STD_NAME)
	@./$(NAME) > $(NAME).txt
	@./$(STD_NAME) > $(STD_NAME).txt
	-@diff -ys $(NAME).txt $(STD_NAME).txt
	@rm -rf $(NAME).txt $(STD_NAME).txt

clean:
	$(HIDE) $(RM) $(OBJS_PATH)
	$(HIDE) $(RM) $(STD_OBJS_PATH)
	@ echo "$(PURPLE)\n        *** Clean objects ***\n$(END)"

fclean: clean
	$(HIDE) $(RM) $(NAME)
	$(HIDE) $(RM) $(STD_NAME)
	@ echo "$(RED)\n        *** Remove $(NAME) ***\n$(END)"

re: fclean all

.PHONY: all clean fclean re std ft diff