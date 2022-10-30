/*
	TP N� 4 -> Funciones "Recursividad"
	
Enunciado:	Desarrolla una funci�n recursiva que permita obtener el producto de dos n�meros (a y b) enteros
	positivos mayor a cero. Aplicando el concepto de �sumar el n�mero �a� la cantidad de veces que indica
	el n�mero �b�.

		Universidad Tecnol�gica Nacional
			Facultad Regional de Tucum�n
			Francisco Miguel Perez  
				<-> 44190234 
				<-> Legajo N� 56355
	
*/

#include<stdio.h>

int multiplicacionConOtroMetodo(int numero, int cantidad);

main(){
	int numero = 0, cantidad = 0, multiplicacion = 0;
	
	printf("Ingrese el numero que desea multiplicar "); scanf("%d", &numero);
	printf("Ingrese la cantidad de veces que desea multiplicar "); scanf("%d", &cantidad);
	
	if(numero > 0 && cantidad > 0){
	 	multiplicacion = multiplicacionConOtroMetodo(numero, cantidad);		
	}
		
	printf("\n--------------------------------");
	printf("\nLa multiplicacion es de %d", multiplicacion);
	
}

int multiplicacionConOtroMetodo(int numero, int cantidad){
	int multiplicacion = 0;
	if(cantidad > 0){
		multiplicacion = numero + (multiplicacionConOtroMetodo(numero, cantidad-1));
	}
	
	return multiplicacion;
}
