FLAGS= -pedantic-errors -std=c++11

linkedlist.o: linkedlist.cpp linkedlist.h
	g++ $(FLAGS) -c $<

load_save.o: load_save.cpp load_save.h
	g++ $(FLAGS) -c $<

encryptdecrypt.o: encryptdecrypt.cpp encryptdecrypt.h
	g++ $(FLAGS) -c $<

command.o : command.cpp command.h
	g++ $(FLAGS) -c $<

dynamic_array.o: dynamic_array.cpp dynamic_array.h
	g++ $(FLAGS) -c $<

performance_index.o: performance_index.cpp performance_index.h
	g++ $(FLAGS) -c $<

ui.o: ui.cpp ui.h
	g++ $(FLAGS) -c $<

resources_management.o: resources_management.cpp resources_management.h
	g++ $(FLAGS) -c $<

infection_rate_calculator.o: infection_rate_calculator.cpp infection_rate_calculator.h
	g++ $(FLAGS) -c $<

apply_effects.o: apply_effects.cpp apply_effects.h
	g++ $(FLAGS) -c $<





#-------------------------------------main------------------------------------
main.o: main.cpp main.h
	g++ $(FLAGS) -c $<

main: main.o linkedlist.o load_save.o encryptdecrypt.o command.o dynamic_array.o performance_index.o ui.o resources_management.o infection_rate_calculator.o apply_effects.o
	g++ $(FLAGS) $^ -o startgame
#-------------------------------------main------------------------------------

clean:
	rm -f *.o

.PHONY:
	clean
