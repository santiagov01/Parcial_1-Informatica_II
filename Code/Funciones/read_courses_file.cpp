#include <iostream>
#include <fstream>
using namespace std;
int main()
{
    return 0;
}
bool file_correct(char *name){
    try {

    } catch (...) {
        return false;
    }
    return true;
}
void leer_cursos()
{
    /*Guardar en una matriz la infromación de cursos
    */

    char cadena[20];
    ifstream fin;               //stream de entrada, lectura
    ofstream fout;              //stream de salida, escritura
    char name_file[64];
    //Pedir nombre del archivo o abrir con nombre existente
    cout<<"Ingrese nombre del archivo (sin espacios) ";
    cin>>name_file;//lee una cadena sin espacios
    while(!(file_correct(name_file))){
        cout << "Ingresa el nombre del archivo correctamente";
        cin >> name_file;
    }

    //cin.getline(cadena1, sizeof(cadena1));      //lee una cadena con espacios

    try{

        fin.open(name_file);        //abre el archivo para lectura
        if(!fin.is_open()){
            throw '2';
        }
        int saltos = 0;

        while(fin.good()){ //lee caracter a caracter hasta el fin del archivo
            char temp=fin.get();
            if(fin.good()){
                if(temp == '\n'){
                    saltos++;//contar saltos de linea (cantidad cursos)
                }
            }

        }
        fin.close();
        fin.open(name_file);        //abre el archivo para lectura
        if(!fin.is_open()){
            throw '2';
        }
        for(int i = 0; i<(saltos+1);i++){
            fin.getline(cadena,15);
            //convertir/formatear cadena a matriz(lista de arreglos char)
            //añadir matriz anterior a matriz 3D
        }

    /*
        int i=0;
        while(fin.good()){              //lee caracter a caracter hasta el fin del archivo
            char temp=fin.get();
            if(fin.good()){
                cadena2[i]=temp;     //Asigna cada caracter leido a la cadena de caracteres
            }
            i++;
        }*/
        fin.close();                //Cierra el archivo de lectura.


    }
    catch (char c){
        cout<<"Error # "<<c<<": ";
        if(c=='2'){
            cout<<"Error al abrir el archivo para escritura.\n";
        }
    }
    catch (...){
        cout<<"Error no definido\n";
    }
}

