#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct {

    char nombre[50];
    int edad;
    int estado;
    int dni;

}EPersona;

#include "funciones.h"  // la inclui en este lugar porque sino no compilaba, no reconocia el tipo de dato EPersona en las funciones.

int obtenerEspacioLibre(EPersona lista[]);
int buscarPorDni(EPersona lista[], int dni);
int buscarPorDni(EPersona lista[], int dni);
void mostrarTodasLasPersonas(EPersona lista[]);
void inicializarGrupoDePersonas(EPersona lista[]);
void ordenarListaPorNombre(EPersona lista[]);
int sistemaNoVacio(EPersona lista[]);
void imprimirGrafico(EPersona grupo[]);

void hardcodeada(EPersona lista[]);


int main()
{
    char seguir='s';
    int opcion=0;
    EPersona grupo[20];
    int indice=-1, dni=0;

    inicializarGrupoDePersonas(grupo);

    //Descomentar la linea siguiente para que comience el sistema cargado con datos.
    //hardcodeada(grupo);

    while(seguir=='s')
    {
        printf("1- Agregar persona\n");
        printf("2- Borrar persona\n");
        printf("3- Imprimir lista ordenada por nombre\n");
        printf("4- Imprimir grafico de edades\n\n");
        printf("5- Salir\n");

        scanf("%d",&opcion);

        system("cls");

        switch(opcion)
        {
            case 1:
                indice=obtenerEspacioLibre(grupo);

                if(indice==-1)
                {
                    printf("No hay espacio libre en el sistema.\n");
                }
                else
                {
                    printf("Ingrese el nombre de la nueva persona: ");
                    fflush(stdin);
                    gets(grupo[indice].nombre);

                    printf("Ingrese la edad de la nueva persona: ");
                    fflush(stdin);
                    scanf("%d", &grupo[indice].edad);

                    printf("Ingrese el dni de la nueva persona: ");
                    fflush(stdin);
                    scanf("%d", &grupo[indice].dni);

                    grupo[indice].estado=1;
                }
                break;

            case 2:


                if (sistemaNoVacio(grupo))
                {

                    printf("Ingrese el dni de la persona a eliminar");
                    fflush(stdin);
                    scanf("%d", &dni);
                    indice=buscarPorDni(grupo,dni);

                    if (indice==-1)
                    {
                        printf("La persona con ese dni no se encuentra en el sistema.\n\n");
                    }
                    else
                    {
                        grupo[indice].estado=0;
                    }
                }
                else
                {
                  printf("El sistema esta vacio.\n\n");
                }
                break;

            case 3:

                if (sistemaNoVacio(grupo))
                {
                    imprimirListaOrdenadaPorNombre(grupo);
                }
                else
                {
                  printf("El sistema esta vacio.\n\n");
                }

                break;

            case 4:

                if (sistemaNoVacio(grupo))
                {
                    imprimirGrafico(grupo);
                }
                else
                {
                    printf("El sistema esta vacio.\n\n");
                }


                break;

            case 5:
                seguir = 'n';
                break;

            default:
                printf("La opcion ingresada no es valida.\n");
                break;
        }
   }
    return 0;
}
