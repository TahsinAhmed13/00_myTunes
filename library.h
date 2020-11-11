#include "list.h"

struct song_node **create_library(); 

void print_letter_library(struct song_node **, char); 

void print_artist_library(struct song_node **, char*); 

void print_library(struct song_node **); 

void print_shuffle(struct song_node **); 

struct song_node **add_to_library(struct song_node **, char *, char *); 

struct song_node *find_song_library(struct song_node **, char *, char *); 

struct song_node *find_artist_library(struct song_node **, char *); 

struct song_node *del_song_library(struct song_node **, char *, char *);

struct song_node **free_library(struct song_node **); 

