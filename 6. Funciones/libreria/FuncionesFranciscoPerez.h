#include<stdio.h>

// PROTOTIPOS ---------------------
int devolverMayorValor(int a1, int b1, int c1);
int menorValor(int a1, int b1, int c1);
float promedioValores(int a1, int b1, int c1);
int productoDeDosValores(int a, int b, int c);
float divisionDosNumeros(int a, int b, int c, int &resultadoDivision);
int sumarDosValores(int a, int b, int c);
int restarDosValores(int a, int b, int c);



// FIN PROTOTIPOS ------------------------



// DESARROLLO ---------------
int devolverMayorValor(int a1, int b1, int c1){
	int mayorValor = 0;
	
	if(a1 > b1 && a1 > c1){
		mayorValor = a1;
 	}else if(b1 > a1 && b1 > c1){
 		mayorValor = b1;
	}else if(c1 > a1 && c1 > b1){
		mayorValor = c1;
	}
	
	return mayorValor;
}

int menorValor(int a1, int b1, int c1){
	int menorValor = 0;
	
	if(a1 > b1 && a1 > c1){
		if(b1 > c1){
			menorValor = c1;
		}else{
			menorValor = b1;
		}
 	}else if(b1 > a1 && b1 > c1){
		if(a1 > c1){
			menorValor = c1;
		}else{
			menorValor = a1;
		}
	}else if(c1 > a1 && c1 > b1){
		if(a1 > b1){
			menorValor = b1;
		}else{
			menorValor = a1;
		}
	}
	return menorValor;
}

float promedioValores(int a1, int b1, int c1){
	float sumatoria = a1+b1+c1;
	float promedio = (float) sumatoria/3;
	return promedio;
}

int productoDeDosValores(int a, int b, int c){
	int des = 0, multiplicacion = 0; 
	printf("\n¿Que valores desea multiplicar?");
	printf("\n1. A*B \t2. A*C \t3. B*C\n Su decision: "); scanf("%d", &des);
	switch(des){
		case 1:
			printf("\nIngreso la opcion 1, A*B");
			multiplicacion = a*b;
			break;
		case 2:
			printf("\nIngreso la opcion 2, A*C");
			multiplicacion = a*c;
			break;
		case 3:
			printf("\nIngreso la opcion 3, B*C");
			multiplicacion = b*c;
			break;
		default:
			printf("\nIngreso una opcion no valida, el resultado será 0.");
			multiplicacion = 0;
			break;
	}
	return multiplicacion;
}

void divisionDosNumeros(int a, int b, int c, float &division){
	int des = 0; 
	printf("\nQue valores desea dividir ");
	printf("\n1. A/B \t2. A/C \t3. B/A \t4. C/A \t5. B/C  \t6. C/B"); 
	printf("\nSu decision: "); scanf("%d", &des);
	switch(des){
		case 1:
			printf("\nIngreso la opcion 1, A/B");
			if(b != 0){
				division = a/b;
			}else{
				printf("\nDivision por cero no definida.");
				printf("\nSe establece el resultado en 0.");
				division = 0;
			}
			break;
		case 2:
			printf("\nIngreso la opcion 2, A/C");
			if(c != 0){
				division = a/c;
			}else{
				printf("\nDivision por cero no definida.");
				printf("\nSe establece el resultado en 0.");
				division = 0;
			}
			break;
		case 3:
			printf("\nIngreso la opcion 3, B/A");
			if(a != 0){
				division = b/a;
			}else{
				printf("\nDivision por cero no definida.");
				printf("\nSe establece el resultado en 0.");
				division = 0;
			}
			break;
		case 4:
			printf("\nIngreso la opcion 4, C/A");
			if(a != 0){
				division = c/a;
			}else{
				printf("\nDivision por cero no definida.");
				printf("\nSe establece el resultado en 0.");
				division = 0;
			}
			break;
		case 5:
			printf("\nIngreso la opcion 5, B/C");
			if(c != 0){
				division = b/c;
			}else{
				printf("\nDivision por cero no definida.");
				printf("\nSe establece el resultado en 0.");
				division = 0;
			}
			break;
		case 6:
			printf("\nIngreso la opcion 5, C/B");
			if(b != 0){
				division = c/b;
			}else{
				printf("\nDivision por cero no definida.");
				printf("\nSe establece el resultado en 0.");
				division = 0;
			}
			break;
		default:
			printf("\nIngreso una opcion no valida, el resultado de la división será 0.");
			division = 0;
			break;
	}
}

int sumarDosValores(int a, int b, int c){
	int des = 0, suma = 0;
	printf("\n¿Que valores desea sumar? "); 
	printf("\n1. A+B \t2. A+C \t3. B+C"); 
	printf("\nSu decision: "); scanf("%d", &des);
	switch(des){
		case 1:
			printf("\nEligio A+B");
			suma = a+b;			
			break;
		case 2:
			printf("\nEligio A+C");
			suma = a+c;
			break;
		case 3:
			printf("\nEligio B+C");
			suma = b+c;
			break;
		default:
			printf("\nIngreso una opcion incorrecta, por lo tanto la suma sera 0\n");
			suma = 0;
			break;
	}
	return suma;
}

int restarDosValores(int a, int b, int c){
	int des, resta = 0;
	printf("\n¿Que accion desea realizar?");
	printf("\n1. A-B \t2. A-C \t3. B-A \t4. C-A \t5. B-C \t6. C-B");
	printf("\nSu decision: "); scanf("%d", &des);
	switch(des){
		case 1:
			printf("\nEligio A-B");
			resta = a-b;
			break;
		case 2:
			printf("\nEligio A-C");
			resta = a-c;
			break;
		case 3:
			printf("\nEligio B-A");
			resta = b-a;
			break;
		case 4:
			printf("Eligio C-A");
			resta = c-a;
			break;
		case 5:
			printf("Eligio B-C");
			resta = b-c;
			break;
		case 6:
			printf("Eligio C-B");
			resta = c-b;
			break;
		default:
			printf("\nEligio una opcion incorrecta\n");
			printf("\nPor lo tanto sera 0 la respuseta.\n");
			resta = 0;
			break;
	}
	return resta;
}
