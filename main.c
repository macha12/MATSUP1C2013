#include <stdio.h>
#include <stdlib.h>


void imprimirMenu(void);


int main(){
       int menu;
       
       printf("<TEXTO BIENVENIDA>");
       
       while(1){
       imprimirMenu();
       system("pause");
       /*
       switch(menu){
       
       case 1:
            
            break;
       
       case 2:
            
            break; 
            
       case 3:
            
            break; 

       case 4:
            
            break;
       
       case 5:
            
            break; 
            
       case 6:
            
            break;
       
       default:
               
               break;*/
               
       return 0;
       }       
}

void imprimirMenu(void){
     
     printf("Seleccione alguna de las siguientes opciones:\n");
     printf("1 - Suma de dos numeros imaginarios\n");
     printf("2 - Resta de dos numeros imaginarios\n");
     printf("3 - Multiplicacion de dos numeros imaginarios\n");
     printf("4 - Division de dos numeros imaginarios\n");
     printf("5 - Potencia de un numero imaginario\n");
     printf("6 - Radicacion de un numero imaginario\n");
     printf("7 - Radicacion de un numero imaginario (solo las primitivas)\n");
}
