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
#include <conio.h>

struct registro{
	float ventas;
};

int menu();
void cargarDatos(FILE *arch, registro reg);
void mostrarDatos(FILE *arch, registro reg);
void mostrarElMayor(FILE *arch, float &mayor, registro reg);
int contarCantidadMayor(FILE *arch, float mayor, registro reg);
void borrarArchivo(FILE *arch);

main(){
	
	registro ventas;
    FILE *arch;
    int opcion = 0;
    //int acDeCargas = 0;
    float mayor = 0.0;
    int cantMay; 

    arch = fopen("totalventas.dat","r+b");
	// AQUÍ ABRO EL ARCHIVO, PRIMERA VEZ QUE LO ABRO
	// también probé a+b y tampoco funciona
	
	if ( arch == NULL)
	{
		arch == fopen("totalventas.dat","w+b");		
	}
		if ( arch == NULL)
		{
			printf("Error. No se pudo crear el archivo");
			exit(1);
		}

    do{
        opcion = menu();
        
        switch(opcion){
            case 1:
                cargarDatos(arch, ventas);
                system("cls");
            break;
            case 2:
                mostrarDatos(arch, ventas);
                
				printf("\n\n");
                system("pause");
                //system("cls");
            break;
            case 3:
                system("cls");
                mostrarElMayor(arch, mayor, ventas);

                printf("El mayor es: %06.2f", mayor);

                printf("\n\n");

                system("pause");
            break;
            case 4:
                system("cls");
                cantMay = contarCantidadMayor(arch, mayor, ventas);

                printf("\nLa cantidad de veces que se repite el mayor es %d \n", cantMay);
                system("pause");
            break;
            case 5:
                borrarArchivo(arch);
            break;
            case 6:
                system("cls");
                printf("Saliendo del programa...");
            //    exit(1);
            break;
            default:
                system("cls");
                printf("Error con la opcion, saliendo...");
            //    exit(1);
            break;
        }

    }while(opcion != 6);

	fclose(arch);
	printf("\n");
	// si este es el unico fclose PORQUE SE ME BORRAN LOS DATOSSSSSSSSS
	system("pause");
} // fin main

int menu(){
    int opc = 0;
    system("cls");
    printf("--- Menu ---\n");
    printf("1- Cargar datos... \n");
    printf("2- Listar datos... \n");
    printf("3- Mostrar el mayor... \n");
    printf("4- Mostrar la cantidad de veces que se repite el mayor... \n");
    printf("5- Borrar el archivo\n");
    printf("6- Salir del menu");
    printf("\n\nSu opcion: ");
    scanf("%d", &opc);

    return opc;
}

void cargarDatos(FILE *arch, registro reg)
{
    int n = 0;    
    int i = 0;
    //printf("Ingrese n: ");
    //scanf("%d", &n);

    printf("\nCarga de montos: \n");

    //acDeCargas += n;
	
    rewind(arch);
    
    //_flushall();
    
    //while(!feof(arch) && n > i){
        printf("\nIngrese el monto: ");
        scanf("%f", &reg.ventas);
        fseek(arch,sizeof(reg),SEEK_END);

        fwrite(&reg, sizeof(reg), 1, arch);
        //i++;
    //}
    
    /*
    	
    	No se puede realizar un while porque esto proximamente generará problemas.
    	es mejor cargar uno por uno.
    	
    */

	// si yo pongo un f close aca despues se re mil bugea
}

void mostrarDatos(FILE *arch, registro reg){
    
	system("cls");
	//_flushall();
	
//	fclose(arch);
//	arch = fopen("totalventas.dat","rb");
	
    rewind(arch);
    
    fread(&reg, sizeof(reg), 1, arch);
    
    while(!feof(arch)) {
    	
    	printf("| %09.2f \n", reg.ventas);
    	
    	fread(&reg, sizeof(reg), 1, arch);
	}
	
}

void mostrarElMayor(FILE *arch, float &mayor, registro reg){
    
	float temp = 0.0;

    rewind(arch);


    while(!feof(arch)){

    fread(&reg, sizeof(registro), 1, arch);

    if(reg.ventas > mayor){
        mayor = reg.ventas;
    }

    }

}

int contarCantidadMayor(FILE *arch, float mayor, registro reg){
    int cantidad = 0;
    int i = 0;
    _flushall();
    rewind(arch);
    
    while(!feof(arch)){
    	
        fread(&reg, sizeof(registro), 1, arch);

        if(mayor == reg.ventas) cantidad++;
        i++;
    }

    return cantidad;
}

void borrarArchivo(FILE *arch){
    system("cls");
    remove("totalventas.dat");
    printf("Archivo Borrado...\n");
    system("pause");
    printf("\nGenerando nuevo archivo...");
    arch = fopen("totalventas.dat","w+b");
    // este es el 2do f open que hay pero solo se ejecuta si llamas a la funcion
}
