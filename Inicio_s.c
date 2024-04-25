#include <stdio.h>
#include <string.h>
#include "Inicios.h"
#define LONGITUD_EMAIL 30
#define LONGITUD_CONTRASENA 15
#define LONGITUD_LINEA 200
#include "Administrador.h"
#include "Transportista.h"
#include "Proveedor.h"
#include "Cliente.h"
#include "Eleccion.h"

//Cabecera void inicio_sesion()
//Precondicion archivos de usuarios cargados y las constantes LONGITUD_EMAIL y LONGITUD_CONTRASENA definidas
//Postcondicion verifica el email y la contrasena, y se llama a manejar_opciones_usuario si son correctas, o se muestra un mensaje si no lo son
void inicio_sesion() {
    int p;
    char id[4];
    float cantidad;
    char email[LONGITUD_EMAIL];
    char password[LONGITUD_CONTRASENA];
    char passwordFromFile[LONGITUD_CONTRASENA];
    int archivoEncontrado = 0; //este entero tiene el valor: 0: no encontrado, 1: Clientes.txt, 2: Proveedor en AdminProv.txt, 3: Transportistas.txt, 4: Administrador en Adminprov.txt

    printf("Introduce tu correo electronico o escribe 'exit' para salir: ");
    fgets(email, LONGITUD_EMAIL, stdin);
    email[strcspn(email, "\n")] = '\0'; // Elimina salto de línea

    if (strcmp(email, "exit") == 0) {
        puts("De acuerdo, programa finalizando...");
        exit(0);
    }

    archivoEncontrado = email_archivo("Clientes.txt", email, passwordFromFile);
    if (archivoEncontrado == 0) {
        archivoEncontrado = email_archivo("AdminProv.txt", email, passwordFromFile);
        if (archivoEncontrado == 2) { // Si se encontró en AdminProv.txt, verificar "ESIZON"
            archivoEncontrado = (strstr(passwordFromFile, "ESIZON") != NULL) ? 4 : 2;
        }
    }
    if (archivoEncontrado == 0) {
        archivoEncontrado = email_archivo("Transportistas.txt", email, passwordFromFile);
    }

    if (archivoEncontrado != 0) {
        printf("Correo electronico encontrado. Introduce tu contrasena: ");
        scanf("%s", password);
        fflush(stdin);

        // Verifica si la contraseña es correcta.
        if (strcmp(password, passwordFromFile) == 0)
            manejar_opciones_usuario(archivoEncontrado, email, password);
         else {
            puts("Contrasena incorrecta");
            inicio_sesion();
        }
    } else {
        puts("Correo electronico no encontrado");
        inicio_sesion();
    }
}

//Cabecera int email_archivo(const char *, const char *, char *)
//Precondicion archivos de usuarios deben estar cargados y las constantes LONGITUD_EMAIL y LONGITUD_CONTRASENA deben estar definidas
//Postcondicion busca el email en un archivo especifico y verifica la contrasena utilizando funciones especificas para cada tipo de archivo. Devuelve un codigo que indica el tipo de archivo en el que se encontro el email
int email_archivo(const char *nombre_archivo, const char *email, char *password) {
    FILE *file = fopen(nombre_archivo, "r");
    if (file == NULL) {
        puts("Error al abrir el archivo");
        return 0;
    }

    FuncionContrasena func = NULL;
    int resultado = 0;

    if (strcmp(nombre_archivo, "Clientes.txt") == 0) {
        func = contrasena_cliente;
        resultado = 1;
    } else if (strcmp(nombre_archivo, "AdminProv.txt") == 0) {
        func = contrasena_AdminProv;
        // No asignar resultado aquí, ya que contrasena_AdminProv puede devolver 2 o 4
    } else if (strcmp(nombre_archivo, "Transportistas.txt") == 0) {
        func = contrasena_transportista;
        resultado = 3;
    } else {
        fclose(file);
        return 0; // Si el archivo no coincide, devuelve 0
    }

    int funcResult = f_email(file, email, password, func);
    fclose(file);

    // Si el archivo es AdminProv.txt, usar el resultado de contrasena_AdminProv
    if (strcmp(nombre_archivo, "AdminProv.txt") == 0) {
        return funcResult;
    }

    // Para los demás archivos, usar el resultado asignado previamente
    return funcResult ? resultado : 0;
}

