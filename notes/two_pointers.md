# Two Pointers

## Pattern Description

> Brief description of the Two Pointers pattern.

## When to Use

- Sorted arrays or strings
- Searching for pairs
- Palindrome checking
- Partitioning problems

## Time Complexity

- O(n) time
- O(1) extra space

## Common Mistakes

- Forgetting to move the correct pointer
- Infinite loops when pointers converge
- Not handling empty or single-element inputs

## Example Problems

- Two Sum II - Input Array Is Sorted
- 3Sum
- Container With Most Water
- Trapping Rain Water
- Valid Palindrome


# Problem #38 - Valid Palindrome

## Pattern
Two Pointers

## Key Idea
Use two pointers:

- `left` starts at the beginning.
- `right` starts at the end.

Ignore characters that are not letters or numbers.

Compare the remaining characters while ignoring uppercase
and lowercase differences.

## Example

s = "A man, a plan, a canal: Panama"

Ignoring spaces and punctuation:

amanaplanacanalpanama

It reads the same forward and backward.

Answer:
true

## Algorithm
1. Put one pointer at the beginning.
2. Put one pointer at the end.
3. Skip non-alphanumeric characters.
4. Compare the two characters.
5. If they are different, return false.
6. Move both pointers toward the center.
7. If everything matches, return true.

## Time Complexity
O(n)

## Space Complexity
O(1)

# Problem #39 - Two Sum II: Input Array Is Sorted

## Pattern
Two Pointers

## Key Idea
Because the array is already sorted, we can use two pointers.

- `left` starts at the beginning.
- `right` starts at the end.

Calculate their sum.

If the sum is too small:
Move `left` forward.

If the sum is too large:
Move `right` backward.

If the sum equals the target:
Return the indices.

## Example

numbers = [2,7,11,15]
target = 9

2 + 15 = 17

17 is too large, so move right.

2 + 11 = 13

Still too large, so move right.

2 + 7 = 9

Answer:
[1,2]

## Time Complexity
O(n)

## Space Complexity
O(1)
# Problem #41 - Move Zeroes

## Pattern
Two Pointers

## Key Idea
Use one pointer to find non-zero elements and another
pointer to show where the next non-zero element should go.

The `insertPosition` pointer keeps track of where we should
place the next non-zero number.

## Example

nums = [0,1,0,3,12]

Move non-zero numbers forward:

1 → first position

3 → second position

12 → third position

Result:

[1,3,12,0,0]

## Algorithm
1. Set `insertPosition = 0`.
2. Loop through the array.
3. If the current number is not zero:
   - Swap it with the number at `insertPosition`.
   - Move `insertPosition` forward.
4. Continue until the end.

## Time Complexity
O(n)

## Space Complexity
O(1)
# Problem #44 - Container With Most Water

## Pattern
Two Pointers

## Key Idea
The amount of water depends on:

Area = width × minimum height

Use two pointers:
- `left` at the beginning
- `right` at the end

Calculate the area and move the pointer with the smaller
height inward.

## Why move the smaller height?

The smaller height limits the amount of water.

Moving the taller height cannot increase the limiting height,
so we move the smaller one and hope to find a taller line.

## Example

height = [1,8,6,2,5,4,8,3,7]

The maximum area is between:

8 and 7

Width = 7
Height = 7

Area:

7 × 7 = 49

Answer:
49

## Algorithm
1. Put `left` at the first position.
2. Put `right` at the last position.
3. Calculate width.
4. Find the smaller height.
5. Calculate the area.
6. Update the maximum area.
7. Move the pointer with the smaller height.
8. Continue until pointers meet.

## Time Complexity
O(n)

## Space Complexity
O(1)
# Problem #45 - 3Sum

## Pattern
Sorting + Two Pointers

## Key Idea

We need to find three numbers whose sum equals zero.

First, sort the array.

Then choose one number and use two pointers to find the
other two numbers.

## Example

nums = [-1,0,1,2,-1,-4]

After sorting:

[-4,-1,-1,0,1,2]

Choose:

-1

Now use two pointers to find two numbers that make the
total equal to zero.

-1 + -1 + 2 = 0

-1 + 0 + 1 = 0

Answer:

[[-1,-1,2],[-1,0,1]]

## Algorithm

1. Sort the array.
2. Choose one number using a loop.
3. Put `left` after that number.
4. Put `right` at the end.
5. Calculate the sum of all three numbers.
6. If the sum is too small, move `left`.
7. If the sum is too large, move `right`.
8. If the sum is zero, save the triplet.
9. Skip duplicate values.

## Time Complexity

O(n²)

## Space Complexity

O(1) excluding the output.

# Problem #46 - Valid Triangle Number

## Pattern
Sorting + Two Pointers

## Key Idea

Three sides can form a triangle when:

a + b > c

After sorting the array, we choose the largest side `c`.

Then we use two pointers to find pairs where:

nums[left] + nums[right] > nums[k]

## Example

nums = [2,2,3,4]

After sorting:

[2,2,3,4]

Possible valid triangles:

[2,2,3] ✅
[2,3,4] ✅
[2,3,4] ✅

Answer = 3

## Algorithm

1. Sort the array.
2. Start with the largest number as the third side.
3. Put `left` at the beginning.
4. Put `right` before the largest side.
5. Check if:

nums[left] + nums[right] > nums[k]

6. If true, count all possible values between left and right.
7. If false, move `left` forward.
8. Continue until all possibilities are checked.

## Time Complexity

O(n²)

## Space Complexity

O(1) excluding sorting
# Problem #47 - Squares of a Sorted Array

## Pattern
Two Pointers

## Key Idea

The array is already sorted, but it can contain negative
numbers.

When we square negative numbers, they become positive.

For example:

[-4,-1,0,3,10]

After squaring:

[16,1,0,9,100]

This is not sorted.

The largest square must come from either:
- the left side, or
- the right side.

So we use two pointers.

## Algorithm

1. Put `left` at the beginning.
2. Put `right` at the end.
3. Compare their squares.
4. Put the larger square at the end of the result array.
5. Move the pointer that produced the larger square.
6. Continue until all positions are filled.

## Example

nums = [-4,-1,0,3,10]

Compare:

(-4)² = 16
10² = 100

100 is larger, so put it at the end.

Then continue comparing until the result is:

[0,1,9,16,100]

## Time Complexity

O(n)

## Space Complexity

O(n)