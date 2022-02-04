#include "unorderedArray.h"

unordered_array_set unordered_array_set_create(size_t capacity) {
    return (unordered_array_set) {malloc(sizeof(int) * capacity), 0, capacity};
}

unordered_array_set unordered_array_set_create_from_array(const int *a, size_t size) {
    unordered_array_set unorderedArray = unordered_array_set_create(size);
    if (size > 0)
        unorderedArray.data[unorderedArray.size++] = a[0];
    for (size_t i = 1; i < size; i++) {
        if (linearSearch_(a, i, a[i]) == i)
            unorderedArray.data[unorderedArray.size++] = a[i];
    }

    return unorderedArray;
}

size_t unordered_array_set_in(unordered_array_set *set, int value) {
    return linearSearch_(set->data, set->size, value);
}

bool unordered_array_set_isEqual(unordered_array_set set1, unordered_array_set set2) {
    if (set1.size != set2.size)
        return 0;
    qsort(set1.data, set1.size, sizeof(int), cmp_ints);
    qsort(set2.data, set2.size, sizeof(int), cmp_ints);
    return memcmp(set1.data, set2.data, sizeof(int) * set1.size) == 0;
}

void unordered_array_set_isAbleAppend(unordered_array_set *set) {
    assert(set->size < set->capacity);
}

void unordered_array_set_insert(unordered_array_set *set, int value) {
    unordered_array_set_isAbleAppend(set);
    if (unordered_array_set_in(set, value) == set->size)
        append_(set->data, &set->size, value);
}

void unordered_array_set_deleteElement(unordered_array_set *set, int value) {
    size_t indexDeletedElement = linearSearch_(set->data, set->size, value);
    assert(indexDeletedElement != set->size);
    deleteByPosUnsavedOrder_(set->data, &set->size, indexDeletedElement);
}

unordered_array_set unordered_array_set_union(unordered_array_set set1, unordered_array_set set2) {
    unordered_array_set unionSet = set1;
    unionSet.capacity += set2.size;
    for (size_t i = 0; i < set2.size; i++)
        if (unordered_array_set_in(&set1, set2.data[i]) == set1.size)
            unordered_array_set_insert(&unionSet, set2.data[i]);

    return unionSet;
}

unordered_array_set unordered_array_set_intersection(unordered_array_set set1, unordered_array_set set2) {
    unordered_array_set intersection = unordered_array_set_create(set1.size);
    for (size_t i = 0; i < set1.size; i++)
        if (unordered_array_set_in(&set2, set1.data[i]) != set2.size)
            unordered_array_set_insert(&intersection, set1.data[i]);

    return intersection;
}

unordered_array_set unordered_array_set_difference(unordered_array_set set1, unordered_array_set set2) {
    unordered_array_set intersection = unordered_array_set_create(set1.size);
    for (size_t i = 0; i < set1.size; i++)
        if (unordered_array_set_in(&set2, set1.data[i]) == set2.size)
            unordered_array_set_insert(&intersection, set1.data[i]);

    return intersection;
}

unordered_array_set unordered_array_set_symmetricDifference(unordered_array_set set1, unordered_array_set set2) {
    unordered_array_set difSet1 = unordered_array_set_difference(set1, set2);
    unordered_array_set difSet2 = unordered_array_set_difference(set2, set1);

    return unordered_array_set_union(difSet1, difSet2);
}

unordered_array_set unordered_array_set_complement(unordered_array_set set, unordered_array_set universumSet) {
    unordered_array_set dif = unordered_array_set_difference(universumSet, set);

    return unordered_array_set_union(set, dif);
}

void unordered_array_set_print(unordered_array_set set) {
    printf("{");
    int isEmpty = 1;
    for (int i = 0; i < set.size; i++) {
        printf("%d, ", set.data[i]);
    }
    if (set.size == 0)
        printf("}\n");
    else
        printf("\b\b}\n");
}

void unordered_array_set_delete(unordered_array_set set) {
    free(set.data);
}
