/*

Un Sanatorio Registra la ficha de sus pacientes en un archivo llamado “pacientes.dat” que registra la 
patología de sus pacientes en un registro que contiene la siguente estructura:

1) Código del Paciente 2) Nombre del Paciente 3) Patología 
(0 = Gripe Estacional, 1 = Gripe A, 2 = Neumonía, 3 = Bronquitis).
Se solicita:
a) Crear y cargar N registros en el archivo. 
b) Ingresar un código de paciente y modificar su patología, emitiendo un listado del mismo.


*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct paciente{
    int codigo;
    int patologia;
    char nombre[50];

};

void cargarDeAUno(FILE *arch);
void modificarPatologia(FILE *arch, int codigo);
void listarArchivo(FILE *arch);

main(){
    paciente pacienteUnico;
    FILE *arch;
    int n = 0;
    int codigoDeBusqueda = 0;

    arch = fopen("patologias.dat","r+b");

	if ( arch == NULL)
	{   arch == fopen("patologias.dat","w+b");	}
	if ( arch == NULL)
	{ printf("Error. No se pudo crear el archivo"); exit(1); }

    listarArchivo(arch);
	printf("Ingrese n: ");
    scanf("%d", &n);
    if(n == 10){
    	remove("patologias.dat");
	}
    
    fseek(arch, sizeof(paciente), SEEK_SET);
    
    for(int i = 0; i < n; i++){
    	cargarDeAUno(arch);
    /*	if(i = 0){
    		cargarDeAUno(arch);	
		}else{
			fseek(arch, -sizeof(paciente), SEEK_CUR);
			cargarDeAUno(arch);
		} */
        
    }

	system("cls");
	listarArchivo(arch);
	printf("\n\n");
	system("pause");

    system("cls");
    printf("Ingrese un codigo del paciente: ");
    scanf("%d", &codigoDeBusqueda);

	modificarPatologia(arch, codigoDeBusqueda);
	system("cls");
	listarArchivo(arch);
	
	printf("\n");
	system("pause");

	fclose(arch);
}

void cargarDeAUno(FILE *arch){
    paciente pac;
    
    // carga del struct

    system("cls");
    printf("Ingrese el codigo: ");
    scanf("%d", &pac.codigo);
    printf("\nIngrese la patologia: ");
    scanf("%d", &pac.patologia);
	
	_flushall();
    printf("\nIngrese el nombre: ");
    gets(pac.nombre);
    
    _flushall();
    
	// registro cargado completamente

/*
	Atento que este codigo funciona:
	
	rewind(arch);
    fseek(arch,sizeof(paciente),SEEK_END);
    fseek(arch, -sizeof(paciente), SEEK_CUR);

    fwrite(&pac, sizeof(paciente), 1, arch);
	
	Lógica inerte a este código:
	
	Rebobino el archivo para poner el puntero al inicio del arch
	luego mando un seek al end para obtener donde escribir
	proximamente hago seek a uno atras para escribir
	termino escribiendo y además funcionando...
	
*/

	rewind(arch);
    fseek(arch,sizeof(paciente),SEEK_END);
    fseek(arch, -sizeof(paciente), SEEK_CUR);

    fwrite(&pac, sizeof(paciente), 1, arch);


    printf("\n\nSe realizo la carga del paciente.\n\n");
    system("pause");
	
}

void modificarPatologia(FILE *arch, int codigo){
    paciente pac;
    
    int patologia = 0;

	rewind(arch);

    fread(&pac, sizeof(paciente), 1, arch);

	while(!feof(arch)){
		if(pac.codigo == codigo){
	    
		printf("\nIngrese la correcion de la patologia: ");
	    scanf("%d", &pac.patologia);
	    //fseek(arch, -sizeof(paciente), SEEK_CUR);
	    fseek(arch, -sizeof(paciente), SEEK_CUR);
	    fwrite(&pac, sizeof(paciente), 1, arch);
	    printf("\n\nSe realizo la modificación."); 
	    break;
	}
	
    fread(&pac, sizeof(paciente), 1, arch); 
	}
}

void listarArchivo(FILE *arch){
    paciente pac; 
	int contador = 1;
    rewind(arch);
    
    fread(&pac, sizeof(paciente), 1, arch);

    while(!feof(arch)){

	    printf("\n--- Paciente %d ---", contador);
	
	    printf("\nNombre: %s", pac.nombre);
	    printf("\nCodigo: %d", pac.codigo);
	    printf("\nPatologia: %d", pac.patologia);
	
		printf("\n--- Paciente %d ---\n", contador);
	    
	    fread(&pac, sizeof(paciente), 1, arch);	

		contador++;
    }

}