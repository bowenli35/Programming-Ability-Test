//
//  1022.c
//  PAT
//
//  Created by BowenLi on 2020/8/11.
//  Copyright © 2020 Bowen Li. All rights reserved.
//

#include "1022.h"

/*
 1022 D进制的A+B (20point(s))
 输入两个非负 10 进制整数 A 和 B ，
 输出 A+B 的 D (1<D≤10)进制数。

 输入格式：
 输入在一行中依次给出 3 个整数 A、B 和 D。

 输出格式：
 输出 A+B 的 D 进制数。

 输入样例：
 123 456 8
 
 输出样例：
 1103
 */

void D_System(void) {
    int a, b, d;
    scanf("%d %d %d", &a, &b, &d);
    int sum = a + b;
    int result[100], cnt = 0;
    while (sum) {
        result[cnt++] = sum % d;
        sum /= d;
    }
    for (int i = cnt - 1; i >= 0; i--) {
        printf("%d", result[i]);
    }
    printf("\n");
}
