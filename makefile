all: 
	g++ --std=c++14 -o solve solve.cpp
	g++ --std=c++14 -o solve2 solve2.cpp
clean:
	rm  solve solve2 *.o
