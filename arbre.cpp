#include<string.h>
#include<stdlib.h>
#include<math.h>
#include "arbre.h"
#include"liste.h"
    /*corps des fonctions dont le prototype est defini en arbre.h*/
//Fonction qui cree un  nouveau noeud

NOEUD* cN (objet* OBJET,NOEUD* gauche,NOEUD* droit){
     NOEUD* nouveau = (NOEUD*)malloc(sizeof(NOEUD));
     nouveau->reference = OBJET;
     nouveau->gauche = gauche;
     nouveau->droit = droit;
     return nouveau;
}
//creation dun noeud qui creent une feuille
NOEUD* cF (objet* OBJET){
 return cN (OBJET,NULL,NULL);//les deux noeud droit et gauche
}
//initialisation de larbre
void initarbre(ARBRE* arbre,NOEUD* racine,char* (*afficher)(objet*),int (*comparer)(objet*,objet*)){
    arbre->racine = racine;
    arbre->afficher=afficher;
    arbre->comparer=comparer;
}
//creation de larbre
ARBRE* creerarbre(NOEUD* racine,char* (*afficher)(objet*),int (*comparer)(objet*,objet*)){
 ARBRE* arbre = (ARBRE*)malloc(sizeof(ARBRE));
 initarbre(arbre,racine,afficher,comparer);
 return arbre;
}
//fonction daffichage
char* afficher(objet* OBJET){
 char* p=(char*)OBJET;//caster OBJET en un char
 char* output=(char*)malloc(sizeof(NOEUD));
 snprintf(output,sizeof(NOEUD),"%s\n",p);
 return output;
}

//fonction de comparaison
int comparer(objet* OBJET1,objet* OBJET2){

   return strcmp((char*)OBJET1,(char*)OBJET2);
}
     /* fonctions parcours de liste en profondeur on adapte la maniere de gauche a droite */
//parcours en profondeur préfixé (P-SAG-SAD)-pere au debut
void prefixe(NOEUD* racine,char* (*afficher)(objet*)){
    if(racine != NULL){ //tant qu il ya de racine
        printf("%s",afficher(racine->reference)); //tu affiche son contenu
        prefixe(racine->gauche,afficher);//tu passes a sa racine gauche
        prefixe(racine->droit,afficher);//puis tu passes a sa racine droite
    }
}
//parcours en profondeur infixé(SAG-P-SAD)-pere au milieu
void infixe(NOEUD* racine,char* (*afficher)(objet*)){
    if(racine !=NULL){ //tant qu il ya de racine
        prefixe(racine->gauche,afficher);//tu passes a sa racine gauche
        printf("%s",afficher(racine->reference)); //tu affiche son contenu
        prefixe(racine->droit,afficher);//puis tu passes a sa racine droite
    }
}
//parcours en profondeur postfixé(SAG-SAD-P)-pere en dernier
void postfixe(NOEUD* racine,char* (*afficher)(objet*)){
    if(racine !=NULL){ //tant qu il ya de racine
        prefixe(racine->gauche,afficher);//tu passes a sa racine gauche
        prefixe(racine->droit,afficher);//puis tu passes a sa racine droite
        printf("%s",afficher(racine->reference)); //tu affiche son contenu
    }
}
//trouver un noeud
NOEUD* trouvernoeud(NOEUD* racine,objet* OBJET,int (*comparer)(objet*,objet*)){
    NOEUD* pNom;
    if(racine == NULL){//si elle est nul ca sert a rien de comparer
        pNom = NULL;
    }
    else if(comparer(racine->reference,OBJET)==0){//comparer le contenu de la racine avec lobjet recherche
                                                  //utilité pointeur sur fonction
        pNom=racine;//je retourne le noeud qui contient l'objet recherche
    }
    else{
        pNom = trouvernoeud(racine->gauche,OBJET,comparer);//appliquer de maniere recursive
        if(pNom == NULL){ //je passe au sous arbre droit
            pNom=trouvernoeud(racine->droit,OBJET,comparer);
                }
    }
    return pNom;//retourne soit une valeur null  soit un noeud (je peux acceder a sa valeur noeud->reference
}

//parcours en largeur
void enlargeur(NOEUD* racine,char* (*afficher)(objet*)){
/* Pour passer dun niveau a un autre jai besoin de savoir la racine , pour acceder au niveau n+1 jai besoin du niveau n
dans le bon ordre j'utilise une liste chaine qui joue le role dune file datente*/
LISTE* li = creation(0,NULL,NULL);//creation dune liste
insererenfinliste(li,racine);//au debut jinsere la racine en fin de liste
//faut preciser listevide(li)
  while(!listevide(li)){ //tant que la liste nest pas vide je prend le premier element
    NOEUD* extrait = (NOEUD*)extraireentetedeliste(li);
    printf("%s",afficher(extrait->reference));
    if (extrait->gauche != NULL){
        insererenfinliste(li,extrait->gauche);
    }
    if(extrait->droit != NULL){
        insererenfinliste(li,extrait->droit);
    }
  }
}
//taille
int taille(NOEUD* racine){
//taille des sous arbres droits +taille des sous arbres gauche+1(si la racine nest pas null)
    if(racine==NULL){
        return 0;
    }
    else{
        return 1+taille(racine->gauche)+taille(racine->droit);
    }
}
//estFeuille : il suffit de verifier fils droit et fils gauche null
bool estfeuille(NOEUD* racine){
    return((racine->gauche==NULL)&&(racine->droit==NULL));
}
//nbFeuilles : compte le nombre de feuilles de larbre binaire a partir du noeud racine
int nbFeuilles(NOEUD* racine){
  if(racine==NULL){
    return 0;
  }else if( estfeuille(racine)){ //racine aucun fils est une feuille
   return 1;
  }
  else{
    return nbFeuilles(racine->gauche)+nbFeuilles(racine->droit);
  }
}
//pour  determier qua partir du parametre arbre seul
/*
int nbFeuilles(ARBRE* arbre){
   return nbFeuilles(arbre->racine);
}*/
//lister Feuille
void listerFeuilles(NOEUD* racine,char* (*afficher)(objet*)){
 if(racine != NULL){
    if(estfeuille(racine)){
        printf("%s",afficher(racine->reference));
    }else{
      listerFeuilles(racine->droit,afficher);
      listerFeuilles(racine->gauche, afficher);
     }
 }
}

//hauteur:niveau maximal a partir de la racine:la branche la plus longue
int hauteur(NOEUD* racine){
if(racine==NULL){
    return 0;
}else{
  return 1+ fmax(hauteur(racine->gauche),hauteur (racine->droit));//le 1 de la racine
}
}
//egalité arbre
bool egalitearbre(NOEUD* racine1,NOEUD* racine2,int(*comparer)(objet*,objet*)){
    bool result=false;
    if((racine1==NULL) && (racine2==NULL)){
        result=true;
    } else if((racine1!=NULL)&&(racine2!=NULL)){
     if(comparer(racine1->reference,racine2->reference)==0){
        if(egalitearbre(racine1->gauche,racine2->gauche,comparer)){
            result=egalitearbre(racine1->droit,racine2->droit,comparer);
        }
     }
    }
    return result;
}
