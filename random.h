#ifndef RANDOM_H
#define RANDOM_H

#include <stdlib.h>

srand(time(NULL));

int ranNum(int min, int max) {
    return min + rand() % (max - min + 1);
}

#endif