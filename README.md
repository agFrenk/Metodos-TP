# Resolución TP 1
Todo el codigo esta contenido dentro de un notebook llamado `resolucion_tp.ipynb`.

## Requisitos Previos

Es necesario tener instalado Python y Jupyter Notebook, como también las siguientes librerías:

- numpy
- matplotlib

## Funciones importantes
### Ejercicio 1
Para resolver un sistema de ecuaciones con Eliminación Gaussiana sin pivoteo hay que correr la función `solve_sys_EGsin(M)`, con M una matriz extendida.

### Ejercicio 2
Para resolver un sistema de ecuaciones con float de 32 bits usando Eliminación Gaussiana con pivoteo hay que correr `solve_sys_EG32(M, threshold)`, donde M es una matriz extendida y threshold es el valor con el cual se compara si algo es cercano a 0.

Para resolver un sistema de ecuaciones con float de 64 bits usando Eliminación Gaussiana con pivoteo hay que correr `solve_sys_EG64(M, threshold)`, donde M es una matriz extendida y threshold es el valor con el cual se compara si algo es cercano a 0.

El método `elim_gauss_con_pivot(M, threshold)` solo se dedica a triangular la matriz extendida M. Los métodos `back_subs64(M)` o `back_subs32(M)` toma una matriz triangular superior y devuelve la solución al sistema de ecuaciones. 

### Ejercicio 3
#### Eliminacion Gaussiana para tridiagonales
Para resolver un sistema de ecuaciones tridiagonal con la formulación correspondiente de Eliminación Gaussiana hay que correr `sol_sys_tridiagonal(M)`, a esta función hay que pasarle una matriz extendida.

`elim_gauss_tridiagonal(M)` Solo se dedica a triangular matrices tridiagonales.

#### Algoritmo de Thomas
Para resolver un sistema de ecuaciones tridiagonal con el algoritmo de Thomas hay que correr `thomas_algorithm(a,b,c,d)` donde `a, b, c, d` son los vectores de la representación ímplicita de la matriz, donde  `b` seria la diagonal principal, `a` seria la subdiagonal por debajo de la diagonal principal,  `c` la diagonal por arriba de la diagonal principal y `d` es el término independiente.

#### Algoritmo de Thomas con precómputo
Para resolver el sistema de ecuaciones usando el algoritmo de Thomas con precómputo, primero hay que precomputar la matriz para luego poder resolver con la misma matriz el sistema con los distintos términos independientes.

Si queremos precomputar los datos debemos llamar `precomputo_de_thomas_algorithm(a,b,c)`, donde `a`, `b`, `c` significan lo mismo que antes. Esto nos va a devolver una lista de listas con todo lo necesario para resolver el sistema de ecuaciones con un termino independiente dado. Donde en su primer valor va haber una lista de distintos `w`. En el informe se reporta que son los `w`. En el segundo valor de la lista aparecen los `b` ya de el sistema de ecuaciones resueltos.

Si queremos resolver el sistema de ecuaciones con precomputo debemos correr la funcion `thomas_algorithm_precomputo(precomputo, d)` con el precomputo obtenido anteriormente y un vector  que te devuelve una vector `d` con el término independiente.

### Ejercicio 4
### Experimentación - Verificación de la implementación del método tridiagonal

Para relizar el experimento de verificación de la implementación del método tridiagonal debemos llamar a la función `verificacion_exp(ds):`, donde ds es un arreglo que contiene tres arreglos d_a, d_b y d_c de tamaños 100, 101 y 100 respectivamente. Estos tres arreglos corresponderán a los términos independientes de tres sistemas de ecuaciones tridiagonales cuya matriz asociada es la matriz tridiagonal Laplaciana de tamaño 101. Para ello, el código utiliza la función `precomputo_de_thomas_algorithm(a, b, c)` de manera que puedan precomputarse los valores necesarios para resolver los sistemas de la manera más eficiente posible. La función principal también se encarga de generar el gráfico correspondiente al experimento, sin necesidad de llamar a ninguna otra función. 
En nuestro caso, los arreglos d_a, d_b, y d_c fueron proporcionados en la consigna del trabajo. 

### Ejercicio 5
### Ítem a
### Experimentación - Medición de tiempos de Cómputo EG Pivot vs. EG Tridiagonal
Para relizar el experimento de medición de tiempos de Cómputo EG vs. EG pivot debemos llamar a la función `experimentoEG_EGT():` . Esta función llama a su vez a la función `create_laplaciano_testing_instace()` para crear distintas instancias de sistemas de ecuaciones tridiagonales, asociados siempre a la matriz Laplaciana, pero variando en el tamaño de la matriz. Luego compara el tiempo que tarda cada uno de los dos algoritmos en resolver el sistema. Para ver los resultados gráficamente, hay que llamar a la función `plot_eg()`

### Ejercicio 5
### Ítem b
### Experimentación - Medición de tiempos de Cómputo EG tridiagonal vs. Algoritmo de Thomas
Para relizar el experimento de medición de tiempos de Cómputo EG Tridiagonal vs. Algoritmo de Thomas debemos llamar a la función `experimentoEGT_ThA()`. Esta función resolverá el sistema para la matriz Laplaciana de tamaño 100, y medirá el tiempo que tarda cada algoritmo en resolverlo para una determinada cantidad de repeticiones. Para ver los resultados gráficamente, hay que llamar a la función `plot_eg()`

## Ejercicio 6















