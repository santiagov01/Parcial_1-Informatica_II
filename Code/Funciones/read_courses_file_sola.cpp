void leer_cursos(char ***cursos)
{
    /*Guardar en una matriz la infromación de cursos
    */

    char cadena[40]; //Mejor asignar con memoria dinamica??
    ifstream fin;               //stream de entrada, lectura
    ofstream fout;              //stream de salida, escritura
    char name_file[64];
    //Pedir nombre del archivo o abrir con nombre existente
    cout<<"Ingrese nombre del archivo (sin espacios) ";
    cin>>name_file;//lee una cadena sin espacios
    /*while(!(file_correct(name_file))){
        cout << "Ingresa el nombre del archivo correctamente";
        cin >> name_file;
    }*/

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

        //ASIGNAR MEMORIA DINAMICA PARA GUARDAR CURSOS-----------------

        int n = saltos, m = 5;
        int p = 20; // longitud  maxima de cada elemento

        // Asignar memoria dinámica al puntero triple
        cursos = new char**[n];

        // Asignar memoria dinámica a los punteros dobles
        for (int i = 0; i < n; i++) {
          cursos[i] = new char*[m];
          // Asignar memoria dinámica a los punteros simples
            for (int j = 0; j < m; j++) {
                cursos[i][j] = new char[p];
            }
        }
        // FINALIZACIÓN DE ASIGNACIÓN--------------------------------

        char **lista_individual = nullptr;
        lista_individual = new char* [5];
        for(int i = 0; i<5; i++){
            lista_individual[i] = new char[20];
        }
        //-----------------------------------------------

        fin.close();
        fin.open(name_file);        //abre el archivo para lectura
        if(!fin.is_open()){
            throw '2';
        }
        cout << "Saltos: " << saltos << endl;
        //LECTURA OFICIAL
        for(int i = 0; i<(saltos+1);i++){
            fin.getline(cadena,40);
            split(cadena,lista_individual,';',5);
            for(int j = 0;j<5;j++){
                cout << lista_individual[j];

                cout << endl;
            }
            for(int j = 0;j<5;j++){
                cursos[i][j] = lista_individual[j];

            }
            //convertir/formatear cadena a matriz(lista de arreglos char)
            //añadir matriz anterior a matriz 3D
        }

        for (int j = 0; j < 5; j++) {
            cout << cursos[0][j];
            cout << endl;
        }


    /*
        int i=0;
        while(fin.good()){  //lee caracter a caracter hasta el fin del archivo
            char temp=fin.get();
            if(fin.good()){
                cadena2[i]=temp;//Asigna cada caracter leido a la cadena de caracteres
            }
            i++;
        }*/
        fin.close();   //Cierra el archivo de lectura.

        // Liberar la memoria asignada---------------------
        // Si se libera acá no se puede utilizar la matriz
        // Mejor liberar matriz afuera, pasandole por los valores de sus dimensiones
        for (int i = 0; i < n; i++) {
           for (int j = 0; j < m; j++) {
              delete [] cursos[i][j];
           }
           delete[] cursos[i];
        }
        delete[] cursos;
        // Liberar la memoria asignada---------------------
        for(int i = 0; i<5;i++)delete[] lista_individual[i];
        delete[] lista_individual;



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