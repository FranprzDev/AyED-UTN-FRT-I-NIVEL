/*
Para el siguiente enunciado codificación.
En una escuela se ingresa por cada uno de los N alumnos, su promedio en un vector llamado PROM, 
y un vector llamado LEG donde se guardan los números de legajo.
Se solicita:
a) Cargar los elementos en los vectores a través de una función sin tipo.
b) Ordenar los vectores de acuerdo al promedio en orden descendente a través de una función sin tipo, mostrar luego en main(),
los tres primeros promedios con sus correspondientes números de legajo.
c) A través de una función con tipo indicar, en la función principal, si un determinado número de legajo ingresado en main()
 se encuentra o no en el vector.
 
 Francisco Miguel Perez UTN - FRT
*/

#include<stdio.h>
#include<stdlib.h>

void cargaDelVector(int vectorLegajo[10], float vectorProm[10], int n);
void ordenarVector(int vectorLegajo[10], float vectorProm[10], int n);
bool buscarLegajo(int vectorLegajo[10], int n); 

int main(){
	int vectorLegajo[10];
	float vectorProm[10];
	system("cls");
	int n;
	printf("Ingrese la cantidad de alumnos: "); scanf("%d", &n);
	printf("\n");
	cargaDelVector(vectorLegajo, vectorProm,  n);
	ordenarVector(vectorLegajo, vectorProm,  n);
	
	printf("\nLos 3 primeros legajos y promedios son: ");	
	for(int i = 0; i < 3; i++){
		printf("\n%d - Legajo: %d Promedio: %.2f", i+1, vectorLegajo[i], vectorProm[i]);
	}
	
	bool comp = buscarLegajo(vectorLegajo, n);
	
	if(comp == 1){
		printf("\nEl numero se encuentra.");
	}else{
		printf("\nEl numero no se encuentra.");
	}
}

void cargaDelVector(int vectorLegajo[10], float vectorProm[10], int n){
	for(int i = 0 ; i < n ; i++){
		printf("Ingrese el legajo de %d/%d : ", i+1, n); 
		scanf("%d", &vectorLegajo[i]);
		printf("Ingrese el promedio de %d/%d : ", i+1, n);
		scanf("%f", &vectorProm[i]);
	}
}

void ordenarVector(int vectorLegajo[10], float vectorProm[10], int n){
	int auxiliar = 0, bandera = 0; 

	do{
	
	for(int i = 0; i < n-1; i++){
		if(vectorProm[i] < vectorProm[i+1]){
		
		// Acomodar el promedio.
		auxiliar = vectorProm[i];	
		vectorProm[i] = vectorProm[i+1];
		vectorProm[i+1] = auxiliar;
		
		// Acomodar el legajo.
		auxiliar = vectorLegajo[i];
		vectorLegajo[i] = vectorLegajo[i+1];
		vectorLegajo[i+1] = auxiliar;
			bandera = 1;
		}else{
			bandera = 0;
		}
	}		
 }while(bandera == 1);
}

bool buscarLegajo(int vectorLegajo[10], int n){
	int numLegajo = 0, bandera = 0;
	printf("\n\nIngrese el numero de legajo que desea buscar: "); 
	scanf("%d", &numLegajo);
	for(int i = 0; i < n; i++){
		int elemComp = vectorLegajo[i];
		if(vectorLegajo[i] == numLegajo){
			bandera = 1;
		}
	}
	if(bandera == 0){
		return false;
	}else{
		return true;
	}
}
