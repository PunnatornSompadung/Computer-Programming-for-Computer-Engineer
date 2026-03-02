#include <stdio.h>

int KnapsackBT(int *weight_list, int *value_list, int total_items, int max_capacity, int current_index, int *result_array);

int main() {
    int total_items = 5;
    int max_capacity = 11;
    
    int weight_list[5] = { 1, 2, 5, 6, 7 };
    int value_list[5] = { 1, 6, 18, 22, 28 };
    
    int *result_array;
    int maximum_value;
    
    result_array = new int[total_items];
    
    maximum_value = KnapsackBT(weight_list, value_list, total_items, max_capacity, 0, result_array);
    
    printf("Value = %d\n", maximum_value);
    
    for (int index = 0; index < total_items; index++) {
        printf("%d ", result_array[index]);
    }
    
    return 0;
}

int KnapsackBT(int *weight_list, int *value_list, int total_items, int max_capacity, int current_index, int *result_array) {
    if (current_index == total_items) {
        return 0;
    }

    int *array_if_excluded = new int[total_items];
    int *array_if_included = new int[total_items];

    for (int copy_index = 0; copy_index < total_items; copy_index++) {
        array_if_excluded[copy_index] = 0;
        array_if_included[copy_index] = 0;
    }

    int value_if_excluded = KnapsackBT(weight_list, value_list, total_items, max_capacity, current_index + 1, array_if_excluded);

    int value_if_included = 0;
    if (max_capacity >= weight_list[current_index]) {
        int remaining_capacity = max_capacity - weight_list[current_index];
        value_if_included = value_list[current_index] + KnapsackBT(weight_list, value_list, total_items, remaining_capacity, current_index + 1, array_if_included);
    }

    int highest_value_found = 0;

    if (value_if_included > value_if_excluded) {
        highest_value_found = value_if_included;
        
        for (int update_index = current_index + 1; update_index < total_items; update_index++) {
            result_array[update_index] = array_if_included[update_index];
        }
        result_array[current_index] = 1;
        
    } else {
        highest_value_found = value_if_excluded;
        
        for (int update_index = current_index + 1; update_index < total_items; update_index++) {
            result_array[update_index] = array_if_excluded[update_index];
        }
        result_array[current_index] = 0;
    }

    delete[] array_if_excluded;
    delete[] array_if_included;

    return highest_value_found;
}