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

#COLOR
YELLOW=\033[0;33m
GREEN=\033[0;32m
NC=\033[0m

# thu muc chua file nguon
SRC= $(wildcard src/*.c)
EXECUTABLE = bin/chuongtrinh

all: linux run

win: cuoiky.c
	@echo "$(YELLOW)Dang bien dich cho Window...$(NC)"
	@$(WCC) cuoiky.c $(CFLAGS) -o $(EXECUTABLE).exe
	@echo "$(GREEN)XONG$(NC)"
linux: cuoiky.c
	@echo "$(YELLOW)Dang bien dich cho Linux/Unix...$(NC)"
	@$(CC) cuoiky.c $(CFLAGS) -o $(EXECUTABLE)
	@echo "$(GREEN)XONG$(NC)"

run:
	@./$(EXECUTABLE)
runexe:
	@./$(EXECUTABLE).exe

clean:
	@echo "$(YELLOW)Dang xoa file ...$(NC)"
	@rm -f $(EXECUTABLE) $(EXECUTABLE).exe
	@echo "$(GREEN)XONG$(NC)"
