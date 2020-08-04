//
//  1013.c
//  PAT
//
//  Created by BowenLi on 2020/8/4.
//  Copyright © 2020 Bowen Li. All rights reserved.
//

#include "1013.h"
#include "1007.h"

/*
 1013 数素数 (20point(s))
 令 Pi表示第 i 个素数。
 现任给两个正整数 M≤N≤10^4，请输出 PM到PN的所有素数。

 输入格式：
 输入在一行中给出 M 和 N，其间以空格分隔。

 输出格式：
 输出从 PM 到 PN的所有素数，每 10 个数字占 1 行，
 其间以空格分隔，但行末不得有多余空格。

 输入样例：
 5 27
 
 输出样例：
 11 13 17 19 23 29 31 37 41 43
 47 53 59 61 67 71 73 79 83 89
 97 101 103
 */

void countPrime(void) {
    int i, m, n;
    scanf("%d %d", &m, &n);
    int primes[MAX];
    primeTable(primes, MAX);
    for (i = m - 1; i < n; i++) {
        printf("%d", primes[i]);
        if ((i + 1) % 10 && i + 1 < n)
            printf(" ");
        else
            printf("\n");
    }
}

void primeTable(int* p, int max) {
    int cnt = 0;
    for (int i = 2; i < max; i++) {
        if (!isPrime(i))
            p[cnt++] = i;
    }
}
