typedef struct noeud
{
    int valeur;
    struct noeud *gauche;
    struct noeud *droite;
} Noeud;

typedef Noeud *Arbre;

typedef enum {FAUX,VRAIE} Boolean;

//expliquer le rôle de chaque champ
//valeur: valeur du noeud
//gauche: pointeur vers le noeud gauche
//droite: pointeur vers le noeud droite

Noeud* creer_noeud(int valeur);

Boolean est_vide(Arbre a);

Arbre creer_arbre(int racine, Arbre gauche, Arbre droit);

void parcours_prefixe(Arbre a);

void parcours_infixe(Arbre a);

void parcours_postfixe(Arbre a);

int hauteur(Arbre a);

int taille(Arbre a);

int somme(Arbre a);

Boolean rechercher(Arbre a, int x);
