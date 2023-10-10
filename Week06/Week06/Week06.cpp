#include <windows.h>

// 윈도우 프로시저 함수
LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
    static int rect1X = 50; // 1번 사각형의 X 좌표
    static int rect1Y = 50; // 1번 사각형의 Y 좌표
    static int rect2X = 200; // 2번 사각형의 X 좌표
    static int rect2Y = 200; // 2번 사각형의 Y 좌표
    static bool isHitting = false; // 충돌 여부 플래그

    switch (uMsg) {
    case WM_KEYDOWN:
        switch (wParam) {
        case 'W':
            rect1Y -= 10; // 'W' 키 누르면 위로 이동
            break;
        case 'S':
            rect1Y += 10; // 'S' 키 누르면 아래로 이동
            break;
        case 'A':
            rect1X -= 10; // 'A' 키 누르면 왼쪽으로 이동
            break;
        case 'D':
            rect1X += 10; // 'D' 키 누르면 오른쪽으로 이동
            break;
        }

        // 충돌 검사
        if (rect1X < rect2X + 50 && rect1X + 50 > rect2X &&
            rect1Y < rect2Y + 50 && rect1Y + 50 > rect2Y) {
            isHitting = true;
        }
        else {
            isHitting = false;
        }

        // 윈도우를 다시 그림
        InvalidateRect(hwnd, NULL, TRUE);
        break;

    case WM_PAINT:
    {
        PAINTSTRUCT ps;
        HDC hdc = BeginPaint(hwnd, &ps);

        // 배경을 흰색으로 칠하기
        HBRUSH hBrush = CreateSolidBrush(RGB(255, 255, 255));
        FillRect(hdc, &ps.rcPaint, hBrush);
        DeleteObject(hBrush);

        // 1번 사각형 그리기
        Rectangle(hdc, rect1X, rect1Y, rect1X + 50, rect1Y + 50);

        // 2번 사각형 그리기
        Rectangle(hdc, rect2X, rect2Y, rect2X + 50, rect2Y + 50);

        // 충돌이 감지되면 "HIT" 텍스트 그리기
        if (isHitting) {
            TextOut(hdc, 10, 10, L"HIT", 3);
        }

        EndPaint(hwnd, &ps);
    }
    break;

    case WM_CLOSE:
        PostQuitMessage(0);
        break;
    }

    return DefWindowProc(hwnd, uMsg, wParam, lParam);
}

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {
    // 윈도우 클래스 등록
    WNDCLASS wc = { 0 };
    wc.lpfnWndProc = WindowProc;
    wc.hInstance = hInstance;
    wc.lpszClassName = L"MyWindowClass";
    RegisterClass(&wc);

    // 윈도우 생성
    HWND hwnd = CreateWindow(L"MyWindowClass", L"사각형 이동 및 충돌 감지",
        WS_OVERLAPPEDWINDOW, 100, 100, 400, 400, NULL, NULL, hInstance, NULL);

    // 윈도우 표시
    ShowWindow(hwnd, nCmdShow);

    // 메시지 루프
    MSG msg = { 0 };
    while (GetMessage(&msg, NULL, 0, 0)) {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    return 0;
}
