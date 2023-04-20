#ifndef FUNCIONES_H
#define FUNCIONES_H

#endif // FUNCIONES_H
int len_num (int a);
int len_char (char *p);
int char_int(char *p);
void int_char(int a, int b, char *p1);
int dec_10(int a);
void split(char* cadena,char**subcadenas,char sep, int nf);
bool compare(char a[], char b[]);
int saltoschar(char name_file[]);
void liberar_memoria(char***, int saltos);

void beauty(char *nombre,char *copia_bonita,int l_final);
void mostrar_informacion(char*** Base_datos,int total);
void mostrarCalendario(int *jornada, char ***calendario);

int crearJornada(int *jornada);
void leer_cursos(char ***cursos,char[]);

void validar_dia(char*** datos, int *index, char dia_letra, unsigned short *dia);
void validar_hora(char*** datos, int * jornada,short int *indice_hora, int index,unsigned short int hora);
void matricular_cursos(char ***Base_datos, char*** Matriculadas, unsigned short int *cantidad,int total);
bool validar_materia(char*** Base_datos, char* codigo,int total, int*);
int indice_dia2(char matriculados);
void horario_clases2(char ***Matriculados, char ***datos, char ***calendario, int num_clases , int *jornada,int saltos);
void reservarHora2(char ***calendario, int dia, int hora,char ***datos,int index );

void reservarIndep(char ***calendario, int dia, int hora,char ***datos,int index );
void formato_indpendientes(char *nombre_materia,char *copia_indp,int l_final);

void reservarHora(char ***calendario, char ***matriculados, int dia, int hora,char*** datos,int materia );
bool verificarDisponibilidad(char ***calendario ,char ***matriculados,int *jornada, int indice);
void horario_clases(char ***Matriculados, char ***datos, char ***calendario, int num_clases, int *jornada);
int indice_hora(char ***matriculados,int *jornada,int clase, int hora);
int indice_dia(char *matriculados);
void RestarHora(char *Matricula);
void rellenar(char ***datos, char ***calendario, char ***Matriculados, int num_clases, int *jornada);
void asignar_memoria(char***,int saltos);
