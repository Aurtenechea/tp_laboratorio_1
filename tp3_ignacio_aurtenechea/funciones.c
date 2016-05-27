#include "funciones.h"

/**
 * \brief Carga una pelicula en el "array" de peliculas. O Lo inicializa en un elemento.
 * \param eMoviePtrArray El puntero que tiene la direccion del "array"
 * \param eMovieAux La eMovie con los datos a cargar
 * \param cant Puntero con la direccion de la variable cant del main para poder incrementarla desde la funcion.
 * \return retorna la nueva direccion de memoria del array.
 */
eMovie* cargarEMovie(eMovie * eMoviePtrArray, eMovie eMovieAux, int* cant)
{
    (*cant)++;
    if((*cant)-1==0)
    {
        eMoviePtrArray=(eMovie*)malloc(sizeof(eMovie)* (*cant));
        if(eMoviePtrArray == NULL)
        {
            printf("\nERROR! Error de memoria.");
            exit(1);
        }
    }
    else
    {
        eMoviePtrArray=(eMovie*)realloc(eMoviePtrArray, sizeof(eMovie)* (*cant));
        if(eMoviePtrArray == NULL)
        {
            printf("\nERROR! Error de memoria.");
            exit(1);
        }
    }
//copio el titulo-----------
    (eMoviePtrArray+((*cant)-1))->titulo=(char*) malloc( sizeof(char) * ( strlen(eMovieAux.titulo) + 1 ) );
    if( (eMoviePtrArray+((*cant)-1))->titulo == NULL)
    {
        printf("\nERROR! Error de memoria.");
        exit(1);
    }
    strcpy((eMoviePtrArray+((*cant)-1))->titulo, eMovieAux.titulo);
//copio la descripcion-----------
    (eMoviePtrArray+((*cant)-1))->descripcion=(char*) malloc( sizeof(char) * ( strlen(eMovieAux.descripcion) + 1 ) );
    if( (eMoviePtrArray+((*cant)-1))->descripcion == NULL)
    {
        printf("\nERROR! Error de memoria.");
        exit(1);
    }
    strcpy((eMoviePtrArray+((*cant)-1))->descripcion,eMovieAux.descripcion);
//copio el genero-------
    (eMoviePtrArray+((*cant)-1))->genero=(char*) malloc( sizeof(char) * ( strlen(eMovieAux.genero) + 1 ) );
    if( (eMoviePtrArray+((*cant)-1))->genero == NULL)
    {
        printf("\nERROR! Error de memoria.");
        exit(1);
    }
    strcpy((eMoviePtrArray+((*cant)-1))->genero,eMovieAux.genero);
//copio link imagen-------
    (eMoviePtrArray+((*cant)-1))->linkImagen=(char*) malloc( sizeof(char) * ( strlen(eMovieAux.descripcion) + 1 ) );
    if( (eMoviePtrArray+((*cant)-1))->linkImagen == NULL)
    {
        printf("\nERROR! Error de memoria.");
        exit(1);
    }
    strcpy((eMoviePtrArray+((*cant)-1))->linkImagen,eMovieAux.linkImagen);
//copio duracion, puntaje e id-------
    (eMoviePtrArray+(*cant)-1)->duracion=eMovieAux.duracion;
    (eMoviePtrArray+(*cant)-1)->puntaje=eMovieAux.puntaje;
    (eMoviePtrArray+(*cant)-1)->id=eMovieAux.id;
    return eMoviePtrArray;
}

/**
 * \brief busca en el "array" de peliculas si existe una con ese id
 * \param eMoviePtrArray El puntero que tiene la direccion del "array"
 * \param cant cantidad de peliculas del array
 * \param id id a buscar
 * \return retorna -1 si no lo encuentra o el indice donde se encuentra.
 */
int buscarIdEMovie (eMovie* eMoviePtrArray, int cant, int id)
{
    int result=-1;

    for(int i=0;i<cant;i++)
    {
        if( (eMoviePtrArray+i)->id == id )
        {
            result=i;
        }
    }
    return result;
}

/**
 * \brief imprime el array
 * \param eMoviePtrArray El puntero que tiene la direccion del "array"
 * \param cant cantidad de peliculas del array
 */
