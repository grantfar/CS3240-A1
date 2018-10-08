#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
#include "config.h"
#include "readLine.h"

int readLine(char* buffer, int FD){
    memset(buffer, 0 , LINE_LENGTH);
    int current = lseek(FD,(off_t)0,SEEK_CUR);
    int readlength = read(FD,buffer,LINE_LENGTH-1);
    if(readlength == LINE_LENGTH-1){
        for(int i = 0; i<LINE_LENGTH; i++){
            if(buffer[i]=='\n'){
                buffer[i+1] = '\0';
                lseek(FD,(off_t)(i+1+current),SEEK_SET);
                return 2;
            
            }
            if(i == LINE_LENGTH-1){
                fprintf(stderr,"%s\n","Line Length To Long in CSV");
                exit(EXIT_FAILURE);
            }
        }
    }
    else if(readlength == 0){
        return 0;
    }
    else if(readlength < 0){
        fprintf(stderr,"error %i: %s\n", errno, strerror(errno));
        close(FD);
        exit(errno);
    }
    else{
        for(int i = 0; i<readlength; i++){
            if(buffer[i]=='\n'){
                buffer[i+1] = '\0';
                lseek(FD,(off_t)i+1+current,SEEK_SET);
                return 2;
            
            }
            if(i == readlength-1){
                buffer[i+1] = '\0';
                return 1;
            }
        }
    }
    return -1;
}