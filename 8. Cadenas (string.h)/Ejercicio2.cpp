/*

 Ingresar una lista con los nombres de personas, separados por una coma. La cadena tiene un tamaño
máximo de 100 caracteres. El ingreso termina cuando se presiona la tecla Enter.
a. Haciendo uso de una Función Sin Tipo, por pantalla Mostrar cada una de las palabras que forman la cadena en una fila diferente. 
Ten en cuenta que el separador de palabras es la coma y no deberá ser mostrado.
b. Haciendo uso de una función Con tipo devolver la longitud total de la cadena ingresada. No utilizar la
función strlen(cadena), incluida en la biblioteca string.h. (Lo que deberá hacer es contar caracter por caracter)

	Francisco Miguel Perez - 44190234
		Legajo Nº 56355
		DNI: 44190234
		UTN - FRT

*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void mostrarPalabras(char cadena[100], int &guardador);
int longitudCadena(char cadena[100]);
void imprimirPorFila(char cadena[100], int indice, int indiceAnt, int &guardador);

main(){
	int lenghtword = 0;
    char cadena[100];
    int guardador = 0;
    printf("Ingrese nombres separados por una coma. \n");
    gets(cadena);
    printf("\n");

    mostrarPalabras(cadena, guardador);

    lenghtword = longitudCadena(cadena);

    printf("\n\nLa longitud de la cadena es: %d", lenghtword);

}

void imprimirPorFila(char cadena[100], int indice, int indiceAnt, int &guardador){
	for(int i = indiceAnt; i < indice; i++){
			if(cadena[i] == ',' || cadena[i] == ' ,' || cadena[i] == ', ' || cadena[i] == ' ')
			{ printf(""); }
			else { printf("%c", cadena[i]); }		
		}
		printf("\n");	
	}

void mostrarPalabras(char cadena[100], int &guardador){
    int indiceAct = -1;
    int indiceAnt = 0;
    for(int i = 0; i < 100; i++){
    	if(cadena[i] == ','){
			indiceAct = i;
			// la coma me la saco en la otra función
    		imprimirPorFila(cadena, indiceAct, indiceAnt, guardador);
    		indiceAnt = indiceAct;
		}		
		if(cadena[i] == '\0') i = 100;
	}
}

int longitudCadena(char cadena[100]){
    int contador = 0;
    for(int i=0; i < 100; i++){
        if(cadena[i] == '\0'){
            i = 100;
            contador--;
        }
        contador++;
    }
    return contador;
}
