CXX = clang++
SFML_PATH = /opt/homebrew/opt/sfml

# Include paths
CXXFLAGS = -std=c++17 \
	-Isrc \
	-Isrc/math \
	-Isrc/physics \
	-Iinclude \
	-I$(SFML_PATH)/include

# Linker flags
LDFLAGS = -L$(SFML_PATH)/lib -lsfml-graphics -lsfml-window -lsfml-system

# Source files from ALL subfolders
SRC = $(shell find src -name "*.cpp")

# Object files
OBJ = $(patsubst src/%.cpp, build/%.o, $(SRC))

# Build target
physics: $(OBJ)
	$(CXX) $(OBJ) -o build/physics_engine $(LDFLAGS)

# Compile rule
build/%.o: src/%.cpp
	@mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean
clean:
	rm -rf build

# Run
run: physics
	./build/physics