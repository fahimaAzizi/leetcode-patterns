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


# Problem #11 - Maximum Subarray

## Pattern
Arrays + Kadane's Algorithm

## Key Idea
At every element, decide whether it is better to:
1. Start a new subarray from the current element, or
2. Continue the previous subarray.

If the previous sum becomes harmful, start again.

## Algorithm
1. Store the first number as `currentSum`.
2. Store it as the initial `maxSum`.
3. For every next number:
   - Compare the current number with `currentSum + current number`.
   - Keep the larger value.
4. Update `maxSum`.
5. Return `maxSum`.

## Time Complexity
O(n)

## Space Complexity
O(1)
# Problem #12 - Best Time to Buy and Sell Stock II

## Pattern
Arrays + Greedy

## Key Idea
Take every positive price increase.

If today's price is higher than yesterday's price,
we can capture that increase as profit.

## Algorithm
1. Start with profit = 0.
2. Compare each price with the previous price.
3. If today's price is higher, add the difference to profit.
4. Continue until the end.
5. Return the total profit.

## Example

prices = [7,1,5,3,6,4]

1 -> 5 gives +4
3 -> 6 gives +3

Total = 7

## Time Complexity
O(n)

## Space Complexity
O(1)

# Problem #13 - Majority Element

## Pattern
Arrays + Boyer-Moore Voting Algorithm

## Key Idea
Keep a candidate and a count.

When the current number matches the candidate, increase
the count.

When it is different, decrease the count.

If the count reaches zero, choose the next number as the
new candidate.

Because the majority element appears more than n/2 times,
it will remain as the final candidate.

## Algorithm
1. Start with count = 0.
2. If count is 0, make the current number the candidate.
3. If the current number equals the candidate, increase count.
4. Otherwise, decrease count.
5. Return the final candidate.

## Time Complexity
O(n)

## Space Complexity
O(1)

# Problem #14 - Missing Number

## Pattern
Arrays + XOR

## Key Idea
Numbers from 0 to n should all appear once except one number.

XOR has an important property:

x ^ x = 0

and

x ^ 0 = x

So when we XOR all expected numbers with all numbers
actually present, the matching numbers cancel out and
the missing number remains.

## Algorithm
1. Start with `result = n`.
2. XOR every index with `result`.
3. XOR every array value with `result`.
4. All matching values cancel each other.
5. The remaining value is the missing number.

## Example

nums = [3,0,1]

Expected numbers:
0,1,2,3

Present numbers:
3,0,1

After XOR cancellation:

Answer = 2

## Time Complexity
O(n)

## Space Complexity
O(1)

# Problem #15 - Find All Numbers Disappeared in an Array

## Pattern
Arrays + In-Place Hashing

## Key Idea
Every number is between 1 and n, so each number can be
mapped to an array index.

For each number:
- Convert it to an index using `abs(num) - 1`.
- Mark that index as visited by making its value negative.

After marking:
- Positive positions represent numbers that never appeared.

## Algorithm
1. Loop through every number.
2. Convert the number to its corresponding index.
3. Make the value at that index negative.
4. Loop through the array again.
5. If a value is still positive, its index + 1 is missing.
6. Return the missing numbers.

## Example

nums = [4,3,2,7,8,2,3,1]

Missing numbers:
[5,6]

## Time Complexity
O(n)

## Space Complexity
O(1) extra space

# Problem #16 - Rotate Array

## Pattern
Arrays + Reverse

## Key Idea
Instead of moving each element one by one, use three reversals.

For rotating right by k:

1. Reverse the entire array.
2. Reverse the first k elements.
3. Reverse the remaining elements.

## Example

nums = [1,2,3,4,5,6,7]
k = 3

Reverse all:
[7,6,5,4,3,2,1]

Reverse first 3:
[5,6,7,4,3,2,1]

Reverse remaining:
[5,6,7,1,2,3,4]

## Time Complexity
O(n)

## Space Complexity
O(1)

# Problem #17 - Remove Element

## Pattern
Arrays + Two Pointers

## Key Idea
Use two pointers:
- `right` checks every element.
- `left` stores the position where the next valid element should go.

If the current element is not equal to `val`, copy it to
the `left` position and move `left`.

## Algorithm
1. Start `left = 0`.
2. Traverse the array using `right`.
3. If `nums[right]` is not equal to `val`, copy it to `nums[left]`.
4. Increase `left`.
5. Return `left`.

## Example

nums = [3,2,2,3]
val = 3

Result:
[2,2]

Return:
2

## Time Complexity
O(n)

## Space Complexity
O(1)

# Problem #18 - Check If N and Its Double Exist

## Pattern
Arrays + Hash Set

## Key Idea
For every number, check whether:
- Its double has already appeared.
- If the number is even, its half has already appeared.

A hash set allows these checks in O(1) average time.

## Algorithm
1. Create an empty hash set.
2. For each number:
   - Check if `num * 2` already exists.
   - If `num` is even, check if `num / 2` exists.
3. If either condition is true, return true.
4. Otherwise, add the number to the set.
5. Return false if no pair exists.

## Example

arr = [10,2,5,3]

When we reach 5:
5 / 2 = 2.5, so that doesn't work.

But when we process 2:
2 * 2 = 4, not present.

When we process 5:
2 is already present and 5 = 2 * 2.5? No.

Actually, the valid pair is:
10 = 2 * 5

So the answer is true.

## Time Complexity
O(n)

## Space Complexity
O(n)

# Problem #19 - Valid Anagram

## Pattern
Hashing + Frequency Counting

## Key Idea
Two strings are anagrams if they contain the same characters
with the same frequencies.

Use an array of 26 integers to count the characters.

For every character in `s`, increase its count.
For every character in `t`, decrease its count.

If every count becomes zero, the strings are anagrams.

## Algorithm
1. Check whether the strings have the same length.
2. Create an array of 26 zeros.
3. Increase the count for each character in `s`.
4. Decrease the count for each character in `t`.
5. Check whether all counts are zero.
6. Return true if they are, otherwise false.

## Time Complexity
O(n)

## Space Complexity
O(1)

# Problem #20 - Group Anagrams

## Pattern
Hashing + Sorting

## Key Idea
Anagrams become identical when their characters are sorted.

For example:

"eat" -> "aet"
"tea" -> "aet"
"ate" -> "aet"

So we use the sorted word as the key in a hash map.

## Algorithm
1. Create a hash map.
2. For every word:
   - Make a copy of the word.
   - Sort the copy.
   - Use the sorted word as the key.
   - Add the original word to that group.
3. Convert the hash map values into the result.

## Time Complexity
O(n * k log k)

Where:
- n = number of words
- k = maximum length of a word

## Space Complexity
O(n * k)