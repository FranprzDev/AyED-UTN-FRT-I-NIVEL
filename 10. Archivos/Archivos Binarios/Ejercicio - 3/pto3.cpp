/*

En un archivo se tienen registradas las ventas que realiza un comercio. Cada registro contiene los
siguientes datos:
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

struct fecha
{
	int dia;
	int mes;
	int anio;
};

struct reg
{
	int NumVendedor;
	char ApeNom[80];
	int numeroFactura;
	float importeVenta;
	int formaVenta;
	fecha fechaVenta;
	bool borrado;
};

int menu();
void cargarArchivo(FILE *vendedores);
void totalVentas(FILE *vendedores);
int ventasContado(FILE *vendedores);
int ventasCredito(FILE *vendedores);
int encontrarNombre(FILE *vendedores,char NomyAp[80]);
float importeTotal(FILE *vendedores, char NomyAp[80]);
float listarDatos(FILE *archi);

main()
{
	FILE *vendedores;
	FILE *test;
	
	vendedores=fopen("vendedores.dat","r+b");
	
	if(vendedores == NULL)
	{
		vendedores=fopen("vendedores.dat","w+b");
		
		if(vendedores == NULL)
		{
			system("cls");
			printf("\nNo se pudo crear el archivo");
			exit(1);
		}
	}
	
	int mes=0;
	char ApeNomAux[80];
	int opcion=0;
	int ventCont,ventCred;
	int encontrado;
	float imp;
	
	do
	{
		opcion=menu();
		
		switch(opcion)
		{
			case 1:
				   system("cls");
				   cargarArchivo(vendedores);
				   break;
			case 2:
				   system("cls");
				   printf("\nTotal de ventas: \n");
				   totalVentas(vendedores);
				   break;
			case 3:
				  ventCont=ventasContado(vendedores);
				  ventCred=ventasCredito(vendedores);
				  
				  printf("\nLa cantidad de ventas de contado es de %d: ",ventCont);
				  printf("\nLa cantidad de ventas de credito es de %d: ",ventCred);

                  printf("\n\n");
                  system("pause");
				  break;
			case 4:
				  printf("\nIngrese un apellido y nombre: ");
				  _flushall();
				  gets(ApeNomAux);
				  encontrado=encontrarNombre(vendedores,ApeNomAux);
				  
				  if(encontrado==1)
				  {
				  	printf("\nSe encontro el vendedor.");
				  	
				  	imp = (float) importeTotal(vendedores,ApeNomAux);
				  	printf("\nEl importe total del vendedor: %s es: %06.2f",ApeNomAux,imp);
				  }
				  else
				  {
				  	printf("\nNo se encontro el apellido y el nombre..");
				  }

                  printf("\n\n");

                  system("pause");
				  break;
			case 5:{
				printf("Listar datos");
				printf("\n\n");
				listarDatos(vendedores);
				system("pause");
				break;
					
			}
				
				  
			case 6:
				  system("cls");
				  printf("\nSaliendo..");
				  break;
			default:
				   system("cls");
				   
				   printf("ERROR - Saliendo....");
                   fclose(vendedores);
                   exit(1);
                   break;
		}
	}while(opcion!=6);
}

int menu()
{
	system("cls");
	int opcion;
	
	printf("\n--- MENU DE OPCIONES ---\n");
	printf("1. Cargar datos en los archivos. ");
    printf("\n2. Solicitar total de venta en un mes. ");
    printf("\n3. Mostrar las ventas de contado y cuantas a credito de un mes");
    printf("\n4. Importe total de ventas por un vendedor, por apellido y nombre.");
    printf("\n5. Listar los datos del archivo. ");
    printf("\n6. Salir\n\n");
    
    system("pause");
    
    printf("\n\nIngrese su opcion: ");
    scanf("%d",&opcion);
    return opcion;
}

void cargarArchivo(FILE *vendedores)
{
	
	rewind(vendedores);
	
	reg vendedor;
	
	//campo numero del vendedor
	printf("Ingrese el numero del vendedor: ");
	scanf("%d",&vendedor.NumVendedor);
	
	while((vendedor.NumVendedor<1)  || (vendedor.NumVendedor>3))
	{
		printf("\nError. El codigo debe estar entre uno y tres.");
		
		printf("\nIngrese el numero del vendedor: ");
		scanf("%d",&vendedor.NumVendedor);
	}
	
	//campo Apellido y Nombre
	printf("\nApellido y nombre: ");
	_flushall();
	gets(vendedor.ApeNom);
	
	//campo numero de factura
	printf("\nNumero de factura: ");
	scanf("%d", &vendedor.numeroFactura);
	
	printf("\nImporte venta: ");
	scanf("%f", &vendedor.importeVenta);

	//campo forma de venta
	do
	{
		printf("\nForma de venta: (1-CONTADO 2-CREDITO) ");
		scanf("%d", &vendedor.formaVenta);
		
		if(vendedor.formaVenta>=1 && vendedor.formaVenta<=2)
		{
			break;
		}
		printf("\nError.La forma de venta debe ser 1(contado) o 2(credito)..\n");
	}while(true);
	
	//campo Fecha de venta
	printf("\n--- Fecha ---\n");
	printf("\nDia: ");
	scanf("%d",&vendedor.fechaVenta.dia);
	printf("\nMes: ");
	scanf("%d",&vendedor.fechaVenta.mes);
	printf("\nAnio: ");
	scanf("%d",&vendedor.fechaVenta.anio);
	
	vendedor.borrado = false;
	
	fseek(vendedores,0,SEEK_END);
	
	fwrite(&vendedor,sizeof(vendedor),1,vendedores);
}

void totalVentas(FILE *vendedores)
{
	system("cls");
	int mes=0;
	
	printf("Ingresa el mes del que quiera ver la cantidad de ventas realizadas: ");
	scanf("%d",&mes);

	_flushall();
	int contadorMes=0;
	
	reg aux;
	rewind(vendedores);
	
	switch(mes)
	{
		case 1:

	          fread(&aux,sizeof(reg),1,vendedores);
			  while(!feof(vendedores))
			  {
			  	if(aux.fechaVenta.mes==mes)
			  	{
			  		contadorMes++;
			  	}
			  	fread(&aux,sizeof(reg),1,vendedores);
			  }
			  printf("\nSe realizo un total de %d ventas en el mes 1.",contadorMes);
			  contadorMes=0;
			  break;
		case 2:

	          fread(&aux,sizeof(reg),1,vendedores);
			  while(!feof(vendedores))
			  {
			  	if(aux.fechaVenta.mes==mes)
			  	{
			  		contadorMes++;
			  	}
			  	fread(&aux,sizeof(reg),1,vendedores);
			  }
			  printf("\nSe realizo un total de %d ventas en el mes 2.",contadorMes);
			  contadorMes=0;
			  break;
	   case 3:

	          fread(&aux,sizeof(reg),1,vendedores);
	   	      while(!feof(vendedores))
			  {
			  	if(aux.fechaVenta.mes==mes)
			  	{
			  		contadorMes++;
			  	}
			  	fread(&aux,sizeof(reg),1,vendedores);
			  }
			  printf("\nSe realizo un total de %d ventas en el mes 3.",contadorMes);
			  contadorMes=0;
			  break;
		case 4:

	          fread(&aux,sizeof(reg),1,vendedores);
			  while(!feof(vendedores))
			  {
			  	if(aux.fechaVenta.mes==mes)
			  	{
			  		contadorMes++;
			  	}
			  	fread(&aux,sizeof(reg),1,vendedores);
			  }
			  printf("\nSe realizo un total de %d ventas en el mes 4.",contadorMes);
			  contadorMes=0;
			  break;
		case 5:

	          fread(&aux,sizeof(reg),1,vendedores);
			  while(!feof(vendedores))
			  {
			  	if(aux.fechaVenta.mes==mes)
			  	{
			  		contadorMes++;
			  	}
			  	fread(&aux,sizeof(reg),1,vendedores);
			  }
			  printf("\nSe realizo un total de %d ventas en el mes 5.",contadorMes);
			  contadorMes=0;
			  break;
		case 6:

	          fread(&aux,sizeof(reg),1,vendedores);
			  while(!feof(vendedores))
			  {
			  	if(aux.fechaVenta.mes==mes)
			  	{
			  		contadorMes++;
			  	}
			  	fread(&aux,sizeof(reg),1,vendedores);
			  }
			  printf("\nSe realizo un total de %d ventas en el mes 6.",contadorMes);
			  contadorMes=0;
			  break;
		case 7:

	          fread(&aux,sizeof(reg),1,vendedores);
			  while(!feof(vendedores))
			  {
			  	if(aux.fechaVenta.mes==mes)
			  	{
			  		contadorMes++;
			  	}
			  	fread(&aux,sizeof(reg),1,vendedores);
			  }
			  printf("\nSe realizo un total de %d ventas en el mes 7.",contadorMes);
			  contadorMes=0;
			  break;
		case 8:

	          fread(&aux,sizeof(reg),1,vendedores);
			  while(!feof(vendedores))
			  {
			  	if(aux.fechaVenta.mes==mes)
			  	{
			  		contadorMes++;
			  	}
			  	fread(&aux,sizeof(reg),1,vendedores);
			  }
			  printf("\nSe realizo un total de %d ventas en el mes 8.",contadorMes);
			  contadorMes=0;
			  break;
		case 9:

	          fread(&aux,sizeof(reg),1,vendedores);
			  while(!feof(vendedores))
			  {
			  	if(aux.fechaVenta.mes==mes)
			  	{
			  		contadorMes++;
			  	}
			  	fread(&aux,sizeof(reg),1,vendedores);
			  }
			  printf("\nSe realizo un total de %d ventas en el mes 9.",contadorMes);
			  contadorMes=0;
			  break;
		case 10:

	          fread(&aux,sizeof(reg),1,vendedores);
			   while(!feof(vendedores))
			  {
			  	if(aux.fechaVenta.mes==mes)
			  	{
			  		contadorMes++;
			  	}
			  	fread(&aux,sizeof(reg),1,vendedores);
			  }
			  printf("\nSe realizo un total de %d ventas en el mes 10.",contadorMes);
			  contadorMes=0;
			  break;
		case 11:

	          fread(&aux,sizeof(reg),1,vendedores);
			   while(!feof(vendedores))
			  {
			  	if(aux.fechaVenta.mes==mes)
			  	{
			  		contadorMes++;
			  	}
			  	fread(&aux,sizeof(reg),1,vendedores);
			  }
			  printf("\nSe realizo un total de %d ventas en el mes 11.",contadorMes);
			  contadorMes=0;
			  break;
		case 12:

	          fread(&aux,sizeof(reg),1,vendedores);
			   while(!feof(vendedores))
			  {
			  	if(aux.fechaVenta.mes==mes)
			  	{
			  		contadorMes++;
			  	}
			  	fread(&aux,sizeof(reg),1,vendedores);
			  }
			  printf("\nSe realizo un total de %d ventas en el mes 12.",contadorMes);
			  contadorMes=0;
			  break;
	   	 
	} // switch del mes
	
	printf("\n\n");
	system("pause");
} // fin void

int ventasContado(FILE *vendedores)
{
	int cantVentasContado=0;
	reg aux;
	
	rewind(vendedores);
	fread(&aux,sizeof(reg),1,vendedores);
	
	while(!feof(vendedores))
	{
		if(aux.formaVenta == 1)
		{
			cantVentasContado++;
		}
	    fread(&aux,sizeof(reg),1,vendedores);
	}
	
	return cantVentasContado;
}

int ventasCredito(FILE *vendedores)
{
	int cantVentasCredito=0;
	reg aux;
	
	rewind(vendedores);
	fread(&aux,sizeof(reg),1,vendedores);
	
	while(!feof(vendedores))
	{
		if(aux.formaVenta==2)
		{
			cantVentasCredito++;
		}
	    fread(&aux,sizeof(reg),1,vendedores);
	}
	return cantVentasCredito;
}

int encontrarNombre(FILE *vendedores,char NomyAp[80])
{
	int seEncuentra=0;
	
	reg aux;
	rewind(vendedores);
	int cond=0;
	
	fread(&aux, sizeof(reg), 1, vendedores);
	cond = strcmp(aux.ApeNom,NomyAp);
    if(cond == 0) seEncuentra=1;

	while(!feof(vendedores) && seEncuentra == 0)
	{
		cond=strcmp(aux.ApeNom,NomyAp);
		
		if(cond==0)
		{
			seEncuentra = 1;
		}

	    fread(&aux, sizeof(reg), 1, vendedores);
	}

	return seEncuentra;
}

float importeTotal(FILE *vendedores, char NomyAp[80])
{
    _flushall();
	rewind(vendedores);
	int comp=0;
	reg aux;
	float importeTotal = 0.0;
	
	fread(&aux,sizeof(reg),1,vendedores);
	
	while(!feof(vendedores))
	{
		comp=strcmp(aux.ApeNom,NomyAp);
		
		if(comp==0)
		{
			importeTotal += aux.importeVenta;
		}
	    fread(&aux,sizeof(reg),1,vendedores);
	}

	return importeTotal;
}

float listarDatos(FILE *archi)
{
	
	system("cls");
	
	rewind(archi);
	
	reg aux;
	int i=0;
	
	fread(&aux,sizeof(aux),1,archi);
	
	while(!feof(archi))
	{
		if(aux.borrado == false){
			
			i++;
		printf("\nVendedor %d", i);
        printf("\nNombre y Apellido: %s", aux.ApeNom);
        printf("\nNumero de Vendedor: %d", aux.NumVendedor);
        printf("\nNumero de Factura: %d", aux.numeroFactura);
        printf("\nImporte Venta: %f", aux.importeVenta);
        printf("\nForma de venta: %d", aux.formaVenta);
        printf("\nFecha de venta: %02d/%02d/%04d", aux.fechaVenta.dia, aux.fechaVenta.mes, aux.fechaVenta.anio);
        
        printf("\n");
        
        fread(&aux,sizeof(aux),1,archi);
			
		}
	}
}