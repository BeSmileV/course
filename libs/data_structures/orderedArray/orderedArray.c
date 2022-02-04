#include "orderedArray.h"

ordered_array_set ordered_array_set_create(size_t capacity) {
    return (ordered_array_set) {malloc(sizeof(int) * capacity), 0, capacity};
}

ordered_array_set ordered_array_set_create_from_array(const int *a, size_t size) {
    ordered_array_set set = ordered_array_set_create(size);
    int *copy = malloc(sizeof(int) * size);
    memcpy(copy, a, sizeof(int) * size);
    qsort(copy, size, sizeof(int), cmp_ints);
    if (size != 0) {
        for (size_t i = 0; i < size - 1; i++)
            if (copy[i] != copy[i + 1])
                set.data[set.size++] = copy[i];

        set.data[set.size++] = copy[size - 1];
    }

    return set;
}

size_t ordered_array_set_in(ordered_array_set *set, int value) {
    return binarySearch_(set->data, set->size, value);
}

bool ordered_array_set_isEqual(ordered_array_set set1, ordered_array_set set2) {
    assert(set1.size == set2.size);
    for (size_t i = 0; i < set1.size; i++)
        if (set1.data[i] != set2.data[i])
            return false;

    return true;
}

bool ordered_array_set_isSubset(ordered_array_set subset, ordered_array_set set) {
    assert(subset.size != 0);
    size_t index = ordered_array_set_in(&set, subset.data[0]);
    if (index + subset.size <= set.size) {
        for (size_t i = 0; i < subset.size; i++)
            if (subset.data[i] != set.data[index++])
                return false;
        return true;
    } else
        return false;
}

void ordered_array_set_isAbleAppend(ordered_array_set *set) {
    assert(set->size < set->capacity);
}

void ordered_array_set_insert(ordered_array_set *set, int value) {
    ordered_array_set_isAbleAppend(set);
    assert(ordered_array_set_in(set, value) == set->size);
    append_(set->data, &set->size, value);
    size_t iRead = set->size - 1;
    while (set->data[iRead] < set->data[iRead - 1] && iRead > 0) {
        swap(&set->data[iRead], &set->data[iRead - 1]);
        iRead--;
    }
}

void ordered_array_set_deleteElement(ordered_array_set *set, int value) {
    size_t indexOfElement = ordered_array_set_in(set, value);
    assert(indexOfElement != set->size);
    deleteByPosSaveOrder_(set->data, &set->size, indexOfElement);
}

ordered_array_set ordered_array_set_union(ordered_array_set set1, ordered_array_set set2) {
    ordered_array_set unionSet = ordered_array_set_create(set1.capacity + set2.capacity);
    mergeOfUniqueElement(set1.data, set1.size, set2.data, set2.size, unionSet.data, &unionSet.size);

    return unionSet;
}

ordered_array_set ordered_array_set_intersection(ordered_array_set set1, ordered_array_set set2) {
    size_t index1 = 0;
    size_t index2 = 0;
    ordered_array_set intersectionSet = ordered_array_set_create(max2(set1.size, set2.size));
    while (index1 < set1.size && index1 < set2.size)
        if (set1.data[index1] < set2.data[index2])
            index1++;
        else if (set1.data[index1] > set2.data[index2])
            index2++;
        else {
            append_(intersectionSet.data, &intersectionSet.size, set1.data[index1++]);
            index2++;
        }

    return intersectionSet;
}

ordered_array_set ordered_array_set_difference(ordered_array_set set1, ordered_array_set set2) {
    size_t index1 = 0;
    size_t index2 = 0;
    ordered_array_set difSet = ordered_array_set_create(set1.size);
    while (index1 < set1.size && index2 < set2.size)
        if (set1.data[index1] < set2.data[index2])
            append_(difSet.data, &difSet.size, set1.data[index1++]);
        else if (set1.data[index1] > set2.data[index2])
            index2++;
        else {
            index1++;
            index2++;
        }

    if (index1 < set1.size)
        for (size_t i = index1; i < set1.size; i++)
            append_(difSet.data, &difSet.size, set1.data[index1++]);

    return difSet;
}

ordered_array_set ordered_array_set_symmetricDifference(ordered_array_set set1, ordered_array_set set2) {
    size_t index1 = 0;
    size_t index2 = 0;
    ordered_array_set difSet = ordered_array_set_create(set1.size + set2.size);
    while (index1 < set1.size && index2 < set1.size)
        if (set1.data[index1] < set2.data[index2])
            append_(difSet.data, &difSet.size, set1.data[index1++]);
        else if (set1.data[index1] > set2.data[index2])
            append_(difSet.data, &difSet.size, set2.data[index2++]);
        else {
            index1++;
            index2++;
        }

    if (index1 < set1.size)
        for (size_t i = index1; i < set1.size; i++)
            append_(difSet.data, &difSet.size, set1.data[index1++]);
    else if (index2 < set2.size)
        for (size_t i = index2; i < set2.size; i++)
            append_(difSet.data, &difSet.size, set2.data[index2++]);

    return difSet;
}

ordered_array_set ordered_array_set_complement(ordered_array_set set, ordered_array_set universumSet) {
    ordered_array_set dif = ordered_array_set_difference(universumSet, set);

    return ordered_array_set_union(set, dif);
}

void ordered_array_set_print(ordered_array_set set) {
    printf("{");
    for (int i = 0; i < set.size; i++) {
        printf("%d, ", set.data[i]);
    }
    if (set.size == 0)
        printf("}\n");
    else
        printf("\b\b}\n");
}

void ordered_array_set_delete(ordered_array_set set) {
    free(set.data);
}

