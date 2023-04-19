int dec_10(int a){
    int dec=1;
    for(int i=1;i<a;i++){
        dec*=10;
    }
    return dec;
}

int len_char (char *p){
    int longitud=0;
    while(p[longitud]!= '\0'){
        longitud++;
    }
    return longitud;
}

int char_int(char *p){
    int dec=dec_10(len_char(p)), num=0,len=len_char(p);
    for(int i=0; i<=len;i++){
        num=num+(p[i]-48)*dec;
        dec/=10;
    }
    return num;
}

void int_char(int a, int b, char *p1){
    for(int i=b-1; i>=0;i--){
        *(p1+i)=(a%10)+48;
        a/=10;
    }
}

int len_num (int a){
    int longitud=1;
    while(a/10!=0){
        longitud++;
        a/=10;
    }
    return longitud;
}


bool compare(char a[], char b[]){
    int t1 = len_char(a);
    int t2 = len_char(b);
    if(t1 == t2){ //Hace falta verificar tamaño
        for(int i =0; i<t1; i++){
            if((a[i]) != (b[i])){ //Si el caracter correspondiente es
                return false;
            }
        }
        return true;
    }else{
        return false;
    }
}




void split(char* cadena,char**subcadenas,char sep, int nf){
    //Cadena: Cadena char a "formatear"
    //Subcadenas: Matriz 2 dimensiones que contiene cada dato como arreglo char
    //sep: caracter que representa la separación ';' '-' etc
    //nf: Cantidad de filas que tendrá la matriz.
    //Por ejemplo, al guardar codigo, nombre, HTI, HTD, nCRED => nf = 5
    int l = len_char(cadena);
    int c = -1;
    for(int i = 0; i<nf;i++){
        int j = 0;
        c++;
        while(cadena[c]!=sep){
            if(c==l) break;//verifica si recorre toda la cadena
            subcadenas[i][j]=cadena[c];
            j++;
            c++;//copia caracter a caracter en la matriz
        }
        subcadenas[i][j]= '\0';
    }

}
