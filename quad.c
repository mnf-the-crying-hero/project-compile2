#define MAX_QUADS 1000
#include <stdlib.h>
 
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
