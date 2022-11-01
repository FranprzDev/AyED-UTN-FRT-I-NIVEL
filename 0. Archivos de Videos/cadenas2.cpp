/*

Ingresar una lista con los nombres de personas, separados por una coma. La cadena tiene un tamaño
máximo de 100 caracteres. El ingreso termina cuando se presiona la tecla Enter.
a. Haciendo uso de una Función Sin Tipo, por pantalla Mostrar cada una de las palabras que forman la
 cadena en una fila diferente. Ten en cuenta que el separador de palabras es la coma y no deberá ser mostrado.
b. Haciendo uso de una función Con tipo devolver la longitud total de la cadena ingresada. No utilizar la
función strlen(cadena), incluida en la biblioteca string.h. (Lo que deberá hacer es contar caracter por caracter)

*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void mostrarCadena(char string[100]);
int contarCantidadCadena(char string[100]);

main(){
    char string[100];
    int cantidadCaract = 0;

	printf("Ingrese la cadena: ");
    gets(string);
    _flushall();

    mostrarCadena(string);

    printf("\n");
    system("pause");
    
    cantidadCaract = contarCantidadCadena(string);

	system("cls");
    printf("La cantidad de caracteres es: %d", cantidadCaract);

}

void mostrarCadena(char string[100]){
    int indiceGuardado = 0;
    for(int i = 0; i < 100; i++){
        if(string[i] == ','){
            indiceGuardado = i;
            for(int m = indiceGuardado; m < indiceGuardado; m++){
                printf("%c", string[m]);
            }   
            printf("\n");
        }
    }
}

int contarCantidadCadena(char string[100]){

    /*
    Forma más optima
    int numero = 0;
    numero = strlen(string);
    return numero;
    */

   int cont = 0;

    for(int i = 0;  i < 100; i++){
        if(string[i] != '\0'){
            cont++;
        }else{
            i = 100;
        }
    }  

    return cont;
}