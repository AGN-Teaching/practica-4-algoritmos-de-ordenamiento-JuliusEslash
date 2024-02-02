#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <chrono>
#include <vector>
#include <numeric>

#include "ordenamiento_t.h"
#include "ordenamiento_rec_t.h"

using namespace std;
using namespace std::chrono;

void generarArregloAleatorio(int A[], int TAM_ARREGLO, int RANGO_MAX) {
    for (int i = 0; i < TAM_ARREGLO; i++) {
        A[i] = rand() % RANGO_MAX + 1;
    }
}

void copiarArreglo(const int A[], int B[], int TAM_ARREGLO) {
    copy(A, A + TAM_ARREGLO, B);
}

duration<double> realizarExperimento(int A[], int TAM_ARREGLO, char algoritmo) {
    high_resolution_clock::time_point inicio = high_resolution_clock::now();

    switch (algoritmo) {
        case 'i':
            insertion_sort(A, TAM_ARREGLO);
            break;
        case 's':
            selection_sort(A, TAM_ARREGLO);
            break;
        case 'b':
            bubblesort(A, TAM_ARREGLO);
            break;
        case 'm':
            merge_sort(A, 0, TAM_ARREGLO - 1, 0);
            break;
        case 'q':
            quicksort(A, 0, TAM_ARREGLO - 1);
            break;
        default:
            cerr << "Error: Algoritmo no reconocido." << endl;
            exit(EXIT_FAILURE);
    }

    high_resolution_clock::time_point fin = high_resolution_clock::now();
    return duration_cast<duration<double>>(fin - inicio);
}

vector<double> realizarRepeticiones(int TAM_ARREGLO, int REPETICIONES, char algoritmo) {
    vector<double> tiempos;

    for (int i = 0; i < REPETICIONES; i++) {
        int *A = new int[TAM_ARREGLO];
        int *B = new int[TAM_ARREGLO];

        generarArregloAleatorio(A, TAM_ARREGLO, 10 * TAM_ARREGLO);
        copiarArreglo(A, B, TAM_ARREGLO);

        duration<double> tiempo = realizarExperimento(B, TAM_ARREGLO, algoritmo);
        tiempos.push_back(tiempo.count());

        delete[] A;
        delete[] B;
    }

    return tiempos;
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        cerr << "Sintaxis: ordenamiento <tamaño_arreglo> <repeticiones>" << endl;
        exit(EXIT_FAILURE);
    }

    int TAM_ARREGLO = atoi(argv[1]);
    int REPETICIONES = atoi(argv[2]);

    srand(static_cast<unsigned>(time(nullptr)));

    ofstream archivoSalida("resultados.txt");
    if (!archivoSalida.is_open()) {
        cerr << "Error al abrir el archivo de salida." << endl;
        exit(EXIT_FAILURE);
    }

    // Imprimir encabezado en el archivo de salida
    archivoSalida << "#Ejec.\ti_t\ts_t\tb_t\tm_t\tq_t" << endl;

    for (int i = 0; i < REPETICIONES; i++) {
        archivoSalida << i + 1;

        char algoritmos[] = {'i', 's', 'b', 'm', 'q'};
        for (char algoritmo : algoritmos) {
            vector<double> tiempos = realizarRepeticiones(TAM_ARREGLO, 1, algoritmo);
            double promedio = accumulate(tiempos.begin(), tiempos.end(), 0.0) / tiempos.size();

            // Imprimir el tiempo actual en el archivo de salida
            archivoSalida << '\t' << promedio;
        }

        archivoSalida << endl;
    }

    archivoSalida.close();

    cout << "Experimentos completados. Resultados guardados en 'resultados.txt'" << endl;

    return EXIT_SUCCESS;
}
