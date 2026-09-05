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
# Problem #53 - Middle of the Linked List

## Pattern
Fast & Slow Pointers

## Key Idea

Use two pointers:

- `slow` moves one step at a time.
- `fast` moves two steps at a time.

When `fast` reaches the end of the linked list, `slow`
will be at the middle.

## Example

1 -> 2 -> 3 -> 4 -> 5

Start:

slow = 1
fast = 1

Move:

slow = 2
fast = 3

Move again:

slow = 3
fast = 5

The fast pointer reaches the end, so `slow` is at the middle.

Answer:
3

## Even Number of Nodes

For:

1 -> 2 -> 3 -> 4 -> 5 -> 6

There are two middle nodes: 3 and 4.

The problem asks us to return the second middle node.

Answer:
4

## Algorithm

1. Set `slow` and `fast` to `head`.
2. Move `slow` one step.
3. Move `fast` two steps.
4. Continue while `fast` can move.
5. Return `slow`.

## Time Complexity

O(n)

## Space Complexity

O(1)

# Problem #54 - Reverse Linked List

## Pattern
Linked List

## Key Idea

To reverse a linked list, we need three pointers:

- `previous`
- `current`
- `nextNode`

We reverse one connection at a time.

## Example

Original:

1 -> 2 -> 3 -> 4 -> 5

After reversing:

5 -> 4 -> 3 -> 2 -> 1

## How It Works

At the beginning:

previous = nullptr

current = 1

First, save the next node:

nextNode = current->next

Then reverse the connection:

current->next = previous

Move both pointers forward and repeat.

## Algorithm

1. Set `previous` to nullptr.
2. Set `current` to head.
3. Save the next node.
4. Reverse the current connection.
5. Move `previous` forward.
6. Move `current` forward.
7. Continue until the list ends.
8. Return `previous`.

## Time Complexity

O(n)

## Space Complexity

O(1)

# Problem #55 - Merge Two Sorted Lists

## Pattern
Linked List

## Key Idea

We have two linked lists that are already sorted.

We compare the current node from both lists and always take
the smaller value.

We continue until one list is finished.

Then we connect the remaining part of the other list.

## Example

list1:

1 -> 2 -> 4

list2:

1 -> 3 -> 4

Compare:

1 and 1 → take 1

2 and 1 → take 1

2 and 3 → take 2

4 and 3 → take 3

4 and 4 → take 4

Add the remaining 4.

Result:

1 -> 1 -> 2 -> 3 -> 4 -> 4

## Dummy Node

We use a dummy node to make building the new linked list
easier.

dummy -> 1 -> 1 -> 2 -> 3 -> 4 -> 4

At the end, we return:

dummy.next

because the dummy node itself is not part of the answer.

## Algorithm

1. Create a dummy node.
2. Compare the current nodes of both lists.
3. Connect the smaller node to the result.
4. Move forward in that list.
5. Repeat until one list ends.
6. Connect the remaining nodes.
7. Return `dummy.next`.

## Time Complexity

O(n + m)

## Space Complexity

O(1)
# Problem #56 - Remove Nth Node From End of List

## Pattern
Two Pointers + Linked List

## Key Idea

We use two pointers:

- `fast`
- `slow`

First, move the `fast` pointer ahead.

Then move both pointers together.

When `fast` reaches the end, `slow` will be right before
the node we need to remove.

## Example

List:

1 -> 2 -> 3 -> 4 -> 5

n = 2

We need to remove:

4

Result:

1 -> 2 -> 3 -> 5

## Why Use a Dummy Node?

The dummy node helps us handle situations where we need to
remove the first node.

Example:

1 -> 2

n = 2

We need to remove `1`.

Using a dummy node makes this easier.

## Algorithm

1. Create a dummy node before `head`.
2. Set `fast` and `slow` to the dummy node.
3. Move `fast` ahead by `n + 1` positions.
4. Move both pointers together.
5. When `fast` reaches the end, `slow` is before the node
   we want to remove.
6. Skip that node.
7. Return `dummy.next`.

## Time Complexity

O(n)

## Space Complexity

O(1)

# Problem #57 - Palindrome Linked List

## Pattern

Fast & Slow Pointers + Linked List

## Key Idea

A palindrome reads the same from both directions.

For example:

1 -> 2 -> 2 -> 1

To solve this efficiently:

1. Find the middle of the linked list.
2. Reverse the second half.
3. Compare the first half with the reversed second half.

## Example

Original list:

1 -> 2 -> 2 -> 1

Find the middle.

Then reverse the second half:

1 -> 2

becomes:

2 -> 1

Now compare:

1 == 1 ✅

2 == 2 ✅

So the list is a palindrome.

## Algorithm

1. Use slow and fast pointers to find the middle.
2. Reverse the second half of the list.
3. Compare the first half and second half.
4. If all values match, return true.
5. Otherwise, return false.

## Time Complexity

O(n)

## Space Complexity

O(1)

# Problem #58 - Intersection of Two Linked Lists

## Pattern

Linked List + Two Pointers

## Key Idea

Use two pointers:

- `pointerA` starts at List A.
- `pointerB` starts at List B.

When `pointerA` reaches the end of List A, move it to the
beginning of List B.

