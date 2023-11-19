#pragma once
class y_stack {
public:
    y_stack(); // 생성자
    ~y_stack(); // 소멸자

    void push(int num); // 스택에 값을 추가하는 함수
    int pop(); // 스택에서 값을 꺼내는 함수

private:
    void** data; // 스택 데이터를 담는 포인터
    int top; // 스택의 꼭대기를 나타내는 변수
};