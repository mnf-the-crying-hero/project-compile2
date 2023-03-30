/*7. Si la constante entière
est signée, elle doit être mise entre parenthèses. ????*/
%{
#include <stdio.h>
#include<string.h>
#include "b.tab.h" 
 
int ligne=1;
int col=0;
%}
chiffre [0-9]
lettre_com[a-zA-Z][%*''()"",&]
/*INTEGER 0|[1-9]{chiffre}*|[(][-+][1-9]{chiffre}*[)]*/
chiffreSigne "("[+-]?([1-9][0-9]*|0)")"
chiffreReelSigne "("[+-]?([0-9][0-9]*"."[0-9]*|0)")"
INTEGER ({chiffre}+|{chiffreSigne})
FLOAT ({chiffreReelSigne}|({chiffre}+"."{chiffre}+))
IDF [a-z](([a-z0-9_])*[a-z0-9])?
commentaire ((%%)({chiffre}|.|{lettre_com})+)
aff =
%%
VAR {col=col+yyleng;return pvar ;}
CODE {col=col+yyleng;return pcode ;}

STRUCT {col=col+yyleng;return pstruct;}
IF {col=col+yyleng;return pif ;}
ELSE {col=col+yyleng;return pelse ;}

FOR {col=col+yyleng;return pfor ;}
WHILE {col=col+yyleng;return pwhile;}
CONST {col=col+yyleng;return pconst;}
INTEGER {col=col+yyleng;return pint;}
FLOAT {col=col+yyleng;return pfloat;}
{INTEGER} {col=col+yyleng; yylval.num=atoi(yytext);
        if( yylval.num < 32767 && yylval.num > (-32768) ){return entier; }
        else {printf("erreur lexical , ligne %d , colonne %d , erreur : %s ",ligne,col,yytext);} }

{FLOAT} {col=col+yyleng; yylval.flt =atof(yytext); return reel; }
{aff} {col=col+yyleng; return aff;}
{IDF} { col=col+yyleng; yylval.str=strdup(yytext);return idf;}

"+" { col=col+yyleng;return padd ;}
"-" { col=col+yyleng;return psous ;}
"*" {col=col+yyleng;return pmul; }
"/" {col=col+yyleng;return pdiv;}

 
")"  {col++;return ')';}
"("  {col++;return '(';}
"[" {col++;return '[';}
"]" {col++;return ']';}
"{" {col++;return '{';}
"}" {col++;return '}';}

">" {col=col+yyleng;return psup;}
">=" {col=col+yyleng;return psupEgal;}
"<" {col=col+yyleng;return pinf;}
"<=" {col=col+yyleng;return pinfEgal;}
"==" {col=col+yyleng;return pequal;}
"!=" {col=col+yyleng;return pnotequal;}
"||" { col=col+yyleng;return ou ;}
"&&" { col=col+yyleng;return  et;}
"!" {col=col+yyleng;return negation;}

"," {col=col+yyleng;return ',';}
":" {col=col+yyleng;return ':';}
{commentaire}
";" {col++;return ';';}
[ \t]  col+=yyleng;
\n {ligne++;col=1;}
.    {printf("Erreur lexical la ligne %d et colonne %d \n",ligne,col);}	

%%
int yywrap(void)
{
return 0;
}
