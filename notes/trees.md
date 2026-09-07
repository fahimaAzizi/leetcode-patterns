# Trees

## Pattern Description

> Brief description of Tree traversal patterns.

## When to Use

- Hierarchical data
- Binary search tree operations
- Recursive or iterative tree traversals

## Time Complexity

- Traversal: O(n)
- Search (BST): O(h) where h is height
- Space: O(h) for recursion stack

## Common Mistakes

- Forgetting base case in recursion
- Null pointer dereferences
- Confusing inorder/preorder/postorder
- Assuming tree is balanced

## Example Problems

- Binary Tree Inorder Traversal
- Validate Binary Search Tree
- Lowest Common Ancestor of a BST
- Binary Tree Level Order Traversal
- Construct Binary Tree from Preorder and Inorder Traversal

## Binary Tree Level Order Traversal — LeetCode #102

### Pattern
Trees + Queue (BFS)

### Idea
Use a queue to visit the tree level by level.

For each level:
1. Count the nodes currently in the queue.
2. Process those nodes.
3. Add their children to the queue.
4. Store the level in the result.

### Example

        3
       / \
      9   20
         /  \
        15   7

Result:

[
    [3],
    [9, 20],
    [15, 7]
]

### Time Complexity
O(n)

### Space Complexity
O(n)

### Key Lesson
A queue and BFS are useful when we need to process
a binary tree level by level.


## Binary Tree Right Side View — LeetCode #199

### Pattern
Trees + BFS

### Idea
Imagine looking at the tree from the right side.

Use BFS to process the tree level by level.

The last node processed at each level is the node
we can see from the right side.

### Example

        1
       / \
      2   3
       \   \
        5   4

Right side view:

[1, 3, 4]

### Time Complexity
O(n)

### Space Complexity
O(n)

### Key Lesson
With level-order traversal, the last node of each
level gives the right-side view of the tree.
