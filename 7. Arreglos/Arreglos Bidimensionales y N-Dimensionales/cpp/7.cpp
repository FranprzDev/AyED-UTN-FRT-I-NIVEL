/*

	Francisco Miguel Perez - 44190234 
	Legajo nº: 56355
	Universidad Tecnológica Nacional 


07) Una empresa internacional, comercializa en 3 países los 4 productos que produce a través de sus 2
sucursales. Los datos de ventas están registrados en una matriz Tridimensional MxNxP. Donde P
representa países, M representa las sucursales y N representan los productos.
a. Defina y realizar la carga de las ventas en la matriz, por medio de una función.
b. Usando una función CON TIPO, calcule y muestre en main cuál fue el país que más vendió.
c. Usando una función CON o SIN TIPO según estime conveniente. Realizar un listado que muestre el
total de venta de cada una de las sucursales.
*/

#include<stdio.h>

void cargarArreglo(int array[10][10][10], int k, int m, int n);
void mostrarArreglo(int array[10][10][10], int k, int m, int n);
int paisMayVent(int array[10][10][10], int k, int m, int n);
void totalVentasSuc(int array[10][10][10], int k, int m, int n);

main(){
	int k,m,n, array[10][10][10];
	printf("Ingrese k (paises): "); scanf("%d", &k);
	m = 2;
	printf("Ingrese n (productos): "); scanf("%d", &n);

	cargarArreglo(array, k,m,n);
	mostrarArreglo(array, k, m, n);

	printf("\n");

	int indexP = paisMayVent(array, k, m, n);
                         -                                                   
	printf("\nEl pais con mayor ventas fue: %d", indexP);

	printf("\n\n");
	totalVentasSuc(array, k, m, n);

	printf("\n\n");
	
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
		printf("\n\nPais %d: \n", planos);
		for(int filas = 0; filas < m; filas++){
			printf("\n\n");
			for(int columnas = 0; columnas < n; columnas++){
				printf("[%d] ", array[planos][filas][columnas]);
			}
		}
	}
}

int paisMayVent(int array[10][10][10], int k, int m, int n){
	int acumulador;
	int mayVentas = 0;
	int indexPais;
	for(int planos = 0; planos < k; planos++){
		acumulador = 0;
		for(int filas = 0; filas < m; filas++){
			for(int columnas = 0; columnas < n; columnas++){
				acumulador += array[planos][filas][columnas];
				indexPais = planos;
			}
		}
		if(acumulador > mayVentas){
			mayVentas = acumulador;
			indexPais = planos;
		}
	}
	return indexPais;
}

void totalVentasSuc(int array[10][10][10], int k, int m, int n){
	int acumulador;
		for(int plano = 0; plano < k; plano++){
			acumulador = 0;
			printf("Plano %d: \n", plano);
			for(int filasNeed = 0; filasNeed < m; filasNeed++){
				for(int columnas = 0; columnas < n; columnas++){
					acumulador += array[plano][filasNeed][columnas];
				}
				printf("Sucursal %d: %d", filasNeed, acumulador);
				printf("\n");
				acumulador = 0;
			}
		}
}
