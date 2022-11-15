/*

Un médico registra la información de sus pacientes en una estructura que posee los siguientes campos: 
Nombre 
Edad
Teléfono 
Fecha de la última visita (estructura anidada). 

Se pide: 

a) Ingresar la información en un vector de registros. 
b) Mediante una función con tipo calcule el promedio de edades de los pacientes.. 

*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct fecha{
    int dia;
    int mes;
    int anio;
};

struct pacientes{
    char nya[80];
    int edad;
    int telefono;
    fecha fechaUltimaVisita;
};


void cargarRegistro(pacientes pacientes[30], int n);
float promedioDeLasEdades(pacientes pacientes[30], int n);

main(){
    pacientes pacientes[30];
    int pac = 0;

    float prom = 0;

    printf("Ingrese la cantidad de registros: ");
    scanf("%d", &pac);

    cargarRegistro(pacientes, n);

    prom = (float) promedioDeLasEdades(pacientes, n);

    printf("\n\nEl promedio es: %.2f", prom);
}

void cargarRegistro(pacientes pacientes[30], int n){
    system("cls");

    for(int i = 0; i < n; i++){
        printf("Ingrese el nombre y apellido: ");
        _flushall();
        gets(pacientes[i].nya);
        printf("\nIngrese la edad: ");
        scanf("%d", &pacientes[i].edad);
        printf("\nIngrese el telefono: ");
        scanf("%d", &pacientes[i].telefono);
        printf("\nIngrese el dia de la ultima venta: ");
        scanf("%d", &pacientes[i].fechaUltimaVisita.dia);
        printf("\nIngrese el mes de la ultima venta: ");
        scanf("%d", &pacientes[i].fechaUltimaVisita.mes);
        printf("\nIngrese el anio de la ultima venta: ");
        scanf("%d", &pacientes[i].fechaUltimaVisita.anio);
        printf("\n\n");
        
    }
}

float promedioDeLasEdades(pacientes pacientes[30], int n){
    int sumEdades = 0;
    float promedio = 0;
    for(int i = 0; i < n; i++){
        sumEdades += pacientes[i].edad;
    }

    promedio  = (float) sumEdades / n;

    return promedio;
}