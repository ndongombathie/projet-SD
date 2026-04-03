#include "graphe.h"
#include <stdlib.h>
#include <stdio.h>


Graphe * creer_graphe(int nb_sommets, int oriente) {
    int i=0;
    Graphe *g = (Graphe*)malloc(sizeof(Graphe)); //on alloue la memoire pour le graphe
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
        printf("%d -> ",i);
        AdjNoeud* p = g->listes[i];
        while(p != NULL) {
            printf("%d(%d)Km ",p->sommet,p->poids);
            p = p->suivant;
        }
        printf("\n");
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


void bfs(Graphe* g, int source) {
    // on initialise les tableaux de visité et de distance
    int* visite = (int*)malloc(g->nb_sommets*sizeof(int));
    int* distance = (int*)malloc(g->nb_sommets*sizeof(int));
    // on initialise les tableaux de visité et de distance a 0
    for(int i=0;i<g->nb_sommets;i++) {
        visite[i] = 0;
        distance[i] = 0;
    }
    // on met la distance de la source a 0
    distance[source] = 0;
    // on met la source a visite
    visite[source] = 1;
}