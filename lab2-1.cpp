#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

class Stack {
public:
    Stack() {
        top = nullptr;
    }
    
    void push(int value) {
        Node* newNode = new Node;
        newNode->data = value;
        newNode-> next = top;
        top = newNode;
    }
    
    int pop() {
        if (isEmpty()) {
            std::cout << "Стек пуст!" << std::endl;
            return -1;
        }
        
        int value = top->data;
        Node* temp = top;
        top = top->next;
        delete temp;
        return value;
    }
    
    int peek() {
        if (isEmpty()) {
            std::cout << "Стек пуст!" << std::endl;
            return -1;
        }
        return top->data;
    }
    
    
    bool isEmpty() {
        return top == nullptr;
    }
    
private:
    Node* top;
};

void swapMinMax(Stack& stack) {
    if (stack.isEmpty()) {
        std::cout << "Стек пуст!" << std::endl;
    }
    
    int minValue = stack.peek();
    int maxValue = stack.peek();
    
    Stack tempStack;
    
    while (!stack.isEmpty()) {
        int currentValue = stack.pop();
        
        if (currentValue < minValue) {
            minValue = currentValue;
        } else if (currentValue > maxValue) {
            maxValue = currentValue;
        }
        
        tempStack.push(currentValue);
    }
    
    while(!tempStack.isEmpty()) {
        int currentValue = tempStack.pop();
        
        if (currentValue == minValue) {
            stack.push(maxValue);
        } else if (currentValue == maxValue) {
            stack.push(minValue);
        } else {
            stack.push(currentValue);
        }
    }
};

void fillStack(Stack& stack) {
    stack.push(5);
    stack.push(3);
    stack.push(1);
    stack.push(4);
    stack.push(2);
}

void outputStack(Stack& myStack) {
    while (!myStack.isEmpty()) {
        std::cout << myStack.pop() << " ";
    }
};

int main() {
    Stack myStack;
    
    fillStack(myStack);
    
    std::cout << "Изначальный стек: ";
    outputStack(myStack);
    std::cout << "" << std::endl;
    
    fillStack(myStack);
    swapMinMax(myStack);
    
    std::cout << "Стек после перетановки: ";
    outputStack(myStack);
}
