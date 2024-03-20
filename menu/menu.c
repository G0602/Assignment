#include <stdio.h> 
#include "../glbl_vars.h"
#include "menu.h"

int mo;// menu option
int smo;// sub menu option
int n; // to see the details of the Es

void mainMenu(void){
    printf("Main Menu:\n");
    printf("\t1. Start Simulation\n");
    printf("\t2. View Instructions\n");
    printf("\t3. Simulation Statistics\n");
    printf("\t4. Exit\n\n");

    printf("Enter Your Choice: ");
    scanf("%d", &mo);

    switch(mo){
        case 1: opt1();
                break;
        case 2: opt2();
                break;
        case 3: opt3();
                break;
        case 4: opt4();
                break;
        default  : ;//default option
    }
}

void opt1(void){
    mo = 0;
    printf("Simulation Options:\n");
    printf("\t1. Setup\n");
    printf("\t2. Run Simulation\n\n");
    printf("Enter Your Choice: ");
    scanf("%d", &mo);
    switch(mo){
        case 1: subMenu();
                break;
        case 2: return;
        default  : ;//default option
    }
}

void opt2(void){
    printf("Upcomming cange");
}

void opt3(void){
    //function to display files and select them
}

void opt4(void){
    //exit function
}

void subMenu(void){
    smo = 0;
    printf("Setup Options:\n");
    printf("\t1. Battleship Properties\n");
    printf("\t2. Escort ships Settings\n");
    printf("\t3. Seed value\n");
    printf("\t4. Return to Main Menu\n\n");
    printf("Enter Your Choice: ");
    scanf("%d", &smo);
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
        default  : ;//default option
    }
}