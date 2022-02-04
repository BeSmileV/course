#include "bitset.h"

#define MAX_VALUE_OF_BITES 32


bitset bitset_create(unsigned maxValue) {
    assert(maxValue < MAX_VALUE_OF_BITES);
    return (bitset) {0, maxValue};
}

bool bitset_in(bitset set, unsigned int value) {
    return (set.values >> value) & 1;
}

bool bitset_isEqual(bitset set1, bitset set2) {
    return set1.values == set2.values &&
           set1.maxValue == set2.maxValue;
}

bool bitset_isSubset(bitset subset, bitset set) {
    return (set.values & subset.values) == subset.values;
}

void bitset_insert(bitset *set, unsigned int value) {
    assert(value <= set->maxValue);
    set->values |= (1 << value);
}

void bitset_deleteElement(bitset *set, unsigned int value) {
    assert(bitset_in(*set, value));
    set->values &= ~(1 << value);
}

bitset bitset_union(bitset set1, bitset set2) {
    assert(set1.maxValue == set2.maxValue);
    return (bitset) {set1.values | set2.values, set1.maxValue};
}

bitset bitset_intersection(bitset set1, bitset set2) {
    assert(set1.maxValue == set2.maxValue);
    return (bitset) {set1.values & set2.values, set1.maxValue};
}

bitset bitset_difference(bitset set1, bitset set2) {
    assert(set1.maxValue == set2.maxValue);
    return (bitset) {set1.values & ~set2.values, set1.maxValue};
}

bitset bitset_symmetricDifference(bitset set1, bitset set2) {
    assert(set1.maxValue == set2.maxValue);
    return (bitset) {set1.values ^ set2.values, set1.maxValue};
}

bitset bitset_complement(bitset set) {
    bitset complement = {~set.values, set.maxValue};
    for (uint32_t i = set.maxValue + 1; i < MAX_VALUE_OF_BITES; i++)
        bitset_deleteElement(&complement, i);

    return complement;
}

void bitset_print(bitset set) {
    printf("{");
    int isEmpty = 1;
    for (int i = 0; i <= set.maxValue; ++i) {
        if (bitset_in(set, i)) {
            printf("%d, ", i);
            isEmpty = 0;
        }
    }
    if (isEmpty)
        printf("}\n");
    else
        printf("\b\b}\n");
}
