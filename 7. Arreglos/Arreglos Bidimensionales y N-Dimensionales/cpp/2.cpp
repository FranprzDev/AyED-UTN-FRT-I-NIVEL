/*

	Francisco Miguel Perez - 44190234 
	Legajo nº: 56355
	Universidad Tecnológica Nacional 

Ingresar los elementos de una matriz donde sus elementos son números enteros. El orden de la
matriz es MxN.
Diagrama de flujo y Codificación en C
a. Realizar la carga de la matriz por medio de una función sin tipo. Al ingresar un valor negativo o
cero mostrar mensaje de error y volver a ingresar el valor para dicha celda.
b. Mostrar la matriz por medio de una función.
c. Cambiar un elemento de la matriz, de una posición ingresada por teclado, por el valor cero. Utilizar
la función realizada en el punto b para mostrar como quedo.
d. Mostrar los elementos de una fila “X”, ingresando el número de fila, por teclado.
e. Mostrar los elementos de una Columna “Y”, ingresando el número de columna por teclado.

*/

#include<stdio.h>

void cargarMatriz(int matriz[10][10], int m, int n);
void mostrarMatriz(int matriz[10][10], int m, int n);
void cambiarPorCero(int matriz[10][10], int m, int n);
void mostrarPorFila(int matriz[10][10], int fila, int n);
void mostrarPorColumna(int matriz[10][10], int columna, int m);

main(){
	int m = 0, n = 0;
	int matriz[10][10];
	int numFila, numColumna;
		
	printf("Ingrese m: "); scanf("%d", &m);
	printf("Ingrese n: "); scanf("%d", &n);
	
	cargarMatriz(matriz, m, n);
	mostrarMatriz(matriz, m, n);

	cambiarPorCero(matriz, m, n);
	mostrarMatriz(matriz, m, n);
	
	printf("\n\nIngrese el numero de fila que desea mostrar: ");
	scanf("%d", &numFila);
	

	printf("\n");
	mostrarPorFila(matriz, numFila, n);
	
	
	printf("\n\nIngrese el numero de columna que desea mostrar: ");
	scanf("%d", &numColumna);
	
	printf("\n");
	mostrarPorColumna(matriz, numColumna, m);
	
	
}

void cargarMatriz(int matriz[10][10], int m, int n){
	int numero = 0;
	for(int i = 0; i < m; i++){
		for(int j = 0; j < n; j++){
				printf("Ingrese [%d][%d]: ", i,j);
				scanf("%d", &numero);
			if(numero > 0){
				matriz[i][j] = numero;
			}else{
				do{
					printf("\n¡Error! Está ingresnado un número negativo o cero. \n");
					printf("Ingrese [%d][%d]: ", i,j);
					scanf("%d", &numero);
				}while(numero < 0);
			}
		}
	}
}

void mostrarMatriz(int matriz[10][10], int m, int n){
	for(int i = 0; i < m; i++){
		printf("\n");
		for(int j = 0; j < n; j++){
			printf("%d ", matriz[i][j]);
		}
	}
}

void cambiarPorCero(int matriz[10][10], int m, int n){
	int posfilas, poscolum;
	printf("\nRecordar que la matriz es de %d*%d", m-1, n-1);
	printf("\nIngrese las posiciones de filas y columnas: ");
	// m = filas & n = columnas.
	
	printf("\nIngrese la posición en filas (0 - %d): ", m-1);
	scanf("%d", &posfilas);
	printf("\nIngrese la posición en columnas (0 - %d): ", n-1);
	scanf("%d", &poscolum);
	
	matriz[posfilas][poscolum] = 0;

}

void mostrarPorFila(int matriz[10][10], int fila, int n){
	for(int i = 0; i < n; i++){
		printf("%d ", matriz[fila][i]);
	}
}


void mostrarPorColumna(int matriz[10][10], int columna, int m){
	for(int i = 0; i < m; i++){
		printf("%d ", matriz[i][columna]);
	}
}

