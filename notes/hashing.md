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

# Problem #21 - Longest Consecutive Sequence

## Pattern
Hash Set

## Key Idea
Put every number into a hash set so we can quickly check
whether a number exists.

A number can be the beginning of a sequence only when
`num - 1` does not exist.

Then keep checking:
`num + 1`
`num + 2`
`num + 3`
and so on.

## Example

nums = [100,4,200,1,3,2]

The sequence starting at 1 is:

1 → 2 → 3 → 4

Length = 4

## Algorithm
1. Put all numbers into a hash set.
2. For every number, check if `num - 1` exists.
3. If it does not exist, this is the start of a sequence.
4. Count consecutive numbers.
5. Keep the largest length.

## Time Complexity
O(n)

## Space Complexity
O(n)

# Problem #22 - Top K Frequent Elements

## Pattern
Hash Map + Bucket Sort

## Key Idea
First count how many times each number appears.

Then create buckets where the index represents the frequency.

For example:

frequency 3 → numbers that appear 3 times

frequency 2 → numbers that appear 2 times

Start from the highest-frequency bucket and collect numbers
until we have k elements.

## Example

nums = [1,1,1,2,2,3]
k = 2

Frequency:
1 → 3
2 → 2
3 → 1

Highest frequencies:
3 → 1
2 → 2

Answer:
[1,2]

## Algorithm
1. Count each number using a hash map.
2. Create frequency buckets.
3. Put each number into its frequency bucket.
4. Traverse buckets from highest to lowest.
5. Add numbers until k elements are collected.

## Time Complexity
O(n)

## Space Complexity
O(n)

# Problem #23 - Happy Number

## Pattern
Hash Set + Cycle Detection

## Key Idea
Repeatedly replace the number with the sum of the squares
of its digits.

If we reach 1, the number is happy.

If a number repeats, we have entered a cycle, so the number
will never reach 1.

## Example

n = 19

19 → 82 → 68 → 100 → 1

Therefore:
true

## Algorithm
1. Create a hash set called `seen`.
2. Calculate the sum of the squares of the digits.
3. Store each result in the set.
4. If the result becomes 1, return true.
5. If a number repeats, a cycle exists.
6. Return false.

## Time Complexity
O(log n)

## Space Complexity
O(log n)

# Problem #24 - Isomorphic Strings

## Pattern
Hash Map + String

## Key Idea
Each character from `s` must map to exactly one character
in `t`.

At the same time, two different characters from `s` cannot
map to the same character in `t`.

Therefore, we keep two mappings:
- s → t
- t → s

## Example

s = "egg"
t = "add"

Mapping:
e → a
g → d

This is valid, so the answer is true.

## Algorithm
1. Create two mapping arrays.
2. For each pair of characters:
   - Check whether the existing mapping is consistent.
   - Check the reverse mapping.
3. Create both mappings.
4. If a conflict occurs, return false.
5. Otherwise return true.

## Time Complexity
O(n)

## Space Complexity
O(1)