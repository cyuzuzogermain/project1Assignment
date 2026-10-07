# Delivery Analysis Program

## Sample Input/Output

**Input:**
```
Enter number of routes (max 100): 5
Enter 5 distances (km):
12 25 8 30 15
Enter distance limit (km): 20
```

**Output:**
```
===== DELIVERY DISTANCE ANALYSIS =====

Total distance: 90 km
Average distance: 18.00 km
Longest route: 30 km
Routes above 20 km: 2

Recursive sum: 90 km

--- Function Reuse Demonstration ---
Routes above 10 km (half limit): 4
(Used count_above_limit() again with a different argument)
```

---

## How the Program is Divided into Functions

The program is structured into five distinct functions, each with a single responsibility:

| Function | Purpose |
|---|---|
| `total_distance()` | Iterates through the array and sums all distances |
| `average_distance()` | Calls `total_distance()` and divides by `n` to compute the mean |
| `longest_route()` | Finds and returns the maximum value in the array |
| `count_above_limit()` | Counts how many distances exceed a given limit |
| `recursive_sum()` | Recursively computes the sum of the first `n` elements |
| `main()` | Handles input, calls all analysis functions, and displays results |

The functions demonstrate **function reuse** in two ways:
- `average_distance()` calls `total_distance()` internally rather than duplicating its logic.
- `count_above_limit()` is called twice in `main()` with different limit arguments (the original limit and half the limit).

---

## How the Recursive Function Works

The function `recursive_sum(int distances[], int n)` computes the sum of the first `n` elements of the array using recursion:

- **Base case:** When `n == 0`, there are no elements left to sum, so the function returns `0`. This stops the recursion.

- **Recursive step:** When `n > 0`, the function returns `distances[n - 1] + recursive_sum(distances, n - 1)`. It adds the last element of the current sub-array to the result of a recursive call with `n - 1`, reducing the problem size by one on each call.

**Example trace** for `distances = [12, 25, 8, 30, 15]` and `n = 5`:

```
recursive_sum([12,25,8,30,15], 5)
= 15 + recursive_sum([12,25,8,30,15], 4)
= 15 + 30 + recursive_sum([12,25,8,30,15], 3)
= 15 + 30 + 8 + recursive_sum([12,25,8,30,15], 2)
= 15 + 30 + 8 + 25 + recursive_sum([12,25,8,30,15], 1)
= 15 + 30 + 8 + 25 + 12 + recursive_sum([12,25,8,30,15], 0)
= 15 + 30 + 8 + 25 + 12 + 0
= 90
```

---

## Advantage and Limitation of Using Recursion for This Problem

**Advantage:**
Recursion produces clean, concise code that closely mirrors the mathematical definition of a sum (e.g., "the sum of n elements is the last element plus the sum of the remaining n-1 elements"). This makes the logic easy to read and reason about for problems that have a naturally recursive structure.

**Limitation:**
Each recursive call adds a new frame to the call stack. For large arrays (e.g., thousands of elements), this can consume significant stack memory and eventually cause a stack overflow. An iterative loop uses constant stack space and is more efficient and safer for large inputs. For small inputs like those in this program, the overhead is negligible, but it is a real concern at scale.
