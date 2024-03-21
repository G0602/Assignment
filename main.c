#include "initial/initial.h"
#include "battle/battle.h"
#include "glbl_vars.h"
#include "canvas/canvas.h"
#include "data/data.h"

// defining following variables to be used in all other files and function
int D = 10;// Default value for D
int N = 10;// Default value for N
int k = 10;// Default value for k
int t = 5;// Default value for t
const char *path = "./battle_info";// to read and write data
btlShp B;
escShp *E;
Movement *move;

bool q = 0;// to decide whether to exit or not

int main(){
    int iteration=0; // the number of times the battle has happend
    E = (escShp*) malloc(N * sizeof(escShp));
    move = (Movement*) malloc(k * sizeof(Movement));

    do{

        genName(); // name the battle based on time
        initialCond();
        location();
        
        q = mainMenu();// if this return 1 the programm will close
        if(q == 1){
            continue;
        }
        
        do{
            battle(iteration + 1);
            motion();
            iteration++;
        } while((iteration < k) && (B.status == 1));

        if((iteration == k) && (B.status == 1)){
            printf("The Battle ship survived all iterations.\n\n");
        }

        printf("What would you like to do\n");


    } while (q == 0);

    free(E);
    free(move);

    return 0;
}