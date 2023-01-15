#include<iostream>
#include <stdio.h>
#include <stdlib.h>
#include<stdlib.h>
#include<string.h>
#include"liste.h"
		/*corps des fonctions dont le prototype est defini en liste.h*/
//intialisation de LISTE (on ne peut pas reconnaitre si lelement est premier,dernier, ou courant=> pointeur li de type LISTE ce dernier pointe sur link)
void initialisation(LISTE *li,int type,char*(*afficher)(objet*),int(*comparer)(objet*,objet*)){
	li->premier=NULL;
	li->dernier=NULL;
	li->courant=NULL;
	li->nbELT=0;
	/*passées en parametres: definis par lutilisateur*/
	li->type=type;
	li->afficher=afficher;
	li->comparer=comparer;
}
//fonction qui permet la creation d'une liste c-a-d allouer de l'espace mémoire
LISTE* creation(int type,char*(*afficher)(objet*),int(*comparer)(objet*,objet*)){//ca retourne un pointeur de type LISTE
	LISTE* li=(LISTE*) malloc(sizeof(LISTE));//allouer la memoire pour l'élément premier- adresse retourner utiliser pour linitialisation
	initialisation(li,type,afficher,comparer);
	return li;
}
//Fonction affichage
char* afficherChar(objet* OBJET){
    return(char*)(OBJET);//caster en chaine caractere
}
//Fonction comparaison
int comparerChar(objet* OBJET1,objet* OBJET2){
	return strcmp((char*)(OBJET1),(char*)(OBJET2));//caster en char puis donnée à la fonction strcmp
}
//fonction qui fournit le nombre d'element dans la liste
int nbELEMENT(LISTE*li){
	return li->nbELT;
}
//fonction qui teste si la liste est vide
bool listevide(LISTE *li){
    return li->nbELT == 0;
}
//Fonction qui cree un nouveau ELEMENT en lui reservant de la mémoire
static ELEMENT* creerelement(){ //static elle ne peut etre appellés que a l'intérieur de ce fichier
	return (ELEMENT*)malloc(sizeof(ELEMENT));
}
//Ajout en tete de liste
typedef void objet;
void insererteteliste(LISTE* li,objet* OBJET){ //OBJET:nom de la variable
	ELEMENT* nouveau = creerelement();
	nouveau->reference= OBJET;//insertion de donnés(passés comme parametres)
	nouveau->suivant=li->premier;//pointeur suivant du nouveau, pointe sur ELEMENT premier
	li->premier=nouveau;//le pointeur li qui pointe sur ELEMENT premier de la liste pointe sur ELEMENT nouveau
	                         //(considéré  maintenant element premier)
	if(li->dernier==NULL){//le cas d'un seul elément dans la liste le premier est le dernier
		li->dernier=nouveau;//le pointeur li sur le dernier devient un pointeur sur le nouveau(qui devient le dernier)
	}
	li->nbELT++;//incrementation des nombres elements constituant la liste
}
//Ajout  apres un element (fct utiliser pour ajouter en fin de liste)
static void insererapres(LISTE* li,ELEMENT* precedent,objet* OBJET){
	if(precedent==NULL){ //retourne au cas insérer en tete liste
	  insererteteliste(li,OBJET);
	}
	else{
		ELEMENT* nouveau=creerelement();
    	nouveau->reference=OBJET;//insertion de donnés(passés comme parametres)
    	nouveau->suivant=precedent->suivant;//le suivant de precedant :sur lequelle pointe suivant du nouveau inseré
    	precedent->suivant=nouveau; //le suivant de lelement precedent pointe sur le nouveau
    	if(precedent==li->dernier){ //si le precedent est le dernier
    		li->dernier=nouveau; //tout simplement li pointe sur nouveau en le considerant"NOUVEAU" dernier
		}
		li->nbELT++;
	}
}
//Ajout en fin de liste
void insererenfinliste(LISTE* li,objet* OBJET){
	insererapres(li,li->dernier,OBJET);//c'est inserer apres le dernier element
}
     /*fonctions de positions dans la liste*/
//positionnement au debut (sur le premier element de la liste li)
void ouvrirliste(LISTE* li){
	li->courant = li->premier; //on prend le premier element et on le stocke dans le courant
}
//indicateur si on arrive a la fin de la liste
bool finliste(LISTE* li){
	return li->courant==NULL; //ca retourne true ou false
}
     /*fonctions de retour ELEMENT-OBJET courant de la liste*/
//retourner ELEMENT courant cad adresse
static ELEMENT* elementcourant(LISTE* li){
	ELEMENT* ptc = li->courant; //un pointeur sur ELEMENT courant
	if(li->courant != NULL){ //si il est null ca sert a rien de voir le suivant on est en fin de LISTE
		li->courant = li->courant->suivant; //qd je retourne le courant il n'est plus courant le courant est ELEMENT suivant
	}
	return ptc;
}
//retourne OBJET courant (cas général type void*)
objet* objetcourant(LISTE* li){
	ELEMENT* ptc = elementcourant(li); // pointeur temporaire
	return ptc==NULL ? NULL: ptc-> reference; // pointeur null on retourne rien sinon on retourne référence c'est la donné
}
     /*fonctions de parcours de liste*/
