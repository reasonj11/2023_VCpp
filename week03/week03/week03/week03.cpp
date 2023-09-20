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

            if (ch == 27) { // 27은 'esc' 키의 ASCII 코드입니다.
                break; // 루프 종료
            }
        }

        if (inputBuffer.size() >= 4) {
            // 입력이 쌓였고, 패턴을 확인
            if (inputBuffer[0] == '2' && inputBuffer[1] == '3' &&
                inputBuffer[2] == '6' && inputBuffer[3] == 'a') {
                std::cout << "아도겐! =o" << std::endl;
                inputBuffer.clear(); // 입력 버퍼 비우기
            }
        }
        if (inputBuffer.size() >= 3) {
            // 입력이 쌓였고, 패턴을 확인
            if (inputBuffer[0] == '4' && inputBuffer[1] == '6' &&
                inputBuffer[2] == '+') {
                std::cout << "소닉붐! =>" << std::endl;
                inputBuffer.clear(); // 입력 버퍼 비우기
            }
        }
        if (inputBuffer.size() >= 4) {
            // 입력이 쌓였고, 패턴을 확인
            if (inputBuffer[0] == '2' && inputBuffer[1] == '3' &&
                inputBuffer[2] == '6' && inputBuffer[3] == 'p') {
                std::cout << "열화권! =o" << std::endl;
                inputBuffer.clear(); // 입력 버퍼 비우기
            }
        }
        if (inputBuffer.size() >= 4) {
            // 입력이 쌓였고, 패턴을 확인
            if (inputBuffer[0] == '2' && inputBuffer[1] == '3' &&
                inputBuffer[2] == '6' && inputBuffer[3] == '+') {
                std::cout << "질주!==3" << std::endl;
                inputBuffer.clear(); // 입력 버퍼 비우기
            }
        }
        if (inputBuffer.size() >= 5) {
            // 입력이 쌓였고, 패턴을 확인
            if (inputBuffer[0] == '4' && inputBuffer[1] == '1' &&
                inputBuffer[2] == '2' && inputBuffer[3] == '3' && inputBuffer[4] == '+') {
                std::cout << "기공권! =)" << std::endl;
                inputBuffer.clear(); // 입력 버퍼 비우기
            }
            else {
                printf("그런 기술 없어요ㅡㅡ\n");
                inputBuffer.clear();
            }
        }
        

        std::this_thread::sleep_for(std::chrono::milliseconds(300)); // 0.3초(300ms) 대기
    }

    return 0;

}
