%{
#include<stdio.h>
#include "bib.h"
#include "hash_table.c"
#include "quad.c"
//quadruple variable
int deb_else=0;
int deb_if=0;
int qc=0;
 
int Fin_if=0;
int finInst1=0;
int finInst2=0;

char tmp [20];
char tmp2 [20];
char res [1000];
char* cond_arret;
//table de hashage variable
#define TAILLE_TABLE 100
TableHachage th;
Liste lisElts;
int typeidf,nature;
multi_val2 val2;
float x;

//bison variable
extern int ligne;
extern int col;
int yyparse();
int yylex();
int yyerror(char *s);
extern FILE* yyin;

%}

%union {
char* operCond;
int num;
char* str;
float flt ;
struct{
int entier;
float reel;
int type;
char* name;
}Col;
}   
%start S
%token  pvar aff pcode pstruct pif pelse pfor pwhile pconst padd psous pmul pint pfloat pdiv ')' '(' '[' ']' '}' '{' ',' ';'   psup psupEgal pinf pinfEgal pequal pnotequal ou et negation
%token <str>idf 
%token <num>entier
%token <flt>reel
%type <Col>expr
%type <operCond>cn c
%left ou
%left et
%left negation
%left  padd psous
%left  pmul pdiv 
%left psup psupEgal pequal pinf pinfEgal
%%
S: idf '{' pvar '{' PARTIEDEC '}' pcode '{' PARTIEINST '}' '}' { printf ("programme syntaxiquement juste"); YYACCEPT ;};


PARTIEDEC: PARTIEDEC pint LISTEVARIABLE ';' {remplire(&lisElts,0,0,0);}|
           PARTIEDEC pfloat LISTEVARIABLE ';' {remplire(&lisElts,0,1,0);}|
           PARTIEDEC pconst pint LISTEVARIABLE aff entier ';' {remplire(&lisElts,1,0,$6);}|
           PARTIEDEC pconst pfloat LISTEVARIABLE aff reel ';' {remplire(&lisElts,1,1,$6);}| 
            PARTIEDEC STRUCTURE 
            |
           
            ;
STRUCTURE: pstruct '{' PARTIEDEC '}' idf ';'
	        ;
LISTEVARIABLE:idf {inserer($1);}|idf ',' LISTEVARIABLE {inserer($1);}|idf '[' entier ']'{inserer($1);}

PARTIEINST:x|x PARTIEINST;
x:inst|INSTIWF;

inst:instaff ';';
instaff:idf aff expr{
        remplire_cont_idf(&lisElts,$1,val2);non_dec(&lisElts,$1); 
        if($3.name==NULL){
                if($3.type==0){
                        
                        sprintf(tmp,"%d",$3.entier);
                        quadr("=",tmp,"vide",$1);
                }
                else if($3.type==1){
                         
                        sprintf(tmp,"%.02f",$3.reel);
                        quadr("=",tmp,"vide",$1);    
                        }
                        else{
                                 
                                quadr("=",$3.name,"vide",$1);        
                        }

                }else{
                        /*
                val2=return_value(&lisElts,$3.name);
                if(val2.type==0){
                        printf("1em2");
                        printf("%d",val2.entier);
                        sprintf(tmp,"%d",val2.entier);
                        quadr("=",tmp,"vide",$1);
                }
                else if(val2.type==1){
                        printf("2em2");
                        sprintf(tmp,"%.02f",val2.real);
                        quadr("=",tmp,"vide",$1);    
                        }
                   */  
                    quadr("=",$3.name,"vide",$1);  
                }
        }
        ;


