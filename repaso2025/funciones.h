#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct TProducto
{
    int Id;
    char *Nombre;
    char *Categoria;
    int Stock;
    float Precio;
    int Activo;
} TProducto;

typedef struct Nodo
{
    TProducto producto;
    struct Nodo *siguiente;
} Nodo;

TProducto *ProductoElectronicos();
void MostrarProductosDeArreglo(TProducto *producto, int cantidad, const char *Titulo);
TProducto CrearProducto(const char *nombre, const char *categoria, int id, int stock, float precio);
void MostrarProducto(TProducto prod);

TProducto *ProductoElectronicos()
{
    TProducto *Productos = (struct TProducto *)malloc(sizeof(struct TProducto) * 40);

    Productos[0] = CrearProducto("Placa madre GigaBlast", "Hardware", 1, 15, 1200);
    Productos[1] = CrearProducto("Simulador de clics infinito", "Software", 2, 5, 500);
    Productos[2] = CrearProducto("Memoria RAM HiperXtreme 16GB", "Hardware", 3, 10, 900);
    Productos[3] = CrearProducto("Compilador de pensamientos", "Software", 4, 3, 1800);
    Productos[4] = CrearProducto("Placa de video Dragón RTX9090", "Hardware", 5, 4, 3000);
    Productos[5] = CrearProducto("Sistema Operativo GatOS", "Software", 6, 12, 1000);
    Productos[6] = CrearProducto("Disco sólido 2TB TruenoSSD", "Hardware", 7, 7, 950);
    Productos[7] = CrearProducto("Suite Ofimática OjoSoft", "Software", 8, 15, 800);
    Productos[8] = CrearProducto("Fuente de poder Nuclear 800W", "Hardware", 9, 6, 1200);
    Productos[9] = CrearProducto("Editor de memes profesional", "Software", 10, 2, 600);
    Productos[10] = CrearProducto("Gabinete con luces de feria", "Hardware", 11, 5, 1100);
    Productos[11] = CrearProducto("Antivirus contra spoilers", "Software", 12, 10, 700);
    Productos[12] = CrearProducto("Kit de ventiladores RGB", "Hardware", 13, 9, 400);
    Productos[13] = CrearProducto("Juego 'Cosecha de Bits'", "Software", 14, 8, 1300);
    Productos[14] = CrearProducto("Adaptador universal para todo", "Hardware", 15, 3, 600);
    Productos[15] = CrearProducto("Calculadora cuántica v2.1", "Software", 16, 6, 1500);
    Productos[16] = CrearProducto("Teclado mecánico DragonFlame", "Hardware", 17, 7, 850);
    Productos[17] = CrearProducto("Traductor de emojis a texto", "Software", 18, 1, 450);
    Productos[18] = CrearProducto("Mouse gamer con cohete", "Hardware", 19, 4, 950);
    Productos[19] = CrearProducto("Simulador de programación", "Software", 20, 2, 1000);
    Productos[20] = CrearProducto("Router WiFi con sonido envolvente", "Hardware", 21, 3, 1400);
    Productos[21] = CrearProducto("ChatBot emocional v3.0", "Software", 22, 1, 1700);
    Productos[22] = CrearProducto("Monitor UltraWide SuperCurvo", "Hardware", 23, 2, 2500);
    Productos[23] = CrearProducto("Editor de memes de gatos AI", "Software", 24, 5, 900);
    Productos[24] = CrearProducto("Procesador OctaCore Lagfree", "Hardware", 25, 6, 3200);
    Productos[25] = CrearProducto("Sistema de gestión de tiempo perdido", "Software", 26, 3, 1500);
    Productos[26] = CrearProducto("Impresora 3D para stickers", "Hardware", 27, 4, 2800);
    Productos[27] = CrearProducto("Aplicación de alarmas personalizadas con voz de gato", "Software", 28, 2, 700);
    Productos[28] = CrearProducto("Auriculares envolventes 9.1", "Hardware", 29, 8, 1600);
    Productos[29] = CrearProducto("Simulador de vacaciones", "Software", 30, 6, 2000);
    Productos[30] = CrearProducto("Cámara web con filtro fantasía", "Hardware", 31, 1, 1300);
    Productos[31] = CrearProducto("Editor de fotos vintage automático", "Software", 32, 4, 1200);
    Productos[32] = CrearProducto("Refrigeración líquida IceBlast", "Hardware", 33, 2, 2200);
    Productos[33] = CrearProducto("Antiestrés digital con IA", "Software", 34, 9, 1100);
    Productos[34] = CrearProducto("Controlador universal para todo lo que se enchufa", "Hardware", 35, 7, 1700);
    Productos[35] = CrearProducto("Sistema de backup por telepatía", "Software", 36, 1, 1900);
    Productos[36] = CrearProducto("Mini dron USB espía (legal)", "Hardware", 37, 5, 2500);
    Productos[37] = CrearProducto("Calculadora de memes", "Software", 38, 2, 800);
    Productos[38] = CrearProducto("Pantalla portátil enrollable", "Hardware", 39, 4, 2100);
    Productos[39] = CrearProducto("Generador de excusas para entregar trabajos tarde", "Software", 40, 3, 600);

    return Productos;
}

