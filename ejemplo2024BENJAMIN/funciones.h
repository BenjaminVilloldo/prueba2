#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Producto
{
    int Id;
    char *Nombre;
    char *Sucursal;
    int Stock;
    float Precio;
    int Activo;
} Producto;

typedef struct Nodo
{
    Producto Producto;
    struct Nodo *Siguiente;
} Nodo;

char Sucursal[3][15] =
    {
        "Tucuman", "Salta", "Deposito"};

Producto *ProductoElectronicos();
void MostrarProductosDeArreglo(Producto *producto, int cantidad, const char *Titulo);
Producto CrearProducto(char *nombre, char *sucursal, int id, int cantidad, int precio);
void MostrarProducto(Producto prod);
void MostrarLista(Nodo *lista, const char *tituloLista);
Nodo *CrearListaVacia();

struct Producto *ProductoElectronicos()
{
    struct Producto *Productos = (struct Producto *)malloc(sizeof(struct Producto) * 40);

    Productos[0] = CrearProducto("Ventilador Portátil", Sucursal[0], 1, 15, 800);
    Productos[1] = CrearProducto("Lavador de bermudas Semiautomático", Sucursal[1], 2, 8, 1500);
    Productos[2] = CrearProducto("Licuadora de bolsillo", Sucursal[0], 3, 6, 300);
    Productos[3] = CrearProducto("Heladera Chui", Sucursal[1], 4, 3, 1800);
    Productos[4] = CrearProducto("Exprimidor de milanesas", Sucursal[0], 5, 5, 2500);
    Productos[5] = CrearProducto("Televisor 65mil pulgadas SanSan", Sucursal[1], 6, 2, 4000);
    Productos[6] = CrearProducto("Cocina solar", Sucursal[0], 7, 7, 1200);
    Productos[7] = CrearProducto("Estación De Poder Nro 5", Sucursal[1], 8, 10, 600);
    Productos[8] = CrearProducto("Caja Serie X", Sucursal[1], 9, 4, 2000);
    Productos[9] = CrearProducto("OjoPhone 11", Sucursal[0], 10, 1, 1500);
    Productos[10] = CrearProducto("Ventilador para arenero de gatos 5000", Sucursal[1], 11, 15, 1200);
    Productos[11] = CrearProducto("Lampara de lava para refugio subterraneo 3000", Sucursal[0], 12, 8, 1700);
    Productos[12] = CrearProducto("Cortador de salame TurboMix 9000", Sucursal[1], 13, 6, 500);
    Productos[13] = CrearProducto("Frigofrost 2000", Sucursal[0], 14, 3, 1900);
    Productos[14] = CrearProducto("SuperSqueeze para botellas de jugo Pro", Sucursal[1], 15, 5, 3000);
    Productos[15] = CrearProducto("Pantalla MegaScreen de 10000 pulgadas", Sucursal[0], 16, 2, 6000);
    Productos[16] = CrearProducto("Robot de cocina MasterChef 6000", Sucursal[1], 17, 7, 2500);
    Productos[17] = CrearProducto("PowerStation X", Sucursal[0], 18, 10, 800);
    Productos[18] = CrearProducto("PC Master Race QuantumBox", Sucursal[1], 19, 4, 3500);
    Productos[19] = CrearProducto("Paseador electronico de mascotas", Sucursal[0], 20, 1, 2000);
    Productos[20] = CrearProducto("Fábrica de pochoclos Acme", Sucursal[1], 21, 1, 2000);
    Productos[21] = CrearProducto("Calentador de helados a vapor", Sucursal[0], 22, 1, 1200);
    Productos[22] = CrearProducto("Engrampadora electrónica marca Lechuck", Sucursal[1], 23, 1, 800);
    Productos[23] = CrearProducto("Heladera mega frost Chanchung", Sucursal[0], 24, 1, 7000);
    Productos[24] = CrearProducto("Secador de papas fritas", Sucursal[1], 25, 1, 1400);
    Productos[25] = CrearProducto("Catalogador de estampas postales automático", Sucursal[0], 26, 1, 2000);
    Productos[26] = CrearProducto("Batidor electrónico para frutas", Sucursal[1], 27, 1, 2000);
    Productos[27] = CrearProducto("Cortadora de pasto para bonsái", Sucursal[0], 28, 1, 2000);
    Productos[28] = CrearProducto("Repuesto para Cortadora de pasto para bonsái", Sucursal[1], 29, 1, 2000);
    Productos[29] = CrearProducto("Videoconsola portátil Noentiendo con 999 juegos", Sucursal[0], 30, 1, 2000);
    Productos[30] = CrearProducto("Asensor transportable para 2 escalones", Sucursal[1], 31, 25, 2000);
    Productos[31] = CrearProducto("Asensor transportable para 3 escalones", Sucursal[0], 32, 6, 7000);
    Productos[32] = CrearProducto("Mesa de luz electrónica", Sucursal[1], 33, 1, 2000);
    Productos[33] = CrearProducto("Rizador de cabellos de hámster", Sucursal[0], 34, 1, 2000);
    Productos[34] = CrearProducto("Batería externa para batidor de frutas", Sucursal[1], 35, 1, 2000);
    Productos[35] = CrearProducto("Dispenser aleatorio de trabas invisibles y coleros de cabello", Sucursal[0], 36, 1, 2000);
    Productos[36] = CrearProducto("trabas invisibles para dispenser Electrónico", Sucursal[1], 37, 1, 2000);
    Productos[37] = CrearProducto("Auriculares con IA para examenes universitarios", Sucursal[0], 38, 1, 2000);
    Productos[38] = CrearProducto("Iluminación artificial para exteriores con poca luz", Sucursal[1], 39, 1, 2000);
    Productos[39] = CrearProducto("Catalogador de memes de gatitos electrónico de un solo uso", Sucursal[0], 40, 1, 2000);