expr :  expr  padd  expr {
        if($1.name==NULL && $3.name==NULL){
                sprintf(res,"T%d\0", qc);
                if($1.type==0 && $3.type==0){
                        $$.type = 0;
                        sprintf(tmp,"%d", $1);
                        sprintf(tmp2,"%d", $3);
                        quadr("+",tmp,tmp2,res);
                }else{
                      
                        $$.type = 1;
                        sprintf(tmp,"%.02f", $1);
                        sprintf(tmp2,"%.02f", $3);
                        quadr("+",tmp,tmp2,res); 
                }
                printf("%s",res);
                $$.name = (char*) malloc(20);
                strcpy($$.name,res);
                 
        }else   if($1.name==NULL){
                        sprintf(res,"T%d", qc);
                        if($1.type==0){
                        sprintf(tmp,"%d", $1);
                        quadr("+",$3.name,tmp,res); 
                        }else{
                        sprintf(tmp,"%.02f", $3);
                        quadr("+",$3.name,tmp,res); 
                        }
                        strcpy($$.name,res);
                }else if($3.name==NULL){
                         
                        sprintf(res,"T%d", qc);
                        if($3.type==0){
                        sprintf(tmp,"%d",$3);
                        quadr("+",tmp,$1.name,res); 
                        }else{
                        sprintf(tmp,"%.02f", $3);
                        quadr("+",tmp,$1.name,res); 
                        }  
                        strcpy($$.name,res);
                }

       // strcpy($$.name, tmp);
        }
        |expr psous expr {
        if($1.name==NULL && $3.name==NULL){
                sprintf(res,"T%d", qc);
                if($1.type==0 && $1.type==0){
                        $$.type = 0; // initialiser le type de la nouvelle expression à entier
                        
                        sprintf(tmp,"%d", $1.entier);
                        sprintf(tmp2,"%d", $3.entier);
                        quadr("-",tmp,tmp2,res);
                }else{
                        $$.type = 1; // initialiser le type de la nouvelle expression à entier
                        
                        sprintf(tmp,"%.02f", $1.reel);
                        sprintf(tmp2,"%.02f", $3.reel);
                        quadr("-",tmp,tmp2,res); 
                }
                              
                $$.name = (char*) malloc(20);
                strcpy($$.name,res);  
        }else   if($1.name==NULL){
                        sprintf(res,"T%d", qc);
                        if($1.type==0){
                        sprintf(tmp,"%d", $1);
                        quadr("-",$3.name,tmp,res); 
                        }else{
                        sprintf(tmp,"%.02f", $3);
                        quadr("-",$3.name,tmp,res); 
                        }
                        strcpy($$.name,res);
                }else if($3.name==NULL){
                         
                        sprintf(res,"T%d", qc);
                        if($3.type==0){
                        sprintf(tmp,"%d",$3);
                        quadr("-",tmp,$1.name,res); 
                        }else{
                        sprintf(tmp,"%.02f", $3);
                        quadr("-",tmp,$1.name,res); 
                        }  
                        strcpy($$.name,res);
                }

        }
        |expr pmul expr {
        if($1.name==NULL && $3.name==NULL){
                sprintf(res,"T%d", qc);
                if($1.type==0 && $1.type==0){
                        $$.type = 0; // initialiser le type de la nouvelle expression à entier
                        sprintf(res,"%d", qc);
                        sprintf(tmp,"%d", $1.entier);
                        sprintf(tmp2,"%d", $3.entier);
                        quadr("*",tmp,tmp2,res);
                }else{
                        $$.type = 1; // initialiser le type de la nouvelle expression à entier
                         
                        sprintf(tmp,"%.02f", $1.reel);
                        sprintf(tmp2,"%.02f", $3.reel);
                        quadr("*",tmp,tmp2,res); 
                }
                $$.name = (char*) malloc(20);
                strcpy($$.name,res);  
        }else   if($1.name==NULL){
                        sprintf(res,"T%d", qc);
                        if($1.type==0){
                        sprintf(tmp,"%d", $1);
                        quadr("*",$3.name,tmp,res); 
                        }else{
                        sprintf(tmp,"%.02f", $3);
                        quadr("*",$3.name,tmp,res); 
                        }
                        strcpy($$.name,res);
                }else if($3.name==NULL){
                         
                        sprintf(res,"T%d", qc);
                        if($3.type==0){
                        sprintf(tmp,"%d",$3);
                        quadr("*",tmp,$1.name,res); 
                        }else{
                        sprintf(tmp,"%.02f", $3);
                        quadr("*",tmp,$1.name,res); 
                        }  
                        strcpy($$.name,res);
                }

        }
        | expr pdiv expr {
                  printf("%d alger%d",$1.type,$3.entier);

        if($1.type!=$3.type){
           printf("Erreur semantique: Incompatibilite Type  a la ligne [%d] et a la colonne [%d]\n\n",ligne,col);exit(-1);     
        }
    
        if($3.entier!=0 || $3.reel!=0){
                if($1.name==NULL && $3.name==NULL){
                
                                sprintf(res,"T%d", qc);
                                if($1.type==0 && $1.type==0){
                                        $$.type = 0; // initialiser le type de la nouvelle expression à entier
                                        sprintf(tmp,"%d", $1.entier);
                                        sprintf(tmp2,"%d", $3.entier);
                                        quadr("/",tmp,tmp2,res);  
                                }else{
                                        $$.type = 1; // initialiser le type de la nouvelle expression à entier
                                        sprintf(tmp,"%.02f", $1.reel);
                                        sprintf(tmp2,"%.02f", $3.reel);
                                        printf("%s",tmp);
                                        quadr("/",tmp,tmp2,res); 
                                }  
                                $$.name = (char*) malloc(20);
                                strcpy($$.name,res);        
                }else   if($1.name==NULL){
                                sprintf(res,"T%d", qc);
                                if($1.type==0){
                                sprintf(tmp,"%d", $1);
                                quadr("/",$3.name,tmp,res); 
                                }else{
                                sprintf(tmp,"%.02f", $3);
                                quadr("/",$3.name,tmp,res); 
                                }
                                strcpy($$.name,res);
                        }else if($3.name==NULL){     
                                sprintf(res,"T%d", qc);
                                if($3.type==0){
                                sprintf(tmp,"%d",$3);
                                quadr("/",tmp,$1.name,res); 
                                }else{
                                sprintf(tmp,"%.02f", $3);
                                quadr("/",tmp,$1.name,res); 
                                }  
                                strcpy($$.name,res);
                        }
        }else{printf("Erreur semantique: Division par zero  a la ligne [%d] et a la colonne [%d]\n\n",ligne,col);exit(-1);} 
        }
        | '(' expr ')' {$$ = $2;}
        | idf {$$.name = strdup($1);}
        | entier {
                $$.type = 0; // initialiser le type de la nouvelle expression à entier
                $$.entier=$1;
                
                
        }
        | reel {
                $$.type = 1; // initialiser le type de la nouvelle expression à réel
                  $$.reel=$1;
                  
        };



