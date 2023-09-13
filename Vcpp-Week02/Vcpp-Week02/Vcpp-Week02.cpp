#include <iostream>
#include <conio.h> // getch 함수를 사용하기 위해 필요

using namespace std;

int main() {
    char input;

    cout << "배지호의 행복한 VC++과제" << endl;

    while (true) {
        cout << "command>";

        string command = "";
        
        while (true) {
            input = _getch(); // 키 입력을 받음

            if (input == 27) { // ESC 키를 누르면 프로그램 종료
                cout << "\n프로그램을 종료합니다." << endl;
                return 0;
            }
            else if (input == '\r') { // 엔터 키를 누르면 명령 실행
                break;
            }
            else {
                command += input;
                cout << input;
            }
        }
        
        if (command == "q") { //q를 입력
            cout << "\nqwer 화이팅" << endl;
        }
        else if (command == "w") { //w를 입력
            cout << "\n과제 너무 좋다" << endl;
        }
        else if (command == "e") { //e를 입력
            cout << "\n담주부턴 과제량 3배다" << endl;
        }
        else if (command == "r") { //r을 입력
            cout << "\n행복합니다." << endl;
        }
        else { //그외를 입력
            cout << "\nFatal Error: q,w,e,r중에 하나를 입력하세요." << endl;
        }
    }

    return 0;
}
