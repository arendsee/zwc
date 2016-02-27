TARGET=wordcount
CC=g++
FLAGS= -O2

all:
	${CC} -o wordcount ${FLAGS} ${TARGET}.cpp

clean:
	rm -f ${TARGET}
