#ifdef UNICODE
#pragma comment(linker, "/entry:wWinMainCRTStartup /subsystem:console")
#endif

#include <windows.h>
#include <stdbool.h>

LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam);

bool blueRectInPinkRect = false; // 파란색 사각형이 분홍색 사각형 안에 있는지 여부

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {
    const char szClassName[] = "ColoredRectanglesWindow";

    WNDCLASSEX wc = { sizeof(WNDCLASSEX), CS_VREDRAW | CS_HREDRAW, WndProc, 0, 0, GetModuleHandle(NULL), NULL, NULL, NULL, NULL, szClassName, NULL };
    RegisterClassEx(&wc);

    HWND hwnd = CreateWindowEx(0, szClassName, "202207017이유진", WS_OVERLAPPEDWINDOW, 100, 100, 800, 600, NULL, NULL, hInstance, NULL);

    if (hwnd == NULL) {
        return 0;
    }

    ShowWindow(hwnd, nCmdShow);
    UpdateWindow(hwnd);

    MSG msg;
    while (GetMessage(&msg, NULL, 0, 0)) {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    return msg.wParam;
}

LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam) {
    static int blueRectX = 50; // 파란색 사각형의 X 좌표
    static int blueRectY = 50; // 파란색 사각형의 Y 좌표

    switch (msg) {
    case WM_CLOSE:
        PostQuitMessage(0);
        break;
    case WM_PAINT: {
        PAINTSTRUCT ps;
        HDC hdc = BeginPaint(hwnd, &ps);

        // 화면을 지우는 코드 추가
        HBRUSH whiteBrush = CreateSolidBrush(RGB(255, 255, 255)); // 흰색 (RGB 값 사용)
        RECT clientRect;
        GetClientRect(hwnd, &clientRect);
        FillRect(hdc, &clientRect, whiteBrush); // 화면을 흰색으로 채우기
        DeleteObject(whiteBrush);

        // 고정된 핑크색 사각형 그리기
        HBRUSH pinkBrush = CreateSolidBrush(RGB(255, 000, 255)); // 핑크색 (RGB 값 사용)
        RECT pinkRect = { 200, 200, 500, 500 }; // 고정된 핑크색 사각형의 위치 및 크기
        FillRect(hdc, &pinkRect, pinkBrush);
        DeleteObject(pinkBrush);

        // 파란색 사각형 그리기 (파란색 박스가 핑크색 박스보다 위에 그려짐)
        HBRUSH blueBrush = CreateSolidBrush(RGB(0, 0, 255)); // 파란색 (RGB 값 사용)
        RECT blueRect = { blueRectX, blueRectY, blueRectX + 50, blueRectY + 50 }; // 사각형 위치 및 크기
        FillRect(hdc, &blueRect, blueBrush);
        DeleteObject(blueBrush);

        // 파란색 사각형과 핑크색 사각형이 겹칠 때 "BOOM!" 문자열을 출력
        if (blueRectX + 50 > 200 && blueRectX < 500 && blueRectY + 50 > 200 && blueRectY < 500) {
            TextOut(hdc, 100, 100, "BOOM!", 5); // "BOOM!" 문자열 출력
            blueRectInPinkRect = true;
        }
        else if (blueRectInPinkRect) {
            TextOut(hdc, 100, 100, "     ", 5); // 이전에 출력한 문자열 지우기
            blueRectInPinkRect = false;
        }

        EndPaint(hwnd, &ps);
        break;
    }
    case WM_KEYDOWN: {
        switch (wParam) {
        case VK_LEFT:
            blueRectX -= 5; // 왼쪽 화살표 키를 누르면 파란색 사각형의 X 좌표를 왼쪽으로 5픽셀 이동
            break;
        case VK_RIGHT:
            blueRectX += 5; // 오른쪽 화살표 키를 누르면 파란색 사각형의 X 좌표를 오른쪽으로 5픽셀 이동
            break;
        case VK_UP:
            blueRectY -= 5; // 위쪽 화살표 키를 누르면 파란색 사각형의 Y 좌표를 위로 5픽셀 이동
            break;
        case VK_DOWN:
            blueRectY += 5; // 아래쪽 화살표 키를 누르면 파란색 사각형의 Y 좌표를 아래로 5픽셀 이동
            break;
        }
        InvalidateRect(hwnd, NULL, TRUE); // 화면 다시 그리기 요청
        break;
    }
    default:
        return DefWindowProc(hwnd, msg, wParam, lParam);
    }
    return 0;
}
