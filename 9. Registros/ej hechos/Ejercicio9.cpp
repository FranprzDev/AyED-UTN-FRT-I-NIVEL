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
	

Se desea almacenar el inventario de un comercio de artículos deportivos, en un arreglo de registro. 
La descripción de cada artículo, contiene.
- Código, Descripción, cantidad en stock, precio unitario.
Desarrolla un programa controlado por un menú, que brinde opciones para:
a. Ingresar N registros en el arreglo.
b. Buscar un artículo, dado su código y mostrar sus datos en pantalla. Si el artículo es encontrado dar la posibilidad de 
eliminar dicho artículo del arreglo. En caso de no ser encontrado mostrar por pantalla informando que el artículo no 
fue encontrado. Tener en cuenta que si se eliminó un artículo, se debe reagrupar el arreglo para no dejar celdas vacías.
c. Lista todo el inventario, ordenado alfabéticamente (decreciente) según descripción de cada artículo. El ordenamiento 
se deberá realizar en otro arreglo.
d. Lista todo el inventario, ordenado crecientemente por cantidad de stock. (usar otro arreglo, puede ser el mismo que 
se usó para ordenar alfabéticamente

*/

#include<stdlib.h>
#include<stdio.h>
#include<string.h>

struct reg{
    int codigo;
    char descripcion[30];
    int cantidadStock;
    float precioUnitario;
};


void cargarRegistros(reg registros[20], int n);
int existeCodigo(reg registros[20], int n, int codBuscar, int &indiceEncontrado);
void mostrarArticulo(reg registros[20], int n, int &indiceEncontrado);
void borrarArticulo(reg registros[20], int n, int &indiceEncontrado);
void listarAlfabeticamenteDecreciente(reg registros[20], int n, reg regAux[20], reg aux[1]);
void listarPorStockCrecientemente(reg registros[20], int n, reg regAux[20], reg aux[1]);
void mostrarTodosLosArt(reg registros[20], int n);

main(){

    reg registros[20];
    reg registrosParalelo[19];
    reg regAux[20];
    reg aux[1];

    int codigoABuscar = 0;
    int bandFind = 0;
    int opc;
    int indiceEncontrado = 0;
    
    int n = 0;
    int decision = 0;
    printf("Ingrese n: ");
    scanf("%d", &n);

    cargarRegistros(registros, n);
    
	printf("\n\n");
	system("cls");
	
	printf("\nListado alfabeticamente en forma decreciente: \n\n");
	
	listarAlfabeticamenteDecreciente(registros, n, regAux, aux);
	mostrarTodosLosArt(regAux, n);
	
	printf("\n");	
	system("pause");
	system("cls");
	
	printf("Listado por stock en forma creciente: \n\n");
	
	listarPorStockCrecientemente(registros, n, regAux, aux);
	mostrarTodosLosArt(regAux, n);
    
    printf("\n\n");
    system("pause");
    
    do{
        system("cls");
        printf("Ingrese un codigo: ");
        scanf("%d", &codigoABuscar);

        bandFind = existeCodigo(registros, n, codigoABuscar, indiceEncontrado);
    }while(bandFind == 0); 

    // en este punto cuando sale del while ya tengo que se encontro el codigo y el indice donde lo encontro...
	
	printf("\n");	
	system("pause");
	system("cls");
	
	do{
	    printf("\nQue desea hacer? \n1. Borrar el articulo \t\t2. Mostrar articulo");
	    printf("\nSu opcion: ");
	    scanf("%d", &opc);	
	    
	   switch(opc){
	    case 1:
	        system("cls");
	        borrarArticulo(registros, n, indiceEncontrado);
	        break;
	    case 2:
	        system("cls");
	        mostrarArticulo(registros, n, indiceEncontrado);
	        break;
	   }
	   
	   printf("\n");
   	   printf("\nDesea hacer otra operacion: \n1. Si \t\t2. No");
	   printf("\nSu opcion: ");
	   scanf("%d", &decision);	
   
	}while(decision == 1);

	system("cls");
	printf("\n\n");
	printf("\nTerminando programa: ");
	
	mostrarTodosLosArt(registros, n);

	printf("\n");	
	system("pause");
	
}

void cargarRegistros(reg registros[20], int n){
    system("cls");
    for(int i = 0; i < n; i++){
    	system("cls");
        printf("Ingrese el codigo: ");
        scanf("%d", &registros[i].codigo);
        _flushall();
        printf("\nIngrese la descripcion: ");
        _flushall();
        gets(registros[i].descripcion);
        _flushall();
        printf("\nIngrese la cantidad de stock: ");
        scanf("%d", &registros[i].cantidadStock);
        _flushall();
        printf("\nIngrese el precio unitario: ");
        scanf("%f", &registros[i].precioUnitario);
        _flushall();
        
        printf("\n\n");
        system("pause");
    }
}


// esto devolvera 1 si y solo si encunetra el codigo en el registro, si no devolvera 0.
int existeCodigo(reg registros[20], int n, int codBuscar, int &indiceEncontrado){
    int seEncontro = 0;
    for(int i = 0; i < n; i++){
        if(codBuscar == registros[i].codigo){
            seEncontro++;
            indiceEncontrado = i;
            i = n;
        }
    }

    return seEncontro;
}   

void mostrarArticulo(reg registros[20], int n, int &indiceEncontrado){
    system("cls");
    
    printf("Articulo N: %d", indiceEncontrado);
    printf("\nCodigo: %d", registros[indiceEncontrado].codigo);
    printf("\nDescripcion: %s", registros[indiceEncontrado].descripcion);
    printf("\nCantidad de Stock: %d", registros[indiceEncontrado].cantidadStock);
    printf("\nPrecio unitario: %.2f", registros[indiceEncontrado].precioUnitario);

}

void mostrarTodosLosArt(reg registros[20], int n){
		
	for(int i = 0; i < n; i++){
	printf("Articulo N: %d", i);
    printf("\nCodigo: %d", registros[i].codigo);
    printf("\nDescripcion: %s", registros[i].descripcion);
    printf("\nCantidad de Stock: %d", registros[i].cantidadStock);
    printf("\nPrecio unitario: %.2f", registros[i].precioUnitario);	
    printf("\n\n");
	}

}

void listarAlfabeticamenteDecreciente(reg registros[20], int n, reg regAux[20], reg aux[1]){
    // decreciente significa del mayor valor al menor 
    // uso de la funcion strcmp() para esto...
    
    int comparacion = 0;
    int band = 0;

    for(int i = 0; i < 20; i++){
        regAux[i] = registros[i];
    }

    do{
        band = 0;
        for(int i = 0; i < n; i++){
            for(int j = i+1; j < n; j++){
                comparacion = strcmp(regAux[i].descripcion, regAux[j].descripcion);
                if(comparacion == -1){
                    aux[1] = regAux[i];
                    regAux[i] = regAux[j];
                    regAux[j] = aux[1];
                    band = 1;
                }
            }
        }
    }while(band == 1);

}

void listarPorStockCrecientemente(reg registros[20], int n, reg regAux[20], reg aux[1]){
    // crecientemente significa del menor al mayor
    int band = 0; 
    
    for(int i = 0; i < 20; i++){
        regAux[i] = registros[i];
    }

	do{
		band = 0;
	    for(int i = 0; i < n; i++){
	        for(int j = i+1; j < n; j++) {
	            if(regAux[i].cantidadStock > regAux[j].cantidadStock){
	                aux[1] = regAux[i];
	                regAux[i] = regAux[j];
	                regAux[j] = aux[1];
	                band = 1;
	            }
	        }
    	}
	}while(band == 1);
	
}

void borrarArticulo(reg registros[20], int n, int &indiceEncontrado){

    for(int contador = indiceEncontrado+1; contador < n; contador++){
        registros[contador-1] = registros[contador]; 
        registros[contador].cantidadStock = 0;
        registros[contador].codigo = 9999;
        registros[contador].precioUnitario = 0;
        strcpy(registros[contador].descripcion, "Registro deshabilitado.");
    }

}
