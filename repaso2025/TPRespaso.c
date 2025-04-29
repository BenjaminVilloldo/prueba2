
#include "funciones.h"

void cargarListas(Nodo **ListaHard, Nodo **ListSoft, TProducto *productos, int cantidadProductos);
void actualizarDisponibilidad(Nodo *Lista, int *ids, int cantidad_id);
int CantidadProductosNoDisponibles(Nodo *Lista);
void EliminarProductosNoDisponibles(Nodo **Lista);


int main()
{
    TProducto *TodosLosProductos = ProductoElectronicos();

    // MostrarProductosDeArreglo(TodosLosProductos, 40, "Productos de Proveedor 1");

    Nodo *ListadoHardware = CrearListaVacia();
    Nodo *ListadoSoftware = CrearListaVacia();

    cargarListas(&ListadoHardware, &ListadoSoftware, TodosLosProductos, 40);

    

    int conjuntos_id[] = {1, 5, 10, 15, 20, 40};

    actualizarDisponibilidad(ListadoHardware, conjuntos_id, 6);
    actualizarDisponibilidad(ListadoSoftware, conjuntos_id, 6);

    mostrarLista(ListadoHardware, "Hardware");
    mostrarLista(ListadoSoftware, "Software");

    EliminarProductosNoDisponibles(&ListadoHardware);
    EliminarProductosNoDisponibles(&ListadoSoftware);
    
    mostrarLista(ListadoHardware, "Hardware");
    mostrarLista(ListadoSoftware, "Software");

    EliminarLista(&ListadoHardware);
    EliminarLista(&ListadoSoftware);
    

    /*fin del programa*/
    printf("\nFin programa\n");
    return 0;
}