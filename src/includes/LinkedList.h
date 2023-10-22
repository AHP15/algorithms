#ifndef LINKED_LIST_H
#define LINKED_LIST_H

template <typename T>
struct Node
{
    T value{};
    Node* next{nullptr};
};

template<typename T>
class LinkedList
{
public:
    void push(T value)
    {
        Node<T>* newNode { new Node<T>{value} };
        ++size;

        if(!head)
        {
            head = newNode;
            return;
        }

        if(!tail)
        {
            tail = newNode;
            head->next = tail;
            return;
        }

        tail->next = newNode;
        tail = newNode;
    }

    T pop()
    {
        if(size == 1)
        {
            --size;
            T value { head->value };
    delete head;
            head = nullptr;
            return value;
        }

        int i{ 0 };
        Node<T>* current{ head };
        while (i < size - 2) //the loop should stop one element before the last
        {
            current = current->next;
            ++i;
        }

        T value{current->next->value};
    delete current->next;
        current->next = nullptr;
        --size;
        return value;
    }

    void unshift(T value)
    {
        Node<T>* newNode { new Node<T>{value} };
        ++size;

        if(!head)
        {
            head = newNode;
            return;
        }

        newNode->next = head;
        head = newNode;
    }

    void shift()
    {
        Node<T>* temp { head };
        head = head->next;
    delete temp;
        --size;
    }

    void removeAt(int position)
    {
        if(position == 0)
        {
            shift();
            return;
        }

        if(position == size - 1)
        {
            pop();
            return;
        }

        Node<T>* current { head };
        int i { 0 };
        while (i < position - 1)
        {
            current = current->next;
            i++;
        }

        Node<T>* nodeToBeRemoved { current->next };
        current->next = nodeToBeRemoved->next;
    delete nodeToBeRemoved;
        --size;
    }

    T get(int index)
    {
        Node<T>* current{ head };
        int i{0};
        while (i < index)
        {
            current = current->next;
            ++i;
        }

        return current->value;
    }

    int getLength() { return size; }
private:
    Node<T>* head{nullptr};
    Node<T>* tail{nullptr};
    int size{0};
};
#endif