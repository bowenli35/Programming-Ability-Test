//
//  1019.c
//  PAT
//
//  Created by BowenLi on 2020/8/10.
//  Copyright © 2020 Bowen Li. All rights reserved.
//

#include "1019.h"

/*
 1019 数字黑洞 (20point(s))
 给定任一个各位数字不完全相同的 4 位正整数，
 如果我们先把 4 个数字按非递增排序，
 再按非递减排序，然后用第 1 个数字减第 2个数字，
 将得到一个新的数字。
 一直重复这样做，我们很快会停在有“数字黑洞”之称的 6174，
 这个神奇的数字也叫 Kaprekar 常数。

 例如，我们从6767开始，将得到
 7766 - 6677 = 1089
 9810 - 0189 = 9621
 9621 - 1269 = 8352
 8532 - 2358 = 6174
 7641 - 1467 = 6174
 ... ...
 现给定任意 4 位正整数，请编写程序演示到达黑洞的过程。

 输入格式：
 输入给出一个 (0,10^4) 区间内的正整数 N。

 输出格式：
 如果 N 的 4 位数字全相等，则在一行内输出 N - N = 0000；
 否则将计算的每一步在一行内输出，直到 6174 作为差出现，
 输出格式见样例。注意每个数字按 4 位数格式输出。

 输入样例 1：
 6767
 
 输出样例 1：
 7766 - 6677 = 1089
 9810 - 0189 = 9621
 9621 - 1269 = 8352
 8532 - 2358 = 6174
 
 输入样例 2：
 2222
 
 输出样例 2：
 2222 - 2222 = 0000
 */

int cmp1(const void * a, const void * b) {
    return *(int*) b - *(int*) a;
}

int cmp2(const void * a, const void * b) {
    return *(int*) a - *(int*) b;
}

void Kaprekar(void) {
    int n;
    scanf("%d", &n);
    int n1[4], n2[4], cnt = 0;
    intToArray(n, n1);
    for (int i = 1; i < 4; i++) {
        if (n1[i] == n1[0]) cnt++;
    }
    if (cnt == 3) {
        printf("%d - %d = %d\n", n, n, n);
    } else {
        while (n != 6174) {
            intToArray(n, n1);
            intToArray(n, n2);
            qsort(n1, 4, sizeof(int), cmp1);
            qsort(n2, 4, sizeof(int), cmp2);
            n = compute(n1, n2);
        }
    }
}

void intToArray(int n, int * a) {
    while (n) {
        *a = n % 10;
        n /= 10;
        a++;
    }
}

int compute(int * a1, int * a2) {
    int n1 = 0;
    int n2 = 0;
    int ans = 0;
    for (int i = 0; i < 4; i++) {
        n1 = n1 * 10 + a1[i];
        n2 = n2 * 10 + a2[i];
    }
    ans = n1 - n2;
    printf("%d - %d = %d\n", n1, n2, ans);
    return ans;
}

