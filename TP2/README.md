# Resolución TP 2
Casi todo el codigo esta contenido dentro de un notebook llamado `resolucion_tp.ipynb`, excepto por la implementancion del metodo potencia que se implemento en C++ que esta ubicado en la carpeta `src`. El makefile esta armado para poder integrar python con C++ con la libreria de pybind.

Para compilar correr `make` o `make all`. Para borrar los archivos compilados correr `make clean`.

## Requisitos Previos

Es necesario tener instalado Python y Jupyter Notebook, como también las siguientes librerías:

- numpy
- matplotlib
- scipy
- pandas
- subprocess
- time

Tambien es necesario tener instalado g++ o gcc con las siguietnes librerias:

- eigen
- pybind

## Funciones importantes
### Implementación de KNN iterativamente
Para ejecutar el clasificador implementado iterativamente podemos llamar a la funcion `knn_iterativo(image, images, images_types, k)` donde `image` es una lista que representando a una imagen cad pixel es un float que representa su intensidad, `images` es una matriz de imagenes representadas en listas, `images_types` es las clases de `images` siguiendo el mismo orden, representadas como un entero del 0 al 9 y por ultimo `k` es el número de vecinos. 

### Implementacion de KNN con NumPy
Para `knn(k, distances_matrix, start_index_desarrollo, end_index_desarrollo)` donde `k` es el número de vecinos, `distances_matrix` es una matriz donde cada elemento (i, j) representa la distancia entre la imagen i del conjunto de desarrollo y la imagen j del conjunto de entrenamiento, `start_index_desarrollo` y `end_index_desarrollo` son los índices para el subconjunto de desarrollo dentro de la matriz de distancias. 

#### Cálculo de matriz de distancias 
Para calcular las distancias entre dos conjuntos `A` y `B` de imágenes podemos llamar a la función `distanceMatrix(A, B)`, donde cada elemento (i, j) de la matriz resultante representa la distancia entre la imagen i de `A` y la imagen j de `B`.


### Power iteration
La función `power_iteration(const Matrix& A, unsigned niter, double eps)` implementada en C++ esta en `src/power_iteration.cpp`. Esta función de toma una matriz A, el número de iteraciones `niter` y la cota de error `eps`. 


### Power iteration con deflación
La función `power_iteration_deflation(const Matrix& A, int num, int niter, double eps)`, implementada en C++ tambien esta ubicada en `src/power_iteration.cpp`. Esta función de toma una matriz A, la cantidad de autovalores/autovectores que se desean encontrar `num`, el número de iteraciones `niter` y la cota de error `eps`. 


### Reconocedor de imágenes (Ejercicio 3.A)
Para simular un reconocedor de imágenes entre `X_test` y `X_train` usando KNN para un k fijo de 5 podemos llamar a la función`image_recognizer(X_test, X_train)`.

### Cross validation unicamente con knn (Ejercicio 3.B)
La funcion `cross_validation(start_k, end_k, X_train)` se encarga de hacer verficacion cruzada explorando el hiperparametro k de KNN. Esta funcion toma un rango de exploracion para distintos k's. `start_k` es el valor inicial de k en el rango de exploración para KNN. `end_k` es el valor final de k en el rango de exploración para KNN. `X_train` es el set de datos sobre el cual se le aplica knn.

### Implementación de PCA (Ejercicio 3.C)
Para realizar el Análisis de Componentes Principales de un conjunto de imágenes podemos llamar a la función `pca(dataset, niter, err)`, donde `dataset` es el conjunto de datos a analizar, `niter` es la cantidad de iteraciones que hará el método de deflación para calcular los autovectores y autovalores del conjunto y `err` es la tolerancia aplicada a este método.

### Varianza Explicada
La función `calculate_explaned_variance(D, p)` permite visualizar la cantidad de varianza explicada en función de la cantidad de componentes `p` . `D` es la matriz diagonal de autovalores generada por el algoritmo de PCA.


### Exploración Conjunta de los hiperparámetros k y p  (Ejercicio 3.D)
La función `cross_validation_pca_knn(X_train, ks, ps)` permite explorar los hiperparámetros k de KNN y p de PCA utilizando la técnica de cross validation sobre el conjunto de datos `X_train`. Se exploran los valores de k dentro del arreglo `ks` y los valores de p dentro del arreglo `ps`.

### Trainging vs Test LA PRUEBA FINAL
Para correr el resultado final hay que utilizar `training_vs_test(best_k, best_p)`. `best_k` es un entero que representa el mejor k hayado en `cross_validation_pca_knn(X_train, ks, ps)`. Lo mismo sucede con `best_p`, es el mejor p hayado después de haber corrido cross validation.

