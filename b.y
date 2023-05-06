%{
#include<stdio.h>
#include "bib.h"
#include <math.h>
#include "hash_table.c"
#include "quad.c"
//quadruple variable
int deb_else=0;
int deb_if=0;
int qc=0;

int Fin_if=0;
int finInst1=0;
int finInst2=0;
int save_bz=0;
int save_bg=0;
int deb_while=0;
int deb_for=0;
noeud* p;
char savetab [20];
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
%type <Col>expr Ainstfor Binstfor cond_arret Cinstfor
%type <operCond> c  
 
 
%left ou
%left et
%left negation
%left  padd psous
%left  pmul pdiv 
%left psup psupEgal pequal pinf pinfEgal
%%
S: idf '{' pvar '{' PARTIEDEC '}'{th = init_table(TAILLE_TABLE);transformer_tsToth(lisElts,th);} pcode '{' PARTIEINST '}' '}' { printf ("programme syntaxiquement juste"); YYACCEPT ;};


PARTIEDEC: PARTIEDEC pint LISTEVARIABLE ';' {remplire(&lisElts,0,0,0);}|
           PARTIEDEC pfloat LISTEVARIABLE ';' {remplire(&lisElts,0,1,0);}|
           PARTIEDEC pconst pint LISTEVARIABLE aff entier ';' {remplire(&lisElts,1,0,$6);}|
           PARTIEDEC pconst pfloat LISTEVARIABLE aff reel ';' {remplire(&lisElts,1,1,$6);}| 
            PARTIEDEC STRUCTURE 
            |
           
            ;
STRUCTURE: pstruct '{' PARTIEDEC '}' idf ';'
	        ;
LISTEVARIABLE:idf {inserer($1);}|idf ',' LISTEVARIABLE {inserer($1);}|idf '[' entier ']'{sprintf(savetab,"%s[%d]",$1,$3); inserer(savetab);}

PARTIEINST:x|x PARTIEINST;
x:inst|INSTIWF;

inst:instaff ';';
instaff:idf aff expr{
        //printf("%d=%d",recherche_type(&lisElts,$1),$3.type);
        remplire_cont_idf(&lisElts,$1,val2);non_dec(&lisElts,$1); 
        if(recherche_type(&lisElts,$1)!=$3.type){
           printf("Erreur semantique: Incompatibilite Type  a la ligne [%d] et a la colonne [%d]\n\n",ligne,col);exit(-1);     
        }
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
       
        sprintf(res,"T%d", qc);
        if($1.name==NULL && $3.name==NULL){
               
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
                //printf("%s",res);
             
                 
        }else   if($1.name==NULL){
                        
                        
                        if($1.type==0){
                        sprintf(tmp,"%d", $1);
                        quadr("+",tmp,$3.name,res); 
                        }else{
                        sprintf(tmp,"%.02f", $3);
                        quadr("+",tmp,$3.name,res); 
                        }
                      
                     
                }else if($3.name==NULL){
                       
                       
                        if($3.type==0){
                        sprintf(tmp,"%d",$3);
                        quadr("+",$1.name,tmp,res); 
                        }else{
                        sprintf(tmp,"%.02f", $3);
                        quadr("+",$1.name,tmp,res); 
                        }  
                        $$.name = (char*) malloc(20);
                       
                }else{
                        
                        quadr("+",$1.name,$3.name,res); 
                }
                $$.name = (char*) malloc(20);
                strcpy($$.name,res);
             

       // strcpy($$.name, tmp);
        }
        |expr psous expr {
     
                sprintf(res,"T%d", qc);
                if($1.name==NULL && $3.name==NULL){
                
                        if($1.type==0 && $3.type==0){
                                $$.type = 0; // initialiser le type de la nouvelle expression à entier
                                
                                sprintf(tmp,"%d", $1.entier);
                                sprintf(tmp2,"%d", $3.entier);
                                quadr("-",tmp,tmp2,res);
                        }else if($1.type==1 && $3.type==1){
                                $$.type = 1; // initialiser le type de la nouvelle expression à entier
                                
                                sprintf(tmp,"%.02f", $1.reel);
                                sprintf(tmp2,"%.02f", $3.reel);
                                quadr("-",tmp,tmp2,res); 
                        }else if($1.type==0 && $3.type==1){
                                $$.type = 1; 
                                 
                                sprintf(tmp,"%d", $1.entier);
                                sprintf(tmp2,"%.02f", $3.reel);
                                quadr("-",tmp,tmp2,res);
                        }else if($1.type==1 && $3.type==0){
                                $$.type = 1; 
                               
                                sprintf(tmp,"%.02f", $1.reel);
                                sprintf(tmp2,"%d", $3.entier);
                                quadr("-",tmp,tmp2,res);
                        }
                                
                
                }else   if($1.name==NULL){
                        
                                if($1.type==0){
                                sprintf(tmp,"%d", $1);
                                quadr("-",tmp,$3.name,res); 
                                }else{
                                sprintf(tmp,"%.02f", $3);
                                quadr("-",tmp,$3.name,res); 
                                }
                                $$.name = (char*) malloc(20);
                                strcpy($$.name,res);
                        }else if($3.name==NULL){
                                
                        
                                if($3.type==0){
                                sprintf(tmp,"%d",$3);
                                quadr("-",$1.name,tmp,res); 
                                }else{
                                sprintf(tmp,"%.02f", $3);
                                quadr("-",$1.name,tmp,res); 
                                }  
                                $$.name = (char*) malloc(20);
                                strcpy($$.name,res);
                        }else{
                        
                                quadr("-",$1.name,$3.name,res); 
                        }
                        $$.name = (char*) malloc(20);
                        strcpy($$.name,res); 

                }
        |expr pmul expr {
                if($1.type!=$3.type){
                printf("Erreur semantique: Incompatibilite Type  a la ligne [%d] et a la colonne [%d]\n\n",ligne,col);exit(-1);     
                }
                sprintf(res,"T%d", qc);
                if($1.name==NULL && $3.name==NULL){
                        
                        if($1.type==0 && $1.type==0){
                                $$.type = 0; // initialiser le type de la nouvelle expression à entier
                                
                                sprintf(tmp,"%d", $1.entier);
                                sprintf(tmp2,"%d", $3.entier);
                                quadr("*",tmp,tmp2,res);
                        }else{
                                $$.type = 1; // initialiser le type de la nouvelle expression à entier
                                
                                sprintf(tmp,"%.02f", $1.reel);
                                sprintf(tmp2,"%.02f", $3.reel);
                                quadr("*",tmp,tmp2,res); 
                        }
                        
                
                }else   if($1.name==NULL){
                                
                                if($1.type==0){
                                sprintf(tmp,"%d", $1);
                                quadr("*",tmp,$3.name,res); 
                                }else{
                                sprintf(tmp,"%.02f", $3);
                                quadr("*",tmp,$3.name,res); 
                                }
                        
                        }else if($3.name==NULL){
                                
                                
                                if($3.type==0){
                                sprintf(tmp,"%d",$3);
                                quadr("*",$1.name,tmp,res); 
                                }else{
                                sprintf(tmp,"%.02f", $3);
                                quadr("*",$1.name,tmp,res); 
                                }  
                                
                        }else{
                                
                                quadr("*",$1.name,$3.name,res);   
                        }
                        $$.name = (char*) malloc(20);
                        strcpy($$.name,res);

                }
        | expr pdiv expr {
        //printf("%d div %d",$1.type,$3.entier);

        /*if($1.type!=$3.type){
           printf("Erreur semantique: Incompatibilite Type  a la ligne [%d] et a la colonne [%d]\n\n",ligne,col);exit(-1);     
        }*/
        sprintf(res,"T%d", qc);
        if($3.entier!=0 || $3.reel!=0){
                $$.type = 1;
                if($1.name==NULL && $3.name==NULL){
                
                                         
                                if($1.type==0 && $1.type==0){
                                        if($1.entier%$3.entier==0){
                                                $$.type = 0; // initialiser le type de la nouvelle expression à entier
                                        }
                                        sprintf(tmp,"%d", $1.entier);
                                        sprintf(tmp2,"%d", $3.entier);
                                        quadr("/",tmp,tmp2,res);  
                                }else{
                                        int a = round($1.reel * 100);    
                                        int b = round($3.reel* 100);    
                                        if (a % b == 0) {
                                          $$.type = 0;
                                        }

                                      
                                        sprintf(tmp,"%.02f", $1.reel);
                                        sprintf(tmp2,"%.02f", $3.reel);
                                        //printf("%s",tmp);
                                        quadr("/",tmp,tmp2,res); 
                                }  
                                   
                }else   if($1.name==NULL){
                                 
                                if($1.type==0){
                                
                                sprintf(tmp,"%d", $1);
                                quadr("/",tmp,$3.name,res); 
                                }else{
                                sprintf(tmp,"%.02f", $1);
                                quadr("/",tmp,$3.name,res); 
                                }
                                
                        }else if($3.name==NULL){     
                                 
                                if($3.type==0){
                                sprintf(tmp,"%d",$3);
                                quadr("/",$1.name,tmp,res); 
                                }else{
                                sprintf(tmp,"%.02f", $3);
                                quadr("/",$1.name,tmp,res); 
                                }  
                                 
                        }else{
                             quadr("/",$1.name,$3.name,res);     
                        }
                $$.name = (char*) malloc(20);
                strcpy($$.name,res);
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
                  
        } 
;

INSTIWF:INSTIF|INSTW|INSTFOR;

cond_arret:idf {$$.name=$1}|entier{$$.entier=$1};
INSTFOR:Dinstfor ')' '{' PARTIEINST '}'
        {       sprintf(tmp,"%d", deb_for);
                quadr("BR",tmp,"vide","vide"); 
                sprintf(tmp2,"%d", qc);
                ajour_quad(save_bg,2,tmp2);
        }
;
Dinstfor:Cinstfor':' cond_arret{
        save_bg=qc;
        sprintf(tmp,"T%d", qc);
        if($3.name==NULL){
                sprintf(tmp2,"%d", $3.entier);
                quadr("BG","",$1.name,tmp2);
        }else{
               
                quadr("BG","",$1.name,$3.name);
        }
    
        

}
;
Cinstfor:Binstfor':' entier{
        deb_for=qc;
        sprintf(res,"T%d", qc);
        sprintf(tmp,"%d", $3);
        quadr("+",tmp,$1.name,res);
        strcpy($$.name,res);
}
;
Binstfor:Ainstfor ':' entier{
     if($1.type!=0){
        printf("Error Symantique:%s pas compatible la ligne [%d] et a la colonne [%d]\n",$1.name,ligne,col);exit(-1);
     }else{
        sprintf(tmp,"%d",$3); 
        quadr("=",tmp,"vide",$1.name);
        strcpy($$.name,$1.name);
     } 
}
;
Ainstfor:pfor '(' idf {
        //printf("ddd%s",$3);
        //printf("dd%lu",th);
        p=lookup($3,th);
     
        if(p==NULL){
                printf("Error Symantique:%s non declareea la ligne [%d] et a la colonne [%d]\n",$3,ligne,col);exit(-1);
        }else{

                $$.type=p->type;
                $$.name=$3;
                //printf($$.name);
               
        }
        }
;


INSTIF: Bif {
        sprintf(tmp,"%d",qc); 
        ajour_quad(finInst1,2,tmp);
        

        sprintf(tmp2,"%d",qc);
        finInst2=qc; 
        ajour_quad(deb_if,2,tmp2);
        
        }
        |Bifelse pelse '{' PARTIEINST '}'
        {

        sprintf(tmp,"%d",qc); 
        ajour_quad(finInst1,2,tmp);

        sprintf(tmp2,"%d",qc);
        /*finInst2=qc; 
        ajour_quad(deb_if,2,tmp2);*/
        //quadr("FIN", "vide","vide","vide"); 

        }
        ;
Bif:Aif '{' PARTIEINST '}'
        {     
        finInst1=qc; 
 
        sprintf(tmp,"%d",qc); // transformer entier vers string
        ajour_quad(deb_if,2,tmp);
        }
        ;
Bifelse:Aif '{' PARTIEINST '}'
        {     
        finInst1=qc; 
        quadr("BR", "","vide","vide"); 
        sprintf(tmp,"%d",qc); 
        ajour_quad(deb_if,2,tmp);
        }
        ;
Aif:pif '(' cond ')'{
         deb_if=qc; 
         quadr("BZ","","temp_cond","vide"); 
        }
    ;
cond:   expr c expr {
         /*deb_if=qc; 
         quadr($2,"","temp_cond","vide"); */
        } 
        |cond ou cond
        |expr et cond 
        |negation cond
;
 
c:psup {strcpy($$,"BLE");}|psupEgal {strcpy($$,"BL");} |pequal {strcpy($$,"BNE")}|pinf {strcpy($$,"BGE")}|pinfEgal{strcpy($$,"BG")}|pnotequal{strcpy($$,"BE")} 
;


INSTW:Binstw '{' PARTIEINST '}'{
       
        sprintf(tmp,"%d",deb_while);
        quadr("BR",tmp,"vide","vide");//qc sincrement dans le quadr
        sprintf(tmp2,"%d",qc);
        ajour_quad(save_bz,2,tmp2);
        //quadr("FIN","vide","vide","vide");
        };
Binstw:Ainstw '(' cond ')'{
           save_bz=qc;   
           quadr("BZ","","temp_cond","vide"); 
        }
        ;
Ainstw:pwhile{
        deb_while=qc;
     
        };
%%
int yyerror(char* msg)
{printf("%s ligne %d et colonne %d",msg,ligne,col);
return 0;
}
int main()  {  

yyparse();
//afficheidf(); 
//liste
affiche(lisElts); 
 
//afficher_table(th);
//Quadruple
affich_quad();
optimize_quads(quadruplets,qc);
 
 
printf("\n-----optimiser------");
affich_quad();

//yyin = fopen("test.txt", "r");
//fclose (yyin);
return 0;  
} 
