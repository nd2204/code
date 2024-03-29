# Thanks to Job Vranish (<https://spin.atomicobject.com/2016/08/26/makefile-c-projects/>)
# MAKEFLAGS += --silent
TARGET_EXEC := final_program
CFLAGS := -Wall

DEBUG := 1

ifeq ($(DEBUG), 1)
    CFLAGS += -g -DDEBUG
    TARGET_EXEC := debug
else
    TARGET_EXEC := main
endif

BUILD_DIR := ./build
SRC_DIRS := ./src
INC_DIRS := $(shell find ./include -type d)

.SILENT: *.o

# Find all the C and C++ files we want to compile
# Note the single quotes around the * expressions. The shell will incorrectly expand these otherwise, but we want to send the * directly to the find command.
SRCS := $(shell find $(SRC_DIRS) -name '*.cpp' -or -name '*.c' -or -name '*.s')
# Prepends BUILD_DIR and appends .o to every src file
# As an example, ./your_dir/hello.cpp turns into ./build/./your_dir/hello.cpp.o
OBJS := $(SRCS:%=$(BUILD_DIR)/%.o)
# String substitution (suffix version without %).
# As an example, ./build/hello.cpp.o turns into ./build/hello.cpp.d
DEPS := $(OBJS:.o=.d)
# Add a prefix to INC_DIRS. So moduleA would become -ImoduleA. GCC understands this -I flag
INC_FLAGS := $(addprefix -I,$(INC_DIRS))

# The -MMD and -MP flags together generate Makefiles for us!
# These files will have .d instead of .o as the output.
CPPFLAGS := $(INC_FLAGS) -MMD -MP

all: run

run: $(BUILD_DIR)/$(TARGET_EXEC)
	@echo "====================== $(BUILD_DIR)/$(TARGET_EXEC) ====================== "
	@$(BUILD_DIR)/$(TARGET_EXEC)

clean:
	rm -r $(BUILD_DIR)

# The final build step.
$(BUILD_DIR)/$(TARGET_EXEC): $(OBJS)
	@$(CXX) $(OBJS) -o $@ $(LDFLAGS)

# Build step for C source
$(BUILD_DIR)/%.c.o: %.c
	mkdir -p $(dir $@)
	$(CC) $(CPPFLAGS) $(CFLAGS) -c $< -o $@

# Build step for C++ source
$(BUILD_DIR)/%.cpp.o: %.cpp
	mkdir -p $(dir $@)
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c $< -o $@

.PHONY: clean

# Include the .d makefiles. The - at the front suppresses the errors of missing
# Makefiles. nitially, all the .d files will be missing, and we don't want those
# errors to show up.
-include $(DEPS)
