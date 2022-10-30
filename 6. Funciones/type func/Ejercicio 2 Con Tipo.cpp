#include<stdlib.h>
#include<stdio.h>

/* El cuadrado de un número entero X, también se puede calcular sumando los X primeros números
impares.
I) Cree una función con tipo, que calcule y retorne los cuadrados de N números. obtenido mediantes sumas
sucesivas de los primeros X números impares.
*/
int calcularCuadrado(int numero);

main(){
	int x = 0;
	printf("Ingrese el numero que desea calcular el cuadrado "); scanf("%d", &x);
	// llamo la func que lo hace xd 
	int cuadrado = calcularCuadrado(x);
	
	printf("\nEl cuadrado de %d es %d", x, cuadrado);
}

int calcularCuadrado(int numero){
	int sumaDeImpares = 0;
	int contadorDeImpares = 0;
	int numPSum = 0;
	
	while(contadorDeImpares < numero){
		if(numPSum % 2 == 1){
			sumaDeImpares += numPSum;
			contadorDeImpares++;
		}
		numPSum++;
	}

		
	return sumaDeImpares;
	}

