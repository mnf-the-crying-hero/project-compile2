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
