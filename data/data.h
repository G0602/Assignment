//this is the header file for data.c
//all the functions declared here are defined in data.c

#ifndef DATA_H
#define DATA_H

void prntDtl(FILE *file); // prints the detail of the current canvas to initial.txt file and the ships.defined in data.c
void B_Dtl( FILE *file); // prints the details of B to initial.txt file. defiend in data.c
void E_Dtl(int i, FILE *file); // prints the details of E to initial.txt file. defiend in data.c
char* btlList(void); //function to list all the past battles. defiend in data.c
void selBtl(char *btlPath); //function to open a file or a folder. defiend in data.c

#endif