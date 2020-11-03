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

struct song_node *add_top(char *name, char *artist, struct song_node *songs)
{
    struct song_node *my_song = new_song(name, artist); 
    my_song->next = songs; 
    return my_song; 
}

struct song_node *add_order(char *name, char *artist, struct song_node *songs)
{
    struct song_node *dummy = new_song("", ""); 
    dummy->next = songs; 
    struct song_node *my_song = new_song(name, artist); 
    struct song_node *last = dummy; 
    while(songs)
    {
        int cmp = strcmp(my_song->artist, songs->artist); 
        int cmp2 = strcmp(my_song->name, songs->name); 
        if(cmp < 0 || (cmp == 0 && cmp2 <= 0))
        {
            last->next = my_song; 
            my_song->next = songs; 
            break; 
        }
        last = songs; 
        songs = songs->next; 
    }
    struct song_node *first = dummy->next; 
    free(dummy); 
    return first; 
}