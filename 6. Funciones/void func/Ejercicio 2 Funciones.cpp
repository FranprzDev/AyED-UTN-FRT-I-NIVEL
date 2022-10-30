/* 	 Cree un programa que solicite por teclado N duplas de valores comprendidos entre 1 y 9

Por cada par de valores entero Num1 y Num2 realizar:
	Usando una función sin tipo determine y muestre ¿Cuáles son los primeros 10 múltiplos comunes
de num1 y num2?

	Francisco Miguel Perez, 44190234 - Legajo Nº 56355
*/

#include<stdio.h>

void primeros10Multiplos(int primero, int segundo);

main(){
	int a,b;
	printf("Ingrese un numero, "); scanf("%d", &a);
	printf("\nIngrese otro numero, "); scanf("%d", &b);
	
	if((a >= 1 && a <= 9) && (b >= 1 && b <= 9)){
		primeros10Multiplos(a, b);
	}else{
		printf("\n\n\tLos numeros no cumplen la condicion...");
	}
	
}

void primeros10Multiplos(int primero, int segundo){
	for(int i = 1; i <= 10; i++){
		printf("El multiplo (%d de 10) es %d\n", i, i*(primero*segundo));
	}		
}



