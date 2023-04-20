#include <iostream>
#include <Funciones.h>
#include <fstream>
#include <cstdlib>
#include <ctime>
using namespace std;
void rellenar(char ***datos, char ***calendario, char ***Matriculados, int num_clases, int *jornada){
    unsigned short int HTI,tam_jornada;
    int index;
    tam_jornada=jornada[3]-jornada[0];
    char dsp[33] = "           Disponible           ";
    for(int i=0;i<num_clases;i++){
    validar_materia(datos,Matriculados[i][0],63,&index);
         HTI=char_int(datos[i][3]);
         srand(time(NULL));
         while(HTI>0){

             int dia= rand() % 6;
             int hora=rand() %tam_jornada;
             if(compare(calendario[hora][dia],dsp)){
                 reservarIndep(calendario,dia,hora,datos,index);
                 HTI--;
             }
        }
    }
}


void horario_clases2(char ***Matriculados, char ***datos, char ***calendario, int num_clases
                     , int *jornada, int saltos){
    //Ingresar hora por hora
    unsigned short int hora = 0,dia = 0,HTD;
    short int indice_hora = 0;
    int index=0;
    char dia_letra = '\0';
    for(int i = 0;i<num_clases;i++){
        validar_materia(datos,Matriculados[i][0],saltos,&index);
        HTD=char_int(datos[index][2]);
        while(HTD>0){

            validar_dia(datos,&index,dia_letra,&dia);
            validar_hora(datos,jornada,&indice_hora,index,hora);

            char dsp[33] = "           Disponible           ";
            if(compare(calendario[indice_hora][dia],dsp)){
                reservarHora2(calendario,dia,indice_hora,datos,index);
                HTD--;
                cout << "HORA MATRICULADA CON EXITO"<<endl;
            }else{
                cout << "ESTA HORA NO ESTÁ DISPONIBLE. Prueba con otra."<<endl;
            }
            mostrarCalendario(jornada,calendario);
        }
    }
}

void validar_hora(char*** datos, int * jornada, short int *indice_hora, int index,unsigned short int hora){
    cout << "Introduzca la HORA(6,7,8...) de " << datos[index][1] << endl;
    cin >> hora;
    (*indice_hora) = hora - jornada[0];
    while(!((*indice_hora)>=0&&((*indice_hora)<=jornada[3]-jornada[0]))){
        cout << "\nINGRESA CORRECTAMENTE LA HORA!!!" << endl;
        cout << "Introduzca la HORA(6,7,8...) de " << datos[index][1] << endl;
        cin >> hora;
        (*indice_hora) = hora - jornada[0];
    }
}
void validar_dia(char*** datos, int *index,char dia_letra, unsigned short int *dia){
    cout << "Introduzca el DIA (L,M,W...) de " << datos[(*index)][1] << endl;
    cin >> dia_letra;
    (*dia)=indice_dia2(dia_letra);
    while((*dia)==10){
        cout << "\nINGRESA CORRECTAMENTE EL DIA !!!\n";
        cout << "Introduzca inicial el DIA [L,M,W,J,V,S] de " << datos[(*index)][1] << endl;
        cin >> dia_letra;
        (*dia)=indice_dia2(dia_letra);
    }


}

void reservarHora2(char ***calendario, int dia, int hora,char ***datos,int index ){
    int l_final = 33;
    char *copia= new char[l_final];

    beauty(datos[index][1],copia,l_final);
    for(int k = 0; k<len_char(calendario[hora][dia]);k++)
        calendario[hora][dia][k]= copia[k];

    delete[] copia;

}

void reservarIndep(char ***calendario, int dia, int hora,char ***datos,int index ){
    int l_final = 33;
    char *copia= new char[l_final+1];

    formato_indpendientes(datos[index][1],copia,l_final);
    for(int k = 0; k<len_char(calendario[hora][dia]);k++)
        calendario[hora][dia][k]= copia[k];

    delete[] copia;

}

