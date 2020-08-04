//
//  1012.c
//  PAT
//
//  Created by BowenLi on 2020/8/4.
//  Copyright © 2020 Bowen Li. All rights reserved.
//

#include "1012.h"

/*
 1012 数字分类 (20point(s))
 给定一系列正整数，请按要求对数字进行分类，并输出以下 5 个数字：

 A1 = 能被 5 整除的数字中所有偶数的和；
 A2 = 将被 5 除后余 1 的数字按给出顺序进行交错求和，即计算 n1−n2+n3−n4⋯；
 A3 = 被 5 除后余 2 的数字的个数；
 A4 = 被 5 除后余 3 的数字的平均数，精确到小数点后 1 位；
 A5 = 被 5 除后余 4 的数字中最大数字。
 
 输入格式：
 每个输入包含 1 个测试用例。
 每个测试用例先给出一个不超过 1000 的正整数 N，
 随后给出 N 个不超过 1000 的待分类的正整数。数字间以空格分隔。

 输出格式：
 对给定的 N 个正整数，按题目要求计算 A1~A5并在一行中顺序输出。
 数字间以空格分隔，但行末不得有多余空格。
 若其中某一类数字不存在，则在相应位置输出 N。
 
 输入样例 1：
 13 1 2 3 4 5 6 7 8 9 10 20 16 18
 
 输出样例 1：
 30 11 2 9.7 9
 
 输入样例 2：
 8 1 2 4 5 6 7 9 16
 
 输出样例 2：
 N 11 2 N 9
 */

void classification(void) {
    int i, n;
    scanf("%d", &n);
    int a[5] = {0};
    int cnt = 0, max = 0;
    int number, result;
    int operator = 1;
    while(n) {
        scanf("%d", &number);
        result = number % 5;
        if (!result) {
            if (number % 2 == 0)
                a[0] += number;
        } else if (result == 1) {
            if (operator) {
                a[1] += number;
                operator = 0;
            } else {
                a[1] -= number;
                operator = 1;
            }
        } else if (result == 2) {
            a[2]++;
        } else if (result == 3) {
            a[3] += number;
            cnt++;
        } else if (result == 4) {
            if (number > max)
                a[4] = number;
            else
                a[4] = max;
        }
        n--;
    }
    for (i = 0; i < 5; i++) {
        if (a[i] == 0)
            printf("%c", 'N');
        else if (i == 3)
            printf("%.1f", (float) a[i] / cnt);
        else
            printf("%d", a[i]);
        if (i + 1 < 5)
            printf(" ");
        else
            printf("\n");
    }
}
