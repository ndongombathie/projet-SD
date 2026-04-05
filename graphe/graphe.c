#include "graphe.h"
#include <stdlib.h>
#include <stdio.h>


Graphe * creer_graphe(int nb_sommets, int oriente) {
    int i=0;
    Graphe *g = (Graphe*)malloc(sizeof(Graphe)); //on alloue la memoire pour le graphe
    if(g == NULL) {
        printf("Erreur d'allocation de memoire pour le graphe\n");
        exit(-1);
    }
    g->nb_sommets = nb_sommets;
    g->nb_aretes = 0;
    g->oriente = oriente; /* 1 = orienté, 0 = non orienté */
    g->listes = (AdjNoeud**)malloc(nb_sommets*sizeof(AdjNoeud*)); //on alloue la memoire pour les listes d'adjacence
    for(;i<nb_sommets;i++) {
        g->listes[i] = NULL; //on initialise les listes a NULL
    }

    return g;
}

AdjNoeud* creer_adj_noeud(int sommet, int poids) {
    AdjNoeud* n = (AdjNoeud*)malloc(sizeof(AdjNoeud));
    if(n == NULL) {
        printf("Erreur d'allocation de memoire pour le nœud d'adjacence\n");
        exit(-1);
    }
    n->sommet = sommet;
    n->poids = poids;
    n->suivant = NULL;
    return n;
}



void ajouter_arete(Graphe* g, int u, int v, int poids) {
    AdjNoeud* n = creer_adj_noeud(v,poids);
    //si le graphe est orienté on ajoute la arete u->v
    if(g->oriente) {
        //si u n'a pas de voisin on ajoute n a la liste de voisin de u
        if(g->listes[u] == NULL) {
            g->listes[u] = n;
        }
        else {
            AdjNoeud* p = g->listes[u];
            while(p->suivant != NULL) {
                p = p->suivant;
            }
            p->suivant = n;
        }
    }

    //si le graphe est non orienté on ajoute la arete u->v et la arete v->u
    else {
        AdjNoeud* n1 = creer_adj_noeud(u,poids);
        //si u n'a pas de voisin on ajoute n a la liste de voisin de u
        if(g->listes[u] == NULL) {
            g->listes[u] = n;
        }
        else {
            AdjNoeud* p = g->listes[u];
            while(p->suivant != NULL) {
                p = p->suivant;
            }
            p->suivant = n;
        }

        //on ajoute la arete v->u
        //si v n'a pas de voisin on ajoute n a la liste de voisin de v
        if(g->listes[v] == NULL) {
            g->listes[v] = n1;
        }
        else {
            AdjNoeud* p = g->listes[v];
            while(p->suivant != NULL) {
                p = p->suivant;
            }
            p->suivant = n1;
        }
    }
    g->nb_aretes++;
}

void supprimer_arete(Graphe* g, int u, int v) {
    AdjNoeud* p = g->listes[u]; 
    AdjNoeud* p1 = g->listes[u];

    while(p != NULL) {
        if(p->sommet != v) {
            p1 = p; // on stocke le arete actuel dans p1
            p = p->suivant; // on passe au suivant
        }else {
            p1->suivant = p->suivant; // on supprime le arete p
            free(p); // on libere la memoire du arete p
            g->nb_aretes--; // on decremente le nombre de aretes
            return;
        }
    }
}

int arete_existe(Graphe* g, int u, int v) {
    AdjNoeud* p = g->listes[u]; // recupere la liste de voisin de u
    // on parcourt la liste de voisin de u
    while(p != NULL) {
        if(p->sommet == v) {
            return 1;
        }
        p = p->suivant;
    }
    return 0;
}

void afficher_graphe(Graphe* g) {
    int i=0;
    for(;i<g->nb_sommets;i++) {
        if(g->listes[i] != NULL) {
            printf("%d -> ",i);
            AdjNoeud* p = g->listes[i];
            while(p != NULL) {
                printf("%d(%d) ",p->sommet,p->poids);
                p = p->suivant;
            }
            printf("\n");
        }
        
    }
}


void liberer_graphe(Graphe* g) {
    int i=0;
    for(;i<g->nb_sommets;i++) {
        AdjNoeud* p = g->listes[i];
        while(p != NULL) {
            AdjNoeud* p1 = p;
            p = p->suivant;
            free(p1);
        }
    }
    free(g->listes);
    free(g);
}

