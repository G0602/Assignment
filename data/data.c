//this sile contains the functions required to eading and writing data in a text file

#include "../glbl_vars.h"
#include "data.h"
#include <dirent.h>
#include <unistd.h>

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

char* btlList(void){
    int max = 100;
    int temp;// to return the input

    struct dirent *btl[max];
    DIR *dir = opendir(path);

    if (dir == NULL) {
        printf("Error! Unable to open battle_info directory.\n");
        return 0;
    }



    int count = 0;
    printf("\nFollowing battle datas are availablle:\n");
    while ((btl[count] = readdir(dir)) != NULL && count < max) {
        if (btl[count]->d_type == DT_DIR) {// To only consider directory files
            if (strcmp(btl[count]->d_name, ".") != 0 && strcmp(btl[count]->d_name, "..") != 0) {// Skip the current and parent directories
                printf("\t%d.%s\n", count+1, btl[count]->d_name);
                count++;
            }
        }
    }

    if(btl[count] == NULL && count == 0){
        printf("\033[F"); //to overwrite the previouse line
        printf("        There is no record of past battles.\n");
        goto end;
    }

    if (count == max) {
        printf("\t...and more directories exist.\n");
    }

    printf("Enter the number of the battle you want to see: ");
    scanf(" %d", &temp);
    
end:

    printf("\n");

    closedir(dir);

    return btl[temp-1]->d_name;
}

void selBtl(char *btlPath){

   if (chdir(btlPath) != 0) {
        perror("chdir() error");
        return;
    }

    int max = 2;

    struct dirent *data[max];

    DIR *dir = opendir(".");

    if (dir == NULL) {
        printf("Error! Unable to open battle data directory.\n");
        return ;
    }

    int count = 0;
    printf("\nFollowing battle datas are availablle:\n");
    while ((data[count] = readdir(dir)) != NULL && count < max) {
        if (data[count]->d_type == DT_REG) {// To only display txt files
            printf("\t%d.%s\n", count+1, data[count]->d_name);
            count++;
        }
    }


    DIR *subDir = opendir("..");

    if (subDir == NULL) {
        printf("Unexpected error occured.\nWe are exiting the program.......\n\n");
        exit(EXIT_FAILURE);
    }
}