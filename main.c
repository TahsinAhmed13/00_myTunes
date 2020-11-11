#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#include "library.h"

int main()
{
    srand(time(NULL)); 
    printf("LINKED LIST\n"); 
    struct song_node *songs = NULL; 
    printf("\n===============\n\n"); 

    printf("Testing add_order:\n"); 
    songs = add_order(songs, "queen", "bohemain rhapsody"); 
    songs = add_order(songs, "led zeppelin", "kashmir"); 
    songs = add_order(songs, "lamb of god", "redneck"); 
    songs = add_order(songs, "guns n' roses", "november rain"); 
    songs = add_order(songs, "led zeppelin", "stairway to heaven"); 
    songs = add_order(songs, "david bowie", "life on mars?"); 
    printf("\n===============\n\n"); 

    printf("Testing add_top:\n"); 
    songs = add_top(songs, "ac/dc", "highway to hell"); 
    songs = add_top(songs, "metallica", "enter sandman"); 
    songs = add_top(songs, "black sabbath", "war pigs"); 
    printf("\n===============\n\n"); 

    printf("Testing print_songs:\n"); 
    print_songs(songs); 
    printf("\n===============\n\n"); 

    struct song_node *index; 
    printf("Testing find_song:\n"); 
    index = find_song(songs, "queen", "bohemain rhapsody"); 
    print_song(index); 
    printf("\n"); 
    index = find_song(songs, "led zeppelin", "kashmir"); 
    print_song(index); 
    printf("\n"); 
    index = find_song(songs, "led zeppelin", "immigrant song"); 
    printf("\n"); 
    printf("\n===============\n\n"); 

    printf("Testing find_artist:\n"); 
    index = find_artist(songs, "led zeppelin"); 
    print_song(index); 
    printf("\n"); 
    index = find_artist(songs, "guns n' roses"); 
    print_song(index); 
    printf("\n"); 
    index = find_artist(songs, "foo fighters"); 
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
    songs = remove_song(songs, "ac/dc", "highway to hell"); 
    printf("\t"); 
    print_songs(songs); 
    songs = remove_song(songs, "black sabbath", "war pigs"); 
    printf("\t"); 
    print_songs(songs); 
    songs = remove_song(songs, "led zeppelin", "kashmir"); 
    printf("\t"); 
    print_songs(songs); 
    printf("\n===============\n\n"); 

    printf("Testing free_songs:\n"); 
    free_songs(songs); 
    printf("\n===============\n\n"); 

    printf("MUSIC LIBRARY TEST\n"); 
    struct song_node **lib = create_library(); 
    printf("\n===============\n\n"); 

    printf("Testing add_to_lib:\n"); 
    lib = add_to_library(lib, "queen", "bohemain rhapsody"); 
    lib = add_to_library(lib, "led zeppelin", "kashmir"); 
    lib = add_to_library(lib, "lamb of god", "redneck"); 
    lib = add_to_library(lib, "guns n' roses", "november rain"); 
    lib = add_to_library(lib, "led zeppelin", "stairway to heaven");
    lib = add_to_library(lib, "linkin park", "numb"); 
    lib = add_to_library(lib, "david bowie", "life on mars?"); 
    printf("\n===============\n\n"); 

    printf("Testing print_library:\n"); 
    print_library(lib); 
    printf("\n===============\n\n"); 

    printf("Testing print_letter_library:\n"); 
    print_letter_library(lib, 'l'); 
    printf("\n===============\n\n"); 

    printf("Testing print_artist_library:\n"); 
    print_artist_library(lib, "led zeppelin"); 
    printf("\n===============\n\n"); 

    printf("Testing print_shuffle:\n"); 
    print_shuffle(lib); 
    printf("\n===============\n\n"); 

    printf("Testing find_song_library:\n"); 
    index = find_song_library(lib, "queen", "bohemain rhapsody"); 
    printf("\t"); 
    print_song(index); 
    printf("\n"); 
    index = find_song_library(lib, "led zeppelin", "kashmir"); 
    printf("\t"); 
    print_song(index); 
    printf("\n"); 
    index = find_song_library(lib, "led zeppelin", "immigrant song"); 
    printf("\n");  
    printf("\n===============\n\n"); 

    printf("Testing find_artist_library:\n"); 
    index = find_artist_library(lib, "led zeppelin"); 
    printf("\t"); 
    print_song(index); 
    printf("\n"); 
    printf("\n===============\n\n"); 

    printf("Testing del_song_library:\n"); 
    printf("\t"); 
    del_song_library(lib, "led zeppelin", "kashmir"); 
    printf("\n"); 
    printf("\n===============\n\n"); 

    printf("Testing free_library:\n"); 
    free_library(lib); 
    printf("\n===============\n\n"); 

    return 0; 
}