void imprimirArrayEMovie (eMovie* eMoviePtrArray, int cant)
{
    for(int i=0; i<cant;i++)
    {
        printf("\neMovie en el indice %d del array.", i);
        printf("\nTitulo: %s",(eMoviePtrArray+i)->titulo);
        printf("\nDescripcion: %s",(eMoviePtrArray+i)->descripcion);
        printf("\nGenero: %s",(eMoviePtrArray+i)->genero);
        printf("\nlinkImagen: %s",(eMoviePtrArray+i)->linkImagen);
        printf("\nDuracion: %d",(eMoviePtrArray+i)->duracion);
        printf("\nPuntaje: %d",(eMoviePtrArray+i)->puntaje);
        printf("\nId: %d",(eMoviePtrArray+i)->id);
        printf("\n\n");
    }
}

/**
 * \brief carga el "array con 2 peliculas"
 * \param eMoviePtrArray El puntero que tiene la direccion del "array"
 * \param cant direccion de memoria de la variable cant del main
 * \return retorna la nueva direccion de memoria del array.
 */
eMovie* hardcodeada(eMovie* eMoviePtrArray, int* cant)
{
    eMovie eMovieAux;
    eMovieAux.titulo=(char*)malloc(sizeof(char) * (strlen("Titulo eMovie.") + 1) );
    strcpy(eMovieAux.titulo, "Titulo eMovie.");
    eMovieAux.descripcion=(char*)malloc(sizeof(char) * (strlen("Descripcion eMovie.") + 1) );
    strcpy(eMovieAux.descripcion, "Descripcion eMovie.");
    eMovieAux.genero=(char*)malloc(sizeof(char) * (strlen("Genero prueba.") + 1) );
    strcpy(eMovieAux.genero, "Genero prueba.");
    eMovieAux.linkImagen=(char*)malloc(sizeof(char) * (strlen("Link imagen prueba.") + 1) );
    strcpy(eMovieAux.linkImagen, "Link imagen prueba.");
    eMovieAux.duracion=50;
    eMovieAux.puntaje=10;
    eMovieAux.id=1;

    eMoviePtrArray=cargarEMovie(eMoviePtrArray, eMovieAux, cant);
    eMovieAux.titulo=(char*)malloc(sizeof(char) * (strlen("Titulo eMovie2.") + 1) );
    strcpy(eMovieAux.titulo, "Titulo eMovie2.");
    eMovieAux.descripcion=(char*)malloc(sizeof(char) * (strlen("Descripcion eMovie2.") + 1) );
    strcpy(eMovieAux.descripcion, "Descripcion eMovie2.");
    eMovieAux.genero=(char*)malloc(sizeof(char) * (strlen("Genero prueba2.") + 1) );
    strcpy(eMovieAux.genero, "Genero prueba2.");
    eMovieAux.linkImagen=(char*)malloc(sizeof(char) * (strlen("Link imagen prueba2.") + 1) );
    strcpy(eMovieAux.linkImagen, "Link imagen prueba2.");
    eMovieAux.duracion=51;
    eMovieAux.puntaje=11;
    eMovieAux.id=2;

    eMoviePtrArray=cargarEMovie(eMoviePtrArray, eMovieAux, cant);
    return eMoviePtrArray;
}
/**
 * \brief Borra una pelicula del array"
 * \param eMoviePtrArray El puntero que tiene la direccion del "array"
 * \param cant direccion de memoria de la variable cant del main
 * \param indice indice de la pelicula a borrar.
 * \return retorna la nueva direccion de memoria del array.
 */
void borrarEMovie(eMovie* eMoviePtrArray, int* cant, int indice)
{
    eMovie eMovieAux;
    eMovieAux=*(eMoviePtrArray+indice);
    *(eMoviePtrArray+indice)=*(eMoviePtrArray+( (*cant)-1 ) );
    eMoviePtrArray=(eMovie*)realloc(eMoviePtrArray, sizeof(eMovie) * ( (*cant)-1 ) );
    (*cant)--;
}

