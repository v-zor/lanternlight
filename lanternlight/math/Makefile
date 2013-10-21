CXX = g++
CXXFLAGS = -g $(shell sdl2-config --cflags) -I../bessie
OBJS = main.o player.o

all:
	${CXX} ${CXXFLAGS} -c line.cpp
	${CXX} ${CXXFLAGS} -c polygon.cpp
	${CXX} ${CXXFLAGS} -c lanternpolygon.cpp

clean: 
	rm -f *.o

.cpp.o:
	$(CXX) $(CXXFLAGS) -c $< -o $@