int indice_dia2(char matriculados){
    short int dia=10;
    if(matriculados==76 || matriculados==118) dia=0;
    if(matriculados==77 || matriculados==109) dia=1;
    if(matriculados==87 || matriculados==119) dia=2;
    if(matriculados==74 || matriculados==106) dia=3;
    if(matriculados==86 || matriculados==118) dia=4;
    if(matriculados==83 || matriculados==115) dia=5;
    return dia;

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

void matricular_cursos(char ***Base_datos, char*** Matriculadas, unsigned short int *cantidad,int total){
    /*
    Base_datos: matriz que contiene toda la informacion
    Matriculadas: Matriz a llenar con las materias del usuario
    ***¿que cantidad de memoria almacenar? Es decir, ¿qué cantidad de materias reservar?
    R/ Asignar por defecto 10

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
                    Matriculadas[i][0][l] = '\0';
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
        int p = 33; // longitud  maxima de cada elemento
        for (int i = 0; i < n; i++) {
          cursos[i] = new char*[m];
            for (int j = 0; j < m; j++) {
                cursos[i][j] = new char[p];
            }
        }
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
                lista_individual[i] = new char[33];
            }
            //separa cadena leida y guardar en lista
            //convertir/formatear cadena a matriz(lista de arreglos char)
            split(cadena,lista_individual,';',5);
            for (int j = 0; j < 5; j++) {
                for(int k = 0;k<33;k++){
                    //añadir matriz anterior a matriz 3D
                    *(*(*(cursos+i)+j)+k) = *(*(lista_individual+j)+k);
                    //iterador i (representa la fila)está al inicio
                }
                *(*(*(cursos+i)+j)+33)='\0';
            }
            for(int i = 0; i<5;i++)delete[] lista_individual[i];
            delete[] lista_individual;
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

void mostrarCalendario(int *jornada, char***calendario) {
    cout << "     ";
    char dias[6]={'L','M','W','J','V','S'};
    for (int j = 0; j < 6; j++) cout <<"               "<< dias[j]<<"                ";
    cout << endl;
    if(jornada[0]>jornada[3]){
        for (int i = 0; i < 24-jornada[0]+jornada[3]; i++) {
            if(jornada[0]+i>23){
                if(jornada[0]+i>9) cout<<jornada[0]+i-24<<":"<<jornada[1]<<jornada[2]<<" ";
                else cout <<jornada[0]+i-24<<":"<<jornada[1]<<jornada[2];

                for (int j = 0; j < 6; j++) cout << calendario[i][j]; //aqui debe de ir la funcion que imprima el nombre
                cout << endl;
            }

            else{
                if(jornada[0]+i>9) cout<<jornada[0]+i<<":"<<jornada[1]<<jornada[2];
                else cout <<jornada[0]+i<<":"<<jornada[1]<<jornada[2]<<" ";

                for (int j = 0; j < 6; j++) cout << calendario[i][j]; //aqui debe de ir la funcion que imprima el nombre
                cout << endl;
            }
        }

    }

    else{
        for (int i = 0; i < jornada[3]-jornada[0]; i++) {
            if(jornada[0]+i>9) cout<<jornada[0]+i<<":"<<jornada[1]<<jornada[2];
            else cout <<jornada[0]+i<<":"<<jornada[1]<<jornada[2]<<" ";

            for (int j = 0; j < 6; j++) cout << calendario[i][j]; //aqui debe de ir la funcion que imprima el nombre
            cout << endl;
            }

    }
}

int crearJornada(int *jornada){
        unsigned short int horai,horaf,horas_jornada;
        bool valido;
        do{
        cout<<"introduzca la hora inicial de su jornada en formato 2400"<<endl;
        cin>>horai;
        cout<<"introduzca la hora final de su jornada en formato 2400"<<endl;
        cin>>horaf;

        if (horai>2400){
            valido=false;
            cout<<"Hora invalida"<<endl;
        }
        else valido=true;
        }while(!valido);

            jornada[0]=horai/100;//Hora
            jornada[1]=horai%100;
            jornada[2]=horai%10;
            jornada[3]=horaf/100;//Hora
            jornada[1]=horaf%100;
            jornada[2]=horaf%10;

        if(jornada[0]>jornada[3]) horas_jornada=24-jornada[0]+jornada[3];
        else horas_jornada=jornada[3]-jornada[0];
        return horas_jornada;
        }

void mostrar_informacion(char*** Base_datos,int total){
    //Muestra los nombres de la materia en una lista
    for(int i = 0;i<total;i++){
        cout << i+1 << ". "<<Base_datos[i][1] << "  "  << Base_datos[i][0];
        cout << endl;
    }
}
//-----
int indice_hora(char ***matriculados,int *jornada,int clase, int hora){
    short int horaClase=0,horaI;
    horaI=-1;
    horaClase=char_int(matriculados[clase][3+hora]);
    for(int j=0;j<jornada[3]-jornada[0];j++){//recorre todas las horas de la jornada
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
bool verificarDisponibilidad2(char ***calendario ,char ***matriculados,int *jornada, int indice) {
    unsigned short int rango,dia,horaD=0,horaI;

    for(int i=0;i<2;i++){
        dia=indice_dia(matriculados[indice][i+1]);

    rango=char_int(matriculados[indice][4])-char_int(matriculados[indice][3]);

    for(int i=0;i<rango;i++){
        horaI=indice_hora(matriculados,jornada,indice,i);
        char dsp[33] = "           Disponible           ";
        if(compare(calendario[horaI][dia],dsp)){
            horaD++;

        }
        else return false;
    }
    }
        if(horaD==2*(char_int(matriculados[indice][4])-char_int(matriculados[indice][3]))) return true;
        else return false;
}
bool verificarDisponibilidad(char ***calendario ,char ***matriculados,int *jornada, int indice) {
    unsigned short int rango,dia,horaD=0,horaI;

    for(int i=0;i<2;i++){
        dia=indice_dia(matriculados[indice][i+1]);

    rango=char_int(matriculados[indice][4])-char_int(matriculados[indice][3]);

    for(int i=0;i<rango;i++){
        horaI=indice_hora(matriculados,jornada,indice,i);
        char dsp[33] = "           Disponible           ";
        if(compare(calendario[horaI][dia],dsp)){
            horaD++;

        }
        else return false;
    }
    }
        if(horaD==2*(char_int(matriculados[indice][4])-char_int(matriculados[indice][3]))) return true;
        else return false;
}
void reservarHora(char ***calendario, char ***matriculados, int dia, int hora,char ***datos,int materia ){
    int l_final = 33;
    char *copia= new char[l_final];
    for(int i=0;i<63;i++){
        if(compare(*matriculados[materia],*datos[i])){
            beauty(datos[materia][1],copia,l_final);
            for(int k = 0; k<len_char(calendario[hora][dia]);k++){
                calendario[hora][dia][k]= copia[k];
            }
            break;
        }
    }
    delete[] copia;

}
void horas_independientes2(char ***Matriculados, char ***datos, char ***calendario, int num_clases
                     , int *jornada){
    //Ingresar hora por hora
    unsigned short int hora,indice_hora,dia,HTI;
    char dia_letra;
    for(int i = 0;i<num_clases;i++){
        HTI=char_int(datos[i][3]);
        while(HTI>0){
            cout << "Introduzca el DIA (L,M,W...) de " << datos[i][1] << endl;
            //FALTA HACER VALIDACION
            cin >> dia_letra;
            dia=indice_dia2(dia_letra);

            cout << "Introduzca la HORA(6,7,8...) de " << datos[i][1] << endl;
            //FALTA HACER VALIDACION
            cin >> hora;
            indice_hora = hora - jornada[0];
            char dsp[33] = "           Disponible           ";
            if(compare(calendario[indice_hora][dia],dsp)){
                reservarHora(calendario,Matriculados,dia,indice_hora,datos,i);
                HTI--;
                cout << "HORA MATRICULADA CON EXITO";
            }else{
                cout << "ESTA HORA NO ESTÁ DISPONIBLE. Prueba con otra.";
            }
            mostrarCalendario(jornada,calendario);
        }
    }
}
void horario_clases(char ***Matriculados, char ***datos, char ***calendario, int num_clases
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

          for(int j=0;j<63;j++){
              if(compare(*Matriculados[i],*datos[j])){ //puede elimin
                   //HTD=char_int(datos[i][2]);
                   cout<<"introduzca los dias de "<<datos[j][1]<<" en formato dia1-dia2"<<endl;
                   cin>>Matriculados[i][1];

                   split(Matriculados[i][1],dias,'-',2);

                   for(int h=0;h<2;h++){
                       for(int k=0;k<2;k++){
                           Matriculados[i][h+1][k] = dias[h][k];
                       }
                   }
                   cout<<"introduzca las horas de "<<datos[j][1]<<" en formato HoraInicial-Horafinal"<<endl;
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
                        i--;
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
//-----
int dec_10(int a){
    int dec=1;
    for(int i=1;i<a;i++){
        dec*=10;
    }
    return dec;
}

int len_char (char *p){
    int longitud=0;
    while(p[longitud]!= '\0'){
        longitud++;
    }
    return longitud;
}

int char_int(char *p){
    int dec=dec_10(len_char(p)), num=0,len=len_char(p);
    for(int i=0; i<=len;i++){
        num=num+(p[i]-48)*dec;
        dec/=10;
    }
    return num;
}

void int_char(int a, int b, char *p1){
    for(int i=b-1; i>=0;i--){
        *(p1+i)=(a%10)+48;
        a/=10;
    }
}

int len_num (int a){
    int longitud=1;
    while(a/10!=0){
        longitud++;
        a/=10;
    }
    return longitud;
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

void liberar_memoria(char*** matrix, int saltos){
    for(int i = 0; i<saltos+1;i++){
        for(int j = 0; j<5; j++){
            delete[] matrix[i][j];
        }
        delete[] matrix[i];
    }
    delete[] matrix;
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

    delete[] temp;
}
