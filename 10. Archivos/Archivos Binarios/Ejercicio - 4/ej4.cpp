/*

ARCHIVO BINARIO CON ESTRUCTURA

Temas: Modificación – Eliminación Lógica - Eliminación Física de registro
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
--- Desde aquí el ejercicio - 4 ---
El gerente de la empresa que nos encomendó la realización del sistema de venta de su comercio;
Ahora nos solicita agreguemos a dicho sistema las siguientes opciones que no fueron 
contemplados en el primer análisis.
f. Realizar la modificación del campo “forma de venta” de una determinada factura, la búsqueda para
modificar será por su número de factura. Nota: mostrar el valor anterior y pedir el nuevo valor del
contenido del campo forma de venta.
g. Realizar baja lógica a una determinada factura. La búsqueda se realiza por número de factura. Una
vez encontrado mostrar sus datos y solicitar confirmación antes de realizar el borrado lógico. En el
caso de no encontrarse mostrar un mensaje de error.
h.Listar todos los registros que hayan sido marcado como borrado lógico.
i. Realizar el borrado físico de los registros marcados con borrado lógico. Para ingresar a esta opción
se debe solicitar una clave de ingreso.
j. Ordenar el archivo por número de factura y listar los datos ordenados.


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

typedef char CAD[200];

int menu();
void cargarArchivo(FILE *vendedores);
void totalVentas(FILE *vendedores);
int ventasContado(FILE *vendedores);
int ventasCredito(FILE *vendedores);
int encontrarNombre(FILE *vendedores,char NomyAp[80]);
float importeTotal(FILE *vendedores, char NomyAp[80]);
float listarDatos(FILE *archi);
int buscarFactura(FILE *vendedores, int tempFactura);
void modificarFactura(FILE *vendedores, int &tempFactura);
void cargarRegConFactura(FILE *vendedores, int tempFactura, reg aux);
void mostrarReg(reg aux);
void bajaLogicaPorFact(FILE *vendedores, int tempFactura);
void listarRegistrosMarcadosLogicamente(FILE *vendedores);
void borradoFisico(FILE *vendedores);
void ordenarPorFactura(FILE *vendedores);
void ordenarVectorDeRegistros(reg vect[30]);
void(char CAD[200], int &contadorVocales)


main()
{
	FILE *vendedores;
	
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
    int tempFactura;
    int tempFactC7;
    int existeFactura;
	
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
                //  Modificar el campo de venta a partir de una factura
                printf("Ingrese una factura: ");
                scanf("%d", &tempFactura);

                existeFactura = buscarFactura(vendedores, tempFactura);

                if(existeFactura == 1){

                    // modificar el campo si es que existe.
                    modificarFactura(vendedores, tempFactura);
                }else{
                    printf("\n\nLa factura indicada, no existe...");
                }

                printf("\n\n");

                system("pause");
            break;

            case 7:
                // Realizar la baja logica a partir de una factura
                tempFactC7 = 0;
                printf("Ingrese una factura: ");
                scanf("%d", &tempFactC7);

                existeFactura = buscarFactura(vendedores, tempFactC7);

                if(existeFactura == 1){
                    // realizo la baja logica del mismo
                    bajaLogicaPorFact(vendedores, tempFactura);
                }else{
                    printf("\n\nLa factura indicada, no existe...");
                }

                printf("\n\n");

                system("pause");
            break;

            case 8:

                listarRegistrosMarcadosLogicamente(vendedores);

                printf("\n\n");

                system("pause");
            break;
            case 9:

                // borrado fisico de los marcados como logico...

                borradoFisico(vendedores);

                printf("\n\n");

                system("pause");
            break;
				  
            case 10:

                // aqui ordeno el archivo por numero de factura...
                
                ordenarPorFactura(vendedores);
                
			case 11:
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
	}while(opcion!=11);


    fclose(vendedores);
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
    printf("\n6. Modificar el campo de venta a partir de una factura");
    printf("\n7. Realizar la baja logica a partir de una factura.");
    printf("\n8. Listar los registros dado de baja logica.");
    printf("\n9. Realizar el borrado fisico de los registros con borrado logico, con clave.");
    printf("\n10. Acomodar el archivo por numero de factura.");
    printf("\n11. Salir\n\n");
    
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
        
        mostrarReg(aux);
        
        printf("\n");
        
		}

        fread(&aux,sizeof(aux),1,archi);
	}
}

int buscarFactura(FILE *vendedores, int tempFactura){
    int existe = 0;

    reg aux;
    rewind(vendedores);

    fread(&aux,sizeof(reg),1,vendedores);

    while(!feof(vendedores)) {
        if(aux.numeroFactura==tempFactura){
            existe = 1;
        }
        
        fread(&aux,sizeof(reg),1,vendedores);
    }

    return existe;
}

void modificarFactura(FILE *vendedores, int &tempFactura){

    int band = 0;
    int contrasenia;
    rewind(vendedores);

    reg aux;
    reg busqueda;
    int cambio = 0;
    
    // carga el reg

    rewind(vendedores);
    
    fread(&aux,sizeof(reg),1,vendedores);

    while(!feof(vendedores) && (band == 0)){
        if(aux.numeroFactura == tempFactura){
            band = 1;
            
            fseek(vendedores, 0, SEEK_END);
            break;
        }

        fread(&aux, sizeof(reg), 1, vendedores);
    }

    system("cls");

    printf("Contenido de la factura: ");
    mostrarReg(aux);

    printf("\n");

    printf("Quiere modificar el campo 'Forma de venta' de la factura: ");

    printf("\n1- Si \t\t 2- No");
    printf("\nSu opcion: ");
    scanf("%d", &band);

    if(band == 1){
        printf("\n\nIngrese la contrasenia: ");
        scanf("%d", &contrasenia);
        if(contrasenia == 1234){
            // aca hago el cambio...
            printf("\nIngrese la forma de venta: \n");
            printf("\n1- Venta de Contado.");
            printf("\n2- Venta por Credito. \n");

            printf("\nSu cambio: ");
            scanf("%d", &cambio);
            
            while(cambio < 1 || cambio > 2){
                printf("\n\n");
                printf("\nIngrese la forma de venta: \n");
                printf("\n1- Venta de Contado.");
                printf("\n2- Venta por Credito. \n");

                printf("\nSu cambio: ");
                scanf("%d", &cambio);
            }

            aux.formaVenta = cambio;

            rewind(vendedores);
            // rebobino archivo y despues
            // voy a realizar el cambio...
            fread(&busqueda, sizeof(reg), 1, vendedores);

            while(!feof(vendedores)){
                if(busqueda.numeroFactura == tempFactura){
                    // haciendo el cambio retrocedo 1 para que 
                    // mande al puntero donde realmente tiene que sobre
                    // escrbir pq si no va a hacer cualquier cosa 
                    fseek(vendedores,(long) -sizeof(reg), SEEK_CUR);
                    fwrite(&aux, sizeof(reg), 1, vendedores);
                    break;
                }

                fread(&busqueda, sizeof(reg), 1, vendedores);
            }

            printf("\nCambio realizado.");
        }else{
            printf("\nContrasenia incorrecta.");
        }
    }else{
        printf("\n\nOk, volviendo al menu principal. \n\n");
    }

}

/*void cargarRegConFactura(FILE *vendedores, int tempFactura, reg aux){
    int band = 0;
    rewind(vendedores);
    
    fread(&aux,sizeof(reg),1,vendedores);

    while(!feof(vendedores) && (band == 0)){
        if(aux.numeroFactura == tempFactura){
            band = 1;
            break;
        }

        fread(&aux, sizeof(reg), 1, vendedores);
    }

    al parecer si lo mando a una funcion no funcaxd
}*/

