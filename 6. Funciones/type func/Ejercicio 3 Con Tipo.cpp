/*
Se ingresa un valor superior a 600, que representa una cantidad en minutos
realizar una función con tipo para mostrar en la función main.
I)Su equivalente en horas.
II) Su equivalente en minutos.
III) Su equivalente en segundo
*/

#include<stdio.h>
#include<stdlib.h>

// float calculoHs(int valorMins);
// float calculoSg(int valorMins);
float dobleCalculo(int valorMins, int codigo);

main(){
	int valorMins = 0;
	printf("Ingrese un valor superior a 600 "); scanf("%d", &valorMins);
	
	if(valorMins > 600){
		
//		float Horas = calculoHs(valorMins);
//		float Segundos = calculoSg(valorMins);
		float Horas = dobleCalculo(valorMins, 1);
		float Segundos = dobleCalculo(valorMins, 2);
		printf("\nSu equivalente en:");
		printf("\n- Horas < - > %2.f (hs)\n", Horas);
		printf("- Minutos < - > %d (min)\n", valorMins);
		printf("- Segundos < - > %2.f (seg)\n", Segundos);
	}else{
		printf("Ingreso un valor menor a 600 minutos");
	}

}

float dobleCalculo(int valorMins, int codigo){
	if(codigo == 1){
		float Hs = valorMins/60;
		return Hs;
	}else if(codigo == 2){
		float Sg = valorMins*60;
		return Sg;
	}
}

/* float calculoHs(int valorMins){
	float Hs = valorMins/60;
	return Hs;
}

float calculoSg(int valorMins){
	float Sg = valorMins*60;
	return Sg;
} */
