void horario_clases2(char ***Matriculados, char ***datos, char ***calendario, int num_clases
                     , int *jornada, int saltos){
    //Ingresar hora por hora
    unsigned short int hora,indice_hora,dia,HTD;
    int index=0;
    char dia_letra;
    for(int i = 0;i<num_clases;i++){
        validar_materia(datos,Matriculados[i][0],saltos,&index);
        HTD=char_int(datos[index][2]);
        while(HTD>0){
            cout << "Introduzca el DIA (L,M,W...) de " << datos[index][1] << endl;
            //FALTA HACER VALIDACION
            cin >> dia_letra;
            dia=indice_dia2(dia_letra);

            cout << "Introduzca la HORA(6,7,8...) de " << datos[index][1] << endl;
            //FALTA HACER VALIDACION
            cin >> hora;
            indice_hora = hora - jornada[0];
            char dsp[32] = "     Disponible     ";
            if(compare(calendario[indice_hora][dia],dsp)){
                reservarHora2(calendario,dia,indice_hora,datos,index);
                HTD--;
                cout << "HORA MATRICULADA CON EXITO";
            }else{
                cout << "ESTA HORA NO ESTÁ DISPONIBLE. Prueba con otra.";
            }
            mostrarCalendario(jornada,calendario);
        }
    }
}

void reservarHora2(char ***calendario, int dia, int hora,char ***datos,int index ){
    int l_final = 21;
    char *copia= new char[l_final];

    beauty(datos[index][1],copia,l_final);
    for(int k = 0; k<len_char(calendario[hora][dia]);k++)
        calendario[hora][dia][k]= copia[k];


    delete[] copia;

}
