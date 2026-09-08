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


## Kth Smallest Element in a BST — LeetCode #230

### Pattern
Trees + Recursion + Binary Search Tree + Inorder Traversal

### Idea
In a Binary Search Tree, inorder traversal visits the
nodes in sorted order.

Inorder traversal follows:

Left → Root → Right

So we keep a counter while traversing the tree.
When the counter reaches k, we have found the kth
smallest element.

### Example

        3
       / \
      1   4
       \
        2

Inorder traversal:

1 → 2 → 3 → 4

If k = 3, the answer is 3.

### Time Complexity
O(n)

### Space Complexity
O(h)

h = height of the tree because of recursion.

### Key Lesson
In a BST, inorder traversal produces values in
ascending order, so it can be used to find the
kth smallest element.


## Lowest Common Ancestor of a BST — LeetCode #235

### Pattern
Trees + Binary Search Tree + Recursion

### Idea
In a BST, values smaller than the current node are
on the left and values larger are on the right.

If both p and q are smaller than the current node,
the LCA must be in the left subtree.

If both are larger, the LCA must be in the right subtree.

Otherwise, the current node is the Lowest Common Ancestor.

### Example

        6
       / \
      2   8
     / \
    0   4

For p = 2 and q = 8:

The values are on different sides of 6,
so 6 is their Lowest Common Ancestor.

### Time Complexity
O(h)

h = height of the tree.

### Space Complexity
O(h)

h = height of the tree because of recursion.

### Key Lesson
Use the BST ordering to decide whether to move
left, move right, or stop at the current node.