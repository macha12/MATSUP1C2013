/* Este archivo contiene todo lo referente a la funcionalidad matematica necesaria */

numComplejo suma(numComplejo, numComplejo);
numComplejo resta(numComplejo, numComplejo);
numComplejo multiplicacion(numComplejo, numComplejo);
numComplejo divicion(numComplejo, numComplejo);


// La funcion suma dos numComplejos binomicos y devuelve un numComplejo binomico
numComplejo suma(numComplejo primerOperando, numComplejo segundoOperando){

            primerOperando.primerElemento += segundoOperando.primerElemento;
            primerOperando.segundoElemento += segundoOperando.segundoElemento;
            return primerOperando;
}

// La funcion resta dos numComplejos binomicos
numComplejo resta(numComplejo primerOperando, numComplejo segundoOperando){

            primerOperando.primerElemento -= segundoOperando.primerElemento;
            primerOperando.segundoElemento -= segundoOperando.segundoElemento;
            return primerOperando;
}

// La funcion multiplica dos numCOmplejos polares
numComplejo multiplicacion(numComplejo primerOperando, numComplejo segundoOperando){
            
            primerOperando.primerElemento *= segundoOperando.primerElemento;
            primerOperando.segundoElemento += segundoOperando.segundoElemento;
            return primerOperando;
}

// La funcion divide dos numComplejos polares
numComplejo divicion(numComplejo primerOperando, numComplejo segundoOperando){
            
            if( segundoOperando.segundoElemento != 0){ 
                primerOperando.primerElemento /= segundoOperando.primerElemento;
                primerOperando.segundoElemento -= segundoOperando.segundoElemento;
            } else
              printf("No se puede dividir por 0, se devuelve el primer operando.\n");   //TODO ALGO MEJOR
            
            return primerOperando;           
}


