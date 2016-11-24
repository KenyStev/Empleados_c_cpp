#include <stdio.h>
#include <stdlib.h>
#include "empleado.h"

char* getString()
{
	char *arr = malloc(256);
	gets(arr);
	return arr;
}

struct empleado* ingresar_empleado()
{
	Empleado_t *e = malloc(sizeof(struct empleado));
	printf("Ingrese Nombre: ");
	e->nombre = getString();
	printf("Ingrese Edad: ");
	scanf("%d", &e->edad);
	getchar();
	printf("Ingrese Genero(M/F): ");
	e->genero = getchar();
	getchar();
	return e;
}

struct empleado* ingresar_empleado_fijo()
{
	struct empleado *e = ingresar_empleado();
	printf("Ingrese Salario: ");
	scanf("%lf",&e->salario);
	getchar();
	e->calcularPagos = pago_empleado_fijo;
	e->imprimir = imprimir_empleado_fijo;
	return e;
}

struct empleado* ingresar_empleado_hora()
{
	struct empleado *e = ingresar_empleado();
	printf("Ingrese Depto (A|B|C): ");
	e->depto = getchar();
	printf("Ingrese Horas: ");
	scanf("%lf",&e->horas);
	getchar();
	e->calcularPagos = pago_empleado_hora;
	e->imprimir = imprimir_empleado_hora;
	return e;
}

struct empleado* ingresar_empleado_comision()
{
	struct empleado *e = ingresar_empleado();
	printf("Ingrese Depto (A|B|C): ");
	e->depto = getchar();
	printf("Ingrese Ventas: ");
	scanf("%lf",&e->ventas_hechas);
	getchar();
	e->calcularPagos = pago_empleado_comision;
	e->imprimir = imprimir_empleado_comision;
	return e;
}

double pago_empleado_fijo(struct empleado*e)
{
	return e->salario;
}

double pago_empleado_hora(struct empleado*e)
{
	switch(e->depto)
	{
		case 'A': return 18*e->horas;
		case 'B': return 15*e->horas;
		case 'C': return 20*e->horas;
	}
}

double pago_empleado_comision(struct empleado*e)
{
	switch(e->depto)
	{
		case 'A': return 0.2*e->ventas_hechas;
		case 'B': return 0.1*e->ventas_hechas;
		case 'C': return 0.05*e->ventas_hechas;
	}
}



void imprimir_empleados_titulos()
{
	printf("Nombre\tTipo\t\tPago\n");
}

void imprimir_empleado_fijo(struct empleado*e)
{
	printf("%s\t%s\t%f\n",e->nombre,"Fijo", e->calcularPagos(e));
}

void imprimir_empleado_hora(struct empleado*e)
{
	printf("%s\t%s\t%f\n",e->nombre,"Hora", e->calcularPagos(e));
}

void imprimir_empleado_comision(struct empleado*e)
{
	printf("%s\t%s\t%f\n",e->nombre,"Comision", e->calcularPagos(e));
}