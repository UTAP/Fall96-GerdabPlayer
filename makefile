UNAME_S := $(shell uname -s)
ifeq ($(UNAME_S),Darwin)
		HEAD := \"sdlheaders/mac.hpp\"
  	CCFLAGS= -framework SDL2 -framework SDL2_mixer
else
		HEAD := \"sdlheaders/linux.hpp\"
		CCFLAGS += -l SDL2 -l SDL2_mixer
endif

all: example1 gerdab.o head

example1: gerdab.o examples/example1.cpp
		g++ src/gerdab.o examples/example1.cpp $(CCFLAGS) -o example1.out

gerdab.o: src/gerdabPlayer.cpp
		g++ -std=c++11 -c src/gerdabPlayer.cpp -o src/gerdab.o
head:
		echo "#include "$(HEAD) > ./src/sdlHeaders.hpp
