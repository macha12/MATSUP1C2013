/* Este archivo contiene todo lo referente a la funcionalidad matematica necesaria */

numComplejo suma(numComplejo, numComplejo);

numComplejo suma(numComplejo primerOperando, numComplejo segundoOperando){

            primerOperando.primerElemento += segundoOperando.primerElemento;
            primerOperando.segundoElemento += segundoOperando.segundoElemento;
            return primerOperando;
}
