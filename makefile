compiler_flags := 
compiler := gcc $(compiler_flags)

obj := ./obj/
bin := ./bin/

sources := $(wildcard *.cpp)
headers := $(wildcard *.h)
objects := $(patsubst %.cpp, $(obj)%.o, $(sources))

run : build
	$(bin)program.exe

build : $(objects)
	$(compiler) $(objects) -o $(bin)program.exe

$(objects) : $(obj)%.o : %.cpp $(headers)
	$(compiler) -c $< -o $@

clean :
	rm $(obj)*.o $(bin)*.exe
