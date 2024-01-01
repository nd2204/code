#Trinh bien dich va flag
WCC = x86_64-w64-mingw32-gcc
CC = gcc
CFLAGS =-std=c99 -lm -Wall

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
