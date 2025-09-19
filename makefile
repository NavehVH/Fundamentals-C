CXX := g++
CXXFLAGS := -Wall -Wextra -std=c++17 -Iinclude

# grab all cpp files in root and src/structures
SRC := $(wildcard *.cpp) $(wildcard src/structures/*.cpp)
OBJ := $(SRC:.cpp=.o)
TARGET := program

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $@ $(OBJ)

# works for files in subdirs too
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(TARGET)
