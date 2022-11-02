/*
En un negocio que se dedica a la venta de insumos eléctricos tiene la información de sus clientes en la siguiente
estructura.

struct datosCliente{
int codCli; //código del cliente
char ApeNom[40]; //apellido y nombre
char dire[60]; //domicilio particular
float monCred; //Monto máximo del crédito que puede realizar en cada compra.
};


• Ingresar el dato N clientes. Listo
• A medida que se van ingresando los clientes, usando una función mostrar los datos registrados.
• Al finalizar la carga de los N clientes, mostrar cuantos clientes tienen un monto de crédito superior a $ 30.000.


*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct datosCliente{

    int codCli; 
    char ApeNom[40];
    char dire[60]; 
    float monCred; 

};

void cargarDatos(datosCliente clientes[20], int n);
void mostrarDatos(datosCliente clientes[20], int indice);
int cantidadClientesMonto30k(datosCliente clientes[20], int indice);


main(){

    int n = 0;
    int cantidadMaximaClientes1 = 20;
    datosCliente clientes[cantidadMa2ximaClientes];

    int maxClient = 0;

    do{
        printf("Ingrese la cantidad n de clientes: ");
        scanf("%d", &n);
        system("cls");
    }while(n > 20);

    cargarDatos(clientes, n);

    maxClient = cantidadClientesMonto30k(clientes, n);

    printf("\n\nLa cantidad con monto mayor a 30000 es de %d clientes", maxClient);

}


void cargarDatos(datosCliente clientes[20], int n){
    system("cls");

    //    int codCliTemp = 0;

    for(int i = 0; i < n; i++){
        printf("Ingrese el codigo del cliente: ");
       // scanf("%d", &codCliTemp);
       // clientes[i].codCli = codCliTemp;
        scanf("%d", &clientes[i].codCli);
        printf("\nIngrese el Apellido y Nombre: ");
        _flushall();
        gets(clientes[i].ApeNom);
        printf("\nIngrese la Direccion: ");
        _flushall();
        gets(clientes[i].dire);
        printf("\nIngrese el monto de credito: ");
        scanf("%f", &clientes[i].monCred);

        mostrarDatos(clientes, i);

    }
}

void mostrarDatos(datosCliente clientes[20], int indice){
    system("cls");

    printf("Codigo: %d", clientes[indice].codCli);
    printf("\nApellido y Nombre: %s", clientes[indice].ApeNom));
    printf("\nDireccion: %s", clientes[indice].dire);
    printf("\nMonto: %.2f", clientes[indice].monCred);

    printf("\n\n");

    system("pause");
}

int cantidadClientesMonto30k(datosCliente clientes[20], int indice){
    int contador = 0;
    for(int i = 0; i < n; i++){

        if(clientes[i].monCred > 30000){
            contador++;
        }
    }

    return contador;
}