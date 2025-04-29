#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX 150

typedef struct TProducto
{
    char *Descripcion;
    char *Categoria;
    int Precio;
    int Stock;
} TProducto;

struct Nodo
{
    TProducto producto;
    struct Nodo *siguiente;
} typedef Nodo;

TProducto CrearProducto(const char *descripcion, const char *categoria, int precio, int stock)
{
    TProducto Producto;
    Producto.Descripcion = (char *)malloc(strlen(descripcion) + 1);
    strcpy(Producto.Descripcion, descripcion);

    Producto.Categoria = (char *)malloc(strlen(categoria) + 1);
    strcpy(Producto.Categoria, categoria);

    Producto.Precio = precio;
    Producto.Stock = stock;
    return Producto;
}

/*
  char *Descripcion;
    char *Categoria;
    int Precio;
    int Stock;
*/
void MostrarProducto(TProducto producto)
{
    printf("-Descripcion:%s\n", producto.Descripcion);
    printf("-Categoria:%s\n", producto.Categoria);
    printf("-Stock:%d\n", producto.Stock);
    printf("-Precio:%d\n", producto.Precio);
    printf("\n");
}

Nodo *CrearNodo(TProducto producto)
{
    Nodo *nuevo_nodo = (Nodo *)malloc(sizeof(Nodo));
    nuevo_nodo->producto = producto;
    nuevo_nodo->siguiente = NULL;
    return nuevo_nodo;
}

Nodo *CrearListaVacia()
{
    return NULL;
}

void InsertarNodoEnLista(Nodo **Lista, Nodo *nodo)
{
    
    nodo->siguiente = *Lista;
    *Lista = nodo;
}

bool EsListaVacia(Nodo *Lista)
{
    return Lista == NULL ? true : false;
}

void mostrarLista(Nodo *Lista, char *nomre_lista)
{
    if (EsListaVacia(Lista))
    {
        printf("Lista vacia\n");
    }
    else
    {
        printf("***** Listado de: %s *****\n", nomre_lista);
        while (!EsListaVacia(Lista))
        {
           MostrarProducto(Lista->producto);
            Lista = Lista->siguiente;
        }
    }
}

int LongitudLista(Nodo *Lista)
{
    int cantidad_nodos = 0;
    if (EsListaVacia(Lista))
        return 0;

    while (!EsListaVacia(Lista))
    {
        cantidad_nodos++;
        Lista = Lista->siguiente;
    }
    return cantidad_nodos;
}


Nodo *QuitarPrimerNodo(Nodo **Lista)
{
    Nodo *nodoAux = *Lista;
    *Lista = (*Lista)->siguiente;
    nodoAux->siguiente = NULL;
    return nodoAux;
}


void EliminarNodo(Nodo *nodo)
{
    free(nodo->producto.Descripcion);
    free(nodo->producto.Categoria);
    free(nodo);
}

void EliminarLista(Nodo **Lista)
{
    int cantidad_nodos = LongitudLista(*Lista);

    Nodo *nodo_quitado = NULL;

    for (int i = 0; i < cantidad_nodos; i++)
    {
        nodo_quitado = QuitarPrimerNodo(Lista);
        EliminarNodo(nodo_quitado);
    }
}

/*
Quitar nodo por algun dato o condicion,
en este caso lo hago por ID
Quitar != borrar
*/

Nodo *QuitarNodoXStock(Nodo **Lista, int stock)
{
    Nodo *nodoAux = *Lista;
    Nodo *nodoAnt = NULL;

    while (nodoAux != NULL && nodoAux->producto.Stock != stock)
    {
        nodoAnt = nodoAux;
        nodoAux = nodoAux->siguiente;
    }

    // 1 - Encontre el nodo -> nodoAux != null
    // 2 - Llegue al final de la lista y no encontre el nodo -> nodoAux == NULL

    if (nodoAux != NULL)
    {
        if (nodoAux == *Lista)
        {
            *Lista = (*Lista)->siguiente;
        }
        else
        {
            nodoAnt->siguiente = nodoAux->siguiente;
        }
        nodoAux->siguiente = NULL;
        return nodoAux;
    }

    return NULL;
}

//--------------------------------------------------------------------------

