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

# Problem #30 - Permutation in String

## Pattern
Sliding Window + Frequency Counting

## Key Idea
A permutation contains exactly the same characters with
the same frequencies.

So we compare the character frequencies of `s1` with
each window of the same length in `s2`.

## Example

s1 = "ab"
s2 = "eidbaooo"

Characters needed:

a → 1
b → 1

Check windows of length 2:

"ei"
"id"
"db"
"ba" ← matches!

Therefore:
true

## Algorithm
1. Count the characters in `s1`.
2. Create a window with the same length as `s1`.
3. Count characters in the first window of `s2`.
4. Compare the two frequency arrays.
5. Move the window one position at a time.
6. Add the new character.
7. Remove the old character.
8. If the frequencies match, return true.
9. Otherwise return false.

## Time Complexity
O(n)

## Space Complexity
O(1)


# Problem #32 - Longest Repeating Character Replacement

## Pattern
Sliding Window + Frequency Counting

## Key Idea
We want the largest window that can be changed into one
repeated character using at most k replacements.

Inside the window:

window length - most frequent character count
= number of replacements needed

If replacements > k, shrink the window.

## Example

s = "AABABBA"
k = 1

Window:
"AABA"

A appears 3 times.
Window length = 4.

Replacements needed:

4 - 3 = 1

Since k = 1, the window is valid.

Answer = 4

## Algorithm
1. Use a frequency array to count characters.
2. Expand the window with `right`.
3. Track the most frequent character.
4. Calculate how many replacements are needed.
5. If replacements > k, move `left`.
6. Track the largest valid window.

## Time Complexity
O(n)

## Space Complexity
O(1)

# Problem #33 - Find All Anagrams in a String

## Pattern
Sliding Window + Frequency Counting

## Key Idea
Anagrams have exactly the same character frequencies.

The window must always have the same length as `p`.

Compare the frequency of the current window with the
frequency of `p`.

## Example

s = "cbaebabacd"
p = "abc"

Window length = 3

"cba" → anagram → index 0
"bae" → not an anagram
...
"bac" → anagram → index 6

Answer:
[0,6]

## Algorithm
1. Count characters in `p`.
2. Create a window with the same length as `p`.
3. Compare the window frequency with `p`.
4. Move the window one position at a time.
5. Add the new character.
6. Remove the old character.
7. If frequencies match, save the starting index.

## Time Complexity
O(n)

## Space Complexity
O(1)

# Problem #34 - Maximum Average Subarray I

## Pattern
Sliding Window

## Key Idea
Every subarray must have exactly `k` elements.

Since every window has the same length, the window with
the largest sum will also have the largest average.

Therefore, we only need to find the maximum sum.

## Example

nums = [1,12,-5,-6,50,3]
k = 4

First window:
[1,12,-5,-6]
sum = 2

Next:
[12,-5,-6,50]
sum = 51

Next:
[-5,-6,50,3]
sum = 42

Maximum sum = 51

Average:
51 / 4 = 12.75

## Algorithm
1. Calculate the sum of the first k elements.
2. Store it as the maximum sum.
3. Move the window one position at a time.
4. Add the new element.
5. Remove the element leaving the window.
6. Update the maximum sum.
7. Divide the maximum sum by k.

## Time Complexity
O(n)

## Space Complexity
O(1)

# Problem #35 - Defuse the Bomb

## Pattern
Sliding Window + Circular Array

## Key Idea
The array is circular, meaning that after the last element
we return to the first element.

For positive k:
- Add the next k elements.

For negative k:
- Add the previous k elements.

For k = 0:
- Every result is 0.

Instead of calculating every sum from scratch, use a sliding
window.

## Example

code = [5,7,1,4]
k = 3

For the first position, take the next 3:

7 + 1 + 4 = 12

For the second position:

1 + 4 + 5 = 10

For the third:

4 + 5 + 7 = 16

For the fourth:

5 + 7 + 1 = 13

Result:
[12,10,16,13]

## Important Idea

Because the array is circular, we use `% n`.

For example:

index = 4
n = 4

4 % 4 = 0

So index 4 refers back to index 0.

## Time Complexity
O(n)

## Space Complexity
O(n)

# Problem #36 - Subarray Product Less Than K

## Pattern
Sliding Window + Two Pointers

## Key Idea
Use a sliding window where the product of all elements
must stay less than k.

Expand the window using `right`.

If the product becomes greater than or equal to k,
shrink the window using `left`.

After finding a valid window, count all valid subarrays
ending at `right`.

## Example

nums = [10,5,2,6]
k = 100

Valid subarrays:

[10]
[5]
[2]
[6]
[10,5]
[5,2]
[2,6]
[5,2,6]

Answer = 8

## Algorithm
1. Start with `left = 0`.
2. Keep a running product.
3. Expand the window with `right`.
4. If product >= k, shrink from the left.
5. Count valid subarrays using:

right - left + 1

## Time Complexity
O(n)

## Space Complexity
O(1)

# Problem #37 - Minimum Window Substring

## Pattern
Sliding Window + Hash Map

## Key Idea
Find the smallest substring in `s` that contains all the
characters from `t`.

We use:
- `need` to count characters required.
- `window` to count characters in the current window.

When the window contains everything we need, try to shrink
it from the left.

## Example

s = "ADOBECODEBANC"
t = "ABC"

A valid window:

"ADOBEC"

Later we find a smaller window:

"BANC"

Answer:

"BANC"

## Algorithm
1. Count characters in `t`.
2. Expand the window using `right`.
3. Track characters inside the current window.
4. When all requirements are satisfied, the window is valid.
5. Try to shrink it using `left`.
6. Save the smallest valid window.

## Time Complexity
O(n)

## Space Complexity
O(n)