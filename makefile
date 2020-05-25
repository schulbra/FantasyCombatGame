CXX = g++
CXXFLAGS =  -std=c++0x
CXXFLAGS +=   -Wall
CXXFLAGS +=   -pedantic-errors
CXXFLAGS +=   -g
#CXXFLAGS +=   -O3
LDFLAGS =  -lboost_date_time
OBJS = GamePlay.o Menu.o Character.o Vampire.o Barbarian.o BlueMen.o Medussa.o HarryPotter.o InputValidation.o main.o
SRCS = GamePlay.cpp Menu.cpp Character.cpp Vampire.cpp Barbarian.cpp BlueMen.cpp Medussa.cpp HarryPotter.cpp InputValidation.cpp main.cpp
HEADERS = GamePlay.hpp Menu.hpp Character.hpp Vampire.hpp Barbarian.hpp BlueMen.hpp Medussa.hpp HarryPotter.hpp InputValidation.hpp

#target: dependencies
#rule to build
#

Project3: ${OBJS} ${HEADERS}
	${CXX} ${LDFLAGS} ${OBJS} -o Project3 

${OBJS}: ${SRCS}
	${CXX} ${CXXFLAGS} -c   $(@:.o=.cpp)

.PHONY: clean
clean:
	rm ${OBJS} Project3

zip:
	zip -D ProjectName_Brandon_Schultz.zip ${HEADERS} ${SRCS} makefile
