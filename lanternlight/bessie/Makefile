CXX = g++
CXXFLAGS = -g $(shell sdl2-config --cflags)
OBJS = Draw.o Draw2.o

all:
	${CXX} ${CXXFLAGS} -c line2array.cpp
	${CXX} ${CXXFLAGS} -c Draw.cpp
	${CXX} ${CXXFLAGS} -c Draw2.cpp
	${CXX} ${CXXFLAGS} -c util.cpp
	${CXX} ${CXXFLAGS} -c ImgSys.cpp

clean: 
	rm *.o

.cpp.o:
	$(CXX) $(CXXFLAGS) -c $< -o $@
