/*

	---------------- Datos -----------------

	Universidad Tecnol�gica Nacional
		Facultad Regional de Tucum�n
			(UTN - FRT)
			
		Nombre y Apellido: Francisco Miguel Perez
		Legajo N�: 56355
		DNI N�: 44190234
		
	Comisi�n 1K5 - Algoritmos y Estructura de Datos.
	
		Prof. Rafael Montesinos - Teor�a
		Prof. Javier Cant� - Pr�ctica.
		
	---------------- Datos -----------------

En un negocio que se dedica a la venta de insumos el�ctricos tiene la informaci�n de sus clientes 
en la siguiente estructura.
struct datosCliente{
int codCli; //c�digo del cliente
char ApeNom[40]; //apellido y nombre
char dire[60]; //domicilio particular
float monCred; //Monto m�ximo del cr�dito que puede realizar en cada compra.
};

Se pide:

� Ingresar el dato de N clientes.
� A medida que se van ingresando los clientes, usando una funci�n
  mostrar los datos registrados.
� Al finalizar la carga de los N clientes, mostrar cuantos clientes 
  tienen un monto de cr�dito  superior a $ 30.000.

*/

#include <stdio.h>
#include <string.h>
#include<stdlib.h>



struct datosCliente{
	int codCli; //c�digo del cliente
	char ApeNom[40]; //apellido y nombre
	char dire[60]; //domicilio particular
	float monCred; //Monto m�ximo del cr�dito que puede realizar en cada compra.
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

        printf("\nIngrese el monto maximo de cr�dito que puede tener: ");
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
        printf("\nMonto m�ximo de cr�dito: %.2f", vectorClientes[i].monCred);
        
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
