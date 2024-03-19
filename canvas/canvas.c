#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "../glbl_vars.h"
#include "../random/random.h"

/*
int canvas() {
    char array[D][D];

    for (int i = 0; i < D; i++) {
        for (int j = 0; j < COLS; j++) {
            array[i][j] = '.';
        }
    }



    FILE *file = fopen("canvas.txt", "w");
    if (file == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            fprintf(file, " %c", array[i][j]);
        }
        fprintf(file, "\n");
    }

    fclose(file);

    printf("Array successfully saved to canvas.txt.\n");

    return 0;
}
*/

// this function generate k number of random loctions and set their status to non visited
void location(){
    for(int i = 0;i < k; i++){
        move[i].position.x = ranNum(0,D);
        move[i].position.y = ranNum(0,D);
        move[i].visit = 0;
    }
}

// this function calclate the distance between B and E
float distCalc(int x1, int y1, int x2, int y2){
    return sqrt(pow((x1 - x2),2) + pow((y1 - y2),2));
}

//this function chose the closest location among the non visited ones from the current location
int chose(){
    int minDist = -1;
    for(int i = 0;i < k; i++){
        if(move[i].visit == 0){
            if(minDist == -1){
                minDist = i;
            }
            move[i].dist = distCalc(B.position.x, B.position.y, move[i].position.x, move[i].position.y);
            if (move[minDist].dist > move[i].dist){
                minDist = i;
            }
        }
    }

    return minDist;
}

//this function move the B by changing its coordinate to the closest location 
void motion(){
    int c = chose();
    B.position.x= move[c].position.x;
    B.position.y= move[c].position.y;
}