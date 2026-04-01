#include "noeud.h"
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

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
    if(r==NULL){
      printf("Erreur: l'allocation memoire a echoue\n");
      exit(-1);
    }
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
    if(h_gauche>h_droite)
      return 1+h_gauche;
    else
      return 1+h_droite; //on retourne la hauteur du sous-arbre actuel
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

void si_est_dans_arbre(Arbre a, int x){

    if(rechercher(a,x)){
        printf("%d est dans l'arbre\n",x);
    }else{
        printf("%d n'est pas dans l'arbre\n",x);
    }
}


Arbre trouver_noeud(Arbre a, int x){
    if(est_vide(a))
        return NULL;

    if(a->valeur == x)
        return a;

    Arbre gauche = trouver_noeud(a->gauche, x);
    if(gauche != NULL)
        return gauche;

    return trouver_noeud(a->droite, x);
}

Arbre rechercher_parent(Arbre a, int x){
    if(est_vide(a))
        return NULL;

    if((a->gauche != NULL && a->gauche->valeur == x) ||
       (a->droite != NULL && a->droite->valeur == x))
        return a;

    Arbre p = rechercher_parent(a->gauche, x);
    if(p != NULL)
        return p;
    return rechercher_parent(a->droite, x);
} 




Arbre inserer_gauche(Arbre a, int parent, int valeur){
   Arbre r = NULL;
   Arbre g=creer_noeud(valeur); //on creer un nouveau noeud avec la valeur donnee
   if(est_vide(a)){
      a=g; //si l'arbre est vide, on ajoute le nouveau noeud a la racine
  }

  //rechercher le parent dans l'arbre a
  r = trouver_noeud(a,parent);

  // verifier si le fils existe deja
  if(rechercher(r,valeur)){
      printf("Erreur: le fils existe deja\n"); //si le fils existe deja, on affiche une erreur
      return a;
  }

  if(r!=NULL){
     r->gauche=g; //si le parent existe, on ajoute le nouveau noeud a la gauche du parent
  }else{
    printf("Erreur: le parent n'existe pas\n"); //si le parent n'existe pas, on affiche une erreur
  }
  return a; //on retourne le pointeur (la racine) vers le noeud
}

Arbre inserer_droite(Arbre a, int parent, int valeur){
   Arbre r = NULL;
   Arbre g=creer_noeud(valeur); //on creer un nouveau noeud avec la valeur donnee
   if(est_vide(a)){
      a=g; //si l'arbre est vide, on ajoute le nouveau noeud a la racine
  }

  //rechercher le parent dans l'arbre a
  r = trouver_noeud(a,parent);

  // verifier si le fils existe deja
  if(rechercher(r,valeur)){
      printf("Erreur: le fils existe deja\n"); //si le fils existe deja, on affiche une erreur
      return a;
  }

  if(r!=NULL){
     r->droite=g; //si le parent existe, on ajoute le nouveau noeud a la droite du parent
  }else{
    printf("Erreur: le parent n'existe pas\n"); //si le parent n'existe pas, on affiche une erreur
  }

  return a; //on retourne le pointeur (la racine) vers le noeud
} 

void afficher_arbre(Arbre a, int niveau){
    if(est_vide(a))
        return;
    afficher_arbre(a->droite, niveau + 1);
    for(int i = 0; i < niveau; i++)
        printf("    ");
    printf("%d\n", a->valeur);
    afficher_arbre(a->gauche, niveau + 1);
}



