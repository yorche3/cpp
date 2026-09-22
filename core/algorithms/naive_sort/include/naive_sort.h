#ifndef NAIVE_SORT_H
#define NAIVE_SORT_H

#include <vector>

// naive_sort — ordenamientos elementales O(n^2) sobre std::vector<int>.
// Especificación: 05_Naive_Sort.
// Contrato: (std::vector<int>) -> std::vector<int> ordenado; el vector vacío se devuelve igual.
namespace naive_sort {

// selection_sort: busca el mínimo del tramo no ordenado y lo intercambia con el inicio
// input: vector de enteros (se ordena una copia)
// output: vector ordenado de menor a mayor
std::vector<int> selection_sort(const std::vector<int> arr);

// bubble_sort: compara e intercambia adyacentes, con bandera de salida temprana
// input: vector de enteros (se ordena una copia)
// output: vector ordenado de menor a mayor
std::vector<int> bubble_sort(const std::vector<int> arr);

// insertion_sort: desplaza cada clave y la inserta en su posición del tramo ordenado
// input: vector de enteros (se ordena una copia)
// output: vector ordenado de menor a mayor
std::vector<int> insertion_sort(const std::vector<int> arr);

} // namespace naive_sort

#endif // NAIVE_SORT_H