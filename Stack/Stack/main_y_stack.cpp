#include "yuhan_stack.h"
#include <iostream>
using namespace std;

int main() {
    y_stack myStack;

    int n; // ����ڷκ��� �Է� ���� ���� ����
    cout << "push values: ";
    cin >> n;

    // 1���� n���� ���� ���ÿ� push
    for (int i = 1; i <= n; ++i) {
        myStack.push(i);
    }

    // ���ÿ��� ���� pop�ϸ鼭 ���
    while (true) {
        int poppedValue = myStack.pop();
        if (poppedValue == -1) {
            break;
        }
        cout << "Popped: " << poppedValue << " " << endl;
    }

    return 0;
}
