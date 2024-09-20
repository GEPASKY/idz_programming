#include <iostream>
#include <algorithm>

template<typename T>
class TreeNode {
public:
    T data;
    TreeNode<T>* left;
    TreeNode<T>* right;
    TreeNode(T val) : data(val), left(nullptr), right(nullptr) {}
};

template<typename T>
class Tree {
private:
    TreeNode<T>* root;

    // Вспомогательная функция для рекурсивного добавления узла в дерево
    TreeNode<T>* addRecursive(TreeNode<T>* root, T val) {
        if (root == nullptr) {
            return new TreeNode<T>(val);
        }
        if (val < root->data) {
            root->left = addRecursive(root->left, val);
        } else if (val > root->data) {
            root->right = addRecursive(root->right, val);
        }
        return root;
    }

    // Вспомогательная функция для рекурсивного удаления узла из дерева
    TreeNode<T>* delRecursive(TreeNode<T>* root, T val) {
        if (root == nullptr) {
            return nullptr;
        }
        if (val < root->data) {
            root->left = delRecursive(root->left, val);
        } else if (val > root->data) {
            root->right = delRecursive(root->right, val);
        } else {
            if (root->left == nullptr) {
                TreeNode<T>* temp = root->right;
                delete root;
                return temp;
            } else if (root->right == nullptr) {
                TreeNode<T>* temp = root->left;
                delete root;
                return temp;
            }
            TreeNode<T>* temp = findMin(root->right);
            root->data = temp->data;
            root->right = delRecursive(root->right, temp->data);
        }
        return root;
    }

    // Вспомогательная функция для поиска минимального элемента в дереве
    TreeNode<T>* findMin(TreeNode<T>* root) {
        while (root->left != nullptr) {
            root = root->left;
        }
        return root;
    }

    // Вспомогательная функция для рекурсивного удаления поддерева
    void delSubtree(TreeNode<T>* root) {
        if (root == nullptr) {
            return;
        }
        delSubtree(root->left);
        delSubtree(root->right);
        delete root;
    }

    // Вспомогательная функция для определения высоты дерева
    int heightRecursive(TreeNode<T>* root) {
        if (root == nullptr) {
            return 0;
        }
        return 1 + std::max(heightRecursive(root->left), heightRecursive(root->right));
    }

public:
    Tree() : root(nullptr) {}

    // Метод для добавления узла в дерево
    void add(T val) {
        root = addRecursive(root, val);
    }

    // Метод для удаления узла из дерева
    void del(T val) {
        root = delRecursive(root, val);
    }

    // Метод для удаления поддерева
    void del_subt(TreeNode<T>* subtreeRoot) {
        delSubtree(subtreeRoot);
    }

    // Метод для определения высоты дерева
    int height() {
        return heightRecursive(root);
    }
};

int main() {
    // Создание объектов класса Tree для разных типов данных
    Tree<int> intTree;
    Tree<double> doubleTree;

    // Добавление элементов и демонстрация работы методов
    intTree.add(5);
    intTree.add(3);
    intTree.add(7);
    intTree.add(2);
    intTree.add(4);
    std::cout << "Height of intTree: " << intTree.height() << std::endl;

    doubleTree.add(5.5);
    doubleTree.add(3.3);
    doubleTree.add(7.7);
    doubleTree.add(2.2);
    doubleTree.add(4.4);
    std::cout << "Height of doubleTree: " << doubleTree.height() << std::endl;

    return 0;
}
