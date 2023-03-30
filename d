%{
#include<stdio.h>
#include "bib.h"
extern int ligne;
extern int col;
int yyparse();
int yylex();
int yyerror(char *s);
 
Liste lisElts;
int typeidf,nature;
multi_val2 val2;
float x;
%}

%union {
int num;
char* str;
float flt ;
struct{
  int entier;
  float reel;
  int type;
}col;
}   
%start S
%token  pvar aff pcode pstruct pif pelse pfor pwhile pconst padd psous pmul pint pfloat pdiv ')' '(' '[' ']' '}' '{' ',' ';' eq psup psupEgal pinf pinfEgal pequal pnotequal ou et negation
%token <str>idf 
%token <num>entier
%token <flt>reel
%type <col>expr
%left ou
%left et
%left negation
%left  padd psous
%left  pmul pdiv 
%left psup psupEgal pequal pinf pinfEgal
%%
S: idf '{' pvar '{' partiedec '}' pcode '{' partieinst '}' '}' { printf ("programme syntaxiquement juste"); YYACCEPT ;};

type : pint {typeidf=0;}|pfloat {typeidf=1;}
;
partiedec:type listvariable ';'{remplire(&lisElts,0,typeidf);}   
            |pconst type listvariable eq entier ';' {remplire(&lisElts,0,typeidf);}|
            pconst type listvariable eq reel ';'{remplire(&lisElts,1,typeidf);}|
            partiedec pconst type listvariable  eq entier';'{remplire(&lisElts,1,typeidf);}|
            partiedec pconst type listvariable eq reel';'{remplire(&lisElts,1,typeidf);}
            ;
 
listvariable:idf {inserer($1);}|idf ',' listvariable {inserer($1);}
partieinst:x|x partieinst;
x:inst|instiwf;

inst:instaff ';';
instaff:idf aff expr {remplire_cont_idf(&lisElts,$1,val2);non_dec(&lisElts,$1);};

expr :  expr  padd  expr{
        if($1.type==0 && $3.type==0){$$.type=0; $$.entier=$1.entier+$3.entier;val2.entier=$$.entier;}
        if($1.type==1 && $3.type==1){$$.type=1; $$.reel=$1.reel+$3.reel;val2.real=$$.reel;}}|
        expr  psous expr{   
         if($1.type==0 && $3.type==0){$$.type=0; $$.entier=$1.entier-$3.entier;val2.entier=$$.entier;}
         if($1.type==1 && $3.type==1){$$.type=1; $$.reel=$1.reel-$3.reel;val2.real=$$.reel;}}|
        expr  pmul  expr{    
        if($1.type==0 && $3.type==0){$$.type=0; $$.entier=$1.entier*$3.entier;val2.entier=$$.entier;}
        if($1.type==0 && $3.type==1){$$.type=1; $$.reel=$1.reel*$3.reel;val2.real=$$.reel;}
        if($1.type==1 && $3.type==0){printf("Erreur semantique:TYPE a la ligne [%d] et a la colonne [%d]\n\n",ligne,col);exit(-1);}  
        if($1.type==1 && $3.type==1){$$.type=1; $$.reel=$1.reel*$3.reel;val2.real=$$.reel;}}|
        expr  pdiv  expr{
         if( $3.type==0){
             if($3.entier==0){printf("Erreur semantique: Division par zero  a la ligne [%d] et a la colonne [%d]\n\n",ligne,col);exit(-1);} 
             else{$$.type=0; $$.entier=$1.entier / $3.entier;val2.entier=$$.entier;}
        }
         if( $1.type==1 && ($3.type==1||$3.type==0)){
                if($3.reel==0){printf("Erreur semantique: Division par zero  a la ligne [%d] et a la colonne [%d]\n\n",ligne,col);exit(-1);} 
                else{$$.type=1; $$.reel=$1.reel / $3.reel;val2.real=$$.reel;}}
        if( $1.type==1 && ($3.type==0)){
                if($3.reel==0){printf("Erreur semantique: Division par zero  a la ligne [%d] et a la colonne [%d]\n\n",ligne,col);exit(-1);} 
                else{$$.type=1; $$.reel=$1.reel / $3.reel;val2.real=$$.reel;}}
        }|
        reel {$$.reel=$1;$$.type=1; val2.real=$1;val2.type=1;}|
        entier {$$.entier=$1;$$.type=0;val2.entier=$1;val2.type=0;}|
        idf  {strcpy(val2.chaine,$1); }
        
;



instiwf:instif|instw|instfor;

instfor:pfor '(' idf ':' entier ':' entier ':' condarret ')' '{' partieinst '}';
condarret:idf|entier;

instif:pif '(' cond ')' '{' partieinst '}' |pif '('cond')''{' partieinst '}'pelse '{' partieinst '}';

cond:idf c expr|idf c expr ou cond|idf c expr et cond |negation cond
;
c: psup | psupEgal |pequal| pinf | pinfEgal|pnotequal
;

instw:pwhile '(' cond ')' '{' partieinst '}';


%%
int yyerror(char* msg)
{printf("%s ligne %d et colonne %d",msg,ligne,col);
return 0;
}
int main()  {  
yyparse();
afficheidf(); 
affiche(lisElts); 
return 0;  
} 
