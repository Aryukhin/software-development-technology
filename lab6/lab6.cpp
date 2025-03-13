#include <memory>
#include <iostream>

class Node {
public:
    int value;
    std::unique_ptr<Node> left;
    std::unique_ptr<Node> right;

    Node(int val) : value(val) {}
};

class BinaryTree {
private:
    std::unique_ptr<Node> root;

    void insertNode(std::unique_ptr<Node>& node, int value) {
        if (!node) {
            node = std::make_unique<Node>(value);
        } else if (value < node->value) {
            insertNode(node->left, value);
        } else if (value > node->value) {
            insertNode(node->right, value);
        }
    }

    std::unique_ptr<Node> removeNode(std::unique_ptr<Node>& node, int value) {
        if (!node) return nullptr;
        if (value < node->value) {
            node->left = removeNode(node->left, value);
        } else if (value > node->value) {
            node->right = removeNode(node->right, value);
        } else {
            if (!node->left) return std::move(node->right);
            if (!node->right) return std::move(node->left);
            Node* minNode = findMin(node->right.get());
            node->value = minNode->value;
            node->right = removeNode(node->right, minNode->value);
        }
        return std::move(node);
    }

    Node* findMin(Node* node) {
        while (node && node->left) {
            node = node->left.get();
        }
        return node;
    }

    void inOrderTraversal(const Node* node) const {
        if (!node) return;
        inOrderTraversal(node->left.get());
        std::cout << node->value << " ";
        inOrderTraversal(node->right.get());
    }

public:
    void insert(int value) {
        insertNode(root, value);
    }

    void remove(int value) {
        root = removeNode(root, value);
    }

    void inOrder() const {
        inOrderTraversal(root.get());
        std::cout << std::endl;
    }
};

int main() {
    BinaryTree tree;
    tree.insert(10);
    tree.insert(5);
    tree.insert(15);
    tree.insert(3);
    tree.insert(7);

    std::cout << "In-order traversal: ";
    tree.inOrder();

    tree.remove(5);
    std::cout << "After removing 5: ";
    tree.inOrder();

    return 0;
}
