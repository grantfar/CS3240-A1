/**
 * WMU CS3240 Fall 2018
 * Grant Farnsworth
 * Assignment 1
 * Build Database
 * */
#include "song.h"
#include "config.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
#include "readInCSV.h"
#include "readline.h"
int main(int argc, char const *argv[])
{
    int CSV;
    
    char* linebuffer = (char*)malloc(LINE_LENGTH);

    if((CSV = open("SongCSV.csv",O_RDONLY))<3){
        fprintf(stderr,"error %i: %s\n", errno, strerror(errno));
    }
    int lineCount = -1;
    while(readLine(linebuffer,CSV)>0){
        lineCount++;
    }
    lseek(CSV,(off_t)0,SEEK_SET);

    song* songs = readInCSV(CSV,lineCount);

    close(CSV);
    FILE * binarySongData = fopen("BinarySongData","w+");

    fwrite(songs,sizeof(song),lineCount,binarySongData);
    return 0;
}
