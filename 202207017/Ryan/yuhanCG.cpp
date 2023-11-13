#include "yuhanCG.h"
#include <windows.h>


bool isSpacebarPressed = false;
// DrawBonobono 함수 정의
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

// DrawRyan 함수 정의
void DrawRyan(HDC hdc, int centerX, int centerY, int size) {
    int halfSize = size / 2;
    int left = centerX - halfSize;
    int top = centerY - halfSize;
    int right = centerX + halfSize;
    int bottom = centerY + halfSize;

    int innerSize = size / 20; // 내부 타원의 크기
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
    int lEyeCenterY = centerY - innerSize; // 수평 중앙에 위치

    HBRUSH hLEyeBrush = CreateSolidBrush(RGB(0, 0, 0)); // 검정색 브러시 생성
    SelectObject(hdc, hLEyeBrush); // 내부 타원을 검정색 브러시로 설정
    Ellipse(hdc, lEyeCenterX - innerHalfSize, lEyeCenterY - innerHalfSize, lEyeCenterX + innerHalfSize, lEyeCenterY + innerHalfSize);

    // hREyeBrush 위치를 오른쪽으로 이동
    int rEyeCenterX = centerX + innerHalfSize * 10;
    int rEyeCenterY = centerY - innerSize; // 수평 중앙에 위치

    HBRUSH hREyeBrush = CreateSolidBrush(RGB(0, 0, 0)); // 검정색 브러시 생성
    SelectObject(hdc, hREyeBrush); // 내부 타원을 검정색 브러시로 설정
    Ellipse(hdc, rEyeCenterX - innerHalfSize, rEyeCenterY - innerHalfSize, rEyeCenterX + innerHalfSize, rEyeCenterY + innerHalfSize);

    int lineLength = size / 10;
    int distanceFromEyes = innerSize + 30;

    MoveToEx(hdc, lEyeCenterX - lineLength, lEyeCenterY - distanceFromEyes, NULL);
    LineTo(hdc, lEyeCenterX + lineLength, lEyeCenterY - distanceFromEyes);

    MoveToEx(hdc, rEyeCenterX - lineLength, rEyeCenterY - distanceFromEyes, NULL);
    LineTo(hdc, rEyeCenterX + lineLength, rEyeCenterY - distanceFromEyes);

    int whiteSize = size / 8; // 흰색 원 크기 설정
    int whiteHalfSize = whiteSize / 2;

    // 두 개의 흰색 원을 이어붙이기
    int whiteX1 = centerX - whiteHalfSize; // 첫 번째 흰색 원
    int whiteY1 = centerY + innerSize * 3; // 아래쪽으로 이동
    int whiteX2 = centerX + whiteHalfSize; // 두 번째 흰색 원
    int whiteY2 = centerY + innerSize * 3; // 아래쪽으로 이동

    HBRUSH hWhiteBrush = CreateSolidBrush(RGB(255, 255, 255)); // 흰색 브러시 생성
    HPEN hYellowPen2 = CreatePen(PS_SOLID, 1, RGB(0, 0, 0));
    SelectObject(hdc, hWhiteBrush); // 흰색 브러시로 설정
    SelectObject(hdc, hYellowPen2);
    Ellipse(hdc, whiteX1 - whiteHalfSize, whiteY1 - whiteHalfSize, whiteX1 + whiteHalfSize, whiteY1 + whiteHalfSize);
    Ellipse(hdc, whiteX2 - whiteHalfSize, whiteY2 - whiteHalfSize, whiteX2 + whiteHalfSize, whiteY2 + whiteHalfSize);

    DeleteObject(hLEyeBrush); // 사용한 브러시 삭제
    DeleteObject(hREyeBrush); // 사용한 브러시 삭제
    DeleteObject(hWhiteBrush);
    DeleteObject(hYellowBrush);
    DeleteObject(hYellowPen);
    DeleteObject(hYellowPen2);
    DeleteObject(RearBrush);
    DeleteObject(RearPen);
}