CC := gcc
CFLAGS := -std=c99 -Wall -Werror -g
OBJECTS := $(patsubst src/%.c,src/%.o,$(wildcard src/*.c))
OUTPUT := bin

compile: $(OBJECTS)
	@mkdir -p $(OUTPUT)
	$(CC) $(CFLAGS) -o $(OUTPUT)/hello $(OBJECTS)
