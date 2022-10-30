/*

	Francisco Miguel Perez - 44190234 
	Legajo nº: 56355
	Universidad Tecnológica Nacional 



Se tiene un de orden MxNxP de valores enteros.
a. Usando una función SIN TIPO, realizar la carga del Arreglo Tridimensional.
b. Usando una función, llenar un vector donde cada elemento del vector corresponde a la suma de todos
los elementos del plano del arreglo Tridimensional. (Nota: La suma de los elementos del plano cero se
almacena en la posición cero del vector, La suma de los elementos del plano uno se almacena en la
posición uno del vector, La suma de los elementos del plano dos se almacena en la posición dos del
vector, así hasta sumar todos los planos).
c. Usando una función SIN TIPO, listar el vector.
d. Usando una función CON TIPO, calcular el promedio del vector y mostrar en main.

*/

#include <stdio.h>

void cargarArreglo(int array[10][10][10], int k, int m, int n);
void mostrarArreglo(int array[10][10][10], int k, int m, int n);
void sumarArregloTri(int array[10][10][10], int &k, int &m, int &n, int vector[10]);
void llenarVectorParalelo(int vector[10], int planos, int acumulador);
void mostrarVector(int vector[10], int k);
float promedioDelVector(int vector[10], int &k);
int sumadorVector(int vector[10], int k);

main(){
	int k,m,n, matriz[10][10][10], vector[10];
	printf("Ingrese k (planos): "); scanf("%d", &k);
	printf("Ingrese m (filas): "); scanf("%d", &m);
	printf("Ingrese n (columnas): "); scanf("%d", &n);
	
	cargarArreglo(matriz, k, m, n);
	mostrarArreglo(matriz, k, m, n);
	
	printf("\n\n\n - Mostrado Correctamente - \n");
	
	sumarArregloTri(matriz, k, m, n, vector);
	printf("\nVector de sumas de planos: ");
	mostrarVector(vector, k);
	float promedio = (float) promedioDelVector(vector, k);
	printf("\n\nEl promedio es %.2f", promedio);
	
}

void cargarArreglo(int array[10][10][10], int k, int m, int n){
	for(int planos = 0; planos < k; planos++){
		for(int filas = 0; filas < m; filas++){
			for(int columnas = 0; columnas < n; columnas++){
				printf("Ingrese el valor de [%d][%d][%d]: ", planos, filas, columnas);
				scanf("%d", &array[planos][filas][columnas]);
			}
		}
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

void sumarArregloTri(int array[10][10][10], int &k, int &m, int &n, int vector[10]){
	int acumulador;
	for(int planos = 0; planos < k; planos++){
			acumulador = 0;
		for(int filas = 0; filas < m; filas++){
			for(int columnas = 0; columnas < n; columnas++){
				acumulador += array[planos][filas][columnas];
			}
		}
		llenarVectorParalelo(vector, planos, acumulador);
	}
}

void llenarVectorParalelo(int vector[10], int planos, int acumulador)
{ vector[planos] = acumulador; }

void mostrarVector(int vector[10], int k){
	for(int i = 0; i < k ; i++){
		printf("{ %d = [%d] } || ", i,vector[i]);
	}
}

float promedioDelVector(int vector[10], int &k){
	float promedio = 0.0;
	int suma = sumadorVector(vector, k);
	promedio = suma / k;
	return promedio;
}

int sumadorVector(int vector[10], int k){
	int ac = 0;
	for(int i = 0; i < k; i++) ac += vector[i];
	return ac; 
}
