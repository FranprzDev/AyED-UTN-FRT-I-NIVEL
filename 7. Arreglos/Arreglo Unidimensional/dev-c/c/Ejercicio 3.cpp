/*
 
 
 Francisco Miguel Perez - 44190234
 Se ingresa un conjunto no establecido de números reales a un arreglo.
a. Registrar los datos por medio de una función con tipo: 
La carga deberá terminar cuando se ingrese un cero.
Terminada la carga devolver la cantidad de números reales que se ingresaron. 
b. Buscar por medio de una función si un número ingresado por teclado se encuentra en el 
conjunto de valores guardados. El valor a buscar se ingresa en la función principal main.
Si el valor es encontrado, Mostrar un mensaje indicando la cantidad de veces que
se repite dicho valor.
Si el valor no es encontrado, “valor ingresado no se encuentra en la lista de valores ingresados”
 
 */
 
void buscarNumero(float arreglo[100], int contador, float numero); 
 
#include<stdio.h>

main(){
	float array[100], numero = 0, numABuscar = 0;;
	int contador = 0;
	
	do{
		printf("Ingrese un elemento del array ");
		scanf("%f", &numero);
		array[contador] = numero;
		contador++;
	}while(numero != 0);

	printf("La cantidad de numeros reales ingresada es de: %d ", contador);
	
	printf("\nIngrese un numero para buscar: "); scanf("%f", &numABuscar);

   	buscarNumero(array, contador, numABuscar);
}

void buscarNumero(float arreglo[100], int contador, float numero){
	
	int n = contador;
	int cantidadDeRep = 0;
	
	for(int i = 0; i < n; i ++){
		if(arreglo[i] == numero){
			cantidadDeRep++;	
		}
	}
	
	if(cantidadDeRep == 0){
		printf("\nEl valor ingresado no se encuentra en la lista de valores ingresados");
	}else{
		printf("\nEl valor ingresado se encuentra un total de %d veces.", cantidadDeRep);
	}
}
