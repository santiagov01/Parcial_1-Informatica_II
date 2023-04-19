#include <iostream>
#include <fstream>
using namespace std;
int len_char (char *p);
int char_int(char *p);
int dec_10(int a);
void split(char* cadena,char**subcadenas,char sep, int nf);
void leer_cursos(char ***cursos,char[]);
int saltoschar(char name_file[]);
void asignar_memoria(char***,int saltos);
void liberar_memoria(char***, int saltos);
void matricular_cursos(char ***Base_datos, char*** Matriculadas, unsigned short int *cantidad,int total);
bool validar_materia(char*** Base_datos, char* codigo,int total, int*);
void mostrar_informacion(char*** Base_datos,int total);
bool compare(char a[], char b[]);

int main()
{

    //char*** ptr3 = nullptr;
    char name_file[32]="cursos.txt";
    int saltos = saltoschar(name_file);
    char ***ptr3 = new char **[saltos+1];
    char ***Matriculadas = new char **[saltos+1];

    for (int i = 0; i < saltos+1; i++) {
      Matriculadas[i] = new char*[10];
        for (int j = 0; j < 10; j++) {
            Matriculadas[i][j] = new char[32];
        }
    }

    unsigned short int cantidad = 0;
    leer_cursos(ptr3,name_file);

    matricular_cursos(ptr3, Matriculadas, &cantidad,saltos+1);


    cout << "\n-----CURSOS MATRICULADOOOS-----" << endl;
    for(int i = 0;i<cantidad+1;i++){
        cout << Matriculadas[i][0];
        cout << " ";
        cout << endl;
    }



    for(int i = 0; i<saltos+1;i++){
        for(int j = 0; j<10; j++){
            delete[] Matriculadas[i][j];
        }
        delete[] Matriculadas[i];
    }
    delete[] Matriculadas;
    liberar_memoria(ptr3,saltos);
    return 0;

}
void matricular_cursos2(char ***Base_datos, char*** Matriculadas, unsigned short int *cantidad,int total){
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
    short int opc = 0;
    while(opc!=-1){//si es con cantidad se hace un bucle for
        // [ ] Pendiente agregar una función que deje ver los cursos que existen
        mostrar_informacion(Base_datos,total);
        cout << "\nIngresa el codigo de la materia: \n";
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
                    }
                    i++;
                    (*cantidad)++;
                }else{
                    cout << "\nEstas loco. No puedes matricular mas de 32 creditos!!!";
                    cout << "Ingresa una nueva materia con menos creditos";
                }


            }else cout << "\nError al matricular. La materia " << Base_datos[index][1] << " ya se encuentra matriculada" <<endl;
        }else cout << "\nError. No se encontro ninguna materia con el codigo ingresado. \nVerifque de nuevo"<<endl;
        if(cred>=8&&cred<=32){
            cout << "\nDeseas matricular una nueva materia?" << endl;
            cout << "Presiona 1 para continuar" << endl;
            cout << "Presiona -1 para salir\n" << endl;
            cin >> opc;
        }else{
            cout << "\nAun no has completado el minimo de codigos para matricular";
        }
    }
}
void matricular_cursos(char ***Base_datos, char*** Matriculadas, unsigned short int *cantidad,int total){
    /*
    Base_datos: matriz que contiene toda la informacion
    Matriculadas: Matriz a llenar con las materias del usuario
    ***¿que cantidad de memoria almacenar? Es decir, ¿qué cantidad de materias reservar?
    R/ Asignar por defecto la cantidad total de materias del curso. Garantizo

    (?)cantidad: Numero de materias que el estudiante va a matricular
    total: Total de materias en Base de datos
    [-] Validar que cantidad sea positiva y menor que el maximo de materias


    [X] Validar que la suma de creditos del estudiante no exceda de 32
    [X] Validar que Curso ingresado no se repita

     */
    //cout << "Ingresa cantidad de Cursos a Matricular";
    //cin >> *cantidad;

    int cred = 0;
    int num;
    int index = 0;//usar como indice de la materia a matricular
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
            cout << "\nAun no has completado el minimo de creditos para matricular\n";
        }
    }
}
void asignar_memoria(char***matrix,int saltos){
    int n = saltos+1, m = 5;
    int p = 20; // longitud  maxima de cada elemento

    matrix = new char**[n];

    for (int i = 0; i < n; i++) {
      matrix[i] = new char*[m];
        for (int j = 0; j < m; j++) {
            matrix[i][j] = new char[p];
        }
    }
}
void liberar_memoria(char*** matrix, int saltos){
    for(int i = 0; i<saltos+1;i++){
        for(int j = 0; j<5; j++){
            delete[] matrix[i][j];
        }
        delete[] matrix[i];
    }
    delete[] matrix;
}
int len_char (char *p){
    int longitud=0;
    while(p[longitud]!= '\0'){
        longitud++;
    }
    return longitud;
}
int saltoschar(char name_file[]){
    ifstream fin;
    int saltos = 0;
    try{

        fin.open(name_file);        //abre el archivo para lectura
        if(!fin.is_open()){
            throw '2';
        }

        while(fin.good()){ //lee caracter a caracter hasta el fin del archivo
            char temp=fin.get();
            if(fin.good()){
                if(temp == '\n'){
                    saltos++;//contar saltos de linea (cantidad cursos)
                }
            }
        }
        fin.close();
        return saltos;
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
    return 1;


}
void split(char* cadena,char**subcadenas,char sep, int nf){
    //Cadena: Cadena char a "formatear"
    //Subcadenas: Matriz 2 dimensiones que contiene cada dato como arreglo char
    //sep: caracter que representa la separación ';' '-' etc
    //nf: Cantidad de filas que tendrá la matriz.
    //Por ejemplo, al guardar codigo, nombre, HTI, HTD, nCRED => nf = 5
    int l = len_char(cadena);
    int c = -1;
    for(int i = 0; i<nf;i++){
        int j = 0;
        c++;
        while(cadena[c]!=sep){
            if(c==l) break;//verifica si recorre toda la cadena
            subcadenas[i][j]=cadena[c];
            j++;
            c++;//copia caracter a caracter en la matriz
        }
        subcadenas[i][j]= '\0';
    }


}

/*bool file_correct(char *name){
    try {

    } catch (...) {
        return false;
    }
    return true;
} */
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
                //cout << cursos[i][j];
            }
            //cout << endl;
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

