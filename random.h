#ifndef RANDOM_H
#define RANDOM_H

#include <stdlib.h>

int getRandomNumber(int min, int max) {
    return min + rand() % (max - min + 1);
}
