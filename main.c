#include <stdlib.h>
#include "initial/initial.h"
#include "battle/battle.h"
#include "glbl_vars.h"

// defining following variables to be used in all other files and function
int D = 10;// Default values for D
int N = 10;// Default values for N
btlShp B;
escShp *E;

int main(){
    E = (escShp*) malloc(N * sizeof(escShp));

    initialCond();
    battle();

    free(E);

    return 0;
}