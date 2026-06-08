# Hello, World! — C++

Implementación de la especificación [01_Hello_World](https://yorche3.github.io/programming_languages/core/foundations/01_Hello_World/) en **C++**, compilada con **G++**.

---

## 📂 Archivos y estructura / Files & Structure

| Archivo | Propósito |
|---------|-----------|
| [`HelloWorld.cpp`](HelloWorld.cpp) | Código fuente: imprime `"Hello, World! from C++!"` en la consola. |

**Estructura de directorios esperada:**

```text
helloworld/
├── HelloWorld.cpp     # Código fuente
├── HelloWorld         # Ejecutable (generado con g++)
└── README.md          # Este archivo
```

---

## 🛠️ Enfoque y construcción / Approach & Build

**ES:** Este proyecto usa **C++** con **G++** y sigue un enfoque minimalista: un único archivo fuente, sin dependencias externas, compilado directamente con `g++`.

Características:
- **Sin bibliotecas externas** — solo `<iostream>` para `cout`.
- **Compilación directa** — un solo comando `g++` genera el ejecutable.
- **`using namespace std;`** — evita prefijar `std::cout` y `std::endl`.

**EN:** This project uses **C++** with **G++** and follows a minimalist approach: a single source file, no external dependencies, compiled directly with `g++`.

Features:
- **No external libraries** — only `<iostream>` for `cout`.
- **Direct compilation** — a single `g++` command generates the executable.
- **`using namespace std;`** — avoids prefixing `std::cout` and `std::endl`.

---

## 📄 Archivos de configuración clave / Key Configuration Files

### `HelloWorld.cpp`

**ES:** Punto de entrada `main()`. Incluye `<iostream>` para `cout` y retorna `0` al sistema operativo indicando éxito.

**EN:** Entry point `main()`. Includes `<iostream>` for `cout` and returns `0` to the OS indicating success.

```cpp
#include <iostream>
using namespace std;

int main()
{
  cout << "Hello, World! from C++!\n";
  return 0;
}
```

| Elemento | Propósito |
|----------|-----------|
| `#include <iostream>` | Importa la biblioteca de E/S de C++ |
| `using namespace std;` | Permite usar `cout` sin prefijo `std::` |
| `int main()` | Punto de entrada del programa |
| `cout << ...` | Imprime una cadena en la consola |
| `"\n"` | Salto de línea (nueva línea) |
| `return 0;` | Código de salida: 0 = éxito |

---

## 🚀 Compilación y ejecución / Build & Run

### Requisito: Tener G++ instalado

```bash
# Linux (Debian/Ubuntu)
sudo apt install g++

# macOS
xcode-select --install

# Windows (MinGW-w64)
winget install GCC.GCC
```

### Compilar y ejecutar

```bash
# Compilar
g++ -o HelloWorld HelloWorld.cpp

# Ejecutar
./HelloWorld
```

**Salida esperada / Expected output:**

```text
Hello, World! from C++!
```

> **ES:** En Windows, el ejecutable se llamará `HelloWorld.exe`.
> **EN:** On Windows, the executable will be named `HelloWorld.exe`.

---

## 📝 Notas de implementación / Implementation Notes

- **ES:** Se usa `using namespace std;` por simplicidad educativa; en proyectos más grandes se recomienda usar `std::cout` explícitamente para evitar colisiones de nombres.
- **EN:** `using namespace std;` is used for educational simplicity; in larger projects it's recommended to use `std::cout` explicitly to avoid name collisions.
- **ES:** No se necesita archivo de proyecto, Makefile ni sistema de construcción. Un solo comando `g++` es suficiente.
- **EN:** No project file, Makefile or build system is needed. A single `g++` command is sufficient.

---

### 🌐 Otras implementaciones / Other implementations

Este proyecto también está implementado en otros lenguajes. Explora el [repositorio principal](https://github.com/yorche3/programming_languages) para ver todas las versiones.

---

*🌐 [github.com/yorche3/programming_languages](https://github.com/yorche3/programming_languages) · [GitHub Pages](https://yorche3.github.io/programming_languages/)*
