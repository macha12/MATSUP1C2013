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
