CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -pedantic

TARGET = chip8

SRC = src/main.cpp src/chip8.cpp
OBJ = $(SRC:.cpp=.o)

$(TARGET): $(OBJ)
	$(CXX) $(OBJ) -o $(TARGET)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -Iinclude -c $< -o $@

clean:
	rm -f $(OBJ) $(TARGET)
