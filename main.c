#include <stdio.h>
#include "records.h"
int main(void) {
    process_file("records.txt", "summary.txt");
    return 0;
}