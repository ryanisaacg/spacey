C_FILES := $(wildcard src/*.cpp)
OBJ_FILES := $(addprefix obj/,$(notdir $(C_FILES:.cpp=.o)))
LD_FLAGS :=
CC_FLAGS := -Wall -Wfatal-errors -Werror -pedantic -std=c++11 -Wextra -Wdouble-promotion -Wunused-parameter -Wunused -Wuninitialized -DDO_TESTS
run: build
	@bin/./out spaces 2 data

build: obj/ bin/ bin/out

debug: bin/dbg
	@gdb bin/dbg

bin/:
	@mkdir bin

obj/:
	@mkdir obj

clean:
	@rm -r obj/
	@rm -r bin/

bin/dbg: $(OBJ_FILES)
	@g++ $(LD_FLAGS) -g -o $@ $^

bin/out: $(OBJ_FILES)
	@g++ $(LD_FLAGS) -o $@ $^

obj/%.o: src/%.cpp
	@g++ $(CC_FLAGS) -c -o $@ $<
