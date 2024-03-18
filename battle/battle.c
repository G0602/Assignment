#include <math.h>
#include <stdio.h>
#include"../glbl_vars.h"
#include "battle.h"
#include "../initial/initial.h"

const float g = 9.80665;// acceleration of gravity
int kill = 0;//to show how many Es' has been destroyed by B
float time = 0;// total time to complete B's attacks

int battle(void){
    /*
    FILE *file = fopen("initial.txt", "r");
    if (file == NULL) {
        printf("Error opening the file initial.txt.\n");
        return 1;
    }
    */
    B.range.min= 0;
    B.range.max= rangeF(45, B.vMax);

    for(int i = 0; i < N; i++){
        rangeMinMax(i);
        E[i].dist = distCalc(i);
        canEAtk(i);
        if (B.status == 1){
            canBAtk (i);
        }
    }
    
    //fclose(file);

    return 0;
}

// this function uses the rangeF function to figure out the maximum and the minimum range of E
void rangeMinMax(int i){

    if((E[i].angMax >= 45) && (E[i].angMin <= 45)){
        E[i].range.max= rangeF(45, E[i].vMax);
        if(fabs(E[i].angMax-45) < fabs(E[i].angMin-45)){
            E[i].range.min= rangeF(E[i].angMin, E[i].vMin);
        } else {
            E[i].range.min= rangeF(E[i].angMax, E[i].vMin);
        }
    } else if(fabs(E[i].angMax-45) < fabs(E[i].angMin-45)){
        E[i].range.max= rangeF(E[i].angMax, E[i].vMax);
        E[i].range.min= rangeF(E[i].angMin, E[i].vMin);
    } else {
        E[i].range.max= rangeF(E[i].angMin, E[i].vMax); 
        E[i].range.min= rangeF(E[i].angMax, E[i].vMin);
    }
}

// this function calclate the distance between B and E
float distCalc(int i){
    return sqrt(pow((B.position.x - E[i].position.x),2) + pow((B.position.y - E[i].position.y),2));
}

//this is a function to calculate the distance travelde by the shell using the angle of the gun and the initial velocity of the shell
float rangeF(int a, int v){
    return ((pow(v, 2)*sin(2 * a * (M_PI / 180.0)))/(g * 1000)); // this will give the range in kilo meters
}

//this a function to calculate the time to shell reach E
float atkTime(int i){
    return ((2 * B.vMax * sin(0.5 * asin((E[i].dist * g)/pow(B.vMax, 2))))/g);
}


//this function check whether the E can attack B
void canEAtk(int i){

    if((E[i].dist <= E[i].range.max) && (E[i].dist >= E[i].range.min)){
        if(B.status == 1){
            printf("B is destroyed.\nIt has been attcked by following ships:\n");
            B.status = 0;
        }
        printf("%s\n", E[i].indexNum);
    }
}

//this function check whether the B can attack E
void canBAtk(int i){
    if(E[i].dist <= B.range.max){
        if (kill == 0){ 
            printf("Following ships has been destroyed by B:\n");
        }
        E[i].status = 0;
        kill++;
        time += atkTime(i);
        E[i].status = 0;
        printf("%s\n", E[i].indexNum);
    }
}