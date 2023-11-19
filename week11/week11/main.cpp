#include "yuhan_stack.h"
#include <iostream>

int main() {
    y_stack myStack;

    int value;
    char choice;

    do {
        std::cout << "���ÿ� ���� ���� �Է��ϼ���: ";
        std::cin >> value;
        myStack.push(value);

        std::cout << "�� ���� �����ðڽ��ϱ�? (y/n): ";
        std::cin >> choice;
    } while (choice == 'y' || choice == 'Y');

    int poppedValue;
    while (true) {
        poppedValue = myStack.pop();
        if (poppedValue == 0) {
            std::cout << "������ ����ֽ��ϴ�." << std::endl;
            break;
        }
        std::cout << "���� ��: " << poppedValue << std::endl;
    }

    return 0;
}