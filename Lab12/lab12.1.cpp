#include <stdio.h>

const int INF_DISTANCE = 999999;
const int NO_PATH = -1;

int *Dijkstra(int *graph_matrix, int node_count);

int main() {
    int total_nodes = 5;
    int *shortest_paths;
    int *graph;
    
    graph = new int[total_nodes * total_nodes];
    
    for(int row = 0; row < total_nodes; row++) {
        for(int col = 0; col < total_nodes; col++) {
            graph[row * total_nodes + col] = NO_PATH;
        }
    }

    graph[0 * total_nodes + 1] = 100;
    graph[0 * total_nodes + 2] = 80;
    graph[0 * total_nodes + 3] = 30;
    graph[0 * total_nodes + 4] = 10;
    graph[1 * total_nodes + 2] = 20;
    graph[3 * total_nodes + 1] = 20;
    graph[3 * total_nodes + 2] = 20;
    graph[4 * total_nodes + 3] = 10;

    shortest_paths = Dijkstra(graph, total_nodes);
    
    for(int index = 0; index < total_nodes - 1; index++) {
        printf("%d ", shortest_paths[index]);
    }
        
    return 0;
}

int *Dijkstra(int *graph_matrix, int node_count) {
    int *distance = new int[node_count];
    int *is_visited = new int[node_count];
    int *final_result = new int[node_count - 1];
    
    for (int node_idx = 0; node_idx < node_count; node_idx++) {
        distance[node_idx] = INF_DISTANCE;
        is_visited[node_idx] = 0;
    }
    
    distance[0] = 0;
    
    for (int step = 0; step < node_count; step++) {
        int current_min_dist = INF_DISTANCE;
        int nearest_node = -1;
        
        for (int search_node = 0; search_node < node_count; search_node++) {
            if (is_visited[search_node] == 1) continue;
            if (distance[search_node] >= current_min_dist) continue;
            
            current_min_dist = distance[search_node];
            nearest_node = search_node;
        }
        
        if (nearest_node == -1) break;
        
        is_visited[nearest_node] = 1;
        
        for (int neighbor = 0; neighbor < node_count; neighbor++) {
            if (is_visited[neighbor] == 1) continue;
            
            int edge_weight = graph_matrix[nearest_node * node_count + neighbor];
            if (edge_weight == NO_PATH) continue;
            
            int calculated_dist = distance[nearest_node] + edge_weight;
            if (calculated_dist < distance[neighbor]) {
                distance[neighbor] = calculated_dist;
            }
        }
    }
    
    for (int result_idx = 1; result_idx < node_count; result_idx++) {
        final_result[result_idx - 1] = distance[result_idx];
    }
    
    return final_result;
}