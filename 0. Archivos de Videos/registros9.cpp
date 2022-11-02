/*

Se desea almacenar el inventario de un comercio de artículos deportivos, en un arreglo de registro.
La descripción de cada artículo, contiene.
- Código, Descripción, cantidad en stock, precio unitario.
Desarrolla un programa controlado por un menú, que brinde opciones para:
a. Ingresar N registros en el arreglo.
b. Buscar un artículo, dado su código y mostrar sus datos en pantalla. Si el artículo es encontrado dar la posibilidad de
eliminar dicho artículo del arreglo. En caso de no ser encontrado mostrar por pantalla informando que el artículo no
fue encontrado. Tener en cuenta que si se eliminó un artículo, se debe reagrupar el arreglo para no dejar celdas vacías.
c. Lista todo el inventario, ordenado alfabéticamente (decreciente) según descripción de cada artículo. El ordenamiento
se deberá realizar en otro arreglo.
d. Lista todo el inventario, ordenado crecientemente por cantidad de stock. (usar otro arreglo, puede ser el mismo que
se usó para ordenar alfabéticamente.

*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct reg{
    int codigo;
    char descripcion[30];
    int cantidadStock;
    float precioUnitario;
};

int menu();
void cargarArreglo(reg art[30], int n);
void listarPorDescripcionDecreciente(reg art[30], reg artDec[30], int n);
void listarPorStockCreciente(reg art[30], reg artCrec[30], int n);
int exist(reg art[30], int n, int codigoBusqueda, int &indice);
void mostrarSegunCodigo(reg art[30], int indice);
void borrarArt(reg art[30], int n, int indice);
void listarTodosReg(reg art[30], int n);

main(){
    int opc = 0;
    int salir = 0;
    int n = 0;
    int codBusqueda = 0, existeCodigo = 0;
    int indice = 0;
    int des = 0;
    printf("Ingrese cantidad de articulos: ");
    scanf("%d", &n);

    reg art[30];
    reg artDec[30];
    reg artCrec[30];

    do{
        opc = menu(); 
        switch(opc){
            case 1:
                cargarArreglo(art, n);
                opc = menu();
                break;
            case 2:
                printf("Codigo a buscar: ");
                scanf("%d", &codBusqueda);

                existeCodigo = exist(art, n, codBusqueda, indice);

                switch(existeCodigo){
                    case 0:
                        printf("\n\nEl codigo no se encontro... ");
                        opc = menu();

                        break;
                    case 1:
    
                        mostrarSegunCodigo(art, indice);
                        printf("\n\nDesea borrar el art: ");
                        printf("\n1- Si \t\t 2 - No");
                        printf("Su opcion: ");

                        scanf("%d", &des);

                        if(des == 1){
                            borrarArt(art, n, indice);
                            printf("\nRegistro borrado con exito. ");
                            printf("\nRegistros reacomodados.");
                            
                            listarTodosReg(art, n);
                            system("pause");
                            opc = menu();
                        }else{
                            opc = menu();
                        }
                    break;
                }
                break;
            case 3:
            	
                listarPorDescripcionDecreciente(art, artDec, n);
                listarTodosReg(artDec, n);
                
            	system("pause");
            	
                opc = menu();
                break;
            case 4:
                listarPorStockCreciente(art, artCrec, n);
                listarTodosReg(artCrec, n);
                
            	system("pause");
            	
                opc = menu();
                break;
            case 5:
                printf("Saliendo...");
                salir = 1;
                break;
            default:
                salir = 1;
                break;
        }
    }while(salir != 1);

}

int menu(){
    int opc = 0;
    system("cls");
    printf("\n1. Cargar Registros: ");
    printf("\n2. Buscar un articulo x codigo y eliminarlo.");
    printf("\n3. Listar por descripcion (decrecientemente)");
    printf("\n4. Listar por stock (crecientemente)");
    printf("\n5. Salir");
    
    printf("\nSu opcion es: ");

    scanf("%d", &opc);

    return opc;
}

void cargarArreglo(reg art[30], int n){
    system("cls");
    for(int i = 0; i < n; i++){
        printf("Ingrese codigo: ");
        scanf("%d", &art[i].codigo);
        printf("\nIngrese cantidad stock: ");
        scanf("%d", &art[i].cantidadStock);
        printf("\nIngrese el precio unitario: ");
        scanf("%f", &art[i].precioUnitario);
        _flushall();
        printf("\nIngrese la descripcion: ");
        gets(art[i].descripcion);
        _flushall();

        printf("\n\n");
    }
}

int exist(reg art[30], int n, int codigoBusqueda, int &indice){
    int existe = 0;
    for(int i = 0; i < n; i++){
        if(art[i].codigo == codigoBusqueda){
            existe++;
            indice = i;
        }
    }

    return existe;
}

void mostrarSegunCodigo(reg art[30], int indice){

    system("cls");
    printf("Codigo: %d", art[indice].codigo);
    printf("\nCantidad Stock: %d", art[indice].cantidadStock);
    printf("\nPreico Unitario: %.2f", art[indice].precioUnitario);
    printf("\nDescripcion: %s", art[indice].descripcion);
    
    printf("\n");

}

void borrarArt(reg art[30], int n,int indice){
    int cantidadRegMov = n - indice;

    for(int i = indice; i < cantidadRegMov; i++){
        art[i] = art[i+1];
    }
}

void listarPorDescripcionDecreciente(reg art[30], reg artDec[30], int n){
    
    reg temporal;
    int bandera = 0, comparacion = 0;

    for(int i = 0; i < n; i++){
        artDec[i] = art[i];
    }

	do{
		bandera = 0;
		
		for(int i = 0; i < n; i++){
			for(int j = i+1; j < n; j++){
				comparacion = strcmp(artDec[i].descripcion, artDec[j].descripcion);
				
				if(comparacion == -1){
					temporal = artDec[i];
					artDec[i] = artDec[j];
					artDec[j] = temporal;
					bandera++;
				}
			}
		}
		
	}while(bandera == 1);


}



void listarPorStockCreciente(reg art[30], reg artCrec[30], int n){
    
    reg temporal;

    for(int i = 0; i < n; i++){
        artCrec[i] = art[i];
    }

    int bandera = 0;
    int comparacion = 0;

	do{
		bandera = 0;
		
		for(int i = 0; i < n; i++){
			for(int j = i+1; j < n; j++){
				if(artCrec[i].cantidadStock > artCrec[j].cantidadStock){
					temporal = artCrec[i];
					artCrec[i] = artCrec[j];
					artCrec[j] = temporal;
					bandera++;
				}
			}
		}
	
	}while(bandera == 1);
	
}

void listarTodosReg(reg art[30], int n){
    system("cls");
    for(int i = 0; i < n; i++){
        printf("Reg %d: ", i);
        printf("\nCod: %d", art[i].codigo);
        printf("\nCant Stock: %d", art[i].cantidadStock);
        printf("\nPrecio Unitario: %.2f", art[i].precioUnitario);
        printf("\nDescripcion: %s", art[i].descripcion);
        printf("\n\n");
    }
}
