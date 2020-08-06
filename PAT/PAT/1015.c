//
//  1015.c
//  PAT
//
//  Created by BowenLi on 2020/8/5.
//  Copyright © 2020 Bowen Li. All rights reserved.
//

#include "1015.h"
#include "string.h"

/*
 1015 德才论 (25point(s))
 宋代史学家司马光在《资治通鉴》中有一段著名的“德才论”：
 “是故才德全尽谓之圣人，才德兼亡谓之愚人，德胜才谓之君子，才胜德谓之小人。
 凡取人之术，苟不得圣人，君子而与之，与其得小人，不若得愚人。”

 现给出一批考生的德才分数，请根据司马光的理论给出录取排名。

 输入格式：
 输入第一行给出 3 个正整数，分别为：N（≤10^5），
 即考生总数；L（≥60），为录取最低分数线，
 即德分和才分均不低于 L 的考生才有资格被考虑录取；H（<100），
 为优先录取线——德分和才分均不低于此线的被定义为“才德全尽”，
 此类考生按德才总分从高到低排序；
 才分不到但德分到线的一类考生属于“德胜才”，
 也按总分排序，但排在第一类考生之后；
 德才分均低于 H，但是德分不低于才分的考生属于“才德兼亡”但尚有“德胜才”者，按总分排序，
 但排在第二类考生之后；其他达到最低线 L 的考生也按总分排序，但排在第三类考生之后。

 随后 N 行，每行给出一位考生的信息，
 包括：准考证号 德分 才分，其中准考证号为 8 位整数，
 德才分为区间 [0, 100] 内的整数。数字间以空格分隔。

 输出格式：
 输出第一行首先给出达到最低分数线的考生人数 M，随后 M 行，
 每行按照输入格式输出一位考生的信息，
 考生按输入中说明的规则从高到低排序。
 当某类考生中有多人总分相同时，按其德分降序排列；
 若德分也并列，则按准考证号的升序输出。

 输入样例：
 14 60 80
 10000001 64 90
 10000002 90 60
 10000011 85 80
 10000003 85 80
 10000004 80 85
 10000005 82 77
 10000006 83 76
 10000007 90 78
 10000008 75 79
 10000009 59 90
 10000010 88 45
 10000012 80 100
 10000013 90 99
 10000014 66 60
 
 输出样例：
 12
 10000013 90 99
 10000012 80 100
 10000003 85 80
 10000011 85 80
 10000004 80 85
 10000007 90 78
 10000006 83 76
 10000005 82 77
 10000002 90 60
 10000014 66 60
 10000008 75 79
 10000001 64 90
 */

int cmp(const void* a,const void* b) {
    Student* s1 = (Student*) a;
    Student* s2 = (Student*) b;
    if ((s1 -> de + s1 -> cai) == (s2 -> de + s2 -> cai)) {
        if (s1 -> de == s2 -> de)
            return strcmp(s2 -> id, s1 -> id);
        else
            return s2 -> de - s1 -> de;
    } else {
        return (s2 -> de + s2 -> cai) - (s1 -> de + s1 -> cai);
    }
}

void print(Student* s, int len) {
    while (len) {
        printf("%s %d %d\n", s -> id, s -> de, s -> cai);
        s++;
        len--;
    }
}

void rankStudents(void) {
    int N, L, H;
    scanf("%d %d %d", &N, &L, &H);
    int i, i1 = 0, i2 = 0, i3 = 0, i4 = 0;
    Student s1[N];
    Student s2[N];
    Student s3[N];
    Student s4[N];
    char id[9];
    int de, cai;
    for (i = 0; i < N; i++) {
        scanf("%s %d %d", id, &de, &cai);
        if (de >= L && cai >= L) {
            if (de >= H && cai >= H) {
                strcpy(s1[i1].id, id);
                s1[i1].de = de;
                s1[i1].cai = cai;
                i1++;
            } else if (de >= H) {
                strcpy(s2[i2].id, id);
                s2[i2].de = de;
                s2[i2].cai = cai;
                i2++;
            } else if (de >= cai) {
                strcpy(s3[i3].id, id);
                s3[i3].de = de;
                s3[i3].cai = cai;
                i3++;
            } else {
                strcpy(s4[i4].id, id);
                s4[i4].de = de;
                s4[i4].cai = cai;
                i4++;
            }
        }
    }
    qsort(s1, i1, sizeof(Student), cmp);
    qsort(s2, i2, sizeof(Student), cmp);
    qsort(s3, i3, sizeof(Student), cmp);
    qsort(s4, i4, sizeof(Student), cmp);
    printf("%d\n", i1 + i2 + i3 + i4);
    print(s1, i1);
    print(s2, i2);
    print(s3, i3);
    print(s4, i4);
}