//Lister liste : affichage de l'ensemble des OBJET
void listerliste(LISTE* li){
	ouvrirliste(li);//positionnement sur ELEMENT premier
	while(!finliste(li)){ //tant que on arrive pas a la fin
		objet* OBJET = objetcourant(li); //chacun devient objet courant et le  passe au suivant
		printf("%s",li->afficher(OBJET));//affichage de lensemble des données de liste-jutilise
		// li->afficher :Pointeur sur une fonction d'affichage car je connais pas son type
	}
}

//Chercher un OBJET cad une donnee
objet* chercherunobjet(LISTE* li,objet* OBJETCHERCHE){
	bool trouve=0;
	objet* OBJET;//pour recuperer et comparer a chaque fois ainsi retourner si elle correspond a la valeur trouvee
	ouvrirliste(li);
	while(!finliste(li) && !trouve){
		OBJET=objetcourant(li);//recupere objetcourant
		trouve=li->comparer(OBJETCHERCHE,OBJET)==0;//pointeur sur fonction car on connait pas le type
	}
	return trouve ? OBJET: NULL;//si je le trouve je le retourne sinon je retourne null
}
    /*fonctions de suppression*/
//retrait en tete de liste
objet* extraireentetedeliste(LISTE* li){
	ELEMENT* extrait = li->premier;//poser dans une variable temporaire
	if(!listevide(li)){
		li->premier = li->premier->suivant;//2eme element devient premier
		if(li->premier==NULL){//cad que la liste contient 1 seul element
			li->dernier = NULL;//jai enleve  le premier element donc je rend la liste vide
		}
		li->nbELT--;
	}
	return extrait == NULL ? NULL : extrait->reference;//si lextrait nest pas nul je retourne sa valeur(donnes) sinon je retourne rien
}
//retrait au milieu de la liste
static objet* extraireapres(LISTE* li,ELEMENT* precedent){ //il faut avoir le precedent car "pointeur suivant" du precedent
                                                           // doit pointer sur le suivant a extraire
	if(precedent==NULL){ //on extrait en tete de liste
		return extraireentetedeliste(li);
	}else{ //le précedent n'est pas nul
		ELEMENT* extrait=precedent->suivant;//on garde ELEMENT precedent qui pointe sur le suivant dans extrait
		if(extrait != NULL){//cas normal
			precedent->suivant=extrait->suivant;//tout normal suivant sur lequelle pointe le precedent,devient le suivant sur
			                                    //lequel pointelextrait
			if(extrait == li->dernier){ //il pointe sur le dernier ELEMENT
				li->dernier = precedent;//on change li pointe sur le precedant etant le dernier
			}
		  li->nbELT--;
		}
	    return (extrait !=NULL) ? extrait->reference :NULL;//si lextrait nest pas nul je retourne sa valeur(donnes)
	                                                        // sinon je retourne rien
	}
}
//retrait a la fin de la liste
objet* extraireenfindeliste(LISTE* li){
	objet* extrait;
	if(listevide(li)){ //on a rien a extraire la liste est vide
		extrait=NULL;
	} else if (li->premier == li->dernier){//la liste contient 1 seul element
		extrait=extraireentetedeliste(li);//ca revient a ca
	}else{
		ELEMENT* ptc = li->premier;//un pointeur qui pointe sur le premier element
		while(ptc->suivant != li->dernier){//pointe sur suivant et narive pas a la fin
			ptc = ptc->suivant;//pointeur passe au suivant
			}
			extrait=extraireapres(li,ptc);//a chaque fois jusqua ce quon arrive a lavant dernier et sera inserer
			                              //comme dernier
		}
      return extrait;
	}


//retrait dun objet a partir de la referance
bool extrairobjet(LISTE* li,objet* OBJET){
	ELEMENT* precedent = NULL ; //precedant ne pointe sur rien
	ELEMENT* ptc = NULL;//pointeur ne pointe sur rien
	bool trouve = false;
	ouvrirliste(li);//positionnement au debut
	while(!finliste(li) && !trouve){ //tant non trouve et on arrive pas a la fin de la liste
		precedent = ptc;//garder element precedent dans chaque iteration utilise en extraire apres
		ptc = elementcourant(li);
		trouve = (ptc->reference == OBJET)? true : false;
	}
	if(!trouve)return false ;//trouve=0 c-a-d il n'a pas trouv
    else {
            objet* extrait = extraireapres(li,precedent);
    return true;}
}
/*Fonction de destruction */
void detruireliste(LISTE* li){
	ouvrirliste(li);//Positionnement au debut
	while(!finliste(li)){
		ELEMENT* ptc=elementcourant(li);
		free(ptc);//libère un bloc de mémoire alloué dynamiquement
	} //on a liberé tout les blocs
}

