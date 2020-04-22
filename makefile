FLAGS= -pedantic-errors -std=c++11

linkedlist.o: linkedlist.cpp linkedlist.h
	g++ $(FLAGS) -c $<

encryptdecrypt.o: encryptdecrypt.cpp encryptdecrypt.h linkedlist.h
	g++ $(FLAGS) -c $<

load_init_countries_statistics.o: load_init_countries_statistics.cpp load_init_countries_statistics.h performance_index.h
	g++ $(FLAGS) -c $<

performance_index.o: performance_index.cpp performance_index.h
	g++ $(FLAGS) -c $<



#-----------------------------for debugging-------------------------------------

test: test.cpp load_init_countries_statistics.o performance_index.o
	g++ $(FLAGS) $^ -o $@

debug_linkedlist.o: debug_linkedlist.cpp linkedlist.h
	g++ $(FLAGS) -c $<

debug_linkedlist: linkedlist.o debug_linkedlist.o
	g++ $(FLAGS) $^ -o $@

encryption_machine.o: encryption_machine.cpp
	g++ $(FLAGS) -c $<

encryption_machine: encryption_machine.o encryptdecrypt.o linkedlist.o
	g++ $(FLAGS) $^ -o $<

#----------------------------end debugging--------------------------------------

clean:
	rm -f *.o
.PHONY:
	clean
