CC ?= gcc
CFLAGS += -std=c99 -O2
CFLAGS += -fPIE -D_FORTIFY_SOURCE=2
CFLAGS += -Wpedantic -Werror -Wall
CFLAGS += -Ilib/glad/include
LDFLAGS ?= obj/glad.o obj/libglwf3.a

SRC  = $(wildcard src/**/*.c) $(wildcard src/*.c)
OBJ  = $(SRC:.c=.o)
BIN  = bin

.PHONY: all clean

all: clean dirs game

libs:
ifeq ($(OS),Windows_NT)
	cd lib/glfw && cmake . -G "MinGW Makefiles" -DUSE_MSVC_RUNTIME_LIBRARY_DLL=0 -DGLFW_VULKAN_STATIC=1 && mingw32-make
else
	cd obj && cmake -S ../lib/glfw -DGLFW_USE_WAYLAND=1 -DGLFW_VULKAN_STATIC=1 && make
endif
	$(CC) -o obj/glad.o -Ilib/glad/include -c lib/glad/src/glad.c

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
	$(CC) $(CFLAGS) -o $@ -c $<

clean:
	rm -rf $(BIN) $(OBJ) 
