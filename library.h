#include "list.h"

struct song_node **create_library(); 

struct song_node **add_to_library(struct song_node **, char *, char *); 

struct song_node *find_song_library(struct song_node **, char *, char *); 
struct song_node *find_artist_library(struct song_node **, char *); 

struct song_node **free_library(struct song_node **); 