GrapheMatrice* creer_graphe_matrice(int nb_sommets, int oriente) {
    int i=0;
    GrapheMatrice* g = (GrapheMatrice*)malloc(sizeof(GrapheMatrice));
    if(g == NULL) {
        printf("Erreur d'allocation de memoire pour le graphe matrice\n");
        exit(-1);
    }
    g->nb_sommets = nb_sommets;
    g->oriente = oriente;
    g->matrice = (int**)malloc(nb_sommets*sizeof(int*));
    for(;i<nb_sommets;i++) {
        g->matrice[i] = (int*)malloc(nb_sommets*sizeof(int));
    }
    return g;
}

void ajouter_arete_mat(GrapheMatrice* g, int u, int v, int poids) {
    if(g->oriente) {
        g->matrice[u][v] = poids;
    }
    else {
        g->matrice[v][u] = poids;
        g->matrice[u][v] = poids;
    }
}

int arete_existe_mat(GrapheMatrice* g, int u, int v) {
    return g->matrice[u][v] != 0;
}

void  afficher_graphe_matrice(GrapheMatrice* g) {
    int i=0;
    for(;i<g->nb_sommets;i++) {
        printf("%d -> ",i);
        for(int j=0;j<g->nb_sommets;j++) {
            printf("%d(%d)",j,g->matrice[i][j]);
        }
        printf("\n");
    }
}

void libere_graphe_mat(GrapheMatrice *g){
    int i=0;
    for(;i<g->nb_sommets;i++){
        free(g->matrice[i]);
    }
    free(g->matrice); // on libere la memoire de la matrice
    free(g); // on libere le graphe de la memoire
}


int est_file_vide(File* f) {
    return f->tete == NULL && f->queue == NULL;
}

File * file_vide() {
    File* f = (File*)malloc(sizeof(File));
    if(f == NULL) {
        printf("Erreur d'allocation de memoire pour la file\n");
        exit(-1);
    }
    f->tete = NULL;
    f->queue = NULL;
    return f;
}

void enfiler_noeud(File* f, AdjNoeud* n) {
    if(est_file_vide(f)) {
        f->tete = n;
        f->queue = n;
    }
    else {
        f->queue->suivant = n;
        f->queue = n;
    }
}

void defiler_noeud(File* f) {
    if (est_file_vide(f)) {
        printf("La file est vide\n");
        return;
    }
    AdjNoeud* p = f->tete;
    f->tete = f->tete->suivant;

    if (f->tete==NULL) {
        f->queue = NULL;
    }
    free(p);
}


void bfs(Graphe* g, int source) {
    // on initialise les tableaux de visité et de distance
    int* noeud_visite = (int*)calloc((g->nb_sommets),sizeof(int)); // on initialise le tableau de visite a 0
    if(noeud_visite == NULL) {
        printf("Erreur d'allocation de memoire pour les tableaux de visité distance\n");
        exit(-1);
    }
    // on initialise la file
    File* f = file_vide();
    // on ajoute le sommet source a la file
    AdjNoeud* n = creer_adj_noeud(source,0);
    enfiler_noeud(f,n);

    printf("Ordre de visite des sommets du parcours bfs :\n");
    printf("Sommet %d (poids : %d)\n",source,0);
    noeud_visite[source] = 1; // on marque le sommet source comme visité
    while(!est_file_vide(f)){
        AdjNoeud* p = f->tete; // on recupere le sommet en tête de la file
        int u = p->sommet; // on recupere le sommet u
        AdjNoeud* adj = g->listes[u]; // on recupere la liste d'adjacence de u
        while(adj != NULL) {
            int v = adj->sommet; // on recupere le sommet v
            if(!noeud_visite[v]) { // si v n'est pas visité
                //ordre de visite des sommets 
                printf("Sommet %d (poids : %d)\n",v,adj->poids); 
                noeud_visite[v] = 1; // on marque v comme visité
                enfiler_noeud(f,creer_adj_noeud(adj->sommet, adj->poids)); // on ajoute v a la file
            }
            adj = adj->suivant; // on passe au suivant dans la liste d'adjacence de u
        }
       defiler_noeud(f); // on retire le sommet en tête de la file
    }
    free(noeud_visite); // on libere la memoire du tableau de visite
    free(f); // on libere la memoire de la file
    printf("\n");
}


