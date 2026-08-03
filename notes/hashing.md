# Hashing

## Pattern Description

> Brief description of the Hashing / Hash Table pattern.

## When to Use

- When you need O(1) lookups
- To detect duplicates
- For frequency counting
- To complement other patterns (e.g., two-sum)

## Time Complexity

- Average insert/search/delete: O(1)
- Worst-case (collisions): O(n)
- Space: O(n)

## Common Mistakes

- Forgetting to handle collisions in interview settings
- Using unordered_map when order matters
- Not checking for key existence before access

## Example Problems

- Two Sum
- Valid Anagram
- Group Anagrams
- Longest Substring Without Repeating Characters
- Top K Frequent Elements
