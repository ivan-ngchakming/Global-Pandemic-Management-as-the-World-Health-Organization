FLAGS= -pedantic-errors -std=c++11

ui.o: ui.cpp ui.h
	g++ $(FLAGS) -c $<

linkedlist.o: linkedlist.cpp linkedlist.h
	g++ $(FLAGS) -c $<

encryptdecrypt.o: encryptdecrypt.cpp encryptdecrypt.h
	g++ $(FLAGS) -c $<

load_init_countries_statistics.o: load_init_countries_statistics.cpp load_init_countries_statistics.h performance_index.h
	g++ $(FLAGS) -c $<

performance_index.o: performance_index.cpp performance_index.h
	g++ $(FLAGS) -c $<

tutorial.o: tutorial.cpp tutorial.h
		g++ $(FLAGS) -c $<

infection_rate_calculator.o: infection_rate_calculator.cpp infection_rate_calculator.h
	g++ $(FLAGS) -c $<

load_save.o: load_save.cpp load_save.h
	g++ $(FLAGS) -c $<

resources_management.o: resources_management.cpp resources_management.h
	g++ $(FLAGS) -c $<


apply_effects.o: apply_effects.cpp apply_effects.h
	g++ $(FLAGS) -c $<

dynamic_array.o: dynamic_array.cpp dynamic_array.h
	g++ $(FLAGS) -c $<

command.o : command.cpp command.h
	g++ $(FLAGS) -c $<


#-----------------------------for debugging-------------------------------------


#for debugging
test: test.cpp load_init_countries_statistics.o performance_index.o infection_rate_calculator.o
	g++ $(FLAGS) $^ -o $@

debug_linkedlist.o: debug_linkedlist.cpp linkedlist.h
	g++ $(FLAGS) -c $<

debug_linkedlist: linkedlist.o debug_linkedlist.o
	g++ $(FLAGS) $^ -o $@

debug_encryptdecrypt.o: debug_encryptdecrypt.cpp
	g++ $(FLAGS) -c $<

debug_encryptdecrypt: debug_encryptdecrypt.o encryptdecrypt.o linkedlist.o
	g++ $(FLAGS) $^ -o $@


debug_command.o: debug_command.cpp
	g++ $(FLAGS) -c $<

debug_command: debug_command.o command.o
	g++ $(FLAGS) $^ -o $@


debug_load_save.o: debug_load_save.cpp
	g++ $(FLAGS) -c $<

debug_load_save: debug_load_save.o load_save.o linkedlist.o encryptdecrypt.o command.o dynamic_array.o
	g++ $(FLAGS) $^ -o $@
#----------------------------end debugging--------------------------------------


#-------------------------------------main------------------------------------
main.o: main.cpp main.h
	g++ $(FLAGS) -c $<

main: main.o linkedlist.o load_save.o encryptdecrypt.o command.o dynamic_array.o performance_index.o ui.o resources_management.o infection_rate_calculator.o apply_effects.o
	g++ $(FLAGS) $^ -o $@
#-------------------------------------main------------------------------------

encryptionmachine.o: encryptionmachine.cpp
	g++ $(FLAGS) -c $<

encryptionmachine : encryptionmachine.o main.o linkedlist.o encryptdecrypt.o command.o load_save.o dynamic_array.o
	g++ $(FLAGS) $^ -o $@

clean:
	rm -f *.o

.PHONY:
	clean
