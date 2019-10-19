////////////////////////////////////////////////////////////////////////////////
//PROGRAMA PARA TESTEAR CONSUMO DE RECURSOS REQUERIDO EN LAS OPERACIONES
//CON MATRICES
//diegostreetbob d761017@hotmail.com
////////////////////////////////////////////////////////////////////////////////
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "matriz2d.h"


int main()
{
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
    return 0;
}
