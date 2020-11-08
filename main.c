#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#include "list.h"

int main()
{
    srand(time(NULL)); 
    struct song_node *songs = NULL; 

    printf("Testing add_order:\n"); 
    songs = add_order(songs, "Queen", "Bohemain Rhapsody"); 
    songs = add_order(songs, "Led Zeppelin", "Kashmir"); 
    songs = add_order(songs, "Guns N' Roses", "November Rain"); 
    songs = add_order(songs, "Led Zeppelin", "Stairway to Heaven"); 
    songs = add_order(songs, "David Bowie", "Life On Mars?"); 
    printf("\n===============\n\n"); 

    printf("Testing add_top:\n"); 
    songs = add_top(songs, "ac/dc", "Highway to Hell"); 
    songs = add_top(songs, "Metellica", "Enter Sandman"); 
    songs = add_top(songs, "Black Sabbath", "War Pigs"); 
    printf("\n===============\n\n"); 

    printf("Testing print_songs:\n"); 
    print_songs(songs); 
    printf("\n===============\n\n"); 

    struct song_node *index; 
    printf("Testing find_song:\n"); 
    index = find_song(songs, "Queen", "Bohemain Rhapsody"); 
    print_song(index); 
    printf("\n"); 
    index = find_song(songs, "Led Zeppelin", "Kashmir"); 
    print_song(index); 
    printf("\n"); 
    index = find_song(songs, "Led Zeppelin", "Immigrant Song"); 
    printf("\n"); 
    printf("\n===============\n\n"); 

    printf("Testing find_artist:\n"); 
    index = find_artist(songs, "Led Zeppelin"); 
    print_song(index); 
    printf("\n"); 
    index = find_artist(songs, "Guns N' Roses"); 
    print_song(index); 
    printf("\n"); 
    index = find_artist(songs, "Foo Fighters"); 
    printf("\n"); 
    printf("\n===============\n\n"); 

    printf("Testing rand_song:\n"); 
    for(int i = 0; i < 4; ++i)
    {
        index = rand_song(songs); 
        print_song(index);    
        printf("\n"); 
    }
    printf("\n===============\n\n"); 

    printf("Testing remove_song:\n"); 
    songs = remove_song(songs, "ac/dc", "Highway to Hell"); 
    printf("\t"); 
    print_songs(songs); 
    songs = remove_song(songs, "Black Sabbath", "War Pigs"); 
    printf("\t"); 
    print_songs(songs); 
    songs = remove_song(songs, "Led Zeppelin", "Kashmir"); 
    printf("\t"); 
    print_songs(songs); 
    printf("\n===============\n\n"); 

    printf("Testing free_songs:\n"); 
    free_songs(songs); 
    printf("\n===============\n\n"); 

    return 0; 
}