/*

Se ingresan N n�meros reales, crea una funci�n (Suma) para leer los N n�meros ingresados y realizar la suma.
El valor N se introduce por teclado en la funci�n main y es transferido a la funci�n suma usando par�metro por valor.
Mostrar el resultado de la suma en la funci�n main. La variable que acumula los valores sumados debe ser
de tipo real.

*/

#include <stdio.h>
#include <stdlib.h>

int sumados = 0; 
void suma(int cantidadASumar);

main(){
	int n;
	
	printf("Ingrese la cantidad N de numeros que desea sumar, ");  scanf("%d", &n);
	suma(n);
	
	printf("\nLa cantidad total de la suma es de %d", sumados);
	
}

void suma(int cantidadASumar){
	
	for(int i=0; i < cantidadASumar; i++){
		int num;
		printf("\nIngrese un numero para sumar, "); scanf("%d", &num);
		sumados = sumados + num;
		
	}
	
}




