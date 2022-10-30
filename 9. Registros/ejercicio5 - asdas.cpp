/*


	   Universidad Tecnológica Nacional
		Facultad Regional de Tucumán
		
		Datos del alumno: 
		
		|	Francisco Miguel Perez
		|	DNI: 44190234
		|	Legajo: 56355
	
Una empresa registra los datos de sus vendedores en un registro y uno de su miembro es un arreglo (vector) 
que representa el monto de venta realizado por el vendedor de lunes a viernes. La estructura de dicho registro es la siguiente:
• Apellido y nombre
• Numero de documento
• Fecha Ingreso (o de contrato)
• Venta Semanal 


Defina el registro de vectores de manera apropiada según la descripción de los datos y por medio de un menú de opciones 
realizar las siguientes operaciones.
    a) Registrar como mínimo 5 empleados, sin registrar ventas.
    b) Registrar el total de venta al final del día. La registración se hará por medio de una función que reciba el apellido y nombre,
       el día de la venta (Lunes, martes,…, viernes), y el monto a registrar. (Si hubo un error porque apellido y nombre no figura 
       mostrar un mensaje indicando el error)
    c) Listar por pantalla las ventas de la semana y el monto total vendido por cada uno de los empleados. Observe el
    modelo de listado que debe realizar. (Para este tipo de listado, deberá investigar la máscara o formato que se
    aplica a los datos de salida).

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct fechaDeIng{
    int dia;
    int mes;
    int anio;
};

struct vendedores{
    char ApyNom[50];
    int documento;
    fechaDeIng fecha;
    float ventaSemanal[4];
    // De lunes a viernes -- Lunes: 0 Viernes: 4 {5 espacios en memoria}.
};

int menuOpciones();
void registrarEmpleados(vendedores vend[30], int n);
int compararSiExiste(vendedores vend[30], int n, char empleado[51]);
void cargarVentasSemanales(vendedores vend[30], int n, char empleado[51]);
void listarDatos(vendedores vend[30], int n);
void cambiarDatos(vendedores vend[30], int n, int dni, char dia[15], float monto, int indice);
int compararSiExisteDNI(vendedores vend[30], int n, int dni, int &indice);


main(){
    	
    vendedores vend[30];
    int cantidad = 0;
    float ventasTotalDia = 0;
    char comp[15];
    char Empleado[51];
    int indice = 0;
    int comparar = 0;
    int dniABusc = 0, compExist = 0;
    char aux1[15];
    float monto1 = 0;
	int clun, cmart, cmierc, cjuev, cvier;
	int band = 0;

    int opcion = menuOpciones(); 
    
    switch(opcion) {
        case 1:
            system("cls");
            do{
            	printf("\nIngrese la cantidad de vendedores que desea registrar: ");	
                scanf("%d", &cantidad);
                if(cantidad < 5) {
                	printf("\nTienes que ingresar mas de 5 vendedores. \n");
                	system("pause");
				}
            }while(cantidad < 5);

            registrarEmpleados(vend, cantidad);
            
            
            system("pause");
            printf("\n\n");
        	
        	opcion = menuOpciones();
        	
        break;
        
        case 2:
            system("cls");
            
            do{
                printf("\nIngrese un empleado: ");
                _flushall();
                gets(Empleado);
                // si existe devolverá 1;
                comparar = compararSiExiste(vend, cantidad, Empleado);
                if(comparar != 1) printf("\nNo se encontro el empleado...\n"); 
                
            }while(comparar != 1);
            
            // ya se que existe mi empleado...

            cargarVentasSemanales(vend, cantidad, Empleado);

			printf("\n\n");
			system("pause");
			
			opcion = menuOpciones();
			
        break;
        
        case 3:
        	
        	system("cls");
        	
            listarDatos(vend, cantidad);
            
            printf("\n\n");
            system("pause");
            
            opcion = menuOpciones();

        break;
        case 4:

            system("cls");

            do{
                printf("\nIngrese el DNI del empleado: ");
                scanf("%d", &dniABusc);
                compExist = compararSiExisteDNI(vend, cantidad, dniABusc, indice);
            }while(compExist != 1);

            do{
                _flushall();
                printf("\nIngrese el dia que desea cambiar: ");
                gets(aux1);
                clun   = strcmp(aux1, "lunes");
                cmart  = strcmp(aux1, "martes");
                cmierc = strcmp(aux1, "miercoles");
                cjuev  = strcmp(aux1, "jueves");
                cvier  = strcmp(aux1, "viernes");
            }while(clun != 0 || cmart != 0 || cmierc != 0 || cjuev != 0 || cvier != 0);

            printf("\nIngrese el monto que desea cambiar: ");
            scanf("%f", &monto1);
            
            cambiarDatos(vend, cantidad, dniABusc, aux1, monto1, indice);
            
            printf("\n\n");
            system("pause");
            
            opcion = menuOpciones();
            
        break;
        
        default:
        system("cls");
        printf("\n\nOpcion incorrecta, cerrando programa. \n");
        system("pause");
    }

}

int menuOpciones(){
    system("cls");
    printf("--- Menu Opciones ---\n");

    printf("1. Registrar como minimo 5 empleados, sin registrar ventas. \n");
    printf("2. Registrar las ventas segun un empleado, ingresando su nombre y apellido. \n");
    printf("3. Mostrar por pantallas la informacion \n");
    printf("4. Modificar los datos de la venta, ingresando Documento, dia a modificar y monto \n");

    int opc;

    printf("\nSu opcion: ");
    scanf("%d", &opc);

    return opc;
}


void registrarEmpleados(vendedores vend[30], int n){
    for(int i=0; i<n; i++){
        system("cls");
        printf("\nIngrese su apellido y nombre: ");
        _flushall();
        gets(vend[i].ApyNom);
        _flushall();
        printf("\nIngrese su documento: ");
        scanf("%d", &vend[i].documento);
        _flushall();


        printf("\nIngrese el dia de ingreso: ");
        scanf("%d", &vend[i].fecha.dia);
        _flushall();
        printf("\nIngrese el mes de ingreso: ");
        scanf("%d", &vend[i].fecha.mes);
        _flushall();
        printf("\nIngrese el anio de ingreso: ");
        scanf("%d", &vend[i].fecha.anio);
        _flushall();
        
    }
}

int compararSiExiste(vendedores vend[30], int n, char empleado[51]){
    int comp = -1;
    for(int i=0; i<n; i++){
        comp = strcmp(vend[i].ApyNom, empleado);
        if(comp == 0) i = n;
    }

    return 1;
}

void cargarVentasSemanales(vendedores vend[30], int n, char empleado[51]){
    char aux[15];
    float venta = 0.0;

    for(int i=0; i<n; i++){
        do{
            printf("\nIngrese el monto del dia lunes (para confirmar escriba 'lunes'): ");
            scanf("%s", &aux);
        }while(strcmp("lunes", aux) != 0);

        printf("\nIngrese la venta del lunes: ");
        scanf("%f", &venta);
        vend[i].ventaSemanal[0] = venta;

        do{
            printf("\nIngrese el monto del dia martes (para confirmar escriba 'martes'): ");
            scanf("%s", &aux);
        }while(strcmp("martes", aux) != 0);
    
        printf("\nIngrese la venta del martes: ");
        scanf("%f", &venta);
        vend[i].ventaSemanal[1] = venta;

        do{
            printf("\nIngrese el monto del dia miercoles (para confirmar escriba 'miercoles'): ");
            scanf("%s", &aux);
        }while(strcmp("miercoles", aux) != 0);
    
        printf("\nIngrese la venta del miercoles: ");
        scanf("%f", &venta);
        vend[i].ventaSemanal[2] = venta;

        do{
            printf("\nIngrese el monto del dia jueves (para confirmar escriba 'jueves'): ");
            scanf("%s", &aux);
        }while(strcmp("jueves", aux) != 0);
    
        printf("\nIngrese la venta del jueves: ");
        scanf("%f", &venta);
        vend[i].ventaSemanal[3] = venta;

        do{
            printf("\nIngrese el monto del dia viernes (para confirmar escriba 'viernes'): ");
            scanf("%s", &aux);
        }while(strcmp("viernes", aux) != 0);
    
        printf("\nIngrese la venta del viernes: ");
        scanf("%f", &venta);
        vend[i].ventaSemanal[4] = venta;
    
    } // cierre for
} // cierre funcion


void listarDatos(vendedores vend[30], int n){
	
	float total = 0.0;
    printf("--- Lista de datos ---\n");
    printf("N: \t Documento: \t Apellido y Nombre \t Lunes \t Martes \t Miercoles \t Jueves \t Viernes \t Total");
    for(int i=0; i<n; i++){
        total = (float) vend[i].ventaSemanal[0] + vend[i].ventaSemanal[1] + vend[i].ventaSemanal[2] + vend[i].ventaSemanal[3] + vend[i].ventaSemanal[4];
        printf("%d: \t %d \t %s \t %.2f \t %.2f \t %.2f \t %.2f \t %.2f \t %f \n", i, vend[i].documento, vend[i].ApyNom, vend[i].ventaSemanal[0], vend[i].ventaSemanal[1], vend[i].ventaSemanal[2], vend[i].ventaSemanal[3], vend[i].ventaSemanal[4], total);
    }

    printf("\n\n");
    printf("================================");
    printf("\n\n");
}

void cambiarDatos(vendedores vend[30], int n, int dni, char dia[15], float monto, int indice){
    
    int index = 0;

    if(strcmp(dia, "lunes") == 0) index = 0;
    if(strcmp(dia, "martes") == 0) index = 1;
    if(strcmp(dia, "miercoles") == 0) index = 2;
    if(strcmp(dia, "jueves") == 0) index = 3;
    if(strcmp(dia, "viernes") == 0) index = 4;

    vend[indice].ventaSemanal[index] = monto;
    
}

int compararSiExisteDNI(vendedores vend[30], int n, int dni, int &indice){
    int encontro = 0;
    for(int i=0; i<n; i++){
        if(vend[i].documento == dni){
            encontro++;
            indice = i;
        } 
    }

    return encontro;
}
