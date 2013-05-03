/* Este archivo contiene todo lo referente al tratamiento de los datos, es decir
estructuras para almacenar los numeros, conversiones entre formas, etc */
#include <math.h>

#define BINOMICA 1
#define POLAR 2
#define FASOR 3

#define SENO 1
#define COSENO 2

typedef struct numComplejo{
        float primerElemento;           //Valor real en binomica o modulo en polar
        float segundoElemento;          //Valor imaginario en binomica o argumento en polar
        short int tipo;                 //Permite identificar con un define el tipo de representacion que es
} numComplejo;

typedef struct funcionTrigonometrica{
        float amplitud;
        float frecuencia;
        float anguloFase;
        int tipo;
} funcionTrigonometrica;

numComplejo APolar(numComplejo);
numComplejo ABinomica(numComplejo);
float modulo(float, float);
float angulo(float, float);
numComplejo trigonometricaAFasor(funcionTrigonometrica);
funcionTrigonometrica fasorATrigonometrica(numComplejo, float);

// La funcion transforma un numComplejo de binomica a polar
// si el numComplejo ya esta en forma polar lo deja en forma polar, por lo tanto no hace falta validacion.

numComplejo APolar(numComplejo numeroBinomica){
            if(numeroBinomica.tipo == BINOMICA){
               numComplejo polar;
               polar.primerElemento = modulo(numeroBinomica.primerElemento, numeroBinomica.segundoElemento);
               polar.segundoElemento = angulo(numeroBinomica.primerElemento, numeroBinomica.segundoElemento); // TODO CORREGIR EL ARGUMENTO
               polar.tipo = POLAR;
               return polar;
            }
            else {
                return numeroBinomica;
            }
}

// La funcion transforma un numComplejo de polar a binomica (debe recibir un numComplejo en polar)
// si el numComplejo ya esta en forma binomica lo deja en forma binomica, por lo tanto no hace falta validacion.
numComplejo ABinomica(numComplejo numeroPolar){
			if(numeroPolar.tipo != BINOMICA){
                numComplejo binomico;
                binomico.primerElemento = numeroPolar.primerElemento * cos(numeroPolar.segundoElemento);
                binomico.segundoElemento = numeroPolar.primerElemento * sin(numeroPolar.segundoElemento);
                binomico.tipo = BINOMICA;
                return binomico;
			}
			else {
			    return numeroPolar;
			}
}



//Calcula el modulo de un vector
float modulo(float abscisa, float ordenada){
    return sqrt(pow(abscisa,2)+ pow(ordenada,2));
}


//calcula el angulo de un vector
float angulo(float abscisa, float ordenada){
    return atan2(ordenada, abscisa); // TODO CORREGIR EL ARGUMENTO
}


// Se asume que llega un coseno
numComplejo trigonometricaAFasor(funcionTrigonometrica trigonometrica){

            numComplejo resultado;
            resultado.tipo = FASOR;
            resultado.primerElemento = trigonometrica.amplitud;
            resultado.segundoElemento = trigonometrica.anguloFase;
            return resultado;            
}

funcionTrigonometrica fasorATrigonometrica(numComplejo fasor, float frecuencia){
                      funcionTrigonometrica trigonometrica;
                      
                      trigonometrica.tipo = COSENO;
                      trigonometrica.amplitud = fasor.primerElemento;
                      trigonometrica.frecuencia = frecuencia;
                      trigonometrica.anguloFase = fasor.segundoElemento;
                      
                      return trigonometrica;

}
                      
