//
//  1024.c
//  PAT
//
//  Created by BowenLi on 2020/8/12.
//  Copyright © 2020 Bowen Li. All rights reserved.
//

#include "1024.h"

/*
 1024 科学计数法 (20point(s))
 科学计数法是科学家用来表示很大或很小的数字的一种方便的方法，
 其满足正则表达式 [+-][1-9].[0-9]+E[+-][0-9]+，
 即数字的整数部分只有 1 位，小数部分至少有 1 位，
 该数字及其指数部分的正负号即使对正数也必定明确给出。

 现以科学计数法的格式给出实数 A，
 请编写程序按普通数字表示法输出 A，
 并保证所有有效位都被保留。

 输入格式：
 每个输入包含 1 个测试用例，即一个以科学计数法表示的实数 A。
 该数字的存储长度不超过 9999 字节，且其指数的绝对值不超过 9999。

 输出格式：
 对每个测试用例，在一行中按普通数字表示法输出 A，
 并保证所有有效位都被保留，包括末尾的 0。

 输入样例 1：
 +1.23400E-03
 
 输出样例 1：
 0.00123400
 
 输入样例 2：
 -1.2E+10
 
 输出样例 2：
 -12000000000
 */

void scientificNotation(void) {
    char a1[max];
    scanf("%s", a1);
    char *a2 = strchr(a1, '.');
    char *a3 = strchr(a2, 'E');
    a2++; a3++;
    // a1 --> +1.23400E-03
    // a2 --> 23400
    // a3 --> -03
    int i, j, cnt = 0;
    char result[max];
    for (i = 1; a3[i]; i++) {
        cnt = cnt * 10 + (a3[i] - '0');
    }
    //-1.E+10
    if (a3[0] == '+') {
        j = plus(result, a1);
        while (*a2 != 'E' && cnt) {
            result[j++] = *a2++;
            cnt--;
        }
        while (cnt) {
            result[j++] = '0';
            cnt--;
        }
    //+1.23400E-03
    } else {
        j = 3;
        result[0] = a1[0];
        result[1] = '0';
        result[2] = '.';
        cnt--;
        while (cnt) {
            result[j++] = '0';
            cnt--;
        }
        result[j++] = a1[1];
        while (*a2 != 'E') {
            result[j++] = *a2;
            a2++;
        }
    }
    result[j] = '\0';
    result[0] == '+' ? printf("re+ =%s\n", result + 1) : printf("re- =%s\n", result);
}


// -1.2E+10
// result = -1
// return 2
int plus(char *result, char *a) {
    int cnt = 0;
    while (*a != '.') {
        *result = *a;
        cnt++;
        result++;
        a++;
    }
    return cnt;
}
