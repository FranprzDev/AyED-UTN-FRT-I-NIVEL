/*

	Francisco Miguel Perez - 44190234 
	Legajo nº: 56355
	Universidad Tecnológica Nacional 



Se tiene una Arreglo Tridimensional de orden MxNxP con valores reales.

a. Realizar la carga del Arreglo Tridimensional, por medio de una función SIN TIPO.
b. Por medio de una función CON TIPO, encontrar el menor valor dentro del Arreglo Tridimensional.
c. Por medio de una función CON TIPO, determinar si el menor valor encontrado es o no par.

*/

#include<stdio.h>
#include<stdlib.h>

void cargarArreglo(int arreglo[10][10][10], int k, int m, int n); 
float encontrarMenorValor(int arreglo[10][10][10], int &k, int &m, int &n);
float determinarParOImpar(int arreglo[10][10][10], int &k, int &m, int &n);
void mostrarArreglo(int array[10][10][10], int k, int m, int n);

main(){
	int arreglo[10][10][10];
	int k,m,n;
	printf("Ingrese la cantidad de planos: "); scanf("%d", &k);
	printf("Ingrese la cantidad de filas: "); scanf("%d", &m);
	printf("Ingrese la cantidad de columnas: "); scanf("%d", &n);
	
	cargarArreglo(arreglo,k,m,n);
	mostrarArreglo(arreglo, k, m, n);
	
	printf("\n\n");
	
	determinarParOImpar(arreglo, k, m, n);
}

void cargarArreglo(int arreglo[10][10][10], int k, int m, int n){
	for(int p = 0; p < k; p++){
		printf("\nPlano %d: \n", p);
		for(int f = 0; f < m; f++){
			printf("\n");
			for(int c = 0; c < n ; c++){
				printf("Ingrese [%d][%d][%d]: ", p,f,c);
				scanf("%d", &arreglo[p][f][c]);
			}
		}
	}
} 

float encontrarMenorValor(int arreglo[10][10][10], int &k, int &m, int &n){
	int menorValor = 0, numero = 0;
	for(int p = 0; p < k; p++){
		for(int f = 0; f < m; f++){
			for(int c = 0; c < n ; c++){
				numero = arreglo[p][f][c];
				if(menorValor > numero){
					menorValor = numero;
				}
			}
		}
	}
	return menorValor;
}

float determinarParOImpar(int arreglo[10][10][10], int &k, int &m, int &n){
	
	int minValue = encontrarMenorValor(arreglo, k, m, n);
	printf("\n");
	printf("El menor valor es: %d", minValue);
	if(minValue % 2 == 0){
		printf("\nEl menor valor es par.");
	}else{
		printf("\nEl menor valor es impar.");
	}
}

void mostrarArreglo(int array[10][10][10], int k, int m, int n){
	for(int planos = 0; planos < k; planos++){
		printf("\n\nPlano %d: \n", planos);
		for(int filas = 0; filas < m; filas++){
			printf("\n\n");
			for(int columnas = 0; columnas < n; columnas++){
				printf("[%d] ", array[planos][filas][columnas]);
			}
		}
	}
}
