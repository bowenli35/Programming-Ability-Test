//
//  1007.c
//  PAT
//
//  Created by BowenLi on 2020/8/3.
//  Copyright © 2020 Bowen Li. All rights reserved.
//

#include "1007.h"

/*
 1007 素数对猜想 (20point(s))
 让我们定义dn为：dn=pn+1−pn，其中pi是第i个素数。
 显然有d1=1，且对于n>1有dn是偶数。“素数对猜想”认为“存在无穷多对相邻且差为2的素数”。

 现给定任意正整数N(<10^5)，请计算不超过N的满足猜想的素数对的个数。

 输入格式:
 输入在一行给出正整数N。

 输出格式:
 在一行中输出不超过N的满足猜想的素数对的个数。

 输入样例:
 20
 
 输出样例:
 4
 */

void primePair(void) {
    int i, n, k = 1, cnt = 0;
    scanf("%d", &n);
    int primes[MAX] = {2};
    for (i = 3; i <= n; i++) {
        if (!isPrime(i)) {
            primes[k++] = i;
        }
    }
    for (i = 0; i < k; i++) {
        if (primes[i+1] - primes[i] == 2) {
            cnt++;
        }
    }
    printf("%d\n", cnt);
}

int isPrime(int n) {
    int prime = 0;
    if (n <= 1) {
        prime = 0;
    } else {
        for (int i = 2; i <= sqrt(n); i++) {
            if (n % i == 0) {
                prime = 1;
                break;
            }
        }
    }
    return prime;
}
