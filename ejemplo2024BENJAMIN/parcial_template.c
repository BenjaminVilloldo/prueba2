/*
 *    AUTHOR: Catedra de lenguajes de Taller 1
 *    DATE: 05/2024
 *    LICENCE: Creative Commons
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.h"

// DECLARE SUS FUNCIONES ACA
void cargarListas(Nodo **listaTucu, Nodo **listaSalta, Producto *ProductoElectronicos, int cant);
void MostrarLista(Nodo *lista, const char *tituloLista);
void cambiarAInactivo(Nodo *lista, Nodo *lista2); //punto 2

//punto 3
Nodo *AislarNodoInactivo(Nodo **lista, int activo);
void eliminarInactivos(Nodo **lista);
//punto 4
void moverADeposito(Nodo **lista, Nodo **listaDeposito);
//punto 5
Nodo *AislarPrimerNodo(Nodo **Lista);
void EliminarLista(Nodo **Lista);

int main()
{
    int cantInactivos;
    Producto *TodosLosProductos = ProductoElectronicos();

    MostrarProductosDeArreglo(TodosLosProductos, 40, "Productos de Proveedor 1");

    //LISTAS
    Nodo *listaTucuman = CrearListaVacia();
    Nodo *listaSalta = CrearListaVacia();
    Nodo *listaRepositorio = CrearListaVacia();

    // PUNTO 1. mover del arreglo los productos a la lista correspondiente según la sucursal de destino

    printf("---------------PUNTO 1---------------\n");
    cargarListas(&listaTucuman,&listaSalta,TodosLosProductos, 40);
    MostrarLista(listaTucuman,"TUCUMAN PUNTO 1");
    MostrarLista(listaSalta,"SALTA PUNTO 1");
    MostrarLinea();
    // FIN PUNTO 1

    
    // PUNTO 2. marque como inactivo los productos ingresados por el usuario
    printf("---------------PUNTO 2---------------\n");
  
    cambiarAInactivo(listaTucuman,listaSalta);
    
    MostrarLista(listaTucuman,"ACTUALIZADO PUNTO 2");
    MostrarLista(listaSalta,"ACTUALIZADO PUNTO 2");
    

    // Aquí puedes hacer lo que necesites con el ID para cada sucursal
    // Llame a sus funciones aqu

    // FIN PUNTO 2

    printf("---------------PUNTO 3---------------\n");
    // PUNTO 3. eliminar inactivos
    // Llame a sus funciones aquí
    cantInactivos = cantidadProductosInactivos(listaSalta,listaTucuman);
    printf("bandera");
    eliminarInactivos(&listaSalta);
    eliminarInactivos(&listaTucuman);
    MostrarLista(listaTucuman, "LISTA DE TUCUMAN SIN INACTIVOS PUNTO 3");
    MostrarLista(listaSalta, "LISTA DE SALTA SIN INACTIVOS PUNTO 3");
    

    // FIN PUNTO 3

    printf("---------------PUNTO 4---------------\n");
    // PUNTO 4. Pasar a la lista deposito desde Tucumán, cuando el total de stock de la sucursal Tucumán supere los 40 elementos
    // Llame a sus funciones aquí

    moverADeposito(&listaTucuman,&listaRepositorio);
    MostrarLista(listaRepositorio,"LISTA REPOSITORIO PUNTO 4");

    // FIN PUNTO 4

    printf("---------------PUNTO 5---------------\n");

    // PUNTO 5. libere la memoria reservada.
    // Llame a sus funciones aquí
    EliminarLista(&listaTucuman);
    EliminarLista(&listaSalta);
    EliminarLista(&listaRepositorio);
    // FIN PUNTO 5

    /*CHEQUEO DE FIN*/
    if (listaTucuman == NULL && listaSalta == NULL && listaRepositorio == NULL)
    {
        printf("\nFin parcial\n");
    }else
    {
        printf("No se elimaron bien.");
    }
    
    
    return 0;
}

// IMPLEMENTE SUS FUNCIONES ACA
