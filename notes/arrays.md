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


# Problem #4 - Move Zeroes

## Pattern
Arrays + Two Pointers

## Key Idea
Use two pointers:
- `right` scans every element.
- `left` keeps track of where the next non-zero element should go.

Whenever a non-zero element is found, swap it with the element at `left`, then move `left` forward.

## Algorithm
1. Set `left = 0`.
2. Traverse the array with `right`.
3. If `nums[right]` is not zero:
   - Swap `nums[left]` and `nums[right]`.
   - Increment `left`.
4. Continue until the end.

## Time Complexity
O(n)

## Space Complexity
O(1)



# Problem #5 - Running Sum of 1D Array

## Pattern
Arrays + Prefix Sum

## Key Idea
Each element becomes the sum of itself and all previous elements.

Instead of creating a new array, update the original array.

## Algorithm

1. Start from index 1.
2. Add the previous value to the current value.
3. Continue until the end.
4. Return the modified array.

## Time Complexity
O(n)

## Space Complexity
O(1)


# Problem #6 - Merge Sorted Array

## Pattern
Arrays + Two Pointers

## Key Idea
Merge the arrays from the end instead of the beginning.

Since nums1 already has extra space at the end,
start comparing the largest elements from both arrays
and place the larger one at the back.

## Algorithm

1. Set three pointers:
   - i = last valid element in nums1
   - j = last element in nums2
   - k = last position in nums1
2. Compare nums1[i] and nums2[j].
3. Place the larger value at nums1[k].
4. Move the corresponding pointer.
5. Copy any remaining elements from nums2.

## Time Complexity
O(m + n)

## Space Complexity
O(1)

# Problem #7 - Remove Duplicates from Sorted Array

## Pattern
Arrays + Two Pointers

## Key Idea
Because the array is already sorted, duplicate values are next
to each other.

Use two pointers:
- `right` searches through the array.
- `left` marks where the next unique value should be placed.

## Algorithm
1. Start `left` at index 1.
2. Move `right` through the array.
3. If the current value is different from the previous value,
   it is unique.
4. Put that value at `nums[left]`.
5. Move `left` forward.
6. Return `left`, which represents the number of unique values.

## Time Complexity
O(n)

## Space Complexity
O(1)

# Problem #8 - Pivot Index

## Pattern
Arrays + Prefix Sum

## Key Idea
Calculate the total sum of the array first.

For every index:
right sum = total sum - left sum - current value

If the left sum equals the right sum, we found the pivot index.

## Algorithm
1. Calculate the total sum of the array.
2. Start `leftSum` at 0.
3. For each index, calculate the right sum.
4. Compare left sum and right sum.
5. If they are equal, return the index.
6. Otherwise, add the current value to `leftSum`.
7. If no pivot exists, return -1.

## Time Complexity
O(n)

## Space Complexity
O(1)
# Problem #9 - Squares of a Sorted Array

## Pattern
Arrays + Two Pointers

## Key Idea
The largest square must come from either the most negative
number on the left or the largest positive number on the right.

Use two pointers and fill the result from the end.

## Algorithm
1. Set `left` at the beginning.
2. Set `right` at the end.
3. Compare the absolute values at both pointers.
4. Put the larger square at the end of the result.
5. Move the pointer that was used.
6. Continue until all positions are filled.

## Time Complexity
O(n)

## Space Complexity
O(n)

# Problem #10 - Product of Array Except Self

## Pattern
Arrays + Prefix/Suffix Products

## Key Idea
For each position, multiply the product of all elements
to its left by the product of all elements to its right.

Use one pass for prefix products and one pass for suffix products.

## Algorithm
1. Traverse from left to right and store the left product.
2. Traverse from right to left.
3. Multiply each answer by the right product.
4. Return the answer.

## Time Complexity
O(n)

## Space Complexity
O(1) extra space