/*

	Ejercicio para probar ordenar un vect 
	
	Francisco Miguel Perez - 44190234
		Legajo Nº 56355
		DNI: 44190234
		UTN - FRT

*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef char cadena[50];
cadena vector[30];

void cargarvector(cadena vector[30], int n);
void ordenarVectorAscedente(cadena vector[30], int n);
void mostrarvector(cadena vector[30], int n);
void ordenarVectorDescendente(cadena vector[30], int n);

main(){
    int n = 0;
    printf("Ingrese cantidad: "); 
    scanf("%d", &n);
    
    cargarvector(vector, n);
    
    ordenarVectorAscedente(vector, n);
    
    mostrarvector(vector, n);
    
    ordenarVectorDescendente(vector, n);
    
    mostrarvector(vector, n);
    
}

void ordenarVectorAscedente(cadena vector[30], int n){
    int b;
	char aux[30];
    
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

void ordenarVectorDescendente(cadena vector[30], int n){
    int b;
	char aux[30];
    
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

void cargarvector(cadena vector[30], int n){
    for(int i = 0; i <= n; i++){
        gets(vector[i]);
    }
}

void mostrarvector(cadena vector[30], int n){
	printf("\n");
    for(int i = 0; i <= n; i++){
        puts(vector[i]);
    }
}
