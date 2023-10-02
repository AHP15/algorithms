#include <iostream>
#include <cassert>

template <typename T>
struct Node
{
    T value{};
    Node *next{nullptr};
};

template <typename T>
class linkedList
{
public:
    void push(T value)
    {
        Node<T> *newNode = new Node<T>{value};

        if (!head)
        {
            head = newNode;
            ++size;
            return;
        }

        if (!tail)
        {
            tail = newNode;
            head->next = tail;
            ++size;
            return;
        }

        tail->next = newNode;
        tail = newNode;
        ++size;
    }

    void unshift(T value)
    {
        Node<T> *newHead = new Node<T>{value};

        if (!head)
        {
            head = newHead;
            ++size;
            return;
        }

        newHead->next = head;
        head = newHead;
        ++size;
    }

    T pop()
    {

        assert(size > 0);

        if (size == 1)
        {
            T value{head->value};
            head = nullptr;
            --size;
            return value;
        };

        int i{0};
        Node<T> *current{head};
        while (i < size - 2) // the loop should stop one element before the last
        {
            current = current->next;
            ++i;
        }

        T value{current->next->value};
        current->next = nullptr;
        --size;

        return value;
    }

    void shift()
    {
        if (!head)
            return;

        Node<T> *temp{head};

        head = head->next;

        --size;

        delete temp;
    }

    void insertAt(T value, int position)
    {
        if(position == 0) {
            unshift(value);
            return;
        }

        Node<T> *current{head};
        int i{0};
        // index - 1 because the loop should stop before the insertion position by one
        while (i < position - 1)
        {
            current = current->next;
            ++i;
        }

        Node<T> *oldNext{current->next};
        Node<T> *newNext{new Node{value}};
        current->next = newNext;
        newNext->next = oldNext;
        ++size;
    }

    void remove(int index) {

        if(index == 0) {
            shift();
            return;
        }

        Node<T>* current{head};
        int i{0};
        // index - 1 because the loop should stop before the insertion position by one
        while (i < index - 1)
        {
            current = current->next;
            ++i;
        }

        Node<T> *nodeToBeRemoved{current->next};

        current->next = nodeToBeRemoved->next;
        delete nodeToBeRemoved;

        --size;
    }

    T get(int index)
    {
        Node<T> *current{head};
        int i{0};
        while (i < index)
        {
            current = current->next;
            ++i;
        }

        return current->value;
    }

    void reverse() {
        if(size <= 1) return;

        Node<T>* current {head};
        Node<T>* next{ nullptr };
        Node<T>* prev { nullptr };

        while (current)
        {
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }

        tail = head;
        head = prev;
        
    }

    ~linkedList() {
        while (size > 0)
        {
            shift();
            --size;
        }
        
    }

private:
    Node<T> *head{nullptr};
    Node<T> *tail{nullptr};
    int size{0};
};

int main()
{

    linkedList<int> list{};
    return 0;
}