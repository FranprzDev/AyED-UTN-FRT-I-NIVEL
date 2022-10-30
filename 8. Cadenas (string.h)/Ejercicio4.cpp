/*

Se tiene un poema con un máximo de 200 caracteres. Se solicita un programa que permita el ingreso
del poema para luego contar y mostrar en pantalla: cuantas consonantes y vocales tiene el poema. Para el
ingreso del poema se utilizara gets() y para la salida puts().

	Francisco Miguel Perez - 44190234
		Legajo Nº 56355
		DNI: 44190234
		UTN - FRT

*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int contarVocalesYEspacios(char poema[200], int &cantidadEspacios, int cantidadDigitos);
int contarDigitos(char poema[200]);

main(){

    char poema[200];
    int cantidadDigit = 0;
    int cantidadEspacios = 0;
    int cantidadVocales = 0;

    printf("Ingrese el peoma: ");
    gets(poema);

    cantidadDigit = contarDigitos(poema);

    cantidadVocales = contarVocalesYEspacios(poema, cantidadEspacios, cantidadDigit);

    int cantidadConsonantes = cantidadDigit - cantidadVocales - cantidadEspacios;

    printf("\nHay un total de %d digitos de los cuales: ", cantidadDigit, cantidadConsonantes);

    printf("\n- Hay un total de %d consonantes: ", cantidadConsonantes);
    printf("\n- Hay un total de %d vocales: ", cantidadVocales);
    printf("\n- Hay un total de %d espacios \n", cantidadEspacios);

    puts(poema);
    
}

int contarDigitos(char poema[200]){
    int cantidadDigitos = 0;

    for(int i=0; i<200; i++){
        cantidadDigitos++;
        if(poema[i] == '\0'){
            cantidadDigitos--;
            break;
        }
    }
    return cantidadDigitos;
}


int contarVocalesYEspacios(char poema[200], int &cantidadEspacios, int cantidadDigitos){
    int cantidadVocales = 0;
    cantidadEspacios = 0;

    for(int i = 0; i < cantidadDigitos; i++){
        if(poema[i] == 'a' || poema[i] == 'e' || poema[i] == 'i' || poema[i] == 'o' || poema[i] == 'u'){
            cantidadVocales++;
        }
        if(poema[i] == ' '){
            cantidadEspacios++;
        }
    }

    return cantidadVocales;
}