    return Productos;
}

// Inserta el nodo al final de la lista
void InsertarEnLista(Nodo **Lista, Nodo *nodo)
{
    if (*Lista == NULL)
    {
        *Lista = nodo;
    }
    else
    {
        Nodo *temp = *Lista;
        while (temp->Siguiente != NULL)
        {
            temp = temp->Siguiente;
        }
        temp->Siguiente = nodo;
    }
}

Nodo *CrearNodo(Producto Producto)
{
    Nodo *nuevo = (Nodo *)malloc(sizeof(Nodo));
    nuevo->Producto = Producto;
    nuevo->Siguiente = NULL;
    return nuevo;
}

struct Producto CrearProducto(char *nombre, char *sucursal, int id, int stock, int precio)
{
    struct Producto producto;
    producto.Id = id;
    producto.Nombre = (char *)malloc(strlen(nombre) + 1);
    strcpy(producto.Nombre, nombre);
    producto.Sucursal = (char *)malloc(strlen(sucursal) + 1);
    strcpy(producto.Sucursal, sucursal);
    producto.Stock = stock;
    producto.Precio = precio;
    producto.Activo = 1;
    return producto;
}

Nodo *CrearListaVacia()
{
    return NULL;
}

void MostrarLista(Nodo *lista, const char *tituloLista)
{
    printf("\n");
    printf("LISTA: %s\n", tituloLista);
    int i = 0;
    while (lista != NULL)
    {
        i++;
        printf("\nNODO - %d ", i);
        MostrarProducto(lista->Producto);
        lista = lista->Siguiente;
    }
    printf("\nCantidad de elementos: %d\n", i);
}

void MostrarLinea()
{
    printf("\n---------------------------\n");
}

int ContarProductos(Nodo *lista)
{
    int i = 0;
    while (lista != NULL)
    {
        i++;
        lista = lista->Siguiente;
    }
    return i;
}

void MostrarTextoYValor(const char *tituloLista, int cantidad)
{
    printf("\n");
    printf("%s - %d \n", tituloLista, cantidad);
}

void MostrarProductosDeArreglo(Producto *producto, int cantidad, const char *Titulo)
{
    printf("%s \n\r", Titulo);
    printf("------------------------- \n\r");
    for (int i = 0; i < cantidad; i++)
    {
        MostrarProducto(producto[i]);
        printf("\n");
    }
    printf("------------------------- \n\r");
}

void MostrarProducto(Producto producto)
{
    printf("%2d - %-7s | %s |$ %f | %d  | %d", producto.Id, producto.Sucursal, producto.Nombre, producto.Precio, producto.Stock, producto.Activo);
}

void MostrarCantidadProductos(Nodo *lista)
{
    int i = 0;
    while (lista != NULL)
    {
        i++;
        lista = lista->Siguiente;
    }
    MostrarTextoYValor("Cantidad de productos", i);
}

