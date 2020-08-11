//
//  1020.h
//  PAT
//
//  Created by BowenLi on 2020/8/10.
//  Copyright © 2020 Bowen Li. All rights reserved.
//

#ifndef _020_h
#define _020_h

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int supply;
    int totalPrice;
    double unitPrice;
} Product;

int comparator(const void * a, const void * b);
void moonCake(void);

#endif /* _020_h */
