# Calculator — C++

Implementación de la especificación [03_Unit_Test_Calculator](https://yorche3.github.io/programming_languages/core/foundations/03_Unit_Test_Calculator/) en **C++**, utilizando **Bazelisk** (Bazel) y **Google Test** para las pruebas unitarias.

---

## 📂 Archivos y estructura / Files & Structure

| Archivo / Directorio | Propósito |
|----------------------|-----------|
| `include/calculator.h` | Interfaz de la clase `Calculator`. |
| `src/calculator.cpp` | Implementación de las 5 operaciones aritméticas básicas. |
| `tests/calculator_tests.cpp` | Suite de pruebas unitarias con Google Test. |
| `BUILD` | Configuración de construcción de Bazel (targets). |
| `MODULE.bazel` | Gestión de dependencias externa (Google Test via Bzlmod). |
| `WORKSPACE` | Raíz del espacio de trabajo (legacy/compatibility). |
| `.bazelversion` | Versión fija de Bazel para el proyecto. |
| `.gitignore` | Archivos y carpetas ignoradas (específico de Bazel). |

**Estructura de directorios esperada:**

```text
calculator/
├── include/
│   └── calculator.h
├── src/
│   └── calculator.cpp
├── tests/
│   └── calculator_tests.cpp
├── BUILD
├── MODULE.bazel
├── WORKSPACE
├── .bazelversion
└── .gitignore
```

---

## 🛠️ Enfoque y construcción / Approach & Build

**ES:** El proyecto se configuró manualmente utilizando **Bazel** como sistema de construcción moderno. En lugar de compilar archivos individuales, Bazel gestiona la descarga de dependencias (Google Test) y la vinculación de la librería de forma automática.

**EN:** The project was manually configured using **Bazel** as a modern build system. Instead of compiling individual files, Bazel manages dependency downloads (Google Test) and library linking automatically.

### Pasos de inicialización:

1.  **Definir el módulo**: Configuración de `MODULE.bazel` para importar Google Test.
2.  **Configurar el BUILD**: Creación de un target `cc_library` para la lógica y un `cc_test` para las pruebas.
3.  **Ejecución con Bazelisk**: Uso de `bazelisk` para garantizar que todos los desarrolladores usen la misma versión de Bazel.

---

## 📄 Archivos de configuración clave / Key Configuration Files

### `BUILD` – Configuración de build

**ES:** Define los componentes del proyecto: una librería pública (`calculator_lib`) y un ejecutable de pruebas que depende de ella y de Google Test.
**EN:** Defines the project components: a public library (`calculator_lib`) and a test executable that depends on it and Google Test.

### `MODULE.bazel` – Manifiesto de dependencias

**ES:** Utiliza el nuevo sistema **Bzlmod** para declarar la dependencia de `googletest` versión `1.15.2`.
**EN:** Uses the new **Bzlmod** system to declare the `googletest` version `1.15.2` dependency.

---

## 🚀 Compilación y ejecución / Build & Run

### Compilar / Build
```bash
bazelisk build //...
```

### Ejecutar pruebas / Run tests
```bash
bazelisk test //...
```

**Salida esperada / Expected output:**
```text
INFO: Analyzed target //:calculator_test (0 packages loaded, 0 targets configured).
INFO: Found 1 test target...
Target //:calculator_test up-to-date:
  bazel-bin/calculator_test
INFO: Elapsed time: 0.150s, Critical Path: 0.01s
INFO: 1 process: 1 internal.
PASS: //:calculator_test
```

---

## 🧠 Algoritmos / operaciones

| Función / Algoritmo | Enfoque | Descripción |
|---------------------|---------|-------------|
| `Addition` | Directo | Suma de dos enteros. |
| `Subtraction` | Directo | Resta de dos enteros. |
| `Multiplication` | Iterativo | Suma repetitiva sin usar el operador `*`. |
| `Division` | Iterativo | Restas sucesivas sin usar el operador `/`. |
| `Modulus` | Iterativo | Resto de la división iterativa. |

---

## 📝 Notas de implementación / Implementation Notes

- **ES:** Para las operaciones de multiplicación y división se utilizaron bucles manuales para cumplir con el requisito educativo de no usar los operadores directos del lenguaje.
- **EN:** For multiplication and division operations, manual loops were used to comply with the educational requirement of not using the language's direct operators.
- **ES:** Se utilizó `strip_include_prefix` en el archivo BUILD para permitir inclusiones limpias como `#include "calculator.h"` sin importar la estructura de carpetas `include/`.

---

### 🌐 Otras implementaciones / Other implementations
Este proyecto también está implementado en otros lenguajes. Explora el repositorio principal para ver todas las versiones.

*🌐 github.com/yorche3/programming_languages · GitHub Pages*