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