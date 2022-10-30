/*

	Francisco Miguel Perez - 44190234 
	Legajo n�: 56355
	Universidad Tecnol�gica Nacional 


Una empresa que se dedica a la producci�n de ropa masculina, posee N taller para la confecci�n
de las prendas que comercializa, que son pantalones, camisas y remeras. La cantidad mensual
producida de pantalones, camisas y remeras por cada una de sus f�bricas son registradas en una
matriz. �Determinar el orden de la matriz M x N?
Codificaci�n
a. Realizar la carga de la matriz, de manera aleatoria.
b. Mostrar la cantidad producida de cada una de sus prendas en los N talleres.
c. Usando una funci�n calcular y mostrar en la funci�n main() cual fue el taller que tuvo mayor
producci�n


*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void cargaAleatoria(int matriz[10][10], int m, int n);
int aleatorio(int valor_Inicial, int valor_Final);
void mostrarMatriz(int matriz[10][10], int m, int n);
int sumaDePrendas(int matriz[10][10], int m, int n);
int calcular(int matriz[10][10], int m, int n);


main ()
{
	int m, n, matriz[10][10];  	

	printf("Ingrese la cantidad de talleres: "); 	
	scanf("%d", &m);
	
	n = 3;
	
	cargaAleatoria(matriz, m, n);
	
	mostrarMatriz(matriz, m, n);
	
	int sumPrendas = sumaDePrendas(matriz, m,n);
	
	printf("\n\nEl total de prendas es de: %d", sumaDePrendas);
	
// Las filas son los talleres y las columnas ser�n la cantidad total de prendas...
// Se tomar�n todas las prendas como una sumatoria total.

	int indice = calcular(matriz, m, n);
	
	printf("\n\nLa sucursal con mayor cantidad de producci�n fue el %d", indice);
	
}

void cargaAleatoria(int matriz[10][10], int m, int n){
	for(int i = 0; i < m; i++){
		for(int j = 0; j < n; j++){
			matriz[i][j] = rand();
		}
	}
}

void mostrarMatriz(int matriz[10][10], int m, int n){
	for(int i = 0; i < m; i++){
		printf("\n");
		for(int j = 0; j < n ; j++){
			printf("%d ", matriz[i][j]);
		}
	}
}

int sumaDePrendas(int matriz[10][10], int m, int n){
	int sumador = 0;
	for(int i = 0; i < m; i++){
		for(int j = 0; j < n; j++){
			sumador += matriz[i][j];
		}
	}
	
	return sumador;
}


int calcular(int matriz[10][10], int m, int n){
	int sumadorPorSucursal = 0, maximo = 0;
	int indice = 0;
	for(int i = 0; i < m; i++){
		for(int j = 0; j < n; j++){
			sumadorPorSucursal = sumadorPorSucursal + matriz[i][j];
			if(sumadorPorSucursal > maximo){
				maximo = sumadorPorSucursal;
				indice = i;
			}
		}
	}
	
	return indice;
}
