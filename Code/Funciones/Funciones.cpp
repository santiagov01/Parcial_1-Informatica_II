#include <iostream>
#include "Funciones.h"
#include <fstream>
using namespace std;



void mostrarCalendario(int *jornada, const char***calendario) {
    cout << "     ";
    char dias[6]={'L','M','W','J','V','S'};
    for (int j = 0; j < 6; j++) cout <<"         "<< dias[j]<<"          ";
    cout << endl;
    if(jornada[0]>jornada[3]){
        for (int i = 0; i < 24-jornada[0]+jornada[3]; i++) {
            if(jornada[0]+i>23){
                if(jornada[0]+i>9) cout<<jornada[0]+i-24<<":"<<jornada[1]<<jornada[2]<<" ";
                else cout <<jornada[0]+i-24<<":"<<jornada[1]<<jornada[2];

                for (int j = 0; j < 6; j++) cout << calendario[i][j]; //aqui debe de ir la funcion que imprima el nombre
                cout << endl;
            }

            else{
                if(jornada[0]+i>9) cout<<jornada[0]+i<<":"<<jornada[1]<<jornada[2];
                else cout <<jornada[0]+i<<":"<<jornada[1]<<jornada[2]<<" ";

                for (int j = 0; j < 6; j++) cout << calendario[i][j]; //aqui debe de ir la funcion que imprima el nombre
                cout << endl;
            }
        }

    }

    else{
        for (int i = 0; i < jornada[3]-jornada[0]; i++) {
            if(jornada[0]+i>9) cout<<jornada[0]+i<<":"<<jornada[1]<<jornada[2];
            else cout <<jornada[0]+i<<":"<<jornada[1]<<jornada[2]<<" ";

            for (int j = 0; j < 6; j++) cout << calendario[i][j]; //aqui debe de ir la funcion que imprima el nombre
            cout << endl;
            }

    }
}

int crearJornada(int *jornada){
        unsigned short int horai,horaf,horas_jornada;
        bool valido;
        do{
        cout<<"introduzca la hora inicial de su jornada en formato 2400"<<endl;
        cin>>horai;
        cout<<"introduzca la hora final de su jornada en formato 2400"<<endl;
        cin>>horaf;

        if (horai>2400){
            valido=false;
            cout<<"Hora invalida"<<endl;
        }
        else valido=true;
        }while(!valido);

            jornada[0]=horai/100;
            jornada[1]=horai%100;
            jornada[2]=horai%10;
            jornada[3]=horaf/100;
            jornada[1]=horaf%100;
            jornada[2]=horaf%10;

        if(jornada[0]>jornada[3]) horas_jornada=24-jornada[0]+jornada[3];
        else horas_jornada=jornada[3]-jornada[0];
        return horas_jornada;
        }








