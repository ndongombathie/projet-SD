#include "noeud.h"
#include <stdio.h>


int main()
{
    Arbre a = creer_arbre(10,creer_noeud(5),creer_noeud(15)); //on cree un arbre avec les noeuds 10, 5 et 15
    a=inserer_gauche(a,5,3); //on insere un nouveau noeud a la gauche de 5 avec la valeur 3
    a=inserer_droite(a,5,7);  //on insere un nouveau noeud a la droite de 5 avec la valeur 7
    a=inserer_gauche(a,15,12); //on insere un nouveau noeud a la gauche de 15 avec la valeur 12
    a=inserer_droite(a,15,20);  //on insere un nouveau noeud a la droite de 15 avec la valeur 20
    parcours_prefixe(a); //on parcourt l'arbre en prefixe
    printf("\n");
    parcours_infixe(a); //on parcourt l'arbre en infixe
    printf("\n");
    parcours_postfixe(a); //on parcourt l'arbre en postfixe
    printf("\n");
    afficher_arbre(a,0); //on affiche l'arbre
    si_est_dans_arbre(a,7);  //on verifie si 7 est dans l'arbre
    si_est_dans_arbre(a,12);  //on verifie si 12 est dans l'arbre
    si_est_dans_arbre(a,25);  //on verifie si 25 est dans l'arbre
    return 0;
}