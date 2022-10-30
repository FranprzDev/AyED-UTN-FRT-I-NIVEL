/*
Francisco Miguel Perez - 44190234 UTN

Dado un arreglo “A” de 10 elementos de valores enteros.
	a. Cargar el arreglo y mostrar el arreglo A. Usando la función obtenida en el punto
	06 de este práctico.
	b. En otro arreglo B guardar la potencia de cada elemento del arreglo A elevado a su
	índice. Mostrar en pantalla el arreglo B
	c. En otro arreglo C guardar la suma de los arreglos A y B. Mostrar en pantalla el
	arreglo C

*/

#include<stdio.h>
#include<math.h>
#include<stdlib.h>

void cargarArray(int arreglo[10], int n);
void mostrarArray(int array[10], int n);
void puntoB(int arrayA[10], int arrayB[10], int n);
void puntoC(int arrayA[10], int arrayB[10], int arrayC[10], int n);

main(){

	int n, arrayA[10], arrayB[10], arrayC[10];
	printf("Ingrese n: "); scanf("%d", &n);
	
	cargarArray(arrayA, n);
	
	printf("\nArray A: ");
	mostrarArray(arrayA, n);
	
	puntoB(arrayA, arrayB, n);
	printf("\nArray B: ");
	mostrarArray(arrayB, n);
	
	puntoC(arrayA, arrayB, arrayC, n);
	printf("\nArray C: ");
	mostrarArray(arrayC, n);

}

void cargarArray(int arreglo[100], int n){
	printf("\n");
	for(int i = 0; i < n; i++){
		printf("Ingrese [ %d | %d ]: ", i, n);
		scanf("%d", &arreglo[i]);
	}
}

void mostrarArray(int array[100], int n){
	printf("\n");
	for(int i = 0; i < n; i++){
		printf("| %d | ", array[i]);
	}
	printf("\n");
}

void puntoB(int arrayA[10], int arrayB[10], int n){
	int numero = 0;
	int resultadoPot = 0;
	for(int i = 0; i < n; i++){
		numero = arrayA[i];
		if(i == 0){ 
			arrayB[i] = 1;
		}else if(i == 1){
			arrayB[i] = numero;
		}else{
			resultadoPot = pow(numero, i);	
			arrayB[i] = resultadoPot;
		}

	}
}

void puntoC(int arrayA[10], int arrayB[10], int arrayC[10], int n){
	for(int i = 0; i < n; i++)
	{ arrayC[i] = arrayA[i] + arrayB[i]; }
}
