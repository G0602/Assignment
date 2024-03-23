//this is the header file for battle.c
//all the functions declared here are defined in battle.c

#ifndef BATTLE_H
#define BATTLE_H

int battle(int it);
void rangeMinMax(int i);
float rangeF(int a, int v);
void canEAtk(int i);
void canBAtk(FILE *file);
float atkTime(int i);
int* choseTarget(void);
void swap(int* a, int* b);

#endif