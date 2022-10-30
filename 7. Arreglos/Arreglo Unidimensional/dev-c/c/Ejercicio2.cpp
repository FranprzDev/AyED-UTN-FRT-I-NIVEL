/*


Francisco Miguel Perez 44190234 - UTN - FRT
 Carga un arreglo de N elementos el cual contiene las notas de un curso. 
a. Realizar la carga de dicho arreglo, usando función sin tipo. Verificar que la nota ingresada 
sea un valor de 1 a 10. En caso de no ser pedir el nuevo el ingreso de dicha nota.
b. Los siguientes datos se mostraran en la función principal main haciendo uso de diferentes 
funciones ya sea con tipo o sin tipo según se especifique.
i. La mayor y menor nota que tenga el arreglo. (Función Sin Tipo). 
ii. Promedio de notas del arreglo. (Función con tipo).
iii. Cantidad de notas superiores al promedio que tenga el arreglo. (Función con tipo).
iv. Cantidad de alumnos aprobados y desaprobados. Se aprueba a partir de 6. (Función sin tipo).

*/

#include<stdio.h>

void cargarArreglo(int arreglo[], int n);
void calcMayAndMen(int arreglo[100], int n, int &mayorValor, int &menorValor);
int promedioDeNotasDelArreglo(int arreglo[100], int n);
int cantidadDeNotasSuperioresAlPromedio(int arreglo[100], int n, float promedio);
int cantidadDeAprobados(int arreglo[100], int n);

main(){
	
	int menorValor = 0, mayorValor = 0;
	int n, arreglo[100];
	printf("Ingrese N: ");
	scanf("%d", &n);
	cargarArreglo(arreglo, n);	
	
	calcMayAndMen(arreglo, n, mayorValor, menorValor);
	
	printf("\n\nEl mayor valor es: %d, ", mayorValor);
	printf("\n\nEl menor valor es: %d, ", menorValor);
	
	
	float promedio = (float) promedioDeNotasDelArreglo(arreglo, n);
	int notasSupProm = cantidadDeNotasSuperioresAlPromedio(arreglo, n, promedio);

	printf("\n\nEl promedio es: %.2f ", promedio);
	printf("\n\nLa cantidad de notas superiores al promedio es de: %d ", notasSupProm);
	
	
	int cantidadAprobados = cantidadDeAprobados(arreglo, n);
	
	printf("\nHay un total de: ");
	printf("\n- %d Alumnos Aprobados ", cantidadAprobados);
	printf("\n- %d Alumnos Desaprobados ", n-cantidadAprobados);
	
	
}

void cargarArreglo(int arreglo[], int n){
	int notas = 1;

	for(int i = 0; i < n; i++){
		printf("Ingrese la nota: "); scanf("%d", &notas);
		if(notas >= 1 && notas <= 10){
			arreglo[i] = notas;
		}else{
			while(notas < 1 && notas > 10){
				printf("\nIngrese otra nota: ");
				scanf("%d", &notas);
			}	
		} 
	}
}


void calcMayAndMen(int arreglo[100], int n, int &mayorValor, int &menorValor){
	
	
	int mayor = arreglo[0];
    for(int i = 0; i < n; i++)
    {
        if(arreglo[i] > mayor)
        {
            mayorValor = arreglo[i];
        }
    }
    
    int menor = arreglo[0];
    for(int i = 0; i < n; i++)
    {
        if(arreglo[i] < mayor)
        {
            menorValor = arreglo[i];
        }
    }
	
}

int promedioDeNotasDelArreglo(int arreglo[100], int n){
	float promedioTotal = 0.0;
	int sumDeTodo = 0;
	
	for(int i = 0; i < n; i++){
		sumDeTodo += arreglo[i];
	}
	
	promedioTotal = (float) sumDeTodo/n;
	
	return promedioTotal;
}


int cantidadDeNotasSuperioresAlPromedio(int arreglo[100], int n, float promedio){
	int contador = 0;
	for(int i = 0; i < n; i++){
		  if(arreglo[i] > promedio){
		  	contador++;
		  }
	}
	
	return contador;
}

int cantidadDeAprobados(int arreglo[100], int n){
	int cantidadAp = 0;
	
	for(int i = 0; i < n; i++){
		if(arreglo[i] > 6){
			cantidadAp++;
		}
	}	
	
	return cantidadAp;
}
