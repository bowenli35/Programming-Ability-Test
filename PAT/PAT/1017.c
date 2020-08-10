//
//  1017.c
//  PAT
//
//  Created by BowenLi on 2020/8/10.
//  Copyright © 2020 Bowen Li. All rights reserved.
//

#include "1017.h"

/*
 1017 A除以B (20point(s))
 本题要求计算 A/B，其中 A 是不超过 1000 位的正整数，B 是 1 位正整数。
 你需要输出商数 Q 和余数 R，使得 A=B×Q+R 成立。

 输入格式：
 输入在一行中依次给出 A 和 B，中间以 1 空格分隔。

 输出格式：
 在一行中依次输出 Q 和 R，中间以 1 空格分隔。

 输入样例：
 123456789050987654321 7
 
 输出样例：
 17636684150141093474 3
 */


void a_divide_b(void) {
    char a[max];
    int b;
    scanf("%s %d", a, &b);
    int num = 0, r = 0;
    for (int i = 0; a[i]; i++) {
        num = r * 10 + (a[i] - '0');
        a[i] = num / b + '0';
        r = num % b;
    }
    char* p = a;
    if (a[0] == '0') p++;
    printf("%s %d\n", p, r);
}
