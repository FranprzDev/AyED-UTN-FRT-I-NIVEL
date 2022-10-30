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

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct fechaDeNac{
    int dia;
    int mes; 
    int anio;
};

struct datosPacientes{
    int cod;
    char apellido[30];
    char nombre[40];
    fechaDeNac fecha;
    char res;
};

void cargarStruct(datosPacientes datos[30], int n);
int buscarPacientesMayoresDe60(datosPacientes datos[30], int n);
float procentajePacientesPositivos(datosPacientes datos[30], int n);

main(){

    datosPacientes datos[30];
    int n = 0;
    int cantidadPacientes = 0;
    printf("Ingrese n: "); scanf("%d", &n);

    cargarStruct(datos, n);
    system("cls");
    
    cantidadPacientes = 0;
    cantidadPacientes = buscarPacientesMayoresDe60(datos, n);

    printf("\nHay un total de: %d mayores a 60 anios.", cantidadPacientes);

    float porc = 0.0;

    porc = procentajePacientesPositivos(datos, n);

    printf("\nHay un total de %.2f%% de porcentaje de pacientes con COVID-19", porc);


}

void cargarStruct(datosPacientes datos[30], int n){
    system("cls");
    for(int i = 0; i < n; i++){
        _flushall();
        printf("Ingrese el codigo del paciente: "); 
        scanf("%d", &datos[i].cod);
        _flushall();
        printf("\nIngrese el apellido: "); 
        gets(datos[i].apellido);
        _flushall();
        printf("\nIngrese el nombre: ");
        gets(datos[i].nombre);
        _flushall();
        printf("\nIngrese el resultado del test: "); 
        scanf("%c", &datos[i].res);
        _flushall();
        printf("\n\n--- Fecha de Nacimeinto ---");
        printf("\nIngrese dia de nacimiento: "); 
        scanf("%d", &datos[i].fecha.dia);
        _flushall();
        printf("\nIngrese mes de nacimiento: "); 
        scanf("%d", &datos[i].fecha.mes);
        _flushall();
        printf("\nIngrese anio de nacimiento: "); 
        scanf("%d", &datos[i].fecha.anio);
        _flushall();
        
        system("cls");
    }

    system("cls");
}

int buscarPacientesMayoresDe60(datosPacientes datos[30], int n){
    int contador = 0;
    int anios = 0;
    for(int i = 0; i < n; i++){
        anios = 2022 - datos[i].fecha.anio;
        if(anios > 60){
            contador++;
        }
    }

    return contador;
}


float procentajePacientesPositivos(datosPacientes datos[30], int n){
    float porcentaje = 0.0;
    int contador = 0;
    
    for(int i = 0; i < n; i++){
        if(datos[i].res == 'P') contador++;
    }
    
	porcentaje = (float) (contador*100) / n;
    
    return porcentaje;
}
