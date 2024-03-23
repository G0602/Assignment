//this file is for global variables and structures

#ifndef GLBL_VARS_H
#define GLBL_VARS_H

#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <dirent.h>
#include <unistd.h>

//definig a location in the canvas
typedef struct {
    int x;// x coordinate in the canvas
    int y;// y coordinate in the canvas
} Point;

//definig a location where B needs to move in the future
typedef struct {
    float dist; //distance from B's current location
    Point position; // position in the canvas
    bool visit;// tells about whether B already visited or not
} Movement;

typedef struct {
    float max; // to store the max value
    float min; // to store the min value
} Minmax;

// defining the structure of the  battle ships
typedef struct {
    Point position;// coordinate of the B in the canvas
    char type;// type of B
    char shpName[25];//name of B
    Minmax range; // minimum and maximum attack range of B, in kilo meter
    float maxVelMinRng; // minimum distance where B can fire at maximum shell velocity
    Minmax vel;// maximum and maximum velocity of B's shell, will be in meter per second
    Minmax ang;// miniun and maximum angle of B's gun, in degree
    bool status;//if status is 1 the ship is fine if it's 0 the the ship is destroyed
    int hp; // this indicates the health of the B. if this hits 0 that means the  ship has been destroyed
    float loadTime;//the time delay between 2 gun firings
} btlShp;

// defining the structure of the  escort ships
typedef struct {
    Point position;// coordinate of the E in the canvas
    char type; // type of E
    char shpName[25];//name of E
    int angRange; //the vertical range of the E, in degree
    Minmax vel;// maximum and maximum velocity of E's shell, will be in meter per second
    Minmax ang;// miniun and maximum angle of E's gun, in degree
    Minmax range; // attack range of E, in kilo meter
    float dist;// distance from the B
    bool status;//if status is 1 the ship is fine if it's 0 the the ship is destroyed
    int ip; // this idicates the impact power of the E. if E hits B this value will reduced from hp
    float loadTime;//the time delay between 2 gun firings
    char indexNum[7];// for the unique ship identifiyer
} escShp;

extern int N; // N is for the number of escort ships, defined in main.c
extern int D; // D is for the size of the battle field, in kilo meter, defined in main.c
extern int k; // k is for the number of locations B need to move, defined in main.c
extern int t; // to denote when the gun of B get stuck, defined in main.c
extern char name[35]; // to store the name of the battle. defined in random.c

extern btlShp B; //B is to indicate the battle ship, defined in main.c
extern escShp *E; //an escShp class pointer to store the memory address of escort ship structure, defined in main.c

extern Movement *move;// pointer to store the memory adress of the location where B needs to move, defined in main.c

extern bool mainMenu(void); //open the main menu of the programm. defiend in menu.c
extern void genName(void); // to create names for battles based on time. defined in random.c

#endif