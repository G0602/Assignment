//this file is for global variables and structures

#ifndef GLBL_VARS_H
#define GLBL_VARS_H

#include <stdbool.h>
//definig the location of the ships
typedef struct {
    int x;
    int y;
} Point;

typedef struct {
    float max;
    float min;
} Minmax;

// defining the structure of the  battle ships
typedef struct {
    Point position;// coordinate of the B in the canvas
    char type;// type of B
    Minmax range; // attack range of B, in kilo meter
    int vMax;// maximum velocity of B's shell, will be in meter per second
    bool status;//if sgttus is 1 the ship is fine if it's 0 the the ship is destroyed
} btlShp;

// defining the structure of the  escort ships
typedef struct {
    Point position;// coordinate of the E in the canvas
    char type; // type of the E
    int vMax;// maximum velocity of E's shell, will be in meter per second
    int vMin;// minimum velocity of E's shell, will be in meter per second
    int angRange; //the vertical range of the E, in degree
    int angMax;// maximum angle of E's gun, in degree
    int angMin;// minimum angle of E's gun, in degree
    Minmax range; // attack range of E, in kilo meter
    float dist;// distance from the B
    bool status;//if status is 1 the ship is fine if it's 0 the the ship is destroyed
    char indexNum[7];// for the unique ship identifiyer
} escShp;

extern int N; // N is for the number of escort ships
extern int D; // D is for the size of the battle field, in kilo meter

extern btlShp B; //B is to indicate the battle ship
extern escShp *E; //an escShp class pointer to be used as a pointer


#endif