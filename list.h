struct song_node
{
    char name[80]; 
    char artist[80];
    struct song_node *next; 
};

void print_song(struct song_node *); 
void print_songs(struct song_node *);

int length(struct song_node *);

struct song_node *new_song(char *, char *); 

struct song_node *add_top(struct song_node *, char *, char *); 
struct song_node *add_order(struct song_node *, char *, char *); 

struct song_node *find_song(struct song_node *, char *, char *); 
struct song_node *find_artist(struct song_node *, char *); 
struct song_node *rand_song(struct song_node *); 

struct song_node *remove_song(struct song_node *, char *, char *); 
struct song_node *free_songs(struct song_node *); 
