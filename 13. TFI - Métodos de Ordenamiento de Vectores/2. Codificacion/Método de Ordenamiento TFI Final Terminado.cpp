#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include "libreria.h"

/*
Universidad Tecnologica Nacional
Facultad regional de Tucuman

Ingenieria en sistemas de información
Algoritmo y estructura de datos

Autores:
	Perez Francisco Miguel, 56355
		FranciscoMiguel.Perez@alu.frt.utn.edu.ar 

	Rosconi Ignacio Federico, 52685
		Ignacio.Rosconi@alu.frt.utn.edu.ar

	Pastrana Angel Daniel,53379
		Angel.Pastrana@alu.frt.utn.edu.ar

	Gerez Braian Esteban Nicolas, 48301
		Braian.Gerez@alu.frt.utn.edu.ar

	Paez Oscar Ignacio, 52396
		Oscar.Paez@alu.frt.utn.edu.ar 

*/

const int TAMANO=999;

// Uso de colores para mejor ambientación.
// Colores Normales....
#define color SetConsoleTextAttribute
HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

/*
	Prototipo de Funciones...
	 1º -> Carga & Mostrar Vector
	 2º -> Menú
	 3º -> Sub-Menus
	 4º -> Usados para texto.
*/

void CargaManualVector(int vec[TAMANO], int tope);
void MostrarVector(int v[TAMANO], int N);

int Menu();


int submenua();
int submenub();
int submenuc();
int submenud();
int submenue();

void antOrdenadoVect(int v[TAMANO], int N);
void subMenuText(int opc);

/*
	-- Inicio del Main -- 
*/

