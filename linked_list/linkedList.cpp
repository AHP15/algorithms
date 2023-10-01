#include <iostream>
#include <cassert>

struct Node
{
    int value{};
    Node *next{};
};

class MyLinkedList
{
public:
    void push(int value)
    {
        if (length == 0)
        {
            head->value = value;
            ++length;
            return;
        }

        Node *current{head};
        while (current->next)
        {
            current = current->next;
        }

        current->next = new Node{value};
        ++length;
    }

    void unshift(int value)
    {
        if (length == 0)
        {
            head->value = value;
            ++length;
            return;
        }

        Node *temp{new Node{value}};
        temp->next = head;

        head = temp;
        ++length;
    }

    void shift()
    {
        if (length == 0)
            return;

        Node *temp{head};

        if (head->next)
        {
            head = head->next;
        }
        else
        {
            head = new Node{};
        }

        delete temp;
        --length;
    }

    void insert(int value, int index)
    {
        assert(index < length && index >= 0);

        Node *current{head};
        int i{0};
        // index - 1 because the loop should stop before the insertion position by one
        while (i < index - 1)
        {
            current = current->next;
            ++i;
        }

        Node *oldNext{current->next};
        Node *newNext{new Node{value}};
        current->next = newNext;
        newNext->next = oldNext;

        ++length;
    }

    void remove(int index)
    {
        assert(index < length && index >= 0);

        if (length == 0)
        {
            return;
        }

        Node *current{head};
        int i{0};
        // index - 1 because the loop should stop before the insertion position by one
        while (i < index - 1)
        {
            current = current->next;
            ++i;
        }

        Node *nodeToBeRemoved{current->next};

        current->next = nodeToBeRemoved->next;

        delete nodeToBeRemoved;
        --length;
    }

    int get(int index)
    {
        assert(index < length);

        Node *current{head};
        int i{0};
        while (i < index)
        {
            current = current->next;
            ++i;
        }

        return current->value;
    }

    int getLength() { return length; }

    void reverse()
    {
        Node* current { head };
        Node* prev { nullptr };
        Node* next { nullptr };
        while (current)
        {
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }

        head = prev;
    }

    ~MyLinkedList()
    {
        while (length >= 0)
        {
            shift();
            --length;
        }
    }

private:
    Node *head{new Node{}};
    bool firstInsertion{true};
    int length{0};
};

void reverse(Node *head)
{

    if (!head->next->next)
    {
        Node *temp{ head };
        head = head->next;
        head->next = temp;
        return;
    }

    reverse(head->next);
}


// int main()
// {
//     MyLinkedList ls{};

//     ls.push(1);
//     ls.push(2);
//     ls.push(3);
//     ls.push(4);

//     for (int i{0}; i < ls.getLength(); ++i)
//     {
//         std::cout << ls.get(i) << ' ';
//     }

//     std::cout << '\n';

//     ls.reverse();

//     for (int i{0}; i < ls.getLength(); ++i)
//     {
//         std::cout << ls.get(i) << ' ';
//     }

//     std::cout << '\n';

//     return 0;
// }
