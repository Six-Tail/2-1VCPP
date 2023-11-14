#include "yuhan_stack.h"
#include <iostream>
using namespace std;

int main() {
    y_stack myStack;

    int n; // 사용자로부터 입력 받을 값의 개수
    cout << "push values: ";
    cin >> n;

    // 1부터 n까지 값을 스택에 push
    for (int i = 1; i <= n; ++i) {
        myStack.push(i);
    }

    // 스택에서 값을 pop하면서 출력
    while (true) {
        int poppedValue = myStack.pop();
        if (poppedValue == -1) {
            break;
        }
        cout << "Popped: " << poppedValue << " " << endl;
    }

    return 0;
}
