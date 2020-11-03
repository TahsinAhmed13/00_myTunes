struct song_node
{
    char name[80]; 
    char artist[80];
    struct song_node *next; 
};

void print_song(struct song_node *);
void print_songs(struct song_node *);

struct song_node *free_songs(struct song_node *); 

struct song_node *add_top(struct song_node *); 