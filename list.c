#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "list.h"

void print_song(struct song_node *song)
{
    printf("[%s: %s] ", song->artist, song->name); 
}

void print_songs(struct song_node *songs)
{
    while(songs)
    {
        print_song(songs);  
        songs = songs->next; 
    }
    printf("\n"); 
}

struct song_node *new_song(char *artist, char *name)
{
    struct song_node *song = (struct song_node *) malloc(sizeof(struct song_node)); 
    strcpy(song->name, name); 
    strcpy(song->artist, artist); 
    return song; 
}

struct song_node *add_top(struct song_node *songs, char *artist, char *name)
{
    printf("Add to Top: [%s, %s]\n", artist, name); 
    struct song_node *my_song = new_song(artist, name); 
    my_song->next = songs; 
    return my_song; 
}

struct song_node *add_order(struct song_node *songs, char *artist, char *name)
{
    printf("Add in Order: [%s, %s]\n", artist, name); 
    struct song_node *my_song = new_song(artist, name); 
    struct song_node *dummy = new_song("", ""); 
    dummy->next = songs; 
    struct song_node *last = dummy; 

    while(songs)
    {
        int cmp = strcmp(artist, songs->artist); 
        int cmp2 = strcmp(name, songs->name); 
        if(cmp < 0 || (cmp == 0 && cmp2 <= 0))
            break; 
        last = songs; 
        songs = songs->next; 
    }
    last->next = my_song; 
    my_song->next = songs; 

    songs = dummy->next; 
    free(dummy); 
    return songs; 
}

struct song_node *find_song(struct song_node *songs, char *artist, char *name)
{
    printf("Finding Song: [%s, %s]\n", artist, name); 
    while(songs)
    {
        if(!strcmp(artist, songs->artist) && !strcmp(name, songs->name))
        {
            printf("\tsong found! "); 
            return songs;
        }
        songs = songs->next; 
    }
    printf("\tsong not found:( "); 
    return NULL;   
} 

struct song_node *find_artist(struct song_node *songs, char *artist) 
{
    printf("Finding Artist: %s\n", artist); 
    while(songs)
    {
        if(!strcmp(artist, songs->artist)) 
        {
            printf("\tartist found! "); 
            return songs; 
        }
        songs = songs->next; 
    }
    printf("\tartist not found:( "); 
    return NULL; 
} 

int length(struct song_node *songs)
{  
    int i = 0; 
    while(songs)
    {
        ++i; 
        songs = songs->next; 
    }
    return i; 
}

struct song_node *rand_song(struct song_node *songs)
{
    int n = rand() % length(songs); 
    for(int i = 0; i < n; ++i)
        songs = songs->next; 
    return songs; 
}

struct song_node *remove_song(struct song_node *songs, char *artist, char *name)
{
    printf("Removing Song: [%s, %s]\n", artist, name); 
    struct song_node *dummy = new_song("", ""); 
    dummy->next = songs; 
    struct song_node *last = dummy; 
    while(songs)
    {
        if(!strcmp(artist, songs->artist) && !strcmp(name, songs->name))
        {
            last->next = songs->next; 
            free(songs); 
            break; 
        }
        last = songs; 
        songs = songs->next; 
    }
    songs = dummy->next; 
    free(dummy); 
    return songs; 
}

struct song_node *free_songs(struct song_node *songs)
{
    struct song_node *nxt = songs;
    while(songs)
    {
        nxt = songs->next;
        printf("Freeing Node: [%s, %s]\n", songs->artist, songs->name); 
        free(songs);
        songs = nxt;
    }   
    return NULL; 
}
