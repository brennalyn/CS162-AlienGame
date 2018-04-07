#
## Author: Brenna Smith
## Date: 03/15/2018
## Description: A makefile for the the final game program 
#


CXX = g++
CXXFLAGS = -std=c++0x
CXXFLAGS += -Wall
CXXFLAGS += -pedantic-errors
CXXFLAGS += -g

OBJS = main.o AlienGame.o Space.o ItemSpace.o AlienSpace.o EventSpace.o EscapeSpace.o inputValid.o Menu.o

SRCS = main.cpp AlienGame.cpp Space.cpp ItemSpace.cpp AlienSpace.cpp EventSpace.cpp EscapeSpace.cpp inputValid.cpp Menu.cpp
HEADERS = AlienGame.hpp ItemSpace.hpp Space.hpp AlienSpace.hpp EventSpace.hpp EscapeSpace.hpp inputValid.hpp Menu.hpp

#target: dependencies     
	#rule to build


runtest: ${OBJS} ${HEADERS}
	${CXX} ${CXXFLAGS} ${OBJS} -o runtest

${OBJS}: ${SRCS}
	${CXX} ${CXXFLAGS} -c $(@:.o=.cpp)

clean:
	rm *.o runtest


