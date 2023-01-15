#include <stdio.h>
#include <stdlib.h>
#include<stdlib.h>
#include<string.h>
	/*contient la déclaration de la structure arbre*/
typedef void objet; //Renommer void en objet
//un noeud de l'arbre: le type NOEUD
typedef struct noeud{
	objet* reference; //le type void* est générique
	struct noeud* gauche;
	struct noeud* droit;
}NOEUD;
//le type arbre
typedef struct{
	NOEUD* racine;
//utilisation de pointeurs sur fonction car le type est générique//
	char* (*afficher) (objet*);
	int (*comparer) (objet*,objet*);
}ARBRE;
//Fonction qui cree un  nouveau noeud
NOEUD* cN (objet* OBJET,NOEUD* gauche,NOEUD* droit);
//creation dun noeud qui creent une feuille
NOEUD* cF (objet* OBJET);
//initialisation de larbre
void initarbre(ARBRE* arbre,NOEUD* racine,char* (*afficher)(objet*),int (*comparer)(objet*,objet*));
//creation de larbre
ARBRE* creerarbre(NOEUD* racine,char* (*afficher)(objet*),int (*comparer)(objet*,objet*));
//fonction daffichage
char* afficher(objet* OBJET);
//fonction de comparaison
int comparer(objet* OBJET1,objet* OBJET2);
 /* fonctions parcours de liste en profondeur on adapte la maniere de gauche a droite */
//parcours en profondeur préfixé (P-SAG-SAD)-pere au debut
void prefixe(NOEUD* racine,char* (*afficher)(objet*));
//parcours en profondeur infixé(SAG-P-SAD)-pere au milieu
void infixe(NOEUD* racine,char* (*afficher)(objet*));
//parcours en profondeur postfixé(SAG-SAD-P)-pere en dernier
void postfixe(NOEUD* racine,char* (*afficher)(objet*));
//trouver un noeud
NOEUD* trouvernoeud(NOEUD* racine,objet* OBJET,int (*comparer)(objet*,objet*));
//parcours en largeur
void enlargeur(NOEUD* racine,char* (*afficher)(objet*));
//taille
int taille(NOEUD* racine);
//estFeuille
bool estfeuille(NOEUD* racine);
//nbFeuilles : compte le nombre de feuilles de larbre binaire a partir du noeud racine
int nbFeuilles(NOEUD* racine);
//lister Feuille
void listerFeuilles(NOEUD* racine,char* (*afficher)(objet*));
//hauteur:niveau maximal a partir de la racine:la branche la plus longue
int hauteur(NOEUD* racine);
//egalité arbre
bool egalitearbre(NOEUD* racine1,NOEUD* racine2,int(*comparer)(objet*,objet*));
