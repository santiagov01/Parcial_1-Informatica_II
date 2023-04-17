#include <iostream>

using namespace std;
void matricular_cursos(char***);
void show_cursos(char***);
void add_horas();
void mostrar_Calendario();

void guardar_calendario(char***);
void gestionar_horas_indp();
void iniciar_calendario();
int main()
{
    int opc = 0;
    char ***Matriculadas = nullptr;
    char ***Base_datos =nullptr;
    char ***Calendario = nullptr;

    bool matricula = false;
    bool init_calendar = false;

    guardar_calendario(Calendario);
    cout << "Ingresa opcion: (Pulse -1 para salir)" <<endl;
    cout << "1. Ver Cursos \n2. Matricular Materias\n3.Autogestionar Calendario";
    cin >> opc;
    while(opc!= -1){

        cin >> opc;
        switch (opc) {
        case 1:
            show_cursos(Base_datos);
            break;
        case 2:
            if(!init_calendar){ // verifica si ya se
                iniciar_calendario();
                init_calendar = true;
            }
            matricular_cursos(Matriculadas);//Matricula las materias
            add_horas();//Esta es la funcion para añadir horas de las clases
            matricula = true;
            break;
        case 3:
            if(matricula){
                gestionar_horas_indp();
                mostrar_Calendario();
            }else cout << "No has matriculado materias!!!";
            break;
        default:
            break;
        }
    }

}

