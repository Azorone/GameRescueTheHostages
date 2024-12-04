#pragma once
#include <random>  // 用于随机数生成
int divide_and_round_up(int a, int b) {
    // 通过向上取整的公式实现
    return (a + b - 1) / b;
}
int randomRange(int min, int max) {

    // 生成 [min, max] 范围内的随机数
    int random_number = min + std::rand() % (max - min + 1);

    return random_number;
}