/*

Realizar un programa que reciba por teclado diferentes palabras, 
hasta que se ingrese la palabra "final". Entonces se deberá mostrar 
por pantalla cual fue la palabra más larga ingresada y cuantas palabras
se ingresaron sin contar la palabra “final”.

*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>


// gets()
// puts()


// haceme un corte de control con la palabra "final"
// la cantidad de palabras

// strlen()
// strcmp()

typedef char cadena[30];
cadena miVector[30];

main(){
    int contador = 0;
    int bandera = 1;
    int cantidadPalabras = 0, mayor = 0;
    int comparacion = 0;
    char final[7] = {'f', 'i', 'n', 'a', 'l'};

    do{
      //  system("cls");
        printf("Ingrese la cadena: ");
        _flushall();
		gets(miVector[contador]);
        _flushall();
        comparacion = strcmp(miVector[contador], "final");
        if(comparacion == 0){
            bandera = 0;
        }else{

            cantidadPalabras = strlen(miVector[contador]);

            if(cantidadPalabras > mayor){
                mayor = cantidadPalabras;
            }
            printf("%d", contador);

			contador++;
        }
    }while(bandera == 1);

    system("cls");
    printf("\nSe ingresaron un total de: %d", contador);
    printf("\nLa palabra con mas digitos es: %d", mayor);
}