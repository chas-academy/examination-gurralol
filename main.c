#include <stdio.h>
#include <ctype.h>
#include <string.h>

typedef struct {
    char name[10];
    int testScores[13];
    float avg;
} student;

int main() {
    student students[5];
    float avgTotal = 0.0;
    int maxAvg = 0;

    for (int i = 0; i < 5; i++) {
        //printf("Student %i name: ", i + 1);
        scanf("%s", students[i].name);
        
        for (int j = 0; j < 13; j++) {
            //printf("Student %i testscore %i: ", i + 1, j + 1);
            scanf("%i", &students[i].testScores[j]);
            students[i].avg += students[i].testScores[j];
        }
        students[i].avg = students[i].avg / 13;

        if (i != 0) {
            if (students[i].avg > students[maxAvg].avg) {
                maxAvg += 1;
            }
        }
    }

    for (int i = 0; i < 5; i++) {
        avgTotal += students[i].avg;
    }

    //printf("Student with highest average: %s", students[maxAvg].name);
    printf("%s", students[maxAvg].name);

    //printf("Students with lower average than total average: \n");
    for (int i = 0; i < 5; i++) {
        if (students[i].avg < avgTotal) {
            printf("%s\n", students[i].name);
        }
    }

    return 0;
}