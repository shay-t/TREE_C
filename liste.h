#include <stdio.h>
#include <stdlib.h>
#include<stdlib.h>
#include<string.h>

	/*contient la déclaration de la structure liste*/
typedef void objet; //Renommer void en objet
//un element de la liste: le type ELEMENT
typedef struct element{
	objet* reference; //le type void* est générique
	struct element *suivant;
}ELEMENT;
//le type LISTE
typedef struct{
	ELEMENT* premier; //Des pointeurs de type ELEMENT
	ELEMENT* dernier;
	ELEMENT* courant;
	int nbELT;
	int type;
//utilisation de pointeurs sur fonction car le type est générique//
	char* (*afficher) (objet*);
	int (*comparer) (objet*,objet*);
}LISTE;
		/*les prototypes des fonctions de gestion d'une liste*/
//procédure intialisation de la liste par un pointeur li de type LISTE
void initialisation(LISTE *li,int type,char*(*afficher)(objet*),int(*comparer)(objet*,objet*));
//fonction qui permet la creation d'une liste c-a-d allouer de l'espace mémoire
LISTE* creation(int type,char*(*afficher)(objet*),int(*comparer)(objet*,objet*));
//Fonction affichage
char* afficherChar(objet* OBJET);
//Fonction comparaison
int comparerChar(objet* OBJET1,objet* OBJET2);
//fonction qui fournit le nombre d'element dans la liste
int nbELEMENT(LISTE*li);
//fonction qui teste si la liste est vide
bool listevide(LISTE* li);
//Ajout en tete de liste
void insererteteliste(LISTE* li,objet* OBJET);
//Ajout en fin de liste
void insererenfinliste(LISTE* li,objet* OBJET);
//positionnement au debut (sur le premier element de la liste li)
void ouvrirliste(LISTE* li);
//indicateur si on arrive a la fin de la liste
bool finliste(LISTE* li);
  /*fonctions de retour ELEMENT-OBJET courant de la liste*/
//retourne OBJET courant (cas général type void*)
objet* objetcourant(LISTE* li);
     /*fonctions de parcours de liste*/
//Lister liste : affichage de l'ensemble des OBJET
void listerliste(LISTE* li);
//Chercher un OBJET cad une donnee
objet* chercherunobjet(LISTE* li,objet* OBJETCHERCHE);
    /*fonctions de suppression*/
//retrait en tete de liste
objet* extraireentetedeliste(LISTE* li);
//retrait a la fin de la liste
objet* extraireenfindeliste(LISTE* li);
//retrait dun objet a partir de la referance
bool extrairobjet(LISTE* li,objet* OBJET);
/*Fonction de destruction */
void detruireliste(LISTE* li);
