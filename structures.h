#ifndef STRUCTURES_H
#define STRUCTURES_H

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
    point position;// coordinate of the B in the canvas
    char type;// type of B
    int vMax;
    bool status;//if sgttus is 1 the ship is fine if it's 0 the the ship is destroyed
} btlShp;

// defining the structure of the  escort ships
typedef struct {
    point position;// coordinate of the E in the canvas
    char type; // type of the E
    int angRange; //the vertical range of the E
    int vMax;
    int vMin;
    int angMax;
    int angMin;
    bool status;//if sgttus is 1 the ship is fine if it's 0 the the ship is destroyed
    char indexNum[7];// for the unique ship identifiyer
} escShp;

#endif