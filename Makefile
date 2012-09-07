CC =g++
LD =g++
CFLAGS =-Iinclude -c
LDFLAGS =
ALL_CPP_FILES = $(wildcard src/*.cpp)
CPP_FILES = $(filter-out src/debug.cpp src/release.cpp src/SDLGame.cpp src/Game.cpp,$(ALL_CPP_FILES))
OBJ_FILES = $(patsubst src/%.cpp,obj/%.o,$(CPP_FILES))

.PHONY: clean
.PHONY: default

# add SDL stuff to the *FLAGS variables for the release build
monopoly: CFLAGS += $(shell sdl-config --cflags)
monopoly: LDFLAGS += $(shell sdl-config --libs)

# swap these around to switch between debug and release builds
default: monopoly
#default: monopoly-debug

monopoly-debug: $(OBJ_FILES) obj/Game.o obj/debug.o
	$(LD) -o $@ $^ $(LDFLAGS)

monopoly: $(OBJ_FILES) obj/SDLGame.o obj/release.o
	$(LD) -o $@ $^ $(LDFLAGS)

obj/%.o: src/%.cpp
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) -o $@ $<

clean:
	@rm -r obj
	@rm monopoly
	@rm monopoly-debug
	@echo "Cleaned!"
