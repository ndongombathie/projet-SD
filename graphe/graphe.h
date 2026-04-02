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

