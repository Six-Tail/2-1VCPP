#include <iostream>
#include <windows.h>
#include <vector>
#include <thread>
#include <chrono>

// 키 입력을 저장하는 벡터
std::vector<int> inputBuffer;

// 입력을 체크하고 "아도겐! =o"를 출력하는 함수
void CheckAndPrint() {
    if (inputBuffer.size() >= 3) {
        // 입력 순서가 "↓", "→", "a"인 경우
        if (inputBuffer[inputBuffer.size() - 3] == VK_DOWN &&
            inputBuffer[inputBuffer.size() - 2] == VK_RIGHT &&
            inputBuffer[inputBuffer.size() - 1] == 'A') {
            std::cout << "(↓→A):아도겐! =o" << std::endl;
        }
    }

    if (inputBuffer.size() >= 3) {
        // 입력 순서가 "→", "↓", "a"인 경우
        if (inputBuffer[inputBuffer.size() - 3] == VK_RIGHT &&
            inputBuffer[inputBuffer.size() - 2] == VK_DOWN &&
            inputBuffer[inputBuffer.size() - 1] == 'A') {
            std::cout << "(→↓A):쇼류켄! ↗↑♨ " << std::endl;
        }
    }

    if (inputBuffer.size() >= 3) {
        // 입력 순서가 "↓", "←", "D"인 경우
        if (inputBuffer[inputBuffer.size() - 3] == VK_DOWN &&
            inputBuffer[inputBuffer.size() - 2] == VK_LEFT &&
            inputBuffer[inputBuffer.size() - 1] == 'D') {
            std::cout << "(↓←D):타츠마키센뿌우갸크! " << std::endl;
        }
    }
}

// 키보드 입력을 감지하는 콜백 함수
LRESULT CALLBACK KeyboardProc(int nCode, WPARAM wParam, LPARAM lParam) {
    static HHOOK keyboardHook = NULL; // HHOOK 변수를 static으로 변경

    if (nCode >= 0) {
        if (wParam == WM_KEYDOWN) {
            KBDLLHOOKSTRUCT* kbStruct = (KBDLLHOOKSTRUCT*)lParam;
            int key = kbStruct->vkCode;

            // 입력을 버퍼에 저장
            inputBuffer.push_back(key);

            // 입력을 체크하고 출력
            CheckAndPrint();

            // 300ms 대기
            std::this_thread::sleep_for(std::chrono::milliseconds(300));
        }
    }

    // ESC 키를 누르면 프로그램 종료
    if (GetAsyncKeyState(VK_ESCAPE) & 0x8000) {
        UnhookWindowsHookEx(keyboardHook); // 후킹 해제
        exit(0); // 프로그램 종료
    }

    // 다음 후크로 전달
    return CallNextHookEx(keyboardHook, nCode, wParam, lParam);
}

int main() {
    // 후킹 변수를 main 함수 내에서 정의
    HHOOK keyboardHook = SetWindowsHookEx(WH_KEYBOARD_LL, KeyboardProc, GetModuleHandle(NULL), 0);

    if (keyboardHook == NULL) {
        std::cerr << "키보드 후킹을 설정하는 데 실패했습니다." << std::endl;
        return 1;
    }

    // 메시지 루프 시작
    MSG msg;
    while (GetMessage(&msg, NULL, 0, 0) != 0) {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    return 0;
}
