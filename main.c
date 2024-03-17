#include "initial/initial.h"
#include "battle/battle.h"
#include "glbl_vars.h"

// defining following variables to be used in all other files and function
int D = 100;// Default values for D
int N = 10;// Default values for N
btlShp B;
escShp *E;

int main(){

    initialCond();
    battle();
    return 0;
}