void leer_cursos(char ***cursos,char name_file[])
{
    /*Guardar en una matriz la infromación de cursos
    */

    char cadena[64]; //Mejor asignar con memoria dinamica??
    ifstream fin;               //stream de entrada, lectura
    try{

        fin.open(name_file);        //abre el archivo para lectura
        if(!fin.is_open()){
            throw '2';
        }
        int saltos = saltoschar(name_file);
        //ASIGNAR MEMORIA DINAMICA PARA GUARDAR CURSOS-----------------

        int n = saltos+1, m = 5;//dimensiones
        int p = 32; // longitud  maxima de cada elemento
        for (int i = 0; i < n; i++) {
          cursos[i] = new char*[m];
            for (int j = 0; j < m; j++) {
                cursos[i][j] = new char[p];
            }
        }
        // ASIGNACIÓN lista individual
        char **lista_individual = new char* [5];
        for(int i = 0; i<5; i++){
            lista_individual[i] = new char[32];
        }
        // FINALIZACIÓN DE ASIGNACIÓN--------------------------------

        fin.close();
        fin.open(name_file);
        if(!fin.is_open()){
            throw '2';
        }
        for(int i = 0; i<(saltos+1);i++){
            //recorre linea a linea
            fin.getline(cadena,64);

            char **lista_individual = new char*[5];
            for(int i = 0; i<5; i++){
                lista_individual[i] = new char[32];
            }
            //separa cadena leida y guardar en lista
            //convertir/formatear cadena a matriz(lista de arreglos char)
            split(cadena,lista_individual,';',5);
            for (int j = 0; j < 5; j++) {
                for(int k = 0;k<32;k++){
                    //añadir matriz anterior a matriz 3D
                    *(*(*(cursos+i)+j)+k) = *(*(lista_individual+j)+k);
                    //iterador i (representa la fila)está al inicio
                }
            }
            for(int i = 0; i<5;i++)delete[] lista_individual[i];
            delete[] lista_individual;
        }
        for(int i = 0; i<saltos+1;i++){
            for (int j = 0; j < 5; j++) {
                cout << cursos[i][j];
            }
            cout << endl;
        }

        fin.close();
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
