CXX = g++
CXXFLAGS = -g -I/usr/local/include -I../bessie
OBJS = main.o player.o

all:
	${CXX} ${CXXFLAGS} -c main.cpp
	${CXX} ${CXXFLAGS} -c player.cpp
	${CXX} ${CXXFLAGS} -c line.cpp
	${CXX} ${CXXFLAGS} -c polygon.cpp
	${CXX} ${CXXFLAGS} -c lanternpolygon.cpp

clean: 
	rm -f *.o

.cpp.o:
	$(CXX) $(CXXFLAGS) -c $< -o $@
