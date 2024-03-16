#include <stdio.h>
#include <stdlib.h>
#include "random.h"
#include "initial.h"

//definig the location of the ships
typedef struct {
    int x;
    int y;
} point;


typedef struct {
   
// i'm planig to define a structure called type here

} Type;

// defining the structure of the  battle ships
typedef struct {
    point position;
    int type;
    float vMax;
} btlShp;

// defining the structure of the  escort ships
typedef struct {
point position;
    int type;
    float vMax;
    float vMin;
    float angMax;
    float angMin;
} escShp;

//function to get the initial condition and save it in a text file called initial.txt
void initialCond(void){

    int N,D;// N is for the number of escort ship and D is for the size of the battle field
    btlShp B;
    escShp E;

    FILE *file = fopen("initial.txt", "w");
    if (file == NULL) {
        printf("Error opening/creating the file initial.txt.\n");
    }


    printf("Enter the size of the battle field: ");
    scanf("%d", &D);

    printf("Enter the number of the escort ships you want to have in this simulation: ");
    scanf("%d", &N);
    
    printf("Enter the maximum velocity of the escort ships: ");
    scanf("%f", &E.vMax);
    
    printf("Enter the minimun velocity of the escort ships: ");
    scanf("%f", &E.vMin);

    printf("Enter the maximum angle of the escort ships: ");
    scanf("%f", &E.angMax);

    printf("Enter the minimum angle of the escort ships: ");
    scanf("%f", &E.angMin);

    printf("Enter the maximum velocity of the battle ship: ");
    scanf("%f", &B.vMax);

    fprintf(file, "canvasSize(D): %d\n", D);
    fprintf(file, "escortNum: %d\n", N);
    fprintf(file, "vMax: %.2f\n", E.vMax);
    fprintf(file, "vMin: %.2f\n", E.vMin);
    fprintf(file, "angMax: %.2f\n", E.angMax);
    fprintf(file, "angMin: %.2f\n", E.angMin);
    

    fclose(file);
}