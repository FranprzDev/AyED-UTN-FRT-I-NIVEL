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
#include<stdio.h>
#include<stdlib.h>

//	Comienzo de Método Intercambio o Burbuja Mejorada

void ordenarAscendenteBurbuja(int a[],int N)
{
	int i,j,aux;
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
}

void ordenarDescendenteBurbuja(int a[],int N)
{
	int i,j,aux;
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
	
	
}

void imprimirBurbuja(int x[], int N){
	for(int i=0;i<N;i++)
	{
	printf("%i, ",x[i]);
	}
}

//	Final del Método de  Intercambio o Burbuja Mejorada

//

//	Comienzo del Método Inserción o Método de la baraja

void MetodoInsercion(int a[],int N)
{
	int i,pos,aux;
	for(i=0; i<N; i++)
	{
		pos=i;
		aux=a[i];
		while((pos>0)&&(a[pos-1] > aux))
		{
			a[pos]=a[pos-1];
			pos--;	
		}			
			a[pos]=aux;	
	}	
}

void imprimirMetodoInserccion(int x[], int N, int opcion){
	switch(opcion){
		case 1:
			for(int i=0;i<N;i++)
			{ printf("%i, ",x[i]); }	
		break;
		case 2:
			for(int j=N-1;j>=0;j--)
			{ printf("%i, ",x[j]); }
		break;
	}
}
	
// Final Método de Insercción o de la Baraja.
 
//

// Comienzo de Método Selección o Método sencillo

void metodoPorSeleccion(int a[], int N)
{
	
	int i,j,auxiliar,minimo;
	
	for(i=0;i<N;i++){
		minimo=i;
		for(j=i+1;j<N;j++){
			
		    if(a[j] < a[minimo]){
			  minimo=j;
	    	}
	  	}
		auxiliar= a[i];
		a[i] = a[minimo];
		a [minimo] =auxiliar;  
	}
   
}

void imprimirSeleccion(int x [],int N, int opcion){
	switch(opcion){
		case 1:
	    for(int i=0;i<N;i++)
		{ printf("%i, ",x[i]); }
		break;
		case 2:
    	for(int i=N-1;i>=0;i--)
		{ printf("%i, ",x[i]); }
		break;
	}	
}

// Final de Método Selección o método sencillo

//

// Comienzo de Método Rápido o QuickSort

void metododeQuickSort(int a[ ],int limiteizquierda, int limitederecha)
{
	
		int pivote,izquierda,derecha,auxiliar;
		
		izquierda=limiteizquierda;
		derecha=limitederecha;
		pivote=a[(izquierda+derecha)/2];
		
		do
		{
			while(a[izquierda]<pivote && izquierda<limitederecha) izquierda++;
			while(pivote<a[derecha] && derecha> limiteizquierda) derecha--;

// Comparación entre los límites del arreglo.
			
			if(izquierda<=derecha)
			{
				auxiliar=a[izquierda];
				a[izquierda]=a[derecha];
				a[derecha]=auxiliar;
				izquierda++;
				derecha--;	
			}
			
		}while(izquierda<=derecha);
		
		if(limiteizquierda<derecha){ metododeQuickSort(a,limiteizquierda,derecha); }
		
		
		if(limitederecha>izquierda){ metododeQuickSort(a,izquierda,limitederecha); }
		
}

void qs(int a[],int N)
{
	metododeQuickSort(a,0,N-1);
}


void imprimirQuickSort(int x[],int N, int opcion){
	switch(opcion){
		case 1:
		    for (int i=0; i<N; i++) 
			{ printf("%i, ",x[i]); }	
	break;
		case 2:
		    for (int i=N-1; i>=0; i--)
			{ printf("%i, ",x[i]); }
	break;
	}
}

// Final Método Rápido o Método QuickSort

//

// 	Comienzo de Método Mezcla o Método MergeSort

void mezcla(int a[],int inicio,int mitad,int final)
{
	int i,j,k;
	int elementosizquierda=mitad-inicio+1;
	int elementosderecha=final-mitad;
	
	int vectorizquierda[elementosizquierda];
	int vectorderecha[elementosderecha];
	
	for(i=0;i<elementosizquierda;i++)
	{
		vectorizquierda[i]=a[inicio+i];
	}
	
	for(j=0;j<elementosderecha;j++)
	{
		vectorderecha[j]=a[mitad+1+j];
	}
	
	i=0;
	j=0;
	k=inicio;
	
	while(i<elementosizquierda && j<elementosderecha)
	{
		if(vectorizquierda[i] <= vectorderecha[j])
		{
			a[k]=vectorizquierda[i];
			i++;
		}
		else
		{
				a[k]=vectorderecha[j];
				j++;
		}
		k++;
	}
	
	while(j<elementosderecha)
	{
		a[k]=vectorderecha[j];
		j++;
		k++;
	}
	while(i<elementosizquierda)
	{
		a[k]=vectorizquierda[i];
		i++;
		k++;
	}
}


void metododeMergeSort(int a[ ],int inicio, int final)
{
	if (inicio < final)
	{
		int mitad=inicio+(final-inicio)/2; 
		
		metododeMergeSort(a,inicio,mitad);
		
		metododeMergeSort(a,mitad+1,final);
		
		mezcla(a,inicio,mitad,final);	
	}
}

void ms(int a[],int N){	metododeMergeSort(a,0,N-1); }


// Opc 1 = Ascendente.
// Opc 2 = Descendente.
void imprimirMergeSort(int a[],int N, int opc){
	switch(opc){
		case 1:
			for (int i=0; i<N; i++)
			{ printf("%i, ",a[i]); }
		break;
		case 2:
			for (int i=N-1; i>=0; i--)
			{ printf("%i, ",a[i]); }
		break;
	}
}
// Final Método de Mezcla o Método MergeSort
