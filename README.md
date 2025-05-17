# Estruturas de Dados e Algoritmos

Este repositório reúne todas as implementações de **Estruturas de Dados** e **Algoritmos** que estou desenvolvendo ao longo do curso de **Ciência da Computação** na **UFES**.

A ideia é manter um registro claro, modular e reutilizável dos principais conceitos estudados, separados por categorias.

## 📁 Estrutura do Projeto

- [`structures/`](structures) — Implementações de estruturas de dados:
    - [`graph/`](structures/graph) — Grafos
    - [`hash/`](structures/hash) — Tabelas hash
    - [`heap/`](structures/heap) — Heaps
    - [`linear/`](structures/linear) — Listas lineares (listas simples, duplamente encadeadas etc.)
    - [`tree/`](structures/tree) — Árvores (binárias, balanceadas etc.)

- [`algorithms/`](algorithms) — Algoritmos diversos (busca, ordenação, programação dinâmica, etc.)

Cada subpasta contém:
- Código-fonte em C (`.c`, `.h`)
- Um `main.c` com testes
- `CMakeLists.txt` para facilitar a compilação com CMake

## 🚀 Como Compilar
Este projeto usa **CMake**.

- No CLion: basta abrir o projeto, o CMake já vem integrado, e rodar o build normalmente.
- Terminal: certifique-se de ter o CMake instalado, depois execute:

```bash
cd structures/linear/1_simple_list  # Exemplo
mkdir build && cd build
cmake ..
make
./<nome_do_executável>
