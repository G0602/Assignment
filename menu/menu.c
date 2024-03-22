#include "../glbl_vars.h"
#include "menu.h"
#include "../data/data.h"
#include "../initial/initial.h"

// ANSI escape codes for text color
#define ANSI_COLOR_YELLOW  "\x1b[33m"
#define ANSI_COLOR_RESET   "\x1b[0m"

int seed; //seed value for the ran function
int n; // to see the details of the Es
bool s; // for returning to menu
char *temp; //to store the temperory pointer values

bool mainMenu(void){

    int mo1;// main menu option

    top:

    printf("Main Menu:\n");
    printf("\t1. Start Simulation\n");
    printf("\t2. View Instructions\n");
    printf("\t3. Simulation Statistics\n");
    printf("\t4. Exit\n\n");
    printf("Enter Your Choice: ");
    scanf("%d", &mo1);

    switch(mo1){
        case 1: s = opt1();
                if (s == 1){
                    s = 0;
                    goto top;
                }
                return 0;// this will start the simulation
        case 2: opt2();
                goto top;
        case 3: opt3();
                goto top;
        case 4: return 1; //this will exit the programm

        default  : printf("\nWrong entry please enter the correct number.\n");
                goto top;
    }
}

bool opt1(void){

    int mo2;// simulation option

    middle:

    printf("Simulation Options:\n");
    printf("\t1. Setup\n");
    printf("\t2. Run Simulation\n");
    printf("\t3. Go back\n\n");
    printf("Enter Your Choice: ");
    scanf(" %d", &mo2);
    switch(mo2){
        case 1: s = subMenu();
                if (s == 1){
                    s = 0;
                    return 1;
                }
                goto middle;
        case 2: return 0;

        case 3: return 1;

        default  : printf("\nWrong entry please enter the correct number.\n");
                goto middle;
    }
}

void opt2(void){

    printf("\nNaval Battle Simulator Instructions\n\n");
    
    printf("Initialization\n");
    printf("    Upon launching, the simulator will display the main menu, providing options to initialize the battlefield, simulate battles, and explore additional features.\n");
    printf("    Enter the required parameters as prompted, including:\n");
    printf("        The size of the canvas area (D), specifying the square dimension of the battlefield.\n");
    printf("        The number of escort ships present on the battlefield (N).\n");
    printf("        Details of the battleship (B) and each escort ship (E) including:\n");
    printf("            Maximum and minimum vertical angles.\n");
    printf("            Maximum shell velocity.\n");
    printf("            Type of each escort ship.\n");
    printf("            Initial positions of the battleship and escort ships.\n\n");

    printf("Simulating the Battle\n");
    printf("    Once initialization is complete, the simulator will simulate the naval battle based on the provided conditions. Those conditions can be randomly generated or inputted by the user.\n");
    printf("    The battlefield has D=1000, N=1000 as the default values, but the user can change them if they want.\n");
    printf("    The battleship (B) will attempt to destroy as many escort ships (E) as possible while minimizing damage from enemy attacks.\n\n");

    printf("Simulation Results\n");
    printf("    After the simulation concludes, you will receive detailed information about the outcome of the battle.\n");
    printf("    If the battleship is sunk during the simulation, the index number of the escort ship responsible will be displayed.\n");
    printf("    Details of all escort ships hit by the battleship, including index, time of impact, and any other relevant information, will be provided.\n");
    printf("    The final conditions of the battlefield will be saved to a text file for reference.\n\n");

    printf("Exploring Additional Features\n");
    printf("    The simulator includes various features to enhance the simulation experience.\n");
    printf("    Users can explore different scenarios by adjusting initial conditions and parameters.\n\n");

    printf("Exiting the Simulator\n");
    printf("    You can exit the simulator by selecting the Exit option in the main menu.\n");
    printf(ANSI_COLOR_YELLOW);
    printf("!!!!!!!!!!Displays past simulation results by accessing text files. Each text file will be shown using vi or vim, and users can quit using :q.!!!!!!!!!!\n");
    printf("!!!!!!!!!!I have written this proggram using some linux terminal commands so this might not work on windows or mac.!!!!!!!!!!\n");
    printf(ANSI_COLOR_RESET);

    printf("\n\n");
}

//function to display files and select them
void opt3(void){
    temp = btlList();
    if (temp != NULL){
        selBtl(temp);
        temp = NULL;
    }
}


bool subMenu(void){
    last:
    int smo = 0;// sub menu option
    printf("Setup Options:\n");
    printf("\t1. Battle ship Properties\n");
    printf("\t2. Escort ship Properties\n");
    printf("\t3. Seed value\n");
    printf("\t4. Change settigs\n");
    printf("\t5. Go back\n");
    printf("\t6. Return to Main Menu\n\n");
    printf("Enter Your Choice: ");
    scanf(" %d", &smo);
    switch(smo){
        case 1: B_Dtl( stdout);
                break;

        case 2: printf("Enter the number of the escort ship you want to see the details of (1 - %d).\nEnter 0 if you want to see the details of all the escort ships: ", N);
                scanf(" %d", &n);
                for(int i = 0; i < N; i++){
                    if(i != n-1 && n != 0){
                        continue;
                    }
                    E_Dtl(i, stdout);
                }
                break;

        case 3: printf("Enter the new seed value for the random number generator:\n");
                scanf("%d", &seed);
                srand(seed);
                break;

        case 4: getInfo();
                break;

        case 5: break;

        case 6: return 1;

        default: printf("\nWrong entry please enter the correct number.\n");
                goto last;
    }
    return 0;
}