all:
	gcc -Wall -Wpedantic -std=c99 -g -c BuildDataBase.c -o BuildDataBase
	gcc -Wall -Wpedantic -std=c99 -g UseDataBase.c -o UseDataBase

BuildDataBase:	BuildDataBase.o	

build:
	./BuildDataBase
use:
	./UseDataBase < test-input.txt
clean:
	rm BuildDataBase UseDataBase *.o