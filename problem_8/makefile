CXX = g++
CXXFLAGS = -Wall
TARGET = problem_8
SRC = problem_8.cpp

all: $(TARGET)
	./$(TARGET)

$(TARGET): $(SRC)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(SRC)

test: $(TARGET)
	./$(TARGET) test

clean:
	rm -f $(TARGET)

.PHONY: all clean test