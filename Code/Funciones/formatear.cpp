void formato_indpendientes(char *nombre_materia,char *copia_indp,int l_final){
    //Agregar la cadena "IND-" al inicio para diferenciarla
    //al momento de invocarla asignar y liberar memoria para copia

    int esp = 0; //espacios para agregar a los lados

    int aux=0;
    //int l_final = 20;
    char prefijo[5]= "ind-";
    int l_inicial = len_char(nombre_materia)+4;//sumar 4 porque es longitud del prefijo
    char *temp = new char[l_final];

    for(int i = 0;i<l_final;i++){//inicializo en vacío
        copia_indp[i] = ' ';
        temp[i] = ' ';
    }
    for(int j = 0; j<4;j++)temp[j]=prefijo[j];//copiar sufijo
    for(int j = 0;j<l_inicial+4;j++)temp[j+4]=nombre_materia[j];

    esp = l_final- l_inicial;
    for(int i = esp/2; i<l_inicial+esp/2;i++){
    //empieza a contar desde la mitad de los espacios necesarios
        copia_indp[i]=temp[aux];
        aux++;
    }
    for(int i = 0; i<l_final;i++)cout << copia_indp[i];

    delete[] temp;
}
void beauty(char *nombre,char *copia_bonita,int l_final){
    /*l_final = >longitud a mostrar en en el calendario
     * copia_bonita se debe liberar después de pegarse
     * */
    int esp = 0; //espacios para agregar a los lados
    int aux=0;
    //int l_final = 20;
    int l_inicial = len_char(nombre);

    for(int i = 0;i<l_final;i++){
        copia_bonita[i] = ' ';
    }
    esp = l_final- l_inicial;
    for(int i = esp/2; i<l_inicial+esp/2;i++){
//empieza a contar desde la mitad de los espacios necesarios
        copia_bonita[i]=nombre[aux];
        aux++;
    }
}
