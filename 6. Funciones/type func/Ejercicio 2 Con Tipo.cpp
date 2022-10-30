#include<stdlib.h>
#include<stdio.h>

/* El cuadrado de un n�mero entero X, tambi�n se puede calcular sumando los X primeros n�meros
impares.
I) Cree una funci�n con tipo, que calcule y retorne los cuadrados de N n�meros. obtenido mediantes sumas
sucesivas de los primeros X n�meros impares.
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

