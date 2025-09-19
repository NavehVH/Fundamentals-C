CC = gcc
CXX = g++
CFLAGS = -Wall -Wextra -std=c11 -Iinclude
CXXFLAGS = -Wall -Wextra -std=c++17 -Iinclude

# collect C and C++ sources
C_SRC  = $(wildcard src_c/*.c)
C_OBJ  = $(C_SRC:.c=.o)

CPP_SRC = $(wildcard src_cpp/*.cpp src_cpp/structures/*.cpp)
CPP_OBJ = $(CPP_SRC:.cpp=.o)

all: program_c program_cpp

program_c: $(C_OBJ)
	$(CC) $(CFLAGS) -o $@ $(C_OBJ)

program_cpp: $(CPP_OBJ)
	$(CXX) $(CXXFLAGS) -o $@ $(CPP_OBJ)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(C_OBJ) $(CPP_OBJ) program_c program_cpp
