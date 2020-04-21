FLAGS= -pedantic-errors -std=c++11

linkedlist.o: linkedlist.cpp linkedlist.h
	g++ $(FLAGS) -c $<

encryptdecrypt.o: encryptdecrypt.cpp encryptdecrypt.h linkedlist.h
	g++ $(FLAGS) -c $<

debug.o: debug.cpp encryptdecrypt.h linkedlist.h
	g++ $(FLAGS) -c $<

debug: linkedlist.o encryptdecrypt.o debug.o
	g++ $(FLAGS) $^ -o $@

load_init_countries_statistics.o: load_init_countries_statistics.cpp load_init_countries_statistics.h performance_index.h
	g++ $(FLAGS) $^ -c $<

performance_index.o: performance_index.cpp performance_index.h
	g++ $(FLAGS) $^ -c $<

test: test.cpp load_init_countries_statistics.o performance_index.o
	g++ $(FLAGS) $^ -o $@

clean:
	rm -f *.o
.PHONY:
	clean
