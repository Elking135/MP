#ifndef Inicio
#define Inicio
typedef int (*FuncionContrasena)(const char *, char *);         // Tipo de puntero a función para las funciones de contraseña

void inicio_sesion();

int email_archivo(const char *, const char *, char *);

int contrasena_cliente(const char *, char *);

int contrasena_transportista(const char *, char *);

int contrasena_AdminProv(const char *, char *);

int f_email(FILE *, const char *, char *, FuncionContrasena );

int buscar_linea_cliente(const char *, const char *, const char *, char *);

void cartera(char *, char *, float );

void listar_productos();

void manejar_opciones_usuario(int, const char *, const char *);

void listar_productos_con_id(const char *);


#endif // Inicio
