/*

Un negocio tiene una lista los apellidos y nombres de sus socios. Se le pide realizar un programa, que
por medio de un menú de opciones se pueda realizar lo siguiente:
a. Usando una función, Ingrese los datos de sus socios.
b. Usando una función, Ordenar en el mismo vector los datos en forma decreciente.
c. Usar una función, para mostrar en pantalla la lista de personas.
d. En otro vector ordenar los apellidos en forma creciente (“A” a la “Z”). Mostrar los datos

	Francisco Miguel Perez - 44190234
		Legajo Nº 56355
		DNI: 44190234
		UTN - FRT

*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef char cadena[30];
cadena vectorSocios[50];

void menu(int n);
void ingresarDatos(cadena vectorSocios[50], int n);
void ordenarVectorDescendente(cadena vectorSocios[50], int &n);
void ordenarVectorAscedente(cadena vectorSocios[50], int &n);
void mostrarPorPantalla(cadena vectorSocios[50], int n);

main(){
    int n = 0;
    printf("Ingrese la cantidad de socios que quiere cargar: ");
    scanf("%d", &n);

    menu(n);
}

// -- Seción de menú -- 
void menu(int n){
    int opc = 0;
    do{
        printf("--- Menu ---\n");
        printf("1. Ingrese los datos de los socios. \n");
        printf("2. Ordenar el vector de forma decreciente. \n");
        printf("3. Ordenar los apellidos de forma creciente.\n");
        printf("4. Mostrar por pantalla las personas\n");
        printf("\n");
        printf("Su opcion es: "); 
		scanf("%d", &opc);
		system("CLS");
		
        switch(opc){
            case 1:
               ingresarDatos(vectorSocios, n); 
               
                break;
            case 2:
                ordenarVectorDescendente(vectorSocios, n);
				mostrarPorPantalla(vectorSocios, n);
                break;
            case 3:
                ordenarVectorAscedente(vectorSocios, n);
				mostrarPorPantalla(vectorSocios, n);
                break;
            case 4:
                mostrarPorPantalla(vectorSocios, n);
                break;
            default:
                printf("Opcion incorrecta, saliendo...");
        }
    }while(opc >= 1 && opc <= 4);
}

// -- Seción "A" realizada --
void ingresarDatos(cadena vectorSocios[50], int n){
    for(int i = 0; i <= n; i++){
        gets(vectorSocios[i]);
    }
}

// -- Seción "B" realizada --
// Uso de strcmp(cadena1, cadena2) 
// --> 0 si son iguales, 1 si la primera es mayor -1 si la segunda es may

// creciente: de menor a mayor
// decreciente: de mayor a menor

void ordenarVectorAscedente(cadena vector[50], int &n){
    int b;
	char aux[50];
    
    do{
        b = 0;
        for(int i = 0; i < n; i++){
            if(strcmp(vector[i], vector[i+1]) > 0){
                strcpy(aux, vector[i]);
                strcpy(vector[i], vector[i+1]);
                strcpy(vector[i+1], aux);
                b++;
            }
        }
    }while(b);

}

void ordenarVectorDescendente(cadena vector[50], int &n){
    int b;
	char aux[50];
    
    do{
        b = 0;
        for(int i = 0; i < n; i++){
            if(strcmp(vector[i], vector[i+1]) < 0){
                strcpy(aux, vector[i]);
                strcpy(vector[i], vector[i+1]);
                strcpy(vector[i+1], aux);
                b++;
            }
        }
    }while(b);

}


// -- Seción "D" realizada --

void mostrarPorPantalla(cadena vectorSocios[50], int n){
	printf("Los socios son (%d socios registrados): \n", n);
	for(int i = 0; i <= n; i++){
		puts(vectorSocios[i]);	
	} 
	
	printf("\n");
	system("pause");
	system("cls");
}