//////////////////////////////////////////////  PUNTO 1 ////////////////////////////////////////////////////////////////////
void cargarListas(Nodo **listaTucu, Nodo **listaSalta, Producto *ProductoElectronicos, int cant)
{
    Nodo *nodoActual = NULL;
    for (int i = 0; i < cant; i++)
    {
        nodoActual = CrearNodo(ProductoElectronicos[i]);
        if (strcasecmp(ProductoElectronicos[i].Sucursal, "tucuman") == 0)
        {
            InsertarEnLista(listaTucu, nodoActual);
        }
        else
        {
            InsertarEnLista(listaSalta, nodoActual);
        }
    }
}
//////////////////////////////////////////////  PUNTO 2 ////////////////////////////////////////////////////////////////////
Nodo *buscarNodoXid(Nodo *lista, int id)
{

    while (lista != NULL)
    {
        if (lista->Producto.Id == id)
        {
            return lista;
        }
        lista = lista->Siguiente;
    }
    return NULL;
}

void cambiarAInactivo(Nodo *lista, Nodo *lista2)
{
    int id;
    Nodo *nodoEncontrado = NULL;
    printf("PRODUCTOS CAMBIADOS A INACTIVO:\n");

    for (int i = 0; i < 2; i++)
    {

        do
        {
            printf("Ingrese ID para cambiar a inactivo:");
            fflush(stdin);
            scanf("%d", &id);
        } while (id < 0 || id > 40);

        nodoEncontrado = buscarNodoXid(lista, id);
        if (nodoEncontrado == NULL)
        {
            nodoEncontrado = buscarNodoXid(lista2, id);
        }

        nodoEncontrado->Producto.Activo = 0;
    }
}
//////////////////////////////////////////////  PUNTO 3 ////////////////////////////////////////////////////////////////////
void EliminarNodo(Nodo *nodo)
{
    free(nodo->Producto.Nombre);
    free(nodo->Producto.Sucursal);
    free(nodo);
}

int cantidadProductosInactivos(Nodo *lista1, Nodo *lista2)
{
    int cont1 = 0, cont2 = 0, contFinal = 0;
    while (lista1 != NULL)
    {
        if (lista1->Producto.Activo == 0)
        {
            cont1++;
        }

        lista1 = lista1->Siguiente;
    }
    while (lista2 != NULL)
    {
        if (lista2->Producto.Activo == 0)
        {
            cont2++;
        }

        lista2 = lista2->Siguiente;
    }
    contFinal = cont1 + cont2;
    return contFinal;
}
Nodo *AislarNodoInactivo(Nodo **Lista, int activo)
{
    Nodo *nodoAux = *Lista;
    Nodo *nodoAnt = NULL;

    while (nodoAux != NULL && nodoAux->Producto.Activo != activo)
    {
        nodoAnt = nodoAux;
        nodoAux = nodoAux->Siguiente;
    }

    if (nodoAux != NULL)
    {
        if (nodoAux == *Lista)
        {
            *Lista = (*Lista)->Siguiente;
        }
        else
        {
            nodoAnt->Siguiente = nodoAux->Siguiente;
        }
        nodoAux->Siguiente = NULL;
    }

    return nodoAux;
}

void eliminarInactivos(Nodo **lista)
{
    int cant = cantidadProductosInactivos(*lista, 0);
    Nodo *nodoAQuitar = NULL;
    for (int i = 0; i < cant; i++)
    {

        nodoAQuitar = AislarNodoInactivo(&(*lista), 0);
        EliminarNodo(nodoAQuitar);
    }
}

void moverADeposito(Nodo **lista, Nodo **listaDeposito)
{
    int totalStock = 0;
    Nodo *nodoAux = *lista;
    Nodo *nodoAnt = NULL;

    if (nodoAux == NULL)
    {
        *listaDeposito = NULL;
    }
    else
    {
        while (nodoAux != NULL && totalStock <= 40)
        {
            totalStock += nodoAux->Producto.Stock;
            nodoAnt = nodoAux;
            nodoAux = nodoAux->Siguiente;
        }
        
        if (nodoAnt)
        {
            nodoAnt->Siguiente = NULL;
        }
        *listaDeposito = nodoAux;
    }
    
    printf("EXCEDENTE ELIMINADO.");
    printf("El stock total es de %d:",totalStock);
}
Nodo *AislarPrimerNodo(Nodo **Lista)
{
    Nodo *nodoAux = *Lista;

    *Lista = (*Lista)->Siguiente;

    nodoAux->Siguiente = NULL;

    return nodoAux;
}


void EliminarLista(Nodo **Lista)
{
    Nodo *nodoAux = NULL;
    while ((*Lista)!=NULL)
    {
        nodoAux = AislarPrimerNodo(Lista);
        EliminarNodo(nodoAux);
    }
}