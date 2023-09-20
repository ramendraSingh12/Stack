// Program for stack implemention with help of struct and class
#include <iostream>

using namespace std;

template <typename t>
class stack;
class iterator;

// Making a template class for stack which can store multiple value
template <typename t>
class stack
{
public:
    // node struct for stack and store the value
    struct node
    {
        // declare the data node for node's data
        t data;

        // declare the next pointer for node's next
        node *next;

        // default constructor for node
        node() : data(0), next(nullptr) {}

        // parametrized constructors for node
        node(t v) : data(v), next(nullptr) {}
        node(t v, node *ptr) : data(v), next(ptr) {}
    };

    // pointer for head node
    node *head;

    // pointer for tail node
    node *tail;

    // declare a value for return stackSize;
    size_t stackSize;

    class iterator;
    // default constructor for stack, when any obeject will creted the head and tail value will be NULL
    stack() : head(nullptr), tail(nullptr), stackSize(0) {}

    // method for chek is stack empty
    bool isEmpty() { return head == nullptr; }

    // method push the value
    void push(t value)
    {
        node *newNode = new node(value);
        if (newNode != nullptr)
        {
            if (isEmpty())
            {
                head = tail = newNode;
            }
            else
            {
                newNode->next = head;
                head = newNode;
            }
        }
        else
        {
            return;
        }

        stackSize++;
    }

    // method for return the topest element in the stack
    t top() { return head->data; }

    // method for pop the topest element in the stack
    void pop()
    {
        if (isEmpty())
        {
            cout << "Can't pop any element";
            return;
        }
        else
        {
            head = head->next;
        }
        stackSize--;
    }
    node *begin() { return head; }
    node *end() { return tail; }
    size_t size() { return stackSize; }
};