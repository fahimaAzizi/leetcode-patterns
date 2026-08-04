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


# Problem #2 - Contains Duplicate

## Pattern
Arrays + Hash Set

## Key Idea
Use a hash set to keep track of numbers you've already seen.
If a number is already in the set, a duplicate exists.

## Algorithm
1. Create an empty hash set.
2. Traverse the array.
3. If the current number already exists in the set, return true.
4. Otherwise, insert it into the set.
5. If the loop finishes, return false.

## Time Complexity
O(n)

## Space Complexity
O(n)



# Problem #3 - Best Time to Buy and Sell Stock

## Pattern
Arrays + Greedy

## Key Idea
Keep track of the lowest stock price seen so far.
For each new price, calculate the profit if you sold today.
Update the maximum profit whenever you find a better one.

## Algorithm
1. Store the first price as the minimum price.
2. Traverse the array once.
3. Update the minimum price if a lower price is found.
4. Calculate today's profit.
5. Update the maximum profit.

## Time Complexity
O(n)

## Space Complexity
O(1)