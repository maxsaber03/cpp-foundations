#include <print>
#include "memoryDemo.h"

// ---------------- Node ----------------

Node::Node(int v, Node* n)
    : value(v), next(n)
{
    std::println("  HEAP: new Node -> created value={} (next link set).", value);
}

Node::~Node()
{
    std::println("  HEAP: delete Node -> destroyed value={}.", value);
}

// ---------------- LinkedList ----------------

LinkedList::LinkedList()
    : head(nullptr), count(0)
{
    std::println("STACK: LinkedList constructed -> head=nullptr, count=0.");
}

LinkedList::~LinkedList()
{
    std::println("\nSTACK: ~LinkedList() -> list leaving scope, must delete remaining {} node(s).", count);
    clear();
    std::println("STACK: ~LinkedList() done.");
}

void LinkedList::push_front(int v)
{
    std::println("\nSTACK: push_front({})", v);
    std::println("  CODE: head = new Node(v, head)");
    head = new Node(v, head);
    ++count;
    std::println("  RESULT: head now points to new node, count={}.", count);
}

void LinkedList::insert_sorted(int v)
{
    std::println("\nSTACK: insert_sorted({})", v);

    if (!head) {
        std::println("  BRANCH: empty list -> insert at head.");
        push_front(v);
        return;
    }

    if (v <= head->value) {
        std::println("  BRANCH: {} <= head->value({}) -> insert at head.", v, head->value);
        push_front(v);
        return;
    }

    Node* cur = head;
    std::size_t i = 0;

    while (cur->next && cur->next->value < v) {
        std::println("  WALK: cur=[{}] value={} -> move cur=cur->next", i, cur->value);
        cur = cur->next;
        ++i;
    }

    std::println("  INSERT: after node value={} (rewire 1 link).", cur->value);
    std::println("  CODE: cur->next = new Node(v, cur->next)");
    cur->next = new Node(v, cur->next);
    ++count;

    std::println("  RESULT: inserted {}, count={}.", v, count);
}

bool LinkedList::find(int v) const
{
    std::println("\nSTACK: find({})", v);

    Node* cur = head;
    std::size_t i = 0;

    while (cur) {
        std::println("  CHECK: node[{}] value={}", i, cur->value);

        if (cur->value == v) {
            std::println("  FOUND -> return true");
            return true;
        }

        cur = cur->next;
        ++i;
    }

    std::println("  NOT FOUND -> return false");
    return false;
}

bool LinkedList::remove_value(int v)
{
    std::println("\nSTACK: remove_value({})", v);
    std::println("  GOAL: delete at most 1 node (first match).");

    if (!head) {
        std::println("  BRANCH: empty list -> return false");
        return false;
    }

    if (head->value == v) {
        std::println("  BRANCH: node is head (value={}).", v);
        Node* node_to_delete = head;
        std::println("  CODE: head = head->next; delete node_to_delete;");
        head = head->next;
        delete node_to_delete;
        --count;
        std::println("  RESULT: deleted head, count={}.", count);
        return true;
    }

    Node* cur = head;

    while (cur->next) {
        if (cur->next->value == v) {
            std::println("  FOUND: node after value={}.", cur->value);
            Node* node_to_delete = cur->next;
            std::println("  CODE: cur->next = node_to_delete->next; delete node_to_delete;");
            cur->next = node_to_delete->next;
            delete node_to_delete;
            --count;
            std::println("  RESULT: deleted {}, count={}.", v, count);
            return true;
        }
        cur = cur->next;
    }

    std::println("  NOT FOUND -> return false");
    return false;
}

void LinkedList::clear()
{
    std::println("\nSTACK: clear()");
    std::println("  LOOP: while(head) {{ node_to_delete=head; head=head->next; delete node_to_delete; }}");

    while (head) {
        Node* node_to_delete = head;
        head = head->next;
        delete node_to_delete;
    }

    count = 0;
    std::println("  RESULT: head=nullptr, count=0.");
}

void LinkedList::print() const
{
    std::println("\nSTACK: print()  (read-only traversal)");
    std::println("LinkedList size={}", count);

    Node* cur = head;
    std::size_t index = 0;

    while (cur) {
        std::println("  [{}] value={}", index, cur->value);
        cur = cur->next;
        ++index;
    }
}
