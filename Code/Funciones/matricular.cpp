bool validar_materia(char*** Base_datos, char* codigo,int total, int *index){
    /*
     * Codigo ingresado a comparar
     * index Sera la posicion en la que se encuentra actualmente
    */
    *index = 0;
    for(int i = 0; i<total; i++){
        (*index)++;//retorna en indice por referencia
        if(compare(Base_datos[i][0],codigo))return true;//el codigo coincide
    }
    return false;
}
void matricular_cursos(char ***Base_datos, char*** Matriculadas, unsigned short int *cantidad,int total){
    /*
    Base_datos: matriz que contiene toda la informacion
    Matriculadas: Matriz a llenar con las materias del usuario
    ***¿que cantidad de memoria almacenar? Es decir, ¿qué cantidad de materias reservar?
    (?)cantidad: Numero de materias que el estudiante va a matricular
    total: Total de materias en Base de datos
    [ ] Validar que cantidad sea positiva y menor que el maximo de materias


    [X] Validar que la suma de creditos del estudiante no exceda de 32
    [ ] Validar que Curso ingresado no se repita

    Hacer una version que dependa solo de creditos
    Hacer una version que dependa de las cantidad y de creditos

     * */
    //cout << "Ingresa cantidad de Cursos a Matricular";
    //cin >> *cantidad;

    int cred = 0;
    char code_mat[16] = "";
    int index = 0;//usar como indice de la materia a matricular
    //se usa para poder acceder al numero de creditos
    int i = 0;//posicion en Matriculadas
    int aux= 0;

    while(cred<=32){//si es con cantidad se hace un bucle for
        // [ ] Pendiente agregar una función que deje ver los cursos que existen
        mostrar_informacion(Base_datos,total);
        cout << "Ingresa el codigo de la materia";
        cin >> code_mat;
        if((validar_materia(Base_datos,code_mat,total,&index))){
            //validar que Codigo ingresado existe en la base de datos.
            if((!validar_materia(Matriculadas,code_mat,i,&aux))){
                // Validar si Codigo ingresado ya existe
                cred+=char_int(Base_datos[index][4]); //aumenta el numero de creditos actuales
                if(cred <=32){
                    //vuelve a verificar
                    for(int m = 0; m<len_char(code_mat);m++){
                        Matriculadas[i][0][m]=code_mat[m];//copia contenido en Matriculados
                        i++;
                    }
                    cantidad++;
                }

            }else cout << "\nError al matricular. La materia " << Base_datos[index][1] << " ya se encuentra matriculada" <<endl;
        }else cout << "\nError. No se encontró ninguna materia con el codigo ingresado. \nVerifque de nuevo"<<endl;

    }
}
