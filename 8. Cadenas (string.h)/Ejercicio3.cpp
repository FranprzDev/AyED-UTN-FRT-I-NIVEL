/*

Ingresar en un vector los nombres las N asignaturas de la carrera Ing. Sistema de Informaci�n, 
paralelamente ingresar en otro vector la cantidad de alumnos inscriptos en este a�o cada asignatura.
SE PIDE:
a. En una funci�n Sin Tipo, realizar la carga de los vectores en forma simult�nea, Asignatura y nro. de inscriptos.
b. Haciendo uso de una funci�n Con Tipo, determinar y mostrar en la funci�n main, que asignatura tiene el mayor
n�mero de inscriptos.
c. Por medio de una funci�n con tipo, mostrar la cantidad de inscrip

	Francisco Miguel Perez - 44190234
		Legajo N� 56355
		DNI: 44190234
		UTN - FRT
		
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef char cadena[50];
cadena vectorAsignatura[30];

void cargaDeVectores(cadena vectorAsignatura[30], int vectorAlumnos[30], int n);
void cargarVectorParalelo(int vectorAlumnos[30], int i);
int mayorNumeroInscriptos(int vectorAlumnos[30], int n);


main(){
    int n = 0;
    int vectorAlumnos[30];
    printf("Ingrese la cantidad de asignaturas a cargar: ");
    scanf("%d",&n);

    cargaDeVectores(vectorAsignatura, vectorAlumnos, n);

    int numInscripMax = 0;
    numInscripMax = mayorNumeroInscriptos(vectorAlumnos, n);

    printf("\n\nEl m�ximo de inscriptos es de %d de la asignatura %s", vectorAlumnos[numInscripMax], vectorAsignatura[numInscripMax]);

}

void cargarVectorParalelo(int vectorAlumnos[100], int i){
    int cantidad = 0;
    printf("\nIngrese la cantidad de alumnos: ");
    scanf("%d", &cantidad);

    vectorAlumnos[i] = cantidad;
    printf("\n");
}

void cargaDeVectores(cadena vectorAsignatura[100], int vectorAlumnos[100], int n){
    for(int i = 0; i < n; i++){
        printf("\nIngrese el nombre de la asignatura %d: ", i+1);
        _flushall();
        gets(vectorAsignatura[i]);
        cargarVectorParalelo(vectorAlumnos, i);

    }
}

int mayorNumeroInscriptos(int vectorAlumnos[100], int n){
    int indice = 0, max = 0, numero = 0;
    for(int i = 0; i < n; i++){
        numero = vectorAlumnos[i];
        if(numero > max){
        max = numero;
        indice = i;
        }
    }
    return indice;
}
