#pragma once
class y_stack {
public:
    y_stack(); // ������
    ~y_stack(); // �Ҹ���

    void push(int num); // ���ÿ� ���� �߰��ϴ� �Լ�
    int pop(); // ���ÿ��� ���� ������ �Լ�

private:
    void** data; // ���� �����͸� ��� ������
    int top; // ������ ����⸦ ��Ÿ���� ����
};