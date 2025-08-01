# Deque (Deck) in C++

Simple deque template class (doubly-linked list) implemenation in C++.

> C++ deque implements doubly-linked list using arry of array, which latter contains index of the next and prev
ious node.

<!-- markdown-toc start - Don't edit this section. Run M-x markdown-toc-refresh-toc -->
**Table of Contents**

- [Deque (Deck) in C++](#deque-deck-in-c)
  - [API](#api)
  - [Example](#example)
  - [Structure](#structure)
    - [-](#-)
  - [To run the code](#to-run-the-code)

<!-- markdown-toc end -->

## API

| Functions                      | Description                                      |
|--------------------------------|--------------------------------------------------|
| `bool isEmpty()`               | Returns `true` if the deque is empty, `false` otherwise. Uses `N <= 0` for check. |
| `int size()`                   | Returns the current number of elements (`N`) in the deque. |
| `void pushLeft(T item)`        | Inserts an element to the left side of the deque. |
| `void pushRight(T item)`       | Inserts an element to the right side of the deque. |
| `T popLeft()`                  | Removes and returns the leftmost item from the deque. |
| `T popRight()`                 | Removes and returns the rightmost item from the deque. |
| `T peekLeft()`                 | Returns the leftmost element without removing it. |
| `T peekRight()`                | Returns the rightmost element without removing it. |

## Example

```cpp
#include "deque.hpp"
#include <iostream>
#include <ostream>
#include <string>

int main() {
    Deque<std::string> myDeq;

    std::cout << "Deq " << (myDeq.isEmpty() ? "is " : "is not ") << "empty."
              << '\n';

    myDeq.pushLeft("Hello");
    myDeq.pushLeft("World");
    myDeq.pushLeft("!");

    myDeq.pushRight("saids");
    myDeq.pushRight("John");

    auto left_item = myDeq.peekLeft();
    std::cout << "Left item: " << left_item << '\n';

    auto right_item = myDeq.peekRight();
    std::cout << "Right item: " << right_item << '\n';

    std::cout << "Deque is now sized " << myDeq.size() << '\n';

    while (!myDeq.isEmpty()) {
        std::cout << myDeq.popLeft() << " ";
    }
    std::cout << '\n';
}
```

Example output:

```
Deq is empty.
Left item: !
Right item: John
Deque is now sized 5
John saids Hello World !
````

## Structure

```mermaid
classDiagram
    class Node {
        +next: shared_ptr Node*
        +prev: share_ptr Node*
        +data: template T
    }
    
    class Deque {
        +left: shared_ptr Node*
        +right: shared_ptr Node*
    }
    
    Node <-- Deque : contains
````

```mermaid
graph LR
    subgraph Deque
        direction LR
        Head[Left] <--next/prev--> A[Node]
        A[Node] <--next/prev--> B[Node]
        B[Node] <--next/prev--> Tail[Right]
    end
```

#### TODO

1. add c++20 concepts.
2. weak_ptr for safty.

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
