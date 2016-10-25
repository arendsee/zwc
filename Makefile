TARGET=wordcount
CC=g++
FLAGS= -O2

${TARGET}: ${TARGET}.cpp
	${CC} -o wordcount ${FLAGS} ${TARGET}.cpp

clean:
	rm -f ${TARGET}
