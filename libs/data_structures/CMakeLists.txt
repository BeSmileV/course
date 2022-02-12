add_library(data_structures
        bitset/bitset.c
        unorderedArray/unorderedArray.c
        orderedArray/orderedArray.c orderedArray/orderedArray.h
        vector/vector.c vector/vector.h
        vectorVoid/vectorVoid.c vectorVoid/vectorVoid.h
        matrix/matrix.c matrix/matrix.h)

target_link_libraries (data_structures algorithms)