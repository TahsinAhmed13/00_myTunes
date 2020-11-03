#include <stdlib.h>
#include <stdio.h>

#include "list.h"

void print_song(struct song_node *song)
{
    printf("%s: %s\n", song->artist, song->name); 
}

void print_songs(struct song_node *songs)
{
    while(songs)
    {
        print_song(songs); 
        songs = songs->next; 
    }
}

struct song_node *free_songs(struct song_node *songs)
{
    struct song_node *nxt = songs;
    while(songs){
        nxt = songs->next;
        free(songs);
        songs = nxt;
    }   
    return NULL; 
}

struct song_node *new_song(char *name, char *artist)
{
    struct song_node *song = (struct song_node *) malloc(sizeof(struct song_node)); 
    strcpy(song->name, name); 
    strcpy(song->artist, artist); 
    return song; 
}