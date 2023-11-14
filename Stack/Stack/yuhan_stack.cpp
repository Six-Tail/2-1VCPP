#include "yuhan_stack.h"

y_stack::y_stack() : top(nullptr) {}

y_stack::~y_stack() {
    // ������ ������ �� ����� �Ҹ���
    while (top != nullptr) {
        Node* temp = top;
        top = top->next;
        delete temp;
    }
}

void y_stack::push(int value) {
    // ���ÿ� ���� �߰��ϸ鼭 ����
    Node* newNode = new Node(value);

    if (top == nullptr || value < top->data) {
        // ������ ����ְų� ���ο� ���� �� ���� ������ ���� ���
        newNode->next = top;
        top = newNode;
    }
    else {
        // ������ ��ȸ�ϸ鼭 �ùٸ� ��ġ�� �� ����
        Node* current = top;
        while (current->next != nullptr && value > current->next->data) {
            current = current->next;
        }
        newNode->next = current->next;
        current->next = newNode;
    }
}

int y_stack::pop() {
    // ���ÿ��� ���� ������ �Լ�
    if (top == nullptr) {
        // ������ ����ִ� ���
        return -1; // �Ǵ� �ٸ� ���� ����Ͽ� ������ ǥ���� �� ����
    }

    int poppedValue = top->data;
    Node* temp = top;
    top = top->next;
    delete temp;

    return poppedValue;
}