/**
 * \brief genera el archivo con codigo html
 * \param eMoviePtrArray El puntero que tiene la direccion del "array"
 * \param cant cantidad de elementos del array
 * \param nombreFichero puntero al nombre del fichero
 */
void generarHtml(eMovie* eMoviePtrArray, int cant, char* nombreFichero)
{
    char* texto;
    FILE * f;
    f=fopen(nombreFichero,"w");
    fclose(f);
    f=fopen(nombreFichero,"a");

    texto=(char*)malloc( ( strlen("<!DOCTYPE html><!-- Template by Quackit.com --><html lang='en'><head><meta charset='utf-8'><meta http-equiv='X-UA-Compatible' content='IE=edge'><meta name='viewport' content='width=device-width, initial-scale=1'><!-- The above 3 meta tags *must* come first in the head; any other head content must come *after* these tags --><title>Lista peliculas</title><!-- Bootstrap Core CSS --><link href='css/bootstrap.min.css' rel='stylesheet'><!-- Custom CSS: You can use this stylesheet to override any Bootstrap styles and/or apply your own styles --><link href='css/custom.css' rel='stylesheet'><!-- HTML5 Shim and Respond.js IE8 support of HTML5 elements and media queries --><!-- WARNING: Respond.js doesn't work if you view the page via file:// --><!--[if lt IE 9]><script src='https://oss.maxcdn.com/libs/html5shiv/3.7.0/html5shiv.js'></script><script src='https://oss.maxcdn.com/libs/respond.js/1.4.2/respond.min.js'></script><![endif]--></head><body><div class='container'><div class='row'>\n") + 1 ) * sizeof(char) );
    strcpy(texto, "<!DOCTYPE html><!-- Template by Quackit.com --><html lang='en'><head><meta charset='utf-8'><meta http-equiv='X-UA-Compatible' content='IE=edge'><meta name='viewport' content='width=device-width, initial-scale=1'><!-- The above 3 meta tags *must* come first in the head; any other head content must come *after* these tags --><title>Lista peliculas</title><!-- Bootstrap Core CSS --><link href='css/bootstrap.min.css' rel='stylesheet'><!-- Custom CSS: You can use this stylesheet to override any Bootstrap styles and/or apply your own styles --><link href='css/custom.css' rel='stylesheet'><!-- HTML5 Shim and Respond.js IE8 support of HTML5 elements and media queries --><!-- WARNING: Respond.js doesn't work if you view the page via file:// --><!--[if lt IE 9]><script src='https://oss.maxcdn.com/libs/html5shiv/3.7.0/html5shiv.js'></script><script src='https://oss.maxcdn.com/libs/respond.js/1.4.2/respond.min.js'></script><![endif]--></head><body><div class='container'><div class='row'>\n" );
    fwrite(texto,sizeof(char),strlen(texto),f);

    for(int i=0;i<cant;i++)
    {
        texto=(char*)malloc( ( strlen("<!-- Repetir esto para cada pelicula --><article class='col-md-4 article-intro'><a href='#'><img class='img-responsive img-rounded' src='") + 1 ) * sizeof(char) );
        strcpy(texto, "<!-- Repetir esto para cada pelicula --><article class='col-md-4 article-intro'><a href='#'><img class='img-responsive img-rounded' src='");
        texto=(char*)realloc(texto, (strlen(texto)+strlen( ( eMoviePtrArray+i )->linkImagen ) +1 ) * sizeof(char) );
        strcat(texto, (eMoviePtrArray+i)->linkImagen);
        texto=(char*)realloc(texto, ( strlen(texto) + strlen("'alt=''></a><h3><a href='#'>") + 1) * sizeof(char));
        strcat(texto, "'alt=''></a><h3><a href='#'>" );
        texto=(char*)realloc(texto, (strlen(texto) + strlen((eMoviePtrArray+i)->titulo) + 1) * sizeof(char));
        strcat(texto, (eMoviePtrArray+i)->titulo);
        texto=(char*)realloc(texto, (strlen(texto) + strlen("</a></h3><ul><li>Género:") + 1) * sizeof(char));
        strcat(texto, "</a></h3><ul><li>Género:" );
        texto=(char*)realloc(texto, (strlen(texto) + strlen((eMoviePtrArray+i)->genero) + 1) * sizeof(char));
        strcat(texto, (eMoviePtrArray+i)->genero);
        texto=(char*)realloc(texto, (strlen(texto) + strlen("</li><li>Puntaje:") + 1) * sizeof(char));
        strcat(texto, "</li><li>Puntaje:" );
        char aux[20];
        sprintf(aux, "%d", (eMoviePtrArray+i)->puntaje);
        texto=(char*)realloc(texto, (strlen(texto) + strlen(aux) + 1) * sizeof(char));
        strcat(texto, aux);
        texto=(char*)realloc(texto, (strlen(texto) + strlen("</li><li>Duración:") + 1) * sizeof(char));
        strcat(texto, "</li><li>Duración:" );
        sprintf(aux, "%d", (eMoviePtrArray+i)->duracion);
        texto=(char*)realloc(texto, (strlen(texto) + strlen(aux) + 1) * sizeof(char));
        strcat(texto, aux);
        texto=(char*)realloc(texto, (strlen(texto) + strlen("</li></ul><p>") + 1) * sizeof(char));
        strcat(texto, "</li></ul><p>" );
        texto=(char*)realloc(texto, (strlen(texto) + strlen((eMoviePtrArray+i)->descripcion) + 1) * sizeof(char));
        strcat(texto, (eMoviePtrArray+i)->descripcion);
        texto=(char*)realloc(texto, (strlen(texto) + strlen("</p></article><!-- Repetir esto para cada pelicula-->") + 1) * sizeof(char));
        strcat(texto, "</p></article><!-- Repetir esto para cada pelicula-->");
        texto=(char*)realloc(texto, (strlen(texto) + strlen("\n") + 1) * sizeof(char));
        strcat(texto, "\n");
        //printf("\ntexto: %s", texto);
        fwrite(texto,sizeof(char),strlen(texto),f);
    }
    texto=(char*)malloc( ( strlen("</div><!-- /.row --></div><!-- /.container --><!-- jQuery --><script src='js/jquery-1.11.3.min.js'></script><!-- Bootstrap Core JavaScript --><script src='js/bootstrap.min.js'></script><!-- IE10 viewport bug workaround --><script src='js/ie10-viewport-bug-workaround.js'></script><!-- Placeholder Images --><script src='js/holder.min.js'></script></body></html>\n") + 1 ) * sizeof(char) );
    strcpy(texto, "</div><!-- /.row --></div><!-- /.container --><!-- jQuery --><script src='js/jquery-1.11.3.min.js'></script><!-- Bootstrap Core JavaScript --><script src='js/bootstrap.min.js'></script><!-- IE10 viewport bug workaround --><script src='js/ie10-viewport-bug-workaround.js'></script><!-- Placeholder Images --><script src='js/holder.min.js'></script></body></html>\n" );
    fwrite(texto,sizeof(char),strlen(texto),f);
    fclose(f);
}

