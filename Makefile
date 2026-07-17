CC = gcc
CFLAGS = -Wall -g

SRC_DIR = src
BUILD_DIR = build

# Define Include Paths for all module folders
INCLUDES = -Iinclude -Isrc/tty -Isrc/screen -Isrc/led

# Recursively find all .c files using shell find
SOURCES = $(shell find $(SRC_DIR) -name "*.c")

# Map src/*.c to build/*.o
OBJECTS = $(patsubst $(SRC_DIR)/%.c, $(BUILD_DIR)/%.o, $(SOURCES))

# Define your final executable name (doesn't have to be main)
TARGET = hardware-controller

all: $(TARGET)

# Link all objects into the target
$(TARGET): $(OBJECTS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJECTS)

# Compile any src/*.c to build/*.o
# The '| $(BUILD_DIR)' ensures the directory exists first
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c | $(BUILD_DIR)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

# Create the object directory
$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

clean:
	rm -rf $(BUILD_DIR) $(TARGET)

.PHONY: all clean