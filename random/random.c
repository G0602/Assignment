#include "random.h"
#include "../glbl_vars.h"

//to generate random number within a range
int ranNum(int min, int max) {
    return min + rand() % (max - min + 1);
}

char name[35]; // to store the name of the battle

//to generate names based on time
void genName(void) {
    time_t current_time;
    struct tm *timeinfo;
    char temp[20]; // to store the time as string

    // Get current time
    time(&current_time);
    timeinfo = localtime(&current_time);

    // Format time into a string
    strftime(temp, sizeof(temp), "%Y%m%d_%H%M%S", timeinfo);

    // Create filename using the formatted time
    snprintf(name, sizeof(name), "battle_%s.txt", temp);
}
