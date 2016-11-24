#include <stdio.h>
#include "empleado.c"

struct empleado* nuevo_empleado();
void imprimir_planilla(struct empleado *empleados[],int cant);

int main(int argc, char const *argv[])
{
	int cont=0;
	struct empleado *empleados[100];
	do{
		printf("%s\n%s\n","1. Ingresar Empleado","2. Imprimir Planilla");
		int opt;
		scanf("%d",&opt);
		getchar();
		switch(opt)
		{
			case 1:
				empleados[cont++] = nuevo_empleado();
			break;
			case 2:
				imprimir_planilla(empleados,cont);
			break;
		}
	}while(1);

	return 0;
}

struct empleado* nuevo_empleado()
{
	int tipo;
	printf("%s\n%s\n%s\n","1. Fijo","2. Hora","3. Comision"); 
	scanf("%d",&tipo);
	getchar();
	switch(tipo)
	{
		case 1: return ingresar_empleado_fijo();
		case 2: return ingresar_empleado_hora();
		case 3: return ingresar_empleado_comision();
	}
}

void imprimir_planilla(struct empleado *empleados[],int cant)
{
	imprimir_empleados_titulos();
	for (int i = 0; i < cant; ++i)
	{
		empleados[i]->imprimir(empleados[i]);
	}
}