#include <math.h>
#include <stdio.h>
#include"../glbl_vars.h"
#include "battle.h"

int battle(void){
    /*
    FILE *file = fopen("initial.txt", "r");
    if (file == NULL) {
        printf("Error opening the file initial.txt.\n");
        return 1;
    }
    */

    for(int i = 0; i < N; i++){
    E[i].dist = distCalc(i);
    printf("The distance between B and %s is -> %f \n", E[i].indexNum, E[i].dist);
    }
    
    //fclose(file);

    return 0;
}

float distCalc(int i){

    return sqrt(fabs(B.position.x - E[i].position.x) + fabs(B.position.y - E[i].position.y));
}