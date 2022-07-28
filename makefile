SRC = $(shell find YSHCPP/ -type f -name '*.cpp')

OBJ = $(SRC:.cpp=.o)

CC = x86_64-w64-mingw64-g++
CCL = g++

NAME = YSH

all: $(NAME)

$(NAME): $(OBJ)
	$(CCL) -o $(NAME) $(OBJ)
	
clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

commit:
	git add .
	git commit -a