#ifdef UNICODE
#pragma comment(linker, "/entry:wWinMainCRTStartup /subsystem:console")
#else
#pragma comment(linker, "/entry:WinMainCRTStartup /subsystem:console")
#endif

#include <windows.h>

RECT drawRect = { 0 };
int isMouseLButtonPressed = 0;
POINT startMousePos; // 사각형 그리기 시작 지점
POINT offset; // 이동거리
HBRUSH Brush; // 브러시 핸들

LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    switch (uMsg)
    {
    case WM_CREATE:
        Brush = CreateSolidBrush(RGB(255, 254, 145)); // 브러시 생성
        break;

    case WM_DESTROY:
        DeleteObject(Brush); // 브러시 삭제
        PostQuitMessage(0);
        break;

    case WM_LBUTTONDOWN:
    {
        // 마우스 왼쪽 버튼이 눌릴 때 새로운 사각형을 그리기 위해 drawRect를 초기화합니다.
        drawRect.left = LOWORD(lParam);
        drawRect.top = HIWORD(lParam);
        drawRect.right = LOWORD(lParam);
        drawRect.bottom = HIWORD(lParam);

        // 그리기 모드를 시작합니다.
        isMouseLButtonPressed = 1;
    }
    break;

    case WM_MOUSEMOVE:
    {
        if (isMouseLButtonPressed)
        {
            // 현재 마우스 위치를 얻어옵니다.
            int curMouseX = LOWORD(lParam);
            int curMouseY = HIWORD(lParam);

            // 사각형 위치를 업데이트합니다.
            drawRect.right = curMouseX;
            drawRect.bottom = curMouseY;

            // 화면을 다시 그립니다.
            InvalidateRect(hwnd, NULL, TRUE);
        }
    }
    break;

    case WM_LBUTTONUP:
    {
        // 마우스 왼쪽 버튼을 떼면 그리기 모드를 종료합니다.
        isMouseLButtonPressed = 0;
    }
    break;

    case WM_PAINT:
    {
        PAINTSTRUCT ps;
        HDC hdc = BeginPaint(hwnd, &ps);

        // 현재 사각형 영역을 검은색으로 칠해 이전 사각형을 지우기
        FillRect(hdc, &ps.rcPaint, (HBRUSH)(COLOR_WINDOW + 1));

        // 브러시를 사용하여 사각형 안을 채움
        FillRect(hdc, &drawRect, Brush);

        // 사각형의 테두리를 검은색으로 그림
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
    // 윈도우 생성 코드
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

    // 창 크기를 고정으로 설정
    int windowWidth = 800;
    int windowHeight = 600;

    hwnd = CreateWindow(
        wc.lpszClassName,
        TEXT("202207017 이유진"),
        WS_OVERLAPPEDWINDOW,
        0, 0,
        windowWidth, windowHeight, // 창의 크기를 고정
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
    ZeroMemory(&msg, sizeof(msg)); // MSG 구조체 초기화

    while (GetMessage(&msg, hwnd, 0, 0)) // GetMessage 함수를 사용하여 메시지 루프 처리
    {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    return (int)msg.wParam;
}