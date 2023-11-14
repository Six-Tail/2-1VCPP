#include "yuhan_stack.h"

y_stack::y_stack() : top(nullptr) {}

y_stack::~y_stack() {
    // 스택을 해제할 때 사용할 소멸자
    while (top != nullptr) {
        Node* temp = top;
        top = top->next;
        delete temp;
    }
}

void y_stack::push(int value) {
    // 스택에 값을 추가하면서 정렬
    Node* newNode = new Node(value);

    if (top == nullptr || value < top->data) {
        // 스택이 비어있거나 새로운 값이 맨 위의 값보다 작을 경우
        newNode->next = top;
        top = newNode;
    }
    else {
        // 스택을 순회하면서 올바른 위치에 값 삽입
        Node* current = top;
        while (current->next != nullptr && value > current->next->data) {
            current = current->next;
        }
        newNode->next = current->next;
        current->next = newNode;
    }
}

int y_stack::pop() {
    // 스택에서 값을 꺼내는 함수
    if (top == nullptr) {
        // 스택이 비어있는 경우
        return -1; // 또는 다른 값을 사용하여 에러를 표시할 수 있음
    }

    int poppedValue = top->data;
    Node* temp = top;
    top = top->next;
    delete temp;

    return poppedValue;
}