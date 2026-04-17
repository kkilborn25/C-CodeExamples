#Copyright kkilborn and lleita 2026
compiler = g++
flags = -Wall -std=c++17
compile = $(compiler) $(flags) -c
link = $(compiler) $(flags)

dynamicarray : project2sampletests.o dynamicarray.o
	$(link) $^ -o $@
	./$@

project2sampletests.o : project2sampletests.cc dynamicarray.h
	$(compile) $<
	
dynamicarray.o : dynamicarray.cc dynamicarray.h 
	$(compile) $<
	
clean :
	rm *.o dynamicarray