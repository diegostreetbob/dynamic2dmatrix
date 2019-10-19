////////////////////////////////////////////////////////////////////////////////
//MATRIZ DINÁMICA DE 2 DIMENSIONES
////////////////////////////////////////////////////////////////////////////////
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "matriz2d.h"
////////////////////////////////////////////////////////////////////////////////
//EJEMPLO DE USO DENTRO DE UN MAIN
////////////////////////////////////////////////////////////////////////////////
    /*    
    Matriz2d matriz2d;
    matriz2d = menuCrearMatriz2d();
    if(matriz2d.error == 0)
    {
        mostrarMatriz(matriz2d.matriz, matriz2d.nFilas, matriz2d.nCols);
        liberarMemoriaMatriz2D(matriz2d.matriz, matriz2d.nFilas);
    }else
    {
        printf("Ha ocurrido un error vuelve a intentarlo");
    }
    */
////////////////////////////////////////////////////////////////////////////////
//FUNCION PARA CREAR UNA MATRIZ2D CON VALORES INT EN FUNCIÓN DE LOS DATOS INTRU-
//DUCIDOS POR TECLADO.
////////////////////////////////////////////////////////////////////////////////
Matriz2d menuCrearMatriz2d(){
    Matriz2d matriz2d;
    inicializarMatriz2d(matriz2d);
    do
    {
    printf("Nombre de la matriz:             ");
    //correcto = scanf("%d", &nFilas);
    matriz2d.correcto = scanf("%s", &matriz2d.nombre);
    while (getchar() != '\n') continue; // limpiar buffer
    }while (!matriz2d.correcto);
    //
    do
    {
    printf("Numero de filas de la matriz:    ");
    //correcto = scanf("%d", &nFilas);
    matriz2d.correcto = scanf("%d", &matriz2d.nFilas);
    while (getchar() != '\n') continue; // limpiar buffer
    }while (!matriz2d.correcto || matriz2d.nFilas < 1);
    //
    do
    {
    printf("Numero de columnas de la matriz: ");
    matriz2d.correcto = scanf("%d", &matriz2d.nCols);
    while (getchar() != '\n') continue; // limpiar buffer
    }while (!matriz2d.correcto || matriz2d.nCols < 1);
    //
    // Asignar memoria para la matriz 2D
    matriz2d.matriz = (int **)asignarMemoriaMatriz2D(matriz2d.nFilas, matriz2d.nCols, sizeof(int));
    //if (m == NULL)
    if (matriz2d.matriz == NULL)
    {
        printf("Insuficiente espacio de memoria\n");
        matriz2d.error=1;//Memoria insuficiente
    }else
    {
        return matriz2d;
    }
}
////////////////////////////////////////////////////////////////////////////////
/**
 * MÉTODO PARA INICIALIZAR TYPEDEF STRUCT
 * @param matriz2d typedef struct
 */
static void inicializarMatriz2d(Matriz2d matriz2d){
    matriz2d.matriz = NULL;
    matriz2d.c=0;
    matriz2d.correcto=0;
    matriz2d.f=0;
    matriz2d.nCols=0;
    matriz2d.nFilas=0;
    strcpy(matriz2d.nombre,"          ");
    matriz2d.error=0;
}
////////////////////////////////////////////////////////////////////////////////
/**
 * MÉTODO PARA CREACIÓN DE UNA MATRIZ 2D, ASIGNA LA MEMORIA NECESARIA Y LA INI-
 * CIALIZA CON NÚMERO ALEATORIOS
 * @param nFilas número de filas de la matriz
 * @param nCols  número de columnas de la matriz
 * @param tamElemento tamaño de cada elemento de la matriz
 * @return puntero a matriz
 */
void **asignarMemoriaMatriz2D(int nFilas, int nCols, size_t tamElemento) 
{
    void **p = 0;
    int i = 0;
    // Asignar memoria para la matriz de punteros
    p = (void **) malloc(nFilas * sizeof (void *));
    if (p == NULL) return NULL;
    // Asignar memoria para cada una de las filas
    for (i = 0; i < nFilas; i++) {
        p[i] = malloc(nCols * tamElemento);
        if (p[i] == NULL) {
            // Liberar la memoria asignada hasta este instante
            liberarMemoriaMatriz2D(p, i);
            return NULL;
        }
        // Iniciar la fila con ceros
        //memset(p[i], 0, nCols * tamElemento);
        memset(p[i], rand(), nCols * tamElemento);
    }
    return p;
}
////////////////////////////////////////////////////////////////////////////////
/**
 * METODO PARA LIBERAR LA MEMORIA OCUPADA POR LA MATRIZ
 * @param pm puntero a matriz, da igual del tipo que sea 
 * @param nFilas número de filas
 */
void liberarMemoriaMatriz2D(void **pm, int nFilas)
{
  int f = 0;
  // Liberar la memoria asignada a cada una de las filas
  for (f = 0; f < nFilas; f++)
    free(pm[f]);
  // Liberar la memoria asignada a la matriz de punteros
  free(pm);
}
////////////////////////////////////////////////////////////////////////////////
/**
 * MÉTODO PARA MOSTRAR LA MATRIZ POR PANTALLA
 * @param pm puntero a matriz
 * @param nFilas número de filas
 * @param nCols número de columnas
 */
void mostrarMatriz(int **pm, int nFilas, int nCols)
{
  int f = 0, c = 0;
  for (f = 0; f < nFilas; f++)
  {
    for (c = 0; c < nCols; c++)
      printf("%d  ", pm[f][c]);
    printf("\n");
  }
}
////////////////////////////////////////////////////////////////////////////////