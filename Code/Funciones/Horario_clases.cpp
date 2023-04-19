void horario_clases(char ***Matriculados, char datos[3][5][30], char ***calendario, int num_clases
    , int *jornada){
      unsigned short int hora,dia;


      for(int i=0;i<num_clases;i++){ //numero de clases de matriz matriculados

          //creo las matrices donde van a ir la hora y los dias de cada materia

          char **dias=new char*[2];
          for(int i=0;i<2;i++){
              dias[i]=new char[1];
          }

          char **horas=new char*[2];
          for(int i=0;i<2;i++){
              horas[i]=new char[1];
          }

          for(int j=0;j<num_clases;j++){
              if(compare(*Matriculados[i],*datos[j])){ //puede elimin
                   //HTD=char_int(datos[i][2]);
                   cout<<"introduzca los dias de "<<datos[i][1]<<" en formato dia1-dia2"<<endl;
                   cin>>Matriculados[i][1];

                   split(Matriculados[i][1],dias,'-',2);

                   for(int h=0;h<2;h++){
                       for(int k=0;k<2;k++){
                           Matriculados[i][h+1][k] = dias[h][k];
                       }
                   }
                   cout<<"introduzca las horas de "<<datos[i][1]<<" en formato HoraInicial-Horafinal"<<endl;
                   cin>>Matriculados[i][3];

                   split(Matriculados[i][3],horas,'-',2);

                   for(int h=0;h<2;h++){
                       for(int k=0;k<3;k++){
                           Matriculados[i][h+3][k] = horas[h][k];
                       }
                   }
                   RestarHora(Matriculados[i][4]);



                   if(verificarDisponibilidad(calendario,Matriculados,jornada,i)==false){
                        cout<<"Esta hora no esta disponible"<<endl;
                        j--;
                        break;
                   }
                   else{
                       for(int t=0;t<2;t++){
                           for(int c=0;c<2;c++){
                               dia=indice_dia(Matriculados[i][c+1]);
                               hora=indice_hora(Matriculados,jornada,i,t);
                               reservarHora(calendario,Matriculados,dia,hora,datos,i);
                           }

                       }


                   }



              }

          }

          for(int k=0;k<2;k++){
              delete[] dias[k];
          }
          delete[] dias;

          for(int k=0;k<2;k++){
              delete[] horas[k];
          }
          delete[] horas;



          }
      for(int i=0;i<num_clases;i++){
          for(int j=0;j<5;j++){
              cout<<Matriculados[i][j]<<" ";
          }
          cout<<endl;
      }


}





bool verificarDisponibilidad(char ***calendario ,char ***matriculados,int *jornada, int indice) {
    unsigned short int rango,dia,horaD=0,horaI;

    for(int i=0;i<2;i++){
        dia=indice_dia(matriculados[indice][i+1]);

    rango=char_int(matriculados[indice][4])-char_int(matriculados[indice][3]);

    for(int i=0;i<rango;i++){
        horaI=indice_hora(matriculados,jornada,indice,i);
        if(compare(calendario[horaI][dia],"     Disponible     ")){
            horaD++;

        }
        else return false;
    }
    }
        if(horaD==2*(char_int(matriculados[indice][4])-char_int(matriculados[indice][3]))) return true;
        else return false;
}



void reservarHora(char ***calendario, char ***matriculados, int dia, int hora,char datos[30][5][30],int materia ){
    for(int i=0;i<30;i++){
        if(compare(*matriculados[materia],*datos[i])){
            calendario[hora][dia]= datos[materia][1];
            break;

        }
    }


}


int indice_dia(char *matriculados){
    short int dia=0;
    if(*matriculados==76 || *matriculados==118) dia=0;
    if(*matriculados==77 || *matriculados==109) dia=1;
    if(*matriculados==87 || *matriculados==119) dia=2;
    if(*matriculados==74 || *matriculados==106) dia=3;
    if(*matriculados==86 || *matriculados==118) dia=4;
    if(*matriculados==83 || *matriculados==115) dia=5;
    return dia;

}

int indice_hora(char ***matriculados,int *jornada,int clase, int hora){
    short int horaClase=0,horaI;
    horaI=-1;
    horaClase=char_int(matriculados[clase][3+hora]);
    for(int j=0;j<jornada[3]-jornada[0];j++){
        if(horaClase==jornada[0]+j){
            horaI++;
            break;
        }
        else horaI++;

    }

    return horaI;
}



void RestarHora(char *Matricula){
    short int Hora_original;
    char Nueva_hora[2]={};
    Hora_original=char_int(Matricula);
    int_char(Hora_original-1,len_num(Hora_original),Nueva_hora);
    for(int i=0;i<len_num(Hora_original);i++){
        Matricula[i]=Nueva_hora[i];
    }

}
