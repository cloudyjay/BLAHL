0;136;0cCXX = g++
CXXFLAGS = -g -Wall -MMD
EXEC = cc3k					# change this
SOURCES = ${wildcard *.cc}			# possibly this too
OBJECTS = ${SOURCES:.cc=.o}
DEPENDS = ${OBJECTS:.o=.d}

${EXEC}: ${OBJECTS}
	${CXX} ${CXXFLAGS} ${OBJECTS} -o ${EXEC}

-include ${DEPENDS}

.PHONY: clean

clean: 
	rm ${EXEC} ${DEPENDS} ${OBJECTS}
