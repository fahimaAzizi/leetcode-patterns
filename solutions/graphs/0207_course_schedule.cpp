#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph(numCourses);
        vector<int> indegree(numCourses, 0);

        // Build graph
        for (auto& prerequisite : prerequisites) {
            int course = prerequisite[0];
            int pre = prerequisite[1];

            graph[pre].push_back(course);
            indegree[course]++;
        }

        // Courses with no prerequisites
        queue<int> q;

        for (int i = 0; i < numCourses; i++) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }

        int completed = 0;

        while (!q.empty()) {
            int current = q.front();
            q.pop();

            completed++;

            for (int nextCourse : graph[current]) {
                indegree[nextCourse]--;

                if (indegree[nextCourse] == 0) {
                    q.push(nextCourse);
                }
            }
        }

        return completed == numCourses;
    }
};