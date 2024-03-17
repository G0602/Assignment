#include "initial/initial.h"

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
    point position;
    char type;// type of B
    int vMax;
} btlShp;

// defining the structure of the  escort ships
typedef struct {
point position;
    char type;
    int angRange;
    int vMax;
    int vMin;
    int angMax;
    int angMin;
    char indexNum[7];
} escShp;

int main(){

    initialCond();

    return 0;
}