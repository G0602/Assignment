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
    char type;
    float vMax;
} btlShp;

// defining the structure of the  escort ships
typedef struct {
point position;
    char type;
    float vMax;
    float vMin;
    float angMax;
    float angMin;
} escShp;

//function to get the initial condition and save it in a text file called initial.txt
void initialCond(void){

    int N,D;// N is for the number of escort ship and D is for the size of the battle field
    btlShp B;
    escShp *E;

    FILE *file = fopen("initial.txt", "w");
    if (file == NULL) {
        printf("Error opening/creating the file initial.txt.\n");
    }


    printf("Enter the size of the battle field: ");
    scanf("%d", &D);

    printf("Enter the number of the escort ships you want to have in this simulation: ");
    scanf("%d", &N);

    E = (int*) malloc(N * sizeof(escShp));

    // error handeling
    if (E == NULL) {
        printf("Memory allocation failed!\n");
        return; 
    }
    
    printf("Enter the maximum velocity of the escort ships: ");
    scanf("%f", &E.vMax);
    
    printf("Enter the minimun velocity of the escort ships: ");
    scanf("%f", &E.vMin);

    printf("Enter the minimum angle of the escort ships: ");
    scanf("%f", &E.angMin);

    printf("Enter the maximum velocity of the battle ship: ");
    scanf("%f", &B.vMax);

    printf("Enter the type of the battle ship you want to observe: ");
    scanf("%c", &B.type);


    fprintf(file, "canvasSize(D): %d\n", D);
    fprintf(file, "escortNum: %d\n", N);

    fprintf(file, "vMax_b: %.2f\n", B.vMAx);
    fprintf(file, "type_b: %c\n", B.type);

    fprintf(file, "vMax_e: %.2f\n", E.vMax);
    fprintf(file, "vMin_e: %.2f\n", E.vMin);
    fprintf(file, "angMin: %.2f\n", E.angMin);
    //fprintf(file, "angMax: %.2f\n", E.angMin + //need to figure oute);


    fclose(file);
}