/**
 * \brief Permite modificar los valores de una eMovie del "array"
 * \param eMoviePtrArray El puntero que tiene la direccion del "array"
 * \param indice indice de la pelicula a modificar.
 * \param opcion permite elegir el campo a modificar.
 * \param texto con el nuevo valor que remplazara al anterior.
 */
void modificarEMovie(eMovie* eMoviePtrArray, int indice, int opcion, char* nuevoValor)
{
    switch(opcion)
    {
        case 1:
            printf("Titulo actual eMovie a modificar: %s", (eMoviePtrArray+indice)->titulo);
            printf("\nIndice donde se encuentra la del id solicitado: %d", indice);
            (eMoviePtrArray+indice)->titulo=(char*)malloc( ( strlen(nuevoValor) + 1 ) * sizeof(char) );
            strcpy( (eMoviePtrArray+indice)->titulo, nuevoValor);
            printf("\nTitulo de la eMovie modificada: %s", (eMoviePtrArray+indice)->titulo);
            break;
        case 2:
            (eMoviePtrArray+indice)->genero=(char*)malloc( ( strlen(nuevoValor) + 1 ) * sizeof(char) );
            strcpy( (eMoviePtrArray+indice)->genero, nuevoValor);
            printf("\nGenero de la eMovie modificada: %s", (eMoviePtrArray+indice)->genero);
            break;
        case 3:
            printf("Descripcion actual de la emovie: %s", (eMoviePtrArray+indice)->descripcion);
            printf("\nIndice donde se encuentra la del id solicitado: %d", indice);
            (eMoviePtrArray+indice)->descripcion=(char*)malloc( ( strlen(nuevoValor) + 1 ) * sizeof(char) );
            strcpy( (eMoviePtrArray+indice)->descripcion, nuevoValor);
            printf("\nDescripcion de la eMovie modificada: %s", (eMoviePtrArray+indice)->descripcion);
            break;
        case 4:
            (eMoviePtrArray+indice)->linkImagen=(char*)malloc( ( strlen(nuevoValor) + 1 ) * sizeof(char) );
            strcpy( (eMoviePtrArray+indice)->linkImagen, nuevoValor);
            printf("\nLinkImagen de la eMovie modificada: %s", (eMoviePtrArray+indice)->linkImagen);
            break;
        case 5:
            (eMoviePtrArray+indice)->duracion=atoi(nuevoValor);
            printf("\nDuracion de la eMovie modificada: %d", (eMoviePtrArray+indice)->duracion);
            break;
        case 6:
            (eMoviePtrArray+indice)->puntaje=atoi(nuevoValor);
            printf("\nPuntaje de la eMovie modificada: %d", (eMoviePtrArray+indice)->puntaje);
            break;
        case 7:
            (eMoviePtrArray+indice)->id=atoi(nuevoValor);
            printf("\nId de la eMovie modificada: %d", (eMoviePtrArray+indice)->id);
            break;
        }
}
/**
 * \brief Verifica si el valor recibido es numérico
 * \param str Array con la cadena a ser analizada
 * \return 1 si es númerico y 0 si no lo es
 *
 */
