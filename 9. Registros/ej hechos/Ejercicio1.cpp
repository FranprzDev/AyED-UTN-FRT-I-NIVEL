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

En un negocio que se dedica a la venta de insumos eléctricos tiene la información de sus clientes 
en la siguiente estructura.
struct datosCliente{
int codCli; //código del cliente
char ApeNom[40]; //apellido y nombre
char dire[60]; //domicilio particular
float monCred; //Monto máximo del crédito que puede realizar en cada compra.
};

Se pide:

• Ingresar el dato de N clientes.
• A medida que se van ingresando los clientes, usando una función
  mostrar los datos registrados.
• Al finalizar la carga de los N clientes, mostrar cuantos clientes 
  tienen un monto de crédito  superior a $ 30.000.

*/

#include <stdio.h>
#include <string.h>
#include<stdlib.h>



struct datosCliente{
	int codCli; //código del cliente
	char ApeNom[40]; //apellido y nombre
	char dire[60]; //domicilio particular
	float monCred; //Monto máximo del crédito que puede realizar en cada compra.
};


const int max = 100;

void cargarDatosEnStruct(datosCliente vectorClientes[100], int n);
void mostrarDatosDelStruct(datosCliente vectorClientes[100], int n);
int montoDeCreditoSupA30k(datosCliente vectorClientes[100], int n);

main(){
    datosCliente vectorClientes[max];
    int n = 0;
    printf("Ingrese la cantidad de clientes: ");
    scanf("%d",&n);

    cargarDatosEnStruct(vectorClientes, n);

    mostrarDatosDelStruct(vectorClientes, n);

    int cantidadSup = montoDeCreditoSupA30k(vectorClientes, n);

    printf("\nHay un total de %d clientes que tienen un monto superior a $30000.", cantidadSup);

}

void cargarDatosEnStruct(datosCliente vectorClientes[100], int n){
    system("cls");
    int cod, montomax = 0;
    for (int i = 0; i < n; i++){
        printf("\nIngrese el codigo del cliente: ");
        scanf("%d", &vectorClientes[i].codCli); _flushall();

        printf("\nIngrese el Apellido y Nombre del cliente: ");
        gets(vectorClientes[i].ApeNom); _flushall();
        
        printf("\nIngrese la direccion del cliente: ");
        gets(vectorClientes[i].dire); _flushall();

        printf("\nIngrese el monto maximo de crédito que puede tener: ");
        scanf("%f", &vectorClientes[i].monCred); _flushall();
    }
}

void mostrarDatosDelStruct(datosCliente vectorClientes[max], int n){
    system("CLS");
    printf("--- Clientes ---\n\n");
    for(int i = 0; i < n; i++){
        printf("Codigo del Cliente: %d", vectorClientes[i].codCli);
        printf("\nApellido y Nombre: %s", vectorClientes[i].ApeNom);
        printf("\nDireccion del cliente: %s", vectorClientes[i].dire);
        printf("\nMonto máximo de crédito: %.2f", vectorClientes[i].monCred);
        
        printf("\n\n");
    }

    printf("\n\n");

    system("PAUSE");
}

int montoDeCreditoSupA30k(datosCliente vectorClientes[100], int n){
    int contador = 0;

    for(int i = 0; i < n; i++){
        if(vectorClientes[i].monCred > 30000) contador++;
    }

    return contador;
}
