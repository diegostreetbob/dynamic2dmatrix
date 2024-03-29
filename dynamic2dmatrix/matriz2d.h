#ifndef MATRIZ2D_H
#define MATRIZ2D_H

////////////////////////////////////////////////////////////////////////////////
//Directivas de sustitución
////////////////////////////////////////////////////////////////////////////////
#define TRUE 1
#define FALSE 0
////////////////////////////////////////////////////////////////////////////////
//Declaración de tipos propios
////////////////////////////////////////////////////////////////////////////////
typedef struct _matriz2d{
  int **matriz;
  int nFilas;
  int nCols;
  int correcto;
  int f;
  int c;
  char nombre[20];
  int error;//o si no hay nigún error
}Matriz2d;
////////////////////////////////////////////////////////////////////////////////
//Declaración de funciones
////////////////////////////////////////////////////////////////////////////////
void **asignarMemoriaMatriz2D(int nFilas, int nCols, size_t tamElemento);
void liberarMemoriaMatriz2D(void **pm, int nFilas);
void mostrarMatriz(int **pm, int nFilas, int nCols);
Matriz2d menuCrearMatriz2d();
static void inicializarMatriz2d(Matriz2d matriz2d);

#endif /* MATRIZ2D_H */
