#include "sort.h"
#include <stdlib.h>
#include <string.h>
int quickSort(song *toSort, songOffset *offsets, int start, int end){
    if(end <= start){
        return 0;
    }
    song pivot;
    song tmpSong;
    songOffset tmpOffset;
    if(end == start +1){
        if(strcmp(toSort[start].Name,toSort[end].Name)>0){
            tmpOffset = offsets[start];
            tmpSong =  toSort[start];
            toSort[start] = toSort[end];
            toSort[end] = tmpSong;
            offsets[start] = offsets[end];
            offsets[end] = tmpOffset;
        }
        return 0;
    }
    pivot = toSort[(start + end)/2];
    tmpOffset = offsets[(start + end)/2];
    int low = start + 1;
    int high = end-1;
    toSort[(start + end)/2] = toSort[start];
    toSort[start] = pivot;
    offsets[(start + end)/2] = offsets[start];
    offsets[start] = tmpOffset;
    
    

    while(low<high){
        while(strcmp(toSort[high].Name,pivot.Name)>=0 && low<high){
            high--;
        }
        while(strcmp(toSort[low].Name,pivot.Name)<0 && low<high){
            low++;
        }
        tmpOffset = offsets[low];
        offsets[low] = offsets[high];
        offsets[high] = tmpOffset;
        tmpSong = toSort[low];
        toSort[low] = toSort[high];
        toSort[high] = tmpSong;
    }

    if(strcmp(toSort[start].Name,toSort[low].Name)>0){
        tmpOffset = offsets[start];
        offsets[start] = offsets[low];
        offsets[low] = tmpOffset;
        toSort[start] = toSort[low];
        toSort[low] = pivot;
    }
    return quickSort(toSort,offsets,start,low) + quickSort(toSort,offsets,low+1,end);
}

int sort(song *toSort, songOffset* offsets, int length){
    return quickSort(toSort, offsets , 0,length);
}
