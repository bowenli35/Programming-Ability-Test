//
//  1016.c
//  PAT
//
//  Created by BowenLi on 2020/8/10.
//  Copyright © 2020 Bowen Li. All rights reserved.
//

#include "1016.h"

/*
 1016 部分A+B (15point(s))
 正整数 A 的“DA为 1 位整数）部分”定义为由 A 中所有 DA组成的新整数 PA。
 例如：给定 A=3862767，DA=6，
 则 A 的“6 部分”P​A是 66，因为 A 中有 2 个 6。
 现给定 A、DA 、B、DB ，请编写程序计算 PA +PB。

 输入格式：
 输入在一行中依次给出 A、DA、B、DB，中间以空格分隔，其中 0<A,B<1010。

 输出格式：
 在一行中输出 PA+PB的值。

 输入样例 1：
 3862767 6 13530293 3
 
 输出样例 1：
 399
 
 输入样例 2：
 3862767 1 13530293 8
 
 输出样例 2：
 0
 */

void a_plus_b(void) {
    char a[max], b[max];
    int da, db;
    scanf("%s %d %s %d", a, &da, b, &db);
    int i, sum1 = 0, sum2 = 0;
    for (i = 0; a[i]; i++) {
        if (a[i] - '0' == da) {
            sum1 = (sum1 + da) * 10;
        }
    }
    for (i = 0; b[i]; i++) {
        if (b[i] - '0' == db) {
            sum2 = (sum2 + db) * 10;
        }
    }
    printf("%d\n", (sum1 + sum2) / 10);
}

