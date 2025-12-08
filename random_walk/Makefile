# Nom de l'exécutable
NAME = random_walk

# Compilateur
CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++17 \
           -Iinclude \
           -I/opt/homebrew/include \
           -I/opt/homebrew/opt/sfml/include

# Dossiers
SRC_DIR = src
OBJ_DIR = obj

# Recherche des fichiers
SRC = $(wildcard $(SRC_DIR)/*.cpp) main.cpp
OBJ = $(patsubst %.cpp, $(OBJ_DIR)/%.o, $(SRC))

# Lib SFML pour macOS (Homebrew)
LIBS = -L/opt/homebrew/lib -L/opt/homebrew/opt/sfml/lib \
       -lsfml-graphics -lsfml-window -lsfml-system

all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) $(CXXFLAGS) $^ -o $@ $(LIBS)

$(OBJ_DIR)/%.o: %.cpp
	@mkdir -p $(OBJ_DIR)/$(SRC_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re