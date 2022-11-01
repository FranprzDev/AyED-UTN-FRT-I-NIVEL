/*
 
Se tiene un poema con un máximo de 200 caracteres. 
Se solicita un programa que permita el ingreso
del poema para luego contar y mostrar en pantalla: 
cuantas consonantes y vocales tiene el poema. 
Para elingreso del poema se utilizara gets() y para la salida puts().

*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int contarVocales(char poema[200]);

main(){
    int longitudMaxima = 200;
    char poema[longitudMaxima];
    int cantidadVocales = 0;
    int cantidadConsonantes = 0;


    printf("Ingrese el peoma: ");
    gets(poema);
    _flushall();

    printf("\nEl poema es: ");
    puts(poema);
    _flushall();

    cantidadVocales = contarVocales(poema);

    printf("La cantidad vocales es: %d", cantidadVocales);

    cantidadConsonantes = longitudMaxima - cantidadVocales - 1;

    printf("La cantidad de consonantes es: %d", cantidadConsonantes);

}

int contarVocales(char poema[200]){
    int contadorVocales = 0;
    for(int i = 0; i < 200; i++){
        if(poema[i] == 'a' || poema[i] == 'e' || poema[i] == 'i' || poema[i] == 'o' || poema[i] == 'u'){
            contadorVocales++;
        }
    }

    return contadorVocales;
}