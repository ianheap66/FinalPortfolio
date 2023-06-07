#include "BinarySearchTree.h"

template<class T>
    struct Node {
        T _x;
        Node *_parent;
        Node *_left;
        Node *_right;
    };
    Node _root;

public:
    void showNode(T x) {
        Node* node = find_last(x);

        if (node == nullptr) {
            std::cout << "Node not found." << std::endl;
            return;
        }


        if (node->_parent != nullptr) {
            std::cout << "Parent: " << node->_parent->_x << std::endl;
        } else {
            std::cout << "Parent: NULL" << std::endl;
        }


        if (node->_left != nullptr) {
            std::cout << "Left Child: " << node->_left->_x << std::endl;
        } else {
            std::cout << "Left Child: NULL" << std::endl;
        }


        if (node->_right != nullptr) {
            std::cout << "Right Child: " << node->_right->_x << std::endl;
        } else {
            std::cout << "Right Child: NULL" << std::endl;
        }
    }


int main() {
    BST<int> binaryTree;
    binaryTree.add(50);
    binaryTree.add(17);
    binaryTree.add(12);
    binaryTree.add(23);
    binaryTree.add(9);
    binaryTree.add(14);
    binaryTree.add(19);
    binaryTree.add(72);
    binaryTree.add(54);
    binaryTree.add(76);
    binaryTree.add(67);

    binaryTree.showNode(17);
    binaryTree.showNode(67);
    binaryTree.showNode(50);
    
    return 0;
};
