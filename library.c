#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "library.h"

struct song_node **create_library()
{
    struct song_node **lib = (struct song_node **) calloc(27, sizeof(struct song_node *)); 
    return lib; 
}

int get_index(char *artist)
{
    char initial = artist[0]; 
    if('a' <= initial && initial <= 'z')
        return initial - 'a' + 1; 
    return 0; 
    return initial - 'a'; 
}

char get_initial(int i)
{
    if(1 <= i && i <= 26)
        return i + 'a' - 1; 
    return '0'; 
}

void print_letter_library(struct song_node **lib, char c) 
{
    printf("printing songs in '%c' list\n\t", c);
    print_songs(lib[get_index(&c)]);
}

void print_artist_library(struct song_node **lib, char *artist)
{
    struct song_node *s = lib[get_index(artist)]; 
    printf("printing songs with artist '%s'\n\t", artist);
    while(s)
    {
        if(!strcmp(s->artist, artist)){
            print_song(s);  
        }
        
        s = s->next; 
    }
}

void print_library(struct song_node **lib)
{
    for(int i = 1; i < 27; i++)
        if(lib[i])
        {
            printf("printing songs in '%c' list\n\t", get_initial(i));
            print_songs(lib[i]);
        }
}

struct song_node **add_to_library(struct song_node **lib, char *artist, char *name)
{
    int i = get_index(artist); 
    printf("adding [%s, %s] to '%c' list\n\t", artist, name, get_initial(i));  
    lib[i] = add_order(lib[i], artist, name); 
    return lib; 
}

struct song_node *find_song_library(struct song_node **lib, char *artist, char *name)
{
    int i = get_index(artist); 
    printf("finding [%s, %s] in '%c' list\n\t", artist, name, get_initial(i));  
    return find_song(lib[i], artist, name); 
}

struct song_node *find_artist_library(struct song_node **lib, char *artist)
{
    int i = get_index(artist); 
    printf("finding artist %s in '%c' list\n\t", artist, get_initial(i));   
    return find_artist(lib[i], artist); 
}

struct song_node *del_song_library(struct song_node **lib, char *artist, char *name){
    remove_song(lib[get_index(artist)], artist, name);
}

struct song_node **free_library(struct song_node **lib)
{
    for(int i = 0; i < 27; ++i)
        if(lib[i])
        {
            printf("freeing %c list\n", get_initial(i)); 
            free_songs(lib[i]); 
        }
    free(lib); 
    return NULL; 
}
