//
//  1015.h
//  PAT
//
//  Created by BowenLi on 2020/8/5.
//  Copyright © 2020 Bowen Li. All rights reserved.
//

#ifndef _015_h
#define _015_h

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
    char id[9];
    int de;
    int cai;
} Student;

void rankStudents(void);
void print(Student* s, int len);
int cmp(const void* a,const void* b);

#endif /* _015_h */
