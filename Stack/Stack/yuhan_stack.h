#pragma once

// ��带 ��Ÿ���� Ŭ����
class Node {
public:
    int data;
    Node* next;

    Node(int value) : data(value), next(nullptr) {}
};

// ������ ��Ÿ���� Ŭ����
class y_stack {
public:
    y_stack();
    ~y_stack();

    void push(int value);
    int pop();

private:
    Node* top;  // ������ �� ���� ����Ű�� ������
};