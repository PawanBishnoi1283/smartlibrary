
CXX = g++
CXXFLAGS = -Wall -std=c++17 -I.

SRC = main.cpp book.cpp user.cpp library.cpp
OBJ = $(SRC:.cpp=.o)
TARGET = SmartLibrary

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CXX) -o $@ $^

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $<

clean:
	rm -f $(OBJ) $(TARGET)
