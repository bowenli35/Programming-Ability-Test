//
//  1003.c
//  PAT
//
//  Created by BowenLi on 2020/8/3.
//  Copyright © 2020 Bowen Li. All rights reserved.
//

#include "1003.h"

/*
 1003 我要通过！ (20point(s))
 “答案正确”是自动判题系统给出的最令人欢喜的回复。
 本题属于 PAT 的“答案正确”大派送
 ——只要读入的字符串满足下列条件，系统就输出“答案正确”，否则输出“答案错误”。

 得到“答案正确”的条件是：
 字符串中必须仅有 P、 A、 T这三种字符，不可以包含其它字符；
 任意形如 xPATx 的字符串都可以获得“答案正确”，其中 x 或者是空字符串，
 或者是仅由字母 A 组成的字符串；如果 aPbTc 是正确的，那么 aPbATca 也是正确的，
 其中 a、 b、 c 均或者是空字符串，或者是仅由字母 A 组成的字符串。
 现在就请你为 PAT 写一个自动裁判程序，判定哪些字符串是可以获得“答案正确”的。

 输入格式：
 每个测试输入包含 1 个测试用例。第 1 行给出一个正整数 n(<10)，是需要检测的字符串个数。
 接下来每个字符串占一行，字符串长度不超过 100，且不包含空格。

 输出格式：
 每个字符串的检测结果占一行，如果该字符串可以获得“答案正确”，则输出 YES，否则输出 NO。

 输入样例：
 8
 PAT
 PAAT
 AAPATAA
 AAPAATAAAA
 xPATx
 PT
 Whatever
 APAAATAA
 
 输出样例：
 YES
 YES
 YES
 YES
 NO
 NO
 NO
 NO
 */

// Key Point :
// 在P前面的A的个数 与 P与T之间的A的个数的乘积等于T后面A的个数

void I_wanna_pass(void) {
    int i, j, n;
    char pat[100];
    scanf("%d", &n);
    char* result[n];
    for (i = 0; i < n; i++) {
        int np = 0, nt = 0, n_other = 0;
        int ip = 0, it = 0;
        scanf("%s", pat);
        for (j = 0; pat[j]; j++) {
            if (pat[j] == 'P') {
                np++;
                ip = j;
            } else if (pat[j] == 'T') {
                nt++;
                it = j;
            } else if (pat[j] != 'A') {
                n_other++;
            }
        }
        int num_of_a_before_p = ip;
        int num_of_a_between_p_and_t = it - ip - 1;
        int num_of_a_after_t = j - it - 1;
        if (np != 1 || nt != 1 || it - ip <= 1 || n_other != 0) {
            result[i] = "No";
        } else if (num_of_a_before_p * num_of_a_between_p_and_t != num_of_a_after_t) {
            result[i] = "No";
        } else {
            result[i] = "YES";
        }
    }
    for (i = 0; i < n; i++) {
        printf("%s\n", result[i]);
    }
}

