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
	

En un negocio de venta de artículos para el hogar se registra el stock o existencia de sus productos en un vector
de estructuras que tiene los siguientes datos:
• Código. //Código producto 5 dígitos.
• Artículo. //Nombre del producto.
• Cantidad mínima. //es el stock mínimo que puede tener el producto.
• Fecha Última Compra. (anidar) //Fecha última Compra realizada.
• Existencia Actual. //Cantidad disponible del producto para la venta.
• Precio 

a. Ingresar como mínimo 10 productos.
b. Ingresado un determinado código, actualizar su existencia actual y la fecha de compra. 
Usar función que recibe entre otros datos necesarios el código del producto, fecha de compra,
cantidad comprada. En caso de no encontrar el código del producto mostrar un mensaje de error.
c. Realizar la venta de un determinado producto solicitando su código y mostrar en pantalla su
 descripción, precio, solicitar la cantidad comprada y mostrar el monto a pagar. 
 Controlar que la Venta no sea mayor a la Existencia actual. Usarfunción.



*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct fechaUltComp{
    int dia;
    int mes;
    int anio;
};

struct stock{
    int codigo;
    char nombre[20];
    int cantMinima;
    int cantActual;
    float precio;
    fechaUltComp fecha;
};

void ingresarDatos(stock stock[30], int n);
int buscarCodigo(stock stock[30], int n, int codigo, int &indice);
void ingCodigoYActualizar(stock stock[30], int n, int codigo, int indice);
void mostrarProducto(stock stock[30], int &n, int &codigo);

main(){
    int n = 0;
    int codigoDeActu = 0;
    stock stock[30];
    int bandera = 0;
    int indice = 0;
    int banderaParaCod = 0;

    do{
        system("cls");
        printf("Ingrese la cantidad de articulos (n >= 10): ");
        scanf("%d", &n); 
    }while(n < 10);

    ingresarDatos(stock, 10);

    printf("\n\n");
    system("pause");
    system("cls");

    do{
        do{
            printf("Ingresar un codigo para actualizar existencia: ");
            scanf("%d", &codigoDeActu);

            banderaParaCod = buscarCodigo(stock, n, codigoDeActu, indice);

            ingCodigoYActualizar(stock, n, codigoDeActu, indice);

        }while(banderaParaCod == 0);

        printf("Desea seguir actualizando stock? \n1- Si \t2- No\nIngrese su opcion: ");
        scanf("%d", &bandera);
    }while(bandera == 1);


    
}

void ingresarDatos(stock stock[30], int n){

    system("cls");
    int codigoTemp = 0;
    int temporalDeCantidad = 0;
    int temporalDeCantidadMinima = 0;
    for(int i=0; i<n; i++){
        // carga del codigo
        do{
            printf("Ingrese el codigo: ");
            scanf("%d", &codigoTemp);
        }while(codigoTemp >= 10000 && codigoTemp < 100000);
        
        stock[i].codigo = codigoTemp;

        // nombre del producto
        _flushall();
        printf("\nIngrese el nombre del producto: ");
        gets(stock[i].nombre);


        // cantidad minima garantizada > 0
        do{
            printf("\nIngrese la cantidad minima del producto: ");
            scanf("%d", &temporalDeCantidadMinima);
        }while(temporalDeCantidadMinima < 0);

        stock[i].cantMinima = temporalDeCantidadMinima;


        // cantidad actual > cantidad minima;
        do{
            printf("\nIngrese la cantidad actual: ");
            scanf("%d", &temporalDeCantidad);
        }while(stock[i].cantMinima > temporalDeCantidad);

        stock[i].cantActual = temporalDeCantidad;

        _flushall();

        printf("\nIngrese el dia de ultima compra: ");
        scanf("%d", &stock[i].fecha.dia);
        printf("\nIngrese el mes de ultima compra: ");
        scanf("%d", &stock[i].fecha.mes);
        printf("\nIngrese el anio de ultima compra: ");
        scanf("%d", &stock[i].fecha.anio);

        _flushall();

        printf("\nIngrese el precio del producto: ");
        scanf("%f", &stock[i].precio);

    }
}

int buscarCodigo(stock stock[30], int n, int codigo, int &indice){
    int seEncuentra = 0;
    for(int i = 0; i < n; i++){
        if(stock[i].codigo == codigo){
            indice = i;
            seEncuentra = 1;
        }
    }

    return seEncuentra;
}

void ingCodigoYActualizar(stock stock[30], int n, int codigo, int indice){
    _flushall();
    system("cls");

    printf("Ingrese la existencia actual: ");
    scanf("%d", stock[indice].cantActual);

    _flushall();

    printf("Ingrese el dia de compra del producto: ");
    scanf("%d", &stock[indice].fecha.dia);
    printf("Ingrese el mes de compra del producto: ");
    scanf("%d", &stock[indice].fecha.mes);
    printf("Ingrese el anio de compra del producto: ");
    scanf("%d", &stock[indice].fecha.anio);
    
}


void mostrarProducto(stock stock[30], int &n, int &codigo){

    system("cls");
    int ind = 0;
    int seEncuentra = 0;
    int cantidadVender = 0;
    int cantidadRequerida = 0;
    seEncuentra = buscarCodigo(stock, n, codigo, ind);

    if(seEncuentra == 1){
        printf("Codigo: ", stock[ind].codigo);
        printf("\nNombre: %s", stock[ind].nombre);
        printf("\nStock minimo: %d", stock[ind].cantMinima);
        printf("\nStock actual: %d", stock[ind].cantActual);
        cantidadVender = stock[ind].cantActual-stock[ind].cantMinima;
        printf("\nDisponible para vender: %d", cantidadVender);

        do{
            printf("\nIngrese la cantidad que quiere vender: ");
            scanf("%d", &cantidadRequerida);
        }while(cantidadRequerida > cantidadVender);

        printf("\nEl precio de la venta es de: %.2f", stock[ind].precio*cantidadRequerida);
        stock[ind].cantActual = stock[ind].cantActual-cantidadRequerida;
        
        printf("\n\n");
        system("pause");

    }
}
