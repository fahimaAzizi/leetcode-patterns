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


**# Problem #101 / 120 - Design Circular Queue — LeetCode #622**

**## Pattern**

Queue + Circular Array

**## Key Idea**

A circular queue allows us to reuse the space that becomes empty after removing elements.

I use an array and keep track of:

- `front` for the first element.
- `rear` for the next position to insert.
- `count` for the number of elements.
- `capacity` for the maximum size.

When the rear reaches the end of the array, it goes back to the beginning.

I use:

(rear + 1) % capacity

to make the queue circular.

**## Algorithm**

1. Create an array with size `k`.

2. Set `front` and `rear` to `0`.

3. When adding an element:
   - Put it at `rear`.
   - Move `rear` using the circular formula.
   - Increase `count`.

4. When removing an element:
   - Move `front` using the circular formula.
   - Decrease `count`.

5. The queue is empty when `count == 0`.

6. The queue is full when `count == capacity`.

**## Example**

```text
k = 3

enQueue(1)
enQueue(2)
enQueue(3)

**# Problem #102 / 120 - Design Circular Deque — LeetCode #641**

**## Pattern**

Queue + Circular Array + Deque

**## Key Idea**

A Deque allows insertion and deletion from both the front and the rear.

I use a circular array so that empty positions can be reused.

I keep track of:

- `front` for the first element.
- `rear` for the last element.
- `count` for the number of elements.
- `capacity` for the maximum size.

The circular movement is done using the modulo operator.

**## Algorithm**

1. Create an array with size `k`.

2. Keep track of `front`, `rear`, and `count`.

3. For `insertFront`:
   - Move `front` one position backward.
   - Insert the value.
   - Increase `count`.

4. For `insertLast`:
   - Move `rear` one position forward.
   - Insert the value.
   - Increase `count`.

5. For deletion:
   - Move `front` or `rear` accordingly.
   - Decrease `count`.

6. The deque is empty when `count == 0`.

7. The deque is full when `count == capacity`.

**## Example**

```text
k = 3

insertLast(1)
insertLast(2)
insertFront(3)