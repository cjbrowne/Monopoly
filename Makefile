CC =g++
LD =g++
CFLAGS =-Iinclude -c -Wall -Wextra -std=c++0x -g -DDEBUG=3
LDFLAGS =-g
ALL_CPP_FILES = $(wildcard src/*.cpp)
CPP_FILES = $(filter-out src/debug.cpp src/release.cpp src/SDLGame.cpp src/Game.cpp,$(ALL_CPP_FILES))
OBJ_FILES = $(patsubst src/%.cpp,obj/%.o,$(CPP_FILES))

.PHONY: clean
.PHONY: default

# add SDL stuff to the *FLAGS variables for the release build
monopoly: CFLAGS += $(shell sdl-config --cflags) $(shell pkg-config SDL_image --cflags) -DSDL_VERSION
monopoly: LDFLAGS += $(shell sdl-config --libs) $(shell pkg-config SDL_image --libs)

# add debugging flags to the *FLAGS variables for the debug build
monopoly-debug: CFLAGS += -DDEBUG -g
monopoly-debug: LDFLAGS += -g

# swap these around to switch between debug and release builds
default: monopoly
#default: monopoly-debug

monopoly-debug: $(OBJ_FILES) obj/Game.o obj/debug.o
	$(LD) -o $@ $^ $(LDFLAGS)
	@echo "\033[1;32m[Success]\033[0m"

monopoly: $(OBJ_FILES) obj/SDLGame.o obj/release.o
	$(LD) -o $@ $^ $(LDFLAGS)
	@echo "\033[1;32m[Success]\033[0m"

obj/%.o: src/%.cpp include/%.h
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) -o $@ $<

obj/release.o: src/release.cpp
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) -o $@ $<

obj/debug.o: src/debug.cpp
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) -o $@ $<

clean:
	@rm -rf obj
	@rm -f monopoly
	@rm -f monopoly-debug
	@echo "Cleaned!"
