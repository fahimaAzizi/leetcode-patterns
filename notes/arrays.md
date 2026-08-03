# Problem #1 - Two Sum

## Pattern
Arrays + Hash Map

## Key Idea
Store previously seen numbers in a hash map.
For each number, calculate the complement (target - current).
If the complement already exists in the map, return both indices.

## Algorithm
1. Create an empty hash map.
2. Loop through the array.
3. Calculate the complement.
4. Check if the complement exists.
5. If yes, return the indices.
6. Otherwise, store the current number and index.

## Time Complexity
O(n)

## Space Complexity
O(n)