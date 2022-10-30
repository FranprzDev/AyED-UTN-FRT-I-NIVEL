/*

	Francisco Miguel Perez - 44190234 
	Legajo nº: 56355
	Universidad Tecnológica Nacional 
	 
Dado un Arreglo Bidimensional de MxN donde M=4 y N=3 cuyo contenido son números
reales.

matriz 4x3

a. Haciendo uso de una función SIN TIPO, ingrese elementos a la matriz.
b. Haciendo uso de una función CON TIPO, encuentre el mayor y menor elemento de la matriz. Los
valores se mostrarán en la función principal main.
c. Usando una función SIN TIPO, liste los elementos de la matriz separados por un guion medio de
manera que se visualicen sus datos en forma de matriz (filas y columnas).

*/

#include<stdio.h>
#include<stdlib.h>

void cargarMatriz(int matriz[4][3]);
int encontrarMayorYMenor(int matriz[4][3], int &menor);
void mostrarMatriz(int matriz[4][3]);

main(){
	int matriz[4][3];
	int m = 4, n = 3, menor = 0;
	
	cargarMatriz(matriz);
	int mayor = encontrarMayorYMenor(matriz, menor);
	
	printf("\nEl elemento mayor es: %d ", mayor);
	printf("\nEl elemento menro es: %d ", menor);
	
	printf("\n\n");
	mostrarMatriz(matriz);
}

void cargarMatriz(int matriz[4][3]){
	for(int i = 0; i < 4; i++){
		for(int j = 0; j < 3; j++){
			printf("Ingrese el elemento [%d][%d]: ", i+1,j+1);
			scanf("%d", &matriz[i][j]);
		}
	}
}

int encontrarMayorYMenor(int matriz[4][3], int &menor){
	int mayor = 0, valor = 0;;
	
	for(int i = 0; i < 4; i++){
		for(int j = 0; j < 3; j++){
			valor = matriz[i][j];
			
			if(mayor < matriz[i][j]){
				mayor = matriz[i][j];
			}
			if(menor > matriz[i][j]){
				menor = matriz[i][j];
			}
		}
	}
	return mayor;
}

void mostrarMatriz(int matriz[4][3]){
	for(int i = 0; i < 4; i++){
			printf("\n\n");
		for(int j = 0; j < 3; j++){
			printf("%d ", matriz[i][j]);
		}
	}
}
