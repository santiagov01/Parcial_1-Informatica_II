#ifndef FUNCIONES_H
#define FUNCIONES_H

#endif // FUNCIONES_H
int len_num (int a);
int len_char (char *p);
int char_int(char *p);
void int_char(int a, int b, char *p1);
int dec_10(int a);
void split(char* cadena,char**subcadenas,char sep, int nf);

int saltoschar(char name_file[]);
void asignar_memoria(char***,int saltos);
void liberar_memoria(char***, int saltos);

bool compare(char a[], char b[]);
void matricular_cursos(char ***Base_datos, char*** Matriculadas, unsigned short int *cantidad,int total);
bool validar_materia(char*** Base_datos, char* codigo,int total, int*);
void mostrar_informacion(char*** Base_datos,int total);

int crearJornada(int *jornada);
void mostrarCalendario(int *jornada, char ***calendario);
void beauty(char *nombre,char *copia_bonita,int l_final);

void leer_cursos(char ***cursos,char[]);
void reservarHora(char ***calendario, char ***matriculados, int dia, int hora,char*** datos,int materia );
bool verificarDisponibilidad(char ***calendario ,char ***matriculados,int *jornada, int indice);
void horario_clases(char ***Matriculados, char ***datos, char ***calendario, int num_clases, int *jornada);
int indice_hora(char ***matriculados,int *jornada,int clase, int hora);
int indice_dia(char *matriculados);
void RestarHora(char *Matricula);

void rellenar(char ***datos, char ***calendario, char ***Matriculados, int num_clases, int *jornada);

int indice_dia2(char matriculados);
void horario_clases2(char ***Matriculados, char ***datos, char ***calendario, int num_clases , int *jornada,int saltos);
void reservarHora2(char ***calendario, int dia, int hora,char ***datos,int index );
void reservarIndep(char ***calendario, int dia, int hora,char ***datos,int index );
void formato_indpendientes(char *nombre_materia,char *copia_indp,int l_final);