//Cabecera int contrasena_cliente(const char *line, char *)
//Precondicion una linea de texto con datos del cliente separados por guiones debe ser proporcionada
//Postcondicion la funcion extrae la contrasena del cliente de la linea de texto y devuelve 1 si la contrasena se encuentra, o 0 si no se encuentra
int contrasena_cliente(const char *line, char *password) {
    int guionCount = 0;
    while (*line != '\0') {
        if (*line == '-') {
            guionCount++;
            if (guionCount == 6) {                 // Copia la contrasena hasta el proximo guion (-)
                line++;
                char *start = password;
                while (*line != '-' && *line != '\0') {
                    *password++ = *line++;
                }
                *password = '\0'; // Anade caracter nulo al final
                return start != password; // Devuelve 1 si la contrasea no esta vacia.
            }
        }
        line++;
    }
    return 0; // Devuelve 0 si no se encuentra la contrasena.
}

//Cabecera int contrasena_transportista(const char *line, char *)
//Precondicion se proporciona una linea de texto con datos del transportista separados por guiones
//Postcondicion la funcion extrae la contrasena del transportista de la linea de texto y devuelve 1 si la contrasena se encuentra, o 0 si no se encuentra
int contrasena_transportista(const char *line, char *password) {
    int guionCount = 0;
    while (*line != '\0') {
        if (*line == '-') {
            guionCount++;
            if (guionCount == 3) {                 // Copia la contrasena hasta el proximo guion (-)
                line++;
                char *start = password;
                while (*line != '-' && *line != '\0') {
                    *password++ = *line++;
                }
                *password = '\0'; // Anade caracter nulo al final
                return start != password; // Devuelve 1 si la contrasea no esta vacia.
            }
        }
        line++;
    }
    return 0; // Devuelve 0 si no se encuentra la contrasena.
}

//Cabecera int contrasena_AdminProv(const char *line, char *)
//Precondicion se proporciona una linea de texto con datos del administrador o proveedor separados por guiones
//Postcondicion la funcion extrae la contrasena del administrador o proveedor de la linea de texto. Si se encuentra, devuelve 2. Si la contrasena contiene “ESIZON”, devuelve 4. Si no se encuentra la contrasena, devuelve 0.
int contrasena_AdminProv(const char *line, char *password) {
    int guionCount = 0;
    const char *startOfPassword = NULL;
    const char *endOfPassword = NULL;
    int esizonPresent = 0; // 0: no presente, 1: presente

    // Verificar si "ESIZON" está entre el primer y segundo guión
    const char *startOfEsizon = NULL;
    const char *endOfEsizon = NULL;

    while (*line != '\0') {
        if (*line == '-') {
            guionCount++;
            if (guionCount == 1) {
                startOfEsizon = line + 1;
            } else if (guionCount == 2) {
                endOfEsizon = line;
                if (endOfEsizon > startOfEsizon && strstr(startOfEsizon, "ESIZON") != NULL) {
                    esizonPresent = 1;
                }
            } else if (guionCount == 3) {
                startOfPassword = line + 1;
            } else if (guionCount == 4) {
                endOfPassword = line;
                break;
            }
        }
        line++;
    }

    // Extraer la contraseña entre los guiones 3 y 4
    if (startOfPassword && endOfPassword) {
        strncpy(password, startOfPassword, endOfPassword - startOfPassword);
        password[endOfPassword - startOfPassword] = '\0'; // Añadir carácter nulo al final
    }

    // Devolver 4 si "ESIZON" está presente, 2 si se encontró contraseña, 0 si no se encontró nada
    return esizonPresent ? 4 : (startOfPassword && endOfPassword ? 2 : 0);
}

