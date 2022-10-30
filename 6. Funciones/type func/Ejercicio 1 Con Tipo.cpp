#include<stdio.h>
#include<stdlib.h>

// prototipo de la func
float promedio(int cMaq1, int cMaq2, int cMaq3, int acumuladorDeEnvases, int acumuladorDeDesechados);

main(){
	int codigo = 0, cantidadEnvasesProducidos = 0, envasesDesechados = 0;
	int contadorMaq1 = 0, contadorMaq2 = 0, contadorMaq3 = 0;
	int acumuladorEnvases = 0, acumuladorDesechados = 0;
	
	do{
	printf("Ingrese el codigo de la maquina ");
	scanf("%d", &codigo);
	printf("Ingrese la cantidad de envases producidos x semana "); 
	scanf("%d", &cantidadEnvasesProducidos);
	printf("Ingrese la cantidad de envases desechados ");
	scanf("%d", &envasesDesechados);
	
	
	switch(codigo){
	case 1:
		contadorMaq1++;
		acumuladorEnvases += cantidadEnvasesProducidos;
		acumuladorDesechados += envasesDesechados;
		break;
	case 2:
		contadorMaq2++;
		acumuladorEnvases += cantidadEnvasesProducidos;	
		acumuladorDesechados += envasesDesechados;
		break;	
	case 3:
		contadorMaq3++;
		acumuladorEnvases += cantidadEnvasesProducidos;
		acumuladorDesechados += envasesDesechados;		
	break;
	default:
		printf("\n\nNo existe dicha maquina.");
		break;
	}
	}while(codigo == 1 || codigo == 2 || codigo == 3);
	
	float prom = promedio(contadorMaq1, contadorMaq2, contadorMaq3, acumuladorEnvases, acumuladorDesechados);
	
	printf("\n\nEl promedio de envases desechados respecto a los envases creados es de %.2f", prom);
}

// desarrollo de la func
float promedio(int cMaq1, int cMaq2, int cMaq3, int acumuladorDeEnvases, int acumuladorDeDesechados){
	int sumatoria = cMaq1+cMaq2+cMaq3;
	float prom = 0.0; 
	prom = (acumuladorDeDesechados * 100)/acumuladorDeEnvases;
	return prom;
}

