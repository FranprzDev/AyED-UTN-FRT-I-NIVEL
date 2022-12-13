/*

Ingrese los datos referidos al “Inventario” de los libros de una librería en 
un vector de orden N. 
Los campos de la estructura almacenarán la siguiente información: 
Título del libro, autor, código Libro, Fecha de publicación, precio,
 cantidad en existencia y cantidad vendida. Se pide: 

a) Mostrar los nombres de los libros que no tienen stock. 
c) Ingresar una fecha determinada de publicación, Calcular y mostrar la cantidad 
vendida de libros mediante una función con tipo. 


*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct fecha{
    int dia;
    int mes;
    int anio;
};

struct lib{
    char titulo[30];
    char autor[30];
    int codigo;
    fecha fechaPub;
    float precio;
    int cantidadExist;
    int cantidadVendida;
};

void cargarRegistro(lib libreria[30], int n);
void mostrarLibrosSinStock(lib libreria[30], int n);
int cantidadLibrosVendidos(lib libreria[30], int n, int dia, int mes, int anio, int &cantidadLibros);


main(){
    lib libreria[30];
    int n = 0;
    int cantidadLibros = 0;
    int existencia = 0;

    printf("Ingrese n: ");
    scanf("%d", &n);
    cargarRegistro(libreria, n);

    // punto a: mostrar los libros sin stock:

    system("cls");

    mostrarLibrosSinStock(libreria, n);


    printf("\n\n");
    system("pause");
    system("cls");

    int dia = 0, mes = 0, anio = 0;

    printf("Ingrese el dia: ");
    scanf("%d", &dia);
    printf("Ingrese el mes: ");
    scanf("%d", &mes);
    printf("Ingrese el anio: ");
    scanf("%d", &anio);

    existencia = cantidadLibrosVendidos(libreria, n, dia, mes, anio, cantidadLibros);

    if(existencia == -1){
        printf("\nNo se encontro el libro...");
        system("pause");
    }else{
        printf("Se encotro el libro y tiene un total de %d libros vendidos", cantidadLibros);
    }

}

void cargarRegistro(lib libreria[30], int n){
    
    // funcion de carga de registro
    system("cls");

    for(int i = 0; i < n; i++){
    	_flushall();
        printf("Ingrese el titulo: ");
        gets(libreria[i].titulo);
        _flushall();
        printf("\nIngrese el autor: ");
        gets(libreria[i].autor);
        printf("\nIngrese el codigo: ");
        scanf("%d", &libreria[i].codigo);
        printf("\nIngrese el precio: ");
        scanf("%f", &libreria[i].precio);
        printf("\nIngrese la cantidad en existencia: ");
        scanf("%d", &libreria[i].cantidadExist);
        printf("\nIngrese la cantidad vendida: ");
        scanf("%d", &libreria[i].cantidadVendida);
        // ingreso del mes:

        printf("\nIngrese el dia de la fecha de publicacion: ");
        scanf("%d", &libreria[i].fechaPub.dia);
        printf("\nIngrese el mes de la fecha de publicacion: ");
        scanf("%d", &libreria[i].fechaPub.mes);
        printf("\nIngrese el anio de la fecha de publicacion: ");
        scanf("%d", &libreria[i].fechaPub.anio);
    }

}

void mostrarLibrosSinStock(lib libreria[30], int n){
    system("cls");

    for(int i = 0; i < n; i++){
        if(libreria[i].cantidadExist == 0){
            printf("\nEl libro guardado en %d llamado %s no tiene stock. \n", i, libreria[i].titulo);
        }
    }
}

int cantidadLibrosVendidos(lib libreria[30], int n, int dia, int mes, int anio, int &cantidadLibros){
    
    int existencia = 0;
	
	for(int i = 0; i < n; i++){
	    if(libreria[i].fechaPub.dia == dia &&  libreria[i].fechaPub.mes == mes && libreria[i].fechaPub.anio == anio){
	        cantidadLibros = libreria[i].cantidadVendida;
	        existencia = 1;
	        i = n;
	    }else{
	        existencia = -1;
	    }	
	}


    return existencia;
}