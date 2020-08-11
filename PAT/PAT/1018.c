//
//  1018.c
//  PAT
//
//  Created by BowenLi on 2020/8/10.
//  Copyright © 2020 Bowen Li. All rights reserved.
//

#include "1018.h"

/*
 1018 锤子剪刀布 (20point(s))
 现给出两人的交锋记录，请统计双方的胜、平、负次数，并且给出双方分别出什么手势的胜算最大。

 输入格式：
 输入第 1 行给出正整数 N（≤10^5），即双方交锋的次数。
 随后 N 行，每行给出一次交锋的信息，
 即甲、乙双方同时给出的的手势。
 C 代表“锤子”、J 代表“剪刀”、B 代表“布”，
 第 1 个字母代表甲方，第 2 个代表乙方，中间有 1 个空格。

 输出格式：
 输出第 1、2 行分别给出甲、乙的胜、平、负次数，数字间以 1 个空格分隔。
 第 3 行给出两个字母，分别代表甲、乙获胜次数最多的手势，中间有 1 个空格。
 如果解不唯一，则输出按字母序最小的解。

 输入样例：
 10
 C J
 J B
 C B
 B B
 B C
 C C
 C B
 J B
 B C
 J J
 
 输出样例：
 5 3 2
 2 3 5
 B B
 */

void rockPaperScissors(void) {
    int n;
    scanf("%d", &n);
    int j = 0, y = 0, p = 0;
    int jia[3] = {0}, yi[3] = {0};
    char c[3] = "CJB";
    char a, b;
    while (n) {
        getchar();
        scanf("%c %c", &a, &b);
        int ju = judge(a, b, jia, yi);
        if (ju == 1) j++;
        else if (ju == 0) y++;
        else p++;
        n--;
    }
    printf("%d %d %d\n", j, p, y);
    printf("%d %d %d\n", y, p, j);
    printf("%c %c\n", c[max(jia)], c[max(yi)]);
}

int judge(char j, char y, int* jia, int* yi) {
    int result = -1;
    if (j == 'J' && y == 'B') {
        jia[1]++;
        result = 1;
    } else if (y == 'J' && j == 'B') {
        yi[1]++;
        result = 0;
    } else if (j > y) {
        yi[indexOf(y)]++;
        result = 0;
    } else if (j < y) {
        jia[indexOf(j)]++;
        result = 1;
    }
    return result;
}



int indexOf(char c) {
    if (c == 'C') return 0;
    else if (c == 'J') return 1;
    else return 2;
}

int max(int* a) {
    if (a[0] > a[1] && a[0] > a[2]) return 0;
    else if (a[0] < a[1] && a[0] > a[2]) return 1;
    else if (a[0] > a[1] && a[0] < a[2]) return 2;
    else if (a[0] == a[1] && a[0] > a[2]) return 1;
    else if (a[0] == a[1] && a[0] < a[2]) return 2;
    else if (a[0] > a[1] && a[1] == a[2]) return 0;
    else if (a[0] < a[1] && a[1] == a[2]) return 2;
    else return 2;
}


