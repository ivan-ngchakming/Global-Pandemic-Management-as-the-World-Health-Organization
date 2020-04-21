FLAGS= -pedantic-errors -std=c++11

linkedlist.o: linkedlist.cpp linkedlist.h
	g++ $(FLAGS) -c $<

encryptdecrypt.o: encryptdecrypt.cpp encryptdecrypt.h linkedlist.h
	g++ $(FLAGS) -c $<

debug.o: debug.cpp encryptdecrypt.h linkedlist.h
	g++ $(FLAGS) -c $<

debug: linkedlist.o encryptdecrypt.o debug.o
	g++ $(FLAGS) $^ -o $@

clean:
	rm -f linkedlist.o encryptdecrypt.o debug.o
.PHONY:
	clean
