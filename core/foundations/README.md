# 🚀 Foundations — C++

Implementaciones de la [Fase 0 — Fundamentos](https://yorche3.github.io/programming_languages/ROADMAP/#fase-0--fundamentos--foundations--completada) en **C++** (C++11 o superior): `hello_world`, `hello_user`, `unit_test/calculator` y `numbers`.

---

## 📖 Módulos / Modules

| Módulo | Especificación | Enfoque | Tests | Estado |
|--------|---------------|---------|:-----:|:------:|
| [`helloworld/`](helloworld/) | [01_Hello_World](https://yorche3.github.io/programming_languages/core/foundations/01_Hello_World/) | `g++` (archivo único) | — | ✅ |
| [`hellouser/`](hellouser/) | [02_Hello_User](https://yorche3.github.io/programming_languages/core/foundations/02_Hello_User/) | `g++` (archivo único) | — | ✅ |
| [`unit_test/calculator/`](unit_test/calculator/) | [03_Unit_Test_Calculator](https://yorche3.github.io/programming_languages/core/foundations/03_Unit_Test_Calculator/) | Bazel + **Google Test** | 5 | ✅ |
| [`numbers/`](numbers/) | [04_Numbers](https://yorche3.github.io/programming_languages/core/foundations/04_Numbers/) | Bazel + **Google Test** | 10 | ✅ |

---

## 📁 Estructura / Structure

```text
foundations/
├── helloworld/                   # 01_Hello_World
│   ├── HelloWorld.cpp            # Imprime "Hello, World! from C++!"
│   └── README.md
│
├── hellouser/                    # 02_Hello_User
│   ├── hello_user.cpp            # Lee nombre y saluda
│   └── README.md
│
├── unit_test/
│   └── calculator/               # 03_Unit_Test_Calculator
│       ├── include/
│       │   └── calculator.h      # Header con prototipos
│       ├── src/
│       │   └── calculator.cpp    # 5 operaciones aritméticas
│       ├── tests/
│       │   └── calculator_tests.cpp # 5 tests con Google Test
│       ├── BUILD                 # Reglas de Bazel
│       ├── MODULE.bazel          # Dependencias (Google Test)
│       ├── WORKSPACE
│       ├── .bazelversion
│       └── README.md
│
└── numbers/                      # 04_Numbers
    ├── include/
    │   └── numbers.h             # Header con 20 métodos (15 públicos + 5 privados)
    ├── src/
    │   └── numbers.cpp           # 3 enfoques × 5 algoritmos
    ├── tests/
    │   ├── numbers_iterative_tests.cpp  # 5 tests iterativos
    │   └── numbers_recursive_tests.cpp  # 5 tests recursivos
    ├── BUILD
    ├── MODULE.bazel
    ├── WORKSPACE
    ├── .bazelversion
    └── README.md
```

---

## 🛠️ Patrón común / Common Pattern

| Característica | Descripción |
|---------------|-------------|
| **Compilador** | G++ con soporte C++11 o superior |
| **Build system** | `g++` directo para programas simples; **Bazel** para proyectos con tests |
| **Test framework** | [Google Test](https://github.com/google/googletest) v1.15.2 |
| **Dependencias** | Google Test se gestiona automáticamente vía Bzlmod (no requiere instalación manual) |
| **Separación** | `include/` (headers), `src/` (implementación), `tests/` (tests) |
| **Compilación directa** | `g++ -o <output> <source>.cpp && ./<output>` |
| **Compilación Bazel** | `bazelisk test //...` |

---

## 🚀 Compilación rápida / Quick Build

```bash
# Hello, World!
cd helloworld
g++ -o HelloWorld HelloWorld.cpp && ./HelloWorld

# Hello, User!
cd hellouser
g++ -o hello_user hello_user.cpp && ./hello_user

# Calculator Tests
cd unit_test/calculator
bazelisk test //...

# Numbers Tests
cd numbers
bazelisk test //...
```

---

### 🌐 Otras implementaciones / Other implementations

Este proyecto también está implementado en otros lenguajes. Explora el [repositorio principal](https://github.com/yorche3/programming_languages) para ver todas las versiones.

---

## ▶️ Siguiente / Next

👉 Después de fundamentos, continúa con [Fase 1 — Algoritmos Puros](https://yorche3.github.io/programming_languages/ROADMAP/#fase-1--algoritmos-puros--algorithms-pure-).  
👉 After foundations, continue with [Phase 1 — Algorithms Pure](https://yorche3.github.io/programming_languages/ROADMAP/#fase-1--algoritmos-puros--algorithms-pure-).

---

*[← Volver a C++](../README.md)*

*🌐 [github.com/yorche3/programming_languages](https://github.com/yorche3/programming_languages) · [GitHub Pages](https://yorche3.github.io/programming_languages/)*