TProducto *ProveedorDeCarnesYBazar()
{
    TProducto *Productos = (TProducto *)malloc(sizeof(TProducto) * 17);

    // Carnes
    Productos[0] = CrearProducto("Milanesa Nalga", "Carnes", 2060, 34);
    Productos[1] = CrearProducto("Picada Especial", "Carnes", 1550, 123);
    Productos[2] = CrearProducto("Peceto Milanesa", "Carnes", 3445, 100);
    Productos[3] = CrearProducto("Tapa De Asado De Novillito", "Carnes", 1599, 10);
    Productos[4] = CrearProducto("Entraña De Novillito", "Carnes", 2950, 55);
    // Bazar
    Productos[5] = CrearProducto("Cucharon Sopero Nylon Menta", "Bazar", 629, 30);
    Productos[6] = CrearProducto("Cucharon Con Apoyo Rubber X 1 Un", "Bazar", 1299, 1);
    Productos[7] = CrearProducto("Espumadera Con Apoyo Rubber- 33 Cm- Antiadherente X 1 U", "Bazar", 1299, 22);
    Productos[8] = CrearProducto("Cuchillo Acero Krea-12 Cm", "Bazar", 2250, 240);
    Productos[9] = CrearProducto("Cuchillo De Pan Acero Krea- 20 Cm", "Bazar", 3240, 0);
    Productos[10] = CrearProducto("Cuchara Con Apoyo Rubber X1u", "Bazar", 1209, 0);
    Productos[11] = CrearProducto("Sacacorcho Wong Krea Acero 11 Cm", "Bazar", 945, 1);
    Productos[12] = CrearProducto("Destapador Botella Rubber", "Bazar", 695, 15);
    Productos[13] = CrearProducto("Batidor Prg Pdq Krea", "Bazar", 501, 5);
    // Pastas
    Productos[14] = CrearProducto("Fideos Tirabuzon C&c 500gr", "Pastas", 244, 0);
    Productos[15] = CrearProducto("Fideos Spaghetti Barilla 500 Gr", "Pastas", 1932, 3);
    //Productos[16] = CrearProducto("Fideos Codito Matarazzo X500 Gr", "Pastas", 219, 10);

    return Productos;
}

TProducto *ProveedorDeTecnologicos()
{
    TProducto *Productos = (TProducto *)malloc(sizeof(TProducto) * 11);
    // Tecnológicos variados
    Productos[0] = CrearProducto("Termotanque Gas Rheem Tgnp120rh 120 L", "Gas", 189000, 21);
    Productos[1] = CrearProducto("Termotanque Señorial Gas Zafiro 120 L", "Gas", 94000, 15);
    Productos[2] = CrearProducto("Taladro Mc Carthy Percutor 13mm 650w", "Herramientas", 8500, 10);
    Productos[3] = CrearProducto("Led Fhd 43 Hisense Smart Tv", "Electronicos", 95000, 5);
    Productos[4] = CrearProducto("Led Noblex 32 Smart", "Electronicos", 75500, 7);
    Productos[5] = CrearProducto("Led Noblex 50 Smart Dk50x6550", "Electronicos", 136000, 22);
    Productos[6] = CrearProducto("Led 55' Samsung 4k", "Electronicos", 210000, 0);
    Productos[7] = CrearProducto("Smart Tv 65 4k Qled Q65b Samsung", "Electronicos", 480000, 0);
    Productos[8] = CrearProducto("Qled 85' Samsung Qn85q70aagczb", "Electronicos", 1100000, 50);
    Productos[9] = CrearProducto("Impresora Inalambrica C/pantalla Led Canon G31", "Electronicos", 91000, 15);
   //Productos[10] = CrearProducto("Notebook Vaio Fe15 Core I5 12gen 8'56gb", "Electronicos", 307000, 4);

    return Productos;
}

