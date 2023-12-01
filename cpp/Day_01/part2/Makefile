NAME = day01
COMPILER = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98

SRCS = ./main.cpp \
		./Clues.class.cpp
OBJS = $(SRCS:.cpp=.o)

all: $(NAME)

.cpp.o:
	${COMPILER} ${CFLAGS} -c $< -o ${<:.cpp=.o}

$(NAME): ${OBJS}
	${COMPILER} ${FLAGS} $(OBJS) -o $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
