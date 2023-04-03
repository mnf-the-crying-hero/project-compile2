#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct element{
    char Nom[20];
    
}tabidf;
 

typedef struct ele3{
     int entier;
     float real;
     int type;
     char chaine[20];
}multi_val2;
typedef struct ele *Liste;
typedef struct ele{
    char Nom[20] ;
    int nature;
    multi_val2 valeur;
    int type; 
    Liste Suivant;  
}noeud;

 


void inserer  (char Nom[20]);
int rechercheidf(char E[20]) ;
void afficheidf();
void ajoutapres(Liste *prd,char* Nom,int nature,int type,int valeur);

void remplire(Liste *lisElts,int nature,int type,int valeur);
void affiche(Liste lisElts);

void non_dec(Liste *lisElts,char Name[20]);

void remplire_cont_idf(Liste *lisElts,char nom[20],multi_val2 valeur);
int recherche_type(Liste *lisElts,char nom[20]);
multi_val2  return_value(Liste *lisElts,char Name[20]);