void mostrar_informacion(char*** Base_datos,int total){
    for(int i = 0;i<total;i++){
        cout << i+1 << ". "<<Base_datos[i][1] << "  "  << Base_datos[i][0];
        cout << endl;
    }
}
bool validar_materia(char*** Matriculadas, char* codigo,int total, int *index){
    /*
     * Codigo ingresado a comparar
     * index Sera la posicion en la que se encuentra actualmente
     * Esta funcion es util para validar si una cadena ya se encuentra
     * en la base de datos, en este caso el codigo
    */
    *index = -1;
    for(int i = 0; i<total; i++){
        (*index)++;//retorna en indice por referencia
        if(compare(Matriculadas[i][0],codigo))return true;//el codigo coincide
    }
    return false;
}
int char_int(char *p){
    int dec=dec_10(len_char(p)), num=0,len=len_char(p);
    for(int i=0; i<=len;i++){
        num=num+(p[i]-48)*dec;
        dec/=10;
    }
    return num;
}
int dec_10(int a){
    int dec=1;
    for(int i=1;i<a;i++){
        dec*=10;
    }
    return dec;
}
bool compare(char a[], char b[]){
    int t1 = len_char(a);
    int t2 = len_char(b);
    if(t1 == t2){ //Hace falta verificar tamaño
        for(int i =0; i<t1; i++){
            if((a[i]) != (b[i])){ //Si el caracter correspondiente es
                return false;
            }
        }
        return true;
    }else{
        return false;
    }
}
