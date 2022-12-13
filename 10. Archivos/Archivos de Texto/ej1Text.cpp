/*

Una empresa tiene dos empleados los cuales reciben en sus cuentas
de correos diferentes email confrases de una longitud no superior
a 80 caracteres cada frase. Cada cierto número de frases estas deben ser
guardadas en un archivo de texto sin perder lo que se tenía ya guardado
en el archivo.

Se Pide: que por medio de un menú se pueda realizar lo siguiente
a- Al abrir el sistema (programa) se deben crear los archivos “Archivo1.txt” y “Archivo2.txt”
b- Crear y Guardar la/s frase/s recibida por el empleado José Luis en el fichero “Archivo1.txt”. La/s
frase/s son ingresada por teclado.
c- Crear y Guardar las frases recibida por la empleada María Emilia en el fichero “Archivo2.txt”.
La/s frase/s son ingresada por teclado.
d- Al final del día ambos archivos son guardados en un único fichero. 
Deberá combinar ambos archivos mezclados, en un nuevo fichero “Frases.txt”. 
Es decir, una frase del Archivo1.txt y una del Archivo2.txt, otra del archivo1 otra del archivo2 y así sucesivamente.
e- Mostrar las frases del archivo de José Luis en minúscula.
f- Mostrar las frases del archivo de María Emilia en Mayúscula.
g- Mostrar las frases del Archivo combinado. Donde cada palabra deberá comenzar en mayúscula y el
resto de cada palabra en minúscula.
h- Al salir del sistema, Los archivos, Archivo1.txt y Archivo2.txt, creados deberán ser eliminados físicamente.
Nota: Tener en cuenta que para los ítems d, e, f existen funciones que realizan tales operaciones. También
se puede hacer de manera secuencial, analizando cada palabra. Deberán elegir que aplicar. 

*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef char frase[80];

int menu();
void fraseRecibidaPorJoseLui(FILE *archivo1);
void fraseRecibidaPorMariaEmilia(FILE *archivo2);
void combinarArchivos(FILE *archivo1, FILE *archivo2, FILE *combinacion);
void listarCombinacion(FILE *combinacion);
void borrarArchivos(FILE *archivo1, FILE *archivo2, FILE *combinacion);
void mostrarFraseJoseMinusc(FILE *archivo1);
void mostrarFraseMariaMayus(FILE *archivo2);

main(){
    FILE *archivo1; // archivo 1 - para jose luis
    FILE *archivo2; // archivo 2 - para maria emilia
    FILE *combinacion;
    
	combinacion = fopen("combinacion.txt", "a+");
    archivo1 = fopen("Archivo1.txt","a+");
    archivo2 = fopen("Archivo2.txt","a+");

    if(archivo1 == NULL || archivo2 == NULL){
        printf("Se obtuvo un error al generar el archivo...");
    }

    fraseRecibidaPorJoseLui(archivo1);    
	
	printf("\n");
	
	fraseRecibidaPorMariaEmilia(archivo2); 
	
	printf("\n");
	
    archivo1 = fopen("Archivo1.txt","a+");
    archivo2 = fopen("Archivo2.txt","a+");

    rewind(archivo1);
    rewind(archivo2);
    
    mostrarFraseJoseMinusc(archivo1);
    
	printf("\n\n");
    system("pause");
    
    mostrarFraseMariaMayus(archivo2);
    
    printf("\n\n");
    
    system("pause");
    
    combinarArchivos(archivo1,archivo2, combinacion);
    
    combinacion = fopen("combinacion.txt", "a+");
    
    listarCombinacion(combinacion);
    
    printf("\n");
    
    system("pause");
    
    borrarArchivos(archivo1, archivo2, combinacion);
    
    fclose(combinacion);
	remove("combinacion.txt");
}

int menu(){
    int opc;
    system("cls");

    printf("1- Crear y Guardar la/s frase/s recibida por el empleado Jose Luis en el fichero Archivo1.txt\n");
    printf("2- Crear y Guardar las frases recibida por la empleada María Emilia en el fichero Archivo2.txt\n");
    printf("3- Combinar en un unico fichero en frases txt\n");
    printf("4- Mostrar las frases del Archivo de José Luis en minuscula\n");
    printf("5- Mostrar las frases del archivo de María Emilia en Mayúscula\n");
    printf("6- Mostrar las frases del Archivo combinado\n");
    printf("7- Borrar los archivos 1 y 2\n");

    printf("\nSu opcion: ");

    scanf("%d", &opc);
    return opc;

}

void fraseRecibidaPorJoseLui(FILE *archivo1){
	frase frase;
    
	system("cls");
	printf("--- Jose Lui --- \n");

    printf("Ingrese la frase (fin para terminarlo): ");

   	_flushall();
	gets(frase);
	
	while(strcmp(frase,"fin") != 0){
		
		fprintf(archivo1, strcat(frase," \n"));
		
		printf("Ingrese la frase (fin para terminarlo): ");

	   	_flushall();
		gets(frase);

	}
    	
    printf("\n\n");
    system("cls");
    
    fclose(archivo1);
    	
    printf("\n\n");
    system("cls");
}

void fraseRecibidaPorMariaEmilia(FILE *archivo2){
	frase frase;
    
	system("cls");
	printf("\n--- Maria Emilia --- \n");


    printf("Ingrese la frase (fin para terminarlo): ");

   	_flushall();
	gets(frase);
	
	while(strcmp(frase,"fin") != 0){
		
		fprintf(archivo2, strcat(frase," \n"));
		
		printf("Ingrese la frase (fin para terminarlo): ");

	   	_flushall();
		gets(frase);

	}
    
    printf("\n\n");
    system("cls");
    
    fclose(archivo2);
    
    printf("\n\n");
    system("cls");
}

void combinarArchivos(FILE *archivo1, FILE *archivo2, FILE *combinacion){
	
    rewind(archivo1);
    rewind(archivo2);

    // primero combino lo de archivo 1 en combinacion
	frase frase;

	_flushall();
	fgets(frase,80,archivo1);
	
	while(!feof(archivo1)){
		
		fprintf(combinacion,frase);
		fgets(frase,80,archivo1);
	}
	
	// ahora combino con el archivo 2
	
	_flushall();
	fgets(frase, 80, archivo2);
	
	while(!feof(archivo2)){
		fprintf(combinacion,frase);
		
		fgets(frase, 80, archivo2);
		
	}
	
	printf("\nEl archivo fue combinado con exito.");
	fclose(archivo1);
	fclose(archivo2);
	fclose(combinacion);
}

void listarCombinacion(FILE *combinacion) {
	system("cls");
	
	printf("La combinacion es: \n");
	
	frase frase;
	int contador = 0;

    // la combinacion para mostrarlo se lo hace facil, con un contador
    // que incluya en cada una de las cargas la cantidad que se va cargando
    // y despues se muestra uno por uno bajando el contador y yendo combinandolos uno a uno
    // para resolver lo del primer caracter en mayúscula hay que usar el getc de c pero yafue

	fgets(frase, 80, combinacion);
	
	while(!feof(combinacion)){

		printf("%s", frase);
		
		fgets(frase, 80, combinacion);
	}
	
	printf("\n\n----------");
}

void borrarArchivos(FILE *archivo1, FILE *archivo2, FILE *combinacion){
	remove("Archivo1.txt");
	remove("Archivo2.txt");
}

void mostrarFraseJoseMinusc(FILE *archivo1){
    frase frase;
    printf("\n\nFrases en Miniscula de Jose \n");

	rewind(archivo1);

    _flushall();
    fgets(frase, 80, archivo1);

    strlwr(frase);

    while(!feof(archivo1)){
    	
        printf("%s", frase);
        fgets(frase, 80, archivo1);
        strlwr(frase);

    }
}

void mostrarFraseMariaMayus(FILE *archivo2){

    frase frase;
    printf("\n\nFrases en Mayusculas de Maria \n");
    
    rewind(archivo2);

    _flushall();
    fgets(frase, 80, archivo2);

    strupr(frase);

    while(!feof(archivo2)){
        printf("%s ", frase);

        _flushall();
        fgets(frase, 80, archivo2);
        if(!feof(archivo2))

        strupr(frase);
    }
}
