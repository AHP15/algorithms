#include <iostream>
#include <cassert>

template <typename T>
struct Node
{
    T value{};
    Node<T> *next{nullptr};
    Node<T> *prev{nullptr};
};

template <typename T>
class DoublyLinkedList
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
        head->prev = newHead;
        head = newHead;
        ++size;
    }

    T pop()
    {
        assert(size > 0);

        if (!tail)
        {
            T value{head->value};
            delete head;
            head = nullptr;
            return value;
        }

        Node<T> *oldTail = tail;
        T value{oldTail->value};

        tail = tail->prev;
        tail->next = nullptr;
        delete oldTail;
        --size;
        return value;
    }

    void shift()
    {
        if (!head)
            return;

        Node<T> *temp{head};

        head = head->next;
        head->prev = nullptr;

        --size;

        delete temp;
    }

    void insertAt(T value, int position)
    {
        if (position == 0)
        {
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
        newNext->prev = current;

        newNext->next = oldNext;
        oldNext->prev = newNext;
        ++size;
    }

    void remove(int index)
    {
        if (index == 0)
        {
            shift();
            return;
        }

        Node<T> *current{head};
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

    void reverse()
    {
        if (size <= 1)
            return;

        Node<T> *current{head};
        Node<T> *next{nullptr};
        Node<T> *prev{nullptr};

        int i{ 0 };
        while (i++ < size)
        {
            next = current->next;
            prev = current->prev;

            current->next = prev;
            current->prev = next;

            current = next;
        }

        tail = head;
        head = current;
    }

    // this method loop throughout the list from both ends
    // if index is in the first half of the list then it start looping from the start
    // otherwise it start from the end
    // this reduces the time complexity from O(n) to O(n/2)
    T get(int index)
    {
        bool isInFirstHalf{index <= size / 2};
        int i{isInFirstHalf ? 0 : size - 1};

        Node<T> *current{isInFirstHalf ? head : tail};
        while (true)
        {
            if (i == index)
                break;

            if (isInFirstHalf)
            {
                current = current->next;
                ++i;
            }
            else
            {
                current = current->prev;
                --i;
            }
        }
        // prev instead of next because the loop will stop one after the desired node
        return current->value;
    }

    int getLength() { return size; }

    ~DoublyLinkedList()
    {
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
    DoublyLinkedList<int> dlist{};

    for (int i{1}; i <= 7; ++i)
    {
        dlist.push(i);
    }

    dlist.reverse();

    for (int i{0}; i < dlist.getLength(); ++i)
    {
        std::cout << dlist.get(i);
    }

    std::cout << '\n';
    return 0;
}
