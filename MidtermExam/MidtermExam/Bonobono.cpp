#include <windows.h>

bool isDrawing = false;
bool isButton1Clicked = false;
bool isButton2Clicked = false;
bool isButton3Clicked = false;
bool isButton4Clicked = false;
bool isButton5Clicked = false;
int startX, startY, endX, endY;
int shapeSize = 0; // 모양의 초기 크기
int shapeType = 0;

bool isSpacebarPressed = false;


void DrawBonobono(HDC hdc, int centerX, int centerY, int size) {
    int halfSize = size / 1;
    int left = centerX - halfSize;
    int top = centerY - halfSize;
    int right = centerX + halfSize;
    int bottom = centerY + halfSize;

    HBRUSH hBlueBrush = CreateSolidBrush(RGB(127, 200, 255));
    HPEN hBlackPen = CreatePen(PS_SOLID, 1, RGB(0, 0, 0));

    SelectObject(hdc, hBlueBrush);
    SelectObject(hdc, hBlackPen);

    Ellipse(hdc, left, top, right, bottom);

    int innerSize = size / 10; // 내부 타원의 크기
    int innerHalfSize = innerSize / 2;

    // 왼쪽 눈의 위치
    int lEyeCenterX = centerX - innerHalfSize * 10;
    int lEyeCenterY = centerY - innerSize; // 수평 중앙에 위치

    // 오른쪽 눈의 위치
    int rEyeCenterX = centerX + innerHalfSize * 10;
    int rEyeCenterY = centerY - innerSize; // 수평 중앙에 위치

    if (isSpacebarPressed) {
        // 스페이스바가 눌린 경우 다른 눈 모양을 그립니다.
        int lineLength = size / 5;

        MoveToEx(hdc, rEyeCenterX + innerHalfSize, rEyeCenterY, NULL);
        LineTo(hdc, rEyeCenterX + innerHalfSize + lineLength, rEyeCenterY + lineLength);

        MoveToEx(hdc, rEyeCenterX + innerHalfSize, rEyeCenterY, NULL);
        LineTo(hdc, rEyeCenterX + innerHalfSize + lineLength, rEyeCenterY - lineLength);

        MoveToEx(hdc, lEyeCenterX - innerHalfSize, lEyeCenterY, NULL);
        LineTo(hdc, lEyeCenterX - innerHalfSize - lineLength, lEyeCenterY + lineLength);

        MoveToEx(hdc, lEyeCenterX - innerHalfSize, lEyeCenterY, NULL);
        LineTo(hdc, lEyeCenterX - innerHalfSize - lineLength, lEyeCenterY - lineLength);
    }
    else {
        // 눈을 지우기 (선을 그리지 않음)

        // hLEyeBrush 위치를 왼쪽으로 이동
        int lEyeCenterX = centerX - innerHalfSize * 15;
        int lEyeCenterY = centerY - innerSize; // 수평 중앙에 위치

        HBRUSH hLEyeBrush = CreateSolidBrush(RGB(0, 0, 0)); // 검정색 브러시 생성
        SelectObject(hdc, hLEyeBrush); // 내부 타원을 검정색 브러시로 설정
        Ellipse(hdc, lEyeCenterX - innerHalfSize, lEyeCenterY - innerHalfSize, lEyeCenterX + innerHalfSize, lEyeCenterY + innerHalfSize);

        HBRUSH hLEyeBrush2 = CreateSolidBrush(RGB(255, 255, 255));
        SelectObject(hdc, hLEyeBrush2);
        Ellipse(hdc, lEyeCenterX - innerHalfSize / 2, lEyeCenterY - innerHalfSize / 2, lEyeCenterX + innerHalfSize / 2, lEyeCenterY + innerHalfSize / 2);

        // hREyeBrush 위치를 오른쪽으로 이동
        int rEyeCenterX = centerX + innerHalfSize * 15;
        int rEyeCenterY = centerY - innerSize; // 수평 중앙에 위치

        HBRUSH hREyeBrush = CreateSolidBrush(RGB(0, 0, 0)); // 검정색 브러시 생성
        SelectObject(hdc, hREyeBrush); // 내부 타원을 검정색 브러시로 설정
        Ellipse(hdc, rEyeCenterX - innerHalfSize, rEyeCenterY - innerHalfSize, rEyeCenterX + innerHalfSize, rEyeCenterY + innerHalfSize);

        HBRUSH hREyeBrush2 = CreateSolidBrush(RGB(255, 255, 255));
        SelectObject(hdc, hREyeBrush2);
        Ellipse(hdc, rEyeCenterX - innerHalfSize / 2, rEyeCenterY - innerHalfSize / 2, rEyeCenterX + innerHalfSize / 2, rEyeCenterY + innerHalfSize / 2);

        DeleteObject(hLEyeBrush); // 사용한 브러시 삭제
        DeleteObject(hREyeBrush); // 사용한 브러시 삭제
    }
    int pinkSize = size / 3; // 핑크색 원 크기 설정
    int pinkHalfSize = pinkSize / 2;

    int pinkX = centerX; // 중앙으로 이동
    int pinkY = centerY + innerSize * 5; // 아래쪽으로 이동

    HBRUSH hPinkBrush = CreateSolidBrush(RGB(255, 150, 255)); // 핑크색 브러시 생성
    SelectObject(hdc, hPinkBrush);
    Ellipse(hdc, pinkX - pinkHalfSize, pinkY - pinkHalfSize, pinkX + pinkHalfSize, pinkY + pinkHalfSize);

    int whiteSize = size / 3; // 흰색 원 크기 설정
    int whiteHalfSize = whiteSize / 2;

    // 두 개의 흰색 원을 이어붙이기
    int whiteX1 = centerX - whiteHalfSize; // 첫 번째 흰색 원
    int whiteY1 = centerY + innerSize * 3; // 아래쪽으로 이동
    int whiteX2 = centerX + whiteHalfSize; // 두 번째 흰색 원
    int whiteY2 = centerY + innerSize * 3; // 아래쪽으로 이동

    HBRUSH hWhiteBrush = CreateSolidBrush(RGB(255, 255, 255)); // 흰색 브러시 생성
    SelectObject(hdc, hWhiteBrush); // 흰색 브러시로 설정
    Ellipse(hdc, whiteX1 - whiteHalfSize, whiteY1 - whiteHalfSize, whiteX1 + whiteHalfSize, whiteY1 + whiteHalfSize);
    Ellipse(hdc, whiteX2 - whiteHalfSize, whiteY2 - whiteHalfSize, whiteX2 + whiteHalfSize, whiteY2 + whiteHalfSize);

    // 중앙에 검은색 원 그리기
    int blackSize = size / 8; // 검은색 원 크기 설정
    int blackHalfSize = blackSize / 2;
    int blackX = centerX; // 중앙에 위치
    int blackY = centerY + innerSize * 3; // 중앙에 위치

    HBRUSH hBlackBrush = CreateSolidBrush(RGB(0, 0, 0)); // 검정색 브러시 생성
    SelectObject(hdc, hBlackBrush); // 검정색 브러시로 설정
    Ellipse(hdc, blackX - blackHalfSize, blackY - blackHalfSize, blackX + blackHalfSize, blackY + blackHalfSize);

    int lineLength = size / 5; // 선의 길이 설정

    // 왼쪽에서 아래로 가는 선
    MoveToEx(hdc, whiteX1, whiteY1, NULL);
    LineTo(hdc, whiteX1 - 1 * lineLength, whiteY1 + lineLength);
    //왼쪽 위로 가는 선
    MoveToEx(hdc, whiteX1, whiteY1 - 10, NULL);
    LineTo(hdc, whiteX1 - lineLength, whiteY1 - 1 * lineLength);

    // 오른쪽에서 아래로 가는 선
    MoveToEx(hdc, whiteX2, whiteY2, NULL);
    LineTo(hdc, whiteX2 + 1 * lineLength, whiteY2 + lineLength);
    //오른쪽 위로 가는 선
    MoveToEx(hdc, whiteX2, whiteY2 - 10, NULL);
    LineTo(hdc, whiteX2 + lineLength, whiteY2 - 1 * lineLength);

    DeleteObject(hBlueBrush); // 브러시 삭제
    DeleteObject(hBlackPen); // 펜 삭제
    DeleteObject(hPinkBrush); // 사용한 브러시 삭제
    DeleteObject(hWhiteBrush); // 사용한 브러시 삭제
}
// 윈도우 프로시저
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam) {
    HDC hdc;
    PAINTSTRUCT ps;
    switch (message) {
    case WM_CLOSE:
        PostQuitMessage(0);
        break;

    case WM_COMMAND:
        if (LOWORD(wParam) == 3) {

            isButton3Clicked = true;
            InvalidateRect(hWnd, NULL, TRUE);

            // 윈도우 중앙 좌표 계산
            RECT clientRect;
            GetClientRect(hWnd, &clientRect);
            int centerX = (clientRect.right + clientRect.left) / 2;
            int centerY = (clientRect.bottom + clientRect.top) / 2;

            // DrawBonobono 함수를 윈도우 중앙에 그림
            PAINTSTRUCT ps;
            HDC hdc = BeginPaint(hWnd, &ps);
            DrawBonobono(hdc, centerX, centerY, 100); // 윈도우 중앙에 크기 100으로 그림
            EndPaint(hWnd, &ps);

            // 보노보노 그림에 포커스를 설정
            SetFocus(hWnd);
        }
        break;

    case WM_KEYDOWN:
        if (wParam == VK_SPACE) {
            isSpacebarPressed = !isSpacebarPressed; // 스페이스바 상태를 토글

            // 윈도우 중앙 좌표 계산
            RECT clientRect;
            GetClientRect(hWnd, &clientRect);
            int centerX = (clientRect.right + clientRect.left) / 2;
            int centerY = (clientRect.bottom + clientRect.top) / 2;

            // DrawBonobono 함수를 호출하여 눈 모양을 변경
            PAINTSTRUCT ps;
            HDC hdc = BeginPaint(hWnd, &ps);
            DrawBonobono(hdc, centerX, centerY, 100); // 윈도우 중앙에 크기 100으로 그림
            EndPaint(hWnd, &ps);

        }
        break;

    case WM_KEYUP:
        if (wParam == VK_SPACE) {
            if (isSpacebarPressed) {
                isSpacebarPressed = false; // 스페이스바 떼어짐

                // 윈도우 중앙 좌표 계산
                RECT clientRect;
                GetClientRect(hWnd, &clientRect);
                int centerX = (clientRect.right + clientRect.left) / 2;
                int centerY = (clientRect.bottom + clientRect.top) / 2;

                // DrawBonobono 함수를 호출하여 눈 모양을 원래대로 변경
                PAINTSTRUCT ps;
                HDC hdc = BeginPaint(hWnd, &ps);
                DrawBonobono(hdc, centerX, centerY, 100); // 윈도우 중앙에 크기 100으로 그림
                EndPaint(hWnd, &ps);
            }
        }
        break;
    case WM_PAINT: {
        hdc = BeginPaint(hWnd, &ps);

        RECT clientRect;
        GetClientRect(hWnd, &clientRect);
        HBRUSH hBackgroundBrush = CreateSolidBrush(RGB(255, 240, 200));
        FillRect(hdc, &clientRect, hBackgroundBrush);

        if (isDrawing) {
            if (isButton1Clicked) {
                shapeType = 0; // 박스그리기
            }
            else if (isButton2Clicked) {
                shapeType = 1; // 원그리기
            }
            else if (isButton3Clicked) {
                shapeType = 2; // 보노보노 그리기
            }
            else if (isButton4Clicked) {
                shapeType = 3; // 라이언 그리기
            }
            else if (isButton5Clicked) {
                shapeType = 4; // 큐브 그리기
            }
            EndPaint(hWnd, &ps);
            break;
        }
    }
    default:
        return DefWindowProc(hWnd, message, wParam, lParam);
    }
    return 0;
}



