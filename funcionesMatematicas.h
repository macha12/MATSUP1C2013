/* Este archivo contiene todo lo referente a la funcionalidad matematica necesaria */

#define BINOMICA 1
#define POLAR 2

numComplejo suma(numComplejo, numComplejo);
numComplejo resta(numComplejo, numComplejo);
numComplejo multiplicacion(numComplejo, numComplejo);
numComplejo division(numComplejo, numComplejo);


// La funcion suma dos numComplejos binomicos y devuelve un numComplejo binomico
numComplejo suma(numComplejo primerOperando, numComplejo segundoOperando) {
            if (primerOperando.tipo == BINOMICA && segundoOperando == BINOMICA) {
                //TODO: Si no se cumple la condicion, transformar los operandos a la forma binomica
                //para poder operar con cualquier tipo de complejo
                primerOperando.primerElemento += segundoOperando.primerElemento;
                primerOperando.segundoElemento += segundoOperando.segundoElemento;
                return primerOperando;
            } else {
                printf("Ambos operandos deben estar en forma binomica");
            }
}

// La funcion resta dos numComplejos binomicos
numComplejo resta(numComplejo primerOperando, numComplejo segundoOperando) {
            if (primerOperando.tipo == BINOMICA && segundoOperando == BINOMICA) {
                //TODO: Si no se cumple la condicion, transformar los operandos a la forma binomica
                //para poder operar con cualquier tipo de complejo
                primerOperando.primerElemento -= segundoOperando.primerElemento;
                primerOperando.segundoElemento -= segundoOperando.segundoElemento;
                return primerOperando;
            } else {
                printf("Ambos operandos deben estar en forma binomica");
            }
}

// La funcion multiplica dos numCOmplejos polares
numComplejo multiplicacion(numComplejo primerOperando, numComplejo segundoOperando) {
            if (primerOperando.tipo == POLAR && segundoOperando == POLAR) {  
                //TODO: Si no se cumple la condicion, transformar los operandos a la forma polar
                //para poder operar con cualquier tipo de complejo
                primerOperando.primerElemento *= segundoOperando.primerElemento;
                primerOperando.segundoElemento += segundoOperando.segundoElemento;
                return primerOperando;
            } else {
                printf("Ambos operandos deben estar en forma polar");
            }
}

// La funcion divide dos numComplejos polares
numComplejo division(numComplejo primerOperando, numComplejo segundoOperando) {
            if (primerOperando.tipo == POLAR && segundoOperando == POLAR) {
                //TODO: Si no se cumple la condicion, transformar los operandos a la forma polar
                //para poder operar con cualquier tipo de complejo
                if (segundoOperando.primerElemento != 0) { 
                    primerOperando.primerElemento /= segundoOperando.primerElemento;
                    primerOperando.segundoElemento -= segundoOperando.segundoElemento;
                } else {
                    printf("No se puede dividir por 0, se devuelve el primer operando.\n");   //TODO ALGO MEJOR
                    return primerOperando;
                }
            } else {
                printf("Ambos operandos deben estar en forma polar");
            }
}
