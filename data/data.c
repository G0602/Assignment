//this file contains the functions required to editing and writing data in a text file

#include "../glbl_vars.h"
#include "data.h"
#include "../initial/initial.h"
#include "../canvas/canvas.h"

//this function will write the details of B and all Es in a givven pointer location
void prntDtl(FILE *file){
    fprintf(file, "Size_of_the_battle_field(D): %d km\n", D);
    fprintf(file, "Number_of_escort_ship: %d\n\n", N);

    B_Dtl( file);

    for(int i = 0; i < N; i++){
        E_Dtl( i, file);
    }
}

//this function will write the details of B in a givven pointer location
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

//this function will write the details of one E in a givven pointer location by gettig the number of E and the pointer as the input
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

// this function list all the directories in the battle_info directory and return the pointer to the directory the user chose.
char* btlList(void){
    int max = 10;
    int temp;// to return the input

    struct dirent *btl[max];
    DIR *dir = opendir(".");
    system("pwd");

    if (dir == NULL) {
        printf("Error! Unable to open battle_info directory.\n");
        return NULL;
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

    do{
    printf("Enter the number of the battle you want to see: ");
    scanf(" %d", &temp);
    }while (!(temp >=1 && temp <= max));
    
end:

    printf("\n");

    closedir(dir);

    return btl[temp-1]->d_name;
}

// this function get a pointer to a directory as in put and show the files in that directories
void selBtl(char *btlPath){

   if (chdir(btlPath) != 0) {
        printf("\n");
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

void getInfo(void){
      do{
    printf("\nEnter the size of the battle field: ");
    scanf("%d", &D);

    printf("\nEnter the number of the escort ships you want to have in this simulation: ");
    scanf("%d", &N);

    if(D <= 0 || N <= 0){
        printf("\nThe vlues you just enterd are not valid.\nPlease make sure they bothe are integer greater than 0.\n");
    }

    }while(D <= 0 || N <= 0);

    initialCond(1);//save ititial condition after changes
    location();//to generate new loctions after changes
}