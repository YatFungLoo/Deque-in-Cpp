# Deque (Deck) in C++
Simple doubly-linked list implemenation in C++.

[![CMake on multiple platforms](https://github.com/YatFungLoo/Deque-in-Cpp/actions/workflows/cmake-multi-platform.yml/badge.svg)](https://github.com/YatFungLoo/Deque-in-Cpp/actions/workflows/cmake-multi-platform.yml)

## TODO

1. add c++20 concepts

## To run the code

```bash
cmake -S . --preset=debug -B build
```

or

```bash
cmake -S . --preset=release -B build
```

then run

```bash
cmake --build build
```

or

```bash
cd build && ninja clean && ninja
```

and executable will exist in the `build/` directory.

to generate compile_commands.json file for clangd LSP, use

```bash
cmake -DCMAKE_EXPORT_COMPILE_COMMANDS=1 .. --preset=${PRESET_NAME}

cd ${ROOT_DIRECTORY}

ln -s build/compile_commands.json
```
