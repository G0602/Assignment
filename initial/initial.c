#include "../random/random.h"
#include "initial.h"
#include"../glbl_vars.h"
#include "../data/data.h"

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

        // error handeling
        if (E == NULL) {
            printf("Memory allocation failed!\n");
            return; 
        }

        //randomly generted values for B's properties
        B.vMax = ranNum(180,200);
        B.angMax = 90;
        B.angMin = 0;
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
        B.position.x = ranNum(0,D);
        B.position.y = ranNum(0,D);
        B.hp = 100;
        B.status = 1;

        //randomly generted values for Es' properties
        for(int i = 0; i < N; i++){
            E[i].status = 1;
            switch(ranNum(0,4)){
            case 0: E[i].type = 'A';
                    E[i].angRange = 20;
                    E[i].ip = 8;
                    break;
            case 1: E[i].type = 'B';
                    E[i].angRange = 30;
                    E[i].ip = 6;
                    break;
            case 2: E[i].type = 'C';
                    E[i].angRange = 25;
                    E[i].ip = 7;
                    break;
            case 3: E[i].type = 'D';
                    E[i].angRange = 50;
                    E[i].ip = 5;
                    break;
            case 4: E[i].type = 'E';
                    E[i].angRange = 70;
                    E[i].ip = 4;
                    break;
            }

            if(E[i].type == 'A'){
                E[i].vMax = ranNum(100 ,1.2*B.vMax);
            } else {
                E[i].vMax = ranNum(100 ,B.vMax);
            }
        
            E[i].vMin = ranNum(10 ,E[i].vMax);
            E[i].angMin = ranNum(0, 90 - E[i].angRange);
            E[i].angMax = E[i].angMin + E[i].angRange;
            E[i].position.x = ranNum(0,D);
            E[i].position.y = ranNum(0,D);
            snprintf(E[i].indexNum, sizeof(E[i].indexNum), "E%c%03d", E[i].type, i + 1);
        }
    }
   
    prntDtl(file);

    fclose(file);
}