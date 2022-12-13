/*

La Universidad Tecnológica Nacional registra la información de sus egresados en un archivo lla-mado.
 “egresados.dat” que presenta la siguiente configuración de registro lógico:
1) Código de Fa-cultad 
2) Nombre de la Facultad 
3) Cantidad de egresados.
Se solicita:
a)	Determine y muestre el código de Facultad con mayor cantidad de egresados. 
b)	Dado un determinado código de facultad eliminar físicamente del archivo el registro corres-pondiente.

*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct fac{
    char nombreFac[80];
	int codigoFac;
    int cantEgresados;
};

void cargarArchivo(FILE *arch);
int codigoMayorFac(FILE *arch, int codBuscar);
void listarArchivo(FILE *arch);
void borrarFisico(FILE *arch, int codigoBorrar);

main(){
	int cantidad;
/*    FILE *arch;
    FILE *aux;

	aux = fopen("aux.dat", "r+b");
	
	if(aux == NULL){
		aux = fopen("aux.dat", "w+b");
		if(aux == NULL){
            printf("El archivo no se pudo crear...");
		}
	}
	
    arch = fopen("egresados.dat", "r+b");

    if(arch == NULL){
        arch = fopen("egresados.dat", "w+b");

        if(arch == NULL){
            printf("El archivo no se pudo crear...");
        }
    } */
    
    FILE *arch;
    FILE *aux;
    
    aux = fopen("aux.dat", "r+b");

    arch = fopen("egresados.dat", "r+b");
    
    if(aux == NULL){
    	aux = fopen("aux.dat", "w+b");
        if(aux == NULL){
            system("cls");
            printf("No se pudo cargar el archivo, error.");
            exit(1);
		}
	}
	
    if(arch == NULL){
    	arch = fopen("egresados.dat", "w+b");
        if(arch == NULL){
            system("cls");
            printf("No se pudo cargar el archivo, error.");
            exit(1);
		}
	}
    
    system("pause");
    listarArchivo(arch);

    printf("Ingrese la cantidad de facultades que desea cargar: ");
    scanf("%d", &cantidad);
    
    rewind(arch);
    
    for(int i = 0; i < cantidad; i++){
        cargarArchivo(arch);
    }
    
    printf("\nIngrese el codigo de la facu que desea buscar: ");
    int codBuscar = 0;
    scanf("%d", &codBuscar);
    int egresados = 0;

    egresados = codigoMayorFac(arch, codBuscar);
    printf("\nLa cantidad de egreasdos del codigo %d es %d \n\n", codBuscar, egresados);

    int codigoBorrar = 0;
    
    printf("\nIngrese un codigo para borrar: ");
    scanf("%d", &codigoBorrar);

    borrarFisico(arch, codigoBorrar);
    
    fclose(arch);
}

void cargarArchivo(FILE *arch){
    int cantidad = 0;
    fac facu;

    system("cls");

    printf("Ingrese el nombre de la facultad: ");
    _flushall();
    gets(facu.nombreFac);
    _flushall();
    printf("\nIngrese el codigo de la fac: ");
    scanf("%d", &facu.codigoFac);
    printf("\nIngrese la cantidad de egresados: ");
    scanf("%d", &facu.cantEgresados);

	fseek(arch, 0, SEEK_END);
    fwrite(&facu, sizeof(facu), 1, arch);

}

int codigoMayorFac(FILE *arch, int codBuscar){
    int egresadosFac = 0;

    fac facu;

    rewind(arch);

    fread(&facu, sizeof(fac), 1, arch);

    while(!feof(arch)){
        if(facu.codigoFac == codBuscar){
            egresadosFac = facu.cantEgresados;
        }
        
        fread(&facu, sizeof(fac), 1, arch);
    }

    return egresadosFac;
}

void listarArchivo(FILE *arch){
    
    system("cls");
	int contador = 0;
	rewind(arch);
    fac facu;
    
    fread(&facu, sizeof(fac), 1, arch);

    while(!feof(arch)){
    	contador++;
    	
    	printf("--- Facu %d ---\n", contador);
        printf("Nombre facu: %s", facu.nombreFac);

        printf("\nCodigo facu: %d", facu.codigoFac);

        printf("\nCantidad Egresados: %d\n\n", facu.cantEgresados);

        fread(&facu, sizeof(fac), 1, arch);
    }
}

void borrarFisico(FILE *arch, int codigoBorrar){

	fclose(arch);
	FILE *test;
//	FILE *aux;
//	FILE *aux3;
	
//	aux = fopen("aux3.dat", "wb");
	
//	aux = fopen("aux.dat", "wb");
	test = fopen("test.dat", "wb");
   	fac facu;
	arch = fopen("egresados.dat", "r+b");
	
    rewind(arch);
    rewind(test);

 
    fread(&facu, sizeof(facu), 1, arch);

    while(!feof(arch)){
        if(facu.codigoFac != codigoBorrar){
        	
            fwrite(&facu, sizeof(facu), 1, test);
            
            fread(&facu, sizeof(facu), 1, arch);	
        }else{
        	fread(&facu, sizeof(facu), 1, arch);
		}
    }
    
    fclose(test);
    fclose(arch);
    
    remove("egresados.dat");
    rename("test.dat", "egresados.dat");
	
	arch = fopen("egresados.dat", "r+b");
	
	listarArchivo(arch);
}