#include <stdio.h>

#define MAX_ROUTES 100

/* Function prototypes */
int total_distance(int distances[], int n);
float average_distance(int distances[], int n);
int longest_route(int distances[], int n);
int count_above_limit(int distances[], int n, int limit);
int recursive_sum(int distances[], int n);

/*
 * Function: total_distance
 * -----------------------
 * Calculates the sum of all distances in the array.
 * Reused by: average_distance (calls this function internally),
 *            and demonstrates function reuse since the recursive
 *            sum is also compared against this total.
 */
int total_distance(int distances[], int n) {
    int total = 0;
    for (int i = 0; i < n; i++) {
        total += distances[i];
    }
    return total;
}

/*
 * Function: average_distance
 * ---------------------------
 * Calculates the average distance.
 * Reuses: total_distance() to get the sum, demonstrating
 *         function reuse (one function calling another).
 */
float average_distance(int distances[], int n) {
    if (n == 0) return 0.0f;
    return (float)total_distance(distances, n) / n;
}

/*
 * Function: longest_route
 * ------------------------
 * Returns the maximum distance in the array.
 */
int longest_route(int distances[], int n) {
    int max = distances[0];
    for (int i = 1; i < n; i++) {
        if (distances[i] > max) {
            max = distances[i];
        }
    }
    return max;
}

/*
 * Function: count_above_limit
 * ----------------------------
 * Counts how many routes have distance greater than `limit`.
 * Reused in main() with different limit values to demonstrate
 *         calling the same function more than once with different arguments.
 */
int count_above_limit(int distances[], int n, int limit) {
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (distances[i] > limit) {
            count++;
        }
    }
    return count;
}

/*
 * Function: recursive_sum
 * ------------------------
 * Recursively calculates the sum of the first n elements.
 *
 * Base case: n == 0  -> return 0  (no elements left to sum)
 * Recursive step: return distances[n-1] + recursive_sum(distances, n-1)
 *                  which reduces the problem size by 1 on each call.
 */
int recursive_sum(int distances[], int n) {
    if (n == 0) {
        return 0;                       /* base case */
    }
    return distances[n - 1] + recursive_sum(distances, n - 1);
}

int main(void) {
    int n;
    int distances[MAX_ROUTES];
    int limit;

    /* --- Input --- */
    printf("Enter number of routes (max %d): ", MAX_ROUTES);
    scanf("%d", &n);

    if (n <= 0 || n > MAX_ROUTES) {
        printf("Invalid number of routes.\n");
        return 1;
    }

    printf("Enter %d distances (km):\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &distances[i]);
    }

    printf("Enter distance limit (km): ");
    scanf("%d", &limit);

    /* --- Calculations --- */
    int total   = total_distance(distances, n);
    float avg   = average_distance(distances, n);
    int longest = longest_route(distances, n);
    int above   = count_above_limit(distances, n, limit);
    int rsum    = recursive_sum(distances, n);

    /* Demonstrate function reuse: call count_above_limit again
       with a different limit (e.g., half the original limit). */
    int above_half = count_above_limit(distances, n, limit / 2);

    /* --- Output --- */
    printf("\n===== DELIVERY DISTANCE ANALYSIS =====\n\n");
    printf("Total distance: %d km\n", total);
    printf("Average distance: %.2f km\n", avg);
    printf("Longest route: %d km\n", longest);
    printf("Routes above %d km: %d\n", limit, above);

    printf("\nRecursive sum: %d km\n", rsum);

    /* Demonstrate additional reuse */
    printf("\n--- Function Reuse Demonstration ---\n");
    printf("Routes above %d km (half limit): %d\n",
           limit / 2, above_half);
    printf("(Used count_above_limit() again with a different argument)\n");

    return 0;
}
