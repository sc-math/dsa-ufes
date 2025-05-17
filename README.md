# Estruturas de Dados e Algoritmos

Este repositório reúne todas as implementações de **Estruturas de Dados** e **Algoritmos** feitas durante meu curso de
**Ciência da Computação** na **UFES**, além de alguns projetos extras que criei por curiosidade.  
A ideia é manter um registro claro, modular e reutilizável dos principais conceitos estudados, separados por categorias.

## 📁 Estrutura do Projeto

- [`structures/`](structures) — Estruturas de dados organizadas por tipo:
  - [`graph/`](structures/graph) — Grafos (simples, ponderados, dirigidos)
  - [`hash/`](structures/hash) — Tabelas hash (HashSets, HashMaps)
  - [`heap/`](structures/heap) — Heaps (min, max, binomial, fibonacci, fila de prioridade)
  - [`linear/`](structures/linear) — Listas, Vetores, Pilhas e Filas (simples, duplamente encadeadas, circulares, deque)
  - [`tree/`](structures/tree) — Árvores (binária, AVL, red-black, B, trie, etc.)

- [`algorithms/`](algorithms) — Algoritmos organizados por tema:
  - [`searching/`](algorithms/searching) — Busca (linear, binary, hashing)
  - [`sorting/`](algorithms/sorting) — Ordenação (insertion, selection, bubble, heap, merge, quick)
  - [`graphs/`](algorithms/graphs) — Grafos (BFS, DFS, Kruskal, Dijkstra, etc.)
  - [`math/`](algorithms/math) — Matemática e Teoria dos Números (Sieve, Euclidean, etc.)
  - [`misc/`](algorithms/misc) — Diversos (Kadane, LIS, etc.)

Cada subpasta contém:
- Código-fonte em C (`.c`, `.h`)
- Um `main.c` com testes
- `CMakeLists.txt` para facilitar a compilação com CMake

## ✅ Pré-requisitos

- GCC ou outro compilador C
- [CMake](https://cmake.org/) instalado
- (Opcional) [CLion](https://www.jetbrains.com/clion/) ou outro IDE com suporte a CMake

## 🚀 Como Compilar

Este projeto usa **CMake** para facilitar a compilação.

- **No CLion**: basta abrir o projeto, o CMake já vem integrado, e rodar o build normalmente.
- **No Terminal**: certifique-se de ter o CMake instalado, depois execute:

```bash
cd structures/linear/1_simple_list  # Exemplo, pode ser qualquer outra pasta com CMakeLists.txt
mkdir build && cd build
cmake ..
make
./app  # O nome do executável é definido no CMakeLists.txt (Por padrão: "app")
```
> 💡 Para compilar outras estruturas ou algoritmos, é só mudar o caminho do `cd` para a pasta desejada  
> (exemplo: `structures/tree/2_avl_tree`, `algorithms/sorting/quick_sort`, etc.).
