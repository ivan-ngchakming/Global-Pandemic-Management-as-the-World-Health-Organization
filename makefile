FLAGS= -pedantic-errors -std=c++11

list.o: list.cpp list.h
	g++ $(FLAGS) -c $<

encryptdecrypt.o: encryptdecrypt.cpp encryptdecrypt.h list.h
	g++ $(FLAGS) -c $<

debug:debug.cpp encryptdecrypt.cpp list.cpp
	g++ $(FLAGS) $^ -o $@

clean:

.PHONY:
	clean
