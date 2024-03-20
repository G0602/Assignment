#include "random.h"
#include "../glbl_vars.h"


int ranNum(int min, int max) {
    return min + rand() % (max - min + 1);
}