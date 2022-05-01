//
// Created by dylan on 5/1/22.
//

#include "util.h"

int MAX(int x, int y) {
    return x > y ? x : y;
}

int MIN(int x, int y) {
    return x < y ? x : y;
}

int collision(int x1, int y1, int w1, int h1, int x2, int y2, int w2, int h2) {
    return (MAX(x1, x2) < MIN(x1 + w1, x2 + w2)) && (MAX(y1, y2) < MIN(y1 + h1, y2 + h2));
}