CC = gcc
CFLAGS = -std=c99 -O2 -g -Wpedantic
#CFLAGS += -Wno-pointer-arith -Wno-newline-eof -Wno-unused-parameter -Wno-gnu-statement-expression
#CFLAGS += -Wno-gnu-compound-literal-initializer -Wno-gnu-zero-variadic-macro-arguments
CFLAGS +=  -Ilib/glfw/include #-Ilib/cglm/include -Ilib/glad/include -Ilib/stb -Ilib/noise
LDFLAGS = lib/glfw/src/libglfw3.a #lib/glad/src/glad.o lib/cglm/.libs/libcglm.a lib/noise/libnoise.a . -lm

SRC  = $(wildcard src/**/*.c) $(wildcard src/*.c)
OBJ  = $(SRC:.c=.o)
BIN = bin

.PHONY: all clean

all: dirs libs game

libs:
	cd lib/glfw && cmake . -G "MinGW Makefiles" -DUSE_MSVC_RUNTIME_LIBRARY_DLL=0 -DGLFW_VULKAN_STATIC=1 && mingw32-make

dirs:
	mkdir -p ./$(BIN)

run: all
	$(BIN)/game.exe

game: $(OBJ)
	$(CC) -o $(BIN)/game.exe $^ $(LDFLAGS)

%.o: %.c
	$(CC) -o $@ -c $< $(CFLAGS)

clean:
	rm -rf $(BIN) $(OBJ) 