/* Este archivo contiene todo lo referente al tratamiento de los datos, es decir
estructuras para almacenar los numeros, conversiones entre formas, etc */
#include <math.h>

#define BINOMICA 1
#define POLAR 2

typedef struct numComplejo{
        float primerElemento;           //Valor real en binomica o modulo en polar
        float segundoElemento;          //Valor imaginario en binomica o argumento en polar
        short int tipo;                 //Permite identificar con un define el tipo de representacion que es
} numComplejo;

numComplejo binomicaAPolar(numComplejo);
numComplejo polarABinomica(numComplejo);

// La funcion transforma un numComplejo de binomica a polar (debe recibir un numComplejo en binomica)

numComplejo binomicaAPolar(numComplejo numeroBinomica){
            if(numeroBinomica.tipo == BINOMICA){
               numComplejo polar;
               polar.primerElemento = sqrt(pow(numeroBinomica.primerElemento,2)+ pow(numeroBinomica.segundoElemento,2));
               polar.segundoElemento = atan2(numeroBinomica.segundoElemento, numeroBinomica.primerElemento); // TODO CORREGIR EL ARGUMENTO
               polar.tipo = POLAR;
            } else {
                printf("El complejo debe estar en forma binomica");
            }
            return polar;
}

// La funcion transforma un numComplejo de polar a binomica (debe recibir un numComplejo en polar)
numComplejo polarABinomica(numComplejo numeroPolar){
            if(numeroPolar.tipo == POLAR){
                numComplejo polar;
                polar.primerElemento = sqrt(pow(numeroBinomica.primerElemento,2) + pow(numeroBinomica.segundoElemento,2));
                polar.segundoElemento = atan2(numeroBinomica.segundoElemento, numeroBinomica.primerElemento); // TODO CORREGIR EL ARGUMENTO
                polar.tipo = POLAR;
            } else {
                printf("El complejo debe estar en forma binomica");
            }
            return polar;
}
