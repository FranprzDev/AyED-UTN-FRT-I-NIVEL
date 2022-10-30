/* 

	Francisco Miguel Perez - 44190234 
	Legajo nº: 56355
	Universidad Tecnológica Nacional 


? Se tiene una matriz A de orden M*N de números enteros, donde M y N son distintos.
Codificación
a. Realizar la carga de la matriz A, puede hacerse de manera aleatoria. Ver ejemplo al final del TP
b. Obtener la Matriz B que es la matriz traspuesta o transpuesta de At
.
c. Mostrar la matriz A y su transpuesta.
d. Usando una función Sin Tipo Incrementar todos los valores que tiene la matriz A por un valor entero
X que se deberá ingresar por teclado en la función main.


// Primer ejercicio divertido en 6 meses XD

*/


#include<stdio.h>
#include<stdlib.h>

void cargarAleatorio(int matriz[10][10], int m, int n);
void mostrarMatriz(int matriz[10][10], int m, int n);
void transponerMatriz(int matriz[10][10], int m, int n);

main(){
	int m,n, matriz[10][10];
	printf("Ingrese el valor de filas: ");
	scanf("%d", &m);
	printf("Ingrese el valor de columnas: ");
	scanf("%d", &n);

	cargarAleatorio(matriz, m,n);
	
	printf("\n\nMatriz normal: ");
	mostrarMatriz(matriz,m,n);
	
	// transponer...
	
	printf("\n\nMatriz transpuesta: ");
	transponerMatriz(matriz, m, n);
	mostrarMatriz(matriz,m,n);
	
}

void transponerMatriz(int matriz[10][10], int m, int n){
	int aux;
	
	for(int i = 0; i < m; i++){
		for(int j = 0; j < n; j++){
			if(i != j){
				aux = matriz[i][j];
				matriz[i][j] = matriz[j][i];
				matriz[j][i] = aux;
			}
		}
	}
}

void cargarAleatorio(int matriz[10][10], int m, int n){
	for(int i = 0; i < m; i++){
		for(int j = 0; j < n; j++){
			matriz[i][j] = rand();
		}
	}
}

void mostrarMatriz(int matriz[10][10], int m, int n){
	for(int i = 0; i < m; i++){
		printf("\n\n");
		for(int j = 0; j < n; j++){
			printf("%d ", matriz[i][j]);
		}
	}
}
