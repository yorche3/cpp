# C++

Proyectos en **C++** (C++11 o superior), compilados con **G++** para programas simples y con **Bazel** (via Bazelisk) para proyectos con pruebas unitarias con **Google Test**.

---

## 📂 Módulos / Modules

| Módulo | Descripción |
|--------|-------------|
| [`core/foundations/`](core/foundations/) | **Fase 0 — Fundamentos**: `hello_world`, `hello_user`, `calculator`, `numbers` |

---

### ▶️ Comenzar / Getting Started

```bash
# Hello, World!
cd core/foundations/helloworld
g++ -o HelloWorld HelloWorld.cpp && ./HelloWorld

# Hello, User!
cd core/foundations/hellouser
g++ -o hello_user hello_user.cpp && ./hello_user

# Calculator Tests
cd core/foundations/unit_test/calculator
bazelisk test //...

# Numbers Tests
cd core/foundations/numbers
bazelisk test //...
```

---

## 📦 Requisitos / Requirements

| Herramienta | Instalación |
|-------------|-------------|
| [G++ (GCC)](https://gcc.gnu.org/) | `sudo apt install g++` (Linux) / `winget install GCC.GCC` (Windows) |
| [Bazelisk](https://github.com/bazelbuild/bazelisk) | `npm install -g @bazel/bazelisk` o descargar el [binario](https://github.com/bazelbuild/bazelisk/releases) |

```bash
# Verificar instalación
g++ --version && bazelisk version
```

---

## 🏗️ Tipos de proyecto / Project Types

### 1. Programa simple (compilación directa con G++)

**ES:** Un único archivo fuente, sin dependencias externas, compilado directamente con `g++`. Ideal para `hello_world` y `hello_user`.

**EN:** A single source file, no external dependencies, compiled directly with `g++`. Ideal for `hello_world` and `hello_user`.

```bash
g++ -o <output> <source>.cpp
./<output>
```

### 2. Proyecto con pruebas unitarias (Bazel + Google Test)

**ES:** Para proyectos que requieren pruebas unitarias, se utiliza **Bazel** como sistema de construcción, que gestiona automáticamente la descarga de Google Test y la vinculación de la biblioteca.

**EN:** For projects that require unit tests, **Bazel** is used as the build system, which automatically manages the download of Google Test and library linking.

```bash
bazelisk test //...
```

---

## 🌐 Otras implementaciones / Other implementations

Este proyecto también está implementado en otros lenguajes. Explora el [repositorio principal](https://github.com/yorche3/programming_languages) para ver todas las versiones.

---
*🌐 [github.com/yorche3/programming_languages](https://github.com/yorche3/programming_languages) · [GitHub Pages](https://yorche3.github.io/programming_languages/)*