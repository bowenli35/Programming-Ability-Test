//
//  1029.c
//  PAT
//
//  Created by BowenLi on 2020/8/4.
//  Copyright © 2020 Bowen Li. All rights reserved.
//

#include "1029.h"

/*
 1029 旧键盘 (20point(s))
 旧键盘上坏了几个键，于是在敲一段文字的时候，对应的字符就不会出现。
 现在给出应该输入的一段文字、以及实际被输入的文字，请你列出肯定坏掉的那些键。

 输入格式：
 输入在 2 行中分别给出应该输入的文字、以及实际被输入的文字。
 每段文字是不超过 80 个字符的串，
 由字母 A-Z（包括大、小写）、数字 0-9、以及下划线 _（代表空格）组成。
 题目保证 2 个字符串均非空。

 输出格式：
 按照发现顺序，在一行中输出坏掉的键。
 其中英文字母只输出大写，每个坏键只输出一次。
 题目保证至少有 1 个坏键。

 输入样例：
 7_This_is_a_test
 _hs_s_a_es
 
 输出样例：
 7TI
 */

void old_keyboard(void) {
    char expected[81];
    char actual[81];
    scanf("%s", expected);
    scanf("%s", actual);
    int check[122] = {0};
    char result[strlen(expected) + 1];
    int i, j = 0, cnt = 0;
    for (i = 0; expected[i]; i++) {
        if (expected[i] != actual[j]) {
            if (expected[i] >= 'a' && expected[i] <= 'z') {
                expected[i] -= 32;
            }
            check[(int)expected[i]] = 1;
            result[cnt++] = expected[i];
        } else {
            j++;
        }
    }
    for (i = 0; result[i]; i++) {
        if (check[(int)result[i]] == 1) {
            printf("%c", result[i]);
            check[(int)result[i]] = 0;
        }
    }
    printf("\n");
}
