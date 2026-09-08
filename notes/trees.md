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

## Binary Tree Maximum Path Sum — LeetCode #124

### Pattern
Trees + Recursion + Postorder Traversal

### Idea
A path can pass through a node and include both
its left and right subtrees.

For every node, calculate the best path that can
continue upward to its parent.

If a subtree gives a negative sum, we ignore it
because it would make the path smaller.

At each node, calculate:

node value + left contribution + right contribution

Keep the largest value seen as the answer.

### Example

        1
       / \
      2   3

The maximum path is:

2 → 1 → 3

Answer = 6

### Time Complexity
O(n)

n = number of nodes.

### Space Complexity
O(h)

h = height of the tree because of recursion.

### Key Lesson
For every node, calculate the best path going upward,
while separately checking the best complete path
passing through that node.

## Serialize and Deserialize Binary Tree — LeetCode #297

### Pattern
Trees + Recursion + Preorder Traversal

### Idea
Serialization converts a binary tree into a string so
it can be stored or transmitted.

Deserialization converts that string back into the
original binary tree.

We use preorder traversal:

Root → Left → Right

For null nodes, we store "#".

### Example

        1
       / \
      2   3

Serialized:

1,2,#,#,3,#,#,

The "#" values are important because they tell us
where the null children are.

### Time Complexity
O(n)

n = number of nodes.

### Space Complexity
O(n)

The serialized string and recursion can require O(n) space.

### Key Lesson
When serializing a tree, we must store null nodes too,
otherwise the original tree structure cannot be reconstructed.
## Construct Binary Tree from Preorder and Inorder Traversal — LeetCode #105

### Pattern
Trees + Recursion + Preorder + Inorder + Hash Map

### Idea
Preorder tells us the root first.

Preorder:
Root → Left → Right

Inorder tells us which values belong to the left
and right subtrees.

Inorder:
Left → Root → Right

We take the current value from preorder as the root.
Then we find its position in inorder.

Everything before that position belongs to the
left subtree, and everything after it belongs
to the right subtree.

### Example

Preorder:
[3, 9, 20, 15, 7]

Inorder:
[9, 3, 15, 20, 7]

The first preorder value is 3, so 3 is the root.

In inorder, 3 separates the left and right subtrees.

        3
       / \
      9   20
         /  \
        15   7

### Time Complexity
O(n)

n = number of nodes.

### Space Complexity
O(n)

The hash map and recursion require O(n) space.

### Key Lesson
Preorder tells us WHAT the root is.
Inorder tells us WHERE to split the tree.
## Binary Tree Paths — LeetCode #257

### Pattern
Trees + DFS + Recursion + Backtracking

### Idea
We need to find every path from the root to a leaf.

We use DFS to travel down the tree.

At every node, add its value to the current path.

When we reach a leaf node, save the complete path.

### Example

        1
       / \
      2   3
       \
        5

Paths:

1->2->5
1->3

### Time Complexity
O(n)

n = number of nodes.

### Space Complexity
O(h)

h = height of the tree because of recursion,
excluding the space needed for the result.

### Key Lesson
For root-to-leaf path problems, think:
DFS + keep track of the current path.

## Path Sum — LeetCode #112

### Pattern
Trees + DFS + Recursion

### Idea
We need to determine if there is a path from the
root to a leaf where the sum of all node values
equals targetSum.

At each node, subtract its value from targetSum.

When we reach a leaf, check whether the remaining
target equals the leaf's value.

### Example

        5
       / \
      4   8
     /
    11

For targetSum = 20:

5 + 4 + 11 = 20

So the answer is true.

### Time Complexity
O(n)

n = number of nodes.

### Space Complexity
O(h)

h = height of the tree because of recursion.

### Key Lesson
For root-to-leaf sum problems, subtract each node's
value from the target while using DFS.