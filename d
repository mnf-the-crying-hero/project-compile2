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
quadruplet* optimize_quads(quadruplet* quads,int num_quads) {
      printf("%d",num_quads);
    
    int optimized = 1;
    while (optimized) {
        optimized = 0;
        for (int i = 0; i < num_quads; i++) {
              
            quadruplet* q1 = &quads[i];
            for (int j = i+1; j < num_quads; j++) {
                
                quadruplet* q2 = &quads[j];
                // Propagation de copie
                if (strcmp(q1->op, "=") == 0 && strcmp(q1->arg1, q2->res) == 0) {
                  printf("propagation copie");
                    strcpy(q2->res, q1->res);
                    optimized = 1;
                }
                // Propagation d'expression
                else if (strcmp(q1->op, q2->op) == 0 && strcmp(q1->arg1, q2->arg1) == 0
                    && strcmp(q1->arg2, q2->arg2) == 0) {
                  printf("Propagation d'expression");

                    strcpy(q2->res, q1->res);
                    optimized = 1;
                }
                // Élimination d'expressions redondantes
                else if (strcmp(q1->res, q2->arg1) == 0 && strcmp(q1->op, q2->op) == 0) {
                    strcpy(q2->arg1, q1->res);
                    printf("Élimination d'expressions redondantes");
                    
                    optimized = 1;
                }
                // Simplification algébrique
                else if (strcmp(q1->op, "+") == 0 && strcmp(q1->arg1, "0") == 0) {
                    printf("Simplification algébrique");

                    strcpy(q1->res, q1->arg2);
                    strcpy(q2->arg1, q1->res);
                    optimized = 1;
                }
                // Élimination de code inutile
                else if (strcmp(q1->res, q2->arg1) == 0 && strcmp(q1->op, "=") == 0
                    && strcmp(q2->op, "=") == 0) {
                    printf("Élimination de code inutile");

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
    printf("sortir");
    return quads;
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

