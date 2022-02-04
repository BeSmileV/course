#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>

#include "libs/data_structures/vector/vector.h"

int main() {
    vector a = createVector(2);
    reserve(&a, SIZE_MAX);

    return 0;
}