#include <iostream>
#include <Funciones.h>
using namespace std;

int main()
{
    char name_file[32]="cursos.txt";
    int saltos = saltoschar(name_file);
    int jornada[6];
    unsigned short int horas_jornada = 0,max_sp=33;

    cout<<"BIENVENIDO AL SISTEMA DE GESTION DE HORARIO"<<endl<<endl;
    cout<<"Para comenzar creemos su jornada de estudio"<<endl;
    horas_jornada = crearJornada(jornada);

    char ***calendario = new char**[25];
// Asignar MEMORIA------------------------------------------------------------------------
    char ***Datos = new char **[saltos+1];
    char ***Matriculadas = new char **[12];//maximo 12 materias

    for (int i = 0; i < 12; i++) {
      Matriculadas[i] = new char*[10];
        for (int j = 0; j < 10; j++) {
            Matriculadas[i][j] = new char[33];
        }
    }
    char dsp[33] = "           Disponible           ";
    for(int i =0;i< horas_jornada;i++){
        calendario[i] = new char *[6];
        for(int j=0;j<6;j++){
            calendario[i][j] = new char[max_sp];
        }
    }

    for(int i =0;i< horas_jornada;i++){
        for(int j=0;j<6;j++){
            for(int k= 0;k<max_sp;k++){
                calendario[i][j][k] = dsp[k];
            }
        }
    }
//------------------------------------------------------------------------
    unsigned short int num_clases = 0,opcion;
    leer_cursos(Datos,name_file);
    do{

        cout<<"Ahora escoga una de las siguientes opciones"<<endl;
        cout<<"1. Matricular Curso"<<endl;
        cout<<"2. Ingresar horario de cursos"<<endl;
        cout<<"3. Ver cursos matriculados"<<endl;
        cout<<"4. Ingresar horas de trabajo independiente"<<endl;
        cout<<"5. Mostrar calendario"<<endl;
        cout<<"0. Salir del programa"<<endl;
        cin>>opcion;

        switch(opcion){
        case 1:{
                matricular_cursos(Datos, Matriculadas, &num_clases,saltos+1);
                break;
        }

        case 2:{
             horario_clases2(Matriculadas, Datos,calendario,num_clases, jornada,saltos+1);
             break;
        }
        case 3:{
            cout << "\n-----CURSOS MATRICULADOOOS-----" << endl;
            for(int i = 0;i<num_clases+1;i++){
                cout << Matriculadas[i][0];
                cout << " ";
                cout << endl;
            }
             break;

        }
        case 4:{
             rellenar(Datos,calendario,Matriculadas,num_clases, jornada);
             break;

        }
        case 5:{
             mostrarCalendario(jornada,calendario);
             break;

        }
        default: cout<<"ingrese una opcion valida"<<endl;
        }



       }while(opcion!=0);

//--------------------------LIBERAR MEMORIA-----------------------------
    for(int i = 0; i<12;i++){
        for(int j = 0; j<10; j++){
            delete[] Matriculadas[i][j];
        }
        delete[] Matriculadas[i];
    }
    delete[] Matriculadas;

    for(int i = 0; i<horas_jornada;i++){
        for(int j = 0; j<6; j++){
            delete[] calendario[i][j];
        }
        delete[] calendario[i];
    }
    delete[] calendario;

    liberar_memoria(Datos,saltos);
    return 0;

}

