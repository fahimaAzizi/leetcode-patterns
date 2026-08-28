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

# Problem #25 - Word Pattern

## Pattern
Hash Map + String

## Key Idea
Each pattern character must map to exactly one word.

Also, each word must map to exactly one pattern character.

Therefore, use two maps:
- character → word
- word → character

## Example

pattern = "abba"
s = "dog cat cat dog"

Mapping:

a → dog
b → cat

So:

a b b a
dog cat cat dog

The pattern is valid.

## Algorithm
1. Split the string into words.
2. Check that the number of words equals the pattern length.
3. Create two maps.
4. Check both directions for every character and word.
5. Return false if a mapping conflicts.
6. Otherwise return true.

## Time Complexity
O(n)

## Space Complexity
O(n)

# Problem #26 - First Unique Character in a String

## Pattern
Hashing + Frequency Counting

## Key Idea
First count how many times every character appears.

Then scan the string from left to right.
The first character whose frequency is 1 is the answer.

## Algorithm
1. Create a frequency array of size 26.
2. Count every character in the string.
3. Scan the string again.
4. If a character has frequency 1, return its index.
5. If no unique character exists, return -1.

## Example

s = "leetcode"

Frequency:
l → 1
e → 3
t → 1
c → 1
o → 1
d → 1

The first character with frequency 1 is `l`.

Answer:
0

## Time Complexity
O(n)

## Space Complexity
O(1)
# Problem #27 - Ransom Note

## Pattern
Hashing + Frequency Counting

## Key Idea
Count how many times each letter appears in `magazine`.

Then, for every letter needed by `ransomNote`, decrease
its available count.

If any count becomes negative, there are not enough letters.

## Algorithm
1. Create a frequency array of 26 zeros.
2. Count all letters in `magazine`.
3. Go through `ransomNote`.
4. Decrease the count for each required letter.
5. If a count becomes negative, return false.
6. Otherwise return true.

## Example

ransomNote = "aa"
magazine = "aab"

Magazine counts:

a → 2
b → 1

Use first `a`:
a → 1

Use second `a`:
a → 0

All letters are available.

Answer:
true

## Time Complexity
O(n + m)

## Space Complexity
O(1)
# Problem #39 - Binary Subarrays With Sum

## Pattern
Prefix Sum + Hash Map

## Key Idea
Use a prefix sum to keep track of the sum from the beginning
of the array.

If:

prefixSum - goal

has appeared before, then the subarray between that previous
position and the current position has a sum equal to `goal`.

## Example

nums = [1,0,1,0,1]
goal = 2

The answer is 4.

## Algorithm
1. Create a hash map to store prefix sum frequencies.
2. Start with prefixCount[0] = 1.
3. Add each number to prefixSum.
4. Calculate:

needed = prefixSum - goal

5. If `needed` appeared before, add its frequency to result.
6. Store the current prefixSum.
7. Return result.

## Time Complexity
O(n)

## Space Complexity
O(n)
# Problem #40 - Subarray Sum Equals K

## Pattern
Prefix Sum + Hash Map

## Key Idea
If the current prefix sum is `prefixSum`, we need to find
an earlier prefix sum equal to:

prefixSum - k

Because:

current prefix sum - previous prefix sum = k

## Example

nums = [1,1,1]
k = 2

Prefix sums:

0
1
2 → found previous 0
3 → found previous 1

There are two subarrays with sum 2.

Answer = 2

## Algorithm
1. Create a hash map for prefix sum frequencies.
2. Set prefixCount[0] = 1.
3. Keep a running prefix sum.
4. Calculate `prefixSum - k`.
5. If that value exists, add its frequency to the answer.
6. Store the current prefix sum.
7. Return the answer.

## Time Complexity
O(n)

## Space Complexity
O(n)