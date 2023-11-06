#include <windows.h>

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
// ������ ���ν���
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

            // ������ �߾� ��ǥ ���
            RECT clientRect;
            GetClientRect(hWnd, &clientRect);
            int centerX = (clientRect.right + clientRect.left) / 2;
            int centerY = (clientRect.bottom + clientRect.top) / 2;

            // DrawBonobono �Լ��� ������ �߾ӿ� �׸�
            PAINTSTRUCT ps;
            HDC hdc = BeginPaint(hWnd, &ps);
            DrawBonobono(hdc, centerX, centerY, 100); // ������ �߾ӿ� ũ�� 100���� �׸�
            EndPaint(hWnd, &ps);

            // ���뺸�� �׸��� ��Ŀ���� ����
            SetFocus(hWnd);
        }
        break;

    case WM_KEYDOWN:
        if (wParam == VK_SPACE) {
            isSpacebarPressed = !isSpacebarPressed; // �����̽��� ���¸� ���

            // ������ �߾� ��ǥ ���
            RECT clientRect;
            GetClientRect(hWnd, &clientRect);
            int centerX = (clientRect.right + clientRect.left) / 2;
            int centerY = (clientRect.bottom + clientRect.top) / 2;

            // DrawBonobono �Լ��� ȣ���Ͽ� �� ����� ����
            PAINTSTRUCT ps;
            HDC hdc = BeginPaint(hWnd, &ps);
            DrawBonobono(hdc, centerX, centerY, 100); // ������ �߾ӿ� ũ�� 100���� �׸�
            EndPaint(hWnd, &ps);

        }
        break;

    case WM_KEYUP:
        if (wParam == VK_SPACE) {
            if (isSpacebarPressed) {
                isSpacebarPressed = false; // �����̽��� ������

                // ������ �߾� ��ǥ ���
                RECT clientRect;
                GetClientRect(hWnd, &clientRect);
                int centerX = (clientRect.right + clientRect.left) / 2;
                int centerY = (clientRect.bottom + clientRect.top) / 2;

                // DrawBonobono �Լ��� ȣ���Ͽ� �� ����� ������� ����
                PAINTSTRUCT ps;
                HDC hdc = BeginPaint(hWnd, &ps);
                DrawBonobono(hdc, centerX, centerY, 100); // ������ �߾ӿ� ũ�� 100���� �׸�
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
                shapeType = 0; // �ڽ��׸���
            }
            else if (isButton2Clicked) {
                shapeType = 1; // ���׸���
            }
            else if (isButton3Clicked) {
                shapeType = 2; // ���뺸�� �׸���
            }
            else if (isButton4Clicked) {
                shapeType = 3; // ���̾� �׸���
            }
            else if (isButton5Clicked) {
                shapeType = 4; // ť�� �׸���
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
        100, 100, 800, 480, NULL, NULL, GetModuleHandle(NULL), NULL);

    if (!hWnd) {
        return 4;
    }

    // ��ư 1�� �����մϴ�.
    CreateWindow(L"BUTTON", L"Box", WS_CHILD | WS_VISIBLE, 50, 50, 100, 64, hWnd, (HMENU)1, GetModuleHandle(NULL), NULL);

    // ��ư 2�� �����մϴ�.
    CreateWindow(L"BUTTON", L"Circle", WS_CHILD | WS_VISIBLE, 200, 50, 100, 64, hWnd, (HMENU)2, GetModuleHandle(NULL), NULL);

    // ��ư 3�� �����մϴ�.
    CreateWindow(L"BUTTON", L"Bonobono", WS_CHILD | WS_VISIBLE, 350, 50, 100, 64, hWnd, (HMENU)3, GetModuleHandle(NULL), NULL);

    CreateWindow(L"BUTTON", L"Ryan", WS_CHILD | WS_VISIBLE, 500, 50, 100, 64, hWnd, (HMENU)4, GetModuleHandle(NULL), NULL);

    CreateWindow(L"BUTTON", L"Cube", WS_CHILD | WS_VISIBLE, 650, 50, 100, 64, hWnd, (HMENU)5, GetModuleHandle(NULL), NULL);


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