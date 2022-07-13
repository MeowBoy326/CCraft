CC = gcc
CFLAGS = -std=c99 -O2 -Wpedantic
CFLAGS += -Ilib/glfw/include -Ilib/glad/include
LDFLAGS = lib/glfw/src/libglfw3.a lib/glad/src/gl.o

SRC  = $(wildcard src/**/*.c) $(wildcard src/*.c)
OBJ  = $(SRC:.c=.o)
BIN = bin

.PHONY: all clean

all: dirs libs game

libs:
ifeq ($(OS),Windows_NT)
	cd lib/glfw && cmake . -G "MinGW Makefiles" -DUSE_MSVC_RUNTIME_LIBRARY_DLL=0 -DGLFW_VULKAN_STATIC=1 && mingw32-make
else
	cd lib/glfw && cmake . -DGLFW_USE_WAYLAND=1 -DGLFW_VULKAN_STATIC=1 && make
endif
	cd lib/glad && $(CC) -o src/gl.o -Iinclude -c src/gl.c

dirs:
	mkdir -p ./$(BIN)

run: all
ifeq ($(OS),Windows_NT)
	$(BIN)/CCraft.exe
else
	$(BIN)/CCraft
endif

game: $(OBJ)
ifeq ($(OS),Windows_NT)
	$(CC) -o $(BIN)/CCraft.exe $^ $(LDFLAGS)
else
	$(CC) -o $(BIN)/CCraft $^ $(LDFLAGS)
endif

%.o: %.c
	$(CC) -o $@ -c $< $(CFLAGS)

clean:
	rm -rf $(BIN) $(OBJ) 
