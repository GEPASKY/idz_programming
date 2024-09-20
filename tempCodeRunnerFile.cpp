#include <iostream>

using namespace std;

// не правильно работает

// Структура для узла двусвязного списка
struct ListNode {
    int data;
    ListNode* prev;
    ListNode* next;
    ListNode(int val) : data(val), prev(nullptr), next(nullptr) {}
};

// Класс двусвязного списка
class DoublyLinkedList {
private:
    ListNode* head;
    ListNode* tail;

public:
    DoublyLinkedList() : head(nullptr), tail(nullptr) {}

    // Метод для добавления элемента в конец списка
    void append(int val) {
        ListNode* newNode = new ListNode(val);
        if (head == nullptr) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }

    // Метод для перемещения элемента на K позиций вперед
    void moveElementKPositions(ListNode* node, int k) {
        if (node == nullptr || k <= 0) {
            return;
        }
        ListNode* current = node;
        for (int i = 0; i < k && current->next != nullptr; ++i) {
            current = current->next;
        }
        // Удаление узла из текущей позиции
        if (current->next == nullptr) {
            if (current->prev != nullptr) {
                current->prev->next = current->next;
            }
            tail = current->prev;
        } else {
            if (current->prev != nullptr) {
                current->prev->next = current->next;
            } else {
                head = current->next;
            }
            current->next->prev = current->prev;
        }
        // Вставка узла после текущей позиции
        if (current->next != nullptr) {
            current->next->prev = node;
        } else {
            tail = node;
        }
        node->next = current->next;
        node->prev = current;
        current->next = node;
    }

    // Метод для возврата указателя на первый элемент списка
    ListNode* getHead() {
        return head;
    }

    // Метод для вывода указателей на первый и последний элементы списка
    void printPointers() {
        cout << "First element pointer: " << head << endl;
        cout << "Last element pointer: " << tail << endl;
    }

    void print(){
        ListNode* curr = head;
        while(curr){
            cout<<curr->data<<" ";
            curr = curr->next;
        }
        cout<<endl;
    }
};

int main() {
    // Создание и заполнение списка
    DoublyLinkedList linkedList;
    linkedList.append(1);
    linkedList.append(2);
    linkedList.append(3);
    linkedList.append(4);
    linkedList.append(5);

    linkedList.print();

    // Вывод указателей на первый и последний элементы списка до перемещения
    cout << "Before moving:" << endl;
    linkedList.printPointers();

    // Заданное число К и указатель на элемент списка
    int K = 2; // Пример
    ListNode* Pq = linkedList.getHead()->next; // Указатель на второй элемент списка

    // Перемещение элемента на К позиций вперед
    linkedList.moveElementKPositions(Pq, K);
linkedList.print();
    // Вывод указателей на первый и последний элементы списка после перемещения
    cout << "After moving:" << endl;
    linkedList.printPointers();

    return 0;
}
