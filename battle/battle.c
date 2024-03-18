#include <math.h>
#include <stdio.h>
#include"../glbl_vars.h"
#include "battle.h"

const float g = 9.80665;

int battle(void){
    /*
    FILE *file = fopen("initial.txt", "r");
    if (file == NULL) {
        printf("Error opening the file initial.txt.\n");
        return 1;
    }
    */

    for(int i = 0; i < N; i++){
        range(i);
        E[i].dist = distCalc(i);
        printf("The distance between B and %s is -> %.2f \n And the maximum and the minimum range are %d,%d\n\n", E[i].indexNum, E[i].dist, E[i].range.max, E[i].range.min);
    }
    
    //fclose(file);

    return 0;
}

// this function uses the rangeF function to figure out the maximum and the minimum range of E
void range(int i){
    if(fabs(E[i].angMax-45) < (E[i].angMin-45)){
        E[i].range.max= rangeF(E[i].angMax, E[i].vMax);
        E[i].range.min= rangeF(E[i].angMin, E[i].vMin);
    } else {
        E[i].range.max= rangeF(E[i].angMin, E[i].vMax); 
        E[i].range.min= rangeF(E[i].angMax, E[i].vMin);
    }
}

// this function calclate the distance between B and E
float distCalc(int i){
    return sqrt(fabs(B.position.x - E[i].position.x) + fabs(B.position.y - E[i].position.y));
}

//this is a function to calculate the distance travelde by the shell using the angle of the gun and the initial velocity of the shell
float rangeF(int a, int v){
    return (float)(pow(v, 2)*sin(2 * a * (M_PI / 180.0)))/g;
}