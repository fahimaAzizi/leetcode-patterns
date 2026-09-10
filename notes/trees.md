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
## Sum of Left Leaves — LeetCode #404

### Pattern
Trees + DFS + Recursion

### Idea
We need to find all leaf nodes that are on the
left side of their parent.

A leaf is a node with no left or right child.

For every node, check whether its left child is
a leaf. If it is, add its value to the sum.

Then continue searching the rest of the tree.

### Example

        3
       / \
      9   20
         /  \
        15   7

Left leaves:

9 + 15 = 24

Answer = 24

### Time Complexity
O(n)

n = number of nodes.

### Space Complexity
O(h)

h = height of the tree because of recursion.

### Key Lesson
A left leaf must satisfy TWO conditions:
1. It is the left child of a node.
2. It has no children of its own.
## Diameter of Binary Tree — LeetCode #543

### Pattern
Trees + DFS + Recursion + Postorder Traversal

### Idea
The diameter is the longest path between any two nodes.

For every node, calculate the height of its left
and right subtrees.

A path passing through the current node has length:

left height + right height

Keep the largest value as the diameter.

### Example

        1
       / \
      2   3
     / \
    4   5

The longest path is:

4 → 2 → 1 → 3

Diameter = 3 edges.

### Time Complexity
O(n)

n = number of nodes.

### Space Complexity
O(h)

h = height of the tree because of recursion.

### Key Lesson
At every node, calculate the longest path passing
through it while returning the height to its parent.

## Subtree of Another Tree — LeetCode #572

### Pattern
Trees + DFS + Recursion

### Idea
We need to check whether subRoot appears as a
complete subtree inside root.

For every node in root, check if the tree starting
at that node is exactly the same as subRoot.

We use a helper function to compare two trees.

### Example

        3
       / \
      4   5
     / \
    1   2

subRoot:

      4
     / \
    1   2

The answer is true because the tree rooted at 4
is exactly the same as subRoot.

### Time Complexity
O(n * m)

n = number of nodes in root.
m = number of nodes in subRoot.

### Space Complexity
O(h)

h = recursion depth.

### Key Lesson
Break the problem into two parts:
1. Find possible matching roots.
2. Check whether two trees are exactly the same.

## Same Tree — LeetCode #100

### Pattern
Trees + DFS + Recursion

### Idea
Two binary trees are the same if they have the
same structure and the same node values.

We compare both trees at the same time.

If both nodes are null, they match.

If only one is null, the trees are different.

If their values are different, the trees are different.

Otherwise, recursively compare their left and
right subtrees.

### Example

Tree 1:        Tree 2:

    1              1
   / \            / \
  2   3          2   3

Both trees have the same structure and values,
so the answer is true.

### Time Complexity
O(n)

n = number of nodes being compared.

### Space Complexity
O(h)

h = height of the tree because of recursion.

### Key Lesson
To compare two trees, compare:
1. Their node values.
2. Their structure.
3. Their left subtrees.
4. Their right subtrees.

## Symmetric Tree — LeetCode #101

### Pattern
Trees + DFS + Recursion

### Idea
A tree is symmetric if its left and right sides
are mirror images of each other.

We compare two nodes at the same time.

The left child of one side must match the
right child of the other side.

The right child must match the left child.

### Example

        1
       / \
      2   2
     / \ / \
    3  4 4  3

This tree is symmetric.

### Time Complexity
O(n)

n = number of nodes.

### Space Complexity
O(h)

h = height of the tree because of recursion.

### Key Lesson
For a symmetric tree, compare:
left.left  with right.right
left.right with right.left

## Minimum Depth of Binary Tree — LeetCode #111

### Pattern
Trees + DFS + Recursion

### Idea
The minimum depth is the number of nodes on the
shortest path from the root to a leaf.

A leaf is a node with no left or right child.

We recursively calculate the minimum depth of
the left and right subtrees.

An important point is that if one child is null,
we cannot simply use min() because that would
incorrectly choose the null side.

### Example

        3
       / \
      9   20
         /  \
        15   7

Shortest path:

3 → 9

Minimum depth = 2

### Time Complexity
O(n)

n = number of nodes.

### Space Complexity
O(h)

h = height of the tree because of recursion.

### Key Lesson
For minimum depth, the path must end at a leaf.
If one child is missing, use the other child.

## Binary Tree Preorder Traversal — LeetCode #144

### Pattern
Trees + DFS + Recursion + Preorder Traversal

### Idea
Preorder traversal visits nodes in this order:

Root → Left → Right

We first process the current node, then recursively
traverse the left subtree, followed by the right subtree.

### Example

        1
       / \
      2   3
     / \
    4   5

Preorder:

1 → 2 → 4 → 5 → 3

### Time Complexity
O(n)

n = number of nodes.

### Space Complexity
O(h)

h = height of the tree because of recursion.

### Key Lesson
Preorder means:
Root first, then Left, then Right.

## Binary Tree Postorder Traversal — LeetCode #145

### Pattern
Trees + DFS + Recursion + Postorder Traversal

### Idea
Postorder traversal visits nodes in this order:

Left → Right → Root

We first recursively process the left subtree,
then the right subtree, and finally the current node.

### Example

        1
       / \
      2   3
     / \
    4   5

Postorder:

4 → 5 → 2 → 3 → 1

### Time Complexity
O(n)

n = number of nodes.

### Space Complexity
O(h)

h = height of the tree because of recursion.

### Key Lesson
Postorder means:
Left first, Right second, Root last.

## Binary Tree Inorder Traversal — LeetCode #94

### Pattern
Trees + DFS + Recursion + Inorder Traversal

### Idea
Inorder traversal visits nodes in this order:

Left → Root → Right

We first recursively visit the left subtree,
then process the current node, and finally
visit the right subtree.

### Example

        1
         \
          2
         /
        3

Inorder:

1 → 3 → 2

### Time Complexity
O(n)

n = number of nodes.

### Space Complexity
O(h)

h = height of the tree because of recursion.

### Key Lesson
Inorder means:
Left first, Root second, Right last.

For a BST, inorder traversal gives values
in ascending order.

## Binary Tree Level Order Traversal II — LeetCode #107

### Pattern
Trees + BFS + Queue

### Idea
This problem is similar to normal level order traversal,
but the levels must be returned from bottom to top.

We use BFS with a queue to collect each level normally.

After collecting all levels, reverse the result.

### Example

        3
       / \
      9   20
         /  \
        15   7

Normal level order:

[3]
[9, 20]
[15, 7]

Bottom-up result:

[15, 7]
[9, 20]
[3]

### Time Complexity
O(n)

n = number of nodes.

### Space Complexity
O(n)

The queue and result require O(n) space.

### Key Lesson
Use BFS to collect levels, then reverse the
result to get bottom-up level order.