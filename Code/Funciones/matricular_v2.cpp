void mostrar_informacion(char*** Base_datos,int total){
    for(int i = 0;i<total;i++){
        cout << i+1 << ". "<<Base_datos[i][1] << "  "  << Base_datos[i][0];
        cout << endl;
    }
}
bool validar_materia(char*** Base_datos, char* codigo,int total, int *index){
    /*
     * Codigo ingresado a comparar
     * index Sera la posicion en la que se encuentra actualmente
     * Esta funcion es util para validar si una cadena ya se encuentra
     * en la base de datos, en este caso el codigo
    */
    *index = -1;
    for(int i = 0; i<total; i++){
        (*index)++;//retorna en indice por referencia
        if(compare(Base_datos[i][0],codigo))return true;//el codigo coincide
    }
    return false;
}

void matricular_cursos2(char ***Base_datos, char*** Matriculadas, unsigned short int *cantidad,int total){
    /*
    Base_datos: matriz que contiene toda la informacion
    Matriculadas: Matriz a llenar con las materias del usuario
    ***¿que cantidad de memoria almacenar? Es decir, ¿qué cantidad de materias reservar?
    R/ Asignar por defecto la cantidad total de materias del curso. Garantizo

    En esta funcion se ingresa un numero de acuerdo a la lista de las materias
    que se pueden matricular.
    Solo se ingresa un numero y el programa sabe de cual materia se trata
    Hace las verificaciones y la reigstra.

     */
    //cout << "Ingresa cantidad de Cursos a Matricular";
    //cin >> *cantidad;

    int cred = 0;
    int num;

    //se usa para poder acceder al numero de creditos
    int i = 0;//posicion en Matriculadas
    int aux= 0;
    short int opc = 0;
    while(opc!=-1){//si es con cantidad se hace un bucle for
        // [ ] Pendiente agregar una función que deje ver los cursos que existen
        cout << "\nSelecciona numero de la siguiente lista de materias\n";
        mostrar_informacion(Base_datos,total);

        cin >> num;//seleccionar materia de acuerdo a la lista mostrada
        if(num > 0 && num<=total){//valida indice
            // Validar si codigo de la materia ya esta matriculado
            if((!validar_materia(Matriculadas,Base_datos[num-1][0],i,&aux))){

                cred+=char_int(Base_datos[num-1][4]); //aumenta el numero de creditos actuales
                if(cred <=32){//verificar cantidad de creditos

                    int l = len_char(Base_datos[num-1][0]);
                    for(int m = 0; m<l;m++){
                        Matriculadas[i][0][m]=Base_datos[num-1][0][m];//copia contenido en Matriculados
                    }
                    i++;
                    (*cantidad)++;
                    cout << "\n La materia " << Base_datos[num-1][1] << " se ha matriculado con EXITO " << endl;
                }else{
                    cout << "\nEstas loco. No puedes matricular mas de 32 creditos!!!";
                    cout << "Ingresa una nueva materia con menos creditos";
                }


            }else cout << "\nERROR al matricular. La materia " << Base_datos[num-1][1] << " ya se encuentra matriculada" <<endl;

        }else cout << "\nIndice de lista incorrecto. Digita bien tu opcion";

        //Pregunta de confirmacion de acuerdo al numero de creditos que lleva
        if(cred>=8&&cred<=32){
            cout << "\nDeseas matricular una nueva materia?" << endl;
            cout << "Presiona 1 para continuar" << endl;
            cout << "Presiona -1 para salir\n" << endl;
            cin >> opc;
        }else{
            cout << "\nAun no has completado el minimo de codigos para matricular\n";
        }
    }
}
