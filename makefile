FLAGS = -pedantic-errors -std=c++11

all: load_init_countries_statistics.o performance_index.o test clean

load_init_countries_statistics.o: load_init_countries_statistics.cpp load_init_countries_statistics.h performance_index.h
		g++ $(FLAGS) $^ -c $<

performance_index.o: performance_index.cpp performance_index.h
		g++ $(FLAGS) $^ -c $<

test: test.cpp load_init_countries_statistics.o performance_index.o
		g++ $(FLAGS) $^ -o $@

clean:
		rm -f *.o *.gch

.PHONY: clean
