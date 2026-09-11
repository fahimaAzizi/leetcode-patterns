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

**# Problem #103 / 120 - Design Front Middle Back Queue — LeetCode #1670**

**## Pattern**

Queue + Deque

**## Key Idea**

This queue allows insertion and deletion from three positions:

- Front
- Middle
- Back

I use a `deque` because it allows easy insertion and deletion from both ends.

For the middle position, I use the size of the queue to find the correct index.

When the queue has an even number of elements, the first of the two middle elements is used.

**## Algorithm**

1. Create a deque to store the elements.

2. For `pushFront`, add the value to the front.

3. For `pushBack`, add the value to the back.

4. For `pushMiddle`:
   - Find the middle index.
   - Insert the value at that position.

5. For `popFront`:
   - Remove and return the first element.

6. For `popBack`:
   - Remove and return the last element.

7. For `popMiddle`:
   - Find the middle index.
   - Remove and return that element.

8. Return `-1` when trying to remove from an empty queue.

**## Example**

Start with:

```text
1 → 2
**# Problem #104 / 120 - Number of Recent Calls — LeetCode #933**

**## Pattern**

Queue + Sliding Window

**## Key Idea**

I need to count how many requests happened during the last 3000 milliseconds.

Because the request times are given in increasing order, I can use a queue.

I add every new request to the queue.

Then I remove requests that are older than:

t - 3000

The size of the queue gives me the number of recent requests.

**## Algorithm**

1. Create an empty queue.

2. For every `ping(t)`:
   - Add `t` to the queue.

3. Remove elements from the front while they are older than `t - 3000`.

4. Return the size of the queue.

**## Example**

```text
ping(1)
ping(100)
ping(3001)

**# Problem #105 / 120 - Find All Numbers Disappeared in an Array — LeetCode #448**

**## Pattern**
Arrays + In-place Marking

**## Key Idea**
Use each number as an index and mark that position negative.

**## Algorithm**
1. For each number, calculate `abs(num) - 1`.
2. Make that position negative.
3. Scan the array.
4. If `nums[i]` is positive, `i + 1` is missing.

**## Example**
`[4,3,2,7,8,2,3,1] → [5,6]`

**## Time Complexity**
O(n)

**## Space Complexity**
O(1) extra space

**## Progress**
#105 / 120 completed