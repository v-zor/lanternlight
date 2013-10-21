.SUFFIXES : .o .cc .c
MAKE=make
CXX = g++
CXXFLAGS = -g $(shell sdl2-config --cflags) 
LIBS = $(shell sdl2-config --libs)

all:
	cd bessie; $(MAKE) $(MFLAGS)
	cd math; $(MAKE) $(MFLAGS)
	cd src; $(MAKE) $(MFLAGS)
	${CXX} ${CXXFLAGS} -o lanternlight bessie/*.o src/*.o $(LIBS) -lole32 -loleaut32

clean:
	rm -f bessie/*.o math/*.o src/*.o lanternlight *.core

.cpp.o:
	$(CXX) $(CXXFLAGS) $< -o $@

