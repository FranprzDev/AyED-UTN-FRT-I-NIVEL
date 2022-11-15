/*

En un archivo se tienen registradas las ventas que realiza un comercio. 
Cada registro contiene los siguientes datos:
- Numero de vendedor (Son tres los vendedores 1, 2, 3)
- Apellido y Nombre del vendedor
- Numero Factura.
- Importe facturado por esa venta.
- Forma de venta (1: Contado, 2: Crédito)
- Fecha de Venta (DD MM AAAA) (Año se registra 4 dígitos) campo jerarquizado.
Desarrolle un programa que permita realizar, al encargado del negocio, por medio de un menú las
siguientes operaciones que deben ser realizadas en función diferente:
a. Carga de los datos al archivo, tener en cuenta que cada vez
que se habrá el archivo o se realice una nueva carga NO debe perder lo que ya se tiene registrado.
Y verificar que se ingresen valores válidos para los miembros número de vendedor y forma
de venta.
b.Cantidad total de venta registrada en un mes determinado. (El mes debe ser solicitado por teclado).
c. Mostrar cuantas ventas se realizaron de Contado y cuantas ventas se realizaron a Crédito, de un
determinado mes. (El mes se solicita por teclado).
d.Importe total realizado en el mes por un vendedor. (El apellido y nombre del vendedor, deberá ser
solicitado por teclado).
e. Listar todos los datos que contiene el archivo.


*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct fecha{
    int dia;
    int mes;
    int anio;
};

struct reg{
    int numVendedor;
    int numeroFactura;
    char nya[80];
    float importeVenta;
    int formaVenta;
    fecha fechaVenta;
};

int menu();
void cargarArchivo(FILE *vendedores);
void cantidadTotalVentas(FILE *vendedores);
int ventasContado(FILE *vendedores);
int ventasCredito(FILE *vendedores);
int seEncuentraNombre(FILE *vendedores, char nombreyAP[80]);
float importeTotal(FILE *vendedores, char nombreYAP[80]);
float listarDatos(FILE *vendedores);

main(){
	
    FILE *vendedores;
    FILE *test;
    
    test = fopen("test.dat", "w+b");

    vendedores = fopen("vendedores.dat", "r+b");

    if(vendedores = NULL){
        vendedores = fopen("vendedore1s.dat", "w+b");
        if(vendedores == NULL){
            system("cls");
            printf("No se pudo cargar el archivo, error.");
            exit(1);
        }
    }

    int mes = 0;
    char nyaAux[80];
    int encontrado = 0;
    float imp = 0;
    int opc = 0;
	int ventC = 0;
    int ventCred = 0;
    
    
    do{
        opc = menu();

        switch(opc){
            case 1:
                system("cls");
                cargarArchivo(vendedores);
            break;
            case 2:
                system("cls");
                cantidadTotalVentas(vendedores);
            break; 
            case 3:
                // ventas de contado y a credito.

                ventC = ventasContado(vendedores);
                ventCred = ventasCredito(vendedores);
                
                printf("\n\nLas ventas de Contado son: %.2f", ventC);
                printf("\n\nLas ventas de Credito son: %.2f", ventCred);
            break; 
            case 4:
                printf("Ingrese un apellido y nombre: ");
                _flushall();
                gets(nyaAux);

                encontrado = seEncuentraNombre(vendedores, nyaAux);

                if (encontrado == 1){
                    printf("\nSe encontro el vendedor.");

                    imp = (float) importeTotal(vendedores, nyaAux);
                    
                    printf("\n\nEl importe total del vendedor: %s es: %06.2f", nyaAux, imp);
                }else{
                    printf("\nNo se encontro el apellido y nombre...");
                }

            break;
            case 5:
                listarDatos(vendedores);
            break;
            case 6:
                system("cls");

                printf("Saliendo....");
            break;
            default:
                system("cls");

                printf("ERROR - Saliendo....");
                fclose(vendedores);
                exit(1);
                break;
        }
        
    }while(opc != 6);

    fclose(vendedores);
}

int menu(){
    system("cls");
    int opc;

    printf("1. Cargar datos en los archivos. ");
    printf("\n2. Solicitar total de venta en un mes. ");
    printf("\n3. Mostrar las ventas de contado y cuantas a credito de un mes");
    printf("\n4. Importe total de ventas por un vendedor, por apellido y nombre.");
    printf("\n5. Listar los datos del archivo. ");
    printf("\n6. Salir");
    printf("\nSu opcion: ");
    scanf("%d", &opc);

    return opc;
}

void cargarArchivo(FILE *vendedores){
    rewind(vendedores);
    reg vendedor;
    int numVendedor = 0;
    int formaVenta = 0;
    system("cls");
    _flushall();
    printf("Ingrese el nombre y apellido: ");
    gets(vendedor.nya);
    _flushall();
    do{
        printf("\nIngrese el num vendedor: ");
        scanf("%d", &numVendedor);
        printf("\n");
    }while(numVendedor != 1 || numVendedor != 2 || numVendedor != 3);
    
    vendedor.numVendedor = numVendedor;
    printf("\nIngrese el num de factura: ");
    scanf("%d", &vendedor.numeroFactura);
    printf("\nIngrese el importe de venta: ");
    scanf("%f", &vendedor.importeVenta);

    do{
        printf("\nIngrese la forma de venta: ");
        scanf("%d", &formaVenta);
        printf("\n");
    }while(formaVenta != 1 || formaVenta != 2);

	vendedor.formaVenta = formaVenta;
	
    printf("\nIngrese el dia de venta: ");
    scanf("%d", &vendedor.fechaVenta.dia);
    printf("\nIngrese el mes de venta: ");
    scanf("%d", &vendedor.fechaVenta.mes);
    printf("\nIngrese el anio de venta: ");
    scanf("%d", &vendedor.fechaVenta.anio);

    // aqui el reg ya esta cargado correctamente entonces empiezo a pasar al arch

    fseek(vendedores, 0, SEEK_END);
    fwrite(&vendedor, sizeof(reg), 1, vendedores);

}

void cantidadTotalVentas(FILE *vendedores){
	system("cls");
	int mes;
	printf("Ingrese el mes que quiera ver la cantidad de ventas realizadas: ");
	scanf("%d", &mes);
	int contadorMes = 0;
 
	reg aux;
	rewind(vendedores); 
 
	fread(&aux,sizeof(reg), 1, vendedores); 
 
	switch(mes){
		case 1:
			while(!feof(vendedores)){
				if(aux.fechaVenta.mes == mes){ contadorMes++; }
				fread(&aux, sizeof(reg),1,vendedores);	
			}

			printf("\nSe realizon un total de %d ventas en el mes 1.", contadorMes);
			contadorMes = 0;
		break;
        case 2:
			while(!feof(vendedores)){
				if(aux.fechaVenta.mes == mes){ contadorMes++; }
				fread(&aux, sizeof(reg),1,vendedores);	
			}

			printf("\nSe realizon un total de %d ventas en el mes 1.", contadorMes);
			contadorMes = 0;
		break;
		case 3:
			while(!feof(vendedores)){
				if(aux.fechaVenta.mes == mes){ contadorMes++; }
				fread(&aux, sizeof(reg),1,vendedores);	
			}

			printf("\nSe realizon un total de %d ventas en el mes 1.", contadorMes);
			contadorMes = 0;
		break;
        case 4:
			while(!feof(vendedores)){
				if(aux.fechaVenta.mes == mes){ contadorMes++; }
				fread(&aux, sizeof(reg),1,vendedores);	
			}

			printf("\nSe realizon un total de %d ventas en el mes 1.", contadorMes);
			contadorMes = 0;
		break;
		case 5:
			while(!feof(vendedores)){
				if(aux.fechaVenta.mes == mes){ contadorMes++; }
				fread(&aux, sizeof(reg),1,vendedores);	
			}

			printf("\nSe realizon un total de %d ventas en el mes 1.", contadorMes);
			contadorMes = 0;
		break;
        case 6:
			while(!feof(vendedores)){
				if(aux.fechaVenta.mes == mes){ contadorMes++; }
				fread(&aux,sizeof(reg),1,vendedores);	
			}

			printf("\nSe realizon un total de %d ventas en el mes 1.", contadorMes);
			contadorMes = 0;
		break;
		case 7:
			while(!feof(vendedores)){
				if(aux.fechaVenta.mes == mes){ contadorMes++; }
				fread(&aux,sizeof(reg),1,vendedores);	
			}

			printf("\nSe realizon un total de %d ventas en el mes 1.", contadorMes);
			contadorMes = 0;
		break;
        case 8:
			while(!feof(vendedores)){
				if(aux.fechaVenta.mes == mes){ contadorMes++; }
				fread(&aux,sizeof(reg),1,vendedores);	
			}

			printf("\nSe realizon un total de %d ventas en el mes 1.", contadorMes);
			contadorMes = 0;
		break;
        case 9:
			while(!feof(vendedores)){
				if(aux.fechaVenta.mes == mes){ contadorMes++; }
				fread(&aux,sizeof(reg),1,vendedores);	
			}

			printf("\nSe realizon un total de %d ventas en el mes 1.", contadorMes);
			contadorMes = 0;
		break;
        case 10:
			while(!feof(vendedores)){
				if(aux.fechaVenta.mes == mes){ contadorMes++; }
				fread(&aux,sizeof(reg),1,vendedores);	
			}

			printf("\nSe realizon un total de %d ventas en el mes 1.", contadorMes);
			contadorMes = 0;
		break;
        case 11:
			while(!feof(vendedores)){
				if(aux.fechaVenta.mes == mes){ contadorMes++; }
				fread(&aux,sizeof(reg),1,vendedores);	
			}

			printf("\nSe realizon un total de %d ventas en el mes 1.", contadorMes);
			contadorMes = 0;
		break;
        case 12:
			while(!feof(vendedores)){
				if(aux.fechaVenta.mes == mes){ contadorMes++; }
				fread(&aux,sizeof(reg),1,vendedores);	
			}

			printf("\nSe realizon un total de %d ventas en el mes 1.", contadorMes);
			contadorMes = 0;
		break;
    }
}

int ventasContado(FILE *vendedores){
    int cantidadVentasContado = 0;
    reg aux;

    rewind(vendedores);

    fread(&aux, sizeof(reg), 1, vendedores);

    while(!feof(vendedores)){
        if(aux.formaVenta == 1){
            cantidadVentasContado++;
        }
    }

    return cantidadVentasContado;
}

int ventasCredito(FILE *vendedores){

    int cantidadVentasCredito = 0;
    reg aux;

    rewind(vendedores);

    fread(&aux, sizeof(reg), 1, vendedores);

    while(!feof(vendedores)){
        if(aux.formaVenta == 2){
            cantidadVentasCredito++;
        }
    }

    return cantidadVentasCredito;
}

int seEncuentraNombre(FILE *vendedores, char nombreyAP[80]){
    int seEncuentra = 0;

    reg aux; 
    rewind(vendedores);
    int cond = 0;

    fread(&aux, sizeof(reg), 1, vendedores);
    
    while(!feof(vendedores)){
        cond = strcmp(aux.nya, nombreyAP);
        
        if(cond == 0){
            seEncuentra = 1;
        }
    }

    return seEncuentra;
}

float importeTotal(FILE *vendedores, char nombreYAP[80]){
    rewind(vendedores);
    int comp = 0;
    reg aux;
    float importeTotal = 0;


    fread(&aux, sizeof(reg), 1, vendedores);

    while(!feof(vendedores)){
        comp = strcmp(aux.nya, nombreYAP);

        if(comp == 0){
            importeTotal += aux.importeVenta;
        }

    }
    
    return importeTotal;
}

float listarDatos(FILE *vendedores){
    rewind(vendedores);
    system("cls");
    reg aux; 
    int i = 0;

    fread(&aux, sizeof(reg), 1, vendedores);

    while(!feof(vendedores)){
        i++;
        printf("Vendedor %d", i);
        printf("\nNombre y Apellido: %s", aux.nya);
        printf("\nNumero de Vendedor: %d", aux.numVendedor);
        printf("\nNumero de Factura: %d", aux.numeroFactura);
        printf("\nImporte Venta: %f", aux.importeVenta);
        printf("\nForma de venta: %d", aux.formaVenta);
        printf("\nFecha de venta: %03d/%03d/%04d", aux.fechaVenta.dia, aux.fechaVenta.mes, aux.fechaVenta.anio);

        printf("\n");

        fread(&aux, sizeof(reg), 1, vendedores);
    }
}