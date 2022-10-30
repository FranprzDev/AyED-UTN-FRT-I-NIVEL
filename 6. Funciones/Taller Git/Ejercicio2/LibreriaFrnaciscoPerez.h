/* prototipos
int suma(int a, int b);
int resta(int a, int b);
int multiplicacion(int a, int b);
float division(int a, int b);	*/

// desarrollo

int suma(int a, int b){
	int resultado = a+b;
	return resultado;
}

int resta(int a, int b){
	int resultado = a-b;
	return resultado;
}
int multiplicacion(int a, int b){
	int resultado = a*b;
	return resultado;
}

float division(int a, int b){
	float resultado = 0;
	if(b != 0){
		resultado = (float) a/b;
	}else{
		resultado = 0;
	}
	return resultado;
}
