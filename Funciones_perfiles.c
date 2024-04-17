#include<stdio.h>
#include<string.h>
#include "Administrador.h"
#include "Transportista.h"
#include "Proveedor.h"
#include "Cliente.h"
#include "Eleccion.h"
int main(){
    int p,x,y;
    scanf("%i",&y); //prueba en vez de perfiles.perfil
    if (y==1) //perfiles.perfil
        a_administrador_menu();
    else{
        if(y==2){
            do{
            printf("Usuario:");
   /*         for(p=0;p<20;p++)
                printf("%c",&/*nombre cliente en el registro*);         */
            printf("\n---------------------\n1.Perfil\n2.Productos\n3.Descuentos\n4.Pedidos\n5.Devoluciones\n6.Salir del sistema\n");
            scanf("%i",&x);
            if(x>6 || x<=0)
                puts("Presione una tecla valida");
        }while(x>6 || x<=0);
        switch (x){
    case 1:
        puts("De acuerdo, se le mostrara la informacion de su perfil y podra modificarla si lo desea");
        void a_cliente_perfil();
        break;
    case 2:
        puts("De acuerdo, se le mostrara los productos para realizar consultas");
        void a_cliente_productos();
        break;
    case 3:
        puts("De acuerdo, se le mostrara los codigos promocionales y cheques de regalo");
        void a_cliente_descuentos();
        break;
    case 4:
        puts("De acuerdo, se le mostrara los pedidos");
        void a_cliente_pedidos();
        break;
    case 5:
        puts("De acuerdo, se le mostrara las devoluciones");
        void a_cliente_devoluciones();
        break;
    case 6:
        puts("De acuerdo.\nSaliendo del sistema...\n");
        //void inicio sesion
        }}
        else{
            if(y==3){
                do{
                    printf("Empresa:");
    /*                for(p=0;p<20;p++)
                        printf("%c",&/*nombre empresa en el registro*);         */
                    printf("\n---------------------\n1.Perfil\n2.Productos\n3.Pedidos\n4.Salir del sistema\n");
                    scanf("%i",&x);
                if(x>4 || x<=0)
                    puts("Presione una tecla valida");
                }while(x>4 || x<=0);
                switch (x){
            case 1:
                puts("De acuerdo, se le mostrara la informacion de su perfil y podra modificarla si lo desea");
                void a_proveedor_perfil();
                break;
            case 2:
                puts("De acuerdo, se le mostrara sus productos para realizar consultas");
                void a_proveedor_productos();
                break;
            case 3:
                puts("De acuerdo, se le mostrara los pedidos realizados a sus productos");
                void a_proveedor_pedidos();
                break;
            case 4:
                puts("De acuerdo.\nSaliendo del sistema...\n");
                //void inicio sesion
            }}
            else{
                if(y==4){
                    do{
                        printf("Transportista:");
  /*                      for(p=0;p<20;p++)
                            printf("%c",&/*nombre transportista en el registro*);           */
                        printf("\n---------------------\n1.Perfiles\n2.Clientes\n3.Proveedores\n4.Productos\n5.Categorias\n6.Pedidos\n7.Transportista\n8.Descuentos\n9.Devoluciones\n10.Salir del sistema\n");
                        scanf("%i",&x);
                        if(x>10 || x<=0)
                            puts("Presione una tecla valida");
                    }while(x>10 || x<=0);
                    switch (x){
                case 1:
                    puts("De acuerdo, se le mostrara la informacion de su perfil y podra modificarla si lo desea");
                    void a_transportista_perfil();
                    break;
                case 2:
                    puts("De acuerdo, se le mostrara sus repartos");
                    void a_transportista_repartos();
                    break;
                case 3:
                    puts("De acuerdo, se le mostraran los retornos disponibles");
                    void a_transportista_retornos();
                    break;
                case 4:
                    printf("De acuerdo.\nSaliendo del sistema...\n");
                    //void de iniciar sesion
                }}
            }
        }
    }
}
void a_administrador_menu(){
    int x;
    do{
        printf("Administrador\n---------------------\n1.Perfiles\n2.Clientes\n3.Proveedores\n4.Productos\n5.Categorias\n6.Pedidos\n7.Transportista\n8.Descuentos\n9.Devoluciones\n10.Salir del sistema\n");
        scanf("%i",&x);
        if(x>10 || x<=0)
            puts("Presione una tecla valida");
    }while(x>10 || x<=0);
    switch (x){
    case 1:
        puts("De acuerdo, se le mostrara la informacion de su perfil y podra modificarla si lo desea");
        a_administrador_perfil("antmar01");//aqui va la contraseña del registro cliente
        break;
    case 2:
        puts("De acuerdo, se le mostrara los clientes dados de alta y podra modificar sus datos");
        a_administrador_mostrar("Clientes.txt");
        break;
    case 3:
        puts("De acuerdo, se le dejara acceso a la informacion de los proveedores y podra modificarla");
        void a_administrador_proveedores();
        break;
    case 4:
        puts("De acuerdo, se le mostrara los productos dados de alta en la plataforma y podra modificarlos");
        a_administrador_mostrar("Productos.txt");
        break;
    case 5:
        puts("De acuerdo, se le mostrara las categorias dadas de alta y podra modificarlas");
        a_administrador_mostrar("Categorias.txt");
        break;
    case 6:
        puts("De acuerdo, se le mostrara la informacion de los pedidos dados de alta y podra modificarla");
        a_administrador_mostrar("ProductosPedidos.txt");
        break;
    case 7:
        puts("De acuerdo, se le mostrara la informacion de todos los transportistas dados de alta y podra modificarla");
        a_administrador_mostrar("Transportistas.txt");
        break;
    case 8:
        puts("De acuerdo, se le mostraran todos los descuentos/cheques de regalo dados de alta y podra modificarla");
        a_administrador_mostrar("Descuentos");
        break;
    case 9:
        puts("De acuerdo, se le mostrara las devoluciones y podra modificarlas");
        a_administrador_mostrar("Devoluciones");
        break;
    case 10:
        printf("De acuerdo.\nSaliendo del sistema...\n");
        //void de iniciar sesion
        }
}
void a_administrador_perfil(const char *password){
    char linea[256], nuevaLinea[256];
    FILE *f, *archivoTemporal;
    int opcion, repetir;

    do {
        f=fopen("AdminProv.txt", "r");
        archivoTemporal = fopen("temp.txt", "w");

        if (f == NULL || archivoTemporal == NULL) {
            perror("Error al abrir el archivo");
            if(f) fclose(f);
            if(archivoTemporal) fclose(archivoTemporal);
            return;
        }

        while (fgets(linea, sizeof(linea), f)) {
            if (strstr(linea, password) != NULL) {
                printf("%s", linea);
                printf("Desea modificar esta línea? (1 para sí, 2 para añadir algo, otro para no): ");
                scanf("%d", &opcion);
                getchar(); // Limpiar el buffer de entrada

                if(opcion == 1){
                    printf("Ingrese la nueva línea: ");
                    fgets(nuevaLinea, sizeof(nuevaLinea), stdin);
                    nuevaLinea[strcspn(nuevaLinea, "\n")] = '\0'; // Eliminar el carácter de nueva línea
                    fputs(nuevaLinea, archivoTemporal);
                    fputs("\n", archivoTemporal); // Añadir nueva línea al final
                } else if(opcion == 2){
                    printf("Ingrese el texto que desea añadir: ");
                    fgets(nuevaLinea, sizeof(nuevaLinea), stdin);
                    nuevaLinea[strcspn(nuevaLinea, "\n")] = '\0'; // Eliminar el carácter de nueva línea
                    fputs(linea, archivoTemporal); // Copiar la línea existente
                    fputs(nuevaLinea, archivoTemporal); // Añadir el texto nuevo
                    fputs("\n", archivoTemporal); // Añadir nueva línea al final
                } else {
                    fputs(linea, archivoTemporal); // Copiar la línea sin cambios
                }
            } else {
                fputs(linea, archivoTemporal); // Copiar la línea sin cambios
            }
        }

        fclose(f);
        fclose(archivoTemporal);

        remove("AdminProv.txt"); // Eliminar el archivo original
        rename("temp.txt", "AdminProv.txt"); // Renombrar el archivo temporal al nombre original

        printf("Desea realizar otro cambio? (1 para sí, otro para no): ");
        scanf("%d", &repetir);
        getchar(); // Limpiar el buffer de entrada
    } while (repetir == 1);

    a_administrador_menu();
}


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

void a_administrador_mostrar(const char *nombre){
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
            puts("Que quieres cambiar del archivo?");
            fgets(buscar,100,stdin);
            buscar[strcspn(buscar, "\n")] = '\0'; // Eliminar el car�cter de nueva l�nea

            puts("Por que lo quieres cambiar?");
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
void a_administrador_proveedores(){

}


