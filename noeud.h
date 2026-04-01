typedef struct noeud
{
    int valeur; //valeur du noeud
    struct noeud *gauche; //pointeur vers le noeud gauche (sous-arbre ou fils  gauche)
    struct noeud *droite;  //pointeur vers le noeud droite (sous-arbre ou fils  droite)
} Noeud;

typedef Noeud *Arbre; // pointeur vers un arbre(ou un noeud)

typedef enum {FAUX,VRAIE} Boolean; // type boolean FAUX=0, VRAIE=1

Noeud* creer_noeud(int valeur); // creer un nouveau noeud avec la valeur donnee

Boolean est_vide(Arbre a); // verifie si un arbre est vide

Arbre creer_arbre(int racine, Arbre gauche, Arbre droit); // creer un arbre avec la racine donnee et les sous-arbres gauche et droit

void parcours_prefixe(Arbre a); // parcours prefixe d'un arbre:arbre gauche -> arbre droite -> racine

void parcours_infixe(Arbre a); // parcours infixe d'un arbre:arbre gauche -> racine -> arbre droite

void parcours_postfixe(Arbre a); // parcours postfixe d'un arbre:arbre gauche -> arbre droite -> racine

int hauteur(Arbre a); // calcule la hauteur d'un arbre

int taille(Arbre a); // calcule la taille d'un arbre

int somme(Arbre a); // calcule la somme des valeurs des noeuds d'un arbre

Boolean rechercher(Arbre a, int x); // recherche une valeur dans un arbre

void si_est_dans_arbre(Arbre a, int x); // verifie si une valeur est dans un arbre

Arbre trouver_noeud(Arbre a, int x); // trouver un noeud dans un arbre

Arbre inserer_gauche(Arbre a, int parent, int valeur); // inserer un nouveau noeud a la gauche d'un arbre

Arbre inserer_droite(Arbre a, int parent, int valeur); // inserer un nouveau noeud a la droite d'un arbre

void afficher_arbre(Arbre a, int niveau); // afficher un arbre 