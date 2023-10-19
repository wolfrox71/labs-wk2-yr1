#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int *intArr;
    int numberEl;

    printf("Enter a num of elements:\n");
    scanf("%d", &numberEl);
    printf("Allocating %d elements\n", numberEl);

    intArr = (int*)malloc(numberEl * sizeof(int));

    if (intArr == NULL) {
        // memory hasnt been allocated successfully
        printf("Mem not allocated\n");
        exit(0);
    }
    printf("Mem success aloc\n");
    for (int i = 0; i < numberEl; printf("I: %d\n", i)) {
        intArr[i] = i++;
    }

    for (int i = 0; i < numberEl; printf("V: %d, I: %d\n", intArr[++i], i)) {   
    }
}