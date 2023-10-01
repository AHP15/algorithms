#include <iostream>

struct Node
{
    int value{};
    Node* prev{ nullptr };
    Node* next { nullptr };
};

class DoublyLinkedList
{
public:
    void push(int value) {
        if(length == 0) {
            head = new Node{ value };
            ++length;
            return;
        }

        if(length == 1) {
            tail = new Node{ value };
            tail->prev = head;
            head->next = tail;
            ++length;
            return;
        }

        Node* newNode { new Node{ value } };
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
        ++length;
    }

    int get(int index) {
        Node* current{ head };
        int i{0};
        while (i < index)
        {
            current = current->next;
            ++i;
        }

        return current->value;
    }

    int getLength() { return length; }

    ~DoublyLinkedList()
    {

    }
private:
    Node* head{};
    Node* tail{};
    int length { 0 };
};

int main() {
    DoublyLinkedList dl{};
    dl.push(1);
    
    dl.push(2);
    dl.push(3);
    dl.push(4);
    dl.push(5);

    for(int i { 0 }; i < dl.getLength(); ++i) {
        std::cout << dl.get(i) << ' ';
    }
    std::cout << '\n';
    return 0;
}
