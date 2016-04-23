#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED


int obtenerEspacioLibre(EPersona lista[]);
int buscarPorDni(EPersona lista[], int dni);
int buscarPorDni(EPersona lista[], int dni);
void mostrarTodasLasPersonas(EPersona lista[]);
void inicializarGrupoDePersonas(EPersona lista[]);
void ordenarListaPorNombre(EPersona lista[]);
int sistemaNoVacio(EPersona lista[]);
void imprimirGrafico(EPersona grupo[]);
void hardcodeada(EPersona lista[]);


/*
Puse las funciones dentro del fichero funciones.h y no en funciones.c porque sino no compilaba, y no se porque.
tampoco se que significan las instrucciones #ifndef FUNCIONES_H_INCLUDED #define FUNCIONES_H_INCLUDED quizas es por eso.
*/

/**
 * Obtiene el primer indice libre del array.
 * @param lista: el array de EPersona se pasa como parametro.
 * @return el primer indice disponible o -1 si no encuentra lugar.
 */
int obtenerEspacioLibre(EPersona lista[])
{
    int indice=-1;
    for (int i=0; i<20; i++)
    {
        if (lista[i].estado ==0)
        {
            indice=i;
            break;
        }
    }
    return indice;
}

/**
 * Obtiene el indice que coincide con el dni pasado por parametro.
 * @param lista: el array de EPersona se pasa como parametro.
 * @param dni: el dni a ser buscado en el array.
 * @return el indice en donde se encuentra el elemento que coincide con el parametro dni
 */
int buscarPorDni(EPersona lista[], int dni)
{
    int indice=-1;

    for (int i=0; i<20; i++)
    {
        if (lista[i].estado==1 && lista[i].dni==dni)
        {
            indice=i;
            break;
        }
    }

     return indice;
}


/**
 * Setea el campo estado en cero para todos los tipos EPersona del array.
 * @param lista: el array de tipo EPersona a inicializar.
 */
void inicializarGrupoDePersonas(EPersona lista[])
{
    for (int i=0; i<20; i++)
    {
        lista[i].estado=0;
    }
}

/**
 * Carga los campos con datos para todos los tipos EPersona del array. Se usa para testear el programa.
 * @param lista: el array de tipo EPersona a inicializar.
 */
void hardcodeada(EPersona lista[])
{
     for (int i=0; i<20; i++)
    {
        lista[i].edad=20+i;
        lista[i].dni=i;
        lista[i].estado=1;
    }

    strcpy(lista[0].nombre, "Ignacio");
    strcpy(lista[1].nombre, "Jorge");
    strcpy(lista[2].nombre, "Ruben");
    strcpy(lista[3].nombre, "Maximo");
    strcpy(lista[4].nombre, "Jose");
    strcpy(lista[5].nombre, "Federico");
    strcpy(lista[6].nombre, "Sofia");
    strcpy(lista[7].nombre, "Melina");
    strcpy(lista[8].nombre, "Josefina");
    strcpy(lista[9].nombre, "Talia");
    lista[9].edad=15;
    strcpy(lista[10].nombre, "Tamara");
    strcpy(lista[11].nombre, "Ezequiel");
    strcpy(lista[12].nombre, "Roberto");
    strcpy(lista[13].nombre, "Gonzalo");
    strcpy(lista[14].nombre, "Fernando");
    strcpy(lista[15].nombre, "Carolina");
    strcpy(lista[16].nombre, "Lucas");
    strcpy(lista[17].nombre, "Sabrina");
    strcpy(lista[18].nombre, "Eduardo");
    strcpy(lista[19].nombre, "Pedro");

}

/**
 * Muestra los campos Nombre, Edad y Dni para todos los tipos EPersona que se encuentran en el parametro lista.
 * @param lista: el array con elementos de tipo EPersona.
 */
void mostrarTodasLasPersonas(EPersona lista[])
{
    for(int i=0;i<20;i++)
    {
        if (lista[i].estado==1)
        {
            printf("Nombre: %s\n", lista[i].nombre);
            printf("Edad: %d\n", lista[i].edad);
            printf("Dni: %d\n\n", lista[i].dni);
        }
    }
}


/**
 * Ordena el array de elementos del tipo EPersona por nombre.
 * @param lista: el array de elementos del tipo EPersona.
 */
void ordenarListaPorNombre(EPersona lista[])
{
    EPersona aux;
    for (int i=0;i<20-1; i++)
    {
        for (int j=i+1; j<20; j++)
        {
            if(strcmp(lista[i].nombre,lista[j].nombre)>0)
            {
                aux=lista[i];
                lista[i]=lista[j];
                lista[j]=aux;
            }
        }
    }
}

/**
 * Imprime los campos Nombre, Edad y Dni de los elementos del tipo EPersona pasados como parametros en el array lista.
 * @param lista: el array de elementos del tipo EPersona.
 */
void imprimirListaOrdenadaPorNombre(EPersona lista[])
{
    EPersona aux[20];
    //copy
    for(int i=0;i<20;i++)
    {
        aux[i]=lista[i];
    }
    ordenarListaPorNombre(aux);
    mostrarTodasLasPersonas(aux);
}


/**
 * Imprime los campos Nombre, Edad y Dni de los elementos del tipo EPersona pasados como parametros en el array lista.
 * @param lista: el array de elementos del tipo EPersona.
 * @return 1 si al menos 1 elemento del tipo EPersona tiene el campo estado igual a 1, o 0 (cero) si todos tienen el mismo campo igual a 0 (cero).
 */
int sistemaNoVacio(EPersona lista[])
{
    int flag=0;
    for(int i=0; i<20; i++)
    {
        if(lista[i].estado==1)
        {
            flag=1;
            break;
        }
    }
    return flag;
}

/**
 * Imprime el grafico en forma de columnas que indican la cantidad de elementos del tipo EPersona segun el rango de edad.
 * @param lista: el array de elementos del tipo EPersona.
 */
void imprimirGrafico(EPersona grupo[])
{
    char grafico1[20]={" "};
    char grafico2[20]={" "};
    char grafico3[20]={" "};
    int cant_menores_18=0, cant_entre_19_35=0, cant_mayores_35=0;

    cant_entre_19_35=0;
    cant_mayores_35=0;
    cant_menores_18=0;

    for(int i=0;i<20;i++)
    {
        grafico1[i]=32;//espacios en blanco
        grafico2[i]=32;
        grafico3[i]=32;
    }

    for(int i=0;i<20;i++)
    {
        if(grupo[i].edad<18 && grupo[i].estado==1)
        {
            cant_menores_18++;
        }
        else if( (grupo[i].edad>=19 && grupo[i].edad<=35) && grupo[i].estado==1)
        {
            cant_entre_19_35++;
        }
        else if (grupo[i].edad>35 && grupo[i].estado==1)
        {
            cant_mayores_35++;
        }
    }
    for(int i=0;i<cant_menores_18;i++)
    {
        grafico1[i]=42;//caracter asterisco
    }
    for(int i=0;i<cant_entre_19_35;i++)
    {
        grafico2[i]=42;
    }
    for(int i=0;i<cant_mayores_35;i++)
    {
        grafico3[i]=42;
    }
    printf("\n\n");
    for (int i=19; i>=0; i--)
    {
        if(!(grafico1[i]==32 && grafico2[i]==32 && grafico3[i] == 32));
        printf("\t%c\t\t%c\t\t%c\n",grafico1[i],grafico2[i],grafico3[i]);
        printf("menores a 18 | entre_19_y_35 | mayores_a_35\n");
    }
}

#endif // FUNCIONES_H_INCLUDED
