/*

Se tiene un Arreglo Tridimensional de valores enteros, de orden MxNxP.
    a. Realizar la carga del Arreglo Tridimensional, por medio de una función.
    b. Mediante una función, Realizar la carga a un vector, que contendrá en cada elemento la suma de los
    elementos de cada plano de la Arreglo Tridimensional. (Nota: Tener en cuenta el orden que se deberá dar al
    vector en su definición).
    c. Mostrar el vector generado a través de una función sin tipo.
*/

#include<stdio.h>
#include<stdlib.h>

// arreglo tridimensional MxNxP

void cargarArregloTridimensional(int arreglo[10][10][10], int planos, int columnas, int filas);
void cargarArregloDeSuma(int arreglo[10][10][10], int vectorSuma[3], int planos,int columnas, int filas);
void mostrarArreglo(int vectorSuma[10], int planos);
void mostrarArregloTrid(int arreglo[10][10][10], int planos, int columnas, int filas);

main(){
    int planos = 0, columnas = 0, filas = 0;

    int miArreglo[10][10][10];
    int sumaPlano[10];

    printf("Ingrese la cantidad de planos: ");
    scanf("%d", &planos);
    printf("Ingrese la cantidad de columnas: ");
    scanf("%d", &columnas);
    printf("Ingrese la cantidad de filas: ");
    scanf("%d", &filas);

    cargarArregloTridimensional(miArreglo, planos, columnas, filas);
	
	mostrarArregloTrid(miArreglo, planos, columnas, filas);
	
	printf("\n");
	system("pause");

    cargarArregloDeSuma(miArreglo, sumaPlano, planos, columnas, filas);

    system("pause");
    system("cls");
    printf("\nLa suma de los arreglos es: ");

    printf("\n");

    mostrarArreglo(sumaPlano, planos); 

    

}

void cargarArregloTridimensional(int arreglo[10][10][10], int planos, int columnas, int filas){
    system("cls");
    int numero = 0;
    for(int k = 0; k < planos; k++){
        for(int j = 0; j < columnas; j++){
        	
            for(int i = 0; i < filas; i++){
            	numero = 0;
                printf("Ingrese en plano %d el elemento [%d][%d]: ", k, j, i);
                scanf("%d", &numero);
                arreglo[k][j][i] = numero;

               // scanf("%d", &arreglo[k][j][i]);
            }
        }
    }
}

void cargarArregloDeSuma(int arreglo[10][10][10], int vectorSuma[10], int planos,int columnas, int filas){
    int acumulador = 0;
    int numero = 0;
    for(int k = 0; k < planos; k++){
		acumulador = 0;
     for(int j = 0; j < columnas; j++){
        for(int i = 0; i < filas; i++){
        	numero = arreglo[k][j][i];
            acumulador += numero;
            vectorSuma[k] = acumulador;
        }
     }
    }
}

void mostrarArreglo(int vectorSuma[10], int planos) {
    for(int i = 0; i < planos; i++){
        printf("\n%d: %d", i, vectorSuma[i]);
    }
}

void mostrarArregloTrid(int arreglo[10][10][10], int planos, int columnas, int filas){
	system("cls");
	for(int k = 0; k < planos; k++){
		printf("\nPlano %d: ", k);
		for(int j = 0; j < columnas; j++){
			printf("\n");
			for(int i = 0; i < filas; i++){
				printf("| %d ", arreglo[k][j][i]);
			}
		}
	}
}