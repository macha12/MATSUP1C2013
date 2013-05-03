/* Este archivo contiene todo lo referente a la funcionalidad matematica necesaria */

#include "nahuel-datos.h"

numComplejo suma(numComplejo, numComplejo);
numComplejo resta(numComplejo, numComplejo);
numComplejo multiplicacion(numComplejo, numComplejo);
numComplejo division(numComplejo, numComplejo);
numComplejo potencia(numComplejo, int);
numComplejo *raices(numComplejo, int);
numComplejo *raicesPrimitivas(numComplejo, int);
int sonCoprimos(int, int);
float corregirArgumento(float);
numComplejo sumaFasores(numComplejo, numComplejo);
funcionTrigonometrica sumaSenoidal(funcionTrigonometrica , funcionTrigonometrica);
funcionTrigonometrica convertirACoseno(funcionTrigonometrica);



// La funcion suma dos numComplejos binomicos y devuelve un numComplejo binomico
// no hace falta validar la forma de los operandos (ver como estan definidas las funciones de pasaje de forma)


numComplejo suma(numComplejo primerOperando, numComplejo segundoOperando) {
            numComplejo resultado;
            
            primerOperando = ABinomica(primerOperando);
            segundoOperando = ABinomica(segundoOperando);
            resultado.primerElemento = primerOperando.primerElemento + segundoOperando.primerElemento;
            resultado.segundoElemento = primerOperando.segundoElemento + segundoOperando.segundoElemento;
            resultado.tipo = BINOMICA;
            return resultado;
}





// La funcion resta dos numComplejos binomicos


numComplejo resta(numComplejo primerOperando, numComplejo segundoOperando) {
	 	 	 	numComplejo unOperando = ABinomica(primerOperando); //si el operando ya esta en binomica devuelve el mismo operando,sino lo pasa a polar
	            numComplejo otroOperando = ABinomica(segundoOperando);
	            numComplejo resultado;
	            resultado.primerElemento = unOperando.primerElemento - otroOperando.primerElemento;
	            resultado.segundoElemento = unOperando.segundoElemento - otroOperando.segundoElemento;
	            return resultado;
}





// La funcion multiplica dos numCOmplejos polares


numComplejo multiplicacion(numComplejo primerOperando, numComplejo segundoOperando) {
            	numComplejo primerPolar = APolar(primerOperando);
            	numComplejo segundoPolar = APolar(segundoOperando);
            	numComplejo resultado;
                resultado.primerElemento = primerPolar.primerElemento * segundoPolar.primerElemento;
                resultado.segundoElemento = primerPolar.segundoElemento + segundoPolar.segundoElemento;
                return resultado;
}






// La funcion divide dos numComplejos polares
// el error de division por cero se podria realizar mediante una exception, usan try .... cuando hagamos el main() vemos si hace falta.



numComplejo division(numComplejo primerOperando, numComplejo segundoOperando) {

					numComplejo primerPolar = APolar(primerOperando);
	            	numComplejo segundoPolar = APolar(segundoOperando);
	            	numComplejo resultado;
	                resultado.primerElemento = primerPolar.primerElemento / segundoPolar.primerElemento;
	                resultado.segundoElemento = primerPolar.segundoElemento + segundoPolar.segundoElemento;
	                return resultado;

}





// La funcion devuelve 1 si los numeros son coprimos, y 0 si no son coprimos (Utilizando el algoritmo de euclides),
// la funcion solo funciona si se le pasa el primerOperador mayor al segundoOperador (ya que trabaja con el resto).


int sonCoprimos(int primerOperando, int segundoOperando){
    if( segundoOperando == 0)
        return primerOperando == 1;
    else
        return sonCoprimos(segundoOperando, primerOperando % segundoOperando);
}


numComplejo potencia(numComplejo unComplejo, int exponente){
	numComplejo numero = APolar(unComplejo);
	numComplejo resultado;
	resultado.primerElemento = pow(numero.primerElemento,exponente);
	resultado.segundoElemento = numero.segundoElemento*exponente;
	return resultado;
}


// Devuele un puntero al vector donde estan las raices sucesivas de un complejo
numComplejo *raices(numComplejo unComplejo, int radical){
	numComplejo numero = APolar(unComplejo);
	numComplejo unaRaiz;

	// crear vector y puntero
	numComplejo *complejos; //se declara un puntero
	complejos = malloc(sizeof(numComplejo)*radical); //se crea el vector

	// variables utilizadas
	float anguloDeSuma = 2* M_PI /radical;
	float anguloComplejo = numero.segundoElemento / radical;

	// completo vector
	unaRaiz.primerElemento = pow(numero.primerElemento, 1.0 / radical );
	int i;
		for(i=0;i < radical;i++){
			unaRaiz.segundoElemento = anguloComplejo + (anguloDeSuma * i);
			complejos[i] = unaRaiz;
		}
		
	return complejos;
}


float corregirArgumento(float argumentoViejo){
      if(argumentoViejo > (2 * M_PI)){
         return corregirArgumento(argumentoViejo - (2* M_PI));
      }else if(argumentoViejo < 0){
         return corregirArgumento(argumentoViejo + (2 * M_PI));
      } else {
          return argumentoViejo;
      }
      
}

numComplejo *raicesPrimitivas(numComplejo unComplejo, int radical){
            numComplejo *complejos, *lasRaices;
            int cont, aux;
            
            lasRaices = raices(unComplejo , radical);
            cont = aux = 0;
            
            for(;aux < radical; aux++){
                     if(sonCoprimos(radical, aux))
                        cont++;
            }
            
            complejos = malloc(sizeof(numComplejo) * cont);
            
            for(aux=0, cont = 0; aux < radical; aux++){
                   if(sonCoprimos(radical, aux)){
                       complejos[cont].primerElemento = lasRaices[aux].primerElemento;
                       complejos[cont].segundoElemento = lasRaices[aux].segundoElemento;
                       complejos[cont].tipo = POLAR;
                       cont++;
                       }
                          
                   }
            free(raices);
            return complejos;
}
/*para manipular el vector:
numComplejo *complejos; (declaramos el vector)
complejos=raices() (llamamos a la funcion)*/

numComplejo sumaFasores(numComplejo fasor1, numComplejo fasor2){
            numComplejo fasor3 = suma(fasor1, fasor2);

            return APolar(fasor3);
}


funcionTrigonometrica sumaSenoidal(funcionTrigonometrica trigonometrica1, funcionTrigonometrica trigonometrica2){
                      numComplejo fasor1, fasor2, fasor3;
                      
                      fasor1 = trigonometricaAFasor(convertirACoseno(trigonometrica1));
                      fasor2 = trigonometricaAFasor(convertirACoseno(trigonometrica2));
                      fasor3 = sumaFasores(fasor1, fasor2);
                      fasor3.segundoElemento = corregirArgumento(fasor3.segundoElemento);
                      
                      return fasorATrigonometrica(fasor3, trigonometrica1.frecuencia);

}

funcionTrigonometrica convertirACoseno(funcionTrigonometrica trigonometrica){
      
      if( trigonometrica.tipo == SENO){
          trigonometrica.anguloFase -= M_PI / 2;
          trigonometrica.tipo = COSENO;     
      }
      return  trigonometrica;
}