// 프로그램 진입점
int main() {

    // 윈도우 클래스를 등록합니다.
    WNDCLASS wc = { 0 };
    wc.lpfnWndProc = WndProc;
    wc.hInstance = GetModuleHandle(NULL);
    wc.lpszClassName = L"MyWindowClass";
    wc.hbrBackground = CreateSolidBrush(RGB(255, 240, 200));


    if (!RegisterClass(&wc)) {
        return 1;
    }

    HWND hWnd = CreateWindow(
        L"MyWindowClass", L"202207017이유진", WS_OVERLAPPEDWINDOW,
        100, 100, 800, 480, NULL, NULL, GetModuleHandle(NULL), NULL);

    if (!hWnd) {
        return 4;
    }

    // 버튼 1을 생성합니다.
    CreateWindow(L"BUTTON", L"Box", WS_CHILD | WS_VISIBLE, 50, 50, 100, 64, hWnd, (HMENU)1, GetModuleHandle(NULL), NULL);

    // 버튼 2을 생성합니다.
    CreateWindow(L"BUTTON", L"Circle", WS_CHILD | WS_VISIBLE, 200, 50, 100, 64, hWnd, (HMENU)2, GetModuleHandle(NULL), NULL);

    // 버튼 3을 생성합니다.
    CreateWindow(L"BUTTON", L"Bonobono", WS_CHILD | WS_VISIBLE, 350, 50, 100, 64, hWnd, (HMENU)3, GetModuleHandle(NULL), NULL);

    CreateWindow(L"BUTTON", L"Ryan", WS_CHILD | WS_VISIBLE, 500, 50, 100, 64, hWnd, (HMENU)4, GetModuleHandle(NULL), NULL);

    CreateWindow(L"BUTTON", L"Cube", WS_CHILD | WS_VISIBLE, 650, 50, 100, 64, hWnd, (HMENU)5, GetModuleHandle(NULL), NULL);


    // 윈도우를 화면에 표시합니다.
    ShowWindow(hWnd, SW_SHOWNORMAL);

    // 메인 메시지 루프
    MSG msg = { 0 };
    while (GetMessage(&msg, NULL, 0, 0)) {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    return 0;
}