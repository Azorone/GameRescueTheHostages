#pragma once
#include <random>  // �������������
int divide_and_round_up(int a, int b) {
    // ͨ������ȡ���Ĺ�ʽʵ��
    return (a + b - 1) / b;
}
int randomRange(int min, int max) {

    // ���� [min, max] ��Χ�ڵ������
    int random_number = min + std::rand() % (max - min + 1);

    return random_number;
}