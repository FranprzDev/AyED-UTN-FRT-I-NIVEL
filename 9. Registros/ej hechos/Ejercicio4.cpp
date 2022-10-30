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


En un colegio secundario los datos de los alumnos están en un registro que contiene los siguientes miembros
(campos):
• Nro. de Documento.
• Apellido y nombre.
• Fecha Nacimiento. (es un registro de 3 campos: día, mes, año. Año tiene 4 dígitos)
• Notas Trimestrales (es un registro de 4 campos: Primer Trimestre, Segundo Trimestre, Tercer Trimestre y promedio
anual)

Se pide:
a) Definir de manera apropiada cada uno de los registros y vincular de manera de crear registro de jerarquía.
b) Realizar la carga de N alumnos. Teniendo en cuenta que el campo promedio anual, no se pide su ingreso, se
calcula de los tres trimestres que tiene el alumno.
c) Al final de la carga mostrar el promedio del curso

*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct fechaDeNac{
    int dia;
    int mes;
    int anio;
};

struct notasTrimestrales{
    float primerTrim;
    float segundoTrim;
    float tercerTrim;
    float promedio;
};

struct alumno{
    int numDocumento;
    char ApyNom[50];
    fechaDeNac fechaPers;
    notasTrimestrales notasPers;
};

void cargarDatos(alumno vectAlumnos[30], int n);
float promedioDelCurso(alumno vectAlumnos[30], int n);

main(){
    alumno vectAlumnos[30];
    int n = 0;
    printf("Ingrese la cantidad de alumnos: ");
    scanf("%d", &n);

    cargarDatos(vectAlumnos, n);
    
    float promedioDelC = 0;

    promedioDelC = (float) promedioDelCurso(vectAlumnos, n);

    printf("\nEl promedio del curso es de: %.2f \n\n", promedioDelC);

    system("pause");

}

void cargarDatos(alumno vectAlumnos[30], int n){
    system("cls");
    int anio = 0;
	int n1, n2, n3;
    for(int i = 0; i < n; i++){
        printf("\nIngrese el Nro de Doc: ");
        scanf("%d", &vectAlumnos[i].numDocumento);
        _flushall();
        printf("\nIngrese Apellido y nombre: ");
		gets(vectAlumnos[i].ApyNom);
		_flushall();
        printf("\nIngrese el dia de nacimiento: ");
        scanf("%d", &vectAlumnos[i].fechaPers.dia);
        _flushall();
        printf("\nIngrese el mes de nacimiento: ");
        scanf("%d", &vectAlumnos[i].fechaPers.mes);
        _flushall();
        printf("\nIngrese el anio de nacimiento: ");
        scanf("%d", &anio);
        _flushall();

        while(anio < 0 && anio >= 10000){
            printf("\nIngrese el anio de nacimiento: ");
            scanf("%d", &anio);  
        }

        if(anio >= 0 && anio < 10000){
            vectAlumnos[i].fechaPers.anio = anio;
        }

        printf("\n\n-- Carga de Notas --");

        printf("\nIngrese la nota 1: "); 
        _flushall();
        scanf("%f", &vectAlumnos[i].notasPers.primerTrim);
        printf("\nIngrese la nota 2: "); 
        _flushall();
        scanf("%f", &vectAlumnos[i].notasPers.segundoTrim);
        printf("\nIngrese la nota 3: "); 
        _flushall();
        scanf("%f", &vectAlumnos[i].notasPers.tercerTrim);

		n1 = vectAlumnos[i].notasPers.primerTrim;
		n2 = vectAlumnos[i].notasPers.segundoTrim;
		n3 = vectAlumnos[i].notasPers.tercerTrim;
        vectAlumnos[i].notasPers.promedio = (n1+n2+n3)/3;

        }
        
}

float promedioDelCurso(alumno vectAlumnos[30], int n){
    float acumulador = 0;
    for(int i=0; i<n; i++){
        acumulador += vectAlumnos[i].notasPers.promedio;
    }

    float promedioDelCurso = 0; 
    promedioDelCurso = acumulador / n;

    return promedioDelCurso;
}
