#include "yuhanCG.h"
#include <windows.h>


bool isSpacebarPressed = false;
// DrawBonobono �Լ� ����
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

// DrawRyan �Լ� ����
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