TProducto *ProveedorDeLacteosPanaderiaLiquidos()
{
    TProducto *Productos = (TProducto *)malloc(sizeof(TProducto) * 17);
    // Lacteos
    Productos[0] = CrearProducto("Queso Crema Clásico Casancrem 480gr", "Lacteos", 931, 200);
    Productos[1] = CrearProducto("Queso Untable Finlandia 180 Gr", "Lacteos", 501, 100);
    Productos[2] = CrearProducto("Leche Entera Clasica La Serenisima Sachet 1 L", "Lacteos", 265, 10);
    Productos[3] = CrearProducto("Yogur Cremix Conicet Vainilla Pack X4 Yogurisimo 120gr", "Lacteos", 745, 200);
    Productos[4] = CrearProducto("Manteca Casanto 200g", "Lacteos", 401, 200);
    Productos[5] = CrearProducto("Yogur Bebible Descremado Frutilla La Serenísima Clásico 900gr", "Lacteos", 375, 200);
    // Panaderia
    Productos[6] = CrearProducto("Rapiditas Bimbo Clásicas X 275grs", "Panaderia", 442, 0);
    Productos[7] = CrearProducto("Palmeritas De Manteca 200 Gr", "Panaderia", 741, 0);
    Productos[8] = CrearProducto("Cookies Con Chip De Chocolate", "Panaderia", 681, 2200);
    Productos[9] = CrearProducto("Bizcochuelo Húmedo", "Panaderia", 1039, 160);
    Productos[10] = CrearProducto("Alfajorcitos De Maizena 240 Gr", "Panaderia", 584, 98);
    // Liquidos
    Productos[11] = CrearProducto("Agua Mineral Cuisine & Co Sin Gas 2l", "Liquidos", 208, 57);
    Productos[12] = CrearProducto("Soda Sifon 1", "Liquidos", 321, 25);
    Productos[13] = CrearProducto("Aceite De Oliva Extra Virgen Cuisine & Co 500", "Liquidos", 1166, 7);
    Productos[14] = CrearProducto("Gaseosa Cola Pepsi Regular 2.25l", "Liquidos", 499, 4);
    Productos[15] = CrearProducto("Gaseosa Coca-cola Sabor Original 500 Ml", "Liquidos", 234, 26);
    //Productos[16] = CrearProducto("Gaseosa Sprite Lima-limón 2,25 Lt", "Liquidos", 628, 33);

    return Productos;
}


void MostrarProductosDeArreglo(TProducto *producto, int cantidad, const char *nombreProveedor)
{
    printf("%s \n\r", nombreProveedor);
    printf("------------------------- \n\r");
    for (int i = 0; i < cantidad; i++)
    {
        printf("%s - %d \n\r", producto[i].Descripcion, producto[i].Precio);
    }
    printf("------------------------- \n\r");
}


void insertarArregloEnLista(Nodo **Lista, TProducto *productos, int cantidad_productos)
{
    TProducto producto_copia;
    char *descripcion = NULL;
    char *categoria = NULL;
    int stock = 0, precio = 0;
    Nodo *nuevo_nodo = NULL;

    for (int i = 0; i < cantidad_productos; i++)
    {
        descripcion = productos[i].Descripcion;
        categoria = productos[i].Categoria;
        stock = productos[i].Stock;
        precio = productos[i].Precio;
        producto_copia = CrearProducto(descripcion, categoria, precio, stock);
        nuevo_nodo = CrearNodo(producto_copia);
        InsertarNodoEnLista(Lista, nuevo_nodo);
    }
}

void filtroPorPrecio(Nodo *Lista, Nodo **ListaFiltrada, int precio)
{
    TProducto productoCopia;
    char *descripcion = NULL;
    char *categoria = NULL;
    int stock = 0, precioCopia = 0;
    Nodo *nodo_copia = NULL;

    while (Lista != NULL)
    {
        if (Lista->producto.Precio > precio)
        {
            descripcion = Lista->producto.Descripcion;
            categoria = Lista->producto.Categoria;
            stock=Lista->producto.Stock;
            precioCopia=Lista->producto.Precio;
            productoCopia=CrearProducto(descripcion,categoria,stock,precioCopia);
            nodo_copia=CrearNodo(productoCopia);

            InsertarNodoEnLista(ListaFiltrada, nodo_copia);
        }
        Lista = Lista->siguiente;
    }
}

void modificarPrecioPorPorcentaje(Nodo * Lista,int porcetaje)
{
    while (!EsListaVacia(Lista))
    {
        Lista->producto.Precio =  Lista->producto.Precio*(1 + (porcetaje/(float)100)); 
        Lista = Lista->siguiente;
    }
}

int ContarProductosSinStock(Nodo *Lista)
{
    int cantidad_productos_sinStock = 0;
    if (EsListaVacia(Lista))
        return 0;

    while (!EsListaVacia(Lista))
    {
        if (Lista->producto.Stock == 0)
        {
            cantidad_productos_sinStock++;
        }
        Lista = Lista->siguiente;
    }
    return cantidad_productos_sinStock;
}

void extraerProductosSinStock(Nodo ** Lista, Nodo **ProductosSinStock)
{
    int cantidad_productos_sin_stock = ContarProductosSinStock(*Lista);

    Nodo * nodo_aux = NULL;

    for (int i = 0; i < cantidad_productos_sin_stock; i++)
    {
        nodo_aux = QuitarNodoXStock(Lista,0);
        InsertarNodoEnLista(ProductosSinStock,nodo_aux);
    }
}

