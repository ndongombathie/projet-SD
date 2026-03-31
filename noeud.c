#include "noeud.h"
#include <stdlib.h>
#include <stdio.h>

Noeud* creer_noeud(int valeur){
    Noeud* n = (Noeud*) malloc(sizeof(Noeud));
    n->gauche=NULL;
    n->droite=NULL;
    n->valeur=valeur;
    return n;
}

Boolean est_vide(Arbre a){
    if(a==NULL)
      return VRAIE;
    return FAUX;
}

Arbre creer_arbre(int racine, Arbre gauche, Arbre droit){
    Arbre r = (Arbre)malloc(sizeof(Noeud));
    r->valeur=racine;
    r->gauche=gauche;
    r->droite=droit;
    return r;
}

void parcours_prefixe(Arbre a){
    Arbre r = a;
    if(est_vide(r))
      return;   
    printf("%d ",r->valeur);
    parcours_prefixe(r->gauche);
    parcours_prefixe(r->droite);
}

void parcours_infixe(Arbre a){
    Arbre r = a;
    if(est_vide(r))
      return;   
    parcours_infixe(r->gauche);
    printf("%d ",r->valeur);
    parcours_infixe(r->droite);
}

void parcours_postfixe(Arbre a){
    Arbre r = a;
    if(est_vide(r))
      return;   
    parcours_postfixe(r->gauche);
    parcours_postfixe(r->droite);
    printf("%d ",r->valeur);
}

