#include <stdlib.h>
#include "triangle.h"
#include "row.h"
#include <time.h>

#if !recersive
Row calculateValues(Row oldRow) {
    //take in a array of ints as a row and then calculate the next row of values
    
    // caluclate how many bytes the array is and how many bytes the data 
    
    Row newRow = setupRow(oldRow);
    int oldRowLength = oldRow.length; // im assuming this is faster than checking a struct every cycle
    for (int i = 0; i < newRow.length; i++) {
        if (i == 0 || i == oldRowLength) {
            newRow.values[i] = 1;
        }
        else {
            //printf("Else %d; %d, %d\n", i, oldRow.values[i-1], oldRow.values[i]);
            newRow.values[i] = oldRow.values[i-1] + oldRow.values[i];
        }
    }

    return newRow;
}
#endif


#if recersive
Row CalcRowRec(Row oldRow, int num_rows) {
    outputValuesNicely(oldRow, num_rows);

    Row newRow = setupRow(oldRow);
    int oldRowLength = oldRow.length; // im assuming this is faster than checking a struct every cycle
    for (int i = 0; i < newRow.length; i++) {
        if (i == 0 || i == oldRowLength) {
            newRow.values[i] = 1;
        }
        else {
            //printf("Else %d; %d, %d\n", i, oldRow.values[i-1], oldRow.values[i]);
            newRow.values[i] = oldRow.values[i-1] + oldRow.values[i];
        }
    }

    if (newRow.length > num_rows){
        return newRow;
    }

    return CalcRowRec(newRow, num_rows);
}
#endif


int main() {
    int msec = 0, trigger = 10; /* 10ms */
    clock_t before = clock();
    Row firstRow = setupBlankRow(1);
    firstRow.values[0] = 1;
    int numberOfRows = 20;


    //code goes here
    
    #if recersive
    CalcRowRec(firstRow, numberOfRows);
    #endif
    
    # if !recersive
    Row previousRow = firstRow;
    Row currentRow;
    outputValuesNicely(firstRow, numberOfRows);
    for (int rowID = 0; rowID < numberOfRows-1; rowID++) {
        currentRow = calculateValues(previousRow);
        outputValuesNicely(currentRow, numberOfRows);
        previousRow = currentRow;
    }
    #endif

    clock_t difference = clock() - before;
    msec = difference * 1000 / CLOCKS_PER_SEC;
    printf("Time taken: %ld Cycles\nCPS: %ld CPS\nS:ms:  %d:%d\n",difference, CLOCKS_PER_SEC,msec/1000, msec%1000);
}