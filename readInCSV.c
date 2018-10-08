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
#include "readline.h"
#include "csvLineRead.h"
#include "readInCSV.h"


song *readInCSV(int CSV, int lineCount){

    char* linebuffer = (char*)malloc(LINE_LENGTH);
    song* songs = (song*)malloc(sizeof(song)*lineCount);
    readLine(linebuffer,CSV);
    int inc = 0;
    song *tmp;
    
    while(readLine(linebuffer,CSV)>0){
        tmp = csvLineSpliter(linebuffer);
        memcpy(&songs[inc],tmp,sizeof(song));
        free(tmp);
        inc++;
    }
    return songs;
}