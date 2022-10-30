#include<stdio.h>
#include<math.h>
#include<stdlib.h>

void porcentajespares(float par, float &ppar, float suma)
{
	ppar = (float) par*100/suma;
}

float promimp(float imp, float c, float prom, float n)
{
	prom = imp/c;
	return prom;
}
main(){
	
	float n, imp=0, par=0, l, c=0, prom=0, suma, ppar = 0, tmp, k;
	
	printf("N: ");
	scanf("%f", &n);
	l = fmod(n, 2);
	while(n != 0){
		if(l == 0){
			par++;	
		}
		else{
			if(l == 1){
				imp = imp + n;
				c++;	
			}	
		}
	
		printf("N: ");
		scanf("%f", &n);
		l = fmod(n, 2);
	}
	
	suma = par + c; 
	porcentajespares(par, ppar, suma);
	printf("Porcentaje de pares: %.2f", ppar);
	printf("\nPromedio de impares: %.1f", promimp(imp, c, prom, n));	
}