TProducto CrearProducto(const char *nombre, const char *categoria, int id, int stock, float precio)
{
    TProducto nuevo;

    nuevo.Id = id;
    nuevo.Nombre = (char *)malloc(strlen(nombre) + 1);
    strcpy(nuevo.Nombre, nombre);

    nuevo.Categoria = (char *)malloc(strlen(categoria) + 1);
    strcpy(nuevo.Categoria, categoria);

    nuevo.Stock = stock;
    nuevo.Precio = precio;
    nuevo.Activo = 1; // Por defecto activo

    return nuevo;
}

void MostrarLinea()
{
    printf("\n---------------------------\n");
}

void MostrarTextoYValor(const char *tituloLista, int cantidad)
{
    printf("\n");
    printf("%s - %d \n", tituloLista, cantidad);
}

void MostrarProductosDeArreglo(TProducto *producto, int cantidad, const char *Titulo)
{
    printf("%s \n\r", Titulo);
    MostrarLinea();
    for (int i = 0; i < cantidad; i++)
    {
        MostrarProducto(producto[i]);
    }
    MostrarLinea();
}

void MostrarProducto(struct TProducto producto)
{
    printf("%2d - %-10s | %-40s | $%7.2f | Stock: %2d | Activo: %d\n",
           producto.Id,
           producto.Categoria,
           producto.Nombre,
           producto.Precio,
           producto.Stock,
           producto.Activo);
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
    free(nodo->producto.Nombre);
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

Nodo *QuitarNodoNoDiposnible(Nodo **Lista, int activo)
{
    Nodo *nodoAux = *Lista;
    Nodo *nodoAnt = NULL;

    while (nodoAux != NULL && nodoAux->producto.Activo != activo)
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

Nodo *QuitarUltimoNodo(Nodo **Lista)
{
    if (EsListaVacia(*Lista))
    {
        return NULL;
    }

    Nodo *actual = *Lista;
    Nodo *anterior = NULL;

    while (actual->siguiente != NULL)
    {
        anterior = actual;
        actual = actual->siguiente;
    }

    if (anterior == NULL)
    {
        *Lista = NULL;
    }
    else
    {
        anterior->siguiente = NULL;
    }

    actual->siguiente = NULL;
    return actual;
}

//-------------------------------------------------------------------------------------------------
char Sucursal[3][15] =
    {
        "Tucuman", "Salta", "Deposito"};

        void cargarListas(Nodo **ListaHard, Nodo **ListSoft, TProducto *productos, int cantidadProductos)
        {
            TProducto producto;
            Nodo *nuevo_nodo = NULL;
            for (int i = 0; i < cantidadProductos; i++)
            {
                producto = productos[i];
                nuevo_nodo = CrearNodo(producto);
                if (strcmp(nuevo_nodo->producto.Categoria, "Hardware") == 0)
                {
                    InsertarNodoEnLista(ListaHard, nuevo_nodo);
                }
                else
                {
                    InsertarNodoEnLista(ListSoft, nuevo_nodo);
                }
            }
        }
        
        void actualizarDisponibilidad(Nodo *Lista, int *ids, int cantidad_id)
        {
            Nodo *ListaAux = Lista;
            for (int i = 0; i < cantidad_id; i++)
            {
                while (!EsListaVacia(ListaAux))
                {
                    if (ListaAux->producto.Id == ids[i])
                    {
                        ListaAux->producto.Activo = 0;
                        break;
                    }
                    ListaAux = ListaAux->siguiente;
                }
                ListaAux = Lista;
            }
        }
        
        int CantidadProductosNoDisponibles(Nodo *Lista)
        {
            int cantidad_productos = 0;
            if (EsListaVacia(Lista))
                return 0;
        
            while (!EsListaVacia(Lista))
            {
                if (Lista->producto.Activo == 0)
                {
                    cantidad_productos++;
                }
                Lista = Lista->siguiente;
            }
            return cantidad_productos;
        }
        
        void EliminarProductosNoDisponibles(Nodo **Lista)
        {
            int cantidad_productos = CantidadProductosNoDisponibles(*Lista);
            Nodo *nodo_quitado = NULL;
            for (int i = 0; i < cantidad_productos; i++)
            {
                nodo_quitado = QuitarNodoNoDiposnible(Lista, 0);
                EliminarNodo(nodo_quitado);
            }
        }
        
        