# Hello, User! — C++

Implementación de la especificación [02_Hello_User](https://yorche3.github.io/programming_languages/core/foundations/02_Hello_User/) en **C++**, compilada con **G++**.

Lee un nombre desde la entrada estándar y saluda al usuario.

---

## 📂 Archivos y estructura / Files & Structure

| Archivo | Propósito |
|---------|-----------|
| [`hello_user.cpp`](hello_user.cpp) | Código fuente: solicita un nombre al usuario y saluda. |

**Estructura de directorios esperada:**

```text
hellouser/
├── hello_user.cpp     # Código fuente
├── hello_user         # Ejecutable (generado con g++)
└── README.md          # Este archivo
```

---

## 🛠️ Enfoque y construcción / Approach & Build

**ES:** Este programa introduce dos conceptos nuevos respecto a `helloworld`:

1. **Declaración de variables** — `string name` para almacenar el nombre ingresado.
2. **Lectura de entrada** — `getline(cin, name)` lee una línea completa desde `stdin`, incluyendo espacios.
3. **Concatenación con `<<`** — `cout << "Hello, " << name << "!\n"` para construir el saludo.

**EN:** This program introduces two new concepts compared to `helloworld`:

1. **Variable declaration** — `string name` to store the entered name.
2. **Input reading** — `getline(cin, name)` reads a full line from `stdin`, including spaces.
3. **Concatenation with `<<`** — `cout << "Hello, " << name << "!\n"` to build the greeting.

> **ES:** Se usa `getline(cin, name)` en lugar de `cin >> name` para permitir nombres con espacios. `cin >>` dejaría de leer al encontrar un espacio.
> **EN:** `getline(cin, name)` is used instead of `cin >> name` to allow names with spaces. `cin >>` would stop reading at the first space.

---

## 📄 Archivos de configuración clave / Key Configuration Files

### `hello_user.cpp`

**ES:** El flujo del programa es:

1. Declarar una variable `string name`.
2. Imprimir `"Enter your name: "` con `cout`.
3. Leer una línea completa con `getline(cin, name)`.
4. Imprimir `"Hello, <nombre>!"` con `cout`.
5. Retornar 0 indicando éxito.

**EN:** Program flow:

1. Declare a `string name` variable.
2. Print `"Enter your name: "` with `cout`.
3. Read a full line with `getline(cin, name)`.
4. Print `"Hello, <name>!"` with `cout`.
5. Return 0 indicating success.

```cpp
#include <iostream>
using namespace std;

int main()
{
  string name;
  cout << "Enter your name: ";
  getline(cin, name);
  cout << "Hello, " << name << "!\n";
  return 0;
}
```

| Elemento | Propósito |
|----------|-----------|
| `#include <iostream>` | Importa la biblioteca de E/S de C++ |
| `string name;` | Declara una variable de tipo `string` (C++ estándar) |
| `getline(cin, name)` | Lee una línea completa desde la entrada estándar |
| `cout << "Hello, " << name << "!\n"` | Imprime el saludo usando el operador de inserción `<<` |

> **ES:** `string` forma parte de la biblioteca estándar de C++, no es necesario incluir `<string>` explícitamente porque `<iostream>` lo trae indirectamente (aunque en código estricto debería incluirse).
> **EN:** `string` is part of the C++ standard library. Including `<string>` explicitly is not strictly necessary because `<iostream>` brings it indirectly (though strictly it should be included).

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
g++ -o hello_user hello_user.cpp

# Ejecutar
./hello_user
```

**Salida esperada / Expected output:**

```text
Enter your name: Ada
Hello, Ada!
```

> **ES:** El programa espera a que el usuario escriba su nombre y presione Enter antes de mostrar el saludo.
> **EN:** The program waits for the user to type their name and press Enter before showing the greeting.

---

## 📝 Notas de implementación / Implementation Notes

- **ES:** Se usa `getline` en lugar de `cin >>` para leer nombres que contengan espacios (ej: "Ada Lovelace"). `cin >>` solo leería "Ada".
- **EN:** `getline` is used instead of `cin >>` to read names that contain spaces (e.g., "Ada Lovelace"). `cin >>` would only read "Ada".
- **ES:** La variable `name` es de tipo `std::string` (gracias a `using namespace std;`). No necesita un tamaño fijo como en C — crece dinámicamente.
- **EN:** The `name` variable is of type `std::string` (thanks to `using namespace std;`). It doesn't need a fixed size like in C — it grows dynamically.

---

### 🌐 Otras implementaciones / Other implementations

Este proyecto también está implementado en otros lenguajes. Explora el [repositorio principal](https://github.com/yorche3/programming_languages) para ver todas las versiones.

---

*🌐 [github.com/yorche3/programming_languages](https://github.com/yorche3/programming_languages) · [GitHub Pages](https://yorche3.github.io/programming_languages/)*
