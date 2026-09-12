# Graphs

## Pattern Description

> Brief description of Graph traversal and algorithms.

## When to Use

- Networks, connections, or dependencies
- Path finding
- Cycle detection
- Connected components

## Time Complexity

- BFS/DFS: O(V + E)
- Dijkstra: O(V + E log V)
- Space: O(V)

## Common Mistakes

- Forgetting visited set leading to cycles
- Wrong queue/stack usage for BFS/DFS
- Modifying graph while iterating
- Not handling disconnected components

## Example Problems

- Number of Islands
- Clone Graph
- Course Schedule
- Word Ladder
- Pacific Atlantic Water Flow

**# Problem #106 / 120 - Find the Town Judge — LeetCode #997**

**## Pattern**
Graphs + In-Degree + Out-Degree

**## Key Idea**
The judge is trusted by everyone else but trusts nobody.

**## Algorithm**
1. Count the in-degree of every person.
2. Count the out-degree of every person.
3. Find the person with `inDegree = n - 1` and `outDegree = 0`.
4. Return that person.
5. If nobody satisfies the condition, return `-1`.

**## Example**
`n = 3, [[1,3],[2,3]] → 3`

**## Time Complexity**
O(n + t)

**## Space Complexity**
O(n)

**## Progress**
#106 / 120 completed
