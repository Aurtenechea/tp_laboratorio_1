#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED


typedef struct {

    char nombre[50];
    int edad;
    int estado;
    int dni;

}EPersona;


int obtenerEspacioLibre(EPersona lista[]);
int buscarPorDni(EPersona lista[], int dni);
int buscarPorDni(EPersona lista[], int dni);
void mostrarTodasLasPersonas(EPersona lista[]);
void inicializarGrupoDePersonas(EPersona lista[]);
void ordenarListaPorNombre(EPersona lista[]);
int sistemaNoVacio(EPersona lista[]);
void imprimirGrafico(EPersona grupo[]);
void hardcodeada(EPersona lista[]);



#endif // FUNCIONES_H_INCLUDED
