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


--- Registro Simple Jerarquizado ---
Una concesionaria de autos registra el día sábado las ventas realizadas en la semana. El registro tiene la siguiente estructura jerarquizada:
struct fecha{
int dia;
int mes;
int anio;
};
struct datosCliente{
char ApeNom[40]; //apellido y nombre del cliente
char dire[60]; //domicilio particular del cliente
float monVehi; //Monto del vehículo.
fecha fecVenta; //Fecha de venta del vehículo.

se pide:
a) Ingresar las N ventas realizadas en la semana.
b) A medida que se registran las ventas, por medio de una función, determinar en qué fecha se vendió menos.
c) Haciendo uso de una función a medida que se ingresa los datos de un cliente mostrar en pantalla los datos ingresados.

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct fecha{
    int dia;
    int mes;
    int anio;
};

struct datosCliente{
    char ApeNom[40]; //apellido y nombre del cliente
    char dire[60]; //domicilio particular del cliente
    float monVehi; //Monto del vehículo.
    fecha fecVenta; //Fecha de venta del vehículo.
};

void cargarDatosEnStruct(datosCliente datos[30], int &n, int &guardIndex);
void mostrarDatosDelStruct(datosCliente datos[30],  int n);
//int comparacion(datosCliente datos, int n, int index);

main(){

    int guardInd = 0;
    int n = 0;
    // Solo hay disponible 30 posiciones.
    
    datosCliente datos[30];

    printf("Ingrese la cantidad de ventas de la semana: "); 
    scanf("%d", &n);

    cargarDatosEnStruct(datos, n, guardInd);
    mostrarDatosDelStruct(datos, n);
    system("pause");
    
    printf("La fecha en la que se vendio menos es en (d/m/a): %d/%d/%d", datos[guardInd].fecVenta.dia, datos[guardInd].fecVenta.mes, datos[guardInd].fecVenta.anio);

}

void cargarDatosEnStruct(datosCliente datos[30], int &n, int &guardIndex){
    system("cls");
    float monto = 0.0;
	float montominimo = 0.0;
    for(int i = 0; i < n; i++) {
        printf("--- Cliente %d ---\n", i);
    	_flushall();
        printf("Ingrese el Apellido y Nombre del cliente: ");
        gets(datos[i].ApeNom);
        _flushall();
		printf("\nIngrese el domicilio del cliente: ");
        gets(datos[i].dire);
        _flushall();
		printf("\nIngrese el monto del vehiculo: ");
        scanf("%f", &monto);
        if(i  == 0) montominimo = monto;
        if(montominimo > monto){
        	montominimo = monto;
        	guardIndex = i;
		}
		datos[i].monVehi = monto;
        _flushall();
		printf("\nIngrese el dia de venta del vehiculo: ");
		scanf("%d", &datos[i].fecVenta.dia);
		_flushall();
        printf("\nIngrese el mes de venta del vehiculo: ");
        scanf("%d", &datos[i].fecVenta.mes);
        _flushall();
        printf("\nIngrese el anio de venta del vehiculo: ");
        scanf("%d", &datos[i].fecVenta.anio);
		_flushall();
		system("cls");
    }
}

void mostrarDatosDelStruct(datosCliente datos[30], int n){
    system("cls");
    for(int i = 0; i < n; i++) {
        printf("--- Cliente %d ---\n", i);
        printf("\nApellido y nombre: "); puts(datos[i].ApeNom);
        printf("\nDireccion del cliente: "); puts(datos[i].dire);
        printf("\nMonto del vehiculo: %.2f", datos[i].monVehi);
        printf("\nDia de venta: %d", datos[i].fecVenta.dia);
        printf("\nMes de venta: %d", datos[i].fecVenta.mes);
        printf("\nAnio de venta: %d\n\n", datos[i].fecVenta.anio);
    }
}
