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
**# Problem #107 / 120 - Number of Islands — LeetCode #200**

**## Pattern**
Graphs + DFS + Grid

**## Key Idea**
When we find land, count a new island and use DFS to visit all connected land cells.

**## Algorithm**
1. Scan every cell in the grid.
2. When a cell contains `'1'`, increase the island count.
3. Run DFS from that cell.
4. Mark visited land as `'0'`.
5. Continue until the whole grid is scanned.

**## Example**
`[["1","1","0"],["1","0","0"],["0","0","1"]] → 2`

**## Time Complexity**
O(rows × cols)

**## Space Complexity**
O(rows × cols)

**## Progress**
#107 / 120 completed

**# Problem #108 / 120 - Clone Graph — LeetCode #133**

**## Pattern**
Graphs + DFS + Hash Map

**## Key Idea**
Use a hash map to connect each original node with its cloned node.

**## Algorithm**
1. If the node is null, return null.
2. If the node is already cloned, return its clone.
3. Create a new node.
4. Store the original-to-clone mapping.
5. Recursively clone all neighbors.
6. Return the cloned node.

**## Example**
A graph `1 -- 2 -- 3 -- 4` is copied into a completely separate graph with the same connections.

**## Time Complexity**
O(V + E)

**## Space Complexity**
O(V)

**## Progress**
#108 / 120 completed
**# Problem #109 / 120 - Course Schedule — LeetCode #207**

**## Pattern**
Graphs + BFS + Topological Sort

**## Key Idea**
If all courses can be processed using their prerequisites, there is no cycle.

**## Algorithm**
1. Build the directed graph.
2. Calculate the indegree of every course.
3. Add courses with indegree `0` to a queue.
4. Remove courses from the queue.
5. Decrease the indegree of their neighbors.
6. If all courses are processed, return `true`.
7. Otherwise, a cycle exists, so return `false`.

**## Example**
`numCourses = 2, [[1,0]] → true`

`numCourses = 2, [[1,0],[0,1]] → false`

**## Time Complexity**
O(V + E)

**## Space Complexity**
O(V + E)

**## Progress**
#109 / 120 completed
**# Problem #110 / 120 - Pacific Atlantic Water Flow — LeetCode #417**

**## Pattern**
Graphs + DFS + Matrix

**## Key Idea**
Start DFS from both oceans instead of starting from every cell.

**## Algorithm**
1. Run DFS from the Pacific edges.
2. Run DFS from the Atlantic edges.
3. During reverse DFS, move only to cells with height >= current height.
4. Find cells visited by both searches.
5. Add those cells to the result.

**## Example**
The cells reachable from both the Pacific and Atlantic oceans are returned.

**## Time Complexity**
O(rows × cols)

**## Space Complexity**
O(rows × cols)

**## Progress**
#110 / 120 completed
**# Problem #111 / 120 - Rotting Oranges — LeetCode #994**

**## Pattern**
Graphs + BFS + Multi-Source BFS

**## Key Idea**
Put all rotten oranges into the queue first. Each BFS level represents one minute.

**## Algorithm**
1. Count all fresh oranges.
2. Add every rotten orange to the queue.
3. Run BFS level by level.
4. During each level, rot neighboring fresh oranges.
5. Increase the minute count.
6. If fresh oranges remain, return `-1`.

**## Example**
`[[2,1,1],[1,1,0],[0,1,1]] → 4`

**## Time Complexity**
O(rows × cols)

**## Space Complexity**
O(rows × cols)

**## Progress**
#111 / 120 completed

**# Problem #112 / 120 - Is Graph Bipartite? — LeetCode #785**

**## Pattern**
Graphs + BFS + Two-Coloring

**## Key Idea**
Color connected nodes with opposite colors. If two connected nodes have the same color, the graph is not bipartite.

**## Algorithm**
1. Create a color array initialized to `-1`.
2. Start BFS from every unvisited node.
3. Give the starting node color `0`.
4. Give each neighbor the opposite color.
5. If a neighbor already has the same color, return `false`.
6. If all nodes are processed, return `true`.

**## Example**
`[[1,3],[0,2],[1,3],[0,2]] → true`

**## Time Complexity**
O(V + E)

**## Space Complexity**
O(V)

**## Progress**
#112 / 120 completed
**# Problem #113 / 120 - Graph Valid Tree — LeetCode #261**

**## Pattern**
Graphs + DFS + Cycle Detection

**## Key Idea**
A valid tree must have exactly `n - 1` edges, contain no cycle, and have all nodes connected.

**## Algorithm**
1. Check that the number of edges is `n - 1`.
2. Build an undirected adjacency list.
3. Run DFS from node `0`.
4. Track the parent node to avoid treating the same edge as a cycle.
5. If a visited neighbor is found, a cycle exists.
6. Check that every node was visited.

**## Example**
`n = 5, [[0,1],[0,2],[0,3],[1,4]] → true`

**## Time Complexity**
O(V + E)

