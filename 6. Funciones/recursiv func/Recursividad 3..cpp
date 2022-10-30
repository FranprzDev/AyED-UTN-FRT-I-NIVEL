/*

	TP Nº 4 -> Funciones "Recursividad"
Se ingresan una cantidad NO definidas de valores enteros positivos “X” mayores a cero.
a) Haciendo uso de una función recursiva obtener del número ingresado su factorial.
b) Finalizando el ingreso cuando se ingrese un numero “X” negativo.

		Universidad Tecnológica Nacional
		Facultad Regional de Tucumán
			Francisco Miguel Perez  
				<-> 44190234 
				<-> Legajo Nº 56355
*/

#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int factorialNumero(int x);

main(){
	int x = 0;
	int bandera = 1;
	while(bandera == 1){
		printf("Ingrese X "); scanf("%d", &x);
		int fact = 0;
		fact = factorialNumero(x);
		printf("\nEl factorial de %d es %d", x, fact);
		printf("\nDesea seguir ingresando valores? ");
		printf("\n1. Si \n2. No \nTu decision: ");
		scanf("%d", &bandera);
	}
}

int factorialNumero(int x){
	int factorial = 0;
	if(x == 0 || x == 1){
		factorial = 1;
	}else{
		factorial = x * factorialNumero(x-1);
	}
	
	return factorial;
}
