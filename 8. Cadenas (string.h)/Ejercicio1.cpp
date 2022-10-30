/*

Realizar un programa que reciba por teclado diferentes palabras, hasta que se ingrese la palabra "final". 
Entonces se deberá mostrar por pantalla cual fue la palabra más larga ingresada y cuantas palabras 
se ingresaron sin contar la palabra “final”.


	Francisco Miguel Perez - 44190234
		Legajo Nº 56355
		DNI: 44190234
		UTN - FRT
		
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef char cadena[50];
cadena vector[30];

main(){
	
	int contador = 0; 
	int bandera = 0;
	char caden[7] = "final";
	int maximoPalabra = 0;
	int cantPalabrasAct = 0;
	int cantPalabrasSig = 0;
	int indice = 0;
	
	
	while(bandera == 0){
		printf("Ingrese %d en el vector: ", contador+1);
		_flushall();
		gets(vector[contador]);
		contador++;
		// strcomp
		int comp = 0;
		for(int i = 0; i < contador; i++){
			comp = strcmp(vector[i], caden);
			if(comp == 0){
				bandera = 1;
				contador--;
			}
		}
	}
	
	for(int i = 0; i < contador; i++){
		
		cantPalabrasAct = strlen(vector[i]);
		cantPalabrasSig = strlen(vector[i+1]);
		
		if(cantPalabrasAct > cantPalabrasSig){
			maximoPalabra = cantPalabrasAct;
			indice = i; 
			
		}
	}
	
	printf("\n\nEl maximo total es de: %d y la palabra es: %s", maximoPalabra, vector[indice]);
	printf("\n\nSe ingresaron un total de: %d palabras antes de la ultima palabra", contador);
	

}
