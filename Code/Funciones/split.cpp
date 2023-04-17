#include <iostream>

using namespace std;
int len_char (char *p);
void split(char* cadena,char**subcadenas,char sep, int nf);
int main()
{
    char **matrix;
    char cadena[20] = "22312;Info II;5;4;5";
    matrix = new char* [5];
    for(int i = 0; i<5; i++){
        matrix[i] = new char[10];
    }
    split(cadena,matrix,';',5);
    for(int i = 0;i<5;i++){
        cout << matrix[i];
        cout << endl;
    }
    for(int i = 0; i<5;i++)delete[] matrix[i];
    delete[] matrix;
    return 0;
}
int len_char (char *p){
    int longitud=0;
    while(p[longitud]!= '\0'){
        longitud++;
    }
    return longitud;
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


