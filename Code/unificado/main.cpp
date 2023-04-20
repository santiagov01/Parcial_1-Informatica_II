#include <iostream>
#include <Funciones.h>
using namespace std;

int main()
{
    char name_file[32]="cursos.txt";
        int saltos = saltoschar(name_file);
        int jornada[6];
        unsigned short int horas_jornada = 0,max_sp=33;


        horas_jornada = crearJornada(jornada);

        char ***calendario = new char**[horas_jornada];
// Asignar MEMORIA------------------------------------------------------------------------
        char ***Datos = new char **[saltos+1];
        leer_cursos(Datos,name_file);
        char ***Matriculadas = new char **[12];//maximo 12 materias

        for (int i = 0; i < 12; i++) {
          Matriculadas[i] = new char*[16];
            for (int j = 0; j < 16; j++) {
                Matriculadas[i][j] = new char[10];
            }
        }
        char dsp[27] ="        Disponible        ";
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

//-----------MENU---------------------------------------------------------
    menu(Datos,Matriculadas,calendario,jornada,saltos);

//--------------------------LIBERAR MEMORIA-----------------------------

    liberar_memoria(Matriculadas,12,16);
    liberar_memoria(calendario,horas_jornada,6);
    liberar_memoria(Datos,saltos+1,5);
    return 0;

}

