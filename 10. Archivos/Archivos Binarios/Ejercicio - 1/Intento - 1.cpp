/*

Una empresa dedicada a las ventas de productos por mayor registra en un archivo binario solo los
totales de ventas que se van realizando durante el día. Las cargas de los datos se realizan en cualquier momento,
por lo que el archivo no debe perder la información con una nueva carga.

El dueño de la empresa solicita, al centro de cómputos, le confeccione un sistema qué por medio
de un menú se pueda realizar lo siguiente:
    • Permitir registrar en cualquier momento los montos totales de venta.
    • Saber cuál es la mayor venta guardada y la cantidad de veces que se registró el mismo
    monto.
• Visualizar los datos en pantallas, donde cada fila deberá tener 10 datos separados por un
guion y visualizar 6 dígitos por cada valor. En caso de que la cantidad sea menor a 6 dígitos
rellenar con ceros a la izquierda hasta completar los 6 dígitos.
    • Saber cuál es el monto total de las ventas realizadas en el momento de la consulta.
    • Permitir al final del día borrar el archivo.

    NOTA:
    Utilizar para todas las opciones del menú funciones. 
    Cada función deberá recibir cómo unosus parámetros el archivo.
    El archivo debe ser abierto al inicio del programa y cerrarlo al final del programa

*/


#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int menu();
int accion();
int verificacion(FILE *archivoTotalVenta);
void cargarVentasTotales(FILE *archivoTotalVenta, int cargas);
float conocerMayorVenta(FILE *archivoTotalVenta, int &cantidadCargada);
void indexearDatos(FILE *archivoTotalVenta, int acDeN);
int buscarValor(FILE *archivoTotalVenta, float monto);

main(){

    int cantidadCargada = 0;
    int opc = 0;
    int verif = 0;
    int cargas = 0;
    int operacion = 0;
    float montomax = 0.0;
    int acDeN = 0; 

    FILE *archivoTotalVenta;
    archivoTotalVenta = fopen("ejercicio1.dat", "a+b");

    verif = verificacion(archivoTotalVenta);

    if(verif == 1){
        exit(1);
    }
    opc = menu();
    do{
        switch(opc){
            case 1:
                printf("\nIngrese la cantidad de cargas que desea hacer: ");
                scanf("%d", &cargas);
                system("cls");
                cargarVentasTotales(archivoTotalVenta, cargas);
                acDeN += cargas;
                
   			 	archivoTotalVenta = fopen("ejercicio1.dat", "a+b");
    			
                operacion = accion();
                
                if(operacion == 1){
                    opc = menu();
                }else{
                    opc = 5;
                }
                break;
                
            case 2:
                system("cls");
                montomax = conocerMayorVenta(archivoTotalVenta, cantidadCargada);
                printf("El monto maximo es de: %.2f", montomax);
                printf("\nSe repitio un total de: %d", cantidadCargada);
                break;
                
                operacion = accion();
                if(operacion == 1){
                    opc = menu();
                }else{
                    opc = 4;
                }
                
                // esta situacion del case no funciona directamente 
                // pq jamas guarda los valores xd
            case 3:
                indexearDatos(archivoTotalVenta, acDeN);

                operacion = accion();
                if(operacion == 1){
                    opc = menu();
                }else{
                    opc = 5;
                }
                break;
            case 4:
                printf("\n\nBorrando archivo... \n");
	            fclose(archivoTotalVenta);
	            
	            remove("ejercicio1.dat");
                
				archivoTotalVenta = fopen("ejercicio1.dat", "w+b");

				if(archivoTotalVenta == NULL){
					system("cls");
					printf("Se produjo un error al abrir el archivo.");
					exit(1);
				}
				
                operacion = accion();
                if(operacion == 1){
                    opc = menu();
                }else{
                    opc = 5;
                }

                break;
            case 5:
                system("cls");
                printf("\nSaliendo...");
                exit(1);
                break;
            default:
                printf("Ingreso un valor no permitido.");
                break;
        }
    }while(opc != 5);

	fclose(archivoTotalVenta);
}

int menu(){
    int opc = 0;
    system("cls");
    printf("1- Ingresar una cantidad n de montos de venta.");
    printf("\n2- Conocer la mayor venta guardada y cuantas veces se repitio.");
    printf("\n3- Indexear datos.");
    printf("\n4- Borrar el archivo.");
    printf("\n5- Salir del programa");
    printf("\nSu opcion: ");

    scanf("%d", &opc);

    return opc;
}


int verificacion(FILE *archivoTotalVenta){
    int retorno = 0;
    if(archivoTotalVenta == NULL){

    system("CLS");
    printf("\n\n Se produjo un ERROR al intentar abrir el archivo\n");
    printf("comuniquese con el administrador del Sistema. Gracias");
    printf("\n\n\t");
    system("PAUSE");
        retorno = 1;
    }

    return retorno;
}

void cargarVentasTotales(FILE *archivoTotalVenta, int cargas){
    float monto = 0.0;
    int v = 0;

	fclose(archivoTotalVenta);
	archivoTotalVenta = fopen("ejercicio1.dat", "ab");

	rewind(archivoTotalVenta);

    for(int i = 0; i < cargas; i++){

        do{
            system("cls");
            printf("--------------------------\n");
            printf("Ingrese el monto %d: ", i+1);
            scanf("%f", &monto);
        }while(monto < 0);
        
        fwrite(&monto, sizeof(float), 1, archivoTotalVenta);
        
    }
    	
    fclose(archivoTotalVenta);
}

int accion(){
    int acc = 0;
    printf("\n\nDesea hacer otra accion?");
    printf("\n1- Si \t\t 2- No");
    printf("\nSu opcion: ");
    scanf("%d", &acc);

    if (acc != 0) acc = 1;

    return acc;
}

float conocerMayorVenta(FILE *archivoTotalVenta, int &cantidadCargada){
    float mayor = 0.0;
    float monto = 0.0;

    do {
        fread(&monto, sizeof(float), 1, archivoTotalVenta);

		if(monto > mayor){
			mayor = monto;
		}

    }while(!feof(archivoTotalVenta));

    cantidadCargada = buscarValor(archivoTotalVenta , mayor);

    return mayor;
}

int buscarValor(FILE *archivoTotalVenta, float mayor){
    int cantidadVeces = 0;
    float numero = 0.0;

    rewind(archivoTotalVenta);

    fread(&numero, sizeof(float), 1, archivoTotalVenta);

    do{
        if(numero == mayor){
            cantidadVeces++;
        }
    }while(!feof(archivoTotalVenta));

    return cantidadVeces;
}

void indexearDatos(FILE *archivoTotalVenta, int acDeN){
	
    int count = 0;
    float totalTemp = 0.0;
    float acVentas = 0.0;
    
    system("cls");
    printf("Datos cargados: \n");

    _flushall();
	rewind(archivoTotalVenta);
	

    do{
    	
        fread(&totalTemp, sizeof(totalTemp), 1, archivoTotalVenta);
        acVentas += totalTemp;
        
        printf("%d ||  %6.2f \n", count, totalTemp);
        count++;
        
    }while(!feof(archivoTotalVenta) && acDeN > count);

    printf("\n\nEl total de ventas es de: %.2f", acVentas);

}