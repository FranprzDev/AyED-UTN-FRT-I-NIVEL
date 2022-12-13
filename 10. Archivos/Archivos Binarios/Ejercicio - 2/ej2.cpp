/*
Al iniciar el programa el sistema deberá abrir para su escritura, 
sin perder los datos ya guardado, el archivo numeros.dat, 
en caso de que no exista el archivo deberá crear el archivo numeros.dat y almacenar
(guardar) la cantidad de 276 números enteros comprendido entre el rango 
de valores [125…789] los cuales serán generados de manera aleatoria.
Creado o abierto el archivo, realizar un menú que permita mostrar en la función
main con la siguiente información:
    • Determinar cuántos valores pares e impares están guardado en el archivo.
    • Listar el archivo.
    • Agregar un número no determinado de nuevos Datos. Verificando que el valor ingresado
    sea un entero.
    • Ingresar por teclado un valor y determinar si está almacenado (guardado) en el archivo.
    Enviar un mensaje en pantalla indicando si fue encontrado o no el valor.
    • Determinar cuántos valores están en el rango [125…500] y (500…789].
    
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void cargarArchivo(FILE *numeros);
int menu();
int contarPar(FILE *numeros);
int contarImpar(FILE *numeros);
void agregarDato(FILE *numeros);
void ListarArchivo(FILE *numeros);
int seEncontro(FILE *numeros, int numABuscar);
int cantidadDeValoresPrimario(FILE *numeros, int &contadorSecundario);

main(){
    FILE *numeros;

    numeros = fopen("numeros.dat", "r+b");

    if(numeros == NULL){
        numeros = fopen("numeros.dat", "w+b");
        cargarArchivo(numeros);
        if(numeros == NULL){
            printf("El archivo no se pudo crear...");
            exit(1);
        }
    }

    int opc = 0;
    int contPar, contImpar;
    int band = 0;
    int opcionAgregar;
    int numABuscar = 0;
    int encontrado = 0;
    int contadorSecundario = 0;
    int contPrim = 0;
    opc = menu();
    int b = 0; 
    do{
        switch(opc){
            case 1:
                system("cls");
                contPar = contarPar(numeros);
                contImpar = contarImpar(numeros);

                printf("Hay una cantidad de: %d de numeros pares.", contPar);
                printf("\nHay una cantidad de: %d de numeros impares.", contImpar);

				printf("\n");
				system("pause");
                opc = menu();
            break;
            case 2:
                do{
                    system("cls");
                    printf("Quiere agregar un dato: \n");
                    printf("1. Si \t\t 2- No \nSu opcion: ");

                    scanf("%d", &opcionAgregar);

                    agregarDato(numeros);
                    
                }while(band == 1);

                opc = menu();
            break;
            case 3:
                system("cls");

                ListarArchivo(numeros);

                opc = menu();
            break;
            case 4:
                system("cls");
                printf("Ingrese un valor: ");

                scanf("%d", &numABuscar);

                encontrado = seEncontro(numeros, numABuscar);

                if(encontrado == 1){
                    printf("\nEl numero se encontro.");
                }else{
                    printf("\nEl numero no se encontro.");
                }
                
                printf("\n");
                system("pause");
                
                opc = menu();
            break;
            case 5:
                system("cls");
                contadorSecundario = 0;
                contPrim = cantidadDeValoresPrimario(numeros, contadorSecundario);

                printf("En el rango [125-500] hay un total de %d numeros", contPrim);
                printf("\nEn el rango [500-789] hay un total de %d numeros", contadorSecundario);

                printf("\n\n");
                
                system("pause");
                
                opc = menu();
            break;
            case 6:
                system("cls");
                printf("\nSaliendo...");
                b = 6; 
            break;    
            default:
                system("cls");
                printf("\nError saliendo del programa...");
                b = 6; 
            break;
        }
    }while(b != 6);



    fclose(numeros);
}

void cargarArchivo(FILE *numeros){
    int numRandom = 0;
    
    rewind(numeros);

    numRandom = rand() % 790 + 125;
    
    fwrite(&numRandom, sizeof(int), 1, numeros);

    for(int i = 0; i < 275; i++){
        numRandom = rand() % 790 + 125; //789+1 n+1

        fwrite(&numRandom, sizeof(int), 1, numeros);

     }
    // cargo en rango [125…789]
}

int menu(){
    int opc;
    system("cls");

    printf("1. Determinar valores pares e impares del archivo. \n");
    printf("2. Agregar un numero no determinado de nuevos Datos.\n");
    printf("3. Listar archivo.\n");
    printf("4. Ingresar un valor y saber si esta almacenado.\n");
    printf("5. Determinar valores entre [125 a 500] y [500 a 789].\n");
    printf("6. Salir \n");

    printf("\n\nSu opcion: ");
    scanf("%d", &opc);


    return opc;
}

int contarPar(FILE *numeros){
    int numero = 0;
    int contPar = 0;

    rewind(numeros);
	
    fread(&numero, sizeof(int), 1, numeros);
	
	while(!feof(numeros)){
	    if(numero % 2 == 0){
		    contPar++;
		}
		
    	fread(&numero, sizeof(int), 1, numeros);
	}

    return contPar;
}

int contarImpar(FILE *numeros){
    int numero = 0;
    int contImpar = 0;

    rewind(numeros);

    fread(&numero, sizeof(int), 1, numeros);

	while(!feof(numeros)){
	    if(numero % 2 != 0){
		    contImpar++;
		}
		
    	fread(&numero, sizeof(int), 1, numeros);
	}

    return contImpar;
}

void agregarDato(FILE *numeros){
    rewind(numeros);
    int numero = 0;

    printf("\nIngrese su numero: ");

    scanf("%d", &numero);

    fseek(numeros, 0, SEEK_END);
    fwrite(&numero, sizeof(int), 1, numeros);
    printf("\nNumero cargado correctamente. ");

    printf("\n\n");
}

void ListarArchivo(FILE *numeros){
    system("cls");

    printf("Listado del archivo... \n");

    int numero = 0;
    int contador = 0;
    rewind(numeros);
    
    fread(&numero, sizeof(int), 1, numeros);

    while(!feof(numeros)){
		contador++;
        printf("%d - %d \n", contador, numero);

        fread(&numero, sizeof(int), 1, numeros);
		
    }

    printf("\n\n");

    system("pause");

    system("cls");
}

int seEncontro(FILE *numeros, int numABuscar){
    int numero = 0;
    int seEncontro = 0;

	rewind(numeros);
	
    fread(&numero, sizeof(int), 1, numeros);

    while(!feof(numeros)){
        if(numero == numABuscar){
            seEncontro++;
            break;
			//fseek(numeros, 0, SEEK_END);
            // con esto sale del while
            // se podría usar la instruccion break
        }
        
    	fread(&numero, sizeof(int), 1, numeros);
    }

    return seEncontro;
}

int cantidadDeValoresPrimario(FILE *numeros, int &contadorSecundario){
    int numero = 0;
    int contadorPrimario = 0;
    
    rewind(numeros);

    fread(&numero, sizeof(int), 1, numeros);

    while(!feof(numeros)){
        if(numero >= 125 && numero <= 500){
            contadorPrimario++;
        }else{
            contadorSecundario++;
        }
        
    	fread(&numero, sizeof(int), 1, numeros);
    }

    return contadorPrimario;
}