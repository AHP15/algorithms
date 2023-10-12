#include <string>

template<typename T>
struct Node
{
    T value{};
    std::string name{};
    Node<T>* left{ nullptr };
    Node<T>* right{nullptr};
};

template<typename T>
class BinaryTree
{
public:
    void insertNode(){}
private:
    Node<T>* root{ nullptr };
};

int main() {
    return 0;
}
