# Sliding Window

## Pattern Description

> Brief description of the Sliding Window pattern.

## When to Use

- Contiguous subarray or substring problems
- Optimizing fixed or dynamic window sizes
- Problems asking for min/max of subarray

## Time Complexity

- O(n) time
- O(k) space where k is window size

## Common Mistakes

- Wrong window expansion/shrinking logic
- Forgetting to update result before shrinking
- Off-by-one in window boundaries

## Example Problems

- Best Time to Buy and Sell Stock
- Longest Substring Without Repeating Characters
- Min Window Substring
- Longest Repeating Character Replacement
- Sliding Window Maximum


# Problem #28 - Longest Substring Without Repeating Characters

## Pattern
Sliding Window + Hash Set

## Key Idea
Use a sliding window to keep a substring that contains
no duplicate characters.

- `left` = beginning of the window
- `right` = end of the window

When a duplicate appears, move `left` forward until the
duplicate is removed.

## Example

s = "abcabcbb"

First window:
"abc" → length 3

Next character is `a`, which is already inside the window.

Move `left` forward until `a` is removed.

Continue until the end.

Answer:
3

## Algorithm
1. Create a hash set.
2. Start `left` at 0.
3. Move `right` through the string.
4. If the current character already exists:
   - Remove the character at `left`.
   - Move `left` forward.
5. Add the current character to the set.
6. Update the maximum window length.

## Time Complexity
O(n)

## Space Complexity
O(n)

# Problem #29 - Maximum Number of Vowels in a Substring of Given Length

## Pattern
Sliding Window

## Key Idea
We need to check every substring of length `k`.

Instead of counting the vowels from scratch for every
substring, maintain a sliding window.

When the window moves:
- Add the new character entering the window.
- Remove the old character leaving the window.

## Example

s = "abciiidef"
k = 3

First window:
"abc" → 1 vowel

Move the window:
"bci" → 1 vowel
"cii" → 2 vowels
"iii" → 3 vowels

Maximum = 3

## Algorithm
1. Count vowels in the first `k` characters.
2. Store this as the current maximum.
3. Move the window one character at a time.
4. Add the new character if it is a vowel.
5. Remove the character that leaves the window if it is a vowel.
6. Update the maximum.

## Time Complexity
O(n)

## Space Complexity
O(1)
