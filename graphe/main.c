#include "graphe.h"
#include <stdio.h>


int main()
{
    Graphe *g = creer_graphe(3,1);
    ajouter_arete(g,0,1,1200);
    ajouter_arete(g,0,2,1200);
    ajouter_arete(g,1,2,1200);
    ajouter_arete(g,2,0,1200);
    afficher_graphe(g);
    liberer_graphe(g);
    return 0;
}
