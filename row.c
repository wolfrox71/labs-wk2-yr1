#include "row.h"
#include <stdlib.h>
#include <math.h>

Row setupRow(Row oldRow) {
    Row row;
    row.length = oldRow.length + 1;
    row.values = (int*)malloc(sizeof(int) * row.length);
    return row;
}

Row setupBlankRow(int length) {
    Row row;
    row.length = length;
    row.values = (int*)malloc(sizeof(int) * row.length);
    return row;
}

void outputValuesFromRow(Row row) {
    for (int i = 0; i < row.length; i++) {
        printf("%03d", row.values[i]);
        if (i < row.length-1) {
            printf(", ");
        }
    }
    printf("\n");
    return;
}

void outputValuesNicely(Row row, int numberOfRows) {
    
    // this outputs the values like outputValuesFromRow except it does it with padding
    // so it needs to know the max number of rows
    char fillerChar = ' ';
    int lengthOfLongestRow = ((numberOfRows*2)-2) + (leadingZeros+1) * numberOfRows;
    int lengthOfCurrentRow = ((row.length*2)-2) + (leadingZeros+1) * numberOfRows;    
    int offSetIndex = ((lengthOfLongestRow - lengthOfCurrentRow));

    for (int i = 0; i < offSetIndex; i++) {
        printf("%c", fillerChar);
    }
    for (int valID = 0; valID < row.length; valID++) {
        int nDigits = floor(log10(abs(row.values[valID]))) + 1; // from https://stackoverflow.com/questions/3068397/finding-the-length-of-an-integer-in-c
        
        if (nDigits == leadingZeros){
            printf("%d", row.values[valID]);
        }
        
        else if ((leadingZeros-nDigits) %2 == 0) { // if an odd  number of digit
            for (int i = 0; i < (leadingZeros-nDigits)/2; i++) { // has the padding on the front
                printf("%c", fillerChar);
            }
            printf("%d", row.values[valID]);
            for (int i = 0; i < ((leadingZeros-nDigits)/2); i++) { // has the padding on the end
                printf("%c", fillerChar);
            }
        }
        else if ((leadingZeros-nDigits) %2 == 1) { // if an odd  number of digit
            for (int i = 0; i < (leadingZeros-nDigits); i++) { // has the padding on the front
                printf("%c", fillerChar);
            }
            printf("%d", row.values[valID]);

        } 
        //printf("%03d", row.values[i]
        if (valID < row.length-1) { // if another digit is going to come later
            printf(" ");
        }
    }
    for (int i = 0; i< offSetIndex; i++) {
        printf("%c", fillerChar);
    }
    printf("\n");
}