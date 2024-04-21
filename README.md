# Resolución TP 1
Todo el codigo esta contenido dentro de un notebook llamado `resolucion_tp.ipynb`.

## Requisitos Previos

Es necesario tener instalado Python y Jupyter Notebook. Asegúrate de tener también las siguientes librerías, las cuales son esenciales para la ejecución del notebook:

- numpy
- matplotlib

## Funciones importantes
### Ejercicio 1
Para resolver un sistema de ecuaciones, con Eliminación Gaussiana sin pivot hay que correr `solve_sys_EGsin(M)`, a esta función hay que pasarle una matriz extendida.

### Ejercicio 2
Para resolver un sistema de ecuaciones con float de 32 bits, en Eliminación Gaussiana sin pivot hay que correr `solve_sys_EG32(M, threshold)`, donde M es una matriz extendida y threshold es el alpha con el cual se compara si algo es igual a 0.

Para resolver un sistema de ecuaciones con float de 64 bits, en Eliminación Gaussiana sin pivot hay que correr `solve_sys_EG64(M, threshold)`, donde M es una matriz extendida y threshold es el alpha con el cual se compara si algo es igual a 0.

La `elim_gauss_con_pivot(M, threshold)` solo se dedica a triangular 

Donde M es una matriz extendida y threshold es el alpha con el cual se compara si algo es igual a 0.

### Ejercicio 3
#### Eliminacion Gaussiana para tridiagonales
Para resolver un sistema de ecuaciones tridiagonal, con Eliminación Gaussiana sin pivot hay que correr `sol_sys_tridiagonal(M)`, a esta función hay que pasarle una matriz extendida.

`elim_gauss_tridiagonal(M)` Solo se dedica a triangular matrices tridiagonales.
#### Algoritmo de Thomas
Para resolver un sistema de ecuaciones tridiagonal, con Eliminación Gaussiana sin pivot hay que correr `thomas?algorithm(a,b,c,d)` `a, b, c, d` son todos vectores que represetan distintas cosas. `a` seria la diagonal por debajo de la diagonal principal. `b` seria la diagonal principal. `c` la diagonal por arriba de la diagonal principal y `d` es el término independiente.

#### Algoritmo de Thomas con precómputo
Para resolver el sistema de ecuaciones con precómputo, primero hay que precomputar datos para luego poder resolver con la misma matriz distintos términos independientes.

Si queremos precomputar los datos debemos llamar `precomputo_de_thomas_algorithm(a,b,c)` `a`, `b`, `c` signidican lo mismo que antes. Esto nos va a llamar una lista de listas con todo lo necesario para resolver el sistema de ecuaciones con un termino independiente dado. Donde en su primer valor va haber una lista de distintos `w`. En el informe se reporta que son los `w`. En el segundo valor de la lista aparecen los `b` ya de el sistema de ecuaciones resueltos. Los `c`no son modificados.

Si queremos resolver el sistema de ecuaciones con precomputo 
`thomas_algorithm_precomputo(precomputo, d)` que te devuelve una vector solucion.


