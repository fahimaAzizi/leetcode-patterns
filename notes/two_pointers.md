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
