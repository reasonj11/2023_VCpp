//#include "..\Ryan\yuhanCG.h"
#include <windows.h>
#include <cmath>

LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

RECT View = { 15, 80, 800 - 8, 480 - 8 };
RECT Box = { 100, 100, 800, 500 };
void DrawBox(HDC hdc, int centerX, int centerY, int size);
void DrawCircle(HDC hdc, int centerX, int centerY, int size);
void DrawBonobono(HDC hdc, int centerX, int centerY, int size);
void DrawRyan(HDC hdc, int centerX, int centerY, int size);
void DrawCube(HDC hdc, int centerX, int centerY, int size);

bool isdrawingarea = false;
bool isDrawing = false;
bool isButton1Clicked = false;
bool isButton2Clicked = false;
bool isButton3Clicked = false;
bool isButton4Clicked = false;
bool isButton5Clicked = false;
int startX, startY, endX, endY;
int shapeSize = 0; // ����� �ʱ� ũ��
int shapeType = 0;

bool isSpacebarPressed = false;

void DrawBox(HDC hdc, int centerX, int centerY, int size) {

}
void DrawCircle(HDC hdc, int centerX, int centerY, int size) {

}
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

    int innerSize = size / 10; // ���� Ÿ���� ũ��
    int innerHalfSize = innerSize / 2;

    // ���� ���� ��ġ
    int lEyeCenterX = centerX - innerHalfSize * 10;
    int lEyeCenterY = centerY - innerSize; // ���� �߾ӿ� ��ġ

    // ������ ���� ��ġ
    int rEyeCenterX = centerX + innerHalfSize * 10;
    int rEyeCenterY = centerY - innerSize; // ���� �߾ӿ� ��ġ

    if (isSpacebarPressed) {
        // �����̽��ٰ� ���� ��� �ٸ� �� ����� �׸��ϴ�.
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
        // ���� ����� (���� �׸��� ����)

        // hLEyeBrush ��ġ�� �������� �̵�
        int lEyeCenterX = centerX - innerHalfSize * 15;
        int lEyeCenterY = centerY - innerSize; // ���� �߾ӿ� ��ġ

        HBRUSH hLEyeBrush = CreateSolidBrush(RGB(0, 0, 0)); // ������ �귯�� ����
        SelectObject(hdc, hLEyeBrush); // ���� Ÿ���� ������ �귯�÷� ����
        Ellipse(hdc, lEyeCenterX - innerHalfSize, lEyeCenterY - innerHalfSize, lEyeCenterX + innerHalfSize, lEyeCenterY + innerHalfSize);

        HBRUSH hLEyeBrush2 = CreateSolidBrush(RGB(255, 255, 255));
        SelectObject(hdc, hLEyeBrush2);
        Ellipse(hdc, lEyeCenterX - innerHalfSize / 2, lEyeCenterY - innerHalfSize / 2, lEyeCenterX + innerHalfSize / 2, lEyeCenterY + innerHalfSize / 2);

        // hREyeBrush ��ġ�� ���������� �̵�
        int rEyeCenterX = centerX + innerHalfSize * 15;
        int rEyeCenterY = centerY - innerSize; // ���� �߾ӿ� ��ġ

        HBRUSH hREyeBrush = CreateSolidBrush(RGB(0, 0, 0)); // ������ �귯�� ����
        SelectObject(hdc, hREyeBrush); // ���� Ÿ���� ������ �귯�÷� ����
        Ellipse(hdc, rEyeCenterX - innerHalfSize, rEyeCenterY - innerHalfSize, rEyeCenterX + innerHalfSize, rEyeCenterY + innerHalfSize);

        HBRUSH hREyeBrush2 = CreateSolidBrush(RGB(255, 255, 255));
        SelectObject(hdc, hREyeBrush2);
        Ellipse(hdc, rEyeCenterX - innerHalfSize / 2, rEyeCenterY - innerHalfSize / 2, rEyeCenterX + innerHalfSize / 2, rEyeCenterY + innerHalfSize / 2);

        DeleteObject(hLEyeBrush); // ����� �귯�� ����
        DeleteObject(hREyeBrush); // ����� �귯�� ����
    }
    int pinkSize = size / 3; // ��ũ�� �� ũ�� ����
    int pinkHalfSize = pinkSize / 2;

    int pinkX = centerX; // �߾����� �̵�
    int pinkY = centerY + innerSize * 5; // �Ʒ������� �̵�

    HBRUSH hPinkBrush = CreateSolidBrush(RGB(255, 150, 255)); // ��ũ�� �귯�� ����
    SelectObject(hdc, hPinkBrush);
    Ellipse(hdc, pinkX - pinkHalfSize, pinkY - pinkHalfSize, pinkX + pinkHalfSize, pinkY + pinkHalfSize);

    int whiteSize = size / 3; // ��� �� ũ�� ����
    int whiteHalfSize = whiteSize / 2;

    // �� ���� ��� ���� �̾���̱�
    int whiteX1 = centerX - whiteHalfSize; // ù ��° ��� ��
    int whiteY1 = centerY + innerSize * 3; // �Ʒ������� �̵�
    int whiteX2 = centerX + whiteHalfSize; // �� ��° ��� ��
    int whiteY2 = centerY + innerSize * 3; // �Ʒ������� �̵�

    HBRUSH hWhiteBrush = CreateSolidBrush(RGB(255, 255, 255)); // ��� �귯�� ����
    SelectObject(hdc, hWhiteBrush); // ��� �귯�÷� ����
    Ellipse(hdc, whiteX1 - whiteHalfSize, whiteY1 - whiteHalfSize, whiteX1 + whiteHalfSize, whiteY1 + whiteHalfSize);
    Ellipse(hdc, whiteX2 - whiteHalfSize, whiteY2 - whiteHalfSize, whiteX2 + whiteHalfSize, whiteY2 + whiteHalfSize);

    // �߾ӿ� ������ �� �׸���
    int blackSize = size / 8; // ������ �� ũ�� ����
    int blackHalfSize = blackSize / 2;
    int blackX = centerX; // �߾ӿ� ��ġ
    int blackY = centerY + innerSize * 3; // �߾ӿ� ��ġ

    HBRUSH hBlackBrush = CreateSolidBrush(RGB(0, 0, 0)); // ������ �귯�� ����
    SelectObject(hdc, hBlackBrush); // ������ �귯�÷� ����
    Ellipse(hdc, blackX - blackHalfSize, blackY - blackHalfSize, blackX + blackHalfSize, blackY + blackHalfSize);

    int lineLength = size / 5; // ���� ���� ����

    // ���ʿ��� �Ʒ��� ���� ��
    MoveToEx(hdc, whiteX1, whiteY1, NULL);
    LineTo(hdc, whiteX1 - 1 * lineLength, whiteY1 + lineLength);
    //���� ���� ���� ��
    MoveToEx(hdc, whiteX1, whiteY1 - 10, NULL);
    LineTo(hdc, whiteX1 - lineLength, whiteY1 - 1 * lineLength);

    // �����ʿ��� �Ʒ��� ���� ��
    MoveToEx(hdc, whiteX2, whiteY2, NULL);
    LineTo(hdc, whiteX2 + 1 * lineLength, whiteY2 + lineLength);
    //������ ���� ���� ��
    MoveToEx(hdc, whiteX2, whiteY2 - 10, NULL);
    LineTo(hdc, whiteX2 + lineLength, whiteY2 - 1 * lineLength);

    DeleteObject(hBlueBrush); // �귯�� ����
    DeleteObject(hBlackPen); // �� ����
    DeleteObject(hPinkBrush); // ����� �귯�� ����
    DeleteObject(hWhiteBrush); // ����� �귯�� ����
}
void DrawRyan(HDC hdc, int centerX, int centerY, int size) {
    int halfSize = size / 2;
    int left = centerX - halfSize;
    int top = centerY - halfSize;
    int right = centerX + halfSize;
    int bottom = centerY + halfSize;

    int innerSize = size / 20; // ���� Ÿ���� ũ��
    int innerHalfSize = innerSize / 2;
    int earSize = size / 3;
    int earHalfSize = earSize / 2;

    int LearX = left + (earSize / 2);
    int LearY = centerY - 50 - (earSize / 2);

    int RearX = right - 10 - (earSize / 2);
    int RearY = LearY;

    HBRUSH RearBrush = CreateSolidBrush(RGB(219, 154, 37));
    HPEN RearPen = CreatePen(PS_SOLID, 3, RGB(0, 0, 0));
    SelectObject(hdc, RearBrush);
    SelectObject(hdc, RearPen);
    Ellipse(hdc, RearX - earHalfSize, RearY - earHalfSize, RearX + earHalfSize, RearY + earHalfSize);

    HBRUSH LearBrush = CreateSolidBrush(RGB(219, 154, 37));
    HPEN LearPen = CreatePen(PS_SOLID, 3, RGB(0, 0, 0));
    SelectObject(hdc, LearBrush);
    SelectObject(hdc, LearPen);
    Ellipse(hdc, LearX - earHalfSize, LearY - earHalfSize, LearX + earHalfSize, LearY + earHalfSize);

    HBRUSH hYellowBrush = CreateSolidBrush(RGB(219, 154, 37));
    HPEN hYellowPen = CreatePen(PS_SOLID, 3, RGB(0, 0, 0));

    SelectObject(hdc, hYellowBrush);
    SelectObject(hdc, hYellowPen);

    Ellipse(hdc, left, top, right, bottom);

    int lEyeCenterX = centerX - innerHalfSize * 10;
    int lEyeCenterY = centerY - innerSize; // ���� �߾ӿ� ��ġ

    HBRUSH hLEyeBrush = CreateSolidBrush(RGB(0, 0, 0)); // ������ �귯�� ����
    SelectObject(hdc, hLEyeBrush); // ���� Ÿ���� ������ �귯�÷� ����
    Ellipse(hdc, lEyeCenterX - innerHalfSize, lEyeCenterY - innerHalfSize, lEyeCenterX + innerHalfSize, lEyeCenterY + innerHalfSize);

    // hREyeBrush ��ġ�� ���������� �̵�
    int rEyeCenterX = centerX + innerHalfSize * 10;
    int rEyeCenterY = centerY - innerSize; // ���� �߾ӿ� ��ġ

    HBRUSH hREyeBrush = CreateSolidBrush(RGB(0, 0, 0)); // ������ �귯�� ����
    SelectObject(hdc, hREyeBrush); // ���� Ÿ���� ������ �귯�÷� ����
    Ellipse(hdc, rEyeCenterX - innerHalfSize, rEyeCenterY - innerHalfSize, rEyeCenterX + innerHalfSize, rEyeCenterY + innerHalfSize);

    int lineLength = size / 10;
    int distanceFromEyes = innerSize + 30;

    MoveToEx(hdc, lEyeCenterX - lineLength, lEyeCenterY - distanceFromEyes, NULL);
    LineTo(hdc, lEyeCenterX + lineLength, lEyeCenterY - distanceFromEyes);

    MoveToEx(hdc, rEyeCenterX - lineLength, rEyeCenterY - distanceFromEyes, NULL);
    LineTo(hdc, rEyeCenterX + lineLength, rEyeCenterY - distanceFromEyes);

    int whiteSize = size / 8; // ��� �� ũ�� ����
    int whiteHalfSize = whiteSize / 2;

    // �� ���� ��� ���� �̾���̱�
    int whiteX1 = centerX - whiteHalfSize; // ù ��° ��� ��
    int whiteY1 = centerY + innerSize * 3; // �Ʒ������� �̵�
    int whiteX2 = centerX + whiteHalfSize; // �� ��° ��� ��
    int whiteY2 = centerY + innerSize * 3; // �Ʒ������� �̵�

    HBRUSH hWhiteBrush = CreateSolidBrush(RGB(255, 255, 255)); // ��� �귯�� ����
    HPEN hYellowPen2 = CreatePen(PS_SOLID, 1, RGB(0, 0, 0));
    SelectObject(hdc, hWhiteBrush); // ��� �귯�÷� ����
    SelectObject(hdc, hYellowPen2);
    Ellipse(hdc, whiteX1 - whiteHalfSize, whiteY1 - whiteHalfSize, whiteX1 + whiteHalfSize, whiteY1 + whiteHalfSize);
    Ellipse(hdc, whiteX2 - whiteHalfSize, whiteY2 - whiteHalfSize, whiteX2 + whiteHalfSize, whiteY2 + whiteHalfSize);

    DeleteObject(hLEyeBrush); // ����� �귯�� ����
    DeleteObject(hREyeBrush); // ����� �귯�� ����
    DeleteObject(hWhiteBrush);
    DeleteObject(hYellowBrush);
    DeleteObject(hYellowPen);
    DeleteObject(hYellowPen2);
    DeleteObject(RearBrush);
    DeleteObject(RearPen);
}
void DrawCube(HDC hdc, int centerX, int centerY, int size) {

}
// ������ ���ν���
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam) {
    HDC hdc;
    PAINTSTRUCT ps;
    switch (message) {
    case WM_CLOSE:
        PostQuitMessage(0);
        break;
    case WM_PAINT: {
        hdc = BeginPaint(hWnd, &ps);

        RECT clientRect;
        GetClientRect(hWnd, &clientRect);
        HBRUSH hBackgroundBrush = CreateSolidBrush(RGB(255, 240, 200));
        FillRect(hdc, &clientRect, hBackgroundBrush);

       // // �׵θ��� �׸��� ������ ����մϴ�.
       // RECT borderRect = { 8, 3, 800, 480 }; // �׵θ��� �׷��� ������ ���
       //
       // // �ڽ��� �׵θ��� �׸���
       HPEN hPen = CreatePen(PS_SOLID, 1, RGB(0,0,0)); // �׵θ� ���� �Ӽ� ����
       // HBRUSH hBackgroundBrush2 = CreateSolidBrush(RGB(255, 240, 200));
       // FillRect(hdc, &borderRect, hBackgroundBrush2);
       //
       // // �׵θ� �׸���
       // Rectangle(hdc, borderRect.left, borderRect.top, borderRect.right, borderRect.bottom);

        
        // �ڽ��� �׵θ��� �׸���
        HPEN drawingPen = CreatePen(PS_SOLID, 1, RGB(0, 0, 0)); // �׵θ� ���� �Ӽ� ����
        HGDIOBJ drawingPen2 = SelectObject(hdc, hPen);

        // ��ü �׵θ� �׸���
        //Rectangle(hdc, borderRect.left, borderRect.top, borderRect.right, borderRect.bottom);
        // �׵θ� �׸���
        Rectangle(hdc, View.left, View.top, View.right, View.bottom);

        if (isDrawing) {
            if (isButton1Clicked) {
                shapeType = 0; // �ڽ��׸���
                DrawBox(hdc, startX, startY, shapeSize);
            }
            else if (isButton2Clicked) {
                shapeType = 1; // ���׸���
                DrawCircle(hdc, startX, startY, shapeSize);
            }
            else if (isButton3Clicked) {
                shapeType = 2; // ���뺸�� �׸���
                GetClientRect(hWnd, &clientRect);
                int centerX = (clientRect.right + clientRect.left) / 2;
                int centerY = (clientRect.bottom + clientRect.top) / 2;
                DrawBonobono(hdc, startX, startY, shapeSize);
            }
            else if (isButton4Clicked) {
                shapeType = 3; // ���̾� �׸���
                DrawRyan(hdc, startX, startY, shapeSize);
            }
            else if (isButton5Clicked) {
                shapeType = 4; // ť�� �׸���
                DrawCube(hdc, startX, startY, shapeSize);
            }

            // ����� �� ��ü ����
            SelectObject(hdc, drawingPen2);
            //SelectObject(hdc, hOldPen);
            DeleteObject(drawingPen);
            DeleteObject(hPen);


            EndPaint(hWnd, &ps);
            return 0;
        }
        break;
    }
   
    case WM_COMMAND:
        if (isButton1Clicked || isButton2Clicked || isButton3Clicked || isButton4Clicked || isButton5Clicked) {
            isButton1Clicked = false;
            isButton2Clicked = false;
            isButton3Clicked = false;
            isButton4Clicked = false;
            isButton5Clicked = false;
            isDrawing = false;

            // �����츦 �����Ͽ� ������ �׸� �׸��� ����ϴ�.
            InvalidateRect(hWnd, NULL, FALSE);
        }
        if (LOWORD(wParam) == 3) {
            isButton1Clicked = false;
            isButton2Clicked = false;
            isButton3Clicked = true;
            isButton4Clicked = false;
            isButton5Clicked = false;
            isDrawing = false;

            InvalidateRect(hWnd, NULL, FALSE);
        
            SetFocus(NULL);
            InvalidateRect(hWnd, NULL, FALSE);
            // ���뺸�� �׸��� ��Ŀ���� ����
            SetFocus(hWnd);
            isSpacebarPressed = false;

            // View �ڽ��� �߾� ��ǥ ���
            RECT viewRect = { 15, 80, 800 - 8, 480 - 8 };
            int centerX = (viewRect.left + viewRect.right) / 2;
            int centerY = (viewRect.top + viewRect.bottom) / 2;

            // DrawBonobono �Լ��� ������ �߾ӿ� �׸�
            PAINTSTRUCT ps;
            HDC hdc = BeginPaint(hWnd, &ps);
            DrawBonobono(hdc, centerX, centerY, 150); // ������ �߾ӿ� ũ�� 100���� �׸�
            EndPaint(hWnd, &ps);
        }
        if (LOWORD(wParam) == 4) {
            SetFocus(NULL);
            isButton1Clicked = false;
            isButton2Clicked = false;
            isButton3Clicked = false;
            isButton4Clicked = true;
            isButton5Clicked = false;
            isDrawing = false;
        }

        break;

    case WM_KEYDOWN:
        if (wParam == VK_SPACE) {
            if (isButton3Clicked = true) {
                isSpacebarPressed = true;
                InvalidateRect(hWnd, NULL, FALSE);

                RECT viewRect = { 15, 80, 800 - 8, 480 - 8 };
                int centerX = (viewRect.left + viewRect.right) / 2;
                int centerY = (viewRect.top + viewRect.bottom) / 2;

                // DrawBonobono �Լ��� ȣ���Ͽ� �� ����� ����
                PAINTSTRUCT ps;
                HDC hdc = BeginPaint(hWnd, &ps);
                DrawBonobono(hdc, centerX, centerY, 150); // ������ �߾ӿ� ũ�� 100���� �׸�
                EndPaint(hWnd, &ps);
            }
        }
        break;

    case WM_KEYUP:
        if (wParam == VK_SPACE) {
            if (isButton3Clicked = true) {
                isSpacebarPressed = false; // �����̽��� ������
                InvalidateRect(hWnd, NULL, FALSE);

                RECT viewRect = { 15, 80, 800 - 8, 480 - 8 };
                int centerX = (viewRect.left + viewRect.right) / 2;
                int centerY = (viewRect.top + viewRect.bottom) / 2;

                // DrawBonobono �Լ��� ȣ���Ͽ� �� ����� ������� ����
                PAINTSTRUCT ps;
                HDC hdc = BeginPaint(hWnd, &ps);
                DrawBonobono(hdc, centerX, centerY, 150); // ������ �߾ӿ� ũ�� 100���� �׸�
                EndPaint(hWnd, &ps);
            }
        }
        break;
    case WM_LBUTTONDOWN:
        if (isButton4Clicked) {
            isDrawing = true;
            startX = LOWORD(lParam);
            startY = HIWORD(lParam);
            endX = startX;
            endY = startY;
        }
        break;
        
    case WM_MOUSEMOVE:{
        if (isDrawing) {
            endX = LOWORD(lParam);
            endY = HIWORD(lParam);
            shapeSize = static_cast<int>(sqrt(pow(endX - startX, 2) + pow(endY - startY, 2)));

            InvalidateRect(hWnd, NULL, FALSE); // ȭ�� ����
        }
        POINT pt;
        GetCursorPos(&pt); // ���� ���콺 ��ǥ ���
        ScreenToClient(hWnd, &pt); // ȭ�� ��ǥ�� Ŭ���̾�Ʈ ��ǥ�� ��ȯ

        if (PtInRect(&View, pt)) {
            // drawingArea ������ ���콺�� �ִٸ� CROSS Ŀ���� ����
            SetCursor(LoadCursor(NULL, IDC_CROSS));
        }
        else {
            // drawingArea ���� ���̶�� �⺻ ȭ��ǥ Ŀ���� ����
            SetCursor(LoadCursor(NULL, IDC_ARROW));
        }
        break;
        }
    case WM_LBUTTONUP:
        if (isDrawing) {
            isDrawing = false;

            ReleaseCapture(); // ���콺 ĸó ����
        }
        break;

    default:
        return DefWindowProc(hWnd, message, wParam, lParam);
    }
        return 0;
}