void mostrarReg(reg aux){

    printf("\nNombre y Apellido: %s", aux.ApeNom);
    printf("\nNumero de Vendedor: %d", aux.NumVendedor);
    printf("\nNumero de Factura: %d", aux.numeroFactura);
    printf("\nImporte Venta: %f", aux.importeVenta);
    printf("\nForma de venta: %d", aux.formaVenta);
    printf("\nFecha de venta: %02d/%02d/%04d", aux.fechaVenta.dia, aux.fechaVenta.mes, aux.fechaVenta.anio);

}

void bajaLogicaPorFact(FILE *vendedores, int tempFactura){

    reg aux;
    reg bajado;
    int opc = 0;
    int band = 1;
	int clave = 0;
    // rewind

    rewind(vendedores);

    // leo del archivo un aux
    fread(&aux,sizeof(reg),1,vendedores);
	
    // empiezo a recorrer el archivo preguntando si es el temporal de factura que deseo

    while(!feof(vendedores) && band == 1) {
        if(aux.numeroFactura == tempFactura){
            band = 0;

			fseek(vendedores, 0, SEEK_END);
        }
        
        fread(&aux,sizeof(reg),1,vendedores);
    }

	// ya tengo el registro que quiero modificar en mi auxiliar.
    // muestro el reg ad ar de baja
    printf("\nContenido del registro a dar de baja: \n");
        
    mostrarReg(aux);

	printf("\n");

    printf("\nAun desea darle de baja: ");
    printf("1. Si \t\t 2- No \n");
    printf("Su opcion: ");
    scanf("%d", &opc);
    band = 1;

   if(opc == 1){

		printf("\nIngrese la clave para dar de baja: ");
		scanf("%d", &clave);

		int bandera = 0;

		if(clave == 1234){
			printf("Borrando archivo...");

			fread(&bajado, sizeof(reg), 1, vendedores);

			aux.borrado = true;

			while(!feof(vendedores) && bandera == 0){
				if(bajado.numeroFactura == tempFactura) {
					fseek(vendedores,(long) -sizeof(reg), SEEK_CUR);

					fwrite(&aux, sizeof(reg), 1, vendedores);

					bandera = 1;
					fseek(vendedores, 0, SEEK_END);
				}

				fread(&bajado, sizeof(reg), 1, vendedores);
			}

			if(bandera == 1){
				printf("\nSe pudo realizar la baja del registro en cuestion. \n");
			}else{
				printf("\nNo se pudo realizar la baja del registro en cuestion. \n\n")
			}
		}
   }else{
		printf("\nNo se dio de baja la factura...");
   }


}

