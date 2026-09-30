# Data Structures Basics — C++

Implementación de la especificación [06_Data_Structures_Basics](https://yorche3.github.io/programming_languages/core/algorithms/06_Data_Structures_Basics/) en **C++**, utilizando **Bazelisk** (Bazel) y **Google Test** para las pruebas unitarias.

Define un tipo `Node` compartido y tres tipos independientes de estructuras de datos: `LinkedList`, `Stack` y `Queue`, implementados manualmente sobre celdas enlazadas dinámicas gestionadas con RAII.

Implementation of the [06_Data_Structures_Basics](https://yorche3.github.io/programming_languages/core/algorithms/06_Data_Structures_Basics/) specification in **C++**, using **Bazelisk** (Bazel) and **Google Test** for unit testing.

Defines a shared `Node` type and three independent data structure types: `LinkedList`, `Stack`, and `Queue`, implemented manually on dynamic linked cells managed with RAII.

---

## 📂 Archivos y estructura / Files & Structure

| Archivo / Directory | Propósito / Purpose |
|---|---|
| [`include/data_structures_basics.h`](include/data_structures_basics.h) | Cabecera pública: declaración de `Node`, `LinkedList`, `Stack`, `Queue` y constante de fallo. / Public header: declaration of `Node`, `LinkedList`, `Stack`, `Queue`, and failure constant. |
| `src/data_structures_basics.cpp` | Implementación de las clases y sus operaciones con gestión manual de memoria en heap. / Implementation of classes and their operations with manual heap memory management. |
| `tests/data_structures_basics_test.cpp` | Pruebas unitarias con Google Test que validan los pasos sucesivos de cada estructura. / Google Test unit tests validating successive steps for each data structure. |
| `BUILD` | Configuración de construcción de Bazel (targets `data_structures_basics_lib` y `data_structures_basics_tests`). / Bazel build configuration (targets `data_structures_basics_lib` and `data_structures_basics_tests`). |
| `MODULE.bazel` | Manifiesto Bzlmod con dependencia a Google Test (`googletest` 1.15.2). / Bzlmod manifest with Google Test dependency (`googletest` 1.15.2). |
| `WORKSPACE` | Raíz del espacio de trabajo (compatibilidad con Bazel). / Workspace root (Bazel compatibility). |
| `.bazelversion` | Versión fija de Bazel (`7.1.1`). / Pinned Bazel version (`7.1.1`). |
| `.gitignore` | Archivos generados excluidos del control de versiones. / Generated files excluded from version control. |

**Estructura de directorios / Directory structure:**

```text
data_structures_basics/
├── BUILD                             # Reglas de Bazel / Bazel rules
├── MODULE.bazel                      # Dependencias Bzlmod / Bzlmod dependencies
├── WORKSPACE                         # Espacio de trabajo / Workspace
├── .bazelversion                     # Versión de Bazel / Bazel version
├── .gitignore                        # Archivos ignorados / Ignored files
├── include/
│   └── data_structures_basics.h      # Declaración de clases / Class declarations
├── src/
│   └── data_structures_basics.cpp    # Implementación / Implementation
├── tests/
│   └── data_structures_basics_test.cpp # Pruebas Google Test / Google Test suite
└── README.md                         # Documentación del módulo / Module documentation
```

> **Nota de desviación / Deviation note:** La especificación propone `src/data_structures_basics.ext`, `test/data_structures_basics_test.ext` y `test/run_tests.ext`. En este proyecto se utiliza el layout idiomático de C++ separando la cabecera en `include/` y los fuentes en `src/`, las pruebas se ubican en `tests/` y Bazel/Google Test gestiona la ejecución y descubrimiento de pruebas sin necesidad de un script `run_tests` separado.
>
> **Deviation note:** The specification proposes `src/data_structures_basics.ext`, `test/data_structures_basics_test.ext`, and `test/run_tests.ext`. This project adopts the idiomatic C++ layout by separating public headers into `include/` and sources into `src/`, tests reside in `tests/`, and Bazel/Google Test handles execution and discovery without requiring a separate `run_tests` script.

---

## 🛠️ Enfoque y construcción / Approach & Build

**ES:** El módulo se diseñó siguiendo el paradigma orientado a objetos idiomático de C++. Cada estructura (`LinkedList`, `Stack`, `Queue`) se implementa como una clase independiente sobre el tipo compartido `Node`, gestionando sus propios punteros internos y un contador de tamaño `std::size_t`. La inicialización explícita requerida por el contrato se satisface de forma idiomática mediante constructores (`explicit Node(int)` y constructores por defecto para los contenedores). La gestión de memoria dinámica en heap (`new` / `delete`) está encapsulada mediante destructores RAII, previniendo fugas de memoria al salir de ámbito. Se inhabilitan explícitamente la copia y asignación (`= delete`) para evitar doble liberación superficial de punteros en esta fase.

**EN:** The module was designed following the idiomatic object-oriented paradigm in C++. Each structure (`LinkedList`, `Stack`, `Queue`) is implemented as an independent class over the shared `Node` type, managing its own internal pointers and a `std::size_t` size counter. The explicit initialization required by the contract is fulfilled idiomatically through constructors (`explicit Node(int)` and default constructors for containers). Dynamic heap memory management (`new` / `delete`) is encapsulated via RAII destructors, preventing memory leaks when going out of scope. Copy constructors and assignment operators are explicitly disabled (`= delete`) to avoid shallow double-free issues at this phase.

### Pasos de inicialización / Initialization steps

1. **Definir módulo y dependencias / Define module and dependencies**: `MODULE.bazel` declara la dependencia de `googletest` vía Bzlmod.
2. **Configuración de construcción / Build configuration**: `BUILD` define `cc_library` con prefijo de inclusión recortado (`strip_include_prefix = "include"`) y el target de pruebas `cc_test`.
3. **Ejecución con Bazelisk / Run with Bazelisk**: garantiza consistencia de toolchain ejecutando Bazel `7.1.1`.

---

## 📄 Configuración clave / Key Configuration

### `BUILD` — Targets de Bazel / Bazel targets

```python
cc_library(
    name = "data_structures_basics_lib",
    srcs = ["src/data_structures_basics.cpp"],
    hdrs = ["include/data_structures_basics.h"],
    strip_include_prefix = "include",
    visibility = ["//visibility:public"],
)

cc_test(
    name = "data_structures_basics_tests",
    size = "small",
    srcs = ["tests/data_structures_basics_test.cpp"],
    deps = [
        ":data_structures_basics_lib",
        "@com_google_googletest//:gtest_main",
    ],
)
```

### `MODULE.bazel` — Manifiesto de dependencias / Dependency manifest

```python
module(
    name = "cpp_data_structures_basics",
    version = "1.0",
)

bazel_dep(name = "googletest", version = "1.15.2", repo_name = "com_google_googletest")
```

---

## 🚀 Compilación y ejecución / Build & Run

### Compilar / Build

```bash
bazelisk build //...
```

### Ejecutar pruebas / Run tests

```bash
# Ejecutar suite de pruebas con salida detallada
bazelisk test //:data_structures_basics_tests --test_output=all
```

**Salida real / Actual output:**

```text
Running main() from gmock_main.cc
[==========] Running 4 tests from 1 test suite.
[----------] Global test environment set-up.
[----------] 4 tests from DataStructuresBasicsTests
[ RUN      ] DataStructuresBasicsTests.nodeOperations
[       OK ] DataStructuresBasicsTests.nodeOperations (0 ms)
[ RUN      ] DataStructuresBasicsTests.linkedListOperations
[       OK ] DataStructuresBasicsTests.linkedListOperations (0 ms)
[ RUN      ] DataStructuresBasicsTests.stackOperations
[       OK ] DataStructuresBasicsTests.stackOperations (0 ms)
[ RUN      ] DataStructuresBasicsTests.queueOperations
[       OK ] DataStructuresBasicsTests.queueOperations (0 ms)
[----------] 4 tests from DataStructuresBasicsTests (0 ms total)

[----------] Global test environment tear-down
[==========] 4 tests from 1 test suite ran. (0 ms total)
[  PASSED  ] 4 tests.
```

---

## 🧠 Algoritmos y operaciones / Algorithms & Operations

| Operación / Operation | Entrada → salida / Input → output | Complejidad / Complexity | Notas / Notes |
|---|---|---|---|
| `Node::Node(int)` | `int → Node` | $O(1)$ | Constructor; inicializa `value_` y asigna `next_ = nullptr` / Constructor; initializes `value_` and sets `next_ = nullptr` |
| `Node::get_value()` | `void → int` | $O(1)$ | Observa el valor almacenado / Observes stored value |
| `Node::get_next()` | `void → Node*` | $O(1)$ | Retorna puntero al siguiente nodo o `nullptr` / Returns pointer to next node or `nullptr` |
| `Node::set_next(Node*)` | `Node* → void` | $O(1)$ | Actualiza el enlace al siguiente nodo / Updates link to next node |
| `LinkedList::LinkedList()` | `void → LinkedList` | $O(1)$ | Constructor; inicializa `head_ = nullptr`, `tail_ = nullptr`, `count_ = 0` / Constructor; initializes pointers and zero count |
| `LinkedList::is_empty()` | `void → bool` | $O(1)$ | Informa si `count_ == 0` / Reports whether `count_ == 0` |
| `LinkedList::size()` | `void → std::size_t` | $O(1)$ | Retorna el número de elementos / Returns element count |
| `LinkedList::get_head()` | `void → int` | $O(1)$ | Retorna valor de cabeza o `-1` si está vacía / Returns head value or `-1` if empty |
| `LinkedList::insert_head(int)` | `int → void` | $O(1)$ | Asigna nodo en heap, actualiza cabeza y tail si aplica, incrementa contador / Allocates heap node, updates head/tail, increments count |
| `LinkedList::insert_tail(int)` | `int → void` | $O(1)$ | Asigna nodo en heap, actualiza tail y head si aplica, incrementa contador / Allocates heap node, updates tail/head, increments count |
| `LinkedList::delete_value(int)` | `int → bool` | $O(n)$ | Elimina primera aparición de valor, libera memoria y decrementa tamaño; retorna éxito / Deletes first occurrence, frees memory, decrements size; returns success |
| `Stack::Stack()` | `void → Stack` | $O(1)$ | Constructor; inicializa `top_ = nullptr`, `count_ = 0` / Constructor; initializes `top_` and zero count |
| `Stack::is_empty()` | `void → bool` | $O(1)$ | Informa si `count_ == 0` / Reports whether `count_ == 0` |
| `Stack::size()` | `void → std::size_t` | $O(1)$ | Retorna el número de elementos / Returns element count |
| `Stack::push(int)` | `int → void` | $O(1)$ | Asigna nodo en heap sobre `top_`, incrementa contador / Allocates heap node on `top_`, increments count |
| `Stack::peek()` | `void → int` | $O(1)$ | Observa el tope sin mutar o retorna `-1` si está vacía / Observes top without mutating or returns `-1` if empty |
| `Stack::pop()` | `void → int` | $O(1)$ | Extrae tope, libera nodo y decrementa contador, o `-1` si está vacía / Pops top, frees node, decrements count, or `-1` if empty |
| `Queue::Queue()` | `void → Queue` | $O(1)$ | Constructor; inicializa `front_ = nullptr`, `rear_ = nullptr`, `count_ = 0` / Constructor; initializes pointers and zero count |
| `Queue::is_empty()` | `void → bool` | $O(1)$ | Informa si `count_ == 0` / Reports whether `count_ == 0` |
| `Queue::size()` | `void → std::size_t` | $O(1)$ | Retorna el número de elementos / Returns element count |
| `Queue::enqueue(int)` | `int → void` | $O(1)$ | Asigna nodo en heap tras `rear_`, incrementa contador / Allocates heap node after `rear_`, increments count |
| `Queue::peek()` | `void → int` | $O(1)$ | Observa `front_` sin mutar o retorna `-1` si está vacía / Observes `front_` without mutating or returns `-1` if empty |
| `Queue::dequeue()` | `void → int` | $O(1)$ | Extrae `front_`, libera nodo y decrementa contador, o `-1` si está vacía / Dequeues `front_`, frees node, decrements count, or `-1` if empty |

---

## 🧩 Decisiones de diseño / Design decisions

| Decisión / Decision | Alternativa considerada / Alternative | Razón / Reason |
|---|---|---|
| Clases C++ con constructores (`Node`, `LinkedList`, `Stack`, `Queue`) en lugar de funciones de inicialización separadas | Métodos de inicialización `init(...)` explícitos sobre structs o instancias sin inicializar | En C++, el constructor es el mecanismo idiomático y garantizado por el lenguaje para establecer invariantes de inicialización de un objeto antes de invocar cualquier método. |
| Inhabilitación de copiado y asignación (`= delete`) | Implementar copia profunda manual (*Rule of Three / Five*) | En esta fase elemental de algoritmos el contrato evalúa operaciones sobre una única instancia mutada; inhabilitar la copia evita copias superficiales accidentales que producirían doble liberación de punteros crudos (`double-free`). |
| Uso de punteros nativos `Node*` con gestión manual (`new`/`delete`) y RAII | Punteros inteligentes `std::unique_ptr<Node>` | La especificación evalúa la construcción algorítmica desde cero de estructuras enlazadas y la manipulación explícita de enlaces entre celdas; la encapsulación en destructores garantiza la seguridad de memoria sin depender de envoltorios de la biblioteca estándar. |
| Constante `FAILURE_VALUE = -1` para valores enteros | Excepciones o `std::optional<int>` | La fase actual prohíbe tipos opcionales complejos o excepciones avanzadas para mantener homogeneidad con el contrato de pseudocódigo; `-1` es un valor entero no colisionante con los datos de prueba. |

---

## 🔀 Adaptaciones idiomáticas / Idiomatic adaptations

| Especificación / Specification | Adaptación / Adaptation | Justificación / Justification |
|---|---|---|
| `Node.init(value)` y `ADT.init()` | Constructores de C++: `explicit Node(int)` y constructores por defecto `LinkedList()`, `Stack()`, `Queue()` | En C++ los objetos deben inicializarse durante su construcción para evitar estados indefinidos; el constructor cumple el rol de `init`. |
| `Node.set_next(next)` devuelve `this` en el pseudocódigo | `void Node::set_next(Node* next)` | En C++ las operaciones mutadoras in-place sobre objetos típicamente retornan `void` a menos que se implemente una interfaz fluida explícita. |
| `LinkedList.delete(value)` | Nombrado como `delete_value(int)` | `delete` es una palabra clave reservada del lenguaje C++ (operador de desasignación de memoria), por lo que se adaptó a un identificador válido. |
| `delete_value` devuelve `success` / `failure` | Retorna `bool` (`true` en éxito, `false` en fallo) | Tipo booleano nativo idiomático de C++ para predicados de éxito/fallo. |
| Ausencia de enlace (`absent`) | `nullptr` nativo de C++ | Representación estándar de ausencia de enlace y puntero nulo en C++. |
| Layout `src/` + `test/` | Layout `include/` + `src/` + `tests/` gestionado por Bazel | Convención idiomática de proyectos C++ con separación de interfaces públicas y suite de Google Test. |

---

## 🚨 Indicadores de fallo / Failure indicators

| Operación / Operation | Situación de fallo / Failure situation | Indicador / Indicator | Ejemplo / Example |
|---|---|---|---|
| `Node::get_next()` | Nodo sin enlace siguiente / Node has no next link | `nullptr` | `first_node.get_next() == nullptr` |
| `LinkedList::get_head()` | Lista vacía (`count_ == 0`) / Empty list | `-1` (`FAILURE_VALUE`) | `list.get_head() == -1` tras `init` |
| `LinkedList::delete_value(val)` | Valor no encontrado en la lista / Value absent | `false` | `list.delete_value(99) == false` |
| `Stack::peek()` | Pila vacía (`count_ == 0`) / Empty stack | `-1` (`FAILURE_VALUE`) | `stack.peek() == -1` tras `init` |
| `Stack::pop()` | Pila vacía (`count_ == 0`) / Empty stack | `-1` (`FAILURE_VALUE`) | `stack.pop() == -1` tras `init` |
| `Queue::peek()` | Cola vacía (`count_ == 0`) / Empty queue | `-1` (`FAILURE_VALUE`) | `queue.peek() == -1` tras `init` |
| `Queue::dequeue()` | Cola vacía (`count_ == 0`) / Empty queue | `-1` (`FAILURE_VALUE`) | `queue.dequeue() == -1` tras `init` |

---

## ✅ Cobertura de pruebas / Test coverage

| Caso de la especificación / Specification case | Cubierto / Covered | Prueba / Test | Notas / Notes |
|---|---|:--:|---|
| Node — Inicializar y observar valor/enlace | Sí | `tests/data_structures_basics_test.cpp:43` (`nodeOperations`) | Verifica `get_value() == 10` y `get_next() == nullptr`. |
| Node — Inicializar otro nodo, enlazar y recorrer | Sí | `tests/data_structures_basics_test.cpp:49` (`nodeOperations`) | Verifica enlace con `second_node`, valor expuesto `20` y ausencia de enlace en `second_node`. |
| LinkedList — Estado vacío | Sí | `tests/data_structures_basics_test.cpp:68` (`linkedListOperations`) | Verifica `is_empty() == true`, `size() == 0`, `get_head() == -1`. |
| LinkedList — Insertar por ambos extremos | Sí | `tests/data_structures_basics_test.cpp:74` (`linkedListOperations`) | Inserciones sucesivas (tail: 10, tail: 20, head: 5, tail: 10); valida `size() == 4` y cabeza en `5`. |
| LinkedList — Eliminar primera aparición | Sí | `tests/data_structures_basics_test.cpp:84` (`linkedListOperations`) | Elimina primera aparición de `10`; verifica éxito, conservación de cabeza y `size() == 3`. |
| LinkedList — Valor ausente | Sí | `tests/data_structures_basics_test.cpp:92` (`linkedListOperations`) | Intenta eliminar `99`; verifica fallo y preservación de tamaño y contenido. |
| LinkedList — Vaciar | Sí | `tests/data_structures_basics_test.cpp:100` (`linkedListOperations`) | Eliminación de `5`, `20` y `10`; valida `is_empty() == true`, `size() == 0` y `get_head() == -1`. |
| Stack — Estado vacío y extracción fallida | Sí | `tests/data_structures_basics_test.cpp:120` (`stackOperations`) | Verifica `is_empty() == true`, `size() == 0`, `peek() == -1`, `pop() == -1`. |
| Stack — LIFO y `peek` no mutante | Sí | `tests/data_structures_basics_test.cpp:128` (`stackOperations`) | `push(10)`, `push(20)`, `push(30)`; verifica `peek() == 30` y `size() == 3`. |
| Stack — Extracción y reutilización | Sí | `tests/data_structures_basics_test.cpp:136` (`stackOperations`) | Valida secuencia LIFO `30`, `40`, `20`, `10`; al final `is_empty() == true`, `size() == 0`. |
| Stack — Vacío tras extracción | Sí | `tests/data_structures_basics_test.cpp:145` (`stackOperations`) | Extracción sobre pila vacía; verifica retorno `-1` y permanencia en vacío. |
| Queue — Estado vacío y extracción fallida | Sí | `tests/data_structures_basics_test.cpp:158` (`queueOperations`) | Verifica `is_empty() == true`, `size() == 0`, `peek() == -1`, `dequeue() == -1`. |
| Queue — FIFO y `peek` no mutante | Sí | `tests/data_structures_basics_test.cpp:166` (`queueOperations`) | `enqueue(10)`, `enqueue(20)`, `enqueue(30)`; verifica `peek() == 10` y `size() == 3`. |
| Queue — Extracción y reutilización | Sí | `tests/data_structures_basics_test.cpp:174` (`queueOperations`) | Valida secuencia FIFO `10`, `20`, `30`, `40`; al final `is_empty() == true`, `size() == 0`. |
| Queue — Vacío tras extracción | Sí | `tests/data_structures_basics_test.cpp:183` (`queueOperations`) | Extracción sobre cola vacía; verifica retorno `-1` y permanencia en vacío. |

---

## ⚠️ Limitaciones conocidas / Known limitations

| Limitación / Limitation | Impacto / Impact | Alternativa o plan / Workaround or plan |
|---|---|---|
| Dominio limitado a enteros positivos | Si se introduce el valor `-1` en la estructura, no se puede distinguir de `FAILURE_VALUE` | La especificación restringe deliberadamente las pruebas a enteros positivos para no colisionar con centinelas de error. En fases posteriores se podrán evaluar tipos de retorno enriquecidos (`std::optional`). |
| Agotamiento de heap (`std::bad_alloc`) | Si `new` falla por falta de memoria del sistema operativo, se lanza una excepción estándar no capturada en esta capa | Comportamiento estándar de C++; no se imponen límites artificiales de capacidad a las estructuras dinámicas. |

---

## 📝 Notas de implementación / Implementation Notes

### 🧱 Nodo compartido y estructuras independientes / Shared node and independent structures

Las clases `LinkedList`, `Stack` y `Queue` reutilizan de forma estricta la misma definición de `Node` (`include/data_structures_basics.h`). Cada estructura de datos gestiona sus propios punteros independientes (`head_` / `tail_` para la lista, `top_` para la pila, `front_` / `rear_` para la cola) y contadores de tamaño `count_`. Ni `Stack` ni `Queue` envuelven a `LinkedList` ni delegan operaciones en contenedores de la biblioteca estándar (`std::list`, `std::stack`, `std::queue`).

Classes `LinkedList`, `Stack`, and `Queue` strictly reuse the exact same `Node` definition (`include/data_structures_basics.h`). Each data structure maintains its own independent pointers (`head_` / `tail_` for the list, `top_` for the stack, `front_` / `rear_` for the queue) and size counters `count_`. Neither `Stack` nor `Queue` wrap `LinkedList` or delegate operations to standard library containers (`std::list`, `std::stack`, `std::queue`).

### 💾 Gestión de memoria mediante RAII / Memory management with RAII

Cada contenedor administra el ciclo de vida de sus nodos en memoria dinámica. Cuando se inserta un elemento (`insert_head`, `insert_tail`, `push`, `enqueue`), se asigna un `Node` mediante `new`. Cuando se extrae o elimina un elemento (`delete_value`, `pop`, `dequeue`), la memoria del nodo se libera explícitamente con `delete`. Adicionalmente, los destructores de `LinkedList`, `Stack` y `Queue` recorren y liberan todos los nodos remanentes cuando las estructuras salen de ámbito, garantizando ausencia de fugas de memoria.

Each container manages the lifecycle of its nodes in dynamic heap memory. When an element is inserted (`insert_head`, `insert_tail`, `push`, `enqueue`), a `Node` is allocated with `new`. When an element is extracted or removed (`delete_value`, `pop`, `dequeue`), node memory is explicitly freed with `delete`. Additionally, destructors for `LinkedList`, `Stack`, and `Queue` traverse and free any remaining nodes when going out of scope, guaranteeing absence of memory leaks.

### 🌐 Otras implementaciones / Other implementations

Este proyecto también está implementado en otros lenguajes. Explora el repositorio principal para consultar las demás versiones.

This project is also implemented in other languages. Explore the main repository to see the other versions.

---

## 🔍 Checklist de validación / Validation checklist

- [x] La suite nativa se ejecutó y su salida real está copiada en este README.
- [x] Cada caso de la especificación tiene su fila en _Cobertura de pruebas_ (o `Omitido` con razón).
- [x] Cada desviación del pseudocódigo o de la ubicación esperada está en _Adaptaciones idiomáticas_.
- [x] Cada operación con fallo posible está en _Indicadores de fallo_.
- [x] No hay rutas absolutas del autor, credenciales ni salidas inventadas.
- [x] Los enlaces relativos resuelven dentro del repositorio y el documento es bilingüe.
- [x] Ninguna sección repite lo que ya dice la especificación.

---

## 📚 Referencias / References

| Tipo / Kind | Referencia / Reference |
|---|---|
| Especificación / Specification | [`06_Data_Structures_Basics.md`](../../../../../docs/core/algorithms/06_Data_Structures_Basics.md) |
| Módulo homologado del lenguaje / Homologated module | [`cpp/core/foundations/numbers/`](../../foundations/numbers/README.md) |
| Guía de inicialización / Initialisation guide | [`core/00_Project_Initialization_Guide.md`](../../../../../docs/core/00_Project_Initialization_Guide.md) |
| Adaptaciones idiomáticas / Idiomatic adaptations | [`AGENT_Template.md`](../../../../../docs/AGENT_Template.md) |
| Validación de la documentación / Documentation validation | [`WORKFLOW.md`](../../../../../docs/WORKFLOW.md) |
| Documentación oficial del lenguaje / Language official docs | [cppreference.com](https://en.cppreference.com/) |

---

*[← Volver a Algorithms Pure](../README.md) | [↑ Volver a Core](../../README.md)*

*🌐 [github.com/yorche3/programming_languages](https://github.com/yorche3/programming_languages) · [GitHub Pages](https://yorche3.github.io/programming_languages/)*
