#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.h"
/*
al compilar el compilador devuelve warning: incompatible implicit declaration of built-in function
de casi todas, sino todas las funciones. Creo que los ficheros con funciones y las directivas #include estan
correctos. O por lo menos como nos enseñaron.
O por ahí es por las directivas #ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED que no se como funcionan.
*/

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
