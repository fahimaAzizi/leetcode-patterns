# Queue

## Pattern Description

> Brief description of the Queue (FIFO) pattern.

## When to Use

- First-in-first-out processing
- Breadth-first search (BFS)
- Level-order traversal
- Task scheduling

## Time Complexity

- Enqueue/Dequeue: O(1)
- Peek: O(1)
- Space: O(n)

## Common Mistakes

- Mixing up enqueue and dequeue operations
- Using wrong data structure for BFS (should use queue, not stack)
- Not marking visited nodes in BFS

## Example Problems

- Number of Islands
- Binary Tree Level Order Traversal
-rotting Oranges
- Open the Lock
- Design Hit Counter

**# Problem #100 / 120 - Implement Queue using Stacks — LeetCode #232**

**## Pattern**

Queue + Stack

**## Key Idea**

A stack follows Last In First Out, but a queue follows First In First Out.

I use two stacks to create queue behavior.

The input stack stores newly added elements.

When I need to remove or view the front element, I move the elements from the input stack to the output stack.

This reverses their order, so the oldest element becomes the top of the output stack.

**## Algorithm**

1. Create two stacks: `input` and `output`.

2. For `push`, add the element to the `input` stack.

3. For `pop` or `peek`:
   - If `output` is empty, move all elements from `input` to `output`.
   - The oldest element will now be on top of `output`.

4. For `empty`, check whether both stacks are empty.

**## Example**

Push:

1, 2, 3

The input stack contains:

```text
[1, 2, 3]
