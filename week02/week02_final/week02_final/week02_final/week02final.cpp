#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <conio.h>
#include <string.h>  // 문자열 처리 함수를 사용하기 위한 헤더
#define ESC 27

int main() {
    char input[256];  // 입력된 문자열을 저장할 배열
    int c;

    printf("이은석교수님의 VC++ 최고,,\n\n\n");

    while (1) {
        printf("command> ");

        int i = 0;  // 입력된 문자열의 인덱스 초기화
        do {
            c = _getch();  // 단일 문자 입력을 위해 _getch 사용
            if (c == 27) {  // ESC 키를 누르면 종료
                return 0;
            }
            else if (c == 13) {  // 엔터키를 누르면 입력 종료
                input[i] = '\0';  // 문자열의 끝을 나타내는 NULL 문자 추가
                break;
            }
            else {  // 입력된 문자를 배열에 추가
                input[i] = c;
                i++;
                printf("%c", c);  // 입력한 문자를 화면에 출력
            }
        } while (1);

        printf("\n");

        // 입력된 문자열을 비교하여 메시지 출력
        if (strcmp(input, "q") == 0) {
            printf("qwer 화이팅\n");
        }
        else if (strcmp(input, "w") == 0) {
            printf("과제 너무 좋다\n");
        }
        else if (strcmp(input, "e") == 0) {
            printf("담주부턴 과제량 3배다\n");
        }
        else if (strcmp(input, "r") == 0) {
            printf("행복합니다.\n");
        }
        else {
            printf("다시 입력하세요\n");
        }
    }

    return 0;
}