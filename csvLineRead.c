#include <stdlib.h>
#include "song.h"
#include "csvLineRead.h"
int csvLineSpliter(char *toSplit, song* songs, songOffset* offsets, int position){
    int Start = 0;
    int current = 0;
    char *tmp;
    song tmpSong;
    songOffset tmpOffset;
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
            tmpSong.Album = tmp;
            tmpOffset.AlbumLength = current - Start + 1;
        }

        if(i == 8){
            tmp = malloc(current - Start + 1);
            tmp[current - Start] = '\0';
            for(int i = Start; i < current; i++){
                tmp[i-Start] = toSplit[i];
            }
            tmpSong.Artist = tmp;
            tmpOffset.ArtistLength = current - Start + 1;
        }

        if(i == 10){
            tmp = malloc(current - Start + 1);
            tmp[current - Start] = '\0';
            for(int i = Start; i < current; i++){
                tmp[i-Start] = toSplit[i];
            }
            tmpSong.Durration = atof(tmp);
            free(tmp);
        }

        if(i == 14){
            tmp = malloc(current - Start + 1);
            tmp[current - Start] = '\0';
            for(int i = Start; i < current; i++){
                tmp[i-Start] = toSplit[i];
            }
            tmpSong.Hotness = atof(tmp);
            free(tmp);
        }

        if(i==17){
            tmp = malloc(current - Start + 1);
            tmp[current - Start] = '\0';
            for(int i = Start; i < current; i++){
                tmp[i-Start] = toSplit[i];
            }
            tmpSong.Name = tmp;
            tmpOffset.NameLength = current - Start + 1;
            tmpOffset.songNameAddress = tmp;
        }

        if(i==18){
            tmp = malloc(current - Start + 1);
            tmp[current - Start] = '\0';
            for(int i = Start; i < current; i++){
                tmp[i-Start] = toSplit[i];
            }
            tmpSong.Year = atoi(tmp);
            free(tmp);
        }
        current+=1;
        Start = current;
    }
    tmp = NULL;
    offsets[position] = tmpOffset;
    songs[position] = tmpSong;
    return 0;
}
