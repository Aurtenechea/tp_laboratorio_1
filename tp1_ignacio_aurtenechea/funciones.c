/** \brief recibe 2 parametros y devuelve la suma de ambos.
 *
 * \param primer valor a sumar.
 * \param segundo valor a sumar.
 * \return suma de los parametros.
 *
 */

float suma(float x,float y)
{
    float resultado;
    resultado=x+y;

    return resultado;
}

/** \brief recibe 2 parametros y devuelve la resta de ambos.
 *
 * \param x, primer valor a restar.
 * \param y, segundo valor a restar.
 * \return diferencia de los parametros.
 *
 */

float resta(float x,float y)
{
    float resultado;
    resultado=x-y;

    return resultado;
}

/** \brief recibe 2 parametros y devuelve el cociente de ambos.
 *
 * \param x dividendo.
 * \param y divisor.
 * \return coeficiente de la division x/y.
 *
 */

float division(float x,float y)
{
    float resultado;
    resultado=x/y;

    return resultado;
}

/** \brief recibe 2 parametros y devuelve el producto de ambos.
 *
 * \param x, primer valor a multiplicar.
 * \param y, segundo valor a multiplicar.
 * \return producto de los parametros.
 *
 */

float multiplicacion(float x,float y)
{
    float resultado;
    resultado=x*y;

    return resultado;
}

/** \brief recibe 1 parametro y devuelve su factorial.
 *
 * \param valor a factorizar.
 * \return el factorial del parametro x.
 *
 */

int factorial (int x)
{
    int rta;


    if (x==0)
    {
        rta=1;

    }
    else
    {
        rta = x * factorial(x-1);
    }

    return rta;
}
