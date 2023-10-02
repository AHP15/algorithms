#include <iostream>

template<typename T>
struct Node
{
    T value{};
    Node<T>* next { nullptr };
    Node<T>* prev{ nullptr };
};

template<typename T>
class DoublyLinkedList
{
public:
    void push(T value) {
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
            tail->prev = head;
            head->next = tail;
            ++size;
            return;
        }

        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
        ++size;
    }

    // this method loop throughout the list from both ends
    // if index is in the first half of the list then it start looping from the start
    // otherwise it start from the end
    // this reduces the time complexity from O(n) to O(n/2)
    T get(int index) {
        bool isInFirstHalf { index <= size / 2 };
        int i { isInFirstHalf ? 0 : size - 1 };
        
        Node<T>* current { isInFirstHalf ? head : tail };
        while (true)
        {
            if(i == index) break;

            if(isInFirstHalf) {
                current = current->next;
                ++i;
            } else {
                current = current->prev;
                --i;
            }

        }
        // prev instead of next because the loop will stop one after the desired node
        return current->value;
    }

    ~DoublyLinkedList(){

    }
private:
    Node<T>* head { nullptr };
    Node<T>* tail { nullptr };
    int size { 0 };
};

int main() {
    DoublyLinkedList<int> dlist{};

    for(int i { 1 }; i <= 6; ++i)
    {
        dlist.push(i);
    }

    for(int i { 0 }; i < 6; ++i) {
        std::cout << dlist.get(i);
    }

    std::cout << '\n';
    return 0;
}
