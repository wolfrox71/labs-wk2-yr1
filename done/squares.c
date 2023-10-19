#include <stdio.h>
#include "squares.h"

void displayLine(int length, lineType type) {
    char full_char = '#';
    char empty_char = ' ';
    if (type == full) {
        for (int i = 0; i < length; i++) {
            printf("%c", full_char);
        }
    }
    else if (type == hollow) {
        if (length - 1 > 0) {
            printf("%c", full_char);
        }
        for (int i = 0; i < length-2; i++) {
            printf("%c", empty_char);
        }
        if (length - 2 > 0) {
            printf("%c", full_char);
        }
    }
    printf("\n");
}

void outputBox(int size, lineType boxType) {
    if (size >= 1) {
        displayLine(size, full);

        for (int i = 0; i < size-2; i++) {
            displayLine(size, boxType);
        }

        if (size >= 2) {
            displayLine(size, full);
        }
    }
}

int main() {
    int size = 6;
    outputBox(size,full);
    printf("\n------------------\n");
    outputBox(size, hollow);
}