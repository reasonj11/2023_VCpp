#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <conio.h>
#include <string.h>  // ���ڿ� ó�� �Լ��� ����ϱ� ���� ���
#define ESC 27

int main() {
    char input[256];  // �Էµ� ���ڿ��� ������ �迭
    int c;

    printf("�������������� VC++ �ְ�,,\n\n\n");

    while (1) {
        printf("command> ");

        int i = 0;  // �Էµ� ���ڿ��� �ε��� �ʱ�ȭ
        do {
            c = _getch();  // ���� ���� �Է��� ���� _getch ���
            if (c == 27) {  // ESC Ű�� ������ ����
                return 0;
            }
            else if (c == 13) {  // ����Ű�� ������ �Է� ����
                input[i] = '\0';  // ���ڿ��� ���� ��Ÿ���� NULL ���� �߰�
                break;
            }
            else {  // �Էµ� ���ڸ� �迭�� �߰�
                input[i] = c;
                i++;
                printf("%c", c);  // �Է��� ���ڸ� ȭ�鿡 ���
            }
        } while (1);

        printf("\n");

        // �Էµ� ���ڿ��� ���Ͽ� �޽��� ���
        if (strcmp(input, "q") == 0) {
            printf("qwer ȭ����\n");
        }
        else if (strcmp(input, "w") == 0) {
            printf("���� �ʹ� ����\n");
        }
        else if (strcmp(input, "e") == 0) {
            printf("���ֺ��� ������ 3���\n");
        }
        else if (strcmp(input, "r") == 0) {
            printf("�ູ�մϴ�.\n");
        }
        else {
            printf("�ٽ� �Է��ϼ���\n");
        }
    }

    return 0;
}