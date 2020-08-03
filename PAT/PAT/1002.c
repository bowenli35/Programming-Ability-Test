//
//  1002.c
//  PAT
//
//  Created by BowenLi on 2020/8/3.
//  Copyright © 2020 Bowen Li. All rights reserved.
//

#include "1002.h"

/*
 1002 写出这个数 (20point(s))
 读入一个正整数 n，计算其各位数字之和，用汉语拼音写出和的每一位数字。

 输入格式：
 每个测试输入包含 1 个测试用例，即给出自然数 n 的值。
 这里保证 n 小于 10^100。

 输出格式：
 在一行内输出 n 的各位数字之和的每一位，拼音数字间有 1 空格，但一行中最后一个拼音数字后没有空格。

 输入样例：
 1234567890987654321123456789
 
 输出样例：
 yi san wu
 */

void write_this_number(void) {
    char n[101];
    int i, sum = 0;
    int numbers[101];
    char* const pinyin[10] = {
        "ling", "yi", "er", "san", "si",
        "wu", "liu", "qi", "ba", "jiu"
    };
    scanf("%s", n);
    for (i = 0; n[i]; i++) {
        sum += n[i] - '0';
    }
    for (i = 0; sum; i++) {
        numbers[i] = sum % 10;
        sum /= 10;
    }
    printf("%s", pinyin[numbers[i-1]]);
    for (i -= 2; i >= 0; i--) {
        printf(" %s", pinyin[numbers[i]]);
    }
    printf("\n");
}
