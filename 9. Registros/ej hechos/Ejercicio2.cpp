/*

	---------------- Datos -----------------

	Universidad Tecnológica Nacional
		Facultad Regional de Tucumán
			(UTN - FRT)
			
		Nombre y Apellido: Francisco Miguel Perez
		Legajo Nº: 56355
		DNI Nº: 44190234
		
	Comisión 1K5 - Algoritmos y Estructura de Datos.
	
		Prof. Rafael Montesinos - Teoría
		Prof. Javier Cantó - Práctica.
		
	---------------- Datos -----------------

Las coordenadas de dos puntos en un plano deben guardarse en un registro. 
Hacer un programa con menú de opciones que permita registrar los dos puntos P1 y P2,
representados como registros:

1. Cargar dos puntos por teclado.
2. Mostrar los dos puntos en forma de par ordenado. Ej: P1(x1,y1) ; P2(x2,y2)
3. Calcular la distancia del punto P1 al origen de coordenadas (usar teorema de Pitágoras).
4. Calcular y mostrar en pantalla, la longitud del segmento de recta que une los dos puntos.
d(P1,P2) = sqrt( (x2 – x1)2 + (y2 – y1)2
)

*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

struct parOrdenado{
    int cordAbcisa;
    int cordOrdenada;
};

int menu();
void cargarPuntos(parOrdenado puntos[2], int n);
void mostrarPuntos(parOrdenado puntos[2], int n);
float calcularDistanciaP1(parOrdenado puntos[2], int n);
float calcularDistanciaEntrePuntos(parOrdenado puntos[2], int n);

main(){
    parOrdenado puntos[2];
    int n = 2;
    int opcionPorUsuario = 0;
    float distancia1 = 0.0;
    float distancia2 = 0.0;

    do{
        opcionPorUsuario = menu();

        switch(opcionPorUsuario){
            case 1:
                    system("cls");
                    cargarPuntos(puntos, n);
                break;
            case 2:
                    system("cls");
                    mostrarPuntos(puntos, n);
                break;
            case 3:
            	system("cls");
                distancia1 = calcularDistanciaP1(puntos, n);
                printf("La distancia de (%d, %d) a (0, 0) es: %.2f ", puntos[0].cordAbcisa, puntos[0].cordOrdenada, distancia1);
                printf("\n\n");
				system("pause");
                system("cls");
                break;
            case 4:
                system("cls");
                distancia2 = calcularDistanciaEntrePuntos(puntos, n);
                printf("La distancia entre el punto 1 y 2 es: %.2f ", distancia2);
                printf("\n\n");
                system("pause");
                system("cls");
                break;
            case 5:
                system("cls");
                printf("\n\n");
                printf("Finalizando el programa...");
                system("close");
                break;
        }

    }while(opcionPorUsuario != 5);


}


int menu(){
    int opc;
        printf("--- Menu ---\n");
        printf("1. Cargar dos puntos por teclado. \n");
        printf("2. Mostrar los dos puntos en forma de par ordenado. \n");
        printf("3. Mostrar la distancia hasta el origen de coordenadas. \n");
        printf("4. Mostrar la longitud del segmento de recta que une los dos puntos. \n");
        printf("5. Cerrar programa. \n");

        printf("\nSu opcion es: ");
        scanf("%d", &opc);
   return opc;
}

void cargarPuntos(parOrdenado puntos[100], int n){
    system("cls");
    for(int i = 0; i < n; i++){
        printf("Ingrese el punto de ordenada de %d: ", i+1);
        scanf("%d", &puntos[i].cordAbcisa);
        printf("Ingrese el punto de abcisa de %d: ", i+1);
        scanf("%d", &puntos[i].cordOrdenada);
    }
    printf("\n\n");
    
    system("pause");
    system("cls");
}

void mostrarPuntos(parOrdenado puntos[100], int n){
    system("cls");
    for(int i = 0; i < n; i++){
        printf("El par ordenado %d es: (%d, %d) \n", i+1, puntos[i].cordAbcisa, puntos[i].cordOrdenada);
    }
    printf("\n\n");
    
    system("pause");
    system("cls");
}

float calcularDistanciaP1(parOrdenado puntos[100], int n){
    float distancia = sqrt(puntos->cordAbcisa^2 + puntos->cordOrdenada^2);
    return distancia;
}

// d(P1,P2) = sqrt( (x2 – x1)2 + (y2 – y1)2

float calcularDistanciaEntrePuntos(parOrdenado puntos[2], int n){
	int x1 = puntos[0].cordAbcisa;
	int x2 = puntos[1].cordAbcisa;
	int y1 = puntos[0].cordOrdenada;
	int y2 = puntos[1].cordOrdenada;
	float distanciaEntrePuntos = sqrt(pow((x2-x1), 2) + pow((y2-y1), 2));
    // float distanciaEntrePuntos = sqrt((((puntos[1].cordAbcisa-puntos[0].cordAbcisa)^2) + ((puntos[1].cordOrdenada-puntos[0].cordOrdenada)^2)));

    return distanciaEntrePuntos;   
}
