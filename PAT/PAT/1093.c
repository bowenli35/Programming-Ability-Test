//
//  1093.c
//  PAT
//
//  Created by BowenLi on 2020/8/3.
//  Copyright © 2020 Bowen Li. All rights reserved.
//

#include "1093.h"

/*
 1093 字符串A+B (20point(s))
 给定两个字符串 A 和 B，本题要求你输出 A+B，即两个字符串的并集。
 要求先输出 A，再输出 B，但重复的字符必须被剔除。

 输入格式：
 输入在两行中分别给出 A 和 B，
 均为长度不超过 10^6的、由可见 ASCII 字符 (即码值为32~126)
 空格组成的、由回车标识结束的非空字符串。

 输出格式：
 在一行中输出题面要求的 A 和 B 的和。
 
 输入样例：
 This is a sample test
 to show you_How it works
 
 输出样例：
 This ampletowyu_Hrk
 */

void strs_plus_strs(void) {
    char c;
    int cnt = 0, i = 0;
    int ASCII[128] = {0};
    char toPrint[1000000] = {0};
    while (cnt < 2) {
        c = getchar();
        if (c == '\n') {
            cnt++;
        } else if (!ASCII[(int)c]) {
            ASCII[(int)c]++;
            toPrint[i++] = c;
        }
    }
    printf("%s\n", toPrint);
}

