//this file contains the functions related to assigning random values to B and E and other variables and printing the initial values befor battle

#include "../random/random.h"
#include "initial.h"
#include"../glbl_vars.h"
#include "../data/data.h"
#include "../canvas/canvas.h"

int type =1;//to get the user input,default is 1

//function to get the initial condition and save it in a text file called initial.txt
void initialCond(bool in){

    char command[7 + strlen(name)];//making a string  named command based on the length of the battle name
    sprintf(command, "%s%s","mkdir ", name );
    system (command);

    // to change the working directory into battle_info
    if (chdir(name) != 0) {
        perror("Error changing directory");
        return ;
    }

    FILE *file = fopen("initial.txt", "w");
    if (file == NULL) {
        printf("Error opening/creating the file initial.txt.\n");
    }

    k = ranNum(0,D);
    t = ranNum(0,k);

    //randomly generted values for B's properties
    B.vel.max = ranNum(180,200);
    B.ang.max = 90;
    B.ang.min = 0;

    if (in == 1){
        type_choice:
        printf("\n\t1.USS Iowa (BB-61)\n\t2.MS King George V\n\t3.Richelieu\n\t4.Sovetsky Soyuz-class\n");
        printf("\nEnter the type of the battle ship you want to observe from the list above:");
        scanf("%d", &type);
    }

    switch(type){
        case 1: B.type = 'U';
				strcpy(B.shpName, "USS Iowa (BB-61)");
                B.loadTime = 0.5;
                break;
        case 2: B.type = 'M';
				strcpy(B.shpName, "MS King George V");
                B.loadTime = 0.6;
                break;
        case 3: B.type = 'R';
				strcpy(B.shpName, "Richelieu");
                B.loadTime = 0.55;
                break;
        case 4: B.type = 'S';
				strcpy(B.shpName, "Sovetsky Soyuz-class");
                B.loadTime = 0.48;
                break;
        default: printf("\nNot a valid type.Chose again.\n");
                type = 0;
                goto type_choice;// fail safe
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
                E[i].loadTime = 1.00;
				strcpy(E[i].shpName, "1936A-class Destroyer");
                break;
        case 1: E[i].type = 'B';
                E[i].angRange = 30;
                E[i].ip = 6;
                E[i].loadTime = 1.05;
				strcpy(E[i].shpName, "Gabbiano-class Corvette");
                break;
        case 2: E[i].type = 'C';
                E[i].angRange = 25;
                E[i].ip = 7;
                E[i].loadTime = 1.18;
				strcpy(E[i].shpName, "Matsu-class Destroye");
                break;
        case 3: E[i].type = 'D';
                E[i].angRange = 50;
                E[i].ip = 5;
                E[i].loadTime = 1.20;
				strcpy(E[i].shpName, "F-class Escort Ships");
                break;
        case 4: E[i].type = 'E';
                E[i].angRange = 70;
                E[i].ip = 4;
                E[i].loadTime = 1.15;
				strcpy(E[i].shpName, "Japanese Kaibōkan");
                break;
        }

        if(E[i].type == 'A'){
            E[i].vel.max = ranNum(100 ,1.2*B.vel.max);
        } else {
            E[i].vel.max = ranNum(100 ,B.vel.max);
        }
    
        E[i].vel.min = ranNum(10 ,E[i].vel.max);
        E[i].ang.min = ranNum(0, 90 - E[i].angRange);
        E[i].ang.max = E[i].ang.min + E[i].angRange;
        E[i].position.x = ranNum(0,D);
        E[i].position.y = ranNum(0,D);
        snprintf(E[i].indexNum, sizeof(E[i].indexNum), "E%c%03d", E[i].type, i + 1);
    
    }   
   
    prntDtl(file);

    fclose(file);

    // to change the working directory into battle_info
    if (chdir("..") != 0) {
        perror("Error changing directory");
        return ;
    }
}

void getInfo(void){
      do{
    printf("\nEnter the size of the battle field: ");
    scanf("%d", &D);

    printf("\nEnter the number of the escort ships you want to have in this simulation: ");
    scanf("%d", &N);

    if(D <= 0 || N <= 0){
        printf("\nThe vlues you just enterd are not valid.\nPlease make sure they bothe are integer greater than 0.\n");
    }

    }while(D <= 0 || N <= 0);

    initialCond(1);//save ititial condition after changes
    location();//to generate new loctions after changes
}