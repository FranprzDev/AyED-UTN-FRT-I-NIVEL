#include<stdio.h>
#include<stdlib.h>
#include "LibreriaFrnaciscoPerez.h"

main(){
	int numero1 = 0, numero2 = 0;
	printf("Ingrese el primer numero "); scanf("%d", &numero1);
	printf("\nIngrese el segundo numero "); scanf("%d", &numero2);
	
	// suma
	int suma1 = 0;
	suma1 = suma(numero1, numero2);
	printf("\nEl resultado de la suma es %d", suma1);
	// resta numero1-numero2
	int resta1 = 0;
	resta1 = resta(numero1, numero2);
	printf("\nEl resultado de la resta es %d", resta1);
	// multiplicacion
	int multiplicacion1 = 0;
	multiplicacion1 = multiplicacion(numero1, numero2);
	printf("\nEl resultado de la multiplicacion es %d", multiplicacion1);
	// division numero1/numero2 , con numero2 != 0
	float division1 = 0.0;
	division1 = division(numero1, numero2);
	if(numero2 != 0){
		printf("\nEl resultado de la division es %.2f", division1);	
	}else{
		printf("\nLa division por cero no esta definida...");
	}

}
