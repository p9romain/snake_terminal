CXX = g++
CXXFLAGS = -g -W -Wall -std=c++2a -O3

LDFLAGS = -lncurses
EXEC_FILES = main
DATA = $(wildcard .*.data)

SRC = $(wildcard *.cpp)
OBJ = $(SRC:.cpp=.o)
HDR = $(filter-out main.hpp, $(SRC:.cpp=.hpp))

ARGS = $(filter-out $@, $(MAKECMDGOALS))

BIN_CMD = $(CXX) $(CXXFLAGS) -c $<
EXE_CMD = $(CXX) $(LDFLAGS) -o $@ $^ 

# Binary files
%.o: %.cpp
	@$(BIN_CMD)


# Executive files
main: $(OBJ)
	@$(EXE_CMD)


# Headers
main: $(HDR)


# Utilities
all: clear main
	@clear
	@./main

clean clear:
	@rm -f $(OBJ) $(EXEC_FILES)

reset: clean
	@rm -f $(DATA)