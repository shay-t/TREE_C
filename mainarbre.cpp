#include<iostream>
#include <stdio.h>
#include <stdlib.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include"arbre.h"
#include"liste.h"
 //insertion de la bibliotheque locale crée
//declartaion du menu
int menu1(){
	int code;
	printf("\n GESTION D'arbres:\n");
	printf("\n\n ARBRES BINAIRES\n");
	printf("0-Fin du programme\n");
	printf("1-Creation d'une arbre genealogique\n");
	printf("2-Creation de l'arbre de l'expression arithmetique\n");
	printf("\n");
	printf("3-Parcours prefixe\n");
	printf("4-Parcours infixe\n");
	printf("5-Parcours postfixe\n");
	printf("\n");
	printf("6-Trouver le noeud \n");
	printf("7-Parcours en largeur\n");
	printf("8-Donner la taille\n");
	printf("9-Determiner si c'est une feuille\n");
	printf("10-Determiner le nombre de feuilles\n");
	printf("11-Lister les feuilles\n");
	printf("12-Determiner la hauteur\n");
	printf("13-Egalite des arbres\n");
	printf("\n");
	printf("\n-----------------------------------------\n");
	printf("Veuillez effectuer un choix\n");
    scanf("%d",&code);
	return code;
}
//fonction qui permet la creation dune arbre genealogique a partir des fonctions de arbre.h
ARBRE* creerarbregene(){
    //declaration et allocation dynamique de la memoire
    char* p1=(char*)malloc(sizeof(char));
    char* p2=(char*)malloc(sizeof(char));
    char* p3=(char*)malloc(sizeof(char));
    char* p4=(char*)malloc(sizeof(char));
    char* p5=(char*)malloc(sizeof(char));
    char* p6=(char*)malloc(sizeof(char));
    char* p7=(char*)malloc(sizeof(char));
    //initialisation
    p1="Samir";
    p2="Kamal";
    p3="Yassine";
    p4="Hind";
    p5="Yasmine";
    p6="Sarah";
    p7="Karim";
    //creation de larbre
    /*Creation dun noeud racine qui contient dautres noeuds (nested)-(objet,ng,nd)*/
    NOEUD* racine =
        cN(p1,
           cN(p2,
              cN(p3,
                 NULL,
                 cN(p4,NULL,cF(p5))
                 ),
                 cN(p6,cF(p7),NULL)
              ),
           NULL);

 return creerarbre(racine,afficher,comparer);
}
//fonction qui permet la creation dune arbre arithmetique a partir des fonctions de arbre.h
ARBRE* creerarbrearith(){
    //declaration et allocation dynamique de la memoire
    char* p1=(char*)malloc(sizeof(char));
    char* p2=(char*)malloc(sizeof(char));
    char* p3=(char*)malloc(sizeof(char));
    char* p4=(char*)malloc(sizeof(char));
    char* p5=(char*)malloc(sizeof(char));
    char* p6=(char*)malloc(sizeof(char));
    char* p7=(char*)malloc(sizeof(char));
    char* p8=(char*)malloc(sizeof(char));
    char* p9=(char*)malloc(sizeof(char));
    //initialisation
    p1="-";
    p2="*";
    p3="+";
    p4="a";
    p5="b";
    p6="-";
    p7="c";
    p8="d";
    p9="e";
/*Creation dun noeud racine qui contient dautres noeuds (nested)-(objet,ng,nd)-cN(,,)*/
NOEUD* racine =cN(p1,cN(p2,cN(p3,cF(p4),cF(p5)),cN(p6,cF(p7),cF(p8))),cF(p9));

return creerarbre(racine,afficher,comparer);//pas besoin de declarer afficher ou comparer
}

