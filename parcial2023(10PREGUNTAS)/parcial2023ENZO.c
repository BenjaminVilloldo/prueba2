#include "funciones_parc2023.h"

void insertarArregloEnLista(Nodo **Lista, TProducto *productos, int cantidad_productos);
void filtroPorPrecio(Nodo *Lista, Nodo **ListaFiltrada, int precio);
void modificarPrecioPorPorcentaje(Nodo * Lista,int porcetaje);
int ContarProductosSinStock(Nodo *Lista);
void extraerProductosSinStock(Nodo **Lista, Nodo **ProductosSinStock);


int main()
{
    TProducto *ProductosDeProveedor1 = ProveedorDeLacteosPanaderiaLiquidos();
    TProducto *ProductosDeProveedor2 = ProveedorDeCarnesYBazar();
    TProducto *ProductosElectronicos = ProveedorDeTecnologicos();

    /* MostrarProductosDeArreglo(ProductosDeProveedor1, 16, "Proveedor 1");
     MostrarProductosDeArreglo(ProductosDeProveedor2, 16, "Proveedor 2");
     MostrarProductosDeArreglo(ProductosElectronicos, 10, "Proveedor 3");*/

    Nodo *ListaDeProductos = CrearListaVacia();

    insertarArregloEnLista(&ListaDeProductos, ProductosDeProveedor1, 16);
    insertarArregloEnLista(&ListaDeProductos, ProductosDeProveedor2, 16);
    insertarArregloEnLista(&ListaDeProductos, ProductosElectronicos, 10);

    mostrarLista(ListaDeProductos, "Lista de provedor 1");

    Nodo * ProductosEnOferta = CrearListaVacia();

    filtroPorPrecio(ListaDeProductos, &ProductosEnOferta, 500);

    mostrarLista(ProductosEnOferta, "Lista filtrada");

    modificarPrecioPorPorcentaje(ProductosEnOferta,-10);

    mostrarLista(ProductosEnOferta, "Lista filtrada");

    int cantidad_producto_sinStock = ContarProductosSinStock(ListaDeProductos);
    printf("Cantidad de productos sin stock de la lista general:%d\n", cantidad_producto_sinStock);

    Nodo * ProductosSinStock = CrearListaVacia();

    extraerProductosSinStock(&ListaDeProductos,&ProductosSinStock);

    mostrarLista(ProductosSinStock, "Productos sin stockl");

    EliminarLista(&ListaDeProductos);
    EliminarLista(&ProductosEnOferta);
    EliminarLista(&ProductosSinStock);

    printf("Fin del programa.");
    return 0;
}

/*
recorrer el arrglo
tomar un producto
crear una copia del producto
guardar en el nodo
insertar el nodo en lista
*/