/*

Francisco Miguel Perez - 44190234
Dado un arreglo de N dimensiones de números enteros.
	a. Cargar el arreglo y mostrar y mostrar en pantalla los datos ingresados
	b. Ordenar el arreglo de menor a mayor y mostrar en pantalla los datos ordenados
	c. Ordenar el arreglo de mayor a menor y mostrar en pantalla los datos ordenados
	La función mostrar es una sola.

*/

#include<stdio.h>
#include<stdlib.h>

void cargarArray(int arreglo[100], int n);
void mostrarArray(int array[100], int n);
void ordenarBurbuja(int array[100], int n, int opc);

main(){
	int n, array[100];
	printf("Ingrese n: "); scanf("%d", &n);
	
	cargarArray(array, n);
	printf("\nOriginal: ");
	mostrarArray(array, n);
	
	printf("\nAscendente: ");
	ordenarBurbuja(array, n, 1);
	mostrarArray(array, n);

	printf("\nDescedente: ");	
	ordenarBurbuja(array, n, 2);
	mostrarArray(array, n);
}

void cargarArray(int arreglo[100], int n){
	printf("\n");
	for(int i = 0; i < n; i++){
		printf("Ingrese [ %d | %d ]: ", i, n);
		scanf("%d", &arreglo[i]);
	}
}

void mostrarArray(int array[100], int n){
	printf("\n");
	for(int i = 0; i < n; i++){
		printf("| %d | ", array[i]);
	}
	printf("\n");
}

void ordenarBurbuja(int a[],int N, int opc)
{
switch(opc){
	int i,j,aux;	
	case 1:
		for(i=0; i<N; i++)
		{
			for(j=i;j<N;j++)
			{
				if(a[i]>a[j])
				{
					aux=a[i];
					a[i]=a[j];
					a[j]=aux;
				}
			}		
		}	
	break;
	case 2:
		for(i=0; i<N; i++)
		{
			for(j=i;j<N;j++)
			{
				if(a[i]<a[j])
				{	
					aux=a[i];
					a[i]=a[j];
					a[j]=aux;
				}
			}
			
		}
	break;
	}
}