When `pointerB` reaches the end of List B, move it to the
beginning of List A.

This makes both pointers travel the same total distance.

If the lists intersect, they will meet at the intersection.

If they do not intersect, both pointers will eventually become
`nullptr`.

## Example

List A:

4 -> 1 -> 8 -> 4 -> 5

List B:

5 -> 6 -> 1 -> 8 -> 4 -> 5

The lists intersect at:

8

## Algorithm

1. Create two pointers.
2. Start one at List A.
3. Start the other at List B.
4. Move both pointers forward.
5. When a pointer reaches the end, move it to the other list.
6. Continue until the pointers are equal.
7. Return the intersection node.

## Time Complexity

O(n + m)

## Space Complexity

O(1)

# Problem #59 - Add Two Numbers

## Pattern

Linked List + Math

## Key Idea

The numbers are stored in reverse order.

For example:

2 -> 4 -> 3

represents:

342

We add the numbers one digit at a time, just like normal
addition.

We also keep track of the `carry`.

## Example

l1 = 2 -> 4 -> 3

l2 = 5 -> 6 -> 4

Step 1:

2 + 5 = 7

Step 2:

4 + 6 = 10

Write 0 and carry 1.

Step 3:

3 + 4 + 1 = 8

Result:

7 -> 0 -> 8

## Important Formula

carry = sum / 10

digit = sum % 10

## Algorithm

1. Create a dummy node.
2. Start `carry` at 0.
3. Add the current values from both lists.
4. Add the carry.
5. Create a new node using `sum % 10`.
6. Update carry using `sum / 10`.
7. Continue until both lists and the carry are finished.
8. Return `dummy.next`.

## Time Complexity

O(max(n, m))

## Space Complexity

O(max(n, m))


# Problem #60 - Remove Duplicates from Sorted List

## Pattern

Linked List

## Key Idea

The linked list is already sorted.

This means duplicate values will always be next to each other.

We compare:

current->val

with:

current->next->val

If they are equal, remove the next node.

## Example

Input:

1 -> 1 -> 2 -> 3 -> 3

Compare the first two nodes:

1 == 1

Remove the duplicate:

1 -> 2 -> 3 -> 3

Continue.

Then:

3 == 3

Remove the duplicate.

Final result:

1 -> 2 -> 3

## Algorithm

1. Start at the head.
2. Compare the current node with the next node.
3. If they have the same value:
   - Remove the next node.
4. Otherwise:
   - Move to the next node.
5. Continue until the list ends.
6. Return the head.

## Time Complexity

O(n)

## Space Complexity

O(1)
# Problem #60 - Odd Even Linked List

## Pattern

Linked List

## Key Idea

We need to separate nodes based on their position:

Odd positions:
1st, 3rd, 5th...

Even positions:
2nd, 4th, 6th...

Then connect all odd-positioned nodes first, followed by all
even-positioned nodes.

## Example

Original:

1 -> 2 -> 3 -> 4 -> 5

Odd-positioned nodes:

1 -> 3 -> 5

Even-positioned nodes:

2 -> 4

Final result:

1 -> 3 -> 5 -> 2 -> 4

## Algorithm

1. Create an `odd` pointer starting at the first node.
2. Create an `even` pointer starting at the second node.
3. Save the beginning of the even list.
4. Connect all odd-positioned nodes.
5. Connect all even-positioned nodes.
6. Connect the odd list to the beginning of the even list.
7. Return the head.

## Time Complexity

O(n)

## Space Complexity

O(1)
# Problem #62 - Rotate List

## Pattern

Linked List

## Key Idea

We need to rotate the linked list to the right.

Example:

1 -> 2 -> 3 -> 4 -> 5

k = 2

The last 2 nodes move to the front:

4 -> 5 -> 1 -> 2 -> 3

## Important Step

First, find the length of the linked list.

Then calculate:

k = k % length

This avoids unnecessary rotations.

For example:

length = 5
k = 7

7 % 5 = 2

So rotating 7 times is the same as rotating 2 times.

## Clever Idea

Connect the last node back to the first node to make the
list circular.

Then find the new tail and break the circle.

## Algorithm

1. Find the length of the list.
2. Find the last node.
3. Calculate `k % length`.
4. Connect the last node to the head.
5. Find the new tail.
6. The node after the new tail becomes the new head.
7. Break the circular connection.
8. Return the new head.

## Time Complexity

O(n)

## Space Complexity

O(1)

# Problem #63 - Delete Node in a Linked List

## Pattern

Linked List

## Key Idea

Normally, to delete a node, we need the previous node.

But this problem does NOT give us the previous node.

Instead, we copy the value from the next node into the
current node, then remove the next node.

## Example

Original:

4 -> 5 -> 1 -> 9

We need to delete 5.

Copy 1 into the node containing 5:

4 -> 1 -> 1 -> 9

Then skip the duplicate 1:

4 -> 1 -> 9

The result is correct.

## Algorithm

1. Copy the next node's value into the current node.
2. Make the current node point to the node after the next node.
3. The next node is effectively removed.

## Code

node->val = node->next->val;
node->next = node->next->next;

## Time Complexity

O(1)

## Space Complexity

O(1)

## Important

The node to delete will never be the last node.