//Cabecera int f_email(FILE *, const char *, char *, FuncionContrasena)
//Precondicion un archivo abierto y una funcion de verificacion de contrasena deben estar disponibles
//Postcondicion la funcion busca un correo electronico en el archivo y utiliza la función proporcionada para verificar la contrasena asociada, devolviendo el resultado de esa funcion de verificacion
int f_email(FILE *file, const char *email, char *password, FuncionContrasena func) {
    char line[LONGITUD_LINEA];
    while (fgets(line, LONGITUD_LINEA, file) != NULL) {
        if (strstr(line, email) != NULL) {
            return func(line, password); // Llama a la función de contraseña pasada como argumento
        }
    }
    return 0;
}

//Cabecera void cartera(char *, char *, float )
//Precondicion el archivo “Clientes.txt” debe existir y ser accesible para lectura y escritura
//Postcondicion la funcion actualiza el saldo de un cliente en el archivo, sumando la cantidad especificada al saldo existente si se encuentra la cuenta del cliente
void cartera(char *email, char *password, float cantidad_a_anadir) {
    FILE *file = fopen("Clientes.txt", "r+");
    float saldo_actual;
    char linea[LONGITUD_LINEA];
    int pos;
    int encontrado = 0;

    if (file == NULL) {
        printf("Error al abrir el archivo.\n");
        return;
    }

    while (fgets(linea, LONGITUD_LINEA, file) != NULL) {
        // Buscar la línea que contiene el email y la contraseña
        if (strstr(linea, email) && strstr(linea, password)) {
            encontrado = 1;
            // Calcular la nueva posición donde se encuentra el saldo
            pos = ftell(file) - strlen(linea) + (strrchr(linea, '-') - linea) + 1;
        }
    }

    if (encontrado) {
        // Mover el puntero del archivo a la posición del saldo
        fseek(file, pos, SEEK_SET);

        // Leer el saldo actual y sumarle la cantidad a añadir
        fscanf(file, "%f", &saldo_actual);
        saldo_actual += cantidad_a_anadir;

        // Mover el puntero del archivo atrás para sobrescribir el saldo
        fseek(file, pos, SEEK_SET);
        fprintf(file, "%.2f", saldo_actual);
        fprintf(file, "\n");
    }
    fclose(file);
}

//Cabecera int buscar_linea_cliente(const char *, const char *, const char *, char *)
//Precondicion el archivo especificado por nombre_archivo debe existir y ser accesible para lectura
//Postcondicion la funcion busca una línea en el archivo que contenga el correo electrónico y la contrasena proporcionados. Si se encuentra, no realiza ninguna acción adicional. Si no se encuentra, no hay efecto observable en el estado del programa
int buscar_linea_cliente(const char *nombre_archivo, const char *email, const char *password, char *linea_cliente) {
    FILE *file = fopen(nombre_archivo, "r");
    char *token;
    if (file == NULL) {
        printf("Error al abrir el archivo.\n");
        inicio_sesion();
    }
    while (fgets(linea_cliente, LONGITUD_LINEA, file) != NULL) {
        token = strtok(linea_cliente, "-"); // Obtiene el email
        if (strcmp(token, email) == 0) {
            token = strtok(NULL, "-"); // Obtiene la contraseña
            if (strcmp(token, password) == 0) {
            }
        }
    }
}

//Cabecera void listar_productos(FILE *)
//Precondicion el archivo proporcionado debe existir y ser accesible para lectura
//Postcondicion la funcion muestra el contenido del archivo linea por linea, imprimiendo cada una en la consola. Luego, pausa la ejecucion del programa y espera a que el usuario presione una tecla antes de continuar. Finalmente, cierra el archivo
void listar_productos(FILE *archivo) {
    FILE *file = fopen(archivo, "r");
    char linea[LONGITUD_LINEA];

    if (file == NULL) {
        printf("Error al abrir el archivo.\n");
        return;
    }

    printf("Listado de productos:\n");
    while (fgets(linea, LONGITUD_LINEA, file) != NULL) {
        printf("%s", linea);
    }
    system("PAUSE");
    fflush(stdin);
    fclose(file);
}

