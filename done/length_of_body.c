#include <stdio.h>

typedef struct {
    float height;
    float error;
    char *unit;
} person_height;

float getFemurLength(){
    float femurLength;

    printf("Enter femurLength in cm:\n");
    scanf("%f", &femurLength);

    return femurLength;
}

person_height calculateHeightFromFemur(float lengthOfFemur){
    float height = (2.38 * lengthOfFemur) + 61.41;
    float error = 3.27;
    person_height person = {height, error, "cm"};
    return person;
}

int main(){
    int height;
    float length = getFemurLength();
    person_height person = calculateHeightFromFemur(length);

    printf("The person is %.2f%s tall +- %.2f%s\n", person.height, person.unit, person.error, person.unit);

}