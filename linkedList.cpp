#include <iostream>
#include <cassert>

template <typename T>
struct Node
{
    T value{};
    Node *next{ nullptr };
};

template <typename T>
class linkedList
{
public:
    void push(T value)
    {
        Node<T>* newNode = new Node<T> { value };

        if (!head)
        {
            head = newNode;
            ++size;
            return;
        }

        if(!tail) {
            tail = newNode;
            head->next = tail;
            ++size;
            return;
        }
        
        // Node<T> *current{head};

        // while (current->next)
        // {
        //     current = current->next;
        // }

        // current->next = newNode;

        tail->next = newNode;
        tail = newNode;
        ++size;
    }

    void unshift(T value) {
        Node<T>* newHead = new Node<T> { value };

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

    T pop() {

        assert(size > 0);

        if(size == 1) {
            T value { head->value };
            head = nullptr;
            return value;
        };

        int i{ 0 };
        Node<T>* current{ head };
        while (i < size - 2) // the loop should stop one element before the last
        {
            current = current->next;
            ++i;
        }

        T value { current->next->value };
        current->next = nullptr;
        --size;

        return value;
    }

    void shift() {
        if(!head) return;

        Node<T>* temp { head };

        if(!tail) {
            head = tail;
            delete temp;
            --size;
            return;
        }

        head = head->next;

        delete temp;
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
    ~linkedList() {}

private:
    Node<T> *head{};
    Node<T> *tail{};
    int size { 0 };
};

int main()
{

    linkedList<int> list{};

    for (int i{1}; i <= 10; ++i)
    {
        list.push(i);
    }

    for (int i{11}; i <= 15; ++i)
    {
        list.unshift(i);
    }

    for(int i{ 0 }; i < 15; ++i) {
        std::cout << list.get(i) << ' ';
    }
    std::cout << '\n';

    std::cout << list.pop() << '\n';
    list.shift();

    for(int i{ 0 }; i < 13; ++i) {
        std::cout << list.get(i) << ' ';
    }
    std::cout << '\n';

    return 0;
}