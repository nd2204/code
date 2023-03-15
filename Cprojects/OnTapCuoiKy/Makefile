# # Compiler and linker options
# CFLAGS = -I./include -std=c99
# LDFLAGS =

# # Source files
# SRCDIR = src
# SRC = $(wildcard $(SRCDIR)/*.c)

# # Object files
# OBJDIR = obj
# OBJ = $(SRC:$(SRCDIR)/%.c=$(OBJDIR)/%.o)

# # Executable file name
# EXECUTABLE = bin/myprogram

# # Default rule
# all: $(EXECUTABLE)

# # Rule to link object files into executable
# $(EXECUTABLE): $(OBJ)
# 	$(CC) $(LDFLAGS) $^ -o $@

# # Rule to compile C source files into object files
# $(OBJDIR)/%.o: $(SRCDIR)/%.c
# 	$(CC) $(CFLAGS) -c $< -o $@

# # Clean up object files and executable
# clean:
# 	rm -f $(OBJ) $(EXECUTABLE)

#Trinh bien dich va flag
WCC = x86_64-w64-mingw32-gcc
CC = gcc
CFLAGS =-std=c99 -lm

# thu muc chua file nguon
SRC= $(wildcard src/*.c)
EXECUTABLE = bin/chuongtrinh

all: linux win

win: cuoiky.c
	@echo "Bien dich cho Window..."
	$(WCC) cuoiky.c $(CFLAGS) -o $(EXECUTABLE).exe
linux: cuoiky.c
	@echo "Dang bien dich cho Linux/Unix..."
	$(CC) cuoiky.c $(CFLAGS) -o $(EXECUTABLE)

run:
	./$(EXECUTABLE)
runexe:
	./$(EXECUTABLE).exe

clean:
	@echo "Dang xoa file ..."
	@rm -f $(EXECUTABLE) $(EXECUTABLE).exe
