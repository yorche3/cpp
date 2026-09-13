# Naive Sort — C++

Implementación de la especificación [05_Naive_Sort](https://yorche3.github.io/programming_languages/core/algorithms/05_Naive_Sort/) en **C++**, utilizando **Bazelisk** (Bazel) y **Google Test** para las pruebas unitarias.

Implementa los tres algoritmos elementales de ordenamiento ($O(n^2)$) — **Selection Sort**, **Bubble Sort** e **Insertion Sort** — sobre `std::vector<int>`, devolviendo una copia ordenada de la entrada, sin usar `std::sort` ni estructuras auxiliares.

---

## 📂 Archivos y estructura / Files & Structure

| Archivo / Directorio | Propósito / Purpose |
|----------------------|---------------------|
| [`include/naive_sort.h`](include/naive_sort.h) | Cabecera: declara las 3 funciones públicas en `namespace naive_sort`. / Header: declares the 3 public functions in `namespace naive_sort`. |
| `src/naive_sort.cpp` | Implementación de los 3 algoritmos. / Implementation of the 3 algorithms. |
| `tests/naive_sort_test.cpp` | Suite Google Test: 3 tests con 21 aserciones (7 casos × 3 algoritmos). / Google Test suite: 3 tests with 21 assertions (7 cases × 3 algorithms). |
| `BUILD` | Configuración de Bazel (targets `naive_sort_lib`, `naive_sort_tests`). / Bazel configuration (targets `naive_sort_lib`, `naive_sort_tests`). |
| `MODULE.bazel` | Dependencia externa Google Test vía Bzlmod. / Google Test external dependency via Bzlmod. |
| `WORKSPACE` | Raíz del espacio de trabajo (legacy/compatibilidad). / Workspace root (legacy/compatibility). |
| `.bazelversion` | Versión fija de Bazel para el proyecto. / Pinned Bazel version for the project. |
| `.gitignore` | Artefactos de compilación ignorados. / Ignored build artifacts. |

**Estructura de directorios esperada / Expected directory structure:**

```text
naive_sort/
├── BUILD                     # Reglas de Bazel / Bazel rules
├── MODULE.bazel              # Dependencias de Bazel / Bazel dependencies
├── WORKSPACE                 # Espacio de trabajo / Workspace
├── include/
│   └── naive_sort.h          # Declaraciones (interfaz) / Declarations (interface)
├── src/
│   └── naive_sort.cpp        # Implementaciones / Implementations
├── tests/
│   └── naive_sort_test.cpp   # 21 aserciones / 21 assertions
├── .bazelversion
├── .gitignore
└── README.md
```

---

## 🛠️ Enfoque y construcción / Approach & Build

**ES:** El proyecto se configuró manualmente con **Bazel** como sistema de construcción. En lugar de compilar archivos individuales, Bazel descarga la dependencia (**Google Test**) y vincula la librería de forma automática. La implementación sigue el estilo imperativo/estructurado de C++ (sin usar `std::sort`) y el contrato de la especificación.

**EN:** The project was manually configured with **Bazel** as the build system. Instead of compiling individual files, Bazel downloads the dependency (**Google Test**) and links the library automatically. The implementation follows C++'s imperative/structured style (without using `std::sort`) and the specification contract.

### Pasos de inicialización / Initialization steps

1. **Definir el módulo / Define the module**: `MODULE.bazel` importa Google Test.
2. **Configurar el BUILD / Configure the BUILD**: un `cc_library` para la lógica y un `cc_test` para las pruebas.
3. **Ejecutar con Bazelisk / Run with Bazelisk**: `bazelisk` garantiza que todos usen la misma versión de Bazel.

---

## 📄 Archivos de configuración clave / Key Configuration Files

### `BUILD` — Targets de Bazel / Bazel targets

**ES:** Define dos targets:
- `naive_sort_lib` (`cc_library`): compila `src/naive_sort.cpp` con la cabecera `include/naive_sort.h`.
- `naive_sort_tests` (`cc_test`): compila `tests/naive_sort_test.cpp` contra `naive_sort_lib` y `gtest_main`.

**EN:** Defines two targets:
- `naive_sort_lib` (`cc_library`): builds `src/naive_sort.cpp` with the `include/naive_sort.h` header.
- `naive_sort_tests` (`cc_test`): builds `tests/naive_sort_test.cpp` against `naive_sort_lib` and `gtest_main`.

### `MODULE.bazel` — Manifiesto de dependencias / Dependency manifest

**ES:** Usa **Bzlmod** para declarar `googletest` versión `1.15.2` y fija Bazel `7.1.1` en `.bazelversion`.

**EN:** Uses **Bzlmod** to declare `googletest` version `1.15.2` and pins Bazel `7.1.1` in `.bazelversion`.

### Interfaz pública / Public interface

```cpp
namespace naive_sort {

std::vector<int> selection_sort(const std::vector<int> arr);
std::vector<int> bubble_sort(const std::vector<int> arr);
std::vector<int> insertion_sort(const std::vector<int> arr);

} // namespace naive_sort
```

---

## 🚀 Compilación y ejecución / Build & Run

### Compilar / Build

```bash
bazelisk build //...
```

### Ejecutar pruebas / Run tests

```bash
# Todas las pruebas / All tests
bazelisk test //...

# Solo este módulo / Only this module
bazelisk test //:naive_sort_tests

# Con salida detallada de Google Test / With detailed Google Test output
bazelisk test //:naive_sort_tests --test_output=all
```

**Salida real / Actual output:**

```text
[==========] Running 3 tests from 1 test suite.
[ RUN      ] NaiveSortTest.selection_sort
[       OK ] NaiveSortTest.selection_sort (0 ms)
[ RUN      ] NaiveSortTest.bubble_sort
[       OK ] NaiveSortTest.bubble_sort (0 ms)
[ RUN      ] NaiveSortTest.insertion_sort
[       OK ] NaiveSortTest.insertion_sort (0 ms)
[==========] 3 tests from 1 test suite ran. (0 ms total)
[  PASSED  ] 3 tests.
//:naive_sort_tests                                                      PASSED
```

---

## 🧠 Algoritmos y operaciones / Algorithms & Operations

| Función / Function | Enfoque / Approach | Descripción / Description | Complejidad / Complexity |
|--------------------|:------------------:|---------------------------|--------------------------|
| `selection_sort` | `ite` | Busca el mínimo del tramo no ordenado y lo intercambia al inicio. / Finds the minimum of the unsorted part and swaps it to the front. | $O(n^2)$ siempre / always |
| `bubble_sort` | `ite` | Compara e intercambia adyacentes; incluye **salida temprana** con la bandera `swapped`. / Compares and swaps adjacent items; includes **early exit** with the `swapped` flag. | $O(n^2)$ peor/promedio, $O(n)$ mejor / worst/average, $O(n)$ best |
| `insertion_sort` | `ite` | Inserta cada elemento en su posición dentro del sub-vector ya ordenado. / Inserts each element into its position within the already sorted sub-vector. | $O(n^2)$ peor/promedio, $O(n)$ mejor / worst/average, $O(n)$ best |

### Casos de prueba / Test cases

Cada algoritmo valida los mismos 7 casos (21 aserciones en total) / Each algorithm validates the same 7 cases (21 assertions in total):

| # | Caso / Case | Entrada / Input | Salida esperada / Expected output |
|---|-------------|-----------------|-----------------------------------|
| 1 | Array desordenado / Unsorted array | `{5, 2, 9, 1, 5, 6}` | `{1, 2, 5, 5, 6, 9}` |
| 2 | Ya ordenado / Already sorted | `{1, 2, 3, 4, 5}` | `{1, 2, 3, 4, 5}` |
| 3 | Orden inverso / Reverse order | `{5, 4, 3, 2, 1}` | `{1, 2, 3, 4, 5}` |
| 4 | Idénticos / Identical elements | `{7, 7, 7, 7}` | `{7, 7, 7, 7}` |
| 5 | Negativos / Negative numbers | `{3, -1, 4, -5, 0}` | `{-5, -1, 0, 3, 4}` |
| 6 | Un elemento / Single element | `{42}` | `{42}` |
| 7 | Vacío / Empty | `{}` | `{}` |

---

## 📝 Notas de implementación / Implementation Notes

### Sobre la implementación / On the implementation

- **ES:** Las tres funciones reciben el vector **por valor** y devuelven una **copia ordenada**, de modo que los fixtures compartidos por los tests nunca se mutan. La especificación permite ordenar in-place o devolver una copia.
- **EN:** All three functions take the vector **by value** and return a **sorted copy**, so the fixtures shared by the tests are never mutated. The specification allows sorting in place or returning a copy.
- **ES:** `bubble_sort` implementa la **optimización de salida temprana** con la bandera `swapped` (criterio de aceptación de la especificación): si una pasada no realiza intercambios, el bucle termina, alcanzando $O(n)$ en el mejor caso.
- **EN:** `bubble_sort` implements the **early-exit optimization** with the `swapped` flag (specification acceptance criterion): if a pass performs no swaps, the loop stops, achieving $O(n)$ in the best case.
- **ES:** `selection_sort` intercambia siempre en cada pasada; el intercambio de un elemento consigo mismo es un no-op, por lo que el resultado es equivalente al guardas `if (min_idx != i)` del pseudocódigo.
- **EN:** `selection_sort` always swaps on each pass; swapping an element with itself is a no-op, so the result is equivalent to the pseudocode's `if (min_idx != i)` guard.
- **ES:** No se usa `std::sort` ni `std::stable_sort`; la iteración es explícita (`for`/`while`) y el intercambio se hace con `std::swap`.
- **EN:** Neither `std::sort` nor `std::stable_sort` is used; iteration is explicit (`for`/`while`) and swapping uses `std::swap`.

### Sobre el caso de fallo (nulo) / On the failure (null) case

- **ES:** El tipo `std::vector<int>` (por valor) **no admite `null`**, por lo que la representación equivalente del indicador de fallo no es representable aquí. Siguiendo la nota de la especificación, se documenta esta limitación y se conservan los 7 casos canónicos. Un vector vacío `{}` **no** es un fallo: se devuelve tal cual.
- **EN:** The `std::vector<int>` type (by value) **cannot represent `null`**, so the equivalent failure-indicator representation is not expressible here. Following the specification's note, this limitation is documented and the 7 canonical cases are kept. An empty vector `{}` is **not** a failure: it is returned unchanged.

### Sobre las pruebas / On the tests

- **ES:** Un único helper (`assertSortsAllCases`) recibe la función a probar (puntero a función `std::vector<int>(*)(std::vector<int>)`) y su nombre, y ejecuta las 7 aserciones con mensajes descriptivos. Hay una prueba (`selection_sort`, `bubble_sort`, `insertion_sort`) por algoritmo.
- **EN:** A single helper (`assertSortsAllCases`) receives the function under test (function pointer `std::vector<int>(*)(std::vector<int>)`) and its name, and runs the 7 assertions with descriptive messages. There is one test (`selection_sort`, `bubble_sort`, `insertion_sort`) per algorithm.
- **ES:** Los fixtures son constantes nombradas (`STANDARD_INPUT`, `REVERSE_OUTPUT`, etc.) y la comparación usa `EXPECT_EQ`, que imprime los vectores cuando falla.
- **EN:** Fixtures are named constants (`STANDARD_INPUT`, `REVERSE_OUTPUT`, etc.) and comparison uses `EXPECT_EQ`, which prints the vectors on failure.
- **ES:** La implementación compila limpia con `g++ -std=c++17 -Wall -Wextra -Wpedantic`.
- **EN:** The implementation compiles clean with `g++ -std=c++17 -Wall -Wextra -Wpedantic`.

---

### 🌐 Otras implementaciones / Other implementations

Este proyecto también está implementado en otros lenguajes. Explora el [repositorio principal](https://github.com/yorche3/programming_languages) para ver todas las versiones.

This project is also implemented in other languages. Explore the [main repository](https://github.com/yorche3/programming_languages) to see the other versions.

---

*[← Volver a Algorithms](../README.md)*

*🌐 [github.com/yorche3/programming_languages](https://github.com/yorche3/programming_languages) · [GitHub Pages](https://yorche3.github.io/programming_languages/)*
