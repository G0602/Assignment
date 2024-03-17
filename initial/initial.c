#include <stdio.h>
#include <stdlib.h>
#include "../random/random.h"
#include "initial.h"
#include"../glbl_vars.h"

//function to get the initial condition and save it in a text file called initial.txt
void initialCond(void){

    FILE *file = fopen("initial.txt", "w");
    if (file == NULL) {
        printf("Error opening/creating the file initial.txt.\n");
    }

    
    //i want to add a if condition to select whether the user want to inpu the values or get random values.
    /*{

    printf("Enter the size of the battle field: ");
    scanf("%d", &D);

    printf("Enter the number of the escort ships you want to have in this simulation: ");
    scanf("%d", &N);


    E = (escShp*) malloc(N * sizeof(escShp));

    // error handeling
    if (E == NULL) {
        printf("Memory allocation failed!\n");
        return; 
    }
    
    printf("Enter the maximum velocity of the escort ships: ");
    scanf("%d", &E.vMax);
    
    printf("Enter the minimun velocity of the escort ships: ");
    scanf("%d", &E.vMin);

    printf("Enter the minimum angle of the escort ships: ");
    scanf("%d", &E.angMin);

    printf("Enter the maximum velocity of the battle ship: ");
    scanf("%d", &B.vMax);

    printf("Enter the type of the battle ship you want to observe: ");
    scanf("%c", &B.type);
    }*/

    {

        E = (escShp*) malloc(N * sizeof(escShp));

        // error handeling
        if (E == NULL) {
            printf("Memory allocation failed!\n");
            return; 
        }

        //randomly generted values for B's properties
        B.vMax = ranNum(0,100);
        switch(ranNum(0,3)){
            case 0: B.type = 'U';
                    break;
            case 1: B.type = 'M';
                    break;
            case 2: B.type = 'R';
                    break;
            case 3: B.type = 'S';
                    break;
        }
        B.position.x=ranNum(0,D);
        B.position.y=ranNum(0,D);

        //randomly generted values for Es' properties
        for(int i = 0; i < N; i++){
            E[i].vMax = ranNum(2 ,100);
            E[i].vMin = ranNum(0 ,E[i].vMax - 1);
            switch(ranNum(0,4)){
            case 0: E[i].type = 'A';
                    E[i].angRange = 20;
                    break;
            case 1: E[i].type = 'B';
                    E[i].angRange = 30;
                    break;
            case 2: E[i].type = 'C';
                    E[i].angRange = 25;
                    break;
            case 3: E[i].type = 'D';
                    E[i].angRange = 50;
                    break;
            case 4: E[i].type = 'E';
                    E[i].angRange = 70;
                    break;
            }
            E[i].angMin = ranNum(0, 90 - E[i].angRange);
            E[i].angMax = E[i].angMin + E[i].angRange;
            E[i].position.x = ranNum(0,D);
            E[i].position.y = ranNum(0,D);
            snprintf(E[i].indexNum, sizeof(E[i].indexNum), "E%c%03d", E[i].type, i + 1);
        }
    }
   
    fprintf(file, "canvasSize(D): %d\n", D);
    fprintf(file, "escortNum: %d\n\n", N);

    fprintf(file, "BATTLE_SHIP's Details:\n");
    fprintf(file, "\tvMax: %d\n", B.vMax);
    fprintf(file, "\ttype: %c\n", B.type);
    fprintf(file, "\tcoordiate: (%d,%d)\n\n", B.position.x, B.position.y);

    for(int i = 0; i < N; i++){
        fprintf(file, "ESCORT_SHIP_%d's Details:\n", i + 1);
        fprintf(file, "\ttype: %c\n", E[i].type);
        fprintf(file, "\tindex_number: %s\n", E[i].indexNum);
        fprintf(file, "\tcoordiate: (%d,%d)\n", E[i].position.x, E[i].position.y);
        fprintf(file, "\tvMax: %d\n", E[i].vMax);
        fprintf(file, "\tvMin: %d\n", E[i].vMin);
        fprintf(file, "\tangMin: %d\n", E[i].angMin);
        fprintf(file, "\tangMax: %d\n\n", E[i].angMax);
    }

    free(E);
    fclose(file);
}