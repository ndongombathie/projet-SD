typedef struct adj_noeud {  //Structure des nœuds
    int sommet;
    int poids; /* 0 si graphe non pondéré */
    struct adj_noeud* suivant;
} AdjNoeud;


typedef struct {
    int nb_sommets;
    int nb_aretes;
    int oriente; /* 1 = orienté, 0 = non orienté */
    AdjNoeud** listes; /* tableau de listes d'adjacence */
} Graphe;


typedef struct {
    int nb_sommets;
    int oriente;
    int** matrice;
} GrapheMatrice;


typedef struct file{
    AdjNoeud* tete;
    AdjNoeud* queue;
} File;

typedef AdjNoeud* Pile;

void enfiler_noeud(File* f, AdjNoeud* n); //permet d'ajouter un élément à la file
void defiler_noeud(File* f); //permet de retirer un élément de la file
File * file_vide(); //permet d'initialiser une file vide
int est_file_vide(File* f); //permet de vérifier si la file est vide

void dfs_iteratif(Graphe* g, int source); //permet de faire un parcours en profondeur itératif du graphe à partir d'un sommet source
void empiler_noeud(Pile* p, AdjNoeud* n); //permet d'ajouter un élément à la pile
void depiler_noeud(Pile p); //permet de retirer un élément de la pile
Pile pile_vide(); //permet d'initialiser une pile vide
int est_pile_vide(Pile p); //permet de vérifier si la pile est vide


Graphe* creer_graphe(int nb_sommets, int oriente); //permet de créer un graphe

void ajouter_arete(Graphe* g, int u, int v, int poids); //permet d'ajouter une arete u->v (poids = 0)

AdjNoeud* creer_adj_noeud(int sommet, int poids); //permet de créer un nœud adjacence

void supprimer_arete(Graphe* g, int u, int v); //permet de supprimer une arete u

int arete_existe(Graphe* g, int u, int v); //permet de savoir si une arete u->v existe

void afficher_graphe(Graphe* g); //permet d'afficher le graphe

void liberer_graphe(Graphe* g); //permet de libérer la mémoire du graphe

GrapheMatrice* creer_graphe_matrice(int nb_sommets, int oriente); //permet de créer un graphe matrice

void ajouter_arete_mat(GrapheMatrice* g, int u, int v, int poids); //permet d'ajouter une arete u->v

int arete_existe_mat(GrapheMatrice* g, int u, int v); //permet de savoir si une arete u->v existe

void afficher_matrice(GrapheMatrice* g); //permet d'afficher la matrice de adjacence du graphe matrice

void liberer_graphe_mat(GrapheMatrice* g); //permet de libérer la mémoire du graphe matrice

void bfs(Graphe* g, int source);

