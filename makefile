CC      = gcc
CXX     = g++
CFLAGS  = -Wall -Wextra -std=c11
CXXFLAGS= -Wall -Wextra -std=c++17

# Header search paths
C_INC_DIRS   = src_c/include
CPP_INC_DIRS = src_cpp/include src_cpp

CFLAGS   += $(addprefix -I,$(C_INC_DIRS))
CXXFLAGS += $(addprefix -I,$(CPP_INC_DIRS))

# Sources / Objects
C_SRC   = $(wildcard src_c/*.c)
C_OBJ   = $(C_SRC:.c=.o)

CPP_SRC = $(wildcard src_cpp/*.cpp src_cpp/structures/*.cpp src_cpp/algorithms/*.cpp)
CPP_OBJ = $(CPP_SRC:.cpp=.o)

all: program_c program_cpp

program_c: $(C_OBJ)
	$(CC) $(CFLAGS) -o $@ $(C_OBJ) -pthread

program_cpp: $(CPP_OBJ)
	$(CXX) $(CXXFLAGS) -o $@ $(CPP_OBJ) -pthread

# Pattern rules
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(C_OBJ) $(CPP_OBJ) program_c program_cpp
