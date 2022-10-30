/*
	TP N� 4 -> Funciones "Recursividad"
Enunciado: 
	Desarrolla una funci�n recursiva que permita dividir en forma entera un numero positivo a, mayor
	a cero por otro n�mero positivo b, menor que a, aplicando el principio de �determinar cu�ntas veces
	cabe b en a aplicando restas sucesivas�. 

		Universidad Tecnol�gica Nacional
			Facultad Regional de Tucum�n
			Francisco Miguel Perez  
				<-> 44190234 
				<-> Legajo N� 56355
	
*/

#include<stdio.h>

int division(int a, int b);

main(){
	int a = 0, b = 0;
	
	printf("Ingrese a "); scanf("%d", &a);
	printf("Ingrese b "); scanf("%d", &b);
	
	int r = division(a,b);
	if(a % 2 == 1){
		printf("\nLa division es %d", r);	
	}else{
		printf("\nLa division es %d", r+1);
	}


}

int division(int a, int b){
	int div;
	if(a>0 && b<a) {
		div = 1 + division(a-b, b);	
	}else{
		div = 0;
	}
	
	return div;
}
