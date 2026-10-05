#include <stdio.h>

// User-defined functions
int calculate_total_distance(int distances[], int n) {
    int total = 0;
    for (int i = 0; i < n; i++) {
        total += distances[i];
    }
    return total;
}

float calculate_average_distance(int total, int n) {
    if (n == 0) return 0.0;
    return (float)total / n; 
}

int find_longest_route(int distances[], int n) {
    int max = distances[0];
    for (int i = 1; i < n; i++) {
        if (distances[i] > max) {
            max = distances[i];
        }
    }
    return max;
}

int count_routes_above_limit(int distances[], int n, int limit) {
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (distances[i] > limit) {
            count++;
        }
    }
    return count;
}

// Recursive function
int recursive_sum(int distances[], int n) {
    // Base case: if array size is 0, sum is 0
    if (n <= 0) {
        return 0;
    }
    // Reduce problem: add last element and call recursion for the rest
    return distances[n - 1] + recursive_sum(distances, n - 1);
}

int main() {
    int distances[] = {12, 25, 18, 40, 15, 30};
    int n = 6;
    int limit = 20;

    // Function reuse: we calculate total once, then pass it as an argument to average
    int total = calculate_total_distance(distances, n);
    float average = calculate_average_distance(total, n); 
    int longest = find_longest_route(distances, n);
    int above_limit = count_routes_above_limit(distances, n, limit);
    int r_sum = recursive_sum(distances, n);

    printf("===== DELIVERY DISTANCE ANALYSIS =====\n");
    printf("Total distance: %d km\n", total);
    printf("Average distance: %.2f km\n", average);
    printf("Longest route: %d km\n", longest);
    printf("Routes above %d km: %d\n\n", limit, above_limit);
    printf("Recursive sum: %d km\n", r_sum);

    return 0;
}