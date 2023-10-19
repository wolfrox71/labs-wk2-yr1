#include <stdio.h>

#define leadingZeros 3
#define recersive 0

// from https://stackoverflow.com/questions/17250480/declaring-int-array-inside-struct
typedef struct Row{
    int* values;
    int length; 
} Row;

Row setupRow(Row oldRow);
Row setupBlankRow(int length);
void outputValuesFromRow(Row row);

void outputValuesNicely(Row row, int numberOfRows);