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
	
Una empresa registra los datos de sus vendedores en un registro y cada uno de su miembro es un arreglo (vector) 
que representa el monto de venta realizado por el vendedor de lunes a viernes. 
La estructura de dicho registro es la siguiente:
• Apellido y nombre
• Numero de documento
• Fecha Ingreso (o de contrato)
• Venta Semanal 


Defina el registro de vectores de manera apropiada según la descripción de los datos y 
por medio de un menú de opciones realizar las siguientes operaciones.
    a) Registrar como mínimo 5 empleados, sin registrar ventas.
    b) Registrar el total de venta al final del día. La registración se hará por medio de una función que 
       reciba el apellido y nombre,
       el día de la venta (Lunes, martes,…, viernes), y el monto a registrar. 
       (Si hubo un error porque apellido y nombre no figura mostrar un mensaje indicando el error)
    c) Listar por pantalla las ventas de la semana y el monto total vendido por cada uno de los empleados. Observe el
    modelo de listado que debe realizar. (Para este tipo de listado, deberá investigar la máscara o formato que se
    aplica a los datos de salida).

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct fechaContrato{
    int dia;
    int mes;
    int anio;
};

struct datosVendedores{
    char apellidoynombre[50];
    int numeroDoc;
    fechaContrato fecha;
    float ventaSemanal;
};

int menu();

void cargarEmpleados(datosVendedores vectorVend[30], int n);
int compararSiExiste(datosVendedores vectorVend[30], int n, char vendedor[50], int &indiceEncontrado);
void cargarVentaSemanal(datosVendedores vectorVend[30], int n, int indiceEncontrado, float montoVenta);

main(){
    // maximo de vendedores = 30
    datosVendedores vectorVendedores[30];

    int n = 0, salir = 0, opcionMenu;
    char apynomtemp[50];
    int comparacion = 0;
    int accion = 0;
    int diaACargar = 0;
    float montoVenta = 0.0;
    int indiceEncontrado = 0;

    do{
        opcionMenu = menu();

        switch(opcionMenu) {
            case 1:
                 do{
                    printf("Ingrese la cantidad de vendedores: ");
                    scanf("%d", &n);
                }while(n < 5);
                
                cargarEmpleados(vectorVendedores, n); 
				
                break;
            case 2:
                system("cls");
                printf("Ingrese el apellido y nombre: ");
                _flushall();
                gets(apynomtemp);

                comparacion = compararSiExiste(vectorVendedores, n, apynomtemp, indiceEncontrado);

                if(comparacion == 1){

                        system("cls");

                        printf("Ingrese el monto de venta: ");
                        scanf("%f", &montoVenta);

                        cargarVentaSemanal(vectorVendedores, n, indiceEncontrado, montoVenta);

                }else{
                    printf("\n\n");
                    printf("No se encontro ese apellido y nombre.");
                }

                break;
            case 3:
					
					system("cls");
					
                    printf("--- Lista de Vendedores ---\n");
                    printf("\n%2 N | %30 Apellido y Nombre | %8 Documento |  %3 Contrato - Dia | %3 Contrato - Mes | %3 Contrato - Anio | %10 Venta Semanal \n");
                    for(int i = 0; i < n; i++){
                        printf("\n%2d | %30s                          | %8d       | %3d  | %3d  | %3d  | %10.2f     ", i, vectorVendedores[i].apellidoynombre, vectorVendedores[i].numeroDoc, vectorVendedores[i].fecha.dia, vectorVendedores[i].fecha.mes, vectorVendedores[i].fecha.anio, vectorVendedores[i].ventaSemanal);
                    }
                    
                    
                    printf("\n\n");
                    system("pause");
                break;
            case 4:
                system("cls");
                printf("Saliendo del programa...\n\n");
                system("pause");

                return 0;
                break;
        }

        system("cls");
        printf("\n\nDesea realizar otra opcion?");
        printf("\n1. Si \t\t2. No");
        printf("\nSu opcion: ");
        scanf("%d", &salir);
    }while(salir == 1);
}

int menu(){
    int opc;

        system("cls");

		printf("--- Menu ---\n");
        printf("1. Registrar al menos 5 empleados sin registrar ventas.");
        printf("\n2. Registrar las ventas de cada empleado, y la venta total final");
        printf("\n3. Listar datos");
        printf("\n4. Cerrar programa");

        printf("\n\n");
        printf("Su opcion: ");
        scanf("%d", &opc);

    return opc;
}

void cargarEmpleados(datosVendedores vectorVend[30], int n){
    system("cls");
    for(int i=0; i<n; i++){
        
        // Aqui se registran unicamente datos.

        printf("--- Vendedor %d ---\n", i);
        printf("Ingrese el Apellido y Nombre: ");
        _flushall();
        gets(vectorVend[i].apellidoynombre);
        printf("\nIngrese el numero de documento: ");
        scanf("%d", &vectorVend[i].numeroDoc);
        printf("\nIngrese el dia de contrato: ");
        scanf("%d", &vectorVend[i].fecha.dia);
        printf("\nIngrese el mes de contrato: ");
        scanf("%d", &vectorVend[i].fecha.mes);
        printf("\nIngrese el anio de contrato: ");
        scanf("%d", &vectorVend[i].fecha.anio);

    }

}

int compararSiExiste(datosVendedores vectorVend[30], int n, char vendedor[50], int &indiceEncontrado){
    int devolver = -1;
    for(int i=0; i<n; i++){
        devolver = strcmp(vectorVend[i].apellidoynombre, vendedor);
        if(devolver == 0){
            devolver = 1;
            indiceEncontrado = i;
            i = n;
        }
    }

    return devolver;
}

void cargarVentaSemanal(datosVendedores vectorVend[30], int n, int indiceEncontrado, float montoVenta){
    vectorVend[indiceEncontrado].ventaSemanal = montoVenta;
}
