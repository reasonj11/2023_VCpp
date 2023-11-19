#include "yuhan_stack.h"

y_stack::y_stack() {
    data = new void* [100]; // ����: 100���� void ������ �迭 ����
    top = -1; // ������ ������� ���� �ʱ�ȭ
}

y_stack::~y_stack() {
    delete[] data; // �޸� ����
}

void y_stack::push(int num) {
    top++;
    data[top] = reinterpret_cast<void*>(num); // int�� void �����ͷ� ��ȯ�Ͽ� ���ÿ� �߰�
}

int y_stack::pop() {
    if (top == -1) {
        // ������ ������� ��
        return 0; // �� ���ÿ� ���� ��ȯ �� (Ư���� �� ���� ����)
    }
    else {
        int value = reinterpret_cast<int>(data[top]); // void �����͸� int�� ��ȯ�Ͽ� �� ������
        top--;
        return value;
    }
}