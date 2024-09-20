#include <iostream>
using namespace std;

// Структура для узла бинарного дерева
struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int val) : data(val), left(nullptr), right(nullptr) {}
};

// Класс бинарного дерева
class BinaryTree {
private:
    TreeNode* root;

    TreeNode* insertRecursive(TreeNode* root, int val) {
        if (root == nullptr) {
            return new TreeNode(val);
        }
        if (val < root->data) {
            root->left = insertRecursive(root->left, val);
        } else if (val > root->data) {
            root->right = insertRecursive(root->right, val);
        }
        return root;
    }

    TreeNode* deleteRecursive(TreeNode* root, int val) {
        if (root == nullptr) {
            return nullptr;
        }
        if (val < root->data) {
            root->left = deleteRecursive(root->left, val);
        } else if (val > root->data) {
            root->right = deleteRecursive(root->right, val);
        } else {
            if (root->left == nullptr) {
                TreeNode* temp = root->right;
                delete root;
                return temp;
            } else if (root->right == nullptr) {
                TreeNode* temp = root->left;
                delete root;
                return temp;
            }
            TreeNode* temp = findMin(root->right);
            root->data = temp->data;
            root->right = deleteRecursive(root->right, temp->data);
        }
        return root;
    }

    TreeNode* findMin(TreeNode* root) {
        while (root->left != nullptr) {
            root = root->left;
        }
        return root;
    }

    void printInOrder(TreeNode* root) {
        if (root != nullptr) {
            printInOrder(root->left);
            cout << root->data << " ";
            printInOrder(root->right);
        }
    }

public:
    BinaryTree() : root(nullptr) {}

    void insert(int val) {
        root = insertRecursive(root, val);
    }

    void remove(int val) {
        root = deleteRecursive(root, val);
    }

    void print() {
        printInOrder(root);
        cout << endl;
    }
};

// Структура для узла односвязного списка
struct ListNode {
    int data;
    ListNode* next;
    ListNode(int val) : data(val), next(nullptr) {}
};

// Класс односвязного списка
class LinkedList {
private:
    ListNode* head;

public:
    LinkedList() : head(nullptr) {}

    void add(int val) {
        ListNode* newNode = new ListNode(val);
        newNode->next = head;
        head = newNode;
    }

    bool search(int val) {
        ListNode* current = head;
        while (current != nullptr) {
            if (current->data == val) {
                return true;
            }
            current = current->next;
        }
        return false;
    }

    void remove(int val) {
        if (head == nullptr) {
            return;
        }
        if (head->data == val) {
            ListNode* temp = head;
            head = head->next;
            delete temp;
            return;
        }
        ListNode* current = head;
        while (current->next != nullptr) {
            if (current->next->data == val) {
                ListNode* temp = current->next;
                current->next = current->next->next;
                delete temp;
                return;
            }
            current = current->next;
        }
    }

    void print() {
        ListNode* current = head;
        while (current != nullptr) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }
};

// Класс очереди
class Queue {
private:
    ListNode* front;
    ListNode* rear;

public:
    Queue() : front(nullptr), rear(nullptr) {}

    void enqueue(int val) {
        ListNode* newNode = new ListNode(val);
        if (front == nullptr) {
            front = rear = newNode;
        } else {
            rear->next = newNode;
            rear = newNode;
        }
    }

    void dequeue() {
        if (front == nullptr) {
            cout << "Queue is empty" << endl;
            return;
        }
        ListNode* temp = front;
        front = front->next;
        if (front == nullptr) {
            rear = nullptr;
        }
        cout << "Dequeued: " << temp->data << endl; // Вывод удаляемого элемента
        delete temp;
    }

    void print() {
        ListNode* current = front;
        while (current != nullptr) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }

    static Queue mergeQueues(Queue& q1, Queue& q2) {
        Queue mergedQueue;
        ListNode* current1 = q1.front;
        ListNode* current2 = q2.front;
        while (current1 != nullptr || current2 != nullptr) {
            if (current1 != nullptr) {
                mergedQueue.enqueue(current1->data);
                current1 = current1->next;
            }
            if (current2 != nullptr) {
                mergedQueue.enqueue(current2->data);
                current2 = current2->next;
            }
        }
        return mergedQueue;
    }

    void printPointers() {
        cout << "Front pointer: " << front << endl;
        cout << "Rear pointer: " << rear << endl;
    }
};

int main() {
    Queue queue1;
    queue1.enqueue(1);
    queue1.enqueue(3);
    queue1.enqueue(5);

    Queue queue2;
    queue2.enqueue(2);
    queue2.enqueue(4);
    queue2.enqueue(6);

    cout << "Queue 1: ";
    queue1.print();
    cout << "Queue 2: ";
    queue2.print();

    queue2.dequeue();

    Queue mergedQueue = Queue::mergeQueues(queue1, queue2);

    cout << "Merged Queue: ";
    mergedQueue.print();

    mergedQueue.printPointers();

    return 0;
}
