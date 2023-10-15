#ifdef UNICODE
#pragma comment(linker, "/entry:wWinMainCRTStartup /subsystem:console")
#endif

#include <windows.h>
#include <stdbool.h>

LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam);

bool blueRectInPinkRect = false; // �Ķ��� �簢���� ��ȫ�� �簢�� �ȿ� �ִ��� ����

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {
    const char szClassName[] = "ColoredRectanglesWindow";

    WNDCLASSEX wc = { sizeof(WNDCLASSEX), CS_VREDRAW | CS_HREDRAW, WndProc, 0, 0, GetModuleHandle(NULL), NULL, NULL, NULL, NULL, szClassName, NULL };
    RegisterClassEx(&wc);

    HWND hwnd = CreateWindowEx(0, szClassName, "202207017������", WS_OVERLAPPEDWINDOW, 100, 100, 800, 600, NULL, NULL, hInstance, NULL);

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
    static int blueRectX = 50; // �Ķ��� �簢���� X ��ǥ
    static int blueRectY = 50; // �Ķ��� �簢���� Y ��ǥ

    switch (msg) {
    case WM_CLOSE:
        PostQuitMessage(0);
        break;
    case WM_PAINT: {
        PAINTSTRUCT ps;
        HDC hdc = BeginPaint(hwnd, &ps);

        // ȭ���� ����� �ڵ� �߰�
        HBRUSH whiteBrush = CreateSolidBrush(RGB(255, 255, 255)); // ��� (RGB �� ���)
        RECT clientRect;
        GetClientRect(hwnd, &clientRect);
        FillRect(hdc, &clientRect, whiteBrush); // ȭ���� ������� ä���
        DeleteObject(whiteBrush);

        // ������ ��ũ�� �簢�� �׸���
        HBRUSH pinkBrush = CreateSolidBrush(RGB(255, 000, 255)); // ��ũ�� (RGB �� ���)
        RECT pinkRect = { 200, 200, 500, 500 }; // ������ ��ũ�� �簢���� ��ġ �� ũ��
        FillRect(hdc, &pinkRect, pinkBrush);
        DeleteObject(pinkBrush);

        // �Ķ��� �簢�� �׸��� (�Ķ��� �ڽ��� ��ũ�� �ڽ����� ���� �׷���)
        HBRUSH blueBrush = CreateSolidBrush(RGB(0, 0, 255)); // �Ķ��� (RGB �� ���)
        RECT blueRect = { blueRectX, blueRectY, blueRectX + 50, blueRectY + 50 }; // �簢�� ��ġ �� ũ��
        FillRect(hdc, &blueRect, blueBrush);
        DeleteObject(blueBrush);

        // �Ķ��� �簢���� ��ũ�� �簢���� ��ĥ �� "BOOM!" ���ڿ��� ���
        if (blueRectX + 50 > 200 && blueRectX < 500 && blueRectY + 50 > 200 && blueRectY < 500) {
            TextOut(hdc, 100, 100, "BOOM!", 5); // "BOOM!" ���ڿ� ���
            blueRectInPinkRect = true;
        }
        else if (blueRectInPinkRect) {
            TextOut(hdc, 100, 100, "     ", 5); // ������ ����� ���ڿ� �����
            blueRectInPinkRect = false;
        }

        EndPaint(hwnd, &ps);
        break;
    }
    case WM_KEYDOWN: {
        switch (wParam) {
        case VK_LEFT:
            blueRectX -= 5; // ���� ȭ��ǥ Ű�� ������ �Ķ��� �簢���� X ��ǥ�� �������� 5�ȼ� �̵�
            break;
        case VK_RIGHT:
            blueRectX += 5; // ������ ȭ��ǥ Ű�� ������ �Ķ��� �簢���� X ��ǥ�� ���������� 5�ȼ� �̵�
            break;
        case VK_UP:
            blueRectY -= 5; // ���� ȭ��ǥ Ű�� ������ �Ķ��� �簢���� Y ��ǥ�� ���� 5�ȼ� �̵�
            break;
        case VK_DOWN:
            blueRectY += 5; // �Ʒ��� ȭ��ǥ Ű�� ������ �Ķ��� �簢���� Y ��ǥ�� �Ʒ��� 5�ȼ� �̵�
            break;
        }
        InvalidateRect(hwnd, NULL, TRUE); // ȭ�� �ٽ� �׸��� ��û
        break;
    }
    default:
        return DefWindowProc(hwnd, msg, wParam, lParam);
    }
    return 0;
}
