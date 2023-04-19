int main()
{
    int l_final = 30;
    char *copia= new char[l_final];
    char org[20] = "INFORMATICA II";
    cout << "|||||";
    beauty(org,copia,l_final);

    delete[] copia;
    cout << "|||||";
    return 0;
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
