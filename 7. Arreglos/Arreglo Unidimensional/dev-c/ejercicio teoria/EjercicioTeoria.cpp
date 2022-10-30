/*

Para el siguiente enunciado realice codificación.
En una escuela se ingresa por cada uno de los N alumnos, su promedio, coincidiendo el número de legajo con la posición.
Se solicita:
a) Cargar los elementos en el vector a través de una función sin tipo.
b) A través de una función con tipo indicar el legajo del alumno con mayor promedio

	Francisco Miguel Perez
*/

#include<stdio.h>
#include<stdlib.h>

void cargaDelVector(float vectorProm[10], int vectorLegajo[10] , int n);
int legajoMayorPromedio(float vectorProm[10], int n);

main(){
	int vectorLegajo[10];
	float vectorProm[10];
	int n;
	printf("Ingrese la cantidad de alumnos: "); scanf("%d", &n);
	
	cargaDelVector(vectorProm, vectorLegajo,  n);
	
/*	for(int i = 0; i < n ; i++){
		printf("El legajo es %d y su promedio %.2f \n", vectorLegajo[i], vectorProm[i]);
	}
Para verificar q si funciona xd */
	int indMayProm = legajoMayorPromedio(vectorProm,  n);
 	
 	printf("El legajo con mayor promedio es : %d", vectorLegajo[indMayProm]);
 	
	
}

int legajoMayorPromedio(float vectorProm[10], int n){
	int maxProm = 0;
	int indice = 0;
	for(int i = 0; i < n; i++){
		if(vectorProm[i] > maxProm){
			maxProm = vectorProm[i];
			indice = i;
		}
	}
	return indice;
}
void cargaDelVector(float vectorProm[10], int vectorLegajo[10] , int n){
	for(int i = 0 ; i < n ; i++){
		printf("Ingrese el legajo de %d/%d : ", i+1, n); 
		scanf("%d", &vectorLegajo[i]);
		printf("Ingrese el promedio de %d/%d : ", i+1, n);
		scanf("%f", &vectorProm[i]);
		system("cls");
	}
}