// ���α׷� ������
int main() {

    // ������ Ŭ������ ����մϴ�.
    WNDCLASS wc = { 0 };
    wc.lpfnWndProc = WndProc;
    wc.hInstance = GetModuleHandle(NULL);
    wc.lpszClassName = L"MyWindowClass";
    wc.hbrBackground = CreateSolidBrush(RGB(255, 240, 200));


    if (!RegisterClass(&wc)) {
        return 1;
    }

    HWND hWnd = CreateWindow(
        L"MyWindowClass", L"202207017������", WS_OVERLAPPEDWINDOW,
        100, 100, 820, 530, NULL, NULL, GetModuleHandle(NULL), NULL);

    if (!hWnd) {
        return 4;
    }

    // ��ư 1�� �����մϴ�.
    CreateWindow(L"BUTTON", L"Box", WS_CHILD | WS_VISIBLE, 40, 10, 130, 64, hWnd, (HMENU)1, GetModuleHandle(NULL), NULL);

    // ��ư 2�� �����մϴ�.
    CreateWindow(L"BUTTON", L"Circle", WS_CHILD | WS_VISIBLE, 190, 10, 130, 64, hWnd, (HMENU)2, GetModuleHandle(NULL), NULL);

    // ��ư 3�� �����մϴ�.
    CreateWindow(L"BUTTON", L"Bonobono", WS_CHILD | WS_VISIBLE, 340, 10, 130, 64, hWnd, (HMENU)3, GetModuleHandle(NULL), NULL);

    CreateWindow(L"BUTTON", L"Ryan", WS_CHILD | WS_VISIBLE, 490, 10, 130, 64, hWnd, (HMENU)4, GetModuleHandle(NULL), NULL);

    CreateWindow(L"BUTTON", L"Cube", WS_CHILD | WS_VISIBLE, 640, 10, 130, 64, hWnd, (HMENU)5, GetModuleHandle(NULL), NULL);


    // �����츦 ȭ�鿡 ǥ���մϴ�.
    ShowWindow(hWnd, SW_SHOWNORMAL);

    // ���� �޽��� ����
    MSG msg = { 0 };
    while (GetMessage(&msg, NULL, 0, 0)) {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    return 0;
}