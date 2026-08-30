# Linked List

## Pattern Description

> Brief description of the Linked List pattern.

## When to Use

- Sequential data with frequent insertions/deletions
- When you need to avoid shifting elements
- Fast/slow pointer traversal needed

## Time Complexity

- Access: O(n)
- Search: O(n)
- Insert/Delete (known position): O(1)
- Space: O(1)

## Common Mistakes

- Losing the head pointer
- Incorrect pointer updates during reversal
- Forgetting to handle edge cases (empty list, single node)
- Infinite loops due to circular references

## Example Problems

- Reverse Linked List
- Linked List Cycle
- Merge Two Sorted Lists
- Remove Nth Node From End of List
- Palindrome Linked List


# Problem #52 - Linked List Cycle

## Pattern
Fast & Slow Pointers

## Key Idea

Use two pointers:

- `slow` moves one step at a time.
- `fast` moves two steps at a time.

If there is a cycle, the fast pointer will eventually catch
the slow pointer.

If there is no cycle, the fast pointer will reach the end.

## Example

1 -> 2 -> 3 -> 4
     ^         |
     |_________|

Slow moves:

1 -> 2 -> 3 -> 4

Fast moves twice as quickly.

Eventually, they meet inside the cycle.

That means there is a cycle.

## Algorithm

1. Set `slow` and `fast` to `head`.
2. Move `slow` one step.
3. Move `fast` two steps.
4. If they meet, return true.
5. If `fast` reaches the end, return false.

## Time Complexity

O(n)

## Space Complexity

O(1)