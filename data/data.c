//this sile contains the functions required to eading and writing data in a text file

#include "../glbl_vars.h"
#include "data.h"

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