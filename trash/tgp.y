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
char tmp [20];
char tmp2 [20];
char res [20];

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
%left ou
%left et
%left negation
%left  padd psous
%left  pmul pdiv 
%left psup psupEgal pequal pinf pinfEgal
%%
S: idf '{' pvar '{' PARTIEDEC '}' pcode '{' PARTIEINST '}' '}' { printf ("programme syntaxiquement juste"); YYACCEPT ;};


PARTIEDEC:  TYPE LISTEVARIABLE ';' PARTIEDEC{remplire(&lisElts,0,typeidf,0);}|
           pconst TYPE LISTEVARIABLE aff entier ';' PARTIEDEC{remplire(&lisElts,1,typeidf,$5);}|
            pconst TYPE LISTEVARIABLE aff reel ';' PARTIEDEC{remplire(&lisElts,1,typeidf,$5);}| 
            STRUCTURE PARTIEDEC
           |
            ;
TYPE : pint {typeidf=0;}|pfloat {typeidf=1;}
;
STRUCTURE: pstruct '{' PARTIEDEC '}' idf ';'
	        ;
LISTEVARIABLE:idf {inserer($1);}|idf ',' LISTEVARIABLE {inserer($1);}|idf '[' entier ']'{inserer($1);}

PARTIEINST:x|x PARTIEINST;
x:inst|INSTIWF;

inst:instaff ';';
instaff:idf aff expr{remplire_cont_idf(&lisElts,$1,val2);non_dec(&lisElts,$1); 

if($3.type==0){
sprintf(tmp,"%d",$3.entier);
quadr("=",tmp,"vide",$1);
}else{
     sprintf(tmp,"%d",$3.reel);
quadr("=",tmp,"vide",$1);    
}
};

expr :  expr  padd  expr{
                       /* if($1.nature != 0 && $1.nature != 1 && $3.nature != 0 && $3.nature){
                        if($1.type==0 && $3.type==0){
                        printf($1.name);
                        sprintf(tmp,"%d",$1);
                        sprintf(tmp2,"%d",$3);
                        sprintf(res,"%d",$$); 
                        quadr("+",tmp,tmp2,res);
                        }
                        if($1.type==1 && $3.type==1){
                        sprintf(tmp,"%d",$1);
                        sprintf(tmp2,"%d",$3);
                        sprintf(res,"%d",$$); 
                        quadr("+",tmp,tmp2,res);
                        }
                        */
                 
                         
                        /*}*/
        }
                   
        |expr  psous expr{   
                        if($1.type==0 && $3.type==0){$$.type=0; $$.entier=$1.entier-$3.entier;val2.entier=$$.entier;}
                        if($1.type==1 && $3.type==1){$$.type=1; $$.reel=$1.reel-$3.reel;val2.real=$$.reel;}
                        }
        |expr  pmul  expr{    
                        if($1.type==0 && $3.type==0){$$.type=0; $$.entier=$1.entier*$3.entier;val2.entier=$$.entier;}
                        if($1.type==0 && $3.type==1){$$.type=1; $$.reel=$1.reel*$3.reel;val2.real=$$.reel;}
                        if($1.type==1 && $3.type==0){printf("Erreur semantique:TYPE a la ligne [%d] et a la colonne [%d]\n\n",ligne,col);exit(-1);}  
                        if($1.type==1 && $3.type==1){$$.type=1; $$.reel=$1.reel*$3.reel;val2.real=$$.reel;}
                        }
        |expr  pdiv  expr{
                        if( $3.type==0){        
                        if($3.entier==0){
                        printf("Erreur semantique: Division par zero  a la ligne [%d] et a la colonne [%d]\n\n",ligne,col);
                        exit(-1);
                        }else{$$.type=0; $$.entier=$1.entier / $3.entier;val2.entier=$$.entier;
                             }
                        }
                        if( $1.type==1 && ($3.type==1||$3.type==0)){
                                if($3.reel==0){
                                printf("Erreur semantique: Division par zero  a la ligne [%d] et a la colonne [%d]\n\n",ligne,col);exit(-1);
                                }else{$$.type=1; $$.reel=$1.reel / $3.reel;val2.real=$$.reel;
                                     }
                        }
                        if( $1.type==1 && ($3.type==0)){
                                if($3.reel==0){printf("Erreur semantique: Division par zero  a la ligne [%d] et a la colonne [%d]\n\n",ligne,col);exit(-1);} 
                                else{$$.type=1; $$.reel=$1.reel / $3.reel;val2.real=$$.reel;}}
                        }
        |reel {
                $$.reel=$1;$$.type=1; val2.real=$1;val2.type=1;
              }
        |entier {
                $$.entier=$1;$$.type=0;val2.entier=$1;val2.type=0;
                }
        |idf  {
                strcpy($$.name,$1); 
               }
        
