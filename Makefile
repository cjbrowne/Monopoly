CC =g++
LD =g++
CFLAGS =-Iinclude -c
LDFLAGS =
CPP_FILES =$(wildcard src/*.cpp)
OBJ_FILES =$(patsubst src/%.cpp,obj/%.o,$(CPP_FILES))

.PHONY: obj_dir

Monopoly: $(OBJ_FILES)
	$(LD) $(LDFLAGS) -o $@ $^


obj/%.o: src/%.cpp | obj_dir
	$(CC) $(CFLAGS) -o $@ $<

obj_dir:
	mkdir -p obj

clean:
	rm obj
