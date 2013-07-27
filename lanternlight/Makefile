.SUFFIXES : .o .cc .c
MAKE=make
CXX = g++
CXXFLAGS = -g -I/usr/local/include 
LIBS = -L/usr/local/lib -lSDL

all:
	cd bessie; $(MAKE) $(MFLAGS)
	cd src; $(MAKE) $(MFLAGS)
	${CXX} ${CXXFLAGS} -o lanternlight bessie/*.o src/*.o ${LIBS}

clean:
	rm -f bessie/*.o src/*.o lanternlight *.core

.cpp.o:
	$(CXX) $(CXXFLAGS) $< -o $@

