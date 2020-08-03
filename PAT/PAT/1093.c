//
//  1093.c
//  PAT
//
//  Created by BowenLi on 2020/8/3.
//  Copyright © 2020 Bowen Li. All rights reserved.
//

#include "1093.h"

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

