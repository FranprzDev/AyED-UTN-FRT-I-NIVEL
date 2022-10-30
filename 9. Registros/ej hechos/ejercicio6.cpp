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

Una empresa dedicada a la fabricación de casas y edificios en registro que contienen la siguiente información 
de la documentación presentada.
• Número de expediente (alfanumérico).
• Nombre propietario.
• Cantidad de metros cuadrados construidos.
• Tipo de obra (0: vivienda básica, 1: vivienda de Lujo, 2: Edificio, 3: predio especial).
• Fecha Registración, de adelanto de obra por un periodo de 12 meses.
• Monto monetario, recibido de adelanto de obra por un periodo de 12 meses.

a) Registrar los datos solicitados al menos de 5 registros, si colocar la fecha y los montos de adelanto de obra.
b) Registrar por medio de una función el monto recibido. La función debe recibir por parámetro: Número de expediente,
 fecha del adelanto y cantidad de dinero recibido.
c) Listar por pantalla los montos recibido un determinado expediente.

*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct fechaReg{
    int dia;
    int mes;
    int anio;
};

struct info{
    char numExp[30];
    char nombre[30];
    float mxmConsturidos;
    int tipoObra;
    fechaReg fecha;
    float montoMonetario;
};

void cargarInformacion(info informac[30], int n);
int buscarExpediente(info informac[30], int n, int &indiceEncontrado, char numeroExp[30]);
void cargarFechaYMonto(info informac[30], int indiceEncontrado, int dia, int mes, int anio, float monto);

main(){
    info informacion[30];
    char numeroExpediente[30];
    int indiceEncontrado;
    int comparacion;
    int n =0;

    int dia, mes, anio;
    float monto;
	
	do{
	    printf("Ingrese la cantidad n: ");
	    scanf("%d", &n);
		printf("\n");	
	}while(n < 5);

    cargarInformacion(informacion, n);

    
    printf("\nIngrese un Numero de Expediente: ");
    _flushall();
    gets(numeroExpediente);
    
    comparacion = buscarExpediente(informacion, n, indiceEncontrado, numeroExpediente);

    if(comparacion == 1){
        printf("\nIngrese la fecha de adelanto (dia): ");
        scanf("%d", &dia);
        printf("\nIngrese la fecha de adelanto (mes): ");
        scanf("%d", &mes);
        printf("\nIngrese la fecha de adelanto (anio): ");
        scanf("%d", &anio);
        
        printf("\nIngrese el monto: ");
        scanf("%f", &monto);

        cargarFechaYMonto(informacion, indiceEncontrado, dia, mes, anio, monto);
    }else{
        system("cls");
        printf("\nNo se encontro el expediente..");
    }

    printf("\n\n");
    system("pause");
    system("cls");
    printf("Ingrese un expediente para listar: ");
    _flushall();
    gets(numeroExpediente);

    comparacion = buscarExpediente(informacion, n, indiceEncontrado, numeroExpediente);

    if(comparacion == 1){
        system("cls");

        printf("Expediente: %s", informacion[indiceEncontrado].numExp);
        printf("\nPropietario: %s", informacion[indiceEncontrado].nombre);
        printf("\nTipo de obra: %d", informacion[indiceEncontrado].tipoObra);

        printf("\n\n Fecha  (dia/mes/anio)   |    Monto");
        printf("\n%3d %3d %3d              | %10.2f", informacion[indiceEncontrado].fecha.dia, informacion[indiceEncontrado].fecha.mes, informacion[indiceEncontrado].fecha.anio, informacion[indiceEncontrado].montoMonetario);
    }



}

void cargarInformacion(info informac[30], int n){
    for(int i=0; i<n; i++){
        printf("\nIngrese el numero de expediente: ");
        _flushall();
        gets(informac[i].numExp);
        printf("\nIngrese el nombre del cliente: ");
        _flushall();
        gets(informac[i].nombre);
        printf("\nIngrese los metros cuadrados construidos: ");
        scanf("%f", &informac[i].mxmConsturidos);
        printf("\nIngrese el tipo de obra: ");
        scanf("%d", &informac[i].tipoObra);

    }
}

int buscarExpediente(info info[30], int n, int &indiceEncontrado, char numeroExp[30]){
    int comparacion = 0;
    for(int i = 0; i < n; i++){
        if(strcmp(info[i].numExp, numeroExp) == 0){
            indiceEncontrado = i;
            i = n;
            comparacion = 1;
        }
    }

    return comparacion;
}

void cargarFechaYMonto(info informac[30], int indiceEncontrado, int dia, int mes, int anio, float monto){
    informac[indiceEncontrado].montoMonetario = monto;
    informac[indiceEncontrado].fecha.anio = anio;
    informac[indiceEncontrado].fecha.mes = mes;
    informac[indiceEncontrado].fecha.dia = dia;
}
