#include<stdio.h>
int contAdentro = 0, contAfuera = 0;

void intervalo(float limIzq, float limDer, int cantPuntos);

main(){
	
	int n;
	float limIzq = 0, limDer = 0;
	printf("Ingrese los limites del intervalo");
	printf("\nIngrese el limite izquierdo como intervalo abierto, "); scanf("%f", &limIzq);
	printf("\nIngrese el limite derecho como intervalo cerrado, "); scanf("%f", &limDer);
	
	if(limIzq > limDer){
		printf("\nIngreso una opcion incorrecta, cambio de intervalos");
		int aux = limIzq;
		limIzq = limDer;
		limDer = aux;
	}else if(limIzq == limDer){
		printf("\nEl intervalo solo incluye un numero.");
	}
	
	printf("\nIngrese la cantidad N de valores enteros que desea ingresar, "); scanf("%d", &n);
	
	intervalo(limIzq, limDer, n);
	
	printf("\n\nHay un total de %d puntos adentro del intervalo", contAdentro);
	printf("\n\nHay un total de %d puntos adentro del intervalo", contAfuera);
	
}

void intervalo(float limIzq, float limDer, int cantPuntos){
	
		float punto = 0;	

		for(int i = 0 ; i < cantPuntos ; i++){
		
		printf("\n\nIngrese el punto en un intervalo, "); scanf("%f", &punto);
		
		if((punto > limIzq) && (punto <= limDer)){
			printf("El punto encontrado en el intervalo (%.2f, %.2f] se encuentra adentro", punto, limIzq, limDer);
			contAdentro++;
		}else{
			contAfuera++;
			printf("El punto encontrado en el intervalo (%.2f, %.2f] se encuentra afuera", punto, limIzq, limDer);
			
		}
	}
	
}
