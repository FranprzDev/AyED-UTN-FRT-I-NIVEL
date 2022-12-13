/*
Crear un archivo de texto en donde se guardaran los siguientes de N estudiante, cada dato (campo)
que se almacenan en el archivo son los siguientes
Nombre.
Apellidos.
Carrera que estudia.
Nota promedio.
1) Realizar la carga de los N estudiantes, 
tenga en cuenta que cada uno de los datos estará separado por un punto y como “;” y
los datos de cada estudiante debe ocupar una línea en el archivo.
2) Realizar el listado de los datos guardados.
3) Contar la cantidad de apellidos iguales que tiene el archivo.
4) Contar cuantos estudiantes cursan la misma carrera.
5) Ingresar el apellido y nombre de un estudiante y mostrar la carrera que estudia y su nota
promedio. Tenga en cuenta que los datos se pueden ingresar de diferente forma ej: todo en
mayúscula, minúscula, alguna mayúscula.

*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef char linea[350];

void cargarArchivo(FILE *arch);
void listarDatos(FILE *arch);
int cantidadApellidosIguales(FILE *arch);

main(){
    FILE *arch;
    arch = fopen("datos.txt", "a+");
    int n = 0;
    int apIguales = 0;


    printf("Ingrese la cantidad a cargar: ");

    scanf("%d", &n);

    for(int i = 0; i < n; i++){
        contador++;
        cargarArchivo(arch);
    }

    printf("\n");

    listarDatos(arch);



}

void cargarArchivo(FILE *arch){

    char nombre[50];
    char apellido[50];
    char carrera[50];
    char notaProm[50];
    linea line;
    char separador[5] = " ; ";
    char sep[3] = " ";

    printf("\n\nIngrese el nombre: ");
    _flushall();
    gets(nombre);
    strcat(line, nombre);
    strcat(line, separador);
    printf("\nIngrese el apellido: ");
    _flushall();
    gets(apellido);
    strcat(line, apellido);
    strcat(line, separador);
    printf("\nIngrese la carrera: ");
    _flushall();
    gets(carrera);
    strcat(line, carrera);
    strcat(line, separador);
    printf("\nIngrese la nota promedio: ");
    _flushall();
    gets(notaProm);
    strcat(line, notaProm);
    strcat(line, sep);

    _flushall();

    fprintf(arch, strcat(line, " \n")); 
}

void listarDatos(FILE *arch){
    rewind(arch);
    linea lineaTotal;

    printf("\n\nDatos: ");
    _flushall();
    gets(lineaTotal);

    while(!feof(arch)){
        
        printf("%s", lineaTotal);

        _flushall();

        if(!feof(arch))
        gets(lineaTotal);

    }
}