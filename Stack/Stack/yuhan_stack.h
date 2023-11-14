#pragma once

// 노드를 나타내는 클래스
class Node {
public:
    int data;
    Node* next;

    Node(int value) : data(value), next(nullptr) {}
};

// 스택을 나타내는 클래스
class y_stack {
public:
    y_stack();
    ~y_stack();

    void push(int value);
    int pop();

private:
    Node* top;  // 스택의 맨 위를 가리키는 포인터
};