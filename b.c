#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "bib.h"
 
int cpt=0;
int cpt2=0;
tabidf lidf[200];
Liste listElts;

int recherche_list(Liste *liselts,char Name[20]){
       Liste p;
       p=*liselts;
    while(p!=NULL){
        if(strcmp((p)->Nom,Name)==0){
            return 1;
        }
        else {(p)=(p)->Suivant;}
    }
    return -1;
}

void inserer  (char Nom[20])
{ 
    strcpy(lidf[cpt].Nom,Nom);
    cpt++;
}

void afficheidf()
{
  int i=0;
  printf("\n/********table des IDFS**********/\n");
  while(i<cpt){
    printf("%s \n",lidf[i].Nom);
      i++;
  }
}

Liste creenoeud()
{ 
  Liste l=(Liste)malloc(sizeof(noeud));
  if(l==NULL){printf("erreur d’allocation\n");exit(-1);}
    return l;
}

void ajouttete(Liste *tete,char Nom[20],int nature,int type,int valeur)
{
  Liste nouv;
  
  nouv=creenoeud();
  
  if(nouv!=NULL){
       strcpy(nouv->Nom,Nom);
       nouv->nature=nature; 
       nouv->type=type;
       if(nouv->type==0){
          nouv->valeur.entier=valeur;
       }else if(nouv->type==1){ nouv->valeur.real=valeur;}
        nouv->Suivant=*tete; 
        *tete=nouv;
  }
   
}

void remplire(Liste *lisElts,int nature,int type,int valeur)//rempire +double declaration
{
   int i;   
   for(i=cpt-1;i>=0;i--)
   {
    if(recherche_list(lisElts,lidf[i].Nom)==-1){
        ajouttete(lisElts,lidf[i].Nom,nature,type,valeur);
        cpt--;
    }else {printf("error:Double Declaration \"%s\"",lidf[i].Nom);exit(-1);} 
   }
}

void affiche(Liste lisElts)
{
  
      printf("\n**************la table de symbole**********\n");
      printf("idf*********type***********nature**********valeur\n");
    while(lisElts!=NULL)
    {
       if(lisElts->type==0){
         printf("%s\t\t%d\t\t%d\t\t%d\n",lisElts->Nom,lisElts->type,lisElts->nature,lisElts->valeur.entier);
       }else if(lisElts->type==1){
          printf("%s\t\t%d\t\t%d\t\t%.02f\n",lisElts->Nom,lisElts->type,lisElts->nature,lisElts->valeur.real);
       }
        
        lisElts=lisElts->Suivant;
      
    }
}

void non_dec(Liste *lisElts,char Name[20])
{
   if(recherche_list(lisElts,Name)==-1){
     printf("Erreur semantique:\"%s\" non declare",Name);exit(-1);
   }
}
multi_val2 return_value(Liste *lisElts,char Name[20]){
    Liste p;
    p=*lisElts;
    while(p!=NULL){
       
        if(strcmp((p)->Nom,Name)==0){
            printf("valeur:%s [%s] %d",(p)->Nom,Name,(p)->valeur.entier);
            return (p)->valeur;
        }
        else {(p)=(p)->Suivant;}
    }
    printf("pastrouver%s",Name );
}
void remplire_cont_idf(Liste *lisElts,char nom[20],multi_val2 valeur)
{
  Liste p=*lisElts;
  Liste q=*lisElts;
  while(p!=NULL){
     
      if(strcmp(p->Nom,nom)==0){
          if(p->nature==0){
        if(p->type==0 && valeur.type==0){
         
          (p->valeur).entier=valeur.entier;  
          }else if(p->type==1 && valeur.type==1){
            (p->valeur).real=valeur.real;
            } else if(p->type==1 && valeur.type==0){
              (p->valeur).real=(float)valeur.entier;
            }
           else if(strcmp(p->Nom,valeur.chaine)==0){
          
              while(q!=NULL){ 
                if(strcmp(q->Nom,valeur.chaine)==0){
                
                    if(q->type==0){
                      (p->valeur).entier=(q->valeur).entier; 
                    }else if(q->type==1){
                      (p->valeur).real=(q->valeur).real;
                      }   
                  } q=(*q).Suivant;
                }
              }else{printf("Erreur semantique:type \"%s\" :Pfloat to Pint",nom);exit(-1);} 
          }else{printf("Erreur semantique:changer un constant \"%s\" ",nom);exit(-1);}
     }
     p=(*p).Suivant;
       }
}    
/*a la place de char nom on fait multi val est en fait la verificatiob du resultat $$*/
int recherche_type(Liste *lisElts,char nom[20]) {
  Liste p=*lisElts;
   while(p!=NULL){
 if(strcmp(p->Nom,nom)==0){
       return p->nature;
      }
       p=(*p).Suivant;
   }
}