//programme principale
int main() {
	ARBRE* ag=creerarbregene();;//arbre genealogique
	ARBRE* art=creerarbrearith();//arbre arithmetique

	bool sortir=0;
	while(!sortir){
		switch(menu1()){
		    case 0:{
		          sortir=1;
		    }break;
		    case 1:{
		        printf("l'arbre genealogique a ete creer ");
		        printf("\n-----------------------------------------\n");
		    } break;
		     case 2:{
		         printf("l'arbre arithmetique a ete creer ");
		         printf("\n-----------------------------------------\n");
		    } break;
		     case 3:{
		         printf("le parcours prefixe pour l'arbre genealogique ");
		         prefixe(ag->racine,afficher);
		         printf("\n----------\n");
                 printf("le parcours prefixe pour l'arbre arithmetique \n");
                 prefixe(art->racine,afficher);
		         printf("\n-----------------------------------------\n");
		    } break;
		     case 4:{
                 printf("\n le parcours infixe pour l'arbre genealogique :\n");
		         infixe(ag->racine,afficher);
		         printf("\n----------\n");
                 printf("\n le parcours infixe pour l'arbre arithmetique :\n");
                 infixe(art->racine,afficher);
		         printf("\n-----------------------------------------\n");
		    } break;
		     case 5:{
		         printf("\n le parcours infixe pour l'arbre genealogique :\n");
		         postfixe(ag->racine,afficher);
		         printf("\n----------\n");
                 printf("\n le parcours infixe pour l'arbre arithmetique :\n");
                 postfixe(art->racine,afficher);
		         printf("\n-----------------------------------------\n");
		    } break;
		     case 6:{
		         NOEUD* rechercheg=(NOEUD*)malloc(sizeof(NOEUD));
		         NOEUD* recherchea=(NOEUD*)malloc(sizeof(NOEUD));
		         printf("entrez le noeud que vous voulez rechercher dans larbre genealogique \n");
		         scanf("%s",rechercheg);
		         rechercheg=cN(rechercheg,0,0);//recuperation de donnes
		         //on cree un noeud qui est le rtour de la fonction
		         NOEUD* retourg=(NOEUD*)trouvernoeud(ag->racine,rechercheg->reference,comparer);
		         if(retourg != NULL){
                    printf("lelement %s existe",retourg->reference);
		         }
		         else
                    printf("lelemnt nexiste pas");
                 printf("\n----------\n");
                 printf("entrez le noeud que vous voulez rechercher dans larbre arithmetique \n");
		         scanf("%s",recherchea);
		         recherchea=cN(recherchea,0,0);//recuperation de donnes
		         //on cree un noeud qui est le rtour de la fonction
		         NOEUD* retoura=(NOEUD*)trouvernoeud(art->racine,recherchea->reference,comparer);
		         if(retoura != NULL){
                    printf("lelement %s existe",retoura->reference);
		         }
		         else
                    printf("lelemnt nexiste pas");
                printf("\n-----------------------------------------\n");
		    } break;

		     case 7:{
                printf("\n Parcours en largeur de l arbre genealogique \n");
                enlargeur(ag->racine,afficher);
                printf("\n----------\n");
                printf("\n Parcours en largeur pour l'arbre arithmetique :\n");
                enlargeur(art->racine,afficher);
		    } break;
		     case 8:{
		         printf("\n La taille de l arbre genealogique est : %d",taille(ag->racine));
		         printf("\n----------\n");
		         printf("\n La taille de l'arbre arithmetique est : %d",taille(art->racine));
                 printf("\n-----------------------------------------\n");
		    } break;
		     case 9:{
		         NOEUD* rechercheg=(NOEUD*)malloc(sizeof(NOEUD));
		         NOEUD* recherchea=(NOEUD*)malloc(sizeof(NOEUD));
		         printf("Entrez le noeud que vous voulez verifier que c'est une feuille dans larbre genealogique \n");
		         scanf("%s",rechercheg);
		         rechercheg= cN(rechercheg,0,0);//recuperation de donnes en tant que noeud car on ne sait pas encore si c'est une feuille
		         //il faut trouver le noeud dans larbre puis voir si cest une feuille
		         NOEUD* retourg=(NOEUD*)trouvernoeud(ag->racine,rechercheg->reference,comparer);
		         if(retourg != NULL){
                    if(estfeuille(retourg)){
                        printf("lelement %s est  une feuille",rechercheg->reference);}
		           else{
                      printf("lelement %s n'est pas une feuille",rechercheg->reference);}
		         }
		         else
                    printf("lelemnt nexiste pas");
		         printf("\n----------\n");
                 printf("Entrez le noeud que vous voulez verifier que c'est une feuille dans larbre arithmetique \n");
		         scanf("%s",recherchea);
		         recherchea= cN(recherchea,0,0);//recuperation de donnes en tant que noeud car on ne sait pas encore si c'est une feuille
		          //il faut trouver le noeud dans larbre puis voir si cest une feuille
		         NOEUD* retoura=(NOEUD*)trouvernoeud(art->racine,recherchea->reference,comparer);
		         if(retoura != NULL){
                    if(estfeuille(retoura)){
                        printf("lelement %s est  une feuille",recherchea->reference);}
		           else{
                      printf("lelement %s n'est pas une feuille",recherchea->reference);}
		         }
		         else
                    printf("lelemnt nexiste pas");
		         printf("\n-----------------------------------------\n");
		    } break;
		    case 10:{
		        printf("\n Le nombre de feuilles dans l'arbre genealogique est %d\n",nbFeuilles(ag->racine));
		        printf("\n----------\n");
		        printf("\n Le nombre de feuilles dans l'arbre arithmetique est %d\n",nbFeuilles(art->racine));
		        printf("\n-----------------------------------------\n");
		    } break;
		    case 11:{
		        //probleme
		        printf("\n lister les feuilles de l'arbre genealogique \n");
		        listerFeuilles(ag->racine,afficher);
		        printf("\n----------\n");
		        printf("\n lister les feuilles de larbre arithmetique \n" );
		        listerFeuilles(art->racine,afficher);
		        printf("\n-----------------------------------------\n");
		    } break;
		    case 12:{

		        printf("\n La hauteur de l'arbre genealogique est %d\n",hauteur(ag->racine));
		        printf("\n----------\n");
		        printf("\n La hauteur l'arbre arithmetique est %d\n",hauteur(art->racine));
		        printf("\n-----------------------------------------\n");
		    } break;
		    case 13 :{
		         printf("Comparaison de l'arbre genealogique avec l'arbre arithmetique\n");
                if(egalitearbre(ag->racine,art->racine,comparer)){
                    printf("Les deux arbres sont egaux\n");
                }else{
                    printf("Les deux arbres sont differents\n");
                }
                printf("\n----------\n");
                printf("Comparaison de l'arbre genealogique avec elle meme \n");
                if(egalitearbre(ag->racine,ag->racine,comparer)){
                    printf("Les deux arbres sont egaux\n");
                }else{
                    printf("Les deux arbres sont differents\n");
                }
                printf("\n-----------------------------------------\n");
		    }break ;

		}}
 return 0;}