;



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
        printf("pgm juste")
        }
        |Bif pelse '{' PARTIEINST '}'
        {
        sprintf(tmp,"%d",qc); 
        ajour_quad(finInst1,2,tmp);
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
        deb_if=qc; // J'ai laisser le champs 2 vide. Je dois le remplir apres
        quadr("BZ", "","temp_cond","vide"); 
        }
        ;
cond:idf c expr|idf c expr ou cond|idf c expr et cond |negation cond
;
c: psup | psupEgal |pequal| pinf | pinfEgal|pnotequal
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
expr :  expr  padd  expr{
        if($1.type==0 && $3.type==0){
        $$.type = 0; // initialiser le type de la nouvelle expression à entier
        sprintf(tmp,"%d", qc++);
        quadr("+",$1.name,$3.name,tmp);
        strcpy($$.name, tmp);
        }
        if($1.type==1 && $3.type==1){       
        $$.type = 0; // initialiser le type de la nouvelle expression à entier
        sprintf(tmp,"%d", qc++);
        quadr("+",$1.name,$3.name,tmp);
        strcpy($$.name, tmp);}
        }|
        expr  psous expr{   
         if($1.type==0 && $3.type==0){
                $$.type = 0; // initialiser le type de la nouvelle expression à entier
                sprintf(tmp,"%d", qc++);
                quadr("-",$1.name,$3.name,tmp);
                strcpy($$.name, tmp);
          }
         if($1.type==1 && $3.type==1){   
                $$.type = 0; // initialiser le type de la nouvelle expression à entier
                sprintf(tmp,"%d", qc++);
                quadr("-",$1.name,$3.name,tmp);
                strcpy($$.name, tmp);}
        }|
        expr  pmul  expr{  
         if($1.type==1 || $3.type==1){
                $$.type = 1; // initialiser le type de la nouvelle expression à reel
         } else{
                $$.type = 0; 
         }
        
        sprintf(tmp,"%d", qc++);
        quadr("*",$1.name,$3.name,tmp);
        strcpy($$.name, tmp);}|
        expr  pdiv  expr{
        if( $3.type==0){
             if($3.entier==0){printf("Erreur semantique: Division par zero  a la ligne [%d] et a la colonne [%d]\n\n",ligne,col);exit(-1);} 
             else{$$.type=0; $$.entier=$1.entier / $3.entier;val2.entier=$$.entier;}
        }
        $$.type = 1; // initialiser le type de la nouvelle expression à réel
        sprintf(tmp,"%d", qc++);
        quadr("/",$1.name,$3.name,tmp);
        strcpy($$.name, tmp);
        }|
        reel {    
        $$.type = 1; // initialiser le type de la nouvelle expression à entier
        sprintf(tmp,"%d", qc++);
        sprintf(reel_char,"%.02f",$1);
        quadr("=",reel_char,"vide",tmp);
        strcpy($$.name, tmp);}
        |
        entier {    
        $$.type = 0; // initialiser le type de la nouvelle expression à entier
        sprintf(tmp,"%d", qc++);
        sprintf(entier_char,"%d",$1);
        quadr("=",entier_char,"vide",tmp);
        strcpy($$.name, tmp);}|
        idf  {strcpy(val2.chaine,$1); }
        
;


expr :  expr  padd  expr                 
        |expr  psous expr
        |expr  pmul  expr 
        |expr  pdiv  expr 
        |reel  
        |entier  
        |idf   
        
;
