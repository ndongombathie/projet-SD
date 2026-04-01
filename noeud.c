#include "noeud.h"
#include <stdlib.h>
#include <stdio.h>

Noeud* creer_noeud(int valeur){
    Noeud* n = (Noeud*) malloc(sizeof(Noeud)); //on alloue la memoire pour le noeud
    n->gauche=NULL; //on initialise le pointeur vers le noeud gauche a NULL
    n->droite=NULL;  //on initialise le pointeur vers le noeud droite a NULL
    n->valeur=valeur; //on initialise la valeur du noeud a la valeur passee en parametre
    return n; //on retourne le pointeur vers le noeud
}

Boolean est_vide(Arbre a){
    if(a==NULL) //si le pointeur vers le noeud est NULL, on retourne VRAIE
      return VRAIE; //0 si l'arbre contient aucun noeud
    return FAUX;  //1 si l'arbre contient au moins un noeud
}

Arbre creer_arbre(int racine, Arbre gauche, Arbre droit){
    Arbre r = (Arbre)malloc(sizeof(Noeud));
    r->valeur=racine; //on initialise la valeur du noeud a la valeur passee en parametre
    r->gauche=gauche; //on initialise le pointeur vers le noeud gauche a NULL
    r->droite=droit;  //on initialise le pointeur vers le noeud droite a NULL
    return r; //on retourne le pointeur vers le noeud
}

void parcours_prefixe(Arbre a){
    Arbre r = a; //on copie le pointeur vers le noeud a un autre pointeur r pour ne pas perdu le pointeur vers le noeud a
    if(est_vide(r)) //si le pointeur vers le noeud est NULL, on retourne sans rien
      return;   
    printf("%d ",r->valeur); //on affiche la valeur du noeud actuel
    parcours_prefixe(r->gauche); //on parcourt le sous-arbre gauche jusqu'a la fin du sous-arbre gauche actuel
    parcours_prefixe(r->droite); //on parcourt le sous-arbre droite jusqu'a la fin du sous-arbre droite actuel
}

void parcours_infixe(Arbre a){
    Arbre r = a; //on copie le pointeur vers le noeud a un autre pointeur r pour ne pas perdu le pointeur vers le noeud a
    if(est_vide(r)) //si le pointeur vers le noeud est NULL, on retourne sans rien
      return;   
    parcours_infixe(r->gauche); //on parcourt le sous-arbre gauche jusqu'a la fin du sous-arbre gauche actuel
    printf("%d ",r->valeur); //on affiche la valeur du noeud actuel
    parcours_infixe(r->droite); //on parcourt le sous-arbre droite jusqu'a la fin du sous-arbre droite actuel
}

void parcours_postfixe(Arbre a){
    Arbre r = a; //on copie le pointeur vers le noeud a un autre pointeur r pour ne pas perdu le pointeur vers le noeud a
    if(est_vide(r)) //si le pointeur vers le noeud est NULL, on retourne sans rien
      return;   
    parcours_postfixe(r->gauche); //on parcourt le sous-arbre gauche jusqu'a la fin du sous-arbre gauche actuel
    parcours_postfixe(r->droite); //on parcourt le sous-arbre droite jusqu'a la fin du sous-arbre droite actuel
    printf("%d ",r->valeur); //on affiche la valeur du noeud actuel
}

int hauteur(Arbre a){
    if(est_vide(a)) //cas de base si le noebre est vide, on retourne 0
      return 0;
    int h_gauche =hauteur(a->gauche); //on calcule la hauteur du sous-arbre gauche
    int h_droite =hauteur(a->droite); //on calcule la hauteur du sous-arbre droite
    return 1+MAX(h_gauche,h_droite); //on retourne la hauteur du sous-arbre actuel
    //on ajoute 1 car on compte le noeud actuel
}


int taille(Arbre a){
    if(est_vide(a)) //cas de base si le noebre est vide, on retourne 0
      return 0;  
    return 1+taille(a->gauche)+taille(a->droite); //cas de récursion
}

int somme(Arbre a){
    if(est_vide(a)) //cas de base si le noebre est vide, on retourne 0
      return 0;
    return a->valeur+somme(a->gauche)+somme(a->droite); //cas de récursion
    //on ajoute la valeur du noeud actuel et la somme des valeurs des noeuds de sa sous-arbre gauche et droite
}


Boolean rechercher(Arbre a, int x){
    if(est_vide(a)) //cas de base si le noebre est vide, on retourne FAUX
      return FAUX;
    if(a->valeur==x) //si la valeur du noeud actuel est egale a la valeur recherchee, on retourne VRAIE
      return VRAIE;
    return rechercher(a->gauche,x) || rechercher(a->droite,x); //on recherche dans le sous-arbre gauche et dans le sous-arbre droite
}