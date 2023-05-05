#define MAX_QUADS 1000
#include <stdlib.h>
#include "ctype.h"
typedef struct quadruplet {
  char op[20];
  char arg1[20];
  char arg2[20];
  char res[20];
} quadruplet;

quadruplet quadruplets[MAX_QUADS];
 
extern int qc;
void quadr(char *op, char *arg1, char *arg2, char *res) {

  if (qc >= MAX_QUADS) {
    printf("Erreur : capacité de quadruplets dépassée.\n");
    exit(EXIT_FAILURE);
  }
  
  strcpy(quadruplets[qc].op, op);
  strcpy(quadruplets[qc].arg1, arg1);
  strcpy(quadruplets[qc].arg2, arg2);
  strcpy(quadruplets[qc].res, res);
  qc++;
}

void ajour_quad(int ligne, int champ, char *val) {
  switch (champ) {
    case 1:
      strcpy(quadruplets[ligne].op, val);
      break;
    case 2:
      strcpy(quadruplets[ligne].arg1, val);
      break;
    case 3:
      strcpy(quadruplets[ligne].arg2, val);
      break;
    case 4:
      strcpy(quadruplets[ligne].res, val);
      break;
    default:
      printf("Erreur : champ de quadruplet invalide.\n");
      exit(EXIT_FAILURE);
  }
}
void affich_quad(){
    for (int i = 0; i < sizeof(quadruplets) / sizeof(quadruplets[0]); i++){
        if(strcmp(quadruplets[i].op, "") != 0 || 
        strcmp(quadruplets[i].arg1, "") != 0 || 
        strcmp(quadruplets[i].arg2, "") != 0 || 
        strcmp(quadruplets[i].res, "") != 0) {
        printf("\n %d - ( %s , %s , %s , %s )",i,quadruplets[i].op,quadruplets[i].arg1,quadruplets[i].arg2,quadruplets[i].res); 
        }
    }
}
int checkIfChange(quadruplet* quads,int num_quads,int indice_actuel){
  int changed = 0;
  quadruplet* q1 = &quads[indice_actuel];
  int i ;
    for (i= indice_actuel+1; i < num_quads; i++) {
       quadruplet* q2 = &quads[i];
      if (isalpha(q1->arg1[0])){
        if(strcmp(q1->arg1,q2->res) && strcmp(q2->op,"=")){
          return 1;
        }
      }else if (isalpha(q1->arg2[0])){
        if(strcmp(q1->arg2,q2->res) && strcmp(q2->op,"=")){
          return 1;
        }
      }
  }
  if(i==num_quads-1){
     return 0;
  }else{
    return -1;
  }
 
}
void  Simplify(quadruplet* q1,int indice){
  char res[20];
  char resb[20];
  char savet[20];
  strcpy(savet,q1->res);
   
  
  if(isalpha(q1->arg1[0])){
     quadruplet save[MAX_QUADS];
    // copier les valeurs de quadruplets dans save
    for (int i = 0; i < qc; i++){
        save[i] = quadruplets[i];
    }
 
    int max=atoi(q1->arg2);
     sprintf(resb,"%s%d",q1->res,0);
      
      strcpy(quadruplets[indice].op, "+");
      strcpy(quadruplets[indice].arg1,q1->arg1);
      strcpy(quadruplets[indice].arg2, q1->arg1);
      strcpy(quadruplets[indice].res, resb);
    for(int i=1;i<max-1;i++){
      sprintf(res,"%s%d",q1->res,i);
      indice++;
      strcpy(quadruplets[indice].op, "+");
      strcpy(quadruplets[indice].arg1, resb);
      strcpy(quadruplets[indice].arg2, q1->arg1);
      strcpy(quadruplets[indice].res, res);
    }



  // modifier les valeurs de quadruplets à partir de l'indice donné
  for(int i=indice;i<qc;i++){
      strcpy(quadruplets[i+max-1].op, save[i].op);
      strcpy(quadruplets[i+max-1].arg1,save[i].arg1);
      strcpy(quadruplets[i+max-1].arg2, save[i].arg2);
      strcpy(quadruplets[i+max-1].res, save[i].res);
  }
      

  }else if(isalpha(q1->arg2[0])){
    int max=atoi(q1->arg2);
    for(int i=0;i<max;i++){
      sprintf(res,"%s%d",q1->res,i);
      quadr("+", q1->arg1, q1->arg1, res);
    }
  }
}

quadruplet* optimize_quads(quadruplet* quads,int num_quads) {
 
    
    int optimized = 1;
    while (optimized) {
        
        for (int i = 0; i < num_quads; i++) {
           optimized = 0;
            quadruplet* q1 = &quads[i];
            for (int j = i+1; j < num_quads; j++) {
                
                quadruplet* q2 = &quads[j];
                // Propagation de copie
                 if (isalpha(q1->arg1[0]) && (strncmp(q1->arg1, "T", 1) != 0) && strcmp(q1->op, "=") == 0) {
                    //check if its variable
                     
                        if(strcmp(q1->arg1, q2->arg1) == 0){
                          printf("propagation copie arg1\n");
                          strcpy(q2->arg1, q1->res);
                          optimized = 1;
                        }else if(strcmp(q1->arg1, q2->arg2) == 0){
                          printf("propagation copie arg2\n");
                          strcpy(q2->arg2, q1->res);
                          optimized = 1;
                        }
                   
                }
                // Propagation d'expression
                  else if (strcmp(q1->op, "=") == 0 && (strncmp(q1->arg1, "T", 1) == 0)) {
                    if (strcmp (q1->res,q2->arg1) ==0){
                    printf("Propagation d'expression arg1\n");
                      strcpy(q2->arg1, q1->arg1);
                      optimized = 1;
                    }else if(strcmp (q1->res,q2->arg2)==0){
                      printf("Propagation d'expression arg2\n");
                      strcpy(q2->arg2, q1->arg1);
                      optimized = 1;
                    }
              
                  }
                // Élimination d'expressions redondantes
                  else if (checkIfChange(quads,num_quads,i)==0 ) {
                      strcpy(q2->arg1, q1->res);
                      printf("Elimination d'expressions redondantes\n");
                      
                      optimized = 1;
                  }
                // Simplification algébrique
                  else if (strcmp(q1->op, "*") == 0 && ((atoi(q1->arg1) && isalpha(q1->arg2[0])) || (atoi(q1->arg2) && isalpha(q1->arg1[0])))) {
                      printf("Simplification algebrique\n");

                      Simplify(q1,i);
                      optimized = 1;
                  }
                // Élimination de code inutile
                else if (strcmp(q1->res, q2->arg1) == 0 && strcmp(q1->op, "=") == 0
                    && strcmp(q2->op, "=") == 0) {
                    printf("Elimination de code inutile");

                    memmove(q2, q2+1, (num_quads-j)*sizeof(quadruplet));
                    num_quads--;
                    j--;
                    optimized = 1;
                }
            }
            
        }
        quads = realloc(quads, num_quads*sizeof(quadruplet));
            printf("\navant sortir");
        
    }
    
    return quads;
}




