#include <stdio.h>
#include <stdlib.h>
#include "Carga.h"
#include "Inicios.h"
#define LONGITUD_EMAIL 30
#define LONGITUD_CONTRASENA 15
#define LONGITUD_LINEA 200

int main() {
    Carga_Clientes();
    Carga_AdminProv();
    Carga_Productos();
    Carga_Categorias();
    Carga_Descuentos();
    Carga_Descuentos_Clientes();
    Carga_Lockers();
    Carga_Compartimentos_Lockers();
    Carga_Pedidos();
    Carga_ProductosPedidos();
    Carga_Transportistas();
    Carga_Devoluciones();
    inicio_sesion();
}
void Carga_Clientes() {
    FILE *archivo = fopen("Clientes.txt", "w");
    if (archivo == NULL) {
        printf("Error al abrir el archivo.\n");
        exit(1);
    }
    fprintf(archivo, "0000001-Juan Perez-Plaza San Francisco 1 11000-San Fernando-Cadiz-juanperez@gmail.com-psw1234-1000\n0000002-Guillermo Lopez-Calle Sacramento 2 11003-Cadiz-Cadiz-guillelopez@gmail.com-psw4321-500\n");
    fprintf(archivo, "0000003-Carla Gomez-Avda. de la Constitucion 5 11011-Cadiz-Cadiz-carlagomez@gmail.com-psw5678-750\n0000004-Roberto Sanchez-Calle Ancha 10 11004-Cadiz-Cadiz-robertosanchez@gmail.com-psw8765-300\n");
    fprintf(archivo, "0000005-Ana Torres-Paseo Maritimo 15 11006-Cadiz-Cadiz-anatorres@gmail.com-psw1111-1200\n0000006-Luis Rodriguez-Ronda de los Tejares 20 11007-Cadiz-Cadiz-luisrodriguez@gmail.com-psw2222-600\n");
    fprintf(archivo, "0000007-Marta Jimenez-Calle Real 25 11008-Cadiz-Cadiz-martajimenez@gmail.com-psw3333-900\n0000008-Pedro Martin-Camino de la Playa 30 11009-Cadiz-Cadiz-pedromartin@gmail.com-psw4444-1500\n");
    fprintf(archivo, "0000009-Sofia Ruiz-Avda. del Puerto 35 11010-Cadiz-Cadiz-sofiaruiz@gmail.com-psw5555-500\n0000010-Jose Garcia-Calle Mayor 40 11012-Cadiz-Cadiz-josegarcia@gmail.com-psw6666-200\n");
    fclose(archivo);
}

void Carga_AdminProv(){
    FILE *archivo = fopen("AdminProv.txt", "w");
    if (archivo == NULL) {
        printf("Error al abrir el archivo.\n");
        exit(1);
    }
    fprintf(archivo, "0001-ESIZON-antonio.martin@esizon.com-antmar01-administrador\n0002-DISTGEN-donato.lima@distgen.com-donlim04-proveedor\n0003-ESIZON-carlos.gomez@esizon.com-carlgom02-administrador\n");
    fprintf(archivo, "0004-DISTGEN-laura.lopez@distgen.com-laulop05-proveedor\n0005-ESIZON-maria.sanchez@esizon.com-marsan03-administrador\n0006-DISTGEN-david.jimenez@distgen.com-davjim06-proveedor\n");
    fclose(archivo);
}

void Carga_Productos(){
    FILE *archivo = fopen("Productos.txt", "w");
    if (archivo == NULL) {
        printf("Error al abrir el archivo.\n");
        exit(1);
    }
    fprintf(archivo, "0000001-Television-Televisor 32  3D-0001-0004-50-5-340\n0000002-Auriculares-Auriculares inal mbricos-0002-0001-125-1-45\n0000003-Tablet-Tablet 10  HD-0003-0002-75-3-220\n0000004-Camara-Camara digital 20MP-0004-0006-40-7-150\n");
    fprintf(archivo, "0000005-Altavoz-Altavoz Bluetooth-0005-0001-200-2-90\n0000006-Consola-Consola de juegos 4K-0006-0004-30-4-400\n0000007-Reloj-Reloj inteligente-0007-0005-60-2-280\n0000008-Portatil-Portatil 15  i7-0008-0003-20-5-700\n");
    fprintf(archivo, "0000009-Movil-Movil 5G 128GB-0009-0004-100-1-550\n0000010-Impresora-Impresora 3D-0010-0001-15-6-350\n");
    fclose(archivo);
}

void Carga_Categorias(){
    FILE *archivo = fopen("Categorias.txt", "w");
    if (archivo == NULL) {
        printf("Error al abrir el archivo.\n");
        exit(1);
    }
    fprintf(archivo, "0001-tv video home cinema\n0002-audio HIFI\n0003-Dispositivos moviles\n0004-Fotografia y video\n0005-Audio portatil\n0006-Consolas y videojuegos\n0007-Tecnologia wearable\n0008-Tablets\n0009-Impresion y dise o\n");
    fclose(archivo);
}

void Carga_Descuentos(){
    FILE *archivo = fopen("Descuentos.txt", "w");
    if (archivo == NULL) {
        printf("Error al abrir el archivo.\n");
        exit(1);
    }
    fprintf(archivo, "black001-Black Friday-codpro-activo-10-esizon\nche001-cheque regalo nivel 1-cheqreg-activo-5-todos\nblack002-Descuento 20% Esizon-codpro-activo-20-todos\nche002-Cheque 10 euros-cheqreg-activo-10-todos\nblack003-Oferta Navidad-codpro-activo-15-esizon\nche003-Cheque 25 euros-cheqreg-activo-25-todos\n");
    fclose(archivo);
}

