/*


Francisco Miguel Perez - 44190234
 Carga un arreglo de 100 elementos con valores enteros entre 1 y 432.
a. La carga de los elementos se har� de manera aleatoria en una funci�n sin tipo.
b. Determinar cu�ntos valores son m�ltiplos de un escalar K que se ingresaron. Utiliza una 
funci�n con tipo. Mostrar en la funci�n principal la cantidad de m�ltiplos hallados.
c. Mostrar el arreglo en pantalla


*/

#include<stdio.h>
#include<stdlib.h>


void cargarArregloConRandom(int arreglo[100]);
void mostrarArreglo(int arreglo[100]);
int cantidadDeMultiplosDeK(int arreglo[100], int k);

main(){
	int array[100], valorK = 0;
	
	cargarArregloConRandom(array);
	
	printf("Ingrese un valor K: "); scanf("%d", &valorK);
//	mostrarArreglo(array);

	int multiplosDeK = cantidadDeMultiplosDeK(array, valorK);
	
	printf("Existen un total de: %d multiplos de %d \n", multiplosDeK, valorK);
	
	mostrarArreglo(array);
	
}

void cargarArregloConRandom(int arreglo[100]){
	int num = 0;
	for(int i = 0; i < 100; i++){
		num = rand()%432;
		arreglo[i] = num;
	}
}
void mostrarArreglo(int arreglo[100]){
	for(int i = 0; i < 100; i++){
		printf("%d, ", arreglo[i]);
	}
}

int cantidadDeMultiplosDeK(int arreglo[100], int k){
	int numero = 0;
	int	countMult = 0;
	int resto;
	
	for(int i = 0; i < 100; i++){
	 numero = arreglo[i];
	 resto = numero % k;
		if(resto == 0){
			countMult++;
		}
	}
	
	return countMult;
}
