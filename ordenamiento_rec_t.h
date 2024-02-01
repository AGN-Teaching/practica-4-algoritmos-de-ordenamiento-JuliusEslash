#ifndef ORDENAMIENTO_REC_T_H
#define ORDENAMIENTO_REC_T_H

#include "ordenamiento_t.h"

void merge(int A[], int inicio, int medio, int fin) {
    int *aux = new int[fin - inicio + 1];
    int i = inicio;     // índice de la primera mitad
    int j = medio + 1;  // índice de la segunda mitad
    int h = 0;

    // Se recorren ambos subarreglos y se van combinando sus
    // elementos ordenadamente hasta que se haya recorrido
    // totalmente uno de ellos
    while ((i <= medio) && (j <= fin)) {
        if (A[i] <= A[j]) {
            aux[h] = A[i];
            i += 1;
        } else {
            aux[h] = A[j];
            j += 1;
        }
        h += 1;
    }

    // Si se copiaron todos los elementos de la primera mitad,
    // se copia el resto de la segunda mitad
    if (i > medio) {
        while (j <= fin) {
            aux[h] = A[j];
            j += 1;
            h += 1;
        }
    } // Si no, se copia el resto de la primera mitad
    else {
        while (i <= medio) {
            aux[h] = A[i];
            i += 1;
            h += 1;
        }
    }
    
    h = 0;
    for (int k = inicio; k <= fin; k++) {
        A[k] = aux[h];
        h += 1;
    }
    delete [] aux;
}

    // Función de ordenamiento por fusión (merge sort)
    #include <algorithm> // Necesario para std::sort
    void merge_sort(int A[], int inicio, int fin, int k) {
        if (inicio < fin) {
            // Si el tamaño de la sublista es menor o igual a k, usar std::sort
            if (fin - inicio + 1 <= k) {
                std::sort(A + inicio, A + fin + 1);
            } else {
                int medio = (inicio + fin) / 2;
                merge_sort(A, inicio, medio, k);
                merge_sort(A, medio + 1, fin, k);
                merge(A, inicio, medio, fin);
            }
        }
    }







int partition(int A[], int p, int r) {
    // A[r] es el registro elegido cuya llave será el pivote
    int pivote = A[r];
    
    // Indica el índice del último registro cuyo valor
    // es menor a pivote
    int ultimo = p - 1;

    // Se agrupan los elementos menores a pivote en las primeras
    // posiciones de A
    for (int i = p; i < r; i++) {
        if (A[i] < pivote) {
            ultimo += 1;
            intercambiar(A, ultimo, i);
        }
    }

    // Y se mueve al pivote a su posición correcta
    intercambiar(A, ultimo + 1, r);
    return ultimo + 1;
}

void quicksort(int A[], int p, int r) {
    if (p < r) {
        int q = partition(A, p, r);
        quicksort(A, p, q - 1);
        quicksort(A, q + 1, r);
    }
}

 #endif // ORDENAMIENTO_REC_T_H