/*
Francisco Miguel Perez - 44190234
	Cargar un arreglo de 100 números enteros de manera aleatoria.
	a. Promedio de números Pares.
	b. Promedio de números Impares.
	c. La suma de los elementos que ocupen las posiciones pares del arreglo.
	d. La suma de los elementos que ocupen las posiciones impares del arreglo
*/

#include<stdio.h>
#include<stdlib.h>

void cargarArregloConRandom(int arreglo[100]);
float promImpar(int arreglo[100]);
float promPar(int arreglo[100]);
int sumaElemenetosPar(int arreglo[100]);
int sumaElemenetosImpar(int arreglo[100]);

main(){
	int array[100];
	cargarArregloConRandom(array);
	
	float promedioPar = promPar(array);
	float promedioImpar = promImpar(array);
	
	printf("El promedio par es: %.2f", promedioPar);
	printf("\nEl promedio impar es: %.2f", promedioImpar);
	
	int sumaPar = sumaElemenetosPar(array);
	int sumaImpar = sumaElemenetosImpar(array);
	
	printf("\n\n");
	printf("La suma de las posiciones PARES es de: %d \n", sumaPar);
	printf("La suma de las posiciones IMPARES es de: %d", sumaImpar);
	
}

void cargarArregloConRandom(int arreglo[100]){
	int num = 0;
	for(int i = 0; i < 100; i++){
		num = rand()%432;
		arreglo[i] = num;
	}
}

float promPar(int arreglo[100]){
	int acumuladorPar = 0, contadorPar = 0;
	int numero = 0;
	
	for(int i = 0; i < 100; i++){
		numero = arreglo[i];
		if(numero % 2 == 0){
			acumuladorPar += numero;
			contadorPar++;
		}
	}
	
	float promedioPar = (float) acumuladorPar/contadorPar;
	return promedioPar;
	
}

float promImpar(int arreglo[100]){
	float acumuladorImpar = 0, contadorImpar = 0;
	int numero = 0;
	
	for(int i = 0; i < 100; i++){
		numero = arreglo[i];
		if(numero % 2 == 1){
			acumuladorImpar += numero;
			contadorImpar++;
		}
	}

	float promedioImpar = (float) acumuladorImpar/contadorImpar;
	return promedioImpar;
	
}

int sumaElemenetosPar(int arreglo[100]){
	int acumuladorPar = 0;
	int numero = 0;
	
	for(int i = 0; i < 100; i += 2){
		numero = arreglo[i];
		acumuladorPar += numero;
	}
	
	return acumuladorPar;
}

int sumaElemenetosImpar(int arreglo[100]){
	int acumuladorImpar = 0;
	int numero = 0;
	
	for(int i = 1; i < 100; i += 2){
		numero = arreglo[i];
		acumuladorImpar += numero;
	}
	
	return acumuladorImpar;
}




