#ifndef MEMORYDEMO_H
#define MEMORYDEMO_H

#include <cstddef>   // std::size_t

// ---------------- Node ----------------
struct Node {
    int value;
    Node* next;

    Node(int v, Node* n = nullptr);
    ~Node();
};

// ---------------- LinkedList ----------------
class LinkedList {
public:
    LinkedList();
    ~LinkedList();

    // Prevent shallow copies (double delete).
    LinkedList(const LinkedList&) = delete;
    LinkedList& operator=(const LinkedList&) = delete;

    void push_front(int v);
    void insert_sorted(int v);
    bool find(int v) const;
    bool remove_value(int v);
    void clear();
    void print() const;

    std::size_t size() const { return count; }
    bool empty() const { return head == nullptr; }

private:
    Node* head;
    std::size_t count;
};

#endif
