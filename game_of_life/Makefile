CXX = clang++
SFML_PATH = /opt/homebrew/opt/sfml
CXXFLAGS = -std=c++17 -Iinclude -I$(SFML_PATH)/include
LDFLAGS = -L$(SFML_PATH)/lib -lsfml-graphics -lsfml-window -lsfml-system

SRC = $(wildcard src/*.cpp)
OBJ = $(SRC:src/%.cpp=build/%.o)

game_of_life: $(OBJ)
	$(CXX) $(OBJ) -o build/game_of_life $(LDFLAGS)

build/%.o: src/%.cpp
	@mkdir -p build
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f build/*.o build/game_of_life

run: game_of_life
	./build/game_of_life