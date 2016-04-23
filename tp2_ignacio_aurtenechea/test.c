#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {

    char nombre[50];
    int edad;
    int estado;
    int dni;

}EPersona;

void ordenarListaPorNombre(EPersona lista[]);
void mostrarTodasLasPersonas(EPersona lista[]);

int main()
{

EPersona listaPersonas[4];

listaPersonas[0].estado=1;
listaPersonas[1].estado=1;
listaPersonas[2].estado=1;
listaPersonas[3].estado=1;
strcpy(listaPersonas[0].nombre, "nacho");
strcpy(listaPersonas[1].nombre, "zzzesteban");
strcpy(listaPersonas[2].nombre, "aaaraaaoberto");
strcpy(listaPersonas[3].nombre, "eze");


//printf("%d",strcmp("Julian","Roberto"));




//mostrarTodasLasPersonas(listaPersonas);
ordenarListaPorNombre(listaPersonas);
mostrarTodasLasPersonas(listaPersonas);
return 0;
}

void ordenarListaPorNombre(EPersona lista[])
{   int ret, ret2;
    EPersona aux;
    for (int i=0;i<4-1; i++)
    {
        for (int j=i+1; j<4; j++)
        {

            ret=strcmp(lista[i].nombre,lista[j].nombre);
            printf("%s es mayor a: %s\n",lista[i].nombre, lista[j].nombre);
            printf("%d\n",ret );

            if(strcmp(lista[i].nombre,lista[j].nombre)>0)
            {
                aux=lista[i];
                lista[i]=lista[j];
                lista[j]=aux;

                printf("i:%d----j:%d\n",i,j );
            }
        }
    }
    //return lista;
}

void mostrarTodasLasPersonas(EPersona lista[])
{
    for(int i=0;i<4;i++)
    {
        if (lista[i].estado==1)
        {
            printf("Nombre: %s\n", lista[i].nombre);
            printf("Edad: %d\n", lista[i].edad);
            printf("Dni: %d\n\n", lista[i].dni);
        }
    }
}