int main()
{
// Opciones
	int opc=0;
    int opca=0;
    int opcb=0;
    int opcc=0;
    int opcd=0;
    int opce=0;
    
	int vector[TAMANO]={0};
	int N = 0;
	printf("Ingrese N: ");
	scanf("%d", &N);
	printf("\nIngrese los datos del vector: \n");
	CargaManualVector(vector, N);
   
do{
	system("cls");
	opc = Menu();

	switch (opc)
		{
			case 1:
			{  
			opca=submenua();
			 
			   switch(opca)
			    {
			   	 case 1:
					{
					system("cls");
							antOrdenadoVect(vector, N);
	                        ordenarAscendenteBurbuja(vector,N);
	                        printf("\n");	
	                        color(hConsole, 2);
		                    printf("Ordenado de forma ascendente (Intercambio o burbuja mejorada): \n\t\t");
		                    color(hConsole, 7);
		                    printf("\n");
		                    color(hConsole, 6);
	                        imprimirBurbuja(vector,N);
	                        color(hConsole, 7);
				   		    break;
			   		}
			   	  case 2:
					  {
				 	system("cls");	
							antOrdenadoVect(vector, N);
	                        ordenarDescendenteBurbuja(vector,N);
	                        printf("\n");
	                        color(hConsole, 4);
	                        printf("Ordenado de forma descendente (Intercambio o burbuja mejorada): \n\t\t");
	                        color(hConsole, 7);
	                      	printf("\n");
	                      	color(hConsole, 6);
	                     	imprimirBurbuja(vector,N);
	                     	color(hConsole, 7);
			   				break;
		   	          }
			    }
			  break;
			 } 
	    break; // fin case 1 switch global - burbuja mejorada
			case 2: 
			{
			opcb=submenub();
			
				switch(opcb)
				{
					case 1:
					{
	 				system("cls");	
							antOrdenadoVect(vector, N);
	                        MetodoInsercion(vector,N);
	                        printf("\n");
	                        color(hConsole, 2);
	                        printf("Ordenado de forma ascendente (Insercion o metodo de la baraja): ");
	                        color(hConsole, 7);
							printf("\n\n");
							color(hConsole, 6);
	                        imprimirMetodoInserccion(vector,N,1);
	                        color(hConsole, 7);
							break;
					}
					case 2:
					{
				 	system("cls");	
							antOrdenadoVect(vector, N);
	                        MetodoInsercion(vector,N);
	                        printf("\n");
	                        color(hConsole, 4);
	                        printf("Ordenado de forma descendente (Insercion o metodo de la baraja): \n\t\t");
	                        color(hConsole, 7);
		                    printf("\n");
		                    color(hConsole, 6);
		                    imprimirMetodoInserccion(vector,N,2);
		                    color(hConsole, 7);
							break;
					}	
				}
			 break;
			}
		break;	// fin case 2 global - insercción
			case 3: 
			{
				opcc=submenuc();
			
				switch(opcc)
				{
					case 1:
					{
					system("cls");
							antOrdenadoVect(vector, N);
                            metodoPorSeleccion(vector, N);
                            printf("\n");
                            color(hConsole, 2);
	                        printf("Ordenado de forma ascendente (Seleccion o metodo sencillo): \n\t\t");
	                        color(hConsole, 7);
                            printf("\n");
                            color(hConsole, 6);
	                        imprimirSeleccion(vector,N,1);
							color(hConsole, 7);	
							break;
	           		}
					case 2:
						{
					system("cls");
 							antOrdenadoVect(vector, N);
                            metodoPorSeleccion(vector, N);
                            printf("\n");
                            color(hConsole, 4);
	                        printf("Ordenado de forma descendente Seleccion o metodo sencillo): \n\t\t");
	                        color(hConsole, 7);
	                        printf("\n");
	                        color(hConsole, 6);
	                        imprimirSeleccion(vector,N,2);
	                        color(hConsole, 7);
							break;
				        }    
				}
			 break;
			}
		break; // fin case 3 global - método de selección
			case 4:
			 {
			 	opcd=submenud();

				  switch(opcd)
				  {
					case 1:
						{
					system("cls");
						   antOrdenadoVect(vector, N);
                           qs(vector,N);
                           printf("\n");
                           printf("Ordenado de forma ascendente (Rapido o QuickSort): \n\t\t");
                           printf("\n");
                           color(hConsole, 6);
                           imprimirQuickSort(vector,N,1);
                           color(hConsole, 7);
						   break;	
					    }	    
					case 2:
						{
					system("cls");
							antOrdenadoVect(vector, N);
                            qs(vector,N);
                            printf("\n");
                            printf("Ordenado de forma descendente (Rapido o QuickSort): \n");
                            printf("\n");
                            color(hConsole, 6);
                            imprimirQuickSort(vector,N,2);
                            color(hConsole, 7);
							break;
					    }	
		          }   
			  break;
	       	 }
		break;	// fin de quicksort
			case 5: 
			{
				opce=submenue();
		
				 switch(opce)
				 {
					case 1:
						{
						system("cls");		
							antOrdenadoVect(vector, N);
							
                            ms(vector,N);
                            printf("\n");

                            printf("Ordenado de forma ascendente  (Mezcla o MergeSort): \n");
                            
                            printf("\n");
                            imprimirMergeSort(vector,N,1);
							break;
					    } 
					case 2: 
					  {
					 	system("cls");
							antOrdenadoVect(vector, N);
							
                            ms(vector,N);
                            printf("\n");
                            
                            printf("Ordenado de forma descendente (Mezcla o MergeSort): \n");
                            
                            printf("\n");
                            imprimirMergeSort(vector,N, 2);

						break;
			          }
				 }			
			   break;
		    }
			case 6:
			{
				system("CLS");
				printf("Ingrese N: ");
				scanf("%d", &N);
				printf("\nIngrese los datos del vector: \n");
				CargaManualVector(vector, N);
				break;
			}

			case 0:
			 {
			 	color(hConsole, 4);
				printf("Salir del Programa...");
				color(hConsole, 7);
				break;
			}
		    default: 
			 {
			 	 color(hConsole, 4);
				 printf("Opcion incorrecta...");
				 color(hConsole, 7);
				 break;
		     }
		} // fin del switch global
	    printf("\n\n");
		system("pause");
	} while ( opc != 0);
		
}
	// FIN MAIN 
	
