# Question 3: Functions & Recursion Explanation

### How the program is divided:
Instead of dumping all calculation logic into main(), the program is broken down into small, modular functions (calculate_total_distance, ind_longest_route, etc.). Each function handles exactly one mathematical responsibility. The main() function's only job is to declare the data, orchestrate calling those functions, and print the results.

### How the recursion works:
The ecursive_sum function takes an array of distances and its size 
. 
- **Base Case:** It checks if (n <= 0). If true, it returns 0 because an empty array has a sum of 0. This stops the recursion from running infinitely.
- **Recursive Step:** If not empty, it returns the value of the last element in the array (distances[n - 1]) added to the result of ecursive_sum called again, but this time with 
 - 1 (a smaller array). It keeps breaking the array down by 1 until it hits the base case.

### Pros and Cons of Recursion:
- **Advantage:** It makes complex problems (like traversing tree data structures or writing mathematical formulas) much shorter and cleaner to read compared to writing massive or or while loops.
- **Limitation:** It is heavy on memory. Every time the function calls itself, it adds a new frame to the Call Stack. If the array had 10,000 distances, the recursion would crash the program with a Stack Overflow error. Iterative loops don't have this problem.