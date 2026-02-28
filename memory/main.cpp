#include <print>
#include "memoryDemo.h"

int main()
{
    std::println("=== Linked List Memory Demo ===");
    std::println("--- demo begin ---");

    LinkedList list;

    // Insert values in non-sorted order; list will keep them sorted.
    list.insert_sorted(30);
    list.insert_sorted(10);
    list.insert_sorted(20);
    list.insert_sorted(40);
    list.insert_sorted(25);

    list.print();

    // Find
    (void)list.find(20);
    (void)list.find(99);

    // Remove (head, middle, missing)
    (void)list.remove_value(10);
    (void)list.remove_value(25);
    (void)list.remove_value(12345);

    list.print();

    std::println("\n--- demo end (list will be destroyed as it leaves scope) ---");
    return 0;
}
