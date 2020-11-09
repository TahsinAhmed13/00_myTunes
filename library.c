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

struct song_node **free_library(struct song_node **lib)
{
    for(int i = 0; i < 27; ++i)
    {
        printf("freeing %c list\n", get_initial(i)); 
        free_songs(lib[i]); 
    }
    free(lib); 
    return NULL; 
}

void print_letter_library(struct song_node **lib, char c) 
{
    char fake[1];
    fake[0] = c; 
    printf("printing songs in '%c' list\n\t", c);
    print_songs(lib[get_index(fake)]);
}

void print_artist_library(struct song_node **lib, char *artist)
{
    struct song_node *s = lib[get_index(artist)]; 
    printf("printing songs with artist '%s'\n\t", artist);
    while(s && !strcmp(s->artist, artist))
    {
        print_song(s);  
        s = s->next; 
    }
}

void print_library(struct song_node **lib)
{
    int i;
    printf("printing songs in other symbols list\n\t");
        print_songs(lib[0]);
    for(i = 1; i < 27; i++)
    {
        printf("printing songs in '%c' list\n\t", 'a' + i - 1);
        print_songs(lib[i]);
    }
}

