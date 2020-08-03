//
//  main.c
//  PAT
//
//  Created by BowenLi on 2020/8/3.
//  Copyright © 2020 Bowen Li. All rights reserved.
//

#include <stdio.h>

int myStrlen(char* str) {
    int cnt = 0;
    while (str[cnt]) {
        cnt++;
    }
    return cnt;
}

char* myStrcat(char* restrict dst, char* restrict src) {
    int i = myStrlen(dst);
    int j = 0;
    while (src[j]) {
        dst[i++] = src[j++];
    }
    dst[i] = '\0';
    return dst;
}
