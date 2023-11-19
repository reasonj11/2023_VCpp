#include "yuhan_stack.h"
#include <iostream>

int main() {
    y_stack myStack;

    int value;
    char choice;

    do {
        std::cout << "스택에 넣을 값을 입력하세요: ";
        std::cin >> value;
        myStack.push(value);

        std::cout << "더 값을 넣으시겠습니까? (y/n): ";
        std::cin >> choice;
    } while (choice == 'y' || choice == 'Y');

    int poppedValue;
    while (true) {
        poppedValue = myStack.pop();
        if (poppedValue == 0) {
            std::cout << "스택이 비어있습니다." << std::endl;
            break;
        }
        std::cout << "꺼낸 값: " << poppedValue << std::endl;
    }

    return 0;
}