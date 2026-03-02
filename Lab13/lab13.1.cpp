#include <stdio.h>

const int TOTAL_ITEMS = 5;
const int MAX_CAPACITY = 11;
const int ITEM_SELECTED = 1;
const int ITEM_NOT_SELECTED = 0;

int *KnapsackDP(int *weight_array, int *value_array, int item_count, int max_weight);

int main() {
    int item_count = TOTAL_ITEMS;
    int max_weight = MAX_CAPACITY;
    
    int weight_array[TOTAL_ITEMS] = { 1, 2, 5, 6, 7 };
    int value_array[TOTAL_ITEMS] = { 1, 6, 18, 22, 28 };
    
    int *selected_items;
    
    selected_items = KnapsackDP(weight_array, value_array, item_count, max_weight);
    
    for (int index = 0; index < item_count; index++) {
        printf("%d ", selected_items[index]);
    }
    
    return 0;
}

int *KnapsackDP(int *weight_array, int *value_array, int item_count, int max_weight) {
    
    int **dp_table = new int*[item_count + 1];
    
    for (int row = 0; row <= item_count; row++) {
        dp_table[row] = new int[max_weight + 1];
    }
    
    for (int current_item = 0; current_item <= item_count; current_item++) {
        for (int current_capacity = 0; current_capacity <= max_weight; current_capacity++) {
            
            if (current_item == 0 || current_capacity == 0) {
                dp_table[current_item][current_capacity] = 0;
            } 
            else if (weight_array[current_item - 1] <= current_capacity) {
                
                int include_value = value_array[current_item - 1] + dp_table[current_item - 1][current_capacity - weight_array[current_item - 1]];
                int exclude_value = dp_table[current_item - 1][current_capacity];
                
                if (include_value > exclude_value) {
                    dp_table[current_item][current_capacity] = include_value;
                } else {
                    dp_table[current_item][current_capacity] = exclude_value;
                }
                
            } 
            else {
                dp_table[current_item][current_capacity] = dp_table[current_item - 1][current_capacity];
            }
        }
    }
    
    int *result_array = new int[item_count];
    
    for (int init_idx = 0; init_idx < item_count; init_idx++) {
        result_array[init_idx] = ITEM_NOT_SELECTED;
    }
    
    int remaining_value = dp_table[item_count][max_weight];
    int remaining_capacity = max_weight;
    
    for (int check_item = item_count; check_item > 0; check_item--) {
        if (remaining_value <= 0) {
            break;
        }
        
        if (remaining_value != dp_table[check_item - 1][remaining_capacity]) {
            result_array[check_item - 1] = ITEM_SELECTED;
            remaining_value = remaining_value - value_array[check_item - 1];
            remaining_capacity = remaining_capacity - weight_array[check_item - 1];
        }
    }
    
    return result_array;
}