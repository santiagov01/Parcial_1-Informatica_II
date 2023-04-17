void horario_clases(char Matriculados[1][5][20], char datos[3][5][20],const char ***calendario,int num_clases){
      unsigned short int HTD=0;


      for(int i=0;i<num_clases;i++){

          char **dias=new char*[2];
          for(int i=0;i<2;i++){
              dias[i]=new char[1];
          }

          char **horas=new char*[2];
          for(int i=0;i<2;i++){
              horas[i]=new char[1];
          }

          for(int j=0;j<num_clases;j++){
              if(compare(*Matriculados[i],*datos[j])){
                   HTD=char_int(datos[i][2]);
                   cout<<"introduzca los dias de "<<datos[i][1]<<" en formato dia1-dia2"<<endl;
                   cin>>Matriculados[i][1];

                   split(Matriculados[i][1],dias,'-',2);

                   for(int h=0;h<2;h++){
                       for(int k=0;k<2;k++){
                           Matriculados[i][h+1][k] = dias[h][k];
                       }
                   }
                   cout<<"introduzca las de "<<datos[i][1]<<" en formato HoraInicial-Horafinal"<<endl;
                   cin>>Matriculados[i][3];

                   split(Matriculados[i][3],horas,'-',2);

                   for(int h=0;h<2;h++){
                       for(int k=0;k<2;k++){
                           Matriculados[i][h+3][k] = horas[h][k];
                       }
                   }
              }
              else {
                  cout<<"El curso con codigo "<<Matriculados[i]<<"No existe"<<endl;
                  continue;
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
          for(int j=0;j<4;j++){
              cout<<Matriculados[i][j]<<" ";
          }
          cout<<endl;
      }


}
