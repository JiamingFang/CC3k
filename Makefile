CXX = g++
CXXFLAGS = -std=c++14
EXEC = cc3k
OBJECTS = main.o Helpers.o Floor.o Cell.o Character.o Hero.o Enemy.o Potion.o Treasure.o Display.o GameObject.o BaseObject.o Chamber.o Item.o
DEPENDS = ${OBJECTS:.o=.d}

${EXEC}: ${OBJECTS}
	${CXX} ${CXXFLAGS} ${OBJECTS} -o ${EXEC}

-include ${DEPENDS}

.PHONY: clean

clean:
	rm ${OBJECTS} ${EXEC} ${DEPENDS}