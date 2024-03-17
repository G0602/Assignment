#include <stdlib.h>
#include <time.h>
#include "random.h"


int ranNum(int min, int max) {
    srand(time(NULL));
    return min + rand() % (max - min + 1);
}