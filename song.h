#ifndef SONG_STRUCT
#define SONG_STRUCT
typedef struct{
    char* Artist;
    char* Name;
    char* Album;
    float Durration;
    int Year;
    double Hotness;
} song;

typedef struct{
    char *songNameAddress;
    int NameLength;
    int AlbumLength;
    int ArtistLength;
} songOffset;
#endif