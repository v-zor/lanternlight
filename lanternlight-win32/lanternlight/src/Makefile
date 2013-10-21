CXX = g++
CXXFLAGS = -g $(shell sdl2-config --cflags) -I../bessie -I../math
OBJS = main.o player.o

all:
	${CXX} ${CXXFLAGS} -c main.cpp
	${CXX} ${CXXFLAGS} -c player.cpp

clean: 
	rm -f *.o

.cpp.o:
	$(CXX) $(CXXFLAGS) -c $< -o $@
