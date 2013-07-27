CXX = g++
CXXFLAGS = -g -I/usr/local/include -I../bessie -I../math
OBJS = main.o player.o

all:
	${CXX} ${CXXFLAGS} -c main.cpp
	${CXX} ${CXXFLAGS} -c player.cpp

clean: 
	rm -f *.o

.cpp.o:
	$(CXX) $(CXXFLAGS) -c $< -o $@
