# Algorithms Pure — C++

Implementación de la fase [Algorithms Pure](https://yorche3.github.io/programming_languages/ROADMAP/#fase-1--algoritmos-puros--algorithms-pure-) en **C++**, utilizando **Bazelisk** (Bazel) y **Google Test** para las pruebas unitarias.

---

## 📂 Módulos / Modules

| Módulo | Estado | Descripción / Description |
|--------|--------|---------------------------|
| [`naive_sort/`](naive_sort/) | ✅ | **Ordenamiento elemental** ($O(n^2)$): `selection_sort`, `bubble_sort`, `insertion_sort`. / **Elementary sorting** ($O(n^2)$): `selection_sort`, `bubble_sort`, `insertion_sort`. |

---

## 🚀 Compilación y ejecución / Build & Run

Cada módulo contiene sus propios targets de Bazel. Por ejemplo / Each module has its own Bazel targets. For example:

```bash
cd cpp/core/algorithms/naive_sort
bazelisk test //...
```

---

## 📝 Notas de implementación / Implementation Notes

**ES:** Las funciones trabajan sobre `std::vector<int>` por valor y devuelven una copia ordenada. No se usa `std::sort`; la iteración es explícita y los intercambios usan `std::swap`. `bubble_sort` incluye la salida temprana con la bandera `swapped`.

**EN:** The functions work on `std::vector<int>` by value and return a sorted copy. `std::sort` is not used; iteration is explicit and swaps use `std::swap`. `bubble_sort` includes the early exit with the `swapped` flag.

**ES:** Este proyecto también está implementado en otros lenguajes. Explora el repositorio principal para consultar las demás versiones.

**EN:** This project is also implemented in other languages. Explore the main repository to see the other versions.

---

*[← Volver a Core](../README.md)*

*🌐 [github.com/yorche3/programming_languages](https://github.com/yorche3/programming_languages) · [GitHub Pages](https://yorche3.github.io/programming_languages/)*
