/*

En un colegio secundario los datos de los alumnos están en un registro que contiene los siguientes miembros
(campos):
• Nro. de Documento.
• Apellido y nombre.
• Fecha Nacimiento. (es un registro de 3 campos: día, mes, año. Año tiene 4 dígitos)
• Notas Trimestrales (es un registro de 4 campos: Primer Trimestre, Segundo Trimestre, Tercer Trimestre y promedio
anual)
:
a) Definir de manera apropiada cada uno de los registros y vincular de manera de crear registro de jerarquía.
b) Realizar la carga de N alumnos. Teniendo en cuenta que el campo promedio anual, no se pide su ingreso, se
calcula de los tres trimestres que tiene el alumno.
c) Al final de la carga mostrar el promedio del curso.

*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct fechaNac{
  int dia;
  int mes;
  int anio;
};

struct notas{
    float primerTrim;
    float segundoTrim;
    float tercerTrim;
    float promAnual;
};


struct reg{
  
  int dni;
  char apynom[30];
  fechaNac fecha;
  notas notasAnuales;

};

void cargarAlumnos(reg alumnos[30], int n);
int verificarDia(int dia);
int verificarMes(int mes);
int verificarAnio(int anio);
int verificarNota(float nota);
float calcularPromedio(float notaPrim, float notaSeg, float notaTer);
float promedioCurso(reg alumnos[30], int n);


main(){
    reg alumnos[30];

    int n = 0;
    float promedio = 0.0;

    printf("Ingrese n: ");
    scanf("%d", &n);

    cargarAlumnos(alumnos, n);

    promedio = promedioCurso(alumnos, n);

    printf("\n\n");
    system("pause");
    system("cls");
    printf("\n\n");
    printf("Promedio del curso: %.2f", promedio);

}

int verificarDia(int dia){
    int condVerificacion = 0;
    if(dia >= 1 && dia <= 31){
        condVerificacion++;
    }

    return condVerificacion;
}

int verificarMes(int mes){
    int condVerificacion = 0;

    if(mes >= 1  && mes <= 12){
        condVerificacion++;
    }

    return condVerificacion;
}

int verificarAnio(int anio){
    int condVerificacion = 0;

    if(anio >= 1950 && anio <= 2022){
        condVerificacion++;
    }

    return condVerificacion;
}  

int verificarNota(float nota){
    int verificacion = 0;
    if(nota >= 1 && nota <= 10){
        verificacion++;
    }
    return verificacion;
}

float calcularPromedio(float notaPrim, float notaSeg, float notaTer){
    float promedio = 0;

    promedio = (float) (notaPrim + notaSeg + notaTer) / 3;

    return promedio;
}


void cargarAlumnos(reg alumnos[30], int n){
    int diaTemp = 0;
    int mesTemp = 0;
    int anioTemp = 0;
    int bandera = 0;
    int temporalNota = 0;

    system("cls");
    for(int i = 0; i < n; i++){
        system("cls");
        printf("DNI: ");
        scanf("%d", &alumnos[i].dni);
        _flushall();
        printf("\nApellido y Nombre: ");
        gets(alumnos[i].apynom);
        _flushall();

        printf("\n--- Fecha ---");
        do{
            printf("\nDia: ");
            scanf("%d", &diaTemp);

            bandera = verificarDia(diaTemp);
        }while(bandera != 1);

        alumnos[i].fecha.dia = diaTemp;
    
        do{
            printf("\nMes: ");
            scanf("%d", &mesTemp);
            
            bandera = verificarMes(mesTemp);
        }while(bandera != 1);

        alumnos[i].fecha.mes = mesTemp;

        do{
            printf("Anio: ");
            scanf("%d", &anioTemp);

            bandera = verificarAnio(anioTemp);

        }while(bandera != 1);

        alumnos[i].fecha.anio = anioTemp;
        
        printf("\n\n");

        printf("--- Notas del Alumno %d ---", i);

        do{
            printf("\nIngrese la nota del 1 trimestre: ");
            scanf("%d", &temporalNota);

            bandera = verificarNota(temporalNota);
        }while(bandera != 1);

        alumnos[i].notasAnuales.primerTrim = temporalNota;
        temporalNota = 0;

        do{
            printf("\nIngrese la nota del 2 trimestre: ");
            scanf("%d", &temporalNota);

            bandera = verificarNota(temporalNota);
        }while(bandera != 1);

        alumnos[i].notasAnuales.segundoTrim = temporalNota;
        temporalNota = 0;

        do{
            printf("\nIngrese la nota del 3 trimestre: ");
            scanf("%d", &temporalNota);

            bandera = verificarNota(temporalNota);
        }while(bandera != 1);

        alumnos[i].notasAnuales.tercerTrim = temporalNota;

        alumnos[i].notasAnuales.promAnual = calcularPromedio(alumnos[i].notasAnuales.primerTrim, 
            alumnos[i].notasAnuales.segundoTrim, alumnos[i].notasAnuales.tercerTrim);

    }
}

float promedioCurso(reg alumnos[30], int n){
    float acumulador = 0.0;
    float promedio = 0.0;


    for(int i = 0; i < n; i++){
        acumulador += alumnos[i].notasAnuales.promAnual;
    }

    promedio = acumulador / n;

    return promedio;
}