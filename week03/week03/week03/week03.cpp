#include <iostream>
#include <vector>
#include <chrono>
#include <thread>
#include <conio.h>
#define ESC 27

int main() {
    std::vector<char> inputBuffer;


    while (true) {
        if (_kbhit()) {
            char ch = _getch();
            inputBuffer.push_back(ch);

            if (ch == 27) { // 27�� 'esc' Ű�� ASCII �ڵ��Դϴ�.
                break; // ���� ����
            }
        }

        if (inputBuffer.size() >= 4) {
            // �Է��� �׿���, ������ Ȯ��
            if (inputBuffer[0] == '2' && inputBuffer[1] == '3' &&
                inputBuffer[2] == '6' && inputBuffer[3] == 'a') {
                std::cout << "�Ƶ���! =o" << std::endl;
                inputBuffer.clear(); // �Է� ���� ����
            }
        }
        if (inputBuffer.size() >= 3) {
            // �Է��� �׿���, ������ Ȯ��
            if (inputBuffer[0] == '4' && inputBuffer[1] == '6' &&
                inputBuffer[2] == '+') {
                std::cout << "�Ҵк�! =>" << std::endl;
                inputBuffer.clear(); // �Է� ���� ����
            }
        }
        if (inputBuffer.size() >= 4) {
            // �Է��� �׿���, ������ Ȯ��
            if (inputBuffer[0] == '2' && inputBuffer[1] == '3' &&
                inputBuffer[2] == '6' && inputBuffer[3] == 'p') {
                std::cout << "��ȭ��! =o" << std::endl;
                inputBuffer.clear(); // �Է� ���� ����
            }
        }
        if (inputBuffer.size() >= 4) {
            // �Է��� �׿���, ������ Ȯ��
            if (inputBuffer[0] == '2' && inputBuffer[1] == '3' &&
                inputBuffer[2] == '6' && inputBuffer[3] == '+') {
                std::cout << "����!==3" << std::endl;
                inputBuffer.clear(); // �Է� ���� ����
            }
        }
        if (inputBuffer.size() >= 5) {
            // �Է��� �׿���, ������ Ȯ��
            if (inputBuffer[0] == '4' && inputBuffer[1] == '1' &&
                inputBuffer[2] == '2' && inputBuffer[3] == '3' && inputBuffer[4] == '+') {
                std::cout << "�����! =)" << std::endl;
                inputBuffer.clear(); // �Է� ���� ����
            }
            else {
                printf("�׷� ��� �����Ѥ�\n");
                inputBuffer.clear();
            }
        }
        

        std::this_thread::sleep_for(std::chrono::milliseconds(300)); // 0.3��(300ms) ���
    }

    return 0;

}
