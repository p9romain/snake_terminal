CXX = g++
CXXFLAGS = -g -W -Wall -std=c++2a -O3

LDFLAGS = -lncurses
EXEC_FILES = main
SRC = $(wildcard *.cpp)
OBJ = $(SRC:.cpp=.o)

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
main: Game.hpp


# Utilities
all: clear main
	@clear
	@./main

clean clear:
	@rm -f $(OBJ) $(EXEC_FILES)