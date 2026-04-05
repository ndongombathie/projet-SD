#include "graphe.h"
#include <stdio.h>


int main()
{   
    Graphe *g = creer_graphe(6,1); //graphe oriente=1, Somommets : 0=Dakar 1=Thiès 2=Mbour 3=Kaolack 4=Touba 5=Saint-Louis
    ajouter_arete(g,0,1,70);   //on ajoute une arete entre Dakar et Thies avec un poids de 70
    ajouter_arete(g,0,2,85);   //on ajoute une arete entre Dakar et Mbour avec un poids de 85
    ajouter_arete(g,1,4,120);  //on ajoute une arete entre Thies et Touba avec un poids de 120
    ajouter_arete(g,1,3,180);  //on ajoute une arete entre Thies et Kaolack avec un poids de 180
    ajouter_arete(g,2,3,100);  //on ajoute une arete entre Mbour et Kaolack avec un poids de 100
    ajouter_arete(g,3,5,300);  //on ajoute une arete entre Kaolack et Saint-Louis avec un poids de 300
    ajouter_arete(g,4,5,200); //on ajoute une arete entre Touba et Saint-Louis avec un poids de 200
    printf("Graphe :\n");
    afficher_graphe(g);   //on affiche le graphe
    printf("\n");
    bfs(g,0);  //on fait un parcours en largeur du graphe à partir du sommet 0 (Dakar)
    printf("\n");
    dfs_iteratif(g,0); //on fait un parcours en profondeur itératif du graphe à partir du sommet 0 (Dakar)
    printf("\n");
    dfs(g,0); //on fait un parcours en profondeur récursive du graphe à partir du sommet 0 (Dakar)
    liberer_graphe(g); // mémoire allou mémoire allouée pour le graphe
    return 0;
}