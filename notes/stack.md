# Stack

## Pattern Description

> Brief description of the Stack (LIFO) pattern.

## When to Use

- Last-in-first-out processing
- Nested structures (parentheses, brackets)
- Backtracking or undo mechanisms
- Expression evaluation

## Time Complexity

- Push/Pop: O(1)
- Peek: O(1)
- Space: O(n)

## Common Mistakes

- Popping from an empty stack without checking
- Confusing push/pop order
- Forgetting to clear stack between test cases

## Example Problems

- Valid Parentheses
- Min Stack
- Evaluate Reverse Polish Notation
- Daily Temperatures
- Largest Rectangle in Histogram
## Daily Temperatures — LeetCode #739

### Pattern
Monotonic Stack

### Idea
For every temperature, find how many days we need to
wait for a warmer temperature.

Use a stack to store indexes of temperatures that have
not found a warmer day yet.

When the current temperature is warmer than the
temperature at the top of the stack, we found the answer
for that previous day.

### Example

[73, 74, 75, 71, 69, 72, 76, 73]

Result:

[1, 1, 4, 2, 1, 1, 0, 0]

### Time Complexity
O(n)

### Space Complexity
O(n)

### Key Lesson
A monotonic stack is useful when we need to find the
next greater element efficiently.


## Evaluate Reverse Polish Notation — LeetCode #150

### Pattern
Stack

### Idea
Use a stack to evaluate the expression.

If the token is a number, push it onto the stack.

If the token is an operator, take the top two numbers,
perform the operation, and push the result back.

### Example

["2", "1", "+", "3", "*"]

2 + 1 = 3
3 * 3 = 9

Answer = 9

### Important
For subtraction and division, the first popped value
is the second number.

a = second value
b = first value

Then:
a - b
a / b

### Time Complexity
O(n)

### Space Complexity
O(n)

### Key Lesson
A stack is useful when an expression needs to process
values in last-in-first-out order.