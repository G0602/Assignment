#include <stdlib.h>
#include "initial/initial.h"
#include "battle/battle.h"
#include "glbl_vars.h"
#include "canvas/canvas.h"

// defining following variables to be used in all other files and function
int D = 10;// Default value for D
int N = 10;// Default value for N
int k = 10;// Default value for k
int t = 5;// Default value for t
btlShp B;
escShp *E;
Movement *move;

int main(){
    int iteration=0; // the number of times the battle has happend
    E = (escShp*) malloc(N * sizeof(escShp));
    move = (Movement*) malloc(k * sizeof(Movement));

    mainMenu()

    initialCond();
    location();
    do{
        battle(iteration + 1);
        motion();
        iteration++;
    } while((iteration < k) && (B.status == 1));

    if((iteration == k) && (B.status == 1)){
        printf("The Battle ship survived all iterations.\n");
    }


    free(E);
    free(move);

    return 0;
}

//need to make some changes depends on the function calling this
void prntDtl(FILE *file){
    fprintf(file, "canvasSize(D): %d km\n", D);
    fprintf(file, "escortNum: %d\n\n", N);

    B_Dtl( file);

    for(int i = 0; i < N; i++){
        E_Dtl( i, file);
    }
}

void B_Dtl(FILE *file){
    fprintf(file, "BATTLE_SHIP's Details:\n");
    fprintf(file, "\tMaximum_Shell_velocity: %d m/s\n", B.vMax);
    fprintf(file, "\tType: %c\n", B.type);
    fprintf(file, "\tDurability: %d%%\n", B.hp);
    if(B.status == 1){
        fprintf(file, "\tstatus: %s\n", "Available");
    } else {
        fprintf(file, "\tstatus: %s\n", "Offline");
    }
    fprintf(file, "\tcoordiate: ( %d, %d)\n", B.position.x, B.position.y);
    fprintf(file, "\tMaximum_Angle_of_the_Gun: %d'\n", B.angMax);
    fprintf(file, "\tMinimum_Angle_of_the_Gun: %d'\n\n", B.angMin);
}

void E_Dtl(int i, FILE *file){
    fprintf(file, "ESCORT_SHIP_%d's Details:\n", i + 1);
    fprintf(file, "\tType: %c\n", E[i].type);
    fprintf(file, "\tImpact_power: %.2f\n", (float)(E[i].type/100));
    if(E[i].status == 1){
        fprintf(file, "\tstatus: %s\n", "Available");
    } else {
        fprintf(file, "\tstatus: %s\n", "Offline");
    }
    fprintf(file, "\tindex_number: %s\n", E[i].indexNum);
    fprintf(file, "\tcoordiate: (%d,%d)\n", E[i].position.x, E[i].position.y);
    fprintf(file, "\tMaximum_Shell_velocity: %d m/s\n", E[i].vMax);
    fprintf(file, "\tMinimum_Shell_velocity: %d m/s\n", E[i].vMin);
    fprintf(file, "\tMaximum_Angle_of_the_Gun: %d'\n", E[i].angMax);
    fprintf(file, "\tMinimum_Angle_of_the_Gun: %d'\n\n", E[i].angMin);
}