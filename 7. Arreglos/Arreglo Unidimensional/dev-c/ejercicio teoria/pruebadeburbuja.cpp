#include<stdio.h>
main (void)
{
int n,i,a[50],aux,b;
printf("Ingrese el orden del vector: ");
scanf("%d",&n);
for (i=0;i<n;i++)
{
printf("\n a[%d]= ",i);
scanf("%d",&a[i]);
}
do
{
b=0;
for (i=0;i<n-1;i++)
{
if (a[i]>a[i+1])
{
aux=a[i];
a[i]=a[i+1];
a[i+1]=aux;
b=1;
}
}
}
while (b==1);
printf("\nEl vector ordenado es:\n");
for(i=0;i<n;i++)
{
printf("\n a[%d]= %d\n",i,a[i]);
}
}
