/*
	Universidad Tecnológica Nacional
		Facultad Regional de Tucumán
		
	Alumno: Francisco Miguel Perez  - 44190234
		Legajo Nº 56355 
		Comisión 1K5 - 2022
*/

/* Enunciado:

En este ejercicio se realizará la creación de varias funciones las cuales serán guardadas como una
biblioteca (librería) para luego ser utilizadas en su programa.
I) Crea una librería que contenga las siguientes funciones de tipo:
(1) Retorne el mayor valor de 3 valores cualquiera,	  -----> Hecho <-----
(2) Retorne el menor valor de 3 valores cualquiera, -----> Hecho <-----
(3) Retorne el promedio de 3 valores cualquiera, -----> Hecho <-----
(4) Retorne el resultado del producto de dos valores, -----> Hecho <-----
(5) Mostrar el resultado de la división de dos valores. Tener en cuenta división en cero, usar
parámetro por referencia. ({FUNCIÓN DEL TIPO VOID, POR PARÁMETRO POR REFERENCIA.}) -----> Hecho <-----
(6) Retorne el resultado de Sumar dos valores, -----> Hecho <-----
(7) Mostrar el resultado de restar dos valores, que debe ser devuelto en el parámetro por
referencia. -----> Hecho <-----
II) Una vez creadas las funciones, deberás guardar el archivo nombre.h, el nombre se elijes según su
criterio, en la carpeta “C:\Program Files (x86)\Dev-Cpp\MinGW32\include” esto puede variar
dependiendo de la versión del sistema operativo y/o del lugar donde fue instalado el DEV-C.
III) Ahora realiza un programa que permita el ingreso de 3 valores enteros. 

*/
#include<stdio.h>
#include "FuncionesFranciscoPerez.h"

main(){
	int a,b,c;
	float division = (float) 0; 
	printf("Ingrese el numero A "); scanf("%d", &a);
	printf("\nIngrese el numero B "); scanf("%d", &b);
	printf("\nIngrese el numero C "); scanf("%d", &c);
	
	printf("\n\n");
	printf("\nMAYOR Y MENOR\n");


	// mayor y menor
	if(a != b && b != c){
		int mayorValor = devolverMayorValor(a,b,c);
		printf("\nEl valor mayor es: %d", mayorValor);
		int menV = menorValor(a,b,c);
		printf("\nEl menor valor es: %d", menV);	
	}else{
		printf("\n\t-----\t Los valores son iguales         -----\n");
	}
	
	printf("\n\n");
	printf("\nPROMEDIO DE VALORES\n");
	
	// promedio de valores
	float prom = (float) promedioValores(a,b,c);
	printf("\nEl promedio de valores es: %.2f", prom);
	
	printf("\n\n");
	printf("\nPRODUCTO DE DOS VALORES\n");
	
	// producto de dos valores
	int producto = productoDeDosValores(a,b,c);
	printf("\nEl producto es: %d", producto);
	
	printf("\n\n");
	printf("\nDIVISION DE DOS NUMEROS\n");
	
	// divisionDosNumeros
	divisionDosNumeros(a,b,c, division);
	printf("\nEl resultado de la division es: %.2f", division);
	 
	printf("\n\n");
	printf("\nSUMAR DOS VALORES\n");
	 
	// sumarDosValores
	int suma = sumarDosValores(a,b,c);
	printf("\nLa suma de los valores es: %d", suma);
	
	printf("\n\n");
	printf("\nRESTAR DOS VALORES\n");
	
	// restarDosValores
	int resta = restarDosValores(a,b,c);
	printf("\nLa resta es: %d", resta);
	
}
