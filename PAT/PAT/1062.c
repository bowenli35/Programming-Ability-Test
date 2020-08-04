//
//  1062.c
//  PAT
//
//  Created by BowenLi on 2020/8/4.
//  Copyright © 2020 Bowen Li. All rights reserved.
//

#include "1062.h"

/*
 1062 最简分数 (20point(s))
 一个分数一般写成两个整数相除的形式：
 N/M，其中 M 不为0。
 最简分数是指分子和分母没有公约数的分数表示形式。

 现给定两个不相等的正分数 N1/M1 和 N2/M2，
 要求你按从小到大的顺序列出它们之间分母为 K 的最简分数。

 输入格式：
 输入在一行中按 N/M 的格式给出两个正分数，
 随后是一个正整数分母 K，其间以空格分隔。
 题目保证给出的所有整数都不超过 1000。

 输出格式：
 在一行中按 N/M 的格式列出两个给定分数之间分母为 K 的所有最简分数，
 按从小到大的顺序，其间以 1 个空格分隔。
 行首尾不得有多余空格。题目保证至少有 1 个输出。

 输入样例：
 7/18 13/20 12
 
 输出样例：
 5/12 7/12
 */

// 7/18
void irreducible_fraction(void) {
    int k;
    int n1, m1, n2, m2;
    scanf("%d/%d %d/%d %d", &n1, &m1, &n2, &m2, &k);
    if (n1 * m2 > n2 * m1) {
        swap(n1, n2);
        swap(m1, m2);
    }
    int n = 1;
    int flag = 0;
    while (n1 * k >= m1 * n) n++;
    while (n1 * k < m1 * n && n2 * k > m2 * n) {
        if (gcd(n, k) == 1) {
            printf("%s%d/%d", flag ? " " : "", n, k);
            flag = 1;
        }
        n++;
    }
    printf("\n");
}

// 辗转相除法
int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}

void swap(int a, int b) {
    int temp = a;
    a = b;
    b = temp;
}




