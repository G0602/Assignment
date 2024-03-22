//this file contains the main function of this battle simulator

#include "initial/initial.h"
#include "battle/battle.h"
#include "glbl_vars.h"
#include "canvas/canvas.h"
#include "data/data.h"

// defining following variables to be used in all other files and function
int D = 1000;// initial value for D. these values will only be used if initialising them in initialCond function fail for some reason.
int N = 1000;// initial value for N. these values will only be used if initialising them in initialCond function fail for some reason.
int k = 1000;// initial value for k. these values will only be used if initialising them in initialCond function fail for some reason.
int t = 500;// initial value for t. these values will only be used if initialising them in initialCond function fail for some reason.
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

    system("clear");// to clear the command line

    // to change the working directory into battle_info
    if (chdir("battle_info") != 0) {
        perror("Error changing directory");
        return 1;
    }
    
    do{
        iteration=0;
        genName(); // name the battle based on time. defined in random.c
        initialCond(); //generating the initial conditions randomly. defined in initial.c
        location(); //this will generate the locations the B needs to move randomly. defined in canvas.c
        
        q = mainMenu();// if this function return 1 the programm will exit. defined in menu.c
        if(q == 1){
            continue;
        }
        
        printf("%s begins!!!!!!!!!\n", name);
        do{
            battle(iteration + 1);
            motion();
            iteration++;
        } while((iteration < k) && (B.status == 1));// the loop will break if the B get destroyed or it has visited all the loctions

        if((iteration == k) && (B.status == 1)){
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