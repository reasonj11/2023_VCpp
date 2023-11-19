#include "yuhan_stack.h"

y_stack::y_stack() {
    data = new void* [100]; // 예시: 100개의 void 포인터 배열 생성
    top = -1; // 스택이 비어있을 때의 초기화
}

y_stack::~y_stack() {
    delete[] data; // 메모리 해제
}

void y_stack::push(int num) {
    top++;
    data[top] = reinterpret_cast<void*>(num); // int를 void 포인터로 변환하여 스택에 추가
}

int y_stack::pop() {
    if (top == -1) {
        // 스택이 비어있을 때
        return 0; // 빈 스택에 대한 반환 값 (특정한 값 선택 가능)
    }
    else {
        int value = reinterpret_cast<int>(data[top]); // void 포인터를 int로 변환하여 값 꺼내기
        top--;
        return value;
    }
}