void manejar_opciones_usuario(int archivoEncontrado, const char *email, const char *password) {
    char id[4];
    int p;
    float cantidad;

    switch (archivoEncontrado) {
        case 1:
            printf("Que desea hacer?\n1-Listar productos\n2-Anadir dinero a su cartera\nOtro-Salir\n");
            scanf("%i", &p);
            switch (p) {
                case 1:
                    listar_productos("Productos.txt");
                    manejar_opciones_usuario(archivoEncontrado, email, password);
                    break;
                case 2:
                    puts("Hola, bienvenido al sistema de clientes");
                    puts("Introduce la cantidad de dinero que deseas anadir a tu cartera: ");
                    scanf("%f", &cantidad);
                    cartera(email, password, cantidad);
                    manejar_opciones_usuario(archivoEncontrado, email, password);
                    break;
                default:
                    puts("Volviendo al inicio de sesion...");
                    fflush(stdin);
                    inicio_sesion();
                    break;
            }
            break;
        case 2:
            printf("Que desea hacer?\n1-Listar el ID de mis productos\n2-Ver la lista de devoluciones\nOtro-Salir\n");
            scanf("%i",&p);
            switch(p){
            case 1:
                obtener_id_de_admin_prov(password, id);
                listar_productos_con_id(id);
                manejar_opciones_usuario(archivoEncontrado, email, password);
                break;
            case 2:
                listar_productos("Devoluciones.txt");
                manejar_opciones_usuario(archivoEncontrado, email, password);
                break;
            default:
                puts("Volviendo al inicio de sesion...");
                fflush(stdin);
                inicio_sesion();
            }

            break;
        case 3:
            printf("Bye bye\n");
            break;
        case 4:
            printf("Que desea hacer?\n1-Modificar clientes\n2-Modificar productos\n3-Modificar pedidos\n4-Listar devoluciones\nOtro-Salir\n");
            scanf("%i",&p);
            switch(p){
            case 1:
                a_administrador_mostrar("Clientes.txt");
                manejar_opciones_usuario(archivoEncontrado, email, password);
                break;
            case 2:
                a_administrador_mostrar("Productos.txt");
                manejar_opciones_usuario(archivoEncontrado, email, password);
                break;
            case 3:
                a_administrador_mostrar("Pedidos.txt");
                manejar_opciones_usuario(archivoEncontrado, email, password);
                break;
            case 4:
                listar_productos("Devoluciones.txt");
                manejar_opciones_usuario(archivoEncontrado, email, password);
                break;
            default:
                puts("Volviendo al inicio de sesion...");
                fflush(stdin);
                inicio_sesion();
                break;
            }
            break;
    }
}

//Cabecera int buscar_linea_cliente(const char *, const char *, const char *, char *)
//Precondicion se debe haber identificado previamente el tipo de archivo de usuario y las credenciales deben ser válidas
//Postcondicion la funcion ofrece un menu de opciones basado en el tipo de archivo de usuario encontrado y ejecuta la acción seleccionada por el usuario. Si no se selecciona una accion valida, reinicia el proceso de inicio de sesion
void reemplazarFrase(const char *nombreArchivo, const char *buscar, const char *reemplazar) {
    FILE *archivoEntrada, *archivoSalida;
    char linea[1024];
    archivoEntrada = fopen(nombreArchivo, "r");
    if (archivoEntrada == NULL) {
        printf("Error al abrir el archivo original.\n");
        return;
    }

    // Crear un archivo temporal para escritura
    archivoSalida = fopen("archivo_temp.txt", "w");
    if (archivoSalida == NULL) {
        printf("Error al crear el archivo temporal.\n");
        fclose(archivoEntrada);
        return;
    }

    // Leer y escribir cada línea
    while (fgets(linea, 1024, archivoEntrada) != NULL) {
        char *posicion;
        while ((posicion = strstr(linea, buscar)) != NULL) {
            // Escribir parte del contenido hasta la frase a reemplazar
            *posicion = '\0';
            fputs(linea, archivoSalida);
            fputs(reemplazar, archivoSalida);
            // Continuar leyendo después de la frase a reemplazar
            memmove(linea, posicion + strlen(buscar), strlen(posicion + strlen(buscar)) + 1);
        }
        // Escribir el resto de la línea
        fputs(linea, archivoSalida);
    }

    fclose(archivoEntrada);
    fclose(archivoSalida);

    // Reemplazar el archivo original con el archivo temporal
    remove(nombreArchivo);
    rename("archivo_temp.txt", nombreArchivo);
}

