#include<stdio.h>
#include<conio.h>
#include<math.h>

/*
Utilizar en las funciones de este ejercicio parámetros por valor y por referencia.
I) Crear una función para Calcular la superficie de un cuadrado. Suponiendo como lado del mismo al mayor
valor de los números dados. Su resultado debe ser mostrado en la función main.
II) Crear una función para Calcular la superficie de un circulo. Suponiendo como radio del mismo al menor de
los números dados. Su resultado debe ser mostrado en la función main.
En este problema se trabajar con tres funciones definidas por el programador, para nuestro caso serán
funciones sin tipo, cuyos prototipos son los siguientes:

	Francisco Miguel Perez , 44190234 Legajo Nº 56355
*/

void determinarMayorMenor(int &May, int &Men);
void areaCuadrado (int May, int &SupCua);
void areaCilindro(int Men, int &SupCil);

main(){
	int SupCua, SupCil;
	int May = 0, Men = 0;
	printf("Ingrese un numero, "); scanf("%d", &May);
	printf("\nIngrese el otro numero, "); scanf("%d", &Men);
	
	if(May != Men){
		
	determinarMayorMenor(May, Men);
		
	areaCuadrado(May, SupCua);
		printf("\n\nLa superficie del cuadrado es de %d unidades^2", SupCua);
		
	areaCilindro(Men, SupCil);
		printf("\n\nLa superficie del circulo es de %d unidades^2", SupCil);
	
	}else{
		
		printf("Los numeros son iguales.\n\n");
		getchar();
		
	}
} // fin main

void determinarMayorMenor (int &May, int &Men){
	if(Men > May){
		int aux = May;
		May = Men;
		Men = aux;
	}	
} // fin func determinar


void areaCuadrado(int May, int &SupCua){
	SupCua = May*May;
} // fin func cuadrado

void  areaCilindro(int Men, int &SupCil){
	SupCil = 3*(Men*Men);
} // fin func cilindro