int esNumerico(char str[])
{
   int i=0;
   while(str[i] != '\0')
   {
       if(str[i] < '0' || str[i] > '9')
           return 0;
       i++;
   }
   return 1;
}
/**
 * \brief Verifica si el valor recibido contiene solo letras, números, guines o puntos.
 * \param str Array con la cadena a ser analizada
 * \return 1 si lo verifica, y 0 si no.
 *
 */
int esAlfaNumericoPuntoGuion(char str[])
{
   int i=0;
   while(str[i] != '\0')
   {
       if((str[i] != ' ') && (str[i] < 'a' || str[i] > 'z') && (str[i] < 'A' || str[i] > 'Z') && (str[i] < '0' || str[i] > '9') && str[i]!='.' && str[i]!='-' && str[i]!='_')
       {
            return 0;
       }
       i++;
   }
   return 1;
}

/**
 * \brief Verifica si el valor recibido esta dentro del rango
 * \param miNumero numero a comprobar
 * \param min el minimo
 * \param max el maximo
 * \return 1 si lo verifica, y 0 si no.
 *
 */
int validarRangoInt(int miNumero, int min, int max)
{
    int result=0;
    if( miNumero >= min && miNumero <= max )
    {
        result = 1;
    }
    return result;
}
/**
 * \brief guarda en un archivo binario el array de eMovies
 * \param eMoviePtrArray El puntero que tiene la direccion del "array"
 * \param cant cantidad de peliculas del array
 * \param nombreArchivo nombre del archivo a crear.
 */