void admin_modificar(const char *nombre){
    char content, buscar[100],reemplazar[100];
    int x,y;
    FILE *archivoEntrada;
    archivoEntrada=fopen(nombre,"r");
    if (archivoEntrada == NULL) {
        printf("Error al abrir el archivo original.\n");
        a_administrador_menu();
    }
    content = fgetc(archivoEntrada);
    while(content!=EOF){
        printf("%c",content);
        content=fgetc(archivoEntrada);
    }
    fclose(archivoEntrada);
    printf("\nDesea modificar los datos?\n");
    puts("Pulse 1 en caso afirmativo, en caso contrario, pulse cualquuier otra tecla");
    scanf("%i",&x);
    getchar();
    do{
        if(x==1){
            puts("Que quieres cambiar del archivo? (Escribe la linea completa)");
            fgets(buscar,100,stdin);
            buscar[strcspn(buscar, "\n")] = '\0'; // Eliminar el car�cter de nueva l�nea

            puts("Por que lo quieres cambiar? (Escribe la linea tal cual modificando la parte que quieres)");
            fgets(reemplazar,100,stdin);
            reemplazar[strcspn(reemplazar, "\n")] = '\0'; // Eliminar el car�cter de nueva l�nea

            reemplazarFrase(nombre, buscar, reemplazar);
            printf("La frase ha sido modificada con exito en todo el archivo.\n");
        }
        else
            a_administrador_menu;
        printf("Desea realizar otro cambio?\nPulse 1 si es asi, pulse otra si no desea modificar nada mas\n");
        scanf("%i",&y);
        getchar();
    }while(y==1);
    a_administrador_menu();
}

void obtener_id_de_admin_prov(const char *password, char *id) {
    FILE *file = fopen("AdminProv.txt", "r");
    char linea[LONGITUD_LINEA];
    int esizonPresent = 0;

    if (file == NULL) {
        printf("Error al abrir el archivo AdminProv.txt\n");
        return 0;
    }

    while (fgets(linea, LONGITUD_LINEA, file) != NULL) {
        // Comprobar si la contraseña está en la línea y si "ESIZON" no está presente
        if (strstr(linea, password) != NULL && strstr(linea, "ESIZON") == NULL) {
            strncpy(id, linea, 4); // Copiar los primeros 4 caracteres como ID
            id[4] = '\0'; // Añadir carácter nulo al final
            esizonPresent = 1;
            break;
        }
    }

    fclose(file);
}

void listar_productos_con_id(const char *id) {
    FILE *file = fopen("Productos.txt", "r");
    char linea[LONGITUD_LINEA];
    char *token;
    int guionCount;

    if (file == NULL) {
        printf("Error al abrir el archivo Productos.txt\n");
        return;
    }

    printf("Listado de productos con ID %s:\n", id);
    while (fgets(linea, LONGITUD_LINEA, file) != NULL) {
        guionCount = 0;
        token = strtok(linea, "-");

        // Contar hasta el cuarto guion
        while (token != NULL && guionCount < 4) {
            token = strtok(NULL, "-");
            guionCount++;
        }

        // Si el token actual es el ID, imprimir la línea completa
        if (token != NULL && strncmp(token, id, 4) == 0) {
            printf("%s", linea);
            printf("\n");
        }
    }

    fclose(file);
}