INSTIWF:INSTIF|INSTW|INSTFOR;

INSTFOR:pfor '(' idf ':' entier ':' entier ':' cond_arret ')' '{' PARTIEINST '}'
        /*{
        int debut_boucle = qc; // sauvegarder l'indice du début de la boucle
        char temp_cond[20];
        sprintf(temp_cond, "temp_cond_%d", qc); // créer une variable temporaire pour la condition de boucle
        quadr(":=", $5, "", $1); // initialiser la variable de boucle
        quadr("LABEL", "", "", temp_cond); // étiquette pour la condition de boucle
        quadr("<=", $1, $6, ""); // vérifier la condition de boucle
        int saut_fin_boucle = qc; // sauvegarder l'indice pour le saut à la fin de la boucle
        quadr("BRF", temp_cond, "", ""); // saut à la fin de la boucle si la condition est fausse
       
        quadr("+", $1, $5, $1); // incrémenter la variable de boucle
        quadr("BR", "", "", temp_cond); // saut au début de la boucle
        quadr("LABEL", "", "", ""); // étiquette pour la fin de la boucle
        ajour_quad(saut_fin_boucle, 4, itoa(qc)); // mettre à jour le saut à la fin de la boucle
        jour_quad(fin_boucle, 1, qc); // Mettre à jour le saut à la fin de boucle
        }  */  
        ;
cond_arret:idf|entier;

INSTIF: Bif      {
        sprintf(tmp,"%d",qc); 
        ajour_quad(finInst1,2,tmp);
        

        sprintf(tmp2,"%d",qc);
        finInst2=qc; 
        ajour_quad(deb_if,2,tmp2);
        quadr("FIN", "vide","vide","vide"); 
        }
        |Bif pelse '{' PARTIEINST '}'
        {

        sprintf(tmp,"%d",qc); 
        ajour_quad(finInst1,2,tmp);

        sprintf(tmp2,"%d",qc);
        finInst2=qc; 
        ajour_quad(deb_if,2,tmp2);
        quadr("FIN", "vide","vide","vide"); 

        }
        ;
Bif:Aif '{' PARTIEINST '}'
        {     
        finInst1=qc; 
        quadr("BR", "","vide","vide"); 
        sprintf(tmp,"%d",qc); // transformer entier vers string
        ajour_quad(deb_if,2,tmp);
        }
        ;
Aif:pif '(' cond ')' 
        {
       // J'ai laisser le champs 2 vide. Je dois le remplir apres
         
        }
        ;
cond:   expr cn expr {
         deb_if=qc; 
         quadr($2,"","temp_cond","vide"); 
  
        } 
        |cond1 ou cond{
        sprintf(tmp,"%d",qc); 
         ajour_quad(deb_if_ou,2,tmp) ;
        }
        |expr et cond 
        |negation cond
;
cond1:expr c expr{
         deb_if_ou=qc; 
         quadr($2,"","temp_cond","vide"); 
        } 
;
cn:psup {strcpy($$,"BLE");}|psupEgal {strcpy($$,"BL");} |pequal {strcpy($$,"BNE")}|pinf {strcpy($$,"BGE")}|pinfEgal{strcpy($$,"BG")}|pnotequal{strcpy($$,"BE")} 
;
c:psup {strcpy($$,"BG");}|psupEgal {strcpy($$,"BGE");} |pequal {strcpy($$,"BE")}|pinf {strcpy($$,"BL")}|pinfEgal{strcpy($$,"BLE")}|pnotequal{strcpy($$,"BNE")} 
;

INSTW:pwhile '(' cond ')' '{' PARTIEINST '}';


%%
int yyerror(char* msg)
{printf("%s ligne %d et colonne %d",msg,ligne,col);
return 0;
}
int main()  {  
yyin = fopen("test.txt", "r");
yyparse();
//afficheidf(); 
//liste
affiche(lisElts); 
th = init_table(TAILLE_TABLE);
transformer_tsToth(lisElts,th);
//afficher_table(th);
//Quadruple
affich_quad();
fclose (yyin);
return 0;  
} 