//void dfs(Graphe* g, int source) en version récursive
void dfs_recursive(Graphe* g, int u, int* visite) {
    printf("Sommet %d\n", u);
    visite[u] = 1;
    for(AdjNoeud* adj = g->listes[u]; adj != NULL; adj = adj->suivant) {
        int v = adj->sommet; // on recupere le sommet v
        if(!visite[v]) { // si v n'est pas visité
            dfs_recursive(g, v, visite); // on continue le parcours en profondeur a partir du sommet v
        }
    }
}

void dfs(Graphe* g, int source) {
    int* noeud_visite = (int*)calloc(g->nb_sommets, sizeof(int)); // on initialise le tableau de visite a 0
    if(noeud_visite == NULL) {
        printf("Erreur d'allocation de memoire pour les tableaux de visité distance\n");
        exit(-1);
    }

    printf("Ordre de visite des sommets du parcours dfs en mode récursive :\n");
    dfs_recursive(g, source, noeud_visite); // on commence le parcours en profondeur a partir du sommet source
    free(noeud_visite);// on libere la memoire du tableau de visite
    printf("\n");
}


int est_pile_vide(Pile p) {
    return p == NULL;
}

void empiler_noeud(Pile* p, AdjNoeud* n) {
    if(est_pile_vide(*p)) {
        *p = n;
    }
    else {
        n->suivant = *p;
        *p = n;
    }
}


void depiler_noeud(Pile *p) {

    if (est_pile_vide(*p)) {
        printf("La pile est vide\n");
        return;
    }

    AdjNoeud* pt = *p; // on recupere le sommet en tête de la pile
      *p = pt->suivant;
    free(pt);
}

Pile pile_vide() {
    return NULL;
}



void dfs_iteratif(Graphe* g, int source) {
    // on initialise les tableaux de visité et de distance
    int* noeud_visite = (int*)calloc((g->nb_sommets),sizeof(int)); // on initialise le tableau de visite a 0
    if(noeud_visite == NULL) {
        printf("Erreur d'allocation de memoire pour les tableaux de visité distance\n");
        exit(-1);
    }
    // on initialise la pile
    Pile p = pile_vide();
    // on ajoute le sommet source a la pile
    AdjNoeud* n = creer_adj_noeud(source,0);
    noeud_visite[source] = 1; // on marque le sommet source comme visité
    empiler_noeud(&p,n);
    printf("Ordre de visite des sommets du parcours dfs en mode itératif :\n");
    printf("Sommet %d (poids : %d)\n",source,0);
    noeud_visite[source] = 1; // on marque le sommet source comme visité
    while(!est_pile_vide(p)){
        AdjNoeud* noeud = p; // on recupere le sommet en tête de la pile
        int u = noeud->sommet; // on recupere le sommet u
        AdjNoeud* adj = g->listes[u]; // on recupere la liste d'adjacence de u
        while(adj != NULL) {
            int v = adj->sommet; // on recupere le sommet v
            if(!noeud_visite[v]) { // si v n'est pas visité
                //ordre de visite des sommets 
                printf("Sommet %d (poids : %d)\n",v,adj->poids); 
                noeud_visite[v] = 1; // on marque v comme visité
                empiler_noeud(&p,creer_adj_noeud(adj->sommet, adj->poids)); // on ajoute v a la pile
                adj = g->listes[v]; // on passe a la liste d'adjacence de v pour continuer le parcours en profondeur
            }else{
                adj = adj->suivant; // on passe au suivant dans la liste d'adjacence de u
                printf("Retour en arrière vers le sommet %d\n",v); // on affiche le retour en arrière
                depiler_noeud(&p); // on retire le sommet en tête de la pile
            }
        }
        depiler_noeud(&p); // on retire le sommet en tête de la pile
    }
    free(noeud_visite); // on libere la memoire du tableau de visite    
    printf("\n");
} 

// Parcours en profondeur complet du graphe non convexe
void dfs_complet(Graphe* g) {
    int* noeud_visite = (int*)calloc(g->nb_sommets, sizeof(int));
    if(noeud_visite == NULL) {
        printf("Erreur d'allocation de memoire pour les tableaux de visité distance\n");
        exit(-1);
    }

    printf("Ordre de visite des sommets du parcours dfs en mode récursive complet :\n");
    for(int i = 0; i < g->nb_sommets; i++) {
        if(!noeud_visite[i]) {
            dfs_recursive(g, i, noeud_visite);
        }
    }
    free(noeud_visite);
    printf("\n");
}