// Desarrollo de funciones

void CargaManualVector(int vec[TAMANO], int tope)
{
	int numero = 0;
// Recorrer el vector de forma lineal de izquierda a derecha para poder ir haciendo la lectura.	
	for (int i=0; i<tope; i++)
	{
		printf("Ingrese vec [%d/%d]: ", i+1,tope);
		scanf("%d", &numero);
		vec[i] = numero;
	}
}

// Función dedicada a mostrar el vector.

void MostrarVector(int v[TAMANO], int N)
{
	for (int i=0; i<N; i++)
	{
		printf("%d  ", v[i]);
	}
}

// Menú Principal con todos los métodos

int Menu()
{
	int opcion = 0;
	color(hConsole, 15);
	printf("\tM E N U P R I N C I P A L");
	color(hConsole, 7);
	printf("\n\t------------------------\n");
	color(hConsole, 9);
	printf("\n1- Intercambio o burbuja mejorada");
	color(hConsole, 12);
	printf("\n2- Insercion o metodo de la baraja");
	color(hConsole, 2);
	printf("\n3- Seleccion o metodo sencillo");
	color(hConsole, 8);
	printf("\n4- Rapido o QuickSort");
	color(hConsole, 6);
	printf("\n5- Mezcla o MergeSort");
	color(hConsole, 7);
	printf("\n6- Generar otro vector");
	color(hConsole, 4);
	printf("\n0- Salir");
	color(hConsole, 7);
	printf("\n\nOpcion: ");
	scanf("%d", &opcion);
	
	return opcion;
}


// SubMenú - Texto con colores
void subMenutext(int opc){
	system("CLS");
	color(hConsole, 15);
	printf("\tS U B M E N U");
	
	switch(opc){
		case 1:
			color(hConsole, 9);
			printf("\n       Burbuja Mejorada");	
			break;
		case 2:
			color(hConsole, 12);
			printf("\n     Metodo de la Baraja");
			break;
		case 3:
			color(hConsole, 2);
			printf("\n\t  Selección");
			break;
		case 4:
			color(hConsole, 8);
			printf("\n\t  QuickSort");
			break;
		case 5:
			color(hConsole, 6);
			printf("\n\t MergeSort");
			break;
	}
	
	color(hConsole, 7);
	printf("\n   ------------------------\n");
	printf("\nOrdenar de forma: ");
	color(hConsole, 10);
    printf("\n1- Ascendente");
 	color(hConsole, 4);
	printf("\n2- Descendente");
	color(hConsole, 7);
	printf("\n0- Salir");
}

// SubMenú Burbuja Mejorada

int submenua()
{
	int opciona=0;
	subMenutext(1);
	printf("\n\nOpcion: ");
	scanf("%d", &opciona);
	return opciona;
}

// SubMenú Baraja

int submenub()
{
	int opcionb=0;
	
	subMenutext(2);
	printf("\n\nOpcion: ");
	scanf("%d", &opcionb);
	return opcionb;
}

// SubMenú Selección

int submenuc()
{
	int opcionc=0;
	
	subMenutext(3);
	printf("\n\nOpcion: ");
	scanf("%d", &opcionc);
	return opcionc;
}

// SubMenú QuickSort

int submenud()
{
	int opciond=0;
	
	subMenutext(4);
	printf("\n\nOpcion: ");
	scanf("%d", &opciond);
	return opciond;
}

// SubMenú MergeSort

int submenue()
{
	int opcione=0;	
	subMenutext(5);
	printf("\n\nOpcion: ");
	scanf("%d", &opcione);
	return opcione;
}

//

void antOrdenadoVect(int vector[], int N){
	color(hConsole, 7);
	printf("Contenido del vector\n\n");
	color(hConsole, 14);
	MostrarVector(vector, N); 
	printf("\n");
	color(hConsole, 7);
}
