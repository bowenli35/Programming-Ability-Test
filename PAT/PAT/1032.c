//
//  1032.c
//  PAT
//
//  Created by BowenLi on 2020/8/4.
//  Copyright © 2020 Bowen Li. All rights reserved.
//

#include "1032.h"

/*
 1032 挖掘机技术哪家强 (20point(s))
 为了用事实说明挖掘机技术到底哪家强，PAT 组织了一场挖掘机技能大赛。
 现请你根据比赛结果统计出技术最强的那个学校。

 输入格式：
 输入在第 1 行给出不超过 10^5的正整数 N，即参赛人数。
 随后 N 行，每行给出一位参赛者的信息和成绩，
 包括其所代表的学校的编号（从 1 开始连续编号)
 及其比赛成绩（百分制），中间以空格分隔。

 输出格式：

 在一行中给出总得分最高的学校的编号、及其总分，中间以空格分隔。
 题目保证答案唯一，没有并列。

 输入样例：
 6
 3 65
 2 80
 1 100
 2 70
 3 40
 3 0
 
 输出样例：
 2 150
 */

void excavator(void) {
    int i, n;
    scanf("%d", &n);
    int player[n];
    for (i = 0; i < n; i++) {
        player[i] = 0;
    }
    int id, grade;
    for (i = 0; i < n; i++) {
        scanf("%d %d", &id, &grade);
        player[id-1] += grade;
    }
    int max = player[0], max_id = 1;
    for (i = 1; i < n; i++) {
        if (player[i] > max) {
            max = player[i];
            max_id = i + 1;
        }
    }
    printf("%d %d\n", max_id, max);
}