void Carga_Descuentos_Clientes(){
    FILE *archivo = fopen("DescuentosClientes.txt", "w");
    if (archivo == NULL) {
        printf("Error al abrir el archivo.\n");
        exit(1);
    }
    fprintf(archivo, "0000001-black001-25/01/2024-27/03/2024-0\n0000002-che001-01/02/2024-01/06/2024-0\n0000003-black002-05/02/2024-05/05/2024-0\n0000004-che002-10/02/2024-10/06/2024-0\n0000005-black003-15/02/2024-15/05/2024-0\n0000006-che003-20/02/2024-20/06/2024-0\n");
    fclose(archivo);
}

void Carga_Lockers(){
    FILE *archivo = fopen("Lockers.txt", "w");
    if (archivo == NULL) {
        printf("Error al abrir el archivo.\n");
        exit(1);
    }
    fprintf(archivo, "Lock001-Puerto Real-C diz-local 12-15-0\nLock002-Jerez de la Frontera-Cadiz-local 13-15-5\nLock003-Cadiz-Cadiz-local 14-15-3\nLock004-Puerto Real-Cadiz-local 15-15-9\nLock005-Jerez de la Frontera-Cadiz-local 16-15-1\nLock006-Jerez de la Frontera-Cadiz-local 2-15-6\n");
    fprintf(archivo, "Lock007-Puerto Real-Cadiz-local 9-15-11\nLock008-Cadiz-Cadiz-local 5-15-8\nLock009-Jerez de la Frontera-Cadiz-local 20-15-9\nLock010-Cadiz-Cadiz-local 21-15-10\n");
    fclose(archivo);
}

void Carga_Compartimentos_Lockers(){
    FILE *archivo = fopen("CompartimentosLockers.txt", "w");
    if (archivo == NULL) {
        printf("Error al abrir el archivo.\n");
        exit(1);
    }
    fprintf(archivo, "Lock001-01-134697-ocupado-08/01/2024-13/03/2024\nLock002-04-134698-ocupado-09/01/2024-14/03/2024\nLock003-03-134699-ocupado-10/01/2024-15/03/2024\nLock004-07-134700-ocupado-11/01/2024-16/03/2024\nLock005-01-134701-ocupado-12/01/2024-17/03/2024\nLock006-06-134702-ocupado-13/01/2024-18/03/2024\n");
    fprintf(archivo, "Lock007-11-134703-ocupado-14/01/2024-19/03/2024\nLock008-08-134704-ocupado-15/01/2024-20/03/2024\nLock009-07-134705-ocupado-16/01/2024-21/03/2024\nLock010-10-134706-ocupado-17/01/2024-22/03/2024\n");
    fclose(archivo);
}

void Carga_Pedidos(){
    FILE *archivo = fopen("Pedidos.txt", "w");
    if (archivo == NULL) {
        printf("Error al abrir el archivo.\n");
        exit(1);
    }
    fprintf(archivo, "0000001-02/02/2024-0000004-domicilio-Lock001-che001\n0000002-03/02/2024-0000001-locker-Lock003-black002\n0000003-04/02/2024-0000006-domicilio-Lock005-che002\n0000004-05/02/2024-0000009-locker-Lock010-che003\n");
    fclose(archivo);
}

void Carga_ProductosPedidos(){
    FILE *archivo = fopen("ProductosPedidos.txt", "w");
    if (archivo == NULL) {
        printf("Error al abrir el archivo.\n");
        exit(1);
    }
    fprintf(archivo, "0000001-0000004-1-07/03/2024-340-enPreparaci n\n0000002-0000004-2-08/02/2024-45-enLocker-0002-Lock003-134699-08/02/2024\n0000003-0000006-1-09/03/2024-220-enPreparaci n\n0000004-0000009-2-05/02/2024-700-entregado-0004-16/05/2024\n");
    fclose(archivo);
}

void Carga_Transportistas(){
    FILE *archivo = fopen("Transportistas.txt", "w");
    if (archivo == NULL) {
        printf("Error al abrir el archivo.\n");
        exit(1);
    }
    fprintf(archivo, "0001-Rafael Gutierrez-rafael@gutitrans.com-rg917-GutiTrans-Cadiz\n0002-Pepe Tinoco-pepe@itranspo.com-pt185-TransPo-Puerto Real\n0003-Miguel Luna-miguel@luntrans.com-ml237-MigTrans-Cadiz\n0004-Francisco Aparicio-fran@apatranspo.com-ra826-GutiTrans-Jerez de la Frontera\n");
    fprintf(archivo, "0005-Marta Lopez-marta@itranspo.com-ml519-TransPo-Puerto Real\n0006-Juan Sanchez-juan@gutitrans.com-js072-MigTrans-Cadiz\n0007-Laura Martin-laura@itranspo.com-lm346-TransPo-Jerez de la Frontera\n");
    fprintf(archivo, "0008-Carlos Perez-carlos@gutitrans.com-cp884-GutiTrans-Cadiz\n0009-Sofia Ruiz-sofia@itranspo.com-sr461-TransPo-Puerto Real\n0010-David Jimenez-david@gutitrans.com-dj530-MigTrans-Jerez de la Frontera\n");
    fclose(archivo);
}

void Carga_Devoluciones(){
    FILE *archivo = fopen("Devoluciones.txt", "w");
    if (archivo == NULL) {
        printf("Error al abrir el archivo.\n");
        exit(1);
    }
    fprintf(archivo, "0000001-0000004-25/02/2024-desperfecto-pendiente\n0000003-0000001-26/02/2024-desperfecto-enviado-26/02/2024-26/03/2024\n");
    fclose(archivo);
}
