#include <stdio.h>
#include "records.h"
int main(void) {
    int idx = 5;
    int grade;
    int rr = parse_grade("Alice 85", &grade, &idx);
    printf("%d\n", grade);
    printf("%d\n", idx);
    printf("%d\n", rr);




    return 0;
}