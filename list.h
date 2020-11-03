struct song_node
{
    char name[80]; 
    char artist[80];
    struct song_node *next; 
};

void print_songs(struct song_node *);

struct song_node *free_songs(struct song_node *); 

struct song_node *add_top(char *, char *, struct song_node *); 
struct song_node *add_order(char *, char *, struct song_node *); 