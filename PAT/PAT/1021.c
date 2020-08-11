//
//  1021.c
//  PAT
//
//  Created by BowenLi on 2020/8/11.
//  Copyright © 2020 Bowen Li. All rights reserved.
//

#include "1021.h"

/*
 1021 个位数统计 (15point(s))
 给定一个 k 位整数 N，请编写程序统计每种不同的个位数字出现的次数。
 例如：给定 N=100311，则有 2 个 0，3 个 1，和 1 个 3。

 输入格式：
 每个输入包含 1 个测试用例，即一个不超过 1000 位的正整数 N。

 输出格式：
 对 N 中每一种不同的个位数字，以 D:M 的格式在一行中输出该位数字 D 及其在 N 中出现的次数 M。要求按 D 的升序输出。

 输入样例：
 100311
 
 输出样例：
 0:2
 1:3
 3:1
 */

void statistics(void) {
    char n[1001];
    int numbers[9] = {0};
    scanf("%s", n);
    int i;
    for (i = 0; n[i]; i++) {
        numbers[n[i] - '0']++;
    }
    for (i = 0; i < 9; i++) {
        if (numbers[i]) {
            printf("%d:%d\n", i, numbers[i]);
        }
    }
}
