typedef struct empleado 
{
	char *nombre;
	int edad;
	char genero;
	double salario;
	char depto;
	double horas;
	double ventas_hechas;
	double (*calcularPagos)(struct empleado*);
	void (*imprimir)(struct empleado*);
} Empleado_t;

struct empleado* ingresar_empleado();
struct empleado* ingresar_empleado_fijo();
struct empleado* ingresar_empleado_hora();
struct empleado* ingresar_empleado_comision();

double pago_empleado_fijo(struct empleado*);
double pago_empleado_hora(struct empleado*);
double pago_empleado_comision(struct empleado*);

void imprimir_empleados_titulos();
void imprimir_empleado_fijo(struct empleado*);
void imprimir_empleado_hora(struct empleado*);
void imprimir_empleado_comision(struct empleado*);