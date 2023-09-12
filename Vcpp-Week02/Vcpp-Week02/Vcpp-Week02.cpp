#include <iostream>
#include <conio.h>

using namespace std;

int main()
{
    cout << "배지호의 행복한 VC++과제" << endl; //스플래시 이미지 출력

    char command = 0; //초기 커맨드값은 0

    while (true) {
        cout << "command>" << command; //커맨드 입력 및 커서 출력

        char input = _getch(); //키 입력 받기

        switch (input) { //입력된 키값에 따라 프로그램 실행

        case 'q': //q: qwer 화이팅
            cout << "qwer 화이팅" << endl;
            break;

        case 'w': //w: 과제 너무 좋다
            cout << "과제 너무 좋다" << endl;
            break;

        case 'e': //e: 담주부턴 과제량 3배다
            cout << "담주부턴 과제량 3배다" << endl;
            break;

        case 'r': //r: 행복합니다.
            cout << "행복합니다." << endl;
            break;

        case 27: //ESC키를 누르면 즉시 프로그램이 종료하도록 만든다. (ESC키의 아스키코드는 27)
            return 0; //프로그램 종료

        default: //다른 글자를 입력하면 오류메시지와 함께 다시 입력하도록 안내한다.
            cout << "\n오류: 잘못된 문자입니다. q,w,e,r중에 하나를 입력하세요." << endl;
        }
    }
    return 0;
}


