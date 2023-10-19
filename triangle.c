#include <stdlib.h>
#include "triangle.h"
#include "row.h"


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

int main() {
    Row firstRow = setupBlankRow(1);
    firstRow.values[0] = 1;
    int numberOfRows = 10;
    Row previousRow = firstRow;
    Row currentRow;
    outputValuesNicely(firstRow, numberOfRows);
    for (int rowID = 0; rowID < numberOfRows-1; rowID++) {
        currentRow = calculateValues(previousRow);
        outputValuesNicely(currentRow, numberOfRows);
        previousRow = currentRow;
    }
    
}