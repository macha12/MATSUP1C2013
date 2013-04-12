/* Este archivo contiene todo lo referente a la funcionalidad matematica necesaria */

numComplejo suma(numComplejo, numComplejo);
numComplejo resta(numComplejo, numComplejo);


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

