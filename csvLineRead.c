#include <stdlib.h>
#include "song.h"
#include "csvLineRead.h"
song *csvLineSpliter(char *toSplit){
    int Start = 0;
    int current = 0;
    char *tmp;
    song *returnSong = (song*)malloc(sizeof(song));
    for(int i = 0; i<19; i++){
        
        while((toSplit[current]!=',') & (toSplit[current]!='\0')){
            current ++;
        }
        
        if(i == 3){
            tmp = malloc(current - Start + 1);
            tmp[current - Start] = '\0';
            for(int i = Start; i < current; i++){
                tmp[i-Start] = toSplit[i];
            }
            returnSong->Album = tmp;
        }

        if(i == 8){
            tmp = malloc(current - Start + 1);
            tmp[current - Start] = '\0';
            for(int i = Start; i < current; i++){
                tmp[i-Start] = toSplit[i];
            }
            returnSong->Artist = tmp;
        }

        if(i == 10){
            tmp = malloc(current - Start + 1);
            tmp[current - Start] = '\0';
            for(int i = Start; i < current; i++){
                tmp[i-Start] = toSplit[i];
            }
            returnSong->Durration = atof(tmp);
            free(tmp);
        }

        if(i == 14){
            tmp = malloc(current - Start + 1);
            tmp[current - Start] = '\0';
            for(int i = Start; i < current; i++){
                tmp[i-Start] = toSplit[i];
            }
            returnSong->Hotness = atof(tmp);
            free(tmp);
        }

        if(i==17){
            tmp = malloc(current - Start + 1);
            tmp[current - Start] = '\0';
            for(int i = Start; i < current; i++){
                tmp[i-Start] = toSplit[i];
            }
            returnSong->Name = tmp;
        }

        if(i==18){
            tmp = malloc(current - Start + 1);
            tmp[current - Start] = '\0';
            for(int i = Start; i < current; i++){
                tmp[i-Start] = toSplit[i];
            }
            returnSong->Year = atoi(tmp);
            free(tmp);
        }
        current+=1;
        Start = current;
    }
    tmp = NULL;
    return returnSong;
}
