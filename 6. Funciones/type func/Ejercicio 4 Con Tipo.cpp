/*


	Francisco Miguel Perez 1K5 - Legajo Nº 56355
		Universidad Tecnológica Nacional 
			Facultad Regional Tucumán.
	Ingresar una cantidad de N valores enteros.		
	
	Enunciado:
	A través de una función Sin Tipo encontrar el porcentaje de valores pares que se introducen, la
	función recibe dos parámetros el primero por valor (cantidad a sumar) y otro por referencia (variable
	que almacena la suma de los números recibidos).
	b) A través de una función Con Tipo encontrar el promedio de valores impares.
	c) Muestre los resultados obtenidos en la función main.
	
*/

#include<stdio.h>
#include<stdlib.h>

void porcentajePares(int numero, int &acumuladorNum);
float promedioValorImpar(int totalNumeros, int contadorImpares, int acumuladorImpares);

main(){
	int bandera = 1;
	int contadorNum = 0;
	int acumuladorImpares = 0; 
	int contadorImpares = 0;
	int totalNumeros = 0;
	int numero = 0;
	

	while(bandera == 1){

		printf("Ingrese un valor: "); scanf("%d", &numero);
		porcentajePares(numero, contadorNum);	
		totalNumeros++;
		if(numero % 2 == 1){
			acumuladorImpares += numero;
			contadorImpares++;
		}
		printf("Desea seguir ingresando valores? \tSI (1) - NO (2) \nSu decision: "); scanf("%d", &bandera);
	}

	float promedio = promedioValorImpar(totalNumeros, contadorImpares, acumuladorImpares);
	printf("\nSe ingreso un total de %d de numeros pares", contadorNum);
	printf("\nEl promedio es %2.f%%", promedio);	
	
}

void porcentajePares(int numero, int &contadorNum){
	if(numero % 2 == 0){
		contadorNum += 1;
	}
} // fin void 

float promedioValorImpar(int totalNumeros, int contadorImpares, int acumuladorImpares){
	int cantidadImpares = totalNumeros - contadorImpares;
	float promedio = (float) (cantidadImpares*100)/totalNumeros;
	// 100 _ 10
	// x _ 7
	return promedio;
}

