#ifdef UNICODE
#pragma comment(linker, "/entry:wWinMainCRTStartup /subsystem:console")
#else
#pragma comment(linker, "/entry:WinMainCRTStartup /subsystem:console")
#endif

#include <windows.h>

RECT drawRect = { 0 };
int isMouseLButtonPressed = 0;
POINT startMousePos; // �簢�� �׸��� ���� ����
POINT offset; // �̵��Ÿ�
HBRUSH Brush; // �귯�� �ڵ�

LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    switch (uMsg)
    {
    case WM_CREATE:
        Brush = CreateSolidBrush(RGB(255, 254, 145)); // �귯�� ����
        break;

    case WM_DESTROY:
        DeleteObject(Brush); // �귯�� ����
        PostQuitMessage(0);
        break;

    case WM_LBUTTONDOWN:
    {
        // ���콺 ���� ��ư�� ���� �� ���ο� �簢���� �׸��� ���� drawRect�� �ʱ�ȭ�մϴ�.
        drawRect.left = LOWORD(lParam);
        drawRect.top = HIWORD(lParam);
        drawRect.right = LOWORD(lParam);
        drawRect.bottom = HIWORD(lParam);

        // �׸��� ��带 �����մϴ�.
        isMouseLButtonPressed = 1;
    }
    break;

    case WM_MOUSEMOVE:
    {
        if (isMouseLButtonPressed)
        {
            // ���� ���콺 ��ġ�� ���ɴϴ�.
            int curMouseX = LOWORD(lParam);
            int curMouseY = HIWORD(lParam);

            // �簢�� ��ġ�� ������Ʈ�մϴ�.
            drawRect.right = curMouseX;
            drawRect.bottom = curMouseY;

            // ȭ���� �ٽ� �׸��ϴ�.
            InvalidateRect(hwnd, NULL, TRUE);
        }
    }
    break;

    case WM_LBUTTONUP:
    {
        // ���콺 ���� ��ư�� ���� �׸��� ��带 �����մϴ�.
        isMouseLButtonPressed = 0;
    }
    break;

    case WM_PAINT:
    {
        PAINTSTRUCT ps;
        HDC hdc = BeginPaint(hwnd, &ps);

        // ���� �簢�� ������ ���������� ĥ�� ���� �簢���� �����
        FillRect(hdc, &ps.rcPaint, (HBRUSH)(COLOR_WINDOW + 1));

        // �귯�ø� ����Ͽ� �簢�� ���� ä��
        FillRect(hdc, &drawRect, Brush);

        // �簢���� �׵θ��� ���������� �׸�
        SelectObject(hdc, GetStockObject(BLACK_PEN));
        SelectObject(hdc, GetStockObject(NULL_BRUSH));
        Rectangle(hdc, drawRect.left, drawRect.top, drawRect.right, drawRect.bottom);

        EndPaint(hwnd, &ps);
    }
    break;

    default:
        return DefWindowProc(hwnd, uMsg, wParam, lParam);
    }

    return 0;
}

#ifdef UNICODE
int WINAPI wWinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ LPWSTR lpCmdLine, _In_ int nShowCmd)
#else
int WINAPI WinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ LPSTR pCmdLine, _In_ int nCmdShow)
#endif
{
    // ������ ���� �ڵ�
    HWND hwnd;

    WNDCLASS wc;
    ZeroMemory(&wc, sizeof(wc));
    wc.hInstance = hInstance;
    wc.lpszClassName = TEXT("Computer Software");
    wc.hIcon = LoadIcon(NULL, IDI_APPLICATION);
    wc.hCursor = LoadCursor(NULL, IDC_CROSS);
    wc.style = CS_HREDRAW | CS_VREDRAW;
    wc.lpfnWndProc = WindowProc;

    if (RegisterClass(&wc) == 0)
    {
        MessageBox(NULL, L"RegisterClass failed!", L"Error", MB_ICONERROR);
        exit(-1);
    }

    // â ũ�⸦ �������� ����
    int windowWidth = 800;
    int windowHeight = 600;

    hwnd = CreateWindow(
        wc.lpszClassName,
        TEXT("202207017 ������"),
        WS_OVERLAPPEDWINDOW,
        0, 0,
        windowWidth, windowHeight, // â�� ũ�⸦ ����
        NULL, NULL,
        hInstance,
        NULL
    );

    if (hwnd == NULL)
    {
        MessageBox(NULL, L"CreateWindow failed!", L"Error", MB_ICONERROR);
        exit(-1);
    }

    ShowWindow(hwnd, SW_SHOW);
    UpdateWindow(hwnd);

    MSG msg;
    ZeroMemory(&msg, sizeof(msg)); // MSG ����ü �ʱ�ȭ

    while (GetMessage(&msg, hwnd, 0, 0)) // GetMessage �Լ��� ����Ͽ� �޽��� ���� ó��
    {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    return (int)msg.wParam;
}