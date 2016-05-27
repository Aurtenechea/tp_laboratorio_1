#include <stdio.h>
#include <stdlib.h>
typedef struct{
    char* titulo;
    char* genero;
    int duracion;
    char* descripcion;
    int puntaje;
    char* linkImagen;
    int id;

}eMovie;
typedef struct{
    char titulo[1001];
    char genero[1001];
    int duracion;
    char descripcion[5001];
    int puntaje;
    char linkImagen[1001];
    int id;
}eMovieEstatico;

int buscarIdEMovie (eMovie* eMoviePtrArray, int cant, int id);
eMovie* cargarEMovie(eMovie * eMoviePtrArray, eMovie eMovieAux, int* cant);
void modificarEMovie(eMovie* eMoviePtrArray, int indice, int opcion, char* nuevoValor);
void borrarEMovie(eMovie* eMoviePtrArray, int* cant, int indice);
void generarHtml(eMovie* eMoviePtrArray, int cant, char* nombreFichero);

eMovie* hardcodeada(eMovie* eMoviePtrArray, int* cant);
void imprimirArrayEMovie (eMovie* eMoviePtrArray, int cant);

int validarRangoInt(int miNumero, int min, int max);
int esNumerico(char str[]);
int esAlfaNumericoPuntoGuion(char str[]);

eMovie* leerBinArrayEMovies(int cant, int* ptrCantGlobal, char* nombreArchivo);
void guardarBinArrayEMovies(eMovie* eMoviePtrArray,int cant, char* nombreArchivo);
int leerBinCantArrayEMovies(char* nombreArchivo);
void guardarBinCantArrayEMovies(int cant, char* nombreArchivo);
