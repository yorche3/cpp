# Data Structures Advanced — C++

Implementación de la especificación [07_Data_Structures_Advanced](https://yorche3.github.io/programming_languages/core/algorithms/07_Data_Structures_Advanced/) en **C++**, utilizando **Bazelisk** (Bazel) y **Google Test** para las pruebas unitarias.

Define una clase base `Node` que almacena únicamente el valor, un nodo binario `TreeNode` y una estructura `BinaryTree` (árbol binario de búsqueda), junto con `GraphNode` y `Graph` (grafo dirigido con adyacencia ordenada), implementados manualmente con gestión de memoria dinámica en heap encapsulada mediante RAII.

Implementation of the [07_Data_Structures_Advanced](https://yorche3.github.io/programming_languages/core/algorithms/07_Data_Structures_Advanced/) specification in **C++**, using **Bazelisk** (Bazel) and **Google Test** for unit testing.

Defines a `Node` base class storing only the value, a binary node `TreeNode` and a `BinaryTree` structure (binary search tree), along with `GraphNode` and `Graph` (directed graph with sorted adjacency), manually implemented with dynamic heap memory management encapsulated via RAII.

---

## 📂 Archivos y estructura / Files & Structure

| Archivo / Directory | Propósito / Purpose |
|---|---|
| [`include/data_structures_advanced.h`](include/data_structures_advanced.h) | Cabecera pública: declaración de `Node`, `TreeNode`, `BinaryTree`, `GraphNode` y `Graph`. / Public header: declaration of `Node`, `TreeNode`, `BinaryTree`, `GraphNode`, and `Graph`. |
| `src/data_structures_advanced.cpp` | Implementación de las clases, algoritmos de ABB y grafo con registro enlazado canónico y gestión de memoria. / Implementation of classes, BST and graph algorithms with canonical linked registry and memory management. |
| `tests/data_structures_advanced_test.cpp` | Pruebas unitarias con Google Test agrupadas por abstracción y validadas mediante escenarios parametrizados. / Google Test unit tests grouped by abstraction and validated via parameterized scenarios. |
| `BUILD` | Configuración de construcción de Bazel (targets `data_structures_advanced_lib` y `data_structures_advanced_tests`). / Bazel build configuration (targets `data_structures_advanced_lib` and `data_structures_advanced_tests`). |
| `MODULE.bazel` | Manifiesto Bzlmod con dependencia a Google Test (`googletest` 1.15.2). / Bzlmod manifest with Google Test dependency (`googletest` 1.15.2). |
| `WORKSPACE` | Raíz del espacio de trabajo (compatibilidad con Bazel). / Workspace root (Bazel compatibility). |
| `.bazelversion` | Versión fija de Bazel (`7.1.1`). / Pinned Bazel version (`7.1.1`). |
| `.gitignore` | Archivos generados excluidos del control de versiones. / Generated files excluded from version control. |

**Estructura de directorios / Directory structure:**

```text
data_structures_advanced/
├── BUILD                                 # Reglas de Bazel / Bazel rules
├── MODULE.bazel                          # Dependencias Bzlmod / Bzlmod dependencies
├── WORKSPACE                             # Espacio de trabajo / Workspace
├── .bazelversion                         # Versión de Bazel / Bazel version
├── .gitignore                            # Archivos ignorados / Ignored files
├── include/
│   └── data_structures_advanced.h        # Declaración de clases / Class declarations
├── src/
│   └── data_structures_advanced.cpp      # Implementación / Implementation
├── tests/
│   └── data_structures_advanced_test.cpp # Pruebas Google Test / Google Test suite
└── README.md                             # Documentación del módulo / Module documentation
```

> **Nota de desviación / Deviation note:** La especificación propone `src/data_structures_advanced.ext`, `test/data_structures_advanced_test.ext` y `test/run_tests.ext`. Siguiendo el precedente homologado de `data_structures_basics`, este proyecto adopta la estructura canónica de C++ separando las interfaces públicas en `include/` y las implementaciones en `src/`, las pruebas en `tests/` y Bazel/Google Test gestiona la compilación y ejecución de la suite sin requerir scripts auxiliares.
>
> **Deviation note:** The specification proposes `src/data_structures_advanced.ext`, `test/data_structures_advanced_test.ext`, and `test/run_tests.ext`. Following the homologated precedent of `data_structures_basics`, this project adopts the canonical C++ layout separating public headers into `include/` and source files into `src/`, tests in `tests/`, and Bazel/Google Test handles build and execution without requiring auxiliary scripts.

---

## 🛠️ Enfoque y construcción / Approach & Build

**ES:** El módulo se diseñó siguiendo el paradigma orientado a objetos de C++ con herencia real para la base de valor. La clase base `Node` encapsula exclusivamente `value_` (con constructor protegido y destructor no virtual protegido según C.35 de C++ Core Guidelines) y no realiza validaciones. `TreeNode` y `GraphNode` heredan de `Node`. `BinaryTree` implementa un árbol binario de búsqueda sin límite de capacidad. `Graph` mantiene un registro lineal manual de vértices enlazados (`vertices_`) con recorrido `O(V)` sin delegar en tablas hash ni árboles estándar; la secuencia de adyacencia utiliza `std::list<int>` exclusivamente como almacenamiento de vecinos, mientras que la búsqueda de duplicados e inserción ordenada se realizan de forma algorítmica manual. La gestión de memoria dinámica en heap (`new` / `delete`) se encapsula mediante destructores RAII, inhabilitando explícitamente copia y movimiento (`= delete`) para prevenir problemas de doble liberación superficial.

**EN:** The module was designed following the C++ object-oriented paradigm with true inheritance for the value base. Base class `Node` encapsulates exclusively `value_` (with protected constructor and protected non-virtual destructor per C++ Core Guidelines C.35) and performs no validations. `TreeNode` and `GraphNode` derive from `Node`. `BinaryTree` implements an unbounded binary search tree. `Graph` maintains a manual linked vertex registry (`vertices_`) with `O(V)` traversal without delegating to standard hash tables or trees; adjacency sequence uses `std::list<int>` strictly as neighbour storage, while duplicate detection and sorted insertion are handled manually. Dynamic heap memory management (`new` / `delete`) is encapsulated via RAII destructors, with copy and move operations explicitly disabled (`= delete`) to prevent shallow double-free issues.

### Pasos de inicialización / Initialization steps

1. **Definir módulo y dependencias / Define module and dependencies**: `MODULE.bazel` declara la dependencia externa de `googletest` vía Bzlmod.
2. **Configuración de construcción / Build configuration**: `BUILD` define `cc_library` con prefijo de inclusión recortado (`strip_include_prefix = "include"`) y el target de pruebas `cc_test` vinculado a `gtest_main`.
3. **Ejecución con Bazelisk / Run with Bazelisk**: garantiza consistencia de toolchain ejecutando Bazel `7.1.1` conforme a `.bazelversion`.

---

## 📄 Configuración clave / Key Configuration

### `BUILD` — Targets de Bazel / Bazel targets

```python
cc_library(
    name = "data_structures_advanced_lib",
    srcs = ["src/data_structures_advanced.cpp"],
    hdrs = ["include/data_structures_advanced.h"],
    strip_include_prefix = "include",
    visibility = ["//visibility:public"],
)

cc_test(
    name = "data_structures_advanced_tests",
    size = "small",
    srcs = ["tests/data_structures_advanced_test.cpp"],
    deps = [
        ":data_structures_advanced_lib",
        "@com_google_googletest//:gtest_main",
    ],
)
```

### `MODULE.bazel` — Manifiesto de dependencias / Dependency manifest

```python
module(
    name = "cpp_data_structures_advanced",
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
bazelisk test //:data_structures_advanced_tests --test_output=all
```

**Salida real / Actual output:**

```text
Running main() from gmock_main.cc
[==========] Running 3 tests from 1 test suite.
[----------] Global test environment set-up.
[----------] 3 tests from DataStructuresAdvancedTests
[ RUN      ] DataStructuresAdvancedTests.treeNodeOperations
[       OK ] DataStructuresAdvancedTests.treeNodeOperations (0 ms)
[ RUN      ] DataStructuresAdvancedTests.binaryTreeOperations
[       OK ] DataStructuresAdvancedTests.binaryTreeOperations (0 ms)
[ RUN      ] DataStructuresAdvancedTests.graphOperations
[       OK ] DataStructuresAdvancedTests.graphOperations (0 ms)
[----------] 3 tests from DataStructuresAdvancedTests (0 ms total)

[----------] Global test environment tear-down
[==========] 3 tests from 1 test suite ran. (0 ms total)
[  PASSED  ] 3 tests.
```

---

## 🧠 Algoritmos y operaciones / Algorithms & Operations

| Operación / Operation | Entrada → salida / Input → output | Complejidad / Complexity | Notas / Notes |
|---|---|---|---|
| `Node::get_value()` | `void → int` | $O(1)$ | Observador del valor encapsulado en la base. / Observer for the encapsulated value in base. |
| `TreeNode::TreeNode(int)` | `int → TreeNode` | $O(1)$ | Constructor; inicializa base `Node(value)` y enlaces en `nullptr`. / Constructor; initializes base `Node(value)` and links to `nullptr`. |
| `TreeNode::get_left()` | `void → TreeNode*` | $O(1)$ | Retorna puntero al hijo izquierdo o `nullptr`. / Returns pointer to left child or `nullptr`. |
| `TreeNode::get_right()` | `void → TreeNode*` | $O(1)$ | Retorna puntero al hijo derecho o `nullptr`. / Returns pointer to right child or `nullptr`. |
| `TreeNode::set_left(TreeNode*)` | `TreeNode* → void` | $O(1)$ | Actualiza enlace al hijo izquierdo. / Updates left child pointer link. |
| `TreeNode::set_right(TreeNode*)` | `TreeNode* → void` | $O(1)$ | Actualiza enlace al hijo derecho. / Updates right child pointer link. |
| `BinaryTree::BinaryTree()` | `void → BinaryTree` | $O(1)$ | Constructor; inicializa `root_ = nullptr` y `count_ = 0`. / Constructor; initializes `root_ = nullptr` and `count_ = 0`. |
| `BinaryTree::insert(int)` | `int → bool` | $O(h)$ | Inserta en ABB respetando invariante; duplicados no alteran tamaño; retorna éxito. / Inserts into BST preserving invariant; duplicates do not grow size; returns success. |
| `BinaryTree::contains(int)` | `int → bool` | $O(h)$ | Búsqueda por ramas del ABB; retorna pertenencia. / BST branch traversal lookup; returns membership. |
| `BinaryTree::is_empty()` | `void → bool` | $O(1)$ | Informa si `count_ == 0`. / Reports whether `count_ == 0`. |
| `BinaryTree::size()` | `void → std::size_t` | $O(1)$ | Retorna cantidad de nodos del árbol. / Returns tree node count. |
| `Graph::Graph()` | `void → Graph` | $O(1)$ | Constructor; inicializa registro `vertices_ = nullptr`, `vertex_total_ = 0`, `edges_ = 0`. / Constructor; initializes registry `vertices_ = nullptr`, counts to 0. |
| `Graph::add_vertex(int)` | `int → bool` | $O(V)$ | Inserta vértice al frente del registro si no existe; duplicado es idempotente y exitoso. / Adds vertex to registry front if not present; duplicate is idempotent and succeeds. |
| `Graph::add_edge(int, int)` | `(int, int) → bool` | $O(V + d(u))$ | Verifica existencia de $u$ y $v$; inserta $v$ ordenado en `neighbors_` de $u$; duplicado es exitoso. / Checks $u$ and $v$ exist; inserts $v$ sorted into $u$'s `neighbors_`; duplicate succeeds. |
| `Graph::has_edge(int, int)` | `(int, int) → bool` | $O(V + d(u))$ | Localiza $u$ en registro y busca $v$ en su adyacencia. / Locates $u$ in registry and searches $v$ in its adjacency list. |
| `Graph::get_neighbors(int)` | `int → std::unique_ptr<std::list<int>>` | $O(V + d(u))$ | Devuelve copia independiente de la adyacencia ordenada, o `nullptr` si $u$ no existe. / Returns independent copy of sorted adjacency, or `nullptr` if $u$ is absent. |
| `Graph::is_empty()` | `void → bool` | $O(1)$ | Informa si `vertex_total_ == 0`. / Reports whether `vertex_total_ == 0`. |
| `Graph::vertex_count()` | `void → std::size_t` | $O(1)$ | Retorna cantidad de vértices registrados. / Returns count of registered vertices. |
| `Graph::edge_count()` | `void → std::size_t` | $O(1)$ | Retorna cantidad de aristas dirigidas. / Returns count of directed edges. |

---

## 🧩 Decisiones de diseño / Design decisions

| Decisión / Decision | Alternativa considerada / Alternative | Razón / Reason |
|---|---|---|
| Reutilización de valor mediante herencia real (`TreeNode` y `GraphNode` heredan de `Node`) | Composición por valor embebido en cada estructura de nodo | C++ soporta herencia de tipos de forma nativa con coste cero en tiempo de ejecución cuando no se usan tablas virtuales; modela directamente la relación conceptual de la especificación sin duplicar atributos. |
| Destructor protegido y no virtual en `Node` (C.35) | Destructor público virtual en `Node` | `Node` es una base conceptual no instanciable que jamás se manipula ni destruye a través de punteros polimórficos `Node*`; evitar la tabla virtual ahorra memoria en cada celda y satisface las Core Guidelines de C++. |
| `GraphNode` como clase interna con acceso de amistad a `Graph` (`friend class Graph`) | `GraphNode` con interfaz pública abierta accesible por el usuario | `GraphNode` y el puntero de registro `next_vertex_` son detalles internos de la representación enlazada del grafo; encapsularlos previene que el código cliente altere la topología del registro o cree estados inconsistentes. |
| Retorno de `std::unique_ptr<std::list<int>>` en `get_neighbors` | Retorno por valor `std::list<int>` con centinela o excepciones | Permite diferenciar de forma inequívoca el vértice inexistente (`nullptr`) del vértice aislado registrado (puntero válido a lista vacía `size == 0`) transfiriendo la propiedad exclusiva de la copia al llamador sin ambigüedad. |
| Registro lineal manual de vértices mediante `next_vertex_` en $O(V)$ | `std::unordered_map<int, GraphNode*>` o `std::map` | La especificación prohíbe explícitamente el uso de tablas hash, diccionarios o índices de biblioteca para el registro de vértices a fin de evaluar la construcción manual del ADT enlazado. |

---

## 🔀 Adaptaciones idiomáticas / Idiomatic adaptations

| Especificación / Specification | Adaptación / Adaptation | Justificación / Justification |
|---|---|---|
| `Node.init(value)`, `TreeNode.init(value)` y `ADT.init()` | Constructores de C++: `explicit Node(int)`, `explicit TreeNode(int)`, `BinaryTree()`, `Graph()` | En C++ los constructores son el mecanismo nativo para garantizar inicialización completa e invariantes de clase sin requerir llamadas explícitas posteriores. |
| `TreeNode.set_left(node)` y `set_right(node)` retornan `this` | Métodos con retorno `void` | En C++ las operaciones mutadoras in-place sobre nodos se diseñan con retorno `void` salvo que se busque intencionalmente encadenamiento fluido de métodos. |
| `Graph.get_neighbors(u)` devuelve secuencia de vecinos o fallo | Retorna `std::unique_ptr<std::list<int>>` (`nullptr` en fallo, lista en éxito) | En C++ un puntero nulo encapsulado en `std::unique_ptr` representa fallo/ausencia de vértice de forma segura, diferenciándolo de una lista vacía para vértices aislados. |
| Ausencia de enlace o subárbol (`absent`) | `nullptr` nativo de C++ | Representación estándar de puntero nulo y enlace ausente en C++. |
| Requisitos de inmutabilidad en retorno de vecinos | Copia profunda independiente retornada al llamador | Al retornar una copia en heap, el llamador puede consultar o mutar su propia copia sin afectar el estado interno del grafo ni sufrir modificaciones ante inserciones posteriores. |
| Layout de archivos `src/` + `test/` | Layout idiomático `include/` + `src/` + `tests/` con Bazel | Convención estándar de proyectos C++ con separación de cabeceras públicas, implementaciones y suite Google Test. |

---

## 🚨 Indicadores de fallo / Failure indicators

| Operación / Operation | Situación de fallo / Failure situation | Indicador / Indicator | Ejemplo / Example |
|---|---|---|---|
| `TreeNode::get_left()` | Enlace izquierdo ausente / Absent left link | `nullptr` | `node.get_left() == nullptr` |
| `TreeNode::get_right()` | Enlace derecho ausente / Absent right link | `nullptr` | `node.get_right() == nullptr` |
| `BinaryTree::contains(val)` | Valor ausente en el árbol / Value absent from BST | `false` | `tree.contains(99) == false` |
| `Graph::add_edge(u, v)` | Vértice origen $u$ o destino $v$ inexistente / Missing endpoint $u$ or $v$ | `false` | `graph.add_edge(10, 99) == false` |
| `Graph::has_edge(u, v)` | Arista ausente o extremos no registrados / Edge or endpoint absent | `false` | `graph.has_edge(10, 99) == false` |
| `Graph::get_neighbors(u)` | Vértice $u$ no registrado en el grafo / Vertex $u$ not registered | `nullptr` | `graph.get_neighbors(99) == nullptr` |

---

## ✅ Cobertura de pruebas / Test coverage

| Caso de la especificación / Specification case | Cubierto / Covered | Prueba / Test | Notas / Notes |
|---|---|:--:|---|
| TreeNode — Crear un nodo de árbol | Sí | `tests/data_structures_advanced_test.cpp:76` (`treeNodeOperations`) | Verifica `get_value() == 10`. |
| TreeNode — Enlaces iniciales ausentes | Sí | `tests/data_structures_advanced_test.cpp:81` (`treeNodeOperations`) | Verifica `get_left() == nullptr` y `get_right() == nullptr`. |
| TreeNode — Enlazar dos hijos | Sí | `tests/data_structures_advanced_test.cpp:88` (`treeNodeOperations`) | Enlaza hijos 20 y 30; verifica exposición de punteros y valores `20` y `30`. |
| TreeNode — Recorrer cada enlace | Sí | `tests/data_structures_advanced_test.cpp:104` (`treeNodeOperations`) | Recorre padre → hijos y verifica enlaces ausentes en los hijos. |
| TreeNode — Desenlazar hijos | Sí | `tests/data_structures_advanced_test.cpp:128` (`treeNodeOperations`) | `set_left(nullptr)` y `set_right(nullptr)`; valida persistencia del valor y actualización de punteros. |
| TreeNode — Adaptación inmutable | Omitido | `tests/data_structures_advanced_test.cpp` | C++ implementa nodos mutables con gestión por punteros; la variante inmutable no aplica. |
| BinaryTree — Crear vacío | Sí | `tests/data_structures_advanced_test.cpp:159` (`binaryTreeOperations`) | Verifica `is_empty() == true`, `size() == 0`, `contains(50) == false`. |
| BinaryTree — Insertar la raíz | Sí | `tests/data_structures_advanced_test.cpp:167` (`binaryTreeOperations`) | `insert(50)`; verifica éxito, `size() == 1`, `is_empty() == false`, `contains(50) == true`. |
| BinaryTree — Insertar menor y mayor | Sí | `tests/data_structures_advanced_test.cpp:174` (`binaryTreeOperations`) | Inserta 50, 30, 70; verifica éxito, `size() == 3` y pertenencia de los tres valores. |
| BinaryTree — Ramas de varios niveles | Sí | `tests/data_structures_advanced_test.cpp:182` (`binaryTreeOperations`) | Inserta 50, 30, 70, 20, 40; verifica `size() == 5` y pertenencia individual. |
| BinaryTree — Valor ausente en árbol no vacío | Sí | `tests/data_structures_advanced_test.cpp:192` (`binaryTreeOperations`) | `contains(99) == false`; valida que la consulta no muta ni altera `size() == 1`. |
| BinaryTree — Duplicado idempotente | Sí | `tests/data_structures_advanced_test.cpp:201` (`binaryTreeOperations`) | Inserta 50, 30, 70, 30; verifica éxito en todas, preservación de `size() == 3` y contenidos. |
| BinaryTree — Inserciones ordenadas | Sí | `tests/data_structures_advanced_test.cpp:209` (`binaryTreeOperations`) | Inserta 20, 30, 40, 50, 70; verifica `size() == 5`, pertenencia y fallo con `99`. |
| Graph — Crear vacío | Sí | `tests/data_structures_advanced_test.cpp:227` (`graphOperations`) | Verifica `is_empty() == true`, `vertex_count() == 0`, `edge_count() == 0`, `has_edge` y `get_neighbors` fallan. |
| Graph — Vértice aislado | Sí | `tests/data_structures_advanced_test.cpp:235` (`graphOperations`) | `add_vertex(10)`; verifica `is_empty() == false`, 1 vértice, 0 aristas y vecinos vacíos (`size == 0`). |
| Graph — Etiquetas no consecutivas y arista dirigida | Sí | `tests/data_structures_advanced_test.cpp:242` (`graphOperations`) | Registra 10 y 70, añade (10,70); verifica arista directa exitosa, inversa fallida, 2 vértices y 1 arista. |
| Graph — Vértice duplicado conserva adyacencia | Sí | `tests/data_structures_advanced_test.cpp:254` (`graphOperations`) | Registra 10 y 30, arista (10,30), re-registra 10; valida éxito, 2 vértices, 1 arista y vecinos `[30]`. |
| Graph — Arista duplicada | Sí | `tests/data_structures_advanced_test.cpp:263` (`graphOperations`) | Inserta (10,30) dos veces; valida éxito en ambas, 2 vértices, 1 arista y vecinos `[30]`. |
| Graph — Extremo inexistente sin mutación | Sí | `tests/data_structures_advanced_test.cpp:273` (`graphOperations`) | Prueba fallos con extremos inexistentes; verifica no mutación de contadores, adyacencias ni creación de vértices. |
| Graph — Vecinos ordenados y contadores | Sí | `tests/data_structures_advanced_test.cpp:302` (`graphOperations`) | Inserta aristas desordenadas en 10; valida ordenación ascendente `[30, 50, 70]`, 4 vértices y 4 aristas. |
| Graph — Consulta de arista ausente | Sí | `tests/data_structures_advanced_test.cpp:317` (`graphOperations`) | Registra 10 y 30 sin aristas; `has_edge(10,30) == false`, 2 vértices, 0 aristas. |
| Graph — Vecinos de vértice inexistente | Sí | `tests/data_structures_advanced_test.cpp:326` (`graphOperations`) | `get_neighbors(99) == nullptr`, diferenciado de vecinos vacíos de 10; contadores intactos. |
| Graph — Bucle y duplicado | Sí | `tests/data_structures_advanced_test.cpp:334` (`graphOperations`) | Inserta bucle (10,10) dos veces; valida éxito, `has_edge(10,10) == true`, vecinos `[10]`, 1 vértice y 1 arista. |
| Graph — Aislamiento del resultado de vecinos | Sí | `tests/data_structures_advanced_test.cpp:344` (`graphOperations`) | Modifica copia devuelta e inserta arista posterior; verifica que copia previa guardada permanece inalterada. |

> **Organización lógica y ejecución:** Los 24 escenarios de la especificación se mapean en 3 pruebas lógicas de Google Test (`treeNodeOperations`, `binaryTreeOperations`, `graphOperations`) ejecutadas mediante la función parametrizada `run_cases` dentro de la suite `DataStructuresAdvancedTests` en el ejecutable `//:data_structures_advanced_tests`. El runner ejecuta todos los escenarios y propaga cualquier aserción fallida al proceso.

---

## ⚠️ Limitaciones conocidas / Known limitations

| Limitación / Limitation | Impacto / Impact | Alternativa o plan / Workaround or plan |
|---|---|---|
| Dominio restringido a enteros de tipo `int` | No se pueden almacenar valores genéricos o tipos flotantes sin instanciación separada | Conforme al contrato pedagógico del core donde los nodos operan sobre enteros representables. En fases posteriores se podrán evaluar plantillas genéricas (`templates`). |
| Inserciones degeneradas en el árbol binario | Una secuencia monótona de inserciones genera un árbol degenerado con altura $O(n)$ en lugar de $O(\log n)$ | Comportamiento estándar de un BST puro no balanceado; el balanceo automático se abordará en módulos avanzados de árboles auto-balanceables (AVL / Red-Black). |
| Agotamiento de memoria del sistema (`std::bad_alloc`) | Si `new` falla por falta de memoria en heap, se lanza una excepción estándar de C++ | Comportamiento canónico de C++; no se imponen límites artificiales ni capacidades máximas al ADT. |

---

## 📝 Notas de implementación / Implementation Notes

### 🧱 Jerarquía de herencia y base de valor / Inheritance hierarchy and value base

La clase base `Node` encapsula el atributo `int value_` y provee el observador `get_value()`. Para adherirse a las directrices de C++ (Core Guideline C.35), su constructor y destructor son protegidos y no virtuales, evitando cualquier sobrecoste de despacho dinámico y garantizando que `Node` actúe estrictamente como base local no instanciable por sí misma. Tanto `TreeNode` como `GraphNode` heredan públicamente de `Node` e inicializan la base en sus constructores.

Base class `Node` encapsulates the attribute `int value_` and provides the observer `get_value()`. To follow C++ guidelines (Core Guideline C.35), its constructor and destructor are protected and non-virtual, avoiding any dynamic dispatch overhead and ensuring `Node` acts strictly as a non-instantiable local base. Both `TreeNode` and `GraphNode` publicly derive from `Node` and initialize the base within their constructors.

### 🌳 Árbol binario de búsqueda / Binary Search Tree

`BinaryTree` implementa un ABB clásico no acotado. La operación `insert` recorre recursiva o iterativamente el árbol según la relación de orden ($<$, $>$) y es idempotente ante valores duplicados (no incrementa `count_`). La pertenencia `contains` realiza una búsqueda guiada por la invariante de orden en tiempo $O(h)$. La liberación de memoria se realiza recursivamente en postorden en el destructor (`free_tree`).

`BinaryTree` implements a classic unbounded BST. The `insert` operation traverses the tree according to ordering ($<$, $>$) and is idempotent for duplicate values (without incrementing `count_`). The `contains` query performs an invariant-guided traversal in $O(h)$ time. Memory deallocation is executed recursively in post-order inside the destructor (`free_tree`).

### 🕸️ Grafo con registro enlazado y adyacencia ordenada / Graph with linked registry and sorted adjacency

`Graph` implementa un grafo dirigido con registro explícito de vértices. Internamente, los vértices forman una lista enlazada canónica mediante el puntero `next_vertex_`, garantizando que la localización de un vértice `find_vertex(label)` sea un recorrido lineal $O(V)$ sin depender de índices preasignados ni contenedores asociativos de biblioteca. Las aristas se almacenan en `neighbors_` (`std::list<int>`) manteniendo orden ascendente estricto mediante inserción ordenada manual e ignorando duplicados en tiempo $O(d(u))$.

`Graph` implements a directed graph with explicit vertex registration. Internally, vertices form a canonical linked list via the `next_vertex_` pointer, ensuring vertex lookup `find_vertex(label)` is a linear $O(V)$ traversal without depending on preallocated indices or associative library containers. Edges are stored in `neighbors_` (`std::list<int>`) maintaining strict ascending order via manual sorted insertion and ignoring duplicates in $O(d(u))$ time.

### 💾 Gestión de memoria y seguridad de copias / Memory management and copy safety

Todas las asignaciones dinámicas (`new TreeNode`, `new GraphNode`) se emparejan con su correspondiente desasignación en los destructores de `BinaryTree` y `Graph`. Las operaciones de copia y asignación por copia/movimiento se inhabilitan explícitamente (`= delete`) para evitar punteros colgantes o dobles liberaciones accidentales. La consulta `get_neighbors` devuelve un `std::unique_ptr<std::list<int>>` que contiene una copia profunda de la adyacencia, garantizando aislamiento total entre la vista del cliente y la estructura interna del grafo.

All dynamic allocations (`new TreeNode`, `new GraphNode`) are matched with corresponding deallocations in the destructors of `BinaryTree` and `Graph`. Copy and move constructors/assignments are explicitly disabled (`= delete`) to prevent dangling pointers or double frees. The `get_neighbors` query returns a `std::unique_ptr<std::list<int>>` containing a deep copy of adjacency, guaranteeing complete isolation between client views and internal graph state.

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
| Especificación / Specification | [`07_Data_Structures_Advanced.md`](../../../../../docs/core/algorithms/07_Data_Structures_Advanced.md) |
| Primera base del lenguaje / First language reference | [`cpp/core/algorithms/data_structures_basics/`](../data_structures_basics/README.md) |
| Segunda base del lenguaje / Second language reference | [`cpp/core/foundations/numbers/`](../../foundations/numbers/README.md) |
| Guía de inicialización / Initialisation guide | [`core/00_Project_Initialization_Guide.md`](../../../../../docs/core/00_Project_Initialization_Guide.md) |
| Adaptaciones idiomáticas / Idiomatic adaptations | [`AGENT_Template.md`](../../../../../docs/AGENT_Template.md) |
| Validación de la documentación / Documentation validation | [`WORKFLOW.md`](../../../../../docs/WORKFLOW.md) |
| Documentación oficial del lenguaje / Language official docs | [cppreference.com](https://en.cppreference.com/) |

---

*[← Volver a Algorithms Pure](../README.md) | [↑ Volver a Core](../../README.md)*

*🌐 [github.com/yorche3/programming_languages](https://github.com/yorche3/programming_languages) · [GitHub Pages](https://yorche3.github.io/programming_languages/)*
