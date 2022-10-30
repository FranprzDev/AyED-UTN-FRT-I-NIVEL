	/*
Se tiene un arreglo de N posiciones de números enteros.
a. En una función sin tipo, Registrar la carga del arreglo.
b. Usando una función con tipo, obtener el menor valor ingresado el cual deberá ser mostrado
en la función main.
c. Usando una función sin tipo, listar los datos del arreglo.
*/

#include<stdio.h>

void cargarArreglo(int arreglo[100], int tope);
int obtainMinValue(int arreglo[100], int tope);
int obtenerMenorValor(int arreglo[100], int tope, int minimoDelArreglo);
void mostrarArreglo(int arreglo[100], int tope);

main(){
	int minimoDelArreglo;
	int n, arreglo[100];
	
	printf("Ingrese n: "); scanf("%d", &n);
	printf("\n");
	
	cargarArreglo(arreglo, n);
	int minimo = obtainMinValue(arreglo, n);
	
	printf("\nEl minimo del arreglo es: %d \n", minimo);
	
	mostrarArreglo(arreglo, n);

}

void cargarArreglo(int arreglo[100], int tope){
	for(int i = 0; i < tope; i++){
		printf("Ingrese el elemento %d: ", i);
		scanf("%d", &arreglo[i]);
	}
}

int obtainMinValue(int arreglo[100], int tope){
	int menorValor = 0;
	
	for(int j = 0; j < tope; j++){
		if(arreglo[j] < arreglo[menorValor]){
					menorValor = arreglo[j];
		}
	}
	
	return menorValor;
}

void mostrarArreglo(int arreglo[100], int tope){
	for(int i = 0; i < tope; i++){
		printf("\n[%d/%d]: es: %d", i, tope, arreglo[i]);
	}
}
