//this file contains the main function of this battle simulator

#include "initial/initial.h"
#include "battle/battle.h"
#include "glbl_vars.h"
#include "canvas/canvas.h"
#include "data/data.h"

// defining following variables to be used in all other files and function
int D = 1000;// initial value for D. this values will only be used if initialising them in initialCond function fail for some reason.
int N = 1000;// initial value for N. this values will only be used if initialising them in initialCond function fail for some reason.
int k = 1000;// initial value for k. this values will only be used if initialising them in initialCond function fail for some reason.
int t = 500; // initial value for t. this values will only be used if initialising them in initialCond function fail for some reason.
btlShp B; //this structure is defined in glbl_vars.h
escShp *E; //this structure is defined in glbl_vars.h
Movement *move; //this structure is defined in glbl_vars.h

bool q = 0;// to decide whether to exit or not

int main(){
    int iteration; // the number of times the battle has happend
    
    E = (escShp*) malloc(N * sizeof(escShp));// allocating dinamic memmory

    // error handeling
    if (E == NULL) {
        printf("Memory allocation failed!\n");
        return 1; 
    }

    move = (Movement*) malloc(k * sizeof(Movement));// allocating dinamic memmory

    // error handeling
    if (move == NULL) {
        printf("Memory allocation failed!\n");
        return 1; 
    }

    if (system("clear") != 0) {// to clear the terminal
    printf("Failed to clear the terminal window.\n");
    }

    // to change the working directory into battle_info
    check:
    if (chdir("battle_info") != 0) {
        if(system("mkdir battle_info"))//create the file if it doesn't exist
            return 1;// return if fail to create file
        goto check;
    }
    
    do{ //this loop will go on forever until user decide to exit or an error happen
        iteration=0;//for every new battles itterations resets
        genName(); // name the battle based on time. defined in random.c
        initialCond(0); //generating the initial conditions randomly. defined in initial.c
        location(); //this will generate the locations the B needs to move randomly. defined in canvas.c
        
        q = mainMenu();// if this function return 1 the programm will exit. defined in menu.c
        if(q == 1){
            break;
        }
        
        printf("%s begins!!!!!!!!!\n", name);
        do{
            if (battle(iteration + 1)){
                perror("battle function didn't work properly");
                exit (EXIT_FAILURE);
            }
            motion();
            iteration++;
        } while((iteration < k) && (B.status == 1));// the loop will break if the B get destroyed or it has visited all the loctions

        if(B.status == 1){
            printf("The Battle ship survived all iterations.\n\n");
        } else {
            printf("Better luck next time.\n\n");
        }

        printf("What would you like to do\n");


    } while (q == 0);

    free(E);
    free(move);

    return 0;
}