void listarRegistrosMarcadosLogicamente(FILE *vendedores){
    reg aux;

    printf("\nListado de Registros Borrados Logicamente \n");

    rewind(vendedores);

    fread(&aux,sizeof(reg),1,vendedores);

    while(!feof(vendedores)){
        if(aux.borrado == true){
        	
            mostrarReg(aux);
            printf("\n");
            
        }

        fread(&aux,sizeof(reg),1,vendedores);
    }

}

void borradoFisico(FILE *vendedores){

    int clave;
    reg aux;
    FILE *auxiliar;

    auxiliar = fopen("auxiliar.dat","w+b");

    // la verdad q no me importa q pase con este aux, ya que es solo un aux...

    system("cls");

    printf("Archivos a Borrar: ");

    listarRegistrosMarcadosLogicamente(vendedores);

    printf("\n\n");

    printf("\nDesea confirmar borrar, debe ingresar una clave: ");
    printf("\nIngrese la clave: ");
    scanf("%d", &clave);

    if(clave == 1234){
        system("cls");

        // aquí hago el cambio...

        rewind(vendedores);

        fread(&aux,sizeof(reg),1,vendedores);

        while(!feof(vendedores)){
            
            if(aux.borrado == false){
                fwrite(&aux,sizeof(reg),1, auxiliar);    
            }

            fread(&aux,sizeof(reg),1,vendedores);


            // con esto voy omitiendo los que tengan el borrado en 'false'
        }

        fclose(vendedores);
        fclose(auxiliar);

        remove("vendedores.dat");
        rename("auxiliar.dat", "vendedores.dat");

        // este el proceso para una baja física.

        vendedores = fopen("vendedores.dat","a+b");

        // este es el proceso para volver a abrir el archivo
        // y que cuando lo mande al main me vuelva con lo que necesito xd.

    }else{
        printf("\n\nClave INCORRECTA...");
    }
    
    // tecnicamente aqui termina la función, ya que no hay nada más que hacer.
}

void ordenarPorFactura(FILE *vendedores){

    reg vectAux[30];

    reg aux;

    rewind(vendedores);

    fread(&aux, sizeof(reg), 1, vendedores);
    // i < 30 muestra la cantidad de reg que voy a guardar como max.
    for(int i = 0; i < 30; i++){

    /*
        if(aux.borrado == false){
            vectAux[i] = aux;
        }

            esto podría ser una solucion para los reg borrados pero me 
            da mucha paja hacerla, tienen que verificar como se mueve el puntero.
    */     

    vectAux[i] = aux;

    fread(&aux, sizeof(reg), 1, vendedores);

    }

    ordenarVectorDeRegistros(vectAux);

    rewind(vendedores);

    for(int i = 0; i < 30; i++){
        aux = vectAux[i];

        fwrite(&aux,sizeof(reg),1,vendedores);

    }

    // termina ya ordenado todo el arreglo
}

void ordenarVectorDeRegistros(reg vect[30]){
    // los ordeno por el numero de factura
    int b;
    reg temp;

    do{
        b = 0;
        for(int i = 0; i < 30; i++){
            for(int j = i+1; j < 30; j++){
                // los ordeno crecientemente, del menor al mayor
                if(vect[i].numeroFactura > vect[j].numeroFactura){
                    temp = vect[i];
                    vect[i] = vect[j];
                    vect[j] = temp;
                    b = 1;
                }
            }
        }
    }while(b == 1);

    // este codigo me ordena el vector donde estan los registros.
    // devuelve el reg ya ordenado
}