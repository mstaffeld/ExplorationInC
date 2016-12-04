CC := gcc
CFLAGS := -std=c99 -Wall -Werror -g
OBJECTS := $(patsubst src/%.c,src/%.o,$(wildcard src/*.c))
OUTPUT := bin
TESTOBJECTS := $(patsubst test/%.c, test/%.o,$(wildcard test/*.c))

compile: $(OBJECTS) $(TESTOBJECTS)
	@mkdir -p $(OUTPUT)
	$(CC) $(CFLAGS) -o $(OUTPUT)/roman $(OBJECTS) $(TESTOBJECTS) `pkg-config --cflags --libs check`

clean:
	git clean -dxf
