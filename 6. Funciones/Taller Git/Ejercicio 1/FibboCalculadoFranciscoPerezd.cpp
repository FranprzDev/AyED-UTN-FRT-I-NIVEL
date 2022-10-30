#include<stdio.h>

int fibboCalculado(int numero);

main(){
	int num = 0;
	printf("Ingrese el primer numero para fibonacci: ");
	scanf("%d", &num);
	int fibbo = fibboCalculado(num);
	
	if(fibbo == -1){
		printf("El numero ingresado es incorrecto");
	}else{
		printf("El numero de la sucesion es: %d", fibbo);	
	}
	
}

int fibboCalculado(int numero){
	int fibboCalcualdo = 0;
	if(numero >= 0){
		fibboCalcualdo = numero-1 + numero -2;
	}else if(numero < 0){
		fibboCalcualdo = -1;
	}
	return fibboCalcualdo;
}
