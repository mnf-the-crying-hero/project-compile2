#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
#define TAILLE_TABLE 100 // taille de la table de hachage
 
typedef struct {
    int taille;
    Liste *table;
} TableHachage;

// fonction de hachage
int hash(char *nom, int taille_table) {
    int somme = 0;
    for (int i = 0; nom[i] != '\0'; i++) {
        somme += nom[i];
    }
    return somme % taille_table;
}

// fonction pour initialiser la table de hachage
TableHachage init_table(int taille) {
    TableHachage table;
    table.taille = taille;
    table.table = malloc(taille * sizeof(Liste));
    for (int i = 0; i < taille; i++) {
        table.table[i] = NULL;
    }
    return table;
}

// fonction pour ajouter un noeud dans la table de hachage
void ajouter_noeud(char *nom, int nature, multi_val2 valeur, int type, TableHachage *table) {
    int index = hash(nom, table->taille);
    Liste nouvelle_liste = malloc(sizeof(noeud));
    strncpy(nouvelle_liste->Nom, nom, 20);
    nouvelle_liste->nature = nature;
   
    nouvelle_liste->valeur = valeur;
    nouvelle_liste->type = type;
    nouvelle_liste->Suivant = table->table[index];
    table->table[index] = nouvelle_liste;
}

// fonction pour chercher un noeud dans la table de hachage
noeud* lookup(char *nom, TableHachage table) {
    int index = hash(nom, table.taille);
    Liste liste_actuelle = table.table[index];
    while (liste_actuelle != NULL) {
        if (strcmp(liste_actuelle->Nom, nom) == 0) {
            return liste_actuelle;
        }
        liste_actuelle = liste_actuelle->Suivant;
    }
    return NULL;
}

// fonction pour afficher la table de hachage
void afficher_table(TableHachage table) {
    for (int i = 0; i < table.taille; i++) {
        printf("[%d]: ", i);
        Liste liste_actuelle = table.table[i];
        while (liste_actuelle != NULL) {
                 if(liste_actuelle->type==0){
                     printf("(Nom:%s,Nature:%d,Type:%d,valeur:%d) ", liste_actuelle->Nom, liste_actuelle->nature,liste_actuelle->type,liste_actuelle->valeur.entier);
                }else if(liste_actuelle->type==1){
                    printf("(Nom:%s,Nature:%d,Type:%d,valeur:%.02f) ", liste_actuelle->Nom, liste_actuelle->nature,liste_actuelle->type,liste_actuelle->valeur.real);
                }
           
            liste_actuelle = liste_actuelle->Suivant;
        }
        printf("\n");
    }
}
void transformer_tsToth( Liste ts,TableHachage th){

    while(ts!=NULL)
    {
        ajouter_noeud(ts->Nom, ts->nature,ts->valeur,ts->type,&th);  
        ts=ts->Suivant;
 
    }
     
   
}
/*
}
int main() {
    TableHachage table = init_table(TAILLE_TABLE);

    // ajouter des noeuds dans la table de hachage
    multi_val2 valeur1 = {10, 3.14, 1, "hello"};
    ajouter_noeud("variable1", 1, valeur1, 1, &table);  
    ajouter_noeud("variable12", 1, valeur1, 1, &table);
    multi_val2 valeur2 = {20, 6.28, 2, "world"};
    ajouter_noeud("variable2", 1, valeur2, 1, &table);

    // afficher la
    afficher_table(table);
}*/