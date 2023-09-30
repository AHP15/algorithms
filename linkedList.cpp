#include <iostream>

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
            return;
        }

        if(!tail) {
            tail = newNode;
            head->next = tail;
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
    }

    void unshift(T value) {
        Node<T>* newHead = new Node<T> { value };

        if (!head)
        {
            head = newHead;
            return;
        }

        newHead->next = head;
        head = newHead;
    }

    T pop() {

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
    return 0;
}