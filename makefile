
BuildDataBase:	BuildDataBase.o	readInCSV.o readLine.o csvLineRead.o sort.o
	gcc -Wall -Wpedantic -std=c99 -g BuildDataBase.o readInCSV.o readLine.o csvLineRead.o sort.o -o BuildDataBase

BuildDataBase.o: BuildDataBase.c song.h config.h readInCSV.h readLine.h csvLineRead.h song.h
	gcc -Wall -Wpedantic -std=c99 -g -c BuildDataBase.c -o BuildDataBase.o
readInCSV.o: readInCSV.c readInCSV.h readLine.h csvLineRead.h config.h song.h
	gcc -Wall -Wpedantic -std=c99 -g -c readInCSV.c
readLine.o: readLine.c readLine.h
	gcc -Wall -Wpedantic -std=c99 -g -c readLine.c -o readLine.o
csvLineRead.o: csvLineRead.c csvLineRead.h song.h
	gcc -Wall -Wpedantic -std=c99 -g -c csvLineRead.c -o csvLineRead.o
sort.o: sort.c song.h
	gcc -Wall -Wpedantic -std=c99 -g -c sort.c -o sort.o
build:
	./BuildDataBase
use:
	./UseDataBase < test-input.txt
clean:
	rm -f BuildDataBase UseDataBase *.o