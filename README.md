[![Review Assignment Due Date](https://classroom.github.com/assets/deadline-readme-button-24ddc0f5d75046c5622901739e7c5dd533143b0c8e959d652212380cedb1ea36.svg)](https://classroom.github.com/a/ke8zCzPd)
[![Open in Codespaces](https://classroom.github.com/assets/launch-codespace-7f7980b617ed060a017424585567c406b6ee15c891e84e1186181d67ecf80aa0.svg)](https://classroom.github.com/open-in-codespaces?assignment_repo_id=13521303)
# Práctica 4: Algoritmos de ordenamiento

[![Review Assignment Due Date](https://classroom.github.com/assets/deadline-readme-button-24ddc0f5d75046c5622901739e7c5dd533143b0c8e959d652212380cedb1ea36.svg)](https://classroom.github.com/a/ke8zCzPd)
[![Open in Codespaces](https://classroom.github.com/assets/launch-codespace-7f7980b617ed060a017424585567c406b6ee15c891e84e1186181d67ecf80aa0.svg)](https://classroom.github.com/open-in-codespaces?assignment_repo_id=13521303)
# Práctica 4: Algoritmos de ordenamiento

#### Introducción.

El objetivo de esta práctica es realizar experimentos de rendimiento en algoritmos de ordenamiento para analizar y comparar su eficiencia en términos de tiempo de ejecución.

#### Descripción del programa ordenamiento.cpp.

En el archivo "ordenamiento.cpp" se ha desarrollado un programa en C++ que lleva a cabo experimentos para analizar y comparar el rendimiento de diferentes algoritmos de ordenamiento. Aquí está una descripción paso a paso del trabajo realizado en este archivo:

- *Librerías y Espacios de Nombres:*

* Se incluyen las librerías necesarias para el funcionamiento del programa, como <iostream>, <fstream>, <cstdlib>, <ctime>, <chrono>, <vector>, <numeric>. Además, se utiliza el espacio de nombres std y std::chrono para facilitar el uso de las funciones estándar.

- *Definición de Funciones:*

   * Se definen diversas funciones que realizan operaciones específicas:
        + "generarArregloAleatorio:" Genera un arreglo aleatorio de enteros.
        + "copiarArreglo:" Copia un arreglo en otro.
        + "realizarExperimento:" Realiza un experimento de ordenamiento con un algoritmo específico y devuelve el tiempo de ejecución.
        + "realizarRepeticiones:" Realiza múltiples repeticiones de experimentos y devuelve los tiempos de ejecución promedio.

- *Función Principal (main):*

* Se inicia el programa en la función main.
* Se verifica que el número de argumentos de línea de comandos sea correcto (3 argumentos: tamaño del arreglo, repeticiones).
* Se obtienen los parámetros del tamaño del arreglo y la cantidad de repeticiones desde los argumentos de línea de comandos.

- *Generación de Resultados:*

* Se realiza un bucle para cada repetición del experimento.
* Dentro de cada repetición, se ejecutan los algoritmos de ordenamiento (Insertion Sort, Selection Sort, Bubble Sort, Merge Sort, Quick Sort) para el tamaño de arreglo dado.
* Se calculan los tiempos promedio de ejecución de cada algoritmo a través de las repeticiones.

- *Generación de Archivo de Salida:*

* Se abre un archivo de salida llamado "resultados.txt" para escribir los resultados.
* Se imprime en el archivo un encabezado indicando las columnas correspondientes a los algoritmos.
* Se imprimen los resultados de cada repetición en formato tabular en el archivo.

- *Cierre del Archivo de Salida:*

Se cierra el archivo de salida después de imprimir todos los resultados.

- *Mensajes de Éxito:*

Se imprime un mensaje en la consola indicando que los experimentos han sido completados y que los resultados se han guardado en "resultados.txt".

#### Análisis del trabajo realizado
El trabajo realizado se enfocó en el desarrollo de un programa en C++ llamado ordenamiento.cpp. El programa es una herramienta completa y bien estructurada para realizar experimentos y comparar el rendimiento de diferentes algoritmos de ordenamiento, brindando flexibilidad y claridad en su implementación.

#### Descripción y modificación de la cabecera ordenamiento_rec_t.h.
ordenamiento_rec_t.h es un archivo de encabezado que contiene las declaraciones de funciones relacionadas con algoritmos de ordenamiento recursivos, específicamente merge_sort y quicksort. A continuación, se proporciona una descripción detallada de las funciones:

- *merge_sort:*
* Parámetros:
+ A[]: Arreglo de enteros que se va a ordenar.
+ inicio: Índice que representa el inicio de la sublista a ordenar.
+ fin: Índice que representa el final de la sublista a ordenar.
+ k: Tamaño umbral. Si el tamaño de la sublista es menor o igual a k, se utiliza std::sort para ordenarla.

* *Funcionamiento:*
+ Divide recursivamente la sublista en dos mitades.
+ Aplica recursivamente merge_sort a ambas mitades.
+ Combina las dos mitades ordenadas utilizando la función merge.
+ Si el tamaño de la sublista es menor o igual a k, utiliza std::sort.
+ Esta versión de merge_sort permite especificar un umbral (k) para cambiar a un método de ordenación diferente cuando la sublista es lo suficientemente pequeña.

- *partition y quicksort:*
* Parámetros:
+ A[]: Arreglo de enteros que se va a ordenar.
+ p: Índice que representa el inicio de la sublista a ordenar.
+ r: Índice que representa el final de la sublista a ordenar.

* *Funcionamiento:*
+ partition: Selecciona un elemento pivote y organiza los elementos alrededor del pivote.
+ quicksort: Aplica recursivamente el algoritmo de ordenación rápida a ambas mitades de la sublista.

El código también incluye una función intercambiar para realizar el intercambio de elementos en el arreglo.Esto sugiere que el archivo ordenamiento_rec_t.h está utilizando alguna funcionalidad definida en ordenamiento_t.h. Algunas de las funciones definidas en ordenamiento_t.h podrían estar siendo utilizadas en ordenamiento_rec_t.h, ya sea directa o indirectamente. 


- *Modificacion en el algoritmo merge_sort*

* En merge_sort, se ha agregado un nuevo parámetro k que se utiliza para determinar el umbral a partir del cual se usa std::sort en lugar de la recursión.
* Se ha agregado #include <algorithm> para utilizar la función std::sort.
* El código está envuelto en guardias de inclusión (#ifndef, #define, #endif) para evitar la inclusión múltiple en el caso de archivos de encabezado.

- *Descripción de los cambios en merge_sort*

1. *Agregado del parámetro k:* Se agregó un nuevo parámetro k a la función merge_sort. Este parámetro indica el tamaño máximo de la sublista para la cual se utilizará el algoritmo de ordenamiento std::sort en lugar de merge_sort. Si la sublista tiene un tamaño menor o igual a k, se utiliza std::sort directamente.

2. *Inclusión de <algorithm>:* Se incluyó la cabecera <algorithm> para utilizar la función std::sort dentro de la función merge_sort.

Estos cambios permiten optimizar el rendimiento del algoritmo merge_sort al usar std::sort para sublistas pequeñas, ya que std::sort es eficiente para arreglos pequeños. Esto puede mejorar la eficiencia del algoritmo en casos específicos.

#### Analisis del trabajo realizado.

En resumen, el archivo modificado de "ordenamiento_rec_t.h" presenta adaptaciones en la función merge_sort para integrar una versión optimizada del algoritmo, así como ajustes en la inclusión de cabeceras para facilitar la modularidad del código.

#### Descripción y modificacion del programa ordenamiento_rec_t.cpp.

El programa es un conjunto de funciones y experimentos diseñados para evaluar el rendimiento de dos algoritmos de ordenamiento: Merge Sort y QuickSort. El código incluye funciones para la generación de arreglos aleatorios, copia de arreglos, y la ejecución de los algoritmos de ordenamiento. Además, realiza múltiples repeticiones de los experimentos, calcula tiempos promedio y muestra los resultados. Se han realizado modificaciones en el algoritmo de Merge Sort para utilizar una versión optimizada cuando el tamaño de la sublista es menor o igual a un valor k, y estas modificaciones han sido reflejadas en los archivos ordenamiento_rec_t.h y ordenamiento_rec_t.cpp.

- *Modificación del archivo*

* Modificación en la función ordenar_merge_sort: La función ordenar_merge_sort ha sido modificada para incluir un tercer parámetro k. Esto coincide con la modificación realizada en la función merge_sort en el archivo ordenamiento_rec_t.h. Ahora, al invocar ordenar_merge_sort, se especifica el rango [inicio, fin] y el valor k.

* Actualización en el llamado de ordenar_merge_sort: Dentro de la función experimentos, el llamado a ordenar_merge_sort ahora incluye los parámetros 0 y TAM_ARREGLO - 1 para indicar el rango completo del arreglo.

* Uso de #include "ordenamiento_rec_t.h": En el archivo ordenamiento_rec_t.cpp, se mantiene la inclusión de la cabecera ordenamiento_rec_t.h para asegurar que las funciones definidas en esta cabecera estén disponibles para su uso.

* Cambio en los mensajes de salida: Se han ajustado los mensajes de salida para reflejar la modificación realizada en el nombre del algoritmo de ordenamiento (se añadió “MODIFICADO” a "MERGE SORT MODIFICADO").

#### Analisis del trabajo realizado 

El programa "ordenamiento_rec_t.cpp" modificado presenta adaptaciones para aprovechar las funciones comunes definidas en "ordenamiento_t.h" y ajustes en la función merge_sort para incorporar una estrategia de optimización específica. Esto mejora la modularidad y mantenibilidad del código.

#### Resumen de los resultados del programa ordenamiento.cpp

para este apartado se observa un analisis de los resultados de ejecucion en n (tamaño de arreglos) y m con 30 repeticiones.

## Nota:

Para entender un poco más este apartado es conveniente leer el archivo "tablas y gráficas.pdf" que contiene los resultados y sus respectivos gráficas de como se va manejando los 5 algoritmos en n (tamaño del arreglo). También en el archivo viene incluido su desviación estándar de los 5 algoritmos y el tiempo promedio en que se tarda.  

- *n=5:*
 En el caso de n=5 los algoritmos de ordenamiento más simples (Insertion Sort, Selection Sort y Bubble Sort) muestran tiempos competitivos y son eficientes para conjuntos pequeños. Merge Sort, conocido por su eficiencia en conjuntos grandes, presenta tiempos más altos en estos casos pequeños. Quick Sort destaca como uno de los algoritmos más rápidos incluso para tamaños pequeños de datos.

- *n=10*
 para n=10, los algoritmos de ordenamiento están mostrando tiempos de ejecución relativamente bajos, con Merge Sort y Quick Sort liderando en eficiencia. Esto es consistente con la esperanza de que algoritmos más avanzados superen a los simples para tamaños pequeños de n.

- *n=50*
 Para n=50, Insertion Sort, Merge Sort y Quick Sort son opciones eficientes, mientras que Selection Sort y Bubble Sort son menos eficientes, especialmente a medida que el tamaño del conjunto de datos crece.

 - *n=100*
 Para n=100, Quicksort muestra el mejor rendimiento promedio, seguido de cerca por Insertion Sort y Merge Sort. Bubble Sort tiene un rendimiento más lento en comparación con los otros algoritmos.

- *n=500*
 En términos generales, se mantiene la tendencia de eficiencia relativa de los algoritmos de ordenamiento, donde Quick Sort es generalmente el más rápido, seguido por Merge Sort. Los métodos más simples como Insertion Sort, Selection Sort y Bubble Sort tienden a ser más lentos para conjuntos de datos más grandes.

- *n=10^3*
En general, los tiempos se mantienen en rangos proporcionales a medida que aumenta n, lo que indica una eficiencia relativa constante del algoritmo en función del tamaño de entrada.

- *n=5x10^3*
En general, Quick Sort y Merge Sort continúan siendo los algoritmos más eficientes en este rango de tamaño de entrada. Aunque hay fluctuaciones, los tiempos de ejecución no parecen tener una tendencia clara, y los algoritmos de ordenamiento mantienen un rendimiento consistente.

- *n=10^4*
para n=10^4, se observa que el tiempo de mezcla (ms_t) y el tiempo de búsqueda cuaternaria (qs_t) son los componentes más significativos en términos de aumento. La eficiencia del algoritmo podría mejorarse optimizando estas operaciones, especialmente a medida que n continúa creciendo.

- *n=5x10^4*
Se observa un aumento en los tiempos de inicialización y suma de elementos.
La búsqueda binaria (bs_t) sigue mostrando un aumento logarítmico.
Mezcla de arreglos (ms_t) y ordenación rápida (qs_t) mantienen eficiencia.

- *n=10^5*
* Generación de Bloques: La generación de bloques es la operación más intensiva en tiempo debido al gran valor de n. Optimizaciones en este proceso podrían resultar en mejoras significativas.

* Mezcla de Bloques: La eficiencia en la mezcla de bloques es destacable, contribuyendo positivamente a la velocidad general del algoritmo.

* Generación de Secuencias: La generación de secuencias es rápida y eficiente, lo cual es beneficioso para el rendimiento general.


A partir de n = 5x10^5 en adelante a ejecución del algoritmo se vuelve prohibitivamente costosa a medida que aumenta el valor de n, hay varias razones fundamentales para esto:

1. Complejidad Computacional: A medida que n aumenta, la complejidad computacional del algoritmo de Fisher-Yates también aumenta considerablemente. La generación y mezcla de bloques se vuelven operaciones extremadamente demandantes en términos de tiempo y recursos.

2. Consumo de Recursos: Con valores tan grandes de n, la cantidad de memoria requerida para almacenar las secuencias y realizar operaciones como la generación y mezcla de bloques se vuelve exponencial. Esto puede llevar a un agotamiento rápido de los recursos disponibles en la máquina.

3. Eficiencia del Algoritmo: Aunque el algoritmo de Fisher-Yates es eficiente para tamaños moderados de n, no escala linealmente con valores muy grandes de n. Las operaciones que eran manejables para n más pequeños pueden volverse impracticables para n = 10^9 debido a la complejidad del algoritmo.

## Conclucion de la ejecucion del programa 

En resumen, para valores de n en el rango de 5x10^5 hasta 10^9, la ejecución del algoritmo de Fisher-Yates se ve comprometida debido a la creciente complejidad computacional, el consumo masivo de recursos y las limitaciones inherentes de hardware. En tales casos, se podrían explorar enfoques alternativos o algoritmos más escalables para manejar conjuntos de datos de esa magnitud.

#### Conclución Final.

El análisis del algoritmo de Fisher-Yates para la mezcla aleatoria de listas, hemos observado su eficacia en tamaños de lista moderadamente grandes, específicamente para n = 10^4 y 5x10^4. Sin embargo, al aumentar el tamaño de la lista a n = 10^5, notamos un incremento significativo en el tiempo de ejecución de las operaciones del algoritmo, lo que indica una disminución en la eficiencia.

Este aumento en la complejidad computacional puede deberse a varios factores, como la necesidad de manipular bloques más grandes de elementos durante la mezcla. A medida que n crece, el algoritmo enfrenta desafíos en términos de uso de recursos y tiempo de ejecución.

Además, se identifica limitaciones en la práctica al intentar ejecutar el algoritmo para valores de n mayores a 5x10^5 hasta 10^9, lo que sugiere que el algoritmo puede no ser adecuado para conjuntos de datos extremadamente grandes debido a restricciones de recursos y tiempo.

En resumen, aunque el algoritmo de Fisher-Yates es valioso para tamaños de lista moderados, es esencial considerar alternativas o ajustar estrategias al enfrentar conjuntos de datos más grandes. Cada aplicación específica requerirá una evaluación cuidadosa de la eficiencia y los recursos disponibles para garantizar un rendimiento óptimo.