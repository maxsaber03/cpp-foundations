# Memory Demo – Linked List (C++)

This project demonstrates core memory management mechanics in modern C++, 
with emphasis on how stack and heap interact during object lifetime.

## Concepts Demonstrated

- Stack vs Heap allocation
- Manual dynamic memory using `new` and `delete`
- Deterministic destructor-based cleanup
- Ownership control (copy disabled to prevent shallow copy)
- Pointer rewiring in a singly linked list
- Safe node removal and full list deallocation

## Files

- `main.cpp` – Demonstration driver
- `memoryDemo.h` – Declarations
- `memoryDemo.cpp` – Implementation

## Design Notes

- Each `Node` is allocated on the heap.
- The `LinkedList` object itself lives on the stack.
- The destructor calls `clear()` to prevent memory leaks.
- Copy constructor and copy assignment are explicitly deleted to prevent double-free errors.

## Compilation

Requires C++23 (`<print>` support).

```bash
g++ -std=c++23 main.cpp memoryDemo.cpp -o demo
```

## Sample Output (trimmed)

```text
=== Linked List Memory Demo ===
STACK: LinkedList constructed -> head=nullptr, count=0.

STACK: insert_sorted(30)
  HEAP: new Node -> created value=30

STACK: insert_sorted(10)
  HEAP: new Node -> created value=10

STACK: ~LinkedList()
  HEAP: delete Node -> destroyed value=10
  HEAP: delete Node -> destroyed value=30
```
