/*

	Francisco Miguel Perez - 44190234 
	Legajo nº: 56355
	Universidad Tecnológica Nacional 



8) Se tiene un Arreglo Tridimensional de valores enteros, de orden MxNxP.
a. Realizar la carga del Arreglo Tridimensional, por medio de una función.
b. Mediante una función, Realizar la carga a un vector, que contendrá en cada elemento la suma de los
elementos de cada plano de la Arreglo Tridimensional. (Nota: Tener en cuenta el orden que se deberá dar al
vector en su definición).
c. Mostrar el vector generado a través de una función sin tipo

*/

#include<stdio.h>

void cargarArreglo(int array[10][10][10], int k, int m, int n);
void mostrarArreglo(int array[10][10][10], int k, int m, int n);
void sumarArregloTri(int array[10][10][10], int &k, int &m, int &n, int vector[10]);
void llenarVectorParalelo(int vector[10], int planos, int acumulador);
void mostrarVector(int vector[10], int k);

main(){
	int k,m,n, array[10][10][10];
    int vectPar[10]; // long = planos
	printf("Ingrese k: "); scanf("%d", &k);
	printf("Ingrese m: "); scanf("%d", &m);
	printf("Ingrese n: "); scanf("%d", &n);

    cargarArreglo(array, k,m,n);
	mostrarArreglo(array, k, m, n);

	printf("\n\n");
    sumarArregloTri(array, k, m, n, vectPar);

    mostrarVector(vectPar, k);
    
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
		printf("\nPlano %d: \n", planos);
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