void guardarBinArrayEMovies(eMovie* eMoviePtrArray,int cant, char* nombreArchivo)
{
    FILE * f;
    eMovieEstatico auxEMovieEstatico;

    f=fopen(nombreArchivo,"wb");
    fclose(f);
    f=fopen(nombreArchivo,"ab");

    for(int i=0;i<cant;i++)
   {
        strcpy(auxEMovieEstatico.titulo, (eMoviePtrArray+i)->titulo);
        strcpy(auxEMovieEstatico.descripcion, (eMoviePtrArray+i)->descripcion);
        strcpy(auxEMovieEstatico.genero, (eMoviePtrArray+i)->genero);
        strcpy(auxEMovieEstatico.linkImagen, (eMoviePtrArray+i)->linkImagen);
        auxEMovieEstatico.duracion=(eMoviePtrArray+i)->duracion;
        auxEMovieEstatico.id=(eMoviePtrArray+i)->id;
        auxEMovieEstatico.puntaje=(eMoviePtrArray+i)->puntaje;

        fwrite(&auxEMovieEstatico,sizeof(eMovieEstatico),1,f);
    }
    fclose(f);
}
/**
 * \brief lee y carga de un archivo binario el array de eMovies
 * \param cant cantidad de peliculas guardadas en el archivo
 * \param ptrCantGlobal direccion de memoria de la variable cant del main
 * \param nombreArchivo nombre del archivo a leer.
 * \return puntero con el array cargado.
 */
eMovie* leerBinArrayEMovies(int cant, int* ptrCantGlobal, char* nombreArchivo)
{
    eMovie* eMoviePtrArray=NULL;
    eMovie eMovieAux;
    eMovieEstatico auxEMovieEstatico;
    FILE * f;
    f=fopen(nombreArchivo,"rb");
    if(f!=NULL && cant > 0)
    {
        for(int i=0;i<cant;i++)
        {
            fread(&auxEMovieEstatico,sizeof(eMovieEstatico),1,f);
    //titulo
            eMovieAux.titulo=(char*) malloc( sizeof(char) * (strlen(auxEMovieEstatico.titulo) + 1) );
            if(eMovieAux.titulo == NULL)
            {
                printf("\nERROR! Error de memoria.");
                exit(1);
            }
            strcpy(eMovieAux.titulo, auxEMovieEstatico.titulo);
    //genero
            eMovieAux.genero=(char*) malloc( sizeof(char) * (strlen(auxEMovieEstatico.genero) + 1) );
            if(eMovieAux.genero == NULL)
            {
                printf("\nERROR! Error de memoria.");
                exit(1);
            }
            strcpy(eMovieAux.genero, auxEMovieEstatico.genero);
    //descripcion
            eMovieAux.descripcion=(char*) malloc( sizeof(char) * (strlen(auxEMovieEstatico.descripcion) + 1) );
            if(eMovieAux.descripcion == NULL)
            {
                printf("\nERROR! Error de memoria.");
                exit(1);
            }
            strcpy(eMovieAux.descripcion, auxEMovieEstatico.descripcion);
    //linkImagen
            eMovieAux.linkImagen=(char*) malloc( sizeof(char) * (strlen(auxEMovieEstatico.linkImagen) + 1) );
            if(eMovieAux.linkImagen == NULL)
            {
                printf("\nERROR! Error de memoria.");
                exit(1);
            }
            strcpy(eMovieAux.linkImagen, auxEMovieEstatico.linkImagen);
    //duracion
            eMovieAux.duracion=auxEMovieEstatico.duracion;
    //puntaje
            eMovieAux.puntaje=auxEMovieEstatico.puntaje;
    //id
            eMovieAux.id=auxEMovieEstatico.id;
            eMoviePtrArray=cargarEMovie(eMoviePtrArray, eMovieAux, ptrCantGlobal);
        }
    }
    return eMoviePtrArray;
}
/**
 * \brief guarda en un archivo binario la cantidad de peliculas que hay en el array
 * \param cant cantidad de peliculas del array
 * \param nombreArchivo nombre del archivo a crear.
 */
void guardarBinCantArrayEMovies(int cant, char* nombreArchivo)
{
    FILE * f;
    f=fopen(nombreArchivo,"wb");
    fwrite(&cant,sizeof(int),1,f);
    fclose(f);
}
/**
 * \brief lee de un archivo binario la cantidad de eMovies guardadas en otro archivo binario
 * \param nombreArchivo nombre del archivo a leer.
 * \return la cantidad de eMovies guardadas en otro archivo binario
 */
int leerBinCantArrayEMovies(char* nombreArchivo)
{
    int cant=0;
    FILE * f;
    f=fopen(nombreArchivo,"rb");
    if( f!=NULL)
    {
        fread(&cant,sizeof(int),1,f);
    }
    fclose(f);
    return cant;
}
