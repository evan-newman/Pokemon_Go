CC = g++
flags = -g
link_flags = $(flags) -c
exe_file = game

$(exe_file): location.o event.o pokecenter.o cave.o pokemon.o fire_type.o water_type.o grass_type.o nothing.o
	$(CC) $(flags) driver.cpp -o $(exe_file) location.o event.o pokecenter.o cave.o pokemon.o fire_type.o water_type.o grass_type.o nothing.o

location.o: location.cpp
	$(CC) $(link_flags) location.cpp

event.o: event.cpp
	$(CC) $(link_flags) event.cpp

pokecenter.o: pokecenter.cpp
	$(CC) $(link_flags) pokecenter.cpp

cave.o: cave.cpp
	$(CC) $(link_flags) cave.cpp

pokemon.o: pokemon.cpp
	$(CC) $(link_flags) pokemon.cpp

fire_type.o: fire_type.cpp
	$(CC) $(link_flags) fire_type.cpp

water_type.o: water_type.cpp
	$(CC) $(link_flags) water_type.cpp

grass_type.o: grass_type.cpp
	$(CC) $(link_flags) grass_type.cpp

nothing.o: nothing.cpp
	$(CC) $(link_flags) nothing.cpp

debug: location.o event.o pokecenter.o cave.o pokemon.o fire_type.o water_type.o grass_type.o nothing.o
	$(CC) location.cpp -D DEBUG
	$(CC) *.cpp

clean:
	rm location.o event.o pokecenter.o cave.o pokemon.o fire_type.o water_type.o grass_type.o nothing.o $(exe_file)
	
cleandev:
	rm location.o event.o pokecenter.o cave.o pokemon.o fire_type.o water_type.o grass_type.o nothing.o	
