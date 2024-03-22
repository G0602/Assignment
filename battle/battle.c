//this file contains the functions related to the battle.

#include "../random/random.h"
#include "../glbl_vars.h"
#include "battle.h"
#include "../initial/initial.h"
#include "../canvas/canvas.h"
#include "../data/data.h"

const float g = 9.80665;// acceleration of gravity
int tKill = 0;//to show how many Es' has been destroyed by B totaly
float tTime = 0;// total time to complete B's attacks
int killCount = 0;//number of E destroyed at the attack in one location
float killTime = 0;//time took to complete the attack in one location

int battle(int it){
    FILE *file1;
    if (it == 1){

        if (chdir(name) != 0) {//changing the working directory to the battle file
            perror("Error changing directory");
            return 1;//error handling
        }
        file1 = fopen("destruction.txt", "w");
    } else {
        file1 = fopen("destruction.txt", "a");
    }

    if (file1 == NULL) {
        printf("Error opening the file destruction.txt.\n");
        return 1;
    }

    FILE *file2 = fopen("results.txt", "w");
    if (file2 == NULL) {
        printf("Error opening the file finale.txt.\n");
        return 1;
    }

    printf("Current itteration no.%d:\nCurrent location( %d, %d).\n", it, B.position.x, B.position.y);
    fprintf(file1, "Current itteration no.%d:\n", it);
    
    B.range.min= 0;
    B.range.max= rangeF(45, B.vMax);
    if(it >= t && B.maxVelMinRng == 0){// only true if current itteration is greater than or equal to t and value for maxVelMinRng isn't previously assigned
        B.angMin= ranNum(10,30);
        printf("The gun of the Battle ship is malfunctioned.Now the minimum attacking angle is %d'.\n", B.angMin);
        B.maxVelMinRng = rangeF(B.angMin, B.vMax);
    } 

    for(int i = 0; i < N; i++){
        rangeMinMax(i);
        E[i].dist = distCalc(B.position.x, B.position.y, E[i].position.x, E[i].position.y);
        canEAtk(i);
    }
    
    if (B.status == 1){
        canBAtk ( file1);
        printf("Currently there are no Es in the range of B in this location.\nTotal number of Es got destroyed in this location is %d.\nTotal time took to finish the battle in this location is %.2fs.\n\n", killCount, killTime);
        fprintf(file1, "Currently there are no Es in the range of B in this location.\nTotal number of Es got destroyed in this location is %d.\nTotal time took to finish the battle in this location is %.2fs.\n\n", killCount, killTime);
    }


    prntDtl(file2);

    //the following mesage will print after the last iteration
    if(it == k || B.status == 0){
        printf("The total time took to complete all iterations is %.2f.\nIn total B has destroyed %d Es.\nRemaining durability of the battleship is %d%%\n\n", tTime, tKill, B.hp);
        fprintf(file2, "The total time took to complete all iterations is %.2f.\nIn total B has destroyed %d Es.\nRemaining durability of the battleship is %d%%\n\n", tTime, tKill, B.hp);
   
        if (chdir("..") != 0) {//going back to battle_info
            perror("Error changing directory");
            return 1;//error handling
        }
    }
    
    fclose(file1);
    fclose(file2);

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

//this is a function to calculate the distance travelde by the shell using the angle of the gun and the initial velocity of the shell
float rangeF(int a, int v){
    return ((pow(v, 2)*sin(2 * a * (M_PI / 180.0)))/(g * 1000)); // this will give the range in kilo meters
}

//this a function to calculate the time to shell reach E in seconds
float atkTime(int i){
    if(E[i].dist < B.maxVelMinRng)
        return pow(((( E[i].dist * pow(3, 0.5)) / pow(g, 3) * 2)),0.5);
    else
        return ((2 * B.vMax * sin(0.5 * asin((E[i].dist * 1000 * g)/pow(B.vMax, 2))))/g);
}


//this function check whether the E can attack B if E has not been destroyed
void canEAtk(int i){
    if(E[i].status == 0)
        return;

    if((E[i].dist <= E[i].range.max) && (E[i].dist >= E[i].range.min)){
        B.hp -= E[i].ip;
        if(B.hp <= 0){
            printf("B is destroyed due to its durability reaching 0.\n");
            B.status = 0;
        }
        printf("B has been attcked by:%s and lost %d%% of its durability.\n", E[i].indexNum, E[i].ip);
    }
}

//this function check whether the B can attack E and print the time and count for this attack
void canBAtk(FILE *file){
    killCount = 0;
    killTime = 0;
    for(int i = 0; i < N; i++){
        if(E[i].dist <= B.range.max && E[i].status == 1){
            if (killCount == 0){ 
                printf("Following ships has been destroyed by B:\n");
                fprintf(file, "Following ships has been destroyed by B:\n");
            }
            E[i].status = 0;
            killCount++;
            killTime += atkTime(i);
            printf("\t%s( %d, %d)\n", E[i].indexNum, E[i].position.x, E[i].position.y);
            fprintf(file, "%s\n", E[i].indexNum);
        }
    }
    tTime += killTime;
    tKill += killCount;
}