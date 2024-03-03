compiler_flags := 
compiler := gcc $(compiler_flags)

obj := ./obj/
bin := ./bin/

sources := $(wildcard *.cpp)
headers := $(wildcard *.h)
objects := $(patsubst %.cpp, $(obj)%.o, $(sources))

run : build
	$(bin)program.exe

build : $(objects) $(bin)
	$(compiler) $(objects) -o $(bin)program.exe

$(objects) : $(obj)%.o : %.cpp $(headers) $(obj)
	$(compiler) -c $< -o $@

$(obj) :
	mkdir $(obj)
$(bin) :
	mkdir $(bin)

clean : 
	rm $(obj)*.o $(bin)*.exe
