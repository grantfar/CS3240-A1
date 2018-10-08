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
#include "readLine.h"
#include "sort.h"
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
    song* songs = (song*)malloc(sizeof(song)*lineCount);
    songOffset* offsets = (songOffset*)malloc(sizeof(songOffset)*lineCount);
    readInCSV(CSV,songs,offsets,lineCount);

    close(CSV);

    sort(songs,offsets,lineCount);
    FILE * binarySongData = fopen("BinarySongData","w+");
    FILE * offsetData = fopen("offsetData","w+");
    fwrite(&lineCount,sizeof(int),1,offsetData);
    fclose(offsetData);
    fwrite(offsets,sizeof(songOffset),lineCount,offsetData);
    for(int i = 0; i<lineCount; i++){
        fwrite(songs+i,sizeof(song),1,binarySongData);
        fwrite(songs[i].Artist,offsets[i].ArtistLength,1,binarySongData);
        fwrite(songs[i].Album,offsets[i].AlbumLength,1,binarySongData);
        fwrite(songs[i].Name,offsets[i].NameLength,1,binarySongData);
    }
    fclose(binarySongData);
    return 0;
}
