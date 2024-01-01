CFLAGS := -Wall -Weffc++ -Wextra -Wconversion -Wsign-conversion -Werror
CPPFLAGS := -g3 -DNDEBUG -std=c++17 -pedantic-errors

TARGET := bin/debug

build:
	@mkdir -p bin
	$(CXX) $(CPPFLAGS) $(CFLAGS) -o bin/debug src/*.cpp 

run:
	@$(TARGET)
