

#include <iostream>
#include <fstream>
#include <string>
using namespace std;


class LinkedList {
private:
    struct Node {
        int data;
        Node* next;

        Node(int val): data(val), next(nullptr) {};
    };

    Node* head;

public:
    LinkedList(int count): head(nullptr) {
        if (count > 0) {
            head = new Node(0);
            Node* current = head;

            for (int i = 1; i < count; ++i) {
                current->next = new Node(i);
                current = current->next;
            }
        }
    }

    LinkedList(const LinkedList& other): head(nullptr) {
        Node* current = other.head;

        while (current) {
            append(current -> data);
            current = current -> next;
        }
    }

    void display() {
        Node* current = head;

        while (current) {
            cout << current -> data << " ";
            current = current -> next;
        }

        cout << endl;
    }

    void append(int val) {
        Node* newNode = new Node(val);

        if (!head) {
            head = newNode;
        } else {
            Node* current = head;

            while (current -> next) {
                current = current -> next;
            }

            current->next = newNode;
        }
    }

    void insertAfter(int E1, int E2) {
        Node* current = head;

        while (current) {
            if (current->data == E1) {
                Node* newNode = new Node(E2);
                newNode->next = current->next;
                current->next = newNode;
                return;
            }

            current = current->next;
        }
    }

    void operator+(const pair<int, int>& elements) {
            int e1 = elements.first;
            int val = elements.second;

            Node* newNode = new Node(val);
            if (!head) {
                head = newNode;
            } else {
                Node* curr = head;
                while (curr) {
                    if (curr->data == e1) {
                        newNode->next = curr->next;
                        curr->next = newNode;
                        return;
                    }
                    curr = curr->next;
                }
                cout << "Элемент Е1 не найден, элемент не вставлен." << endl;
            }
        }

    ~LinkedList() {
        while (head) {
            Node*  temp = head;
            head = head -> next;
            delete temp;

        }
    }
};



int main(int argc, const char * argv[]) {

//    Задание 1
    
    LinkedList list(5);
    list.display();

    list.insertAfter(2, 100);
    list.display();

    LinkedList copy(list);
    copy.display();


//    Задание 2
    
    LinkedList list1(5);

    std::cout << "Список 1: ";
    list1.display();

    LinkedList list2 = list1;

    cout << "Список 2 (копия списка 1): ";
    list2.display();

    // Использование обновленной перегрузки оператора + для вставки элемента после E1
    list1 + make_pair(3, 10);

    cout << "Список 1 после вставки: ";
    list1.display();


    return 0;

}