**## Space Complexity**
O(V + E)

**## Progress**
#113 / 120 completed

**# Problem #114 / 120 - Number of Connected Components in an Undirected Graph — LeetCode #323**

**## Pattern**
Graphs + DFS + Connected Components

**## Key Idea**
Every unvisited node starts a new connected component. Use DFS to visit all nodes in that component.

**## Algorithm**
1. Build an undirected adjacency list.
2. Create a visited array.
3. Scan every node.
4. If the node is unvisited, increase the component count.
5. Run DFS to visit all connected nodes.
6. Return the total count.

**## Example**
`n = 5, [[0,1],[1,2],[3,4]] → 2`

**## Time Complexity**
O(V + E)

**## Space Complexity**
O(V + E)

**## Progress**
#114 / 120 completed

**# Problem #115 / 120 - Word Ladder — LeetCode #127**

**## Pattern**
Graphs + BFS + Shortest Path

**## Key Idea**
Treat each word as a graph node. Two words are connected if they differ by one letter.

**## Algorithm**
1. Put all words into a hash set.
2. Start BFS from `beginWord`.
3. Change one character at a time.
4. If the new word exists, add it to the queue.
5. Remove visited words from the set.
6. Return the first level where `endWord` is reached.
7. If it cannot be reached, return `0`.

**## Example**
`hit → hot → dot → dog → cog → 5`

**## Time Complexity**
O(N × L × 26)

**## Space Complexity**
O(N × L)

**## Progress**
#115 / 120 completed

**# Problem #117 / 120 - Redundant Connection — LeetCode #684**

**## Pattern**
Union-Find / Disjoint Set Union (DSU)

**## Key Idea**
A tree cannot contain a cycle. If two nodes are already connected and we try to connect them again, that edge creates a cycle and is the redundant connection.

**## Algorithm**
1. Create a parent array where every node is its own parent.
2. Process every edge.
3. Find the root of both nodes.
4. If both nodes have the same root, a cycle is created.
5. Return that edge.
6. Otherwise, union the two sets.

**## Example**
Input:
[[1,2],[1,3],[2,3]]

Output:
[2,3]

**## Time Complexity**
O(n α(n)) ≈ O(n)

**## Space Complexity**
O(n)

**## Progress**
#117 / 120 completed

**# Problem #118 / 120 - Network Delay Time — LeetCode #743**

**## Pattern**
Dijkstra's Algorithm / Shortest Path

**## Key Idea**
Use Dijkstra's algorithm to find the shortest time from the starting node to every other node. The answer is the largest shortest distance.

**## Algorithm**
1. Build an adjacency list.
2. Set the starting node's distance to 0.
3. Use a min-priority queue.
4. Always process the node with the smallest distance.
5. Relax its neighboring edges.
6. Find the largest shortest distance.
7. If any node is unreachable, return -1.

**## Example**
Input:
times = [[2,1,1],[2,3,1],[3,4,1]]
n = 4
k = 2

Output:
2

**## Time Complexity**
O((V + E) log V)

**## Space Complexity**
O(V + E)

**## Progress**
#118 / 120 completed

**# Problem #119 / 120 - All Paths From Source Lead to Destination — LeetCode #1059**

**## Pattern**
DFS / Cycle Detection / Graph Traversal

**## Key Idea**
Every path from the source must eventually reach the destination. The destination must have no outgoing edges, and there cannot be any reachable cycle or dead-end node.

**## Algorithm**
1. Build the directed graph.
2. Use DFS with three states:
   - 0 = unvisited
   - 1 = currently visiting
   - 2 = completely processed
3. If a node has no outgoing edges, check whether it is the destination.
4. If we encounter a node with state 1, a cycle exists.
5. Recursively check every neighbor.
6. Mark successfully processed nodes as state 2.

**## Example**
Input:
n = 4
edges = [[0,1],[0,2],[1,3],[2,3]]
source = 0
destination = 3

Output:
true

**## Time Complexity**
O(V + E)

**## Space Complexity**
O(V + E)

**## Progress**
#119 / 120 completed
**# Problem #120 / 120 - Cheapest Flights Within K Stops — LeetCode #787**

**## Pattern**
Bellman-Ford / Shortest Path with Limited Stops

**## Key Idea**
Use a modified Bellman-Ford algorithm. Since at most k stops are allowed, we can use at most k + 1 flights.

**## Algorithm**
1. Set the source distance to 0.
2. Repeat the relaxation process k + 1 times.
3. Create a copy of the distance array for every round.
4. Relax every flight using the distances from the previous round.
5. After k + 1 rounds, return the cheapest distance to the destination.
6. If the destination is unreachable, return -1.

**## Example**
Input:
n = 4
flights = [[0,1,100],[1,2,100],[2,3,100],[0,3,500]]
src = 0
dst = 3
k = 1

Output:
500

**## Time Complexity**
O(K × E)

**## Space Complexity**
O(V)

**## Progress**
#120 / 120 completed