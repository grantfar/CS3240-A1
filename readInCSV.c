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
#include "readLine.h"
#include "csvLineRead.h"
#include "readInCSV.h"


int readInCSV(int CSV, song* songs, songOffset* offsets, int lineCount){

    char* linebuffer = (char*)malloc(LINE_LENGTH);
    readLine(linebuffer,CSV);
    int inc = 0;
    
    while(readLine(linebuffer,CSV)>0){
        csvLineSpliter(linebuffer,songs,offsets,inc);
        inc++;
